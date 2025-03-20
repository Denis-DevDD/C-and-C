#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//---------------------------------------------------------------------------------------------------------------------
// <Program recreating wordle game, entering input and then guessing the hidden word depending on output>
//
//---------------------------------------------------------------------------------------------------------------------
//
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[94m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
//---------------------------------------------------------------------------------------------------------------------
/// function to find the num of rows of 2D array
/// @param array a 2D array to check through
///
int sizeof2DArray(char** array);
//---------------------------------------------------------------------------------------------------------------------
/// function to deallocate the memory to 2D array
/// @param array a 2D array to free
///
void free2DArray(char** array);
//---------------------------------------------------------------------------------------------------------------------
/// function find the length of char array (string)
/// @param str a string for what we find length
///
int stringLength(const char* str);
//---------------------------------------------------------------------------------------------------------------------
/// function to check corectness of command line arguments
/// @param argc num of command line arguments
/// @param argv command line arguments 
///
int checkCommandLine(int argc, char* argv[]);
//---------------------------------------------------------------------------------------------------------------------
/// function to remove all white spaces from out input 
/// @param string an array of chars (string) to remove
///
void removeWhiteSpaces(char* string);
//---------------------------------------------------------------------------------------------------------------------
/// function to check the corectness of word (guess) we entered
/// @param word string, our enter, that we check
///
int checkWord(char* word);
//---------------------------------------------------------------------------------------------------------------------
/// function to enter our guess
/// @param keyboard link to our original pointer (that store our input)
///
int enterWord(char** keyboard);
//---------------------------------------------------------------------------------------------------------------------
/// function to fill 2D array with our previous and current outputs(guesses)
/// @param array link to 2D array
/// @param curren_output char array (string) of guess that we have written just now 
///
int outputsLog(char*** array, char* current_output);
//---------------------------------------------------------------------------------------------------------------------
/// function that provides our guesses output with marks
/// @param output an array of chars
/// @param argv we need to find the color parameter 
///
void displayGuess(const char* output, char* argv[]);
//---------------------------------------------------------------------------------------------------------------------
/// function to mark all letters (on their place, not on their place but being present, not oi this word)
/// @param keyboard our input
/// @param argv word that we need to guess 
/// @param array_o link to 2D array of outputs
///
int guessWord(const char* keyboard, char* argv[], char*** array_o);
//---------------------------------------------------------------------------------------------------------------------
/// ,ain function of our game programm 
/// @param argv parameters for color and hidden word
///
int game(char* argv[]);

int main(int argc, char* argv[])
{
  if (checkCommandLine(argc, argv) == -1)
  {
    return -1;
  }

  printf("Welcome to Evolving Spelling Puzzle!\n\n");

  int return_value = game(argv);
  if (return_value == 1)
  {
    return 1;
  }
  else if (return_value == 2)
  {
    return 2;
  }
  else if (return_value == -2)
  {
    return -2;
  }
  else
  {
    return 0;
  }
}

int sizeof2DArray(char** array)
{
  int rows = 0;

  if (array != NULL)
  {
    while (array[rows] != NULL)
    {
      ++rows;
    }
  }
  return rows;
}

void free2DArray(char** array)
{
  if (array != NULL) 
  {
    int rows = sizeof2DArray(array);
    for (int i = 0; i < rows; ++i) 
    {
      free(array[i]);
    }
    free(array);
  }
}

int stringLength(const char* str)
{
  int length = 0;
  while (str[length] != '\0')
  {
    ++length;
  }
  return length;
}

int checkCommandLine(int argc, char* argv[])
{
  if ((argc != 2) && (argc != 3))
  {
    printf("Usage: ./a2 <solution> [optional: color_enabled]\n");
    return -1;
  }
  
  const char* word = argv[1];
  if (stringLength(word) != 5)
  {
    printf("ERROR: Solution argument must be 5 characters long.\n");
    return -1;
  }

  for (int i = 0; word[i] != '\0'; ++i)
  {
    if (!isalpha((unsigned char)word[i]))
    {
      printf("ERROR: Solution argument contains invalid characters.\n");
      return -1;
    }
  }
  if (argc == 3)
  {
    const char* color = argv[2];
    if ((*color != '0' && *color != '1') || stringLength(color) != 1)
    {
      printf("ERROR: (Optional) color output parameter can either be enabled (1) or not (0).\n");
      return -1;
    }
  }
  return 0;
}

void removeWhiteSpaces(char* string)
{
  int j = 0;
  for (int i = 0; string[i] != '\0'; ++i)
  {
    if (!isspace((unsigned char)string[i]))
    {
      string[j++] = string[i];
    }
  }
  string[j] = '\0';
}

int checkWord(char* word)
{
  int length = 0;

  while(word[length] != '\0')
  {
    if (!isalpha(word[length]))
    {
      printf("ERROR: Word contains invalid characters.\n\n");
      return 1;
    }
    word[length] = tolower((unsigned char)word[length]);
    ++length;
  }

  if (length != 5)
  {
    printf("ERROR: Word is not 5 characters long.\n\n");
    return 1;
  }

  return 0;
}

int enterWord(char** keyboard)
{
  size_t bufferSize = 6;
  size_t length = 0;
  char* buffer = NULL;

  while (1)
  {
    printf("Please enter your guess:\n > ");

    buffer = malloc(bufferSize*sizeof(char));
    if (buffer == NULL)
    {
      return -2;
    }

    int ch;
    length = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
      if (length + 1 >= bufferSize)
      {
        bufferSize *= 2;
        char* tmp = realloc(buffer, bufferSize*sizeof(char));
        if (tmp == NULL)
        {
          free(buffer);
          return -3;
        }
        buffer = tmp;
      }
      buffer[length++] = ch;
    }

    if (ch == EOF)
    {
      free(buffer);
      return 3;
    }

    buffer[length] = '\0';
    removeWhiteSpaces(buffer);
    if (checkWord(buffer) == 0)
    {
      *keyboard = buffer;
      break;
    }
    else
    {
      free(buffer);
    }
  }
  return 0;
}

int outputsLog(char*** array, char* current_output)
{
  int size = 0;
  
  size = sizeof2DArray(*array);

  char** temp = realloc(*array, (size + 2) * sizeof(char*));
  if (temp == NULL) 
  {
    return -3;
  }
  *array = temp;

  int str_len = stringLength(current_output);
  (*array)[size] = malloc((str_len + 1) * sizeof(char));
  if ((*array)[size] == NULL) 
  {
    free2DArray(*array);
    return -3;
  }

  for (int i = 0; i <= str_len; ++i)
  { 
    (*array)[size][i] = current_output[i];
  }

  (*array)[size + 1] = NULL;
    
  return 0;
}


void displayGuess(const char* output, char* argv[])
{
  int color = 0;
  if (argv[2] == NULL || *argv[2] == '0')
  {
    color = 0;
  }
  else
  {
    color = 1;
  }
  printf("|");
  if (color == 1)
  {
    for (int i = 0; i<10; ++i)
    {
      if (output[i] == '~')
      {
        printf("  " ANSI_COLOR_MAGENTA "%c" ANSI_COLOR_RESET, toupper(output[i+1]));
        ++i;
      }
      else if (output[i] == '*')
      {
        printf("  " ANSI_COLOR_BLUE "%c" ANSI_COLOR_RESET, toupper(output[i+1]));
        ++i;
      }
      else if (output[i] == ' ')
      {
        printf("  %c", toupper(output[i+1]));
        ++i;
      }
    }
  }
  else
  {
    for (int i = 0; i<10; ++i)
    {
      if (i % 2 != 0)
      {
        printf("%c", toupper(output[i]));
      }
      else
      {
        printf(" %c", output[i]);
      }
    }
  }
  printf("\n");
}

int guessWord(const char* keyboard, char* argv[], char*** array_o)
{
  char* word = argv[1];
  int length = 0;
  char* output = calloc(10, sizeof(char));
  if (output == NULL)
  {
    return -2;
  }
  while(word[length] != '\0')
  {
    word[length] = tolower((unsigned char)word[length]);
    ++length;
  }
  int correctness = 0;
  for (int i = 0; i < 10; i++)
  {
    output[i] = ' ';
  }

  for (int i = 0, k = 0; i < 5; i++, k += 2)
  {
    output[k + 1] = keyboard[i];
    for (int j = 0; j < 5; j++)
    {
      if (keyboard[i] == word[j])
      {
        if (i == j)
        {
          output[k] = '*';
          correctness++;
          break;
        }
        else if (output[k] != '*')
        {
          output[k] = '~';
        }
      }
    }
  }
  if (outputsLog(array_o, output) == -3)
  {
    free(output);
    return -2;
  }
  for (int i = 0; i < (sizeof2DArray(*array_o)); ++i)
  {
    displayGuess((*array_o)[i], argv);
  }
  printf("\n");
  if (correctness == 5)
  {
    return 1;
  }
  return 0;
}

int game(char* argv[])
{
  const char* word = argv[1];
  char** array_of_outputs = NULL;
  int k = 0;
  while (k != 6)
  {
    char* input = NULL;
    int enter = enterWord(&input);
    if (enter == -2)
    {
      free(input);
      free2DArray(array_of_outputs);
      return -2;
    }
    if (enter == 3)
    {
      return 0;
    }
    int result = guessWord(input, argv, &array_of_outputs);
    if (result == -2)
    {
      free(input);
      free2DArray(array_of_outputs);
      return -2;
    }
    else if(result == 1)
    {
      free(input);
      printf("Good job! You solved this puzzle!\n");
      free2DArray(array_of_outputs);
      return 1;
    }
    else if(result == 0)
    {
      free(input);
    }
    ++k;
  }
  if (k == 6)
  {
    printf("Oh no! You did not guess the word correctly! :(\nThe solution was: '");
    int i = 0;
    while (word[i] != '\0')
    {
      printf("%c", toupper(word[i]));
      ++i;
    }
    printf("'!\n");
    free2DArray(array_of_outputs);
    return 2;
  }
  return 0;
}

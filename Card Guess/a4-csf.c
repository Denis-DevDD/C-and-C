
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//---------------------------------------------------------------------------------------------------------------------
// <Program to simulate card guessing game >
//
//---------------------------------------------------------------------------------------------------------------------
//
#define MEM_ERROR 4
#define ERROR -1
//---------------------------------------------------------------------------------------------------------------------
/// struct to define card
/// @param value_ value of card
/// @param spice_ spice of card
/// @param nextcard_ next card in linked list
///
typedef struct _Card_
{
  int value_;
  char spice_;
  struct _Card_ *nextcard_;
} Card;

typedef enum
{
  LAST_LEFT = 10, ALL_OUT = 11
} Modes;

typedef enum
{
  QUIT = 0, DRAW = 1, PLAY = 2, CHALLENGE = 3
} Commands;
//---------------------------------------------------------------------------------------------------------------------
/// function to transfer each letter to lower case
/// @param str string that we need to lower 
///
void toLowerCase(char *str);
//---------------------------------------------------------------------------------------------------------------------
/// function to remove extra whitespaces
/// @param str string to remove whitespaces 
///
void trimWhitespace(char* str);
//---------------------------------------------------------------------------------------------------------------------
/// function to split input into array
/// @param str string input 
/// @param splited array of splited words
///
int splitString(const char* str, char*** splited);
//---------------------------------------------------------------------------------------------------------------------
/// struct to free splited string
/// @param arr splited string to free
///
void freeStringArray(char** arr);
//---------------------------------------------------------------------------------------------------------------------
/// function to clear linked list of cards
/// @param head starting cell of linked list 
///
void clearCards(Card *head);
//---------------------------------------------------------------------------------------------------------------------
/// function to free memory
/// @param list1 and other to free 
///
void freeMEM(Card* list1, Card* list2, Card* list3, Card* singlecard1, 
Card* singlecard2, char* layout);
//---------------------------------------------------------------------------------------------------------------------
/// function to printHand
/// @param head starting cell of linked list 
///
void printHand(Card *head);
//---------------------------------------------------------------------------------------------------------------------
/// function to check commandline input
/// @param argc number of parameters 
///
int checkTheCommandLine(const int argc);
//---------------------------------------------------------------------------------------------------------------------
/// function to check config
/// @param pile config file 
/// @param filename name of file we opened
///
int checkConfigFile(FILE* pile, const char* filename);
//---------------------------------------------------------------------------------------------------------------------
/// function to display score and write in file
/// @param score variable to write score 
/// @param file file to write score in
///
void displayAndWriteScores(int score[], FILE *file);
//---------------------------------------------------------------------------------------------------------------------
/// function to write in input
/// @param input link to store input
///
int keyboardInput(char** input);
//---------------------------------------------------------------------------------------------------------------------
/// helper function to sort cards, in this function we compare cards by its value and spice
/// @param card1 first hand 
/// @param card2 second hand
///
int compareCards(Card* card1, Card* card2);
//---------------------------------------------------------------------------------------------------------------------
/// function to insert cards in hand in correct order
/// @param head sttarting cell
/// @param newCard card to input
///
void insertCardSorted(Card** head, Card* newCard);
//---------------------------------------------------------------------------------------------------------------------
/// function to give cards for each player
/// @param pl1 players 1 hand
/// @param pl2 players2 hand
/// @param draw_deck draw deck
/// @param pile file where we find cards
///
int cardDistribution(Card** pl1, Card** pl2, Card** draw_deck, FILE* pile);
//---------------------------------------------------------------------------------------------------------------------
/// function to draw (to move card from draw deck to player)
/// @param active current players turn link to current player 
/// @param deck deck to draw card
///
int drawCommand(Card** active, Card** deck);
//---------------------------------------------------------------------------------------------------------------------
/// function to execute challenge command
/// @param last last played card that other player see 
/// @param true_p card that has been truly played
/// @param challenge what do we challenge
/// @param played_c how many cards have been played in round
/// @param points_to_change pointer to score so we can add points
/// @param pl_turn which player is playing
/// @param round_p pointer to switch round 
/// @param md game mode
///
int challengeCommand(Card** last, Card** true_p, char* challenge,
int played_c, int* points_to_change, int* pl_turn, int* round_p, int md);
//---------------------------------------------------------------------------------------------------------------------
/// function to find card that we want to play
/// @param active active player pointer
/// @param val_true value of card
/// @param spice_true spice of card
///
Card* findCard(Card* active, int val_true, char spice_true);
//---------------------------------------------------------------------------------------------------------------------
/// function to execute play command
/// @param active active player pointer
/// @param last last played card that (maybe fake)
/// @param true_play last true played card
/// @param played string with card value and spice (truly played card)
/// @param as_played card we show (maybe fake)
///
int playCommand(Card** active, Card** last, Card** true_play, char* played,
char* as_played);
//---------------------------------------------------------------------------------------------------------------------
/// function to check and sellect command
/// @param command command as string 
/// @param act pointer to active player
/// @param pile draw deck
/// @param t_pl true played card lately
/// @param lst last card that seems to be played
/// @param pl player turn
/// @param mod mode to check specific game conditions
/// @param played how many vards has been played 
/// @param points that will be added
/// @param rnd round pointer
///
int commandPrompt(char* command, Card** act, Card** pile, Card** t_pl,
Card** lst, int* pl, int mod, int played, int* points, int* rnd);
//---------------------------------------------------------------------------------------------------------------------
/// function to switch turn
/// @param active pointer to active player
/// @param player1 pointer to player1
/// @param player2 pointer to player 2
/// @param player_turn player turn flag 
/// @param command last executed command
/// @param mode game mode
///
void switchTurn(Card** active, Card** player1, Card** player2, int* player_turn, int command, int* mode);
//---------------------------------------------------------------------------------------------------------------------
/// function to change game setting after challenge command
/// @param player1 pointer to player1
/// @param player2 pointer to player 2
/// @param player_turn player turn flag
/// @param deck draw deck
/// @param endgame pointer to end game
///
void handleChallenge(Card** player1, Card** player2, Card** deck, int* player_turn, int* endgame);
//---------------------------------------------------------------------------------------------------------------------
/// fucntion to print current game status(players hand, cards played and so on)
/// @param md game mode 
/// @param act active player
/// @param last last played card
/// @param pl_t player turn flag
/// @param c_amount cards amount played
///
void gameInfo(int md, Card* act, Card* last, int pl_t, int c_amount);
//---------------------------------------------------------------------------------------------------------------------
/// game logic function
/// @param in_file name of item 
///
int game(FILE* in_file);
//---------------------------------------------------------------------------------------------------------------------
/// main function
/// @param argc number arguments 
/// @param argv arguments
///
int main(int argc, char* argv[])
{
  if (checkTheCommandLine(argc) == 1)
  {
    return 1;
  }
  FILE* file = fopen(argv[1], "r+");
  if (!file)
  {
    printf("Error: Cannot open file: %s\n", argv[1]);
    return 2;
  }
  int configCheck = checkConfigFile(file, argv[1]);
  if (configCheck != 0)
  {
    return configCheck;
  }
  int res = game(file);
  fclose(file);
  return res;
}

void toLowerCase(char *str)
{
  while (*str != '\0')
  {
    if (isalpha((unsigned char)*str))
    {
      *str = tolower((unsigned char)*str);
    }
    str++;
  }
}

void trimWhitespace(char* str)
{
  if (str == NULL)
  {
    return;
  }

  char* start = str;
  char* end;

  while (isspace((unsigned char)*start))
  {
    start++;
  }

  if (start != str)
  {
    char* dest = str;
    while (*start)
    {
      *dest++ = *start++;
    }
   *dest = '\0';
  }

  end = str + strlen(str) - 1;

  while (end >= str && isspace((unsigned char)*end))
  {
    *end = '\0';
    end--;
  }
}

int splitString(const char* str, char*** splited)
{
  int count = 0;
  const char* start = str;
  int alloc = 1;
  *splited = (char**)malloc(sizeof(char*));
  if (*splited == NULL) 
  {
    printf("Error: Out of memory.\n");
    return MEM_ERROR;
  }

  while (*start != '\0') 
  {
    while (isspace((unsigned char)*start))
    {
      start++;
    }

    if (*start == '\0') 
    {
      break;
    }

    const char* end = start;
    while (*end != '\0' && !isspace((unsigned char)*end))
    {
      end++;
    }

    size_t length = end - start;

    if (count >= alloc)
    {
      alloc += 1;
      *splited = (char**)realloc(*splited, alloc * sizeof(char*));
      if (*splited == NULL)
      {
        printf("Error: Out of memory.\n");
        return MEM_ERROR;
      }
    }

    (*splited)[count] = (char*)malloc((length + 1) * sizeof(char));
    if ((*splited)[count] == NULL)
    {
      printf("Error: Out of memory.\n");
      for (int symbol = 0; symbol < count; symbol++)
      {
        free((*splited)[symbol]);
      }
      free(*splited);
      return MEM_ERROR;
    }

    strncpy((*splited)[count], start, length);
    (*splited)[count][length] = '\0';
    count++;
    start = end;
  }
  *splited = (char**)realloc(*splited, (count + 1) * sizeof(char*));
  if (*splited == NULL)
  {
    printf("Error: Out of memory.\n");
    return MEM_ERROR;
  }
  (*splited)[count] = NULL;
  return count;
}

void freeStringArray(char** arr)
{
  int i = 0;
  while (arr[i] != NULL)
  {
    free(arr[i]);
    ++i;
  }
  free(arr);
}

void clearCards(Card *head)
{
  Card* current = head;
  while (current != NULL)
  {
    Card* temp = current;
    current = current->nextcard_;
    free(temp);
  }
}

void freeMEM(Card* list1, Card* list2, Card* list3, Card* singlecard1, 
Card* singlecard2, char* layout)
{
  clearCards(list1);
  clearCards(list2);
  clearCards(list3);
  free(singlecard1);
  free(singlecard2);
  free(layout);
}

void printHand(Card *head) 
{
  Card* current = head;
  while (current != NULL)
  {
    printf(" %d_%c", current->value_, current->spice_);
    current = current->nextcard_;
  }
  printf("\n");
}

int checkTheCommandLine(const int argc)
{
  if (argc != 2)
  {
    printf("Usage: ./a4-csf <config file>\n");
    return 1;
  }
  return 0;
}

int checkConfigFile(FILE* pile, const char* filename)
{
  char buffer[5] = {0};
  fgets(buffer, sizeof(buffer), pile);
  if (strcmp(buffer, "ESP\n") == 0)
  {
    return 0;
  }
  else
  {
    printf("Error: Invalid file: %s\n", filename);
    fclose(pile);
    return 3;
  } 
}

void displayAndWriteScores(int score[], FILE *file) 
{
  fprintf(file, "\n");
  printf("\n");

  if (score[0] == score[1]) 
  {
    fprintf(file, "Player 1: %d points\n", score[0]);
    fprintf(file, "Player 2: %d points\n", score[1]);
    printf("Player 1: %d points\n", score[0]);
    printf("Player 2: %d points\n", score[1]);
  } 
  else 
  {
    fprintf(file, "Player %d: %d points\n", (score[0] > score[1]) ? 1 : 2, 
    (score[0] > score[1]) ? score[0] : score[1]);
    fprintf(file, "Player %d: %d points\n", (score[0] < score[1]) ? 1 : 2, 
    (score[0] < score[1]) ? score[0] : score[1]);

    printf("Player %d: %d points\n", (score[0] > score[1]) ? 1 : 2, 
    (score[0] > score[1]) ? score[0] : score[1]);
    printf("Player %d: %d points\n", (score[0] < score[1]) ? 1 : 2, 
    (score[0] < score[1]) ? score[0] : score[1]);
  }

  fprintf(file, "\n");
  printf("\n");

  if (score[0] == score[1]) 
  {
    fprintf(file, "Congratulations! Player 1 wins the game!\n");
    fprintf(file, "Congratulations! Player 2 wins the game!\n");

    printf("Congratulations! Player 1 wins the game!\n");
    printf("Congratulations! Player 2 wins the game!\n");
  } 
  else 
  {
    fprintf(file, "Congratulations! Player %d wins the game!\n", 
    (score[0] > score[1]) ? 1 : 2);
    printf("Congratulations! Player %d wins the game!\n", 
    (score[0] > score[1]) ? 1 : 2);
  }
}

int keyboardInput(char** input)
{
  char* buffer = NULL;
  size_t buffer_size = 0;
  char temp[10];

  while (fgets(temp, 10, stdin))
  {
    size_t temp_len = strlen(temp);
    char* new_buffer = (char*)realloc(buffer, buffer_size + temp_len + 1);
    if (new_buffer == NULL)
    {
      free(buffer);
      return MEM_ERROR;
    }
    buffer = new_buffer;
    strcpy(buffer + buffer_size, temp);
    buffer_size += temp_len;

    if (temp[temp_len - 1] == '\n')
    {
      break;
    }
  }

  if (buffer[buffer_size - 1] == '\n')
  {
    buffer[buffer_size - 1] = '\0';
    buffer_size--;
  }
  trimWhitespace(buffer);
  *input = buffer;
  return 0;
}

int compareCards(Card* card1, Card* card2) 
{
  int rank1 = (card1->spice_ == 'c') ? 1 : (card1->spice_ == 'p') ? 2 : 3;
  int rank2 = (card2->spice_ == 'c') ? 1 : (card2->spice_ == 'p') ? 2 : 3;
  if (rank1 != rank2) 
  {
    return rank1 - rank2;
  }
  return card1->value_ - card2->value_;
}

void insertCardSorted(Card** head, Card* newCard) 
{
  if (*head == NULL || compareCards(newCard, *head) < 0) 
  {
    newCard->nextcard_ = *head;
    *head = newCard;
  } 
  else 
  {
    Card* current = *head;
    while (current->nextcard_ != NULL && compareCards(current->nextcard_, newCard) < 0) 
    {
      current = current->nextcard_;
    }
    newCard->nextcard_ = current->nextcard_;
    current->nextcard_ = newCard;
  }
}

int cardDistribution(Card** pl1, Card** pl2, Card** draw_deck, FILE* pile) 
{
  int val = 0;
  int counter = 0;
  char sp = 0;
  while (fscanf(pile, "%d_%c", &val, &sp) == 2) 
  {
    Card* newCard = (Card*)malloc(sizeof(Card));
    if (newCard == NULL) 
    {
      printf("Error: Out of memory\n");
      return MEM_ERROR;
    }
    newCard->value_ = val;
    newCard->spice_ = sp;
    newCard->nextcard_ = NULL;

    if (counter % 2 == 0) 
    {
      insertCardSorted(pl1, newCard);
    } 
    else 
    {
      insertCardSorted(pl2, newCard);
    }
    ++counter;
    if (counter == 12)
    {
      break;
    }
  }

  while (fscanf(pile, "%d_%c", &val, &sp) == 2) 
  {
    Card* newCard = (Card*)malloc(sizeof(Card));
    if (newCard == NULL) 
    {
      printf("Error: Out of memory\n");
      return MEM_ERROR;
    }
    newCard->value_ = val;
    newCard->spice_ = sp;
    newCard->nextcard_ = NULL;
    if (*draw_deck == NULL)
    {
      *draw_deck = newCard;
    }
    else
    {
      Card* current = *draw_deck;
      while (current->nextcard_ != NULL) 
      {
        current = current->nextcard_;
      }
      current->nextcard_ = newCard;
    }
  }
  return 0;
}

int drawCommand(Card** active, Card** deck) 
{
  if (*deck == NULL) 
  {
    return ALL_OUT;
  }

  Card* newCard = (Card*)malloc(sizeof(Card));
  if (newCard == NULL) 
  {
    printf("Error: Out of memory\n");
    return MEM_ERROR;
  }

  newCard->value_ = (*deck)->value_;
  newCard->spice_ = (*deck)->spice_;
  newCard->nextcard_ = NULL;

  insertCardSorted(active, newCard);

  Card* temp = *deck;
  *deck = (*deck)->nextcard_;
  free(temp);

  if (*deck == NULL) 
  {
    return ALL_OUT;
  }
  return DRAW;
}

int challengeCommand(Card** last, Card** true_p, char* challenge,
int played_c, int* points_to_change, int* pl_turn, int* round_p, int md)
{
  if (*last == NULL)
  {
    printf("Please enter a command you can use at the moment!\n");
    return ERROR;
  }
  if (strcmp(challenge, "value") != 0 && strcmp(challenge, "spice") != 0)
  {
    printf("Please choose SPICE or VALUE!\n");
    return ERROR;
  }
  else if (strcmp(challenge, "value") == 0)
  {
    if ((*last)->value_ != (*true_p)->value_)
    {
      printf("Challenge successful: %d_%c's", (*last)->value_, (*last)->spice_);
      printf(" value does not match");
      printf(" the real card %d_%c.\n",(*true_p)->value_, (*true_p)->spice_);
      points_to_change[(*pl_turn) - 1] += played_c;
      printf("Player %d gets %d points.\n", *pl_turn, played_c);
      *pl_turn = (*pl_turn == 1) ? 2 : 1;
    }
    else
    {
      printf("Challenge failed: %d_%c's", (*last)->value_, (*last)->spice_);
      printf(" value matches");
      printf(" the real card %d_%c.\n",(*true_p)->value_, (*true_p)->spice_);
      *pl_turn = (*pl_turn == 1) ? 2 : 1;
      points_to_change[(*pl_turn) - 1] += played_c;
      printf("Player %d gets %d points.\n", *pl_turn, played_c);
      if (md == LAST_LEFT)
      {
        points_to_change[(*pl_turn) - 1] += 10;
        printf("Player %d gets 10 bonus points (last card).\n", *pl_turn);
      }
      *pl_turn = (*pl_turn == 1) ? 2 : 1;
    }
    *round_p = 1;
  }
  else if (strcmp(challenge, "spice") == 0)
  {
    if ((*last)->spice_ != (*true_p)->spice_)
    {
      printf("Challenge successful: %d_%c's", (*last)->value_, (*last)->spice_);
      printf(" spice does not match");
      printf(" the real card %d_%c.\n",(*true_p)->value_, (*true_p)->spice_);
      points_to_change[*pl_turn - 1] += played_c;
      printf("Player %d gets %d points.\n", *pl_turn, played_c);
      *pl_turn = (*pl_turn == 1) ? 2 : 1;
    }
    else
    {
      printf("Challenge failed: %d_%c's", (*last)->value_, (*last)->spice_);
      printf(" spice matches");
      printf(" the real card %d_%c.\n",(*true_p)->value_, (*true_p)->spice_);
      *pl_turn = (*pl_turn == 1) ? 2 : 1;
      points_to_change[(*pl_turn) - 1] += played_c;
      printf("Player %d gets %d points.\n", *pl_turn, played_c);
      if (md == LAST_LEFT)
      {
        points_to_change[(*pl_turn) - 1] += 10;
        printf("Player %d gets 10 bonus points (last card).\n", *pl_turn);
      }
      *pl_turn = (*pl_turn == 1) ? 2 : 1;
    }
    *round_p = 1;
  }
  return CHALLENGE;
}

Card* findCard(Card* active, int val_true, char spice_true)
{
  Card* prev = NULL;
  while (active != NULL)
  {
    if (active->value_ == val_true && active->spice_ == spice_true)
    {
      return prev;
    }
    prev = active;
    active = active->nextcard_;
  }
  return NULL;
}

int playCommand(Card** active, Card** last, Card** true_play, char* played,
char* as_played)
{
  int val_true = 0;
  int val = 0;
  char spice_true = 0;
  char spice = 0;
  if (sscanf(played, "%d_%c", &val_true, &spice_true) != 2)
  {
    printf("Please enter the cards in the correct format!\n");
    return ERROR;
  }
  Card* prev = findCard(*active, val_true, spice_true);
  if (prev == NULL && *active == NULL) 
  {
    printf("Please enter a card in your hand cards!\n");
    return ERROR;
  }
  Card* card_to_play = (prev == NULL) ? *active : prev->nextcard_;
  if (*last == NULL)
  {
    if (sscanf(as_played, "%d_%c", &val, &spice) != 2)
    {
      printf("Please enter the cards in the correct format!\n");
      return ERROR;
    }
    if (val < 1 || val > 3)
    {
      printf("Please enter a valid VALUE!\n");
      return ERROR;
    }
    Card* last_create = (Card*)malloc(sizeof(Card));
    if (last_create == NULL)
    {
      printf("Error: Out of memory.\n");
      return MEM_ERROR;
    }
    Card* true_card = (Card*)malloc(sizeof(Card));
    if (true_card == NULL)
    {
      printf("Error: Out of memory.\n");
      free(last_create);
      return MEM_ERROR;
    }
    true_card->value_ = val_true;
    true_card->spice_ = spice_true;
    true_card->nextcard_ = NULL;
    *true_play = true_card;
    last_create->value_ = val;
    last_create->spice_ = spice;
    last_create->nextcard_ = NULL;
    *last = last_create;
  }
  else
  {
    if (sscanf(as_played, "%d_%c", &val, &spice) != 2 || (*last)->spice_ != spice || 
    ((*last)->value_ == 10 && (val < 1 || val > 3)) || ((*last)->value_ != 10 && val < (*last)->value_))
    {
      printf("Please enter a valid VALUE or SPICE!\n");
      return ERROR;
    }
    (*true_play)->value_ = val_true;
    (*true_play)->spice_ = spice_true;
    (*last)->value_ = val;
    (*last)->spice_ = spice;
  }
  if (prev == NULL)
  {
    card_to_play = *active;
    *active = (*active)->nextcard_;
  }
  else
  {
    prev->nextcard_ = card_to_play->nextcard_;
  }
  free(card_to_play);
  return PLAY;
}

int commandPrompt(char* command, Card** act, Card** pile, Card** t_pl,
Card** lst, int* pl, int mod, int played, int* points, int* rnd)
{
  if (command[0] == '\0' || command[0] == ' ')
  {
    printf("Please enter a valid command!\n");
    return ERROR;
  }
  toLowerCase(command);
  char** split_command = NULL;
  int split_amount = splitString(command, &split_command);
  if (strcmp(split_command[0], "quit") == 0 && split_amount == 1)
  {
    freeStringArray(split_command);
    return QUIT;
  }
  if ((strcmp(split_command[0], "quit") == 0 || strcmp(split_command[0], "draw") == 0) 
  && split_amount != 1)
  {
    printf("Please enter the correct number of parameters!\n");
    freeStringArray(split_command);
    return ERROR;
  }
  if (strcmp(split_command[0], "draw") == 0 && split_amount == 1)
  {
    if (mod == LAST_LEFT)
    {
      printf("Please enter a command you can use at the moment!\n");
      freeStringArray(split_command);
      return ERROR;
    }
    int draw = drawCommand(act, pile);
    freeStringArray(split_command);
    return draw;
  }
  if (strcmp(split_command[0], "challenge") == 0 && split_amount == 2)
  {
    int challenge = challengeCommand(lst, t_pl, split_command[1], played,
    points, pl, rnd, mod);
    freeStringArray(split_command);
    return challenge;
  }
  if (strcmp(split_command[0], "challenge") == 0 && split_amount != 2)
  {
    printf("Please enter the correct number of parameters!\n");
    freeStringArray(split_command);
    return ERROR;
  }
  if (strcmp(split_command[0], "play") == 0 && split_amount == 3)
  {
    if (mod == LAST_LEFT)
    {
      printf("Please enter a command you can use at the moment!\n");
      freeStringArray(split_command);
      return ERROR;
    }
    int play = playCommand(act, lst, t_pl, split_command[1], 
    split_command[2]);
    freeStringArray(split_command);
    return play;
  }
  if (strcmp(split_command[0], "play") == 0 && split_amount != 3)
  {
    printf("Please enter the correct number of parameters!\n");
    freeStringArray(split_command);
    return ERROR;
  }
  else
  {
    printf("Please enter a valid command!\n");
    freeStringArray(split_command);
    return ERROR;
  }
  return 0;
}

void gameInfo(int md, Card* act, Card* last, int pl_t, int c_amount)
{
  if (pl_t == 1)
  {
    printf("\nPlayer 1:\n");
  }
  else
  {
    printf("\nPlayer 2:\n");
  }
  if (last == NULL)
  {
    printf("    latest played card:\n");
  }
  else
  {
    printf("    latest played card: %d_%c", last->value_, last->spice_);
    if (md == LAST_LEFT)
    {
      printf(" LAST CARD\n");
    }
    else
    {
      printf("\n");
    }
  }
  printf("    cards played this round: %d\n", c_amount);
  printf("    hand cards:");
  printHand(act);
}

void switchTurn(Card** active, Card** player1, Card** player2, int* player_turn, int command, int* mode)
{
  if (*player_turn == 1 && command != CHALLENGE)
  {
    *player1 = *active;
    if (*player1 == NULL)
    {
      *mode = LAST_LEFT;
    }
    *active = *player2;
    *player_turn = 2;
  }
  else if (*player_turn == 2 && command != CHALLENGE)
  {
    *player2 = *active;
    if (*player2 == NULL)
    {
      *mode = LAST_LEFT;
    }
    *active = *player1;
    *player_turn = 1;
  }
}

void handleChallenge(Card** player1, Card** player2, Card** deck, int* player_turn, int* endgame)
{
  int challenge_draw = 0;
  while (challenge_draw < 2)
  {
    (void)drawCommand((*player_turn == 2) ? player2 : player1, deck);
    challenge_draw++;
  }

  if (*player_turn == 1 && *player2 == NULL)
  {
    while (challenge_draw < 8)
    {
      (void)drawCommand(player2, deck);
      challenge_draw++;
    }
  }
  else if (*player_turn == 2 && *player1 == NULL)
  {
    while (challenge_draw < 8)
    {
      (void)drawCommand(player1, deck);
      challenge_draw++;
    }
  }

  if (*deck == NULL)
  {
    *endgame = 1;
  }
}

int game(FILE* in_file)
{
  printf("Welcome to Entertaining Spice Pretending!\n");
  Card* Player1 = NULL;
  Card* Player2 = NULL;
  Card* Deck = NULL;
  int hands = cardDistribution(&Player1, &Player2, &Deck, in_file);
  if (hands == MEM_ERROR)
  {
    clearCards(Player1);
    clearCards(Player2);
    clearCards(Deck);
    return MEM_ERROR;
  }
  int score[2] = { 0, 0 };
  int endgame = 0;
  int player_turn = 1;
  do
  {
    printf("\n-------------------\nROUND START\n-------------------\n");
    Card* active = NULL;
    active = (player_turn == 1) ? Player1 : Player2;
    Card* last_played = NULL;
    Card* true_played = NULL;
    int new_round = 0, mode = 0, cards_pl = 0;
    do
    {
      int command = 0;
      char* input = NULL;
      gameInfo(mode, active, last_played, player_turn, cards_pl);
      do
      {
        player_turn == 1 ? printf("P1 > ") : printf("P2 > ");
        command = keyboardInput(&input);
        if (command == MEM_ERROR)
        {
          freeMEM(Player1, Player2, Deck, last_played, true_played, input);
          return MEM_ERROR;
        }
        command = commandPrompt(input, &active, &Deck, &true_played, &last_played,
        &player_turn, mode, cards_pl, score, &new_round);
        if (command == QUIT)
        {
          freeMEM(Player1, Player2, Deck, last_played, true_played, input);
          return 0;
        }
        if (command == ALL_OUT)
        {
          new_round = 1;
          endgame = 1;
        }
        if (command == MEM_ERROR)
        {
          freeMEM(Player1, Player2, Deck, last_played, true_played, input);
          return MEM_ERROR;
        }
        if (command == PLAY)
        {
          cards_pl += 1;
        }
        free(input);
      } while (command == ERROR);
      switchTurn(&active, &Player1, &Player2, &player_turn, command, &mode);
      if (command == CHALLENGE)
      {
        handleChallenge(&Player1, &Player2, &Deck, &player_turn, &endgame);
      }
    } while (new_round == 0);
    free(last_played);
    free(true_played);
  } while (endgame == 0);
  displayAndWriteScores(score, in_file);
  clearCards(Player1);
  clearCards(Player2);
  clearCards(Deck);
  return 0;
}

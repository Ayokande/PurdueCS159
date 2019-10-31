
/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. akande@purdue.edu
 *
 *  Homework #:5
 *
 *  Academic Integrity Statement:
 *
 *       I have not used source code obtained from
 *       any other unauthorized source, either modified
 *       or unmodified.  Neither have I provided access
 *       to my code to another. The project I am submitting
 *       is my own original work.
 *
 *  Lab Division and Section: Lab 40 - Lecture 4
 *
 *  Program Description: This program calculates a score an integer input by ading the power
 *  of each individual figure of the number iteratively.
 *  If the numberhappens to be prime then the largest digit in the number will be added
 *  to the score otherwise the smallest digit will be subtracted from the
 *  score to produce the final result.
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Global Declaration
long long getInput();
void calcMembers(long long, int*, int*, int*);
void printResults (int, int, int);

int main()
{
  //Variable Declaration
  long long members; //inputted members in form of number
  int clients = 0; //number of clients
  int coders = 0; //number of coders
  int managers = 0; //number of managers

  //Executable Statements
  members = getInput();
  calcMembers(members, &clients, &coders, &managers);
  printResults(clients, coders, managers);

  return 0;
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function: getInput
 *
 *  Function Return Type: long long
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. none
 *
 *  Function Description: Get desired input value to be stored.
 *
 ***************************************************************************/

long long getInput()
{
  //Variable Declaration
  long long members; //members value

  //Executable Statements
  printf("Enter the potential team members -> ");
  scanf("%lld", &members);

  return members;
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function: calcMembers
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. long long configuration //configuration value inputted
 *    2. int *clients //number of clients
 *    3. int *coders // number of coders
 *    4. int *managers // number of managers
 *
 *
 *  Function Description: The purpose of this function is to evaluate and fix
 *  the digits in value and count the changes being made to clients, coders and managers.
 *
 ***************************************************************************/

void calcMembers(long long members, int* clients, int* coders, int* managers)
{
  //Variable Declaration
  long long value;       //setting value equal to configuration
  long long new_value;   //resulting value after changes
  int remainder; //the remainder from int division
  int i; //lcv

  //Executable Statements
  value = members;
  remainder = value % 10;
  new_value = value / 10;

  if ((remainder % 10) == 1)
  {
    (*clients)++;
  }

  if ((remainder % 10) == 2)
  {
    (*coders)++;
  }

  if ((remainder % 10) == 3)
  {
    (*managers)++;
  }

  for(i = 0; i < 1; i++)
  {
    if (new_value >= 1)
    {
      calcMembers(new_value, clients, coders, managers);
    }
  }
    
  return;
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function: printResults
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int clients //number of clients
 *    2. int coders //number of coders
 *    3. int managers //number of managers
 *
 *  Function Description: To ouput the final results
 *
 ***************************************************************************/

void printResults (int clients, int coders, int managers)
{
  //Executable Statements
  printf("\nComposition of team\n");
  printf("-> Managers: %d\n", managers);
  printf("-> Coders: %d\n", coders);
  printf("-> Clients: %d\n", clients);

  if((managers != 2) || ((coders % 2) != 0) || (clients < 2))
  {
    printf("\nStatus of team: invalid\n");

    if (managers != 2)
    {
      printf("-> Managers: Number of managers must be exactly two.\n");
    }

    if ((coders % 2) != 0)
    {
      printf("-> Coders: Number of coders must be even.\n");
    }

    if (clients < 2)
    {
      printf("-> Clients: Number of clients must be at least two.\n");
    }
  }

  else
  {
    printf("Status of team: valid\n");
  }

  return;
}


/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. akande@purdue.edu
 *
 *  Homework #: 07
 *
 *  Academic Integrity Statement:
 *
 *       I have not used source code obtained from
 *       any other unauthorized source, either modified
 *       or unmodified.  Neither have I provided access
 *       to my code to another. The project I am submitting
 *       is my own original work.
 *
 *  Lab Division and Section: Lab40 - Lecture4
 *
 *  Program Description: This function collects an input array from the user
 *  and calculates totals for 2 teams.
 *
 ***************************************************************************/

#include <stdio.h>
#define SIZE 30

int getInput(int[]);
void sortInput(int[], int);
void swap (int* num1, int* num2);
void printOutput(int[], int input);

int main()
{
  //Variable Declaration Section
  int input; //fo user input
  int array[SIZE]; // array to be filled in by user

  // Executable Statements
  input = getInput(array);
  sortInput(array,input);
  printOutput(array,input);

  return (0);
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: getInput
 *
 *     Programmer's Name: AYomide Akande
 *
 *     Function Return Type:
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1.
 *       2.
 *       3.
 *
 *     Function Description:
 *
 ***************************************************************************/

int getInput(int array[])
{
  //Variable Declaration Section
  int count = 0; //lcv
  int loop_exit = 0; //exit control

  // Executable Statements
  printf("\nEnter available students -> ");

  while (count < SIZE && !loop_exit)
  {
    scanf("%d", &array[count]);
    loop_exit = (array[count] == -1);
    count++;
  }
  if ((count == 30) && (array[count - 1] == -1))
  {
    count--;
  }

  else if (count != 30)
  {
    count--;
  }

  return count;
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: sortInput
 *
 *     Programmer's Name:Ayomide Akande
 *
 *     Function Return Type:
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1. int array[]
 *       2. int count // total nuber of elements
 *       3.
 *
 *     Function Description: Sorts the array in descending order
 *
 ***************************************************************************/

void sortInput(int array[], int count)
{
  //Variable Declaration Section
  int index; // lcv
  int denom; //denominator
  int min; //minimum
  int i; //lcv
  int temp; //temporary value for swapping

  // Executable Statements
  for ( index = 0; index < count - 1; index++)
  {
    min = index;
    for (denom = index + 1; denom < count; denom++)
    {
      if (array[denom] < array[min])
      {
        min = denom;
      }
    }
    if (index != min)
    {
      swap(&array[index], &array[min]);
    }
  }

  for(i = 0 ; i < (count / 2) ; i++)
  {
    temp = array[i];
    array[i] = array[count - i - 1];
    array[count - i - 1] = temp;
  }
  return;
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function:
 *
 *  Function Return Type:
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int* num1 // address of first number
 *    2. int* num2 // address of second number
 *    3.
 *
 *  Function Description: Swaps 2 values passed in by address
 *
 ***************************************************************************/

void swap (int* num1, int* num2)
{
  //Variable Declaration Section
  int hold; //hold variable for swapping process

  // Executable Statements
  hold = *num1;
  *num1 = *num2;
  *num2 = hold;

  return;
}

/***************************************************************************
 *
 *  Function Information
 *
 *  Name of Function:printOutput
 *
 *  Function Return Type: void
 *
 *  Parameters (list data type, name, and comment one per line):
 *    1. int array[]
 *    2. int input // total nuber of input values
 *    3.
 *
 *  Function Description: Prints the desired output
 *
 ***************************************************************************/

void printOutput(int array[], int input)
{
  //Variable Declaration Section
  int total_1; //team 1 total
  int total_2; //team 2 total
  int i; //lcv

  // Executable Statements
  total_1 = 0;
  total_2 = 0;

  for(i = input - 1; i >= 0; i--)
  {
    if (i == 0)
    {
      total_1 += array[i];
    }
    else if (i == 1 || i == 2)
    {
      total_2 += array[i];
    }
    else if((i > 2) && ((i % 2) == 1))
    {
      total_1 += array[i];
    }
    else if((i > 2) && ((i % 2) == 0))
    {
      total_2 += array[i];
    }
  }

  printf("\nTeam #1 Total: %d\n",total_1);
  printf("Team #2 Total: %d\n",total_2);
  return;
}

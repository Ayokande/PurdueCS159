
/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. akande@purdue.edu
 *
 *  Homework #:06
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
 *  Program Description: Given 20 positive integer values, this code sperates values into different arrays.
 *
 *************************************************************************/

#include <stdio.h>
#define SIZE 20

void checkNumber(int * neg, int * pos, int * eq, int numbers[], int negArr[], int posArr[], int eqArr[]);
void printOutput(int * neg, int * pos, int * eq, int negArr[], int posArr[], int eqArr[]);

int main()
{
  //Initialization Section
  int numbers[SIZE];
  int count;
  int negArr[SIZE] = {0};
  int posArr[SIZE] = {0};
  int eqArr[SIZE]= {0};
  int neg = 0;
  int pos = 0;
  int eq = 0;

  //Executable Statements
  printf("Enter 20 integers now -> ");
  for (count = 0; count < SIZE; count++)
  {
    scanf("%d", &numbers[count]);
  }
  checkNumber(&neg, &pos, &eq, numbers, negArr, posArr, eqArr);
  printOutput(&neg, &pos, &eq, negArr, posArr, eqArr);
  printf("\n");

  return (0);
}


/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: checkNUmber
 *
 *     Programmer's Name: Ayomide D. Akande
 *
 *     Function Return Type: int
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1.int number
 *       2.
 *       3.
 *
 *     Function Description: Checks if the number is prime or not
 *
 ***************************************************************************/

void checkNumber(int * neg, int * pos, int * eq, int numbers[], int negArr[], int posArr[], int eqArr[])
{
  //Initialization
  int num;
  int rem;
  int val;
  int pos_flag = 0;
  int neg_flag = 0;
  int eq_flag = 0;
  int prev_pos_flag = 0;
  int prev_neg_flag = 0;
  int prev_eq_flag = 0;
  int consistency_flag = 1;
  int count = 0;
  int original_val;

  //Executable Statements
  for (count = 0; count < SIZE; count++)
  {
    original_val = numbers[count];
    num = numbers[count];
    consistency_flag = 1;
    while(num > 9 && consistency_flag == 1)
    {
      prev_pos_flag = pos_flag;
      prev_neg_flag = neg_flag;
      prev_eq_flag = eq_flag;

      rem = num % 10;
      val = num / 10;
      if((val % 10) < rem)
      {
        neg_flag = 1;
        pos_flag = 0;
        eq_flag = 0;
      }
      if((val % 10) > rem)
      {
        neg_flag = 0;
        pos_flag = 1;
        eq_flag = 0;
      }
      if((val % 10) == rem)
      {
        neg_flag = 0;
        pos_flag = 0;
        eq_flag = 1;
      }

      if (pos_flag && prev_neg_flag)
      {
        consistency_flag = 0;
        num = 0;
      }
      else if (neg_flag && prev_pos_flag)
      {
        consistency_flag = 0;
        num = 0;
      }
      else
      {
        consistency_flag = 1;
      }
      num = num / 10;
    }

    if (consistency_flag == 1 && pos_flag == 1)
    {
      posArr[*pos] = original_val;
      (*pos)++;
    }
    else if (consistency_flag == 1 && neg_flag == 1)
    {
      negArr[*neg] = original_val;
      (*neg)++;
    }
    else
    {
      eqArr[*eq] = original_val;
      (*eq)++;
    }

  }

  return ;
}


/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: printOutput
 *
 *     Programmer's Name: Ayomide D. Akande
 *
 *     Function Return Type: void
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1.int numbers[]
 *       2.
 *       3.
 *
 *     Function Description: Prints out the calculated values.
 *
 ***************************************************************************/

void printOutput(int * neg, int * pos, int * eq, int negArr[], int posArr[], int eqArr[])
{
  int i = 0;

  printf("Negative trending digits: ");
  for(i = 0; i < (*neg) ; i++)
  {
    printf("%d ",negArr[i]);
  }

  printf("\nNumbers without trend: ");
  for(i = 0; i < (*eq) ; i++)
  {
    printf("%d ",eqArr[i]);
  }

  printf("\nPositive trending digits: ");
  for(i = 0; i < (*pos) ; i++)
  {
    printf("%d ",posArr[i]);
  }

  return;
}

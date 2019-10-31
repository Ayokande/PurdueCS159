
/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. akande@purdue.edu
 *
 *  Homework #:03
 *
 *  Academic Integrity Statement:
 *
 *       I have not used source code obtained from
 *       any other unauthorized source, either modified
 *       or unmodified.  Neither have I provided access
 *       to my code to another. The project I am submitting
 *       is my own original work.
 *
 *  Lab Division and Section:Lab 40 - Lecture 4
 *
 *  Program Description: This program is designed using User Defined functions 
 *  to figure out/calculate different aspects of a collision between two carts
 *  ranging from force to energy.
 *
 ***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define CONSTANT 466
#define MIN_A 395
#define MIN_B 350
#define MIN_C 305
#define MIN_D 260

//Global Declaration
int getSeed();
char getGrade(int);
void printResults(int, char);

int main()
{
  //Variable Declaration
  int score; //numerical score of the student
  char grade; //letter grade of the student

  //Executable Statements
  score = getSeed();
  grade = getGrade(score);
  printResults(score,grade);

  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: gerSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description: Helps set the seed and determines random number produced
*
***************************************************************************/

int getSeed()
{
  //Variable Declaration
  int seed; // the random seed
  int value; // the value which is randomly generated

  //Executable Statements
  printf("Enter the seed value -> ");
  scanf("%d", &seed);

  srand(seed);
  value = rand();
  value %= CONSTANT;

  return value;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getGrade
*
*  Function Return Type: char
*
*  Parameters (list data type, name, and comment one per line):
*    1. int score 
*    2.
*    3.
*
*  Function Description: Gets the character value of grade
*
***************************************************************************/

char getGrade(int score)
{
  //Variable Declaration
  char grade; // character value of the grade
  int value; // the identifier helped in determining the grade

  //Executable Statements
  value = score / MIN_A;
  value += score / MIN_B;
  value += score / MIN_C;
  value += score / MIN_D;
  grade = 'F' - value;
  grade -= score / MIN_D; 

  return grade;
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
*    1. int score //score of the student
*    2. char grade //grade of the student
*    3.
*
*  Function Description: Helps to print out final results
*
***************************************************************************/

void printResults(int score, char grade)
{
  //Executable Statements
  printf("\nTotal Points Earned: %d\n", score);
  printf("Course Grade Earned: %c", grade);
  printf("%c\n", 'N' / (score + 1));
  return;
}

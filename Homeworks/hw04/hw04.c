/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. akande@purdue.edu
 *
 *  Homework #:04
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
 *  Program Description: Ths program uses user defined funtions and logic 
 *  statements to determine the day of a given date.
 *
 ***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

//Global Declaration
int getMonth();
int getDay();
int getYear();
int calcDecember( int year);
int calcDateInput(int day, int month, int year);
int getToday(int num_days, int december);
void printResults(int today, int day, int month, int year);

int main()
{
  //Local Declaration
  int month; // The month that is input
  int day; // The day that is input
  //int date; // The date to be printed out
  int year; // The year that is input
  int december; // December 31st of the previous year
  int num_days; // Number of elapsed days
  int today; //The date put in by user

  //Executable Statements
  month = getMonth();
  day = getDay();
  year = getYear();
  december = calcDecember (year);
  num_days = calcDateInput( month,  day,  year);
  today = getToday(num_days, december);
  printResults(today, day, month, year);

  return 0;
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: getMonth
 *
 *     Programmer's Name: Ayomide D. Akande
 *
 *     Function Return Type:int
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1.
 *       2.
 *       3.
 *
 *     Function Description: Function helps determine the inouted day
 *
 ***************************************************************************/

int getMonth()
{
  //Local Declaration
  int month; //The day to be input

  //Executable Statements
  printf("\nEnter month -> ");
  scanf("%d", &month);
  return month;
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: getDay
 *
 *     Programmer's Name: Ayomide D. Akande
 *
 *     Function Return Type:int
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1.
 *       2.
 *       3.
 *
 *     Function Description: Function helps determine the inouted day
 *
 ***************************************************************************/

int getDay()
{
  //Local Declaration
  int day; //The day to be input

  //Executable Statements
  printf("Enter day -> ");
  scanf("%d", &day);
  return day;
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function:getYear
 *
 *     Programmer's Name:Ayomide D. Akande
 *
 *     Function Return Type:int
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1.
 *       2.
 *       3.
 *
 *     Function Description:Function helps determine the inputed year
 *
 ***************************************************************************/

int getYear()
{
  //Local Declaration
  int year; //The year to be input

  //Executable Statements
  printf("Enter the year -> ");
  scanf("%d", &year);
  return year;
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: calcDecember
 *
 *     Programmer's Name:Ayomide D. Akande
 *
 *     Function Return Type:int
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1. int year // the input year
 *       2.
 *       3.
 *
 *     Function Description:Function helps determine the last day of previous year
 *
 ***************************************************************************/

int calcDecember(year)
{
  //Local Declaration
  int december; //Last day of previous year

  //Executable Statements
  december = ((365 * (year - 1)) + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
  return december;
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function:calcDateInput
 *
 *     Programmer's Name:Ayomide D. Akande
 *
 *     Function Return Type:int
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1.int day
 *       2.int year
 *       3.
 *
 *     Function Description: Funtions prints out the date input
 *
 ***************************************************************************/

int calcDateInput(int month, int day, int year)

{
  int x; //Leap year or not
  int num_days; //number of days elapsed in given year
  x =  ((!(year % 4) && (year % 100)) || !(year % 400));

  if (x == 0)
  {
    switch(month)
    {
      case 1: num_days = day;
              break;
      case 2: num_days = day + 31;
              break;
      case 3: num_days = day + 59;
              break;
      case 4: num_days = day + 90;
              break;
      case 5: num_days = day + 120;
              break;
      case 6: num_days = day + 151;
              break;
      case 7: num_days = day + 181;
              break;
      case 8: num_days = day + 212;
              break;
      case 9: num_days = day + 243;
              break;
      case 10: num_days = day + 273;
               break;
      case 11: num_days = day + 304;
               break;
      case 12: num_days = day + 334;
               break;

    }
  }
  else
  {
    switch(month)
    {
      case 1: num_days = day;
              break;
      case 2: num_days = day + 31;
              break;
      case 3: num_days = day + 60;
              break;
      case 4: num_days = day + 91;
              break;
      case 5: num_days = day + 121;
              break;
      case 6: num_days = day + 152;
              break;
      case 7: num_days = day + 182;
              break;
      case 8: num_days = day + 213;
              break;
      case 9: num_days = day + 244;
              break;
      case 10: num_days = day + 274;
               break;
      case 11: num_days = day + 305;
               break;
      case 12: num_days = day + 335;
               break;
    }

  }
  return num_days;
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: getToday
 *
 *     Programmer's Name: Ayomide D. Akande
 *
 *     Function Return Type: int
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1. int num_days
 *       2. int december
 *       3.
 *
 *     Function Description: Function helps determine the actual day of the inputed date
 *
 ***************************************************************************/

int getToday(int num_days, int december)
{
  //Local Declaration
  int today; //The day which has been put in by the user

  //Executable Statements
  today = (num_days + december) % 7;
  return today;
}

/***************************************************************************
 *
 *     Function Information
 *
 *     Name of Function: printResults
 *
 *     Programmer's Name: Ayomide D. Akande
 *
 *     Function Return Type: void
 *
 *     Parameters (list data type, name, and comment one per line):
 *       1. int today
 *       2. int day
 *       3. int month
 *       4. int year
 *
 *     Function Description: Function helps determine the actual day of the inputed date
 *
 ***************************************************************************/

void printResults(int today, int day, int month, int year)
{
  //Executable Statements
  switch(today)
  {
    case 0: printf("\nThe date %02d/%02d/%d is a: Sunday\n", month, day, year);
            break;
    case 1: printf("\nThe date %02d/%02d/%d is a: Monday\n", month, day, year);
            break;
    case 2: printf("\nThe date %02d/%02d/%d is a: Tuesday\n", month, day, year);
            break;
    case 3: printf("\nThe date %02d/%02d/%d is a: Wednesday\n", month, day, year);
            break;
    case 4: printf("\nThe date %02d/%02d/%d is a: Thursday\n", month, day, year);
            break;
    case 5: printf("\nThe date %02d/%02d/%d is a: Friday\n", month, day, year);
            break;
    case 6: printf("\nThe date %02d/%02d/%d is a: Saturday\n", month, day, year);
            break;
  }

  return;
}

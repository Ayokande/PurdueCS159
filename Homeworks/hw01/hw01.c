
/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. akande@purdue.edu
 *
 *  Homework #:1
 *
 *  Academic Integrity Statement:
 *
 *       I have not used source code obtained from
 *       any other unauthorized source, either modified
 *       or unmodified.  Neither have I provided access
 *       to my code to another. The project I am submitting
 *       is my own original work.
 *
 *  Lab Division and Section: 
 *
 *  Program Description: This program calculates temperature.
 *
 ***************************************************************************/
#include<stdio.h>

int main(void)
{
  //local variable declaration
  int hours; //time in hours
  int minutes; //time in minutes
  double time; //sum of hours and minutes after conversion
  double temp_start; //starting temperature
  double temp_end; //ending temperature (C)
  double temp_final; //ending temperature (F)

  printf("Enter the number of hours since failure -> ");
  scanf("%d", &hours);
  printf("Enter the number of minutes since failure -> ");
  scanf("%d", &minutes);
  printf("Enter the temperature at failure (C) -> ");
  scanf("%lf", &temp_start);

  time = hours + (float) minutes / 60; //calculation for time conversion
  temp_end = ((4.0 * (time * time)) / (time + 2.0)) + temp_start; //final temp in C
  temp_final = (temp_end * (float) 9 / 5) + 32; //final temp in F

  printf("\nTotal time since failure: %0.2f hours\n", time);
  printf("Ending temperature (F): %0.2lf\n", temp_final);

  return 0;
}

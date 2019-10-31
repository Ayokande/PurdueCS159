/***************************************************************************
 *
 *  Programmer and Purdue Email Address:
 *  1. akande@purdue.edu
 *
 *  Homework 02:
 *
 *  Academic Integrity Statement:
 *
 *       I have not used source code obtained from
 *       any other unauthorized source, either modified
 *       or unmodified.  Neither have I provided access
 *       to my code to another. The project I am submitting
 *       is my own original work.
 *
 *
 *  Program Description: This program is used to calculate various properties of a hexagonal prism.
 *
 ***************************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{

  //Variable Declaration
  double length_p; //length of prism
  double length_h; //length of hexagonal side
  double apothem; // apothem length
  double area_base; // hexagonal base area
  double area_side; // rectamgular side area
  double volume; // volume of prism
  double area_surface; // total surface area of the prism
  int pre_dec; // value to determine the tenths place
  int dec; // tenths place divided by 2 in int

  // Executable statements
  printf("Enter the length of the prism -> " );
  scanf("%lf", &length_p);
  printf("Enter the length of the hexagon side -> ");
  scanf("%lf", &length_h);

  //Calculations
  apothem = length_h / (2 * tan(M_PI / 6));
  area_base = (3 * (sqrt(3)) * (length_h * length_h)) / 2;
  area_side = length_h * length_p;
  volume = area_base * length_p;
  area_surface = 6 * area_side + 2 * area_base;
  pre_dec = apothem * 10;
  dec = (pre_dec % 10) / 2;

  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Apothem Length: %15.*lf\n", dec, apothem);
  printf("Base Area: %20.*lf\n", dec, area_base);
  printf("Side Area: %20.*lf\n", dec, area_side);
  printf("Prism Volume: %17.*lf\n", dec, volume);
  printf("Prism Surface Area: %11.*lf\n", dec, area_surface);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return 0;
}

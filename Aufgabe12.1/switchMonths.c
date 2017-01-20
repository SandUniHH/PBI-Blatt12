// Bocher Diedrich Sandmeier

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  January,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
} Month;

int is_leap_year(int year)
{
  if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
  {
    return 1;
  }
  return 0;
}

int month_n_days(Month m, int leap)
{
  int days;
  
  switch (m) 
  {
    case February:
      days = (leap ? 29 : 28);
      break;
    case April:
    case June:
    case September:
    case November:
      days = 30;
      break;
    default:
      days = 31;
  }
  
  return days;
}

int main(int argc, char* argv[])
{
  int leap;
  int year;
  Month month;

  // for translating the enum Month to the actual month names
  const char* month_name[12];
    month_name[0]  = "January";
    month_name[1]  = "February";
    month_name[2]  = "March";
    month_name[3]  = "April";
    month_name[4]  = "May";
    month_name[5]  = "June";
    month_name[6]  = "July";
    month_name[7]  = "August";
    month_name[8]  = "September";
    month_name[9]  = "October";
    month_name[10] = "November";
    month_name[11] = "December";

  // get and check the user input
  if (argc == 2) 
  {
    year = atoi(argv[1]);
  } 
  else 
  {
    printf("Please enter a year as parameter.\n");
    return (EXIT_FAILURE);
  }
  
  if (year < 1582)
    printf("\n The year was before the introduction of the Gregorian calendar, so the output may be incorrect.\n");
  
  leap = is_leap_year(year);
  
  for (month = 0; month < 12; month++)
  {
    printf("%s: %i\n", month_name[month], month_n_days(month, leap));
  }

  return (EXIT_SUCCESS);
}
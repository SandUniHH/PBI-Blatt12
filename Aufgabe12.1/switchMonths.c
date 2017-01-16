// Bocher Diedrich Sandmeier

#include <stdio.h>
#include <stdlib.h>

#define NUMBEROFMONTHS 12

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

bool is_leap_year(int year)
{
  if ((jahreszahl % 4 == 0) && ((jahreszahl % 100 != 0) || (jahreszahl % 400 == 0)))
  {
    return 1;
  }
  return 0;
}

int month_n_days(Month m, bool leap)
{
  int days;
  
  switch (m) 
  {
    case 2:
      days = (leap ? 29 : 28);
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      days = 30;
      break;
    default:
      days = 31;
  }
  
  return days;
}

int main(int argc, char* argv[])
{
  bool leap;
  int year, month, i;
  char month_name[NUMBEROFMONTHS] = 
  {
    'January',
    'February',
    'March',
    'April',
    'May',
    'June',
    'July',
    'August',
    'September',
    'October',
    'November',
    'December'
  }
  
  if (argc == 2) 
  {
    year = atoi(argv[1]);
  } 
  else 
  {
    printf("Please enter a year as parameter.\n");
    return (EXIT_FAILURE);
  }
  
  if (year < 1582) printf("\n The year was before the introduction of the Gregorian calendar, so the output may be incorrect.\n");
  
  leap = is_leap_year(year);
  
  for (i = 0; i < NUMBEROFMONTHS; i++)
  {
    printf("%s: %i", month_name[i], days);
  }

  return (EXIT_SUCCESS);
}
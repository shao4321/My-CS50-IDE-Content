#include <stdio.h>

int counter;

void fword(void);
void cword(void);

int main(void)
{

  fword();

  printf("\n");

  cword();

  return 0;
}

void fword(void)
{

  for(counter = 0; counter < 6 ; counter++)
  {
    printf("#");
  }
  for(counter = 0; counter < 2 ; counter++)
  {
    printf("#\n");
  }
  for(counter = 0; counter < 5 ; counter++)
  {
    printf("#");
  }
  for(counter = 0; counter < 3 ; counter++)
  {
    printf("#\n");
  }
}

void cword(void)
{

  for(counter = 0; counter < 3 ; counter++)
  {
    printf(" ");
  }
  for(counter = 0; counter < 6 ; counter++)
  {
    printf("#");
  }

  printf("\n");
  printf(" ");

  for(counter = 0; counter < 2 ; counter++)
  {
    printf("#");
  }
  for(counter = 0; counter < 6 ; counter++)
  {
    printf(" ");
  }
  for(counter = 0; counter < 2 ; counter++)
  {
    printf("#");
  }

  for(counter = 0; counter < 5 ; counter++)
  {
    printf("#\n");
  }

  printf(" ");

  for(counter = 0; counter < 2 ; counter++)
  {
    printf("#");
  }
  for(counter = 0; counter < 6 ; counter++)
  {
    printf(" ");
  }
  for(counter = 0; counter < 2 ; counter++)
  {
    printf("#");
  }

  printf("\n");

  for(counter = 0; counter < 3 ; counter++)
  {
    printf(" ");
  }
  for(counter = 0; counter < 6 ; counter++)
  {
    printf("#");
  }
  printf("\n");
}
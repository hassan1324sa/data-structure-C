#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
  char name[20];
  gets(name);
  if (name[0] >= 97 && name[0] <= 122)
  {
    name[0] -= 32;
  }
  puts(name);
}

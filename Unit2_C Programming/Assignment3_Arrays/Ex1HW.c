#include <stdio.h>

int main()
{
  /*    Ex.1    */
  char c;
  int i, count = 0;
  char text[100];
  printf("Enter a string: ");
  gets(text);
  printf("Enter a characer to find frequency: ");
  scanf("%c",&c);
  for (i=0; i<sizeof(text); i++)
  {
    if(text[i] == c)
    count++;
  }
  printf("Frequency of %c = %d",c,count);
  
    return 0;
}
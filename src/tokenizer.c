#include <stdio.h>
#include "tokenizer.h"


int main()
{
  char str[100];
  printf("Hello!\n Enter any sentence:\n  >> ");
  scanf("%[^\n]s", str);
  printf("Your string is: %s\n", str);
  
  
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maiorSub(char *str, char *sub)
{

  char *aux = malloc(strlen(str));
  if(strlen(str) < strlen(sub))
  {
    return 0;
  }

  if(strcmp(strncpy(aux, str, strlen(sub)), sub) == 0)
  {
    if (strcmp(strncpy(aux, str + strlen(str) - strlen(sub), strlen(str)), sub) == 0)
    {
      return strlen(str);
    } 
    else
    {
      return maiorSub(strncpy(aux, str, strlen(str)-1), sub);
    }
  }

  return maiorSub(strncpy(aux, str + 1, strlen(str)), sub);
}

int main(void) {

  char str[101], sub[100];

  scanf("%s %s", str, sub);

  str[strlen(str)] = '\0';
  sub[strlen(sub)] = '\0';

  printf("%d\n", maiorSub(str, sub));

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char nome[61];
  printf("Qual seu nome?\n");
  scanf("%s",nome);
  printf("\n%s é viado\n", nome);
  system("pause");
  return 0;
}
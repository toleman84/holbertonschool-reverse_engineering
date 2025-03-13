#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


int funcTwo(char param_1,char param_2,char param_3);
int funcTwenty(char param_1,char param_2,char param_3);
int funcTwelve(char param_1,char param_2,char param_3);
int funcThree(char param_1,char param_2);
int funcTen(char param_1,char param_2,char param_3);
int funcSixteen(char param_1,char param_2,char param_3);
int funcSix(char param_1,char param_2,char param_3);
int funcSeventeen(char param_1,char param_2,char param_3);
int funcSeven(char param_1,char param_2,char param_3);
int funcOne(char param_1,char param_2,char param_3);
int funcNineteen(char param_1,char param_2,char param_3);
int funcNine(char param_1,char param_2,char param_3);
int funcFourteen(char param_1,char param_2,char param_3);
int funcFour(char param_1,char param_2,char param_3);
int funcFive(char param_1,char param_2,char param_3);
int funcFifteen(char param_1,char param_2,char param_3);
int funcEleven(char param_1,char param_2,char param_3);
int funcEighteen(char param_1,char param_2,char param_3);
int funcEight(char param_1,char param_2,char param_3);

int funcOne(char param_1,char param_2,char param_3)
{
  return (int)param_3 * (int)param_1 + -100 + (int)param_2 * (int)param_1 * 0x3eb + param_3 * 0xd;
}

int funcTwo(char param_1,char param_2,char param_3)
{
  return (int)param_2 * (int)param_1 +
         (((int)param_3 * (int)param_1 + -0x491e + param_2 * 0x65) -
         ((int)param_2 + (int)param_1 + 0x89));
}

int funcThree(char param_1,char param_2)
{
  return (int)(char)(param_2 + (((char)((uint)(ushort)(short)param_2 * 0x1b >> 8) >> 1) - (param_2 >> 7)) * -0x13) + (int)param_1 * (int)param_2;
}

int funcFour(char param_1,char param_2,char param_3)
{
  return (int)param_1 * (int)param_2 * (int)param_3 - (int)param_3 * (int)param_2;
}

int funcFive(char param_1,char param_2,char param_3)
{
  return ((int)param_1 + (int)param_3 * (int)param_2) % 10000;
}

int funcSix(char param_1,char param_2,char param_3)
{
  return ((int)param_1 * (int)param_2 + (int)param_3) - (int)param_3 * (int)param_2;
}

int funcSeven(char param_1,char param_2,char param_3)
{
  return ((int)param_1 * (int)param_2 + (int)param_3 * (int)param_3) - (int)param_3;
}

int funcEight(char param_1,char param_2,char param_3)
{
  return (int)param_1 * (int)param_2 * (int)param_3 - (int)param_3 * (int)param_2;
}

int funcNine(char param_1,char param_2,char param_3)
{
  return (int)param_1 + ((int)param_1 * (int)param_2 - (int)param_2 * (int)param_3) + -100;
}

int funcTen(char param_1,char param_2,char param_3)
{
  return (int)param_2 + (int)param_3 * ((int)param_1 + (int)param_2) + -10000;
}

int funcEleven(char param_1,char param_2,char param_3)
{
  return (int)param_1 * (int)param_2 + (int)param_3 * (int)param_1 * (int)param_2 + -0x539;
}

int funcTwelve(char param_1,char param_2,char param_3)
{
  return (((int)param_1 * (int)param_3 + param_2 * 10) - (int)param_1) + 0x89;
}

int funcThirteen(char param_1,char param_2,char param_3)
{
  return ((int)param_3 * (int)param_1 * (int)param_2) % 10000 + -500;
}

int funcFourteen(char param_1,char param_2,char param_3)
{
  return (int)param_3 + ((int)param_1 * (int)param_2 * (int)param_3 - (int)param_2 * (int)param_1);
}

int funcFifteen(char param_1,char param_2,char param_3)
{
  return ((int)param_3 + (int)param_1 + (int)param_2) * 0x539 - (int)param_3;
}

int funcSixteen(char param_1,char param_2,char param_3)
{
  return (((int)param_1 * (int)param_2 + param_3 * 10) - (int)param_3 * (int)param_1) + 500;
}

int funcSeventeen(char param_1,char param_2,char param_3)
{
  return param_3 * 0x65 + ((int)param_1 * (int)param_2 - (int)param_2 * (int)param_3);
}

int funcEighteen(char param_1,char param_2,char param_3)
{
  return param_1 * 0x89 + ((int)param_1 * (int)param_2 * (int)param_3 - (int)param_3 * (int)param_2);
}

int funcNineteen(char param_1,char param_2,char param_3)
{
  return ((int)param_1 + (int)param_2 + param_3 * 0x89) - (int)param_2 * (int)param_3;
}

int funcTwenty(char param_1,char param_2,char param_3)
{
  return ((int)param_1 * (int)param_2 + (int)param_3 * (int)param_3) - (int)param_3 * (int)param_1;
}

void main(int param_1, char **param_2)
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (param_1 < 2) {
    printf("Usage %s flag\n",(char *)*param_2);
    exit(1);
  }
  pcVar1 = (char *)param_2[1];
  if (*pcVar1 != 'H') {
    puts("Flag must start with \'H\'");
    exit(2);
  }
  iVar2 = funcOne(*pcVar1,pcVar1[1],pcVar1[2]);
  printf("func_1: %d\n", iVar2);
  
  iVar3 = funcTwo(pcVar1[1],pcVar1[2],pcVar1[3]);
  printf("func_2: %d\n", iVar3);

  iVar4 = funcThree(pcVar1[2],pcVar1[3]);
  printf("func_3: %d\n", iVar4);

  iVar5 = funcFour(pcVar1[3],pcVar1[4],pcVar1[5]);
  printf("func_4: %d\n", iVar5);

  iVar6 = funcFive(pcVar1[4],pcVar1[5],pcVar1[6]);
  printf("func_5: %d\n", iVar6);

  iVar7 = funcSix(pcVar1[5],pcVar1[6],pcVar1[7]);
  printf("func_6: %d\n", iVar7);

  iVar8 = funcSeven(pcVar1[6],pcVar1[7],pcVar1[8]);
  printf("func_7: %d\n", iVar8);

  iVar9 = funcEight(pcVar1[7],pcVar1[8],pcVar1[9]);
  printf("func_8: %d\n", iVar9);

  iVar2 = funcNine(pcVar1[8],pcVar1[9],pcVar1[10]);

  iVar2 = funcNine(pcVar1[8],pcVar1[9],pcVar1[10]);

  iVar2 = funcEleven(pcVar1[10],pcVar1[0xb],pcVar1[0xc]);

  iVar2 = funcTwelve(pcVar1[0xb],pcVar1[0xc],pcVar1[0xd]);

  iVar2 = funcThirteen(pcVar1[0xc],pcVar1[0xd],pcVar1[0xe]);

  iVar2 = funcFourteen(pcVar1[0xd],pcVar1[0xe],pcVar1[0xf]);

  iVar2 = funcFifteen(pcVar1[0xe],pcVar1[0xf],pcVar1[0x10]);

  iVar2 = funcSixteen(pcVar1[0xf],pcVar1[0x10],pcVar1[0x11]);
  
  puts("Wrong flag!");
  exit(2);
}

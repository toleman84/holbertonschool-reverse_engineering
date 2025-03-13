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
  if (iVar2 == 0x7a73e0) {
    iVar2 = funcTwo(pcVar1[1],pcVar1[2],pcVar1[3]);
    if (iVar2 == 0x396c) {
      iVar2 = funcThree(pcVar1[2],pcVar1[3]);
      if (iVar2 == 0x295b) {
        iVar2 = funcFour(pcVar1[3],pcVar1[4],pcVar1[5]);
        if (iVar2 == 0x110aba) {
          iVar2 = funcFive(pcVar1[4],pcVar1[5],pcVar1[6]);
          if (iVar2 == 0xcfd) {
            iVar2 = funcSix(pcVar1[5],pcVar1[6],pcVar1[7]);
            if (iVar2 == 0x1cb) {
              iVar2 = funcSeven(pcVar1[6],pcVar1[7],pcVar1[8]);
              if (iVar2 == 0x6122) {
                iVar2 = funcEight(pcVar1[7],pcVar1[8],pcVar1[9]);
                if (iVar2 == 0x16b5ac) {
                  iVar2 = funcNine(pcVar1[8],pcVar1[9],pcVar1[10]);
                  if (iVar2 == 0x5ce) {
                    iVar2 = funcNine(pcVar1[8],pcVar1[9],pcVar1[10]);
                    if (iVar2 == 0x2d0f) {
                      iVar2 = funcEleven(pcVar1[10],pcVar1[0xb],pcVar1[0xc]);
                      if (iVar2 == 0x10ce2f) {
                        iVar2 = funcTwelve(pcVar1[0xb],pcVar1[0xc],pcVar1[0xd]);
                        if (iVar2 == 0x2c6f) {
                          iVar2 = funcThirteen(pcVar1[0xc],pcVar1[0xd],pcVar1[0xe]);
                          if (iVar2 == 0x133d) {
                            iVar2 = funcFourteen(pcVar1[0xd],pcVar1[0xe],pcVar1[0xf]);
                            if (iVar2 == 0xee949) {
                              iVar2 = funcFifteen(pcVar1[0xe],pcVar1[0xf],pcVar1[0x10]);
                              if (iVar2 == 0x64d5a) {
                                iVar2 = funcSixteen(pcVar1[0xf],pcVar1[0x10],pcVar1[0x11]);
                                if (iVar2 == 0xc6c) {
                                  iVar2 = funcSeventeen(pcVar1[0x10],pcVar1[0x11],pcVar1[0x12]);
                                  if (iVar2 == 0x2d63) {
                                    iVar2 = funcEighteen(pcVar1[0x11],pcVar1[0x12],pcVar1[0x13]);
                                    if (iVar2 == 0x105869) {
                                      iVar2 = funcNineteen(pcVar1[0x12],pcVar1[0x13],pcVar1[0x14]);
                                      if (iVar2 == 0x13b1) {
                                        iVar2 = funcTwenty(pcVar1[0x13],pcVar1[0x14],pcVar1[0x15]);
                                        if (iVar2 == 0x319d) {
                                          iVar2 = funcOne(pcVar1[0x16],pcVar1[0x17],pcVar1[0x18]);
                                          if (iVar2 == 0xc33bd5) {
                                            iVar2 = funcTwo(pcVar1[0x17],pcVar1[0x18],pcVar1[0x19]);
                                            if (iVar2 == 0x4201) {
                                              iVar2 = funcThree(pcVar1[0x18],pcVar1[0x19]);
                                              if (iVar2 == 0x2d2d) {
                                                iVar2 = funcFour(pcVar1[0x19],pcVar1[0x1a],
                                                                 pcVar1[0x1b]);
                                                if (iVar2 == 0x104645) {
                                                  iVar2 = funcFive(pcVar1[0x1a],pcVar1[0x1b],
                                                                   pcVar1[0x1c]);
                                                  if (iVar2 == 0xca6) {
                                                    iVar2 = funcSix(pcVar1[0x1b],pcVar1[0x1c],
                                                                    pcVar1[0x1d]);
                                                    if (iVar2 == -0x361) {
                                                      puts("GG you can submit with this flag");
                                                      return;
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  puts("Wrong flag!");
  exit(2);
}

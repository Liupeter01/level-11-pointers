#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void show1()   //1级指针
{
          int* p = (int*)malloc(sizeof(int) * 10);
          for (int i = 0; i < 10;i++)
          {
                    printf("%d\n", p[i] = i);
          }
          free(p);
}

void show2()    //2级指针
{
          int**pp = (int**)malloc(sizeof(int*) * 10);
          printf("%p\n", pp);
          for (int i = 0; i < 10; i++)
          {
                    pp[i] = (int*)malloc(sizeof(int) * 10);
                    printf("%16p--------------->", pp+i);
                    for (int j = 0; j < 10; ++j)
                    {
                              printf("%4d", pp[i][j]=i*10+j);
                    }
                    printf("\n");
          }
          free(pp);
}

void show3()     //3级指针
{
          int*** ppp = (int***)malloc(sizeof(int**) * 10);
          printf("%p\n", ppp);
          for (int i = 0; i < 10; ++i)
          {
                    ppp[i] = (int**)malloc(sizeof(int*) * 10);
                    printf("%16p\n", ppp[i]);
                    for (int j = 0; j < 10; ++j)
                    {
                              ppp[i][j] = (int*)malloc(sizeof(int) * 10);
                              printf("%24p\n%24s", ppp[i]," ");
                              for (int k = 0; k < 10; ++k)
                              {
                                        printf("%4d", ppp[i][j][k] = i * 100 + j * 10 + k);
                              }
                              printf("\n");
                    }
                    printf("\n");
          }

}


void show5()
{
          int***** ppppp = (int*****)malloc(sizeof(int****) * 10);
          printf("%8p\n", ppppp);
          for (int i = 0; i < 10 ; ++i)
          {
                    ppppp[i]=(int****)malloc(sizeof(int***) * 10);
                    printf("%16p\n", ppppp[i]);
                    for (int j = 0; j < 10; ++j)
                    {
                              ppppp[i][j] = (int***)malloc(sizeof(int**) * 10);
                              printf("%24p\n", ppppp[i][j]);
                              for (int k = 0; k < 10; ++k)
                              {
                                        ppppp[i][j][k] = (int**)malloc(sizeof(int*) * 10);
                                        printf("%32p\n", ppppp[i][j][k]);
                                        for (int l = 0; l < 10; ++l)
                                        {
                                                  ppppp[i][j][k][l] = (int*)malloc(sizeof(int) * 10);
                                                  printf("%40p\n", ppppp[i][j][k][l]);
                                                  for (int m = 0; m < 10; ++m)
                                                  {                                                           
                                                            ppppp[i][j][k][l][m] = 10000 * i + 1000 * j + 100 * k + 10 * l + m;
                                                            printf("%48p\n", &ppppp[i][j][k][l][m]);
                                                            printf("%64d", ppppp[i][j][k][l][m]);
                                                  }
                                                  printf("\n");
                                        }
                                        printf("\n");
                              }
                              printf("\n");
                    }
                    printf("\n");
          }
}
int main()
{
          show5();
          return 0;
}

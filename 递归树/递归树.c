#include<stdio.h>
#include<stdlib.h>

int num = 0;


void go(int data)
{
          num++;
          if (data == 0)
          {
                    return;
          }
          else
          {
                    /*
                    *ѭ�������еݹ�
                    *�ݹ�������ѭ��
                    */
                    for (int i = 0; i < 10; ++i)
                    {
                                 go(data - 1);
                    }
          }
}

int main()
{
          go(1);             //go(n) = 1 + 10*n
          printf("%d", num);
          return 0;
}
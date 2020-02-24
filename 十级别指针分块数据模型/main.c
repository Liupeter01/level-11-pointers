/*
*QQ十级指针演示demo
*分块数据模型
*author:LPH
*/
#include"data.h"

int main()
{
          init();
          while (1)
          {
                    char str[100] = { 0 };
                    printf("请输入要查找的：");
                    scanf("%s", str);
                    printf("\n");
                    search(str);
                    puts("search over\n");
          }
          return 0;
}
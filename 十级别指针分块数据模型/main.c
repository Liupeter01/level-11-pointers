/*
*QQʮ��ָ����ʾdemo
*�ֿ�����ģ��
*author:LPH
*/
#include"data.h"

int main()
{
          init();
          while (1)
          {
                    char str[100] = { 0 };
                    printf("������Ҫ���ҵģ�");
                    scanf("%s", str);
                    printf("\n");
                    search(str);
                    puts("search over\n");
          }
          return 0;
}
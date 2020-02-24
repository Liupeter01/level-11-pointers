#include"data.h"

char*********** all = NULL;   //11��ָ��
//all[1][2][3][4]......
char* path = "D:\\8000��QQ����.txt";   //�ļ�·��

int judge_num(char* str)//�ж��Ƿ�QQ������Ķ��������ַ�
{
          int flag = 0;
          char* p = str;
          while (*p != '\0')
          {
                    if ('0' <= *p && *p <= '9')
                    {
                              flag = 1;
                    }
                    p++;
          }
          return flag;     //����1����ȫ�����������ַ�
}

int chartonum(char str)   //�ַ�ת���֣�all���±������������
{
          return str - '0';
}

/*
*�ݹ���
*/

//2810600695
void memoryallocation(char** pp, int deep, char* str)   //ʮ��ָ�����
{
          /*
          *�����ַ���
          */
          if (deep == 1)   //1��ָ��
          {
                    //str+10-deepָ�������һ��Ԫ��
                    pp[  chartonum(*(str + 10 - deep))  ] = (char*)calloc(50, sizeof(char));     //�ַ�ָ������
                    return;
          }

          /*
          *���·���ָ������
          */
          if(deep == 11)    //����һ��
          {
                    memoryallocation(*pp, deep - 1, str);  //�ݹ����
                    return;
          }

          /*
          *�м��
          */
          if ( pp[ chartonum(*(str + 10 - deep)) ] !=0)   
          {
                    memoryallocation( pp[ chartonum(*(str + 10 - deep)) ] , deep - 1, str);  //�ݹ����
          }
          else
          {
                    pp[ chartonum(*(str + 10 - deep)) ] = (char*)calloc(10, sizeof(char));
                    memoryallocation( pp[ chartonum(*(str + 10 - deep)) ], deep - 1, str);  //�ݹ����
          }
}

/*
*�ַ�����QQ��ȡ
*/
char* convertqq(char* str)
{
          int length = strlen(str);
          char* temp = (char*)malloc(sizeof(char) * (length + 1));    //�������ջ�ڴ�ת�Ƶ����ڴ�
          strcpy(temp, str);
          char* p = strchr(temp, '-');    //����һ���ַ�
          if (p != NULL)
          {
                    *p = '\0';
          }
          /*
          *δ��10λ��QQ�����0
          */
          //1234560000'\0'
          //0000123456'\0'
          int count = strlen(temp);      //6
          if (count < 10)
          {
                    for (int i = 10; i >= 0; i--, count--)   //6--
                    {
                              if (count >= 0)
                              {
                                        temp[i] = temp[count];
                              }
                              else
                              {
                                        temp[i] = '0';
                              }
                   }
          }
          return temp;
}

//2810600695

void init()   //��ʼ��
{
          all = (char*)calloc(10, sizeof(char*));        //����ָ������
          FILE* pf = fopen(path, "r");
          if (pf == NULL)
          {
                    printf("��ʧ��\n");
                    return ;
          }
          else
          {
                    for (int i = 0; i < N; ++i)
                    {
                              char str[50] = { 0 };
                              fgets(str, 50, pf);
                              char* tempstr = convertqq(str);   //��QQ�ŵĴ�����ӹ�
                              if (judge_num(tempstr))  //���tempstr�ж��������򷵻�1
                              {
                                        memoryallocation(&all, 11, tempstr);  //�����ڴ�
                                        strcpy(all[chartonum(tempstr[0])][chartonum(tempstr[1])][chartonum(tempstr[2])]\
                                                  [chartonum(tempstr[3])][chartonum(tempstr[4])][chartonum(tempstr[5])]\
                                                  [chartonum(tempstr[6])][chartonum(tempstr[7])][chartonum(tempstr[8])]\
                                                  [chartonum(tempstr[9])], str);
                              }
                              else
                              {
                                        printf("���ڷǷ����ַ�\n");
                              }

                    }
                    fclose(pf);
          }
}


void search(char *str)
{
          if (judge_num(str) || strlen(str) > 10)
          {
                    return;
          }
          else
          {
                    /*
                    *���0
                    */
                    char* temp = (char*)malloc(11);
                    int count = strlen(str);
                    if (count < 10)
                    {
                              for (int i = 10; i >= 0; --i, count--)
                              {
                                        if (count >= 0)
                                        {
                                                  temp[i] = str[count];
                                        }
                                        else
                                        {
                                                  temp[i] = '\0';   //���'\0'
                                        }
                              }
                    }
                    else
                    {
                              printf("QQ���벻�Ϸ�\n");
                              return;
                    }

                    /*
                    *
                    */
                    if (all[chartonum(temp[0])])          //
                    {
                              if (all[chartonum(temp[0])][chartonum(temp[1])])
                              {
                                        if (all[chartonum(temp[0])][chartonum(temp[1])][chartonum(temp[2])])
                                        {
                                                  if (all[chartonum(temp[0])][chartonum(temp[1])][chartonum(temp[2])][chartonum(temp[3])])
                                                  {
                                                            if (all[chartonum(temp[0])][chartonum(temp[1])][chartonum(temp[2])][chartonum(temp[3])][chartonum(temp[4])])
                                                            {
                                                                      if (all[chartonum(temp[0])][chartonum(temp[1])][chartonum(temp[2])][chartonum(temp[3])][chartonum(temp[4])][chartonum(temp[5])])
                                                                      {
                                                                                if (all[chartonum(temp[0])][chartonum(temp[1])][chartonum(temp[2])][chartonum(temp[3])][chartonum(temp[4])][chartonum(temp[5])][chartonum(temp[6])])
                                                                                {
                                                                                          if (all[chartonum(temp[0])][chartonum(temp[1])][chartonum(temp[2])][chartonum(temp[3])][chartonum(temp[4])][chartonum(temp[5])][chartonum(temp[6])][chartonum(temp[7])])
                                                                                          {
                                                                                                    if (all[chartonum(temp[0])][chartonum(temp[1])][chartonum(temp[2])][chartonum(temp[3])][chartonum(temp[4])][chartonum(temp[5])][chartonum(temp[6])][chartonum(temp[7])][chartonum(temp[8])])
                                                                                                    {
                                                                                                              if (all[chartonum(temp[0])][chartonum(temp[1])][chartonum(temp[2])][chartonum(temp[3])][chartonum(temp[4])][chartonum(temp[5])][chartonum(temp[6])][chartonum(temp[7])][chartonum(temp[8])][chartonum(temp[9])])
                                                                                                              {
                                                                                                                        printf("%s\n", all[chartonum(temp[0])][chartonum(temp[1])][chartonum(temp[2])][chartonum(temp[3])][chartonum(temp[4])][chartonum(temp[5])][chartonum(temp[6])][chartonum(temp[7])][chartonum(temp[8])][chartonum(temp[9])]);
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
                    printf("û���ҵ���\n");

          }
}
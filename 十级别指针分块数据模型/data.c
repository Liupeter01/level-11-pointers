#include"data.h"

char*********** all = NULL;   //11级指针
//all[1][2][3][4]......
char* path = "D:\\8000万QQ数据.txt";   //文件路径

int judge_num(char* str)//判断是否QQ号里面的都是数字字符
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
          return flag;     //返回1代表全部都是数字字符
}

int chartonum(char str)   //字符转数字，all的下标里必须是数字
{
          return str - '0';
}

/*
*递归树
*/

//2810600695
void memoryallocation(char** pp, int deep, char* str)   //十级指针分配
{
          /*
          *分配字符串
          */
          if (deep == 1)   //1级指针
          {
                    //str+10-deep指的是最后一个元素
                    pp[  chartonum(*(str + 10 - deep))  ] = (char*)calloc(50, sizeof(char));     //字符指针数组
                    return;
          }

          /*
          *以下分配指针数组
          */
          if(deep == 11)    //最深一层
          {
                    memoryallocation(*pp, deep - 1, str);  //递归调用
                    return;
          }

          /*
          *中间层
          */
          if ( pp[ chartonum(*(str + 10 - deep)) ] !=0)   
          {
                    memoryallocation( pp[ chartonum(*(str + 10 - deep)) ] , deep - 1, str);  //递归调用
          }
          else
          {
                    pp[ chartonum(*(str + 10 - deep)) ] = (char*)calloc(10, sizeof(char));
                    memoryallocation( pp[ chartonum(*(str + 10 - deep)) ], deep - 1, str);  //递归调用
          }
}

/*
*字符串的QQ截取
*/
char* convertqq(char* str)
{
          int length = strlen(str);
          char* temp = (char*)malloc(sizeof(char) * (length + 1));    //将传入的栈内存转移到堆内存
          strcpy(temp, str);
          char* p = strchr(temp, '-');    //查找一个字符
          if (p != NULL)
          {
                    *p = '\0';
          }
          /*
          *未满10位的QQ号填充0
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

void init()   //初始化
{
          all = (char*)calloc(10, sizeof(char*));        //分配指针数组
          FILE* pf = fopen(path, "r");
          if (pf == NULL)
          {
                    printf("打开失败\n");
                    return ;
          }
          else
          {
                    for (int i = 0; i < N; ++i)
                    {
                              char str[50] = { 0 };
                              fgets(str, 50, pf);
                              char* tempstr = convertqq(str);   //对QQ号的处理与加工
                              if (judge_num(tempstr))  //如果tempstr中都是数字则返回1
                              {
                                        memoryallocation(&all, 11, tempstr);  //分配内存
                                        strcpy(all[chartonum(tempstr[0])][chartonum(tempstr[1])][chartonum(tempstr[2])]\
                                                  [chartonum(tempstr[3])][chartonum(tempstr[4])][chartonum(tempstr[5])]\
                                                  [chartonum(tempstr[6])][chartonum(tempstr[7])][chartonum(tempstr[8])]\
                                                  [chartonum(tempstr[9])], str);
                              }
                              else
                              {
                                        printf("存在非法的字符\n");
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
                    *填充0
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
                                                  temp[i] = '\0';   //填充'\0'
                                        }
                              }
                    }
                    else
                    {
                              printf("QQ号码不合法\n");
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
                    printf("没有找到！\n");

          }
}
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#define N 10000000

void init();   //初始化
char* convertqq(char* str);  //QQ号的加工预处理
int judge_num(char*str);//判断是否QQ号里面的都是数字字符
int chartonum(char str);   //字符转数字
void memoryallocation(char **pp,int deep,char *str);   //十级指针分配
void search(char* str);
#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

#define N 10000000

void init();   //��ʼ��
char* convertqq(char* str);  //QQ�ŵļӹ�Ԥ����
int judge_num(char*str);//�ж��Ƿ�QQ������Ķ��������ַ�
int chartonum(char str);   //�ַ�ת����
void memoryallocation(char **pp,int deep,char *str);   //ʮ��ָ�����
void search(char* str);
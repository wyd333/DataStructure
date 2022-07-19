#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>


//#define MAX 10000
//struct Stack
//{
//	STDataType a[MAX];
//	int top;
//};
typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
// »Î’ª
void StackPush(Stack* ps, STDataType x);
// ≥ˆ’ª
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);

int StackSize(Stack* ps);
bool StackEmpty(Stack* ps);

#ifndef STACK_H
#define STACK_H

#define MAX	32

#include <stdio.h>
#include <stdlib.h>
#include "Linked.h"

typedef List Stack;


void CreateStack(Stack *s);
void Push(Stack *s, int angka);
int Pop(Stack *s);
int isEmpty(Stack s);
void Convert(int angka);
void PrintStack(Stack s);
void ClearStack(Stack *s);

#endif

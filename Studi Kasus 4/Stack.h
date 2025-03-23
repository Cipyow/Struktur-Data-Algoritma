#ifndef STACK_H
#define STACK_H

#include "Linked.h"

typedef List Stack;


void CreateStack(Stack *s);
void Push(Stack *s, int angka);
int Pop(Stack *s);
void PrintStack(Stack s);
void ClearStack(Stack *s);

#endif

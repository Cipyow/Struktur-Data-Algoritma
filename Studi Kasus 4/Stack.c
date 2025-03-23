#include "Stack.h"

void CreateStack(Stack *s) {
	CreateList(s);
}

void Push(Stack *s, infotype X) {
	InsertFirst(s, X);
}

int Pop(Stack *s){
	if(IsEmpty){
		printf("Stack kosong!\n");
		return -1;
	}
	
	int value = s->First->info;
	DeleteFirst(s);
	
	return value;
}

void ClearStack(Stack *s){
	DeleteAll(s);
}

void PrintStack(Stack s) {
	PrintList(s);
}

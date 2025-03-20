#include "Stack.h"

void CreateStack(Stack *s) {
	CreateList(s);
}

void Push(Stack *s, infotype X) {
	InsertFirst(s, X);
}

int Pop(Stack *s){
	if(isEmpty){
		printf("Stack kosong!\n");
		return -1;
	}
	
	int value = s->First->info;
	DeleteFirst(s);
	
	return value;
}

int isEmpty(Stack s) {
	return (s.First == NULL);
}

void Convert(int angka) {
	Stack s;
	CreateStack(&s);
	
	if(angka == 0) {
		printf("Biner: 0\n");
		return;
	}
	
	while(angka > 0) {
		Push(&s, angka % 2);
		angka = angka / 2;
	}
	
	PrintStack(s);
	
	ClearStack(&s);
}

void ClearStack(Stack *s){
	DealokasiList(s);
}

void PrintStack(Stack s) {
	PrintList(s);
}

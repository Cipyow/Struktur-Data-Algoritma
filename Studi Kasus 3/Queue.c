#include "Queue.h"

void CreateQueue (Queue *Q) {
	CreateList (Q);
}

void Enqueue (Queue *Q, infotype X) {
	InsertLast (Q,X);
}

void Dequeue (Queue *Q) {
	DeleteFirst (Q);
}

void PrintQueue (Queue Q) {
	PrintList (Q);
}

void ClearQueue (Queue *Q) {
	DeleteAll (Q);
}

#ifndef QUEUE_H
#define QUEUE_H

#include "Linked.h"

typedef List Queue;

void CreateQueue (Queue *Q);
void Enqueue (Queue *Q, infotype X);
void Dequeue (Queue *Q);
void PrintQueue (Queue Q);
void ClearQueue (Queue *Q);

#endif

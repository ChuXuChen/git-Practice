#pragma once
#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

#define ElemType int

typedef struct QueueNode
{
	ElemType data;
	struct QueueNode* next;
}Node,*PNode;

typedef struct LinkQueue
{
	PNode front;
	PNode tail;
}LinkQueue;

void InitQueue(LinkQueue* Q);
void EnQueue(LinkQueue* Q, ElemType x);
void ShowQueue(LinkQueue* Q);
void DeQueue(LinkQueue* Q);
void GetHead(LinkQueue* Q, ElemType* v);
int Length(LinkQueue* Q);
void ClearQueue(LinkQueue* Q);
void Destroy(LinkQueue* Q);

#endif //__LINKQUEUE_H__
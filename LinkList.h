#pragma once

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int ElemType;

typedef struct LinkNode
{
	ElemType data;
	LinkNode *next;
}LinkNode;

typedef LinkNode *List;

void InitList(List *head);
void CreateList(List *head);
void ShowList(List head);
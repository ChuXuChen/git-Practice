#pragma once
#ifndef __DCLinkList_H__
#define __DCLinkList_H__

#include<stdio.h>
#include<assert.h>
#include<malloc.h>

#define ElemType int

typedef struct Node
{
	ElemType data;
	struct Node* prior;
	struct Node* next;
}Node,*PNode;

typedef struct DCList
{
	PNode first;
	PNode last;
	int size;
}List;

Node* buyNode(ElemType x);
void InitDCList(List* List);
void push_back(List* List, ElemType x);
void push_front(List* List, ElemType x);
void show_list(List* List);
void pop_back(List* List);
void pop_front(List* List);
void insert_val(List* List, ElemType x);
Node* find(List* List, ElemType key);
int length(List* List);
void delete_val(List* List, ElemType v);
void sort(List* List);
void resver(List* List);
void clear(List* List);
void destroy(List* List);

#endif //__DCLinkList_H__
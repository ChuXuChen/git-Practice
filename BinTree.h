#pragma once

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<string.h>

#define ElemType char

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode* root;
	ElemType refvalue;
}BinTree;

void InitBinTree(BinTree* bt, ElemType ref);
void CreateBinTree(BinTree* bt, ElemType* str);
void CreateBinTree(BinTree* bt, BinTreeNode*& t, ElemType*& str);

void PreOrder(BinTree* bt);
void PreOrder(BinTreeNode* t);
void InOrder(BinTree* bt);
void InOrder(BinTreeNode* t);
void PostOrder(BinTree* bt);
void PostOrder(BinTreeNode* t);
void LevelOrder(BinTree* bt);
void LevelOrder(BinTreeNode* t);

int Size(BinTree* bt);
int Size(BinTreeNode* t);
int Height(BinTree* bt);
int Height(BinTreeNode* t);
BinTreeNode* Search(BinTree* bt, ElemType key);
BinTreeNode* Search(BinTreeNode* t, ElemType key);
BinTreeNode* Parent(BinTree* bt, BinTreeNode* p);
BinTreeNode* Parent(BinTreeNode* t, BinTreeNode* p);
BinTreeNode* LeftChild(BinTreeNode* p);
BinTreeNode* RightChild(BinTreeNode* p);

bool BinTreeEmpty(BinTree* bt);
void CopyTree(BinTree* bt1, BinTree* bt2);
void CopyTree(BinTreeNode*& t1, BinTreeNode* t2);
void BinTreeClear(BinTree* bt);
void BinTreeClear(BinTreeNode*& t);

void PreOrder_1(BinTree* bt);
void PreOrder_1(BinTreeNode* t);
void InOrder_1(BinTree* bt);
void InOrder_1(BinTreeNode* t);
void PostOrder_1(BinTree* bt);
void PostOrder_1(BinTreeNode* t);

void CreateBinTree_1(BinTree* bt, char* VLR, char* LVR, int n);
void CreateBinTree_1(BinTreeNode*& t, char* VLR, char* LVR, int n);
#pragma warning(disable:4996)
#include"BinTree.h"
#include"Queue.h"
#include"Stack.h"

void InitBinTree(BinTree* bt, ElemType ref)
{
	bt->root = NULL;
	bt->refvalue = ref;
}
void CreateBinTree(BinTree* bt, ElemType* str)
{
	CreateBinTree(bt, bt->root, str);
}
void CreateBinTree(BinTree* bt, BinTreeNode*& t, ElemType*& str)
{
	if ((*str) == bt->refvalue)
		t = NULL;
	else
	{
		t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = *str;
		CreateBinTree(bt, t->leftChild, ++str);
		CreateBinTree(bt, t->rightChild, ++str);
	}
}
void PreOrder(BinTree* bt)
{
	PreOrder(bt->root);
}
void PreOrder(BinTreeNode* t)
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrder(t->leftChild);
		PreOrder(t->rightChild);
	}
}
void InOrder(BinTree* bt)
{
	InOrder(bt->root);
}
void InOrder(BinTreeNode* t)
{
	if (t != NULL)
	{
		InOrder(t->leftChild);
		printf("%c ", t->data);
		InOrder(t->rightChild);
	}
}
void PostOrder(BinTree* bt)
{
	PostOrder(bt->root);
}
void PostOrder(BinTreeNode* t)
{
	if (t != NULL)
	{
		PostOrder(t->leftChild);
		PostOrder(t->rightChild);
		printf("%c ", t->data);
	}
}
void LevelOrder(BinTree* bt)
{
	LevelOrder(bt->root);
}
void LevelOrder(BinTreeNode* t)
{
	LinkQueue Q;
	InitQueue(&Q);
	BinTreeNode* v;
	if (t != NULL)
	{
		EnQueue(&Q, t);
		while (!IsEmpty(&Q))
		{
			GetHead(&Q, &v);
			DeQueue(&Q);
			printf("%c ", v->data);
			if (v->leftChild != NULL)
				EnQueue(&Q, v->leftChild);
			if (v->rightChild != NULL)
				EnQueue(&Q, v->rightChild);
		}
	}
}
////////////////////////////////////////////////////////////////
int Size(BinTree* bt)
{
	return Size(bt->root);
}
int Size(BinTreeNode* t)
{
	if (t == NULL)
		return 0;
	else
		return Size(t->leftChild) + Size(t->rightChild) + 1;
}
int Height(BinTree* bt)
{
	return Height(bt->root);
}
int Height(BinTreeNode* t)
{
	if (t == NULL)
		return 0;
	else
		return Height(t->leftChild) + 1 > Height(t->rightChild) + 1 
		? Height(t->leftChild) + 1 : Height(t->rightChild) + 1;
}
BinTreeNode* Search(BinTree* bt, ElemType key)
{
	return Search(bt->root, key);
}
BinTreeNode* Search(BinTreeNode* t, ElemType key)
{
	if (t == NULL)
		return NULL;
	if (t->data == key)
		return t;
	if (Search(t->leftChild, key)!=NULL)
		return Search(t->leftChild, key);
	return Search(t->rightChild, key);
}
BinTreeNode* Parent(BinTree* bt, BinTreeNode* p)
{
	return Parent(bt->root, p);
}
BinTreeNode* Parent(BinTreeNode* t, BinTreeNode* p)
{
	if (t == NULL || p == NULL)
		return NULL;
	if (t->leftChild == p || t->rightChild == p)
		return t;
	if (Parent(t->leftChild, p) != NULL)
		return Parent(t->leftChild, p);
	return Parent(t->rightChild, p);
}
BinTreeNode* LeftChild(BinTreeNode* p)
{
	if (p != NULL)
		return p->leftChild;
	return NULL;
}
BinTreeNode* RightChild(BinTreeNode* p)
{
	if (p != NULL)
		return p->rightChild;
	return NULL;
}
bool BinTreeEmpty(BinTree* bt)
{
	return bt->root==NULL;
}
void CopyTree(BinTree* bt1, BinTree* bt2)
{
	CopyTree(bt1->root, bt2->root);
}
void CopyTree(BinTreeNode*& t1, BinTreeNode* t2)
{
	if (t2 == NULL)
		t1 = NULL;
	else
	{
		t1 = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t1 != NULL);
		t1->data = t2->data;
		CopyTree(t1->leftChild, t2->leftChild);
		CopyTree(t1->rightChild, t2->rightChild);
	}
}
void BinTreeClear(BinTree* bt)
{
	BinTreeClear(bt->root);
}
void BinTreeClear(BinTreeNode*& t)
{
	if (t != NULL)
	{
		BinTreeClear(t->leftChild);
		BinTreeClear(t->rightChild);
		free(t);
		t = NULL;
	}
}

//////////////////////////////////////////////////////////////////////////
void PreOrder_1(BinTree* bt)
{
	PreOrder_1(bt->root);
}
void PreOrder_1(BinTreeNode* t)
{
	if (t != NULL)
	{
		Stack st;
		InitStack(&st);
		BinTreeNode* p;
		Push(&st, t);
		while (!IsEmpty(&st))
		{
			GetTop(&st, &p);
			Pop(&st);
			printf("%c ", p->data);
			if (p->rightChild != NULL)
				Push(&st,p->rightChild);
			if (p->leftChild != NULL)
				Push(&st, p->leftChild);
		}
	}
}
void InOrder_1(BinTree* bt)
{
	InOrder_1(bt->root);
}
void InOrder_1(BinTreeNode* t)
{
	if (t != NULL)
	{
		Stack st;
		InitStack(&st);
		BinTreeNode* p;
		Push(&st, t);
		while (!IsEmpty(&st))
		{
			while (t->leftChild != NULL)
			{
				Push(&st, t->leftChild);
				t = t->leftChild;
			}
			GetTop(&st, &p);
			Pop(&st);
			printf("%c ", p->data);
			if (p->rightChild != NULL)
			{
				t = p->rightChild;
				Push(&st, t);
			}
		}
	}
}
void PostOrder_1(BinTree* bt)
{
	PostOrder_1(bt->root);
}
void PostOrder_1(BinTreeNode* t)
{

}

void CreateBinTree_1(BinTree* bt, char* VLR, char* LVR, int n)
{
	CreateBinTree_1(bt->root, VLR, LVR, n);
}
void CreateBinTree_1(BinTreeNode*& t, char* VLR, char* LVR, int n)
{
	if (n == 0)
		t = NULL;
	else
	{
		int k = 0;
		while (VLR[0] != LVR[k])
			k++;
		t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = LVR[k];
		CreateBinTree_1(t->leftChild, VLR + 1, LVR, k);
		CreateBinTree_1(t->rightChild, VLR + 1 + k, LVR+k+1, n-k-1);
	}
}
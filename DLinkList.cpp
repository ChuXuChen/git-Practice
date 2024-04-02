#include"DLinkList.h"

Node* buyNode(ElemType x)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	s->data = x;
	s->prior = s->next = NULL;
	return s;
}
void InitDList(List* List)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	List->first = List->last = s;
	List->last->next = NULL;
	List->first->prior = NULL;
}
void push_back(List* List, ElemType x)
{
	Node *s = buyNode(x);
	s->prior = List->last;
	List->last->next = s;
	List->last = s;
	List->size++;
}
void push_front(List* List, ElemType x)
{
	Node* s = buyNode(x);
	if (List->first == List->last)
	{
		List->last = s;
	}
	else
	{
		s->next = List->first->next;
		s->next->prior = s;
	}
	s->prior = List->first;
	List->first->next = s;
	List->size++;
}
void show_list(List* List)
{
	Node* p = List->first->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Nul.\n");
}
void pop_back(List* List)
{
	if (List->size == 0)
		return;
	Node* p = List->first;
	while (p->next != List->last)
	{
		p = p->next;
	}
	free(List->last);
	List->last = p;
	List->last->next = NULL;
	List->size--;
}
void pop_front(List* List)
{
	if (List->size == 0)
		return;
	Node* p = List->first->next;
	if (List->size == 1)
	{
		List->last = List->first;
		List->first->next = NULL;
	}
	else
	{
		p->next->prior = List->first;
		List->first->next = p->next;
	}
	free(p);
	List->size--;
}
void insert_val(List* List, ElemType x)
{
	Node* p = List->first;
	while (p->next != NULL&&p->next->data<x)
	{
		p = p->next;
	}
	if (p->next == NULL)
	{
		push_back(List, x);
	}
	else
	{
		Node* s = buyNode(x);
		s->next = p->next;
		s->next->prior = s;
		s->prior = p;
		p->next = s;
		List->size++;
	}
}
Node* find(List* List, ElemType key)
{
	Node* p = List->first->next;
	while (p != NULL && p->data != key)
	{
		p = p->next;
	}
	return p;
}
int length(List* List)
{
	return List->size;
}
void delete_val(List* List, ElemType v)
{
	if (List->size == 0)
		return;
	Node* p = find(List, v);
	if (p == NULL)
	{
		printf("待删除的数据不存在\n");
	}
	if (p == List->last)
	{
		List->last = p->prior;
		List->last->next = NULL;
	}
	else
	{
		p->next->prior = p->prior;
		p->prior->next = p->next;
	}
	free(p);
	List->size--;
}
void sort(List* List)
{
	if (List->size == 0 || List->size == 1)
		return;
	Node *s = List->first->next;
	Node *q = s->next;
	List->last = s;
	List->last->next = NULL;
	while (q != NULL)
	{
		s = q;
		q = q->next;

		Node *p = List->first;
		while (p->next != NULL && p->next->data < s->data)
		{
			p = p->next;
		}
		if (p->next == NULL)
		{
			s->next = NULL;
			s->prior = List->last;
			List->last->next = s;
			List->last = s;
		}
		else
		{
			s->next = p->next;
			s->next->prior = s;
			s->prior = p;
			p->next = s;
			List->size++;
		}
	}
}
void resver(List* List)
{
	if (List->size == 0 || List->size == 1)
		return;
	Node* p = List->first->next;
	Node* q = p->next;
	List->last = p;
	List->last->next = NULL;
	while (q != NULL)
	{
		p = q; 
		q = q->next;
		p->next = List->first->next;
		p->prior = List->first;
		List->first->next = p;
	}
}
void clear(List* List)
{
	if (List->size == 0)
		return;
	Node* p = List->first->next;
	while (p != NULL)
	{
		if (p == List->last)
		{
			List->last = List->first;
			List->last->next = NULL;
		}
		else
		{
			p->next->prior = List->first;
			List->first->next = p->next;
		}
		free(p);
		p = List->first->next;
	}
	List->size = 0;
}
void destroy(List* List)
{
	clear(List);
	free(List->first);
	List->first = List->last = NULL;
}
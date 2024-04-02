#pragma warning(disable:4996)
#include"DCLinkList.h"

Node* buyNode(ElemType x)
{
	Node* s = (Node*)malloc(sizeof(Node));
	s->data = x;
	s->prior = s->next = NULL;
	return s;
}
void InitDCList(List* List)
{
	Node* s = (Node*)malloc(sizeof(Node));
	assert(s != NULL);
	List->first = List->last=s;
	List->first->prior = List->last;
	List->last->next = List->first;
	List->size = 0;
}
void push_back(List* List, ElemType x)
{
	Node* s = buyNode(x);
	s->next = List->last->next;
	s->next->prior = s;
	s->prior = List->last;
	List->last->next = s;
	List->last = s;
	List->size++;
}
void push_front(List* List, ElemType x)
{
	Node *s = buyNode(x);
	s->next = List->first->next;
	s->next->prior = s;
	s->prior = List->first;
	List->first->next = s;
	if (List->first == List->last)
		List->last = s;
	List->size++;
}
void show_list(List* List)
{
	Node* p = List->first->next;
	while (p != List->first)
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
	Node* p = List->last;
	List->last = List->last->prior;
	p->next->prior = p->prior;
	p->prior->next = p->next;
	free(p);
	List->size--;
}
void pop_front(List* List)
{
	if (List->size == 0)
		return;
	if (List->size == 1)
	{
		free(List->last);
		List->last = List->first;
	}
	else
	{
		Node* p = List->first->next;
		p->next->prior = p->prior;
		p->prior->next = p->next;
		free(p);
	}
	List->size--;
}
void insert_val(List* List, ElemType x)
{
	Node* p = List->first;
	while (p->next != List->last && p->next->data < x)
		p = p->next;
	if (p->next == List->last && p->next->data < x)
		push_back(List, x);
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
	while (p != List->first && p->data != key)
		p = p->next;
	if (p == List->first)
		return NULL;
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
		printf("要删除的数据不存在。\n");
		return;
	}
	if (p == List->last)
	{
		pop_back(List);
	}
	else
	{
		p->next->prior = p->prior;
		p->prior->next = p->next;
		free(p);
		List->size--;
	}
}
void sort(List* List)
{
	if (List->size == 0 || List->size == 1)
		return;
	Node* s = List->first->next;
	Node* q = s->next;
	List->last->next = NULL;
	List->last = s;
	List->last->next = List->first;
	List->first->prior = List->last;

	while (q != NULL)
	{
		s = q;
		q = q->next;
		Node* p = List->first;
		while (p->next != List->last && p->next->data < s->data)
			p = p->next;
		if (p->next == List->last && p->next->data < s->data)
		{
			s->next = p->next->next;
			s->next->prior = s;
			s->prior = p->next;
			p->next->next = s;
			List->last = s;
		}
		else
		{
			s->next = p->next;
			s->next->prior = s;
			s->prior = p;
			p->next = s;
		}
	}
}
void resver(List* List)
{
	if (List->size == 0 || List->size == 1)
		return;
	Node* s = List->first->next;
	Node* q = s->next;
	List->last->next = NULL;
	List->last = s;
	List->last->next = List->first;
	List->first->prior = List->last;

	while (q != NULL)
	{
		s = q;
		q = q->next;
		s->next = List->first->next;
		s->next->prior = s;
		s->prior = List->first;
		List->first->next = s;
	}
}
void clear(List* List)
{
	if (List->size == 0)
		return;
	Node* p = List->first->next;
	while (p != List->first)
	{
		p->next->prior = List->first;
		List->first->next = p->next;
		free(p);
		p = List->first->next;
	}
	List->last = List->first;
	List->size = 0;
}
void destroy(List* List)
{
	clear(List);
	free(List->first);
	List->first=List->last = NULL;
}
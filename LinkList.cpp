#include"LinkList.h"

void InitList(List *head)
{
	(*head) = (LinkNode *)malloc(sizeof(LinkNode));
	assert(*head != NULL);
	((*head)->next) = NULL;
}
void CreateList(List* head)
{
	LinkNode* p = *head;
	for (int i = 1; i <= 10; ++i)
	{
		p->next = (LinkNode*)malloc(sizeof(LinkNode));
		p = p->next;
		assert(p != NULL);
		p->data = i;
		p->next = NULL;
	}
}
/*
void CreateList(List* head)
{
	for (int i = 1; i <= 10; ++i)
	{
		LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = i;
		s->next = (*head)->next;
		(*head)->next = s;
	}
}
*/
/*
void CreateList(List *head)
{
	(*head) = (LinkNode*)malloc(sizeof(LinkNode));
	assert(*head != NULL);
	(*head)->data = 1;
	(*head)->next = NULL;

	LinkNode* p = *head;
	for (int i = 2; i <= 10; ++i)
	{
		LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;

		p->next = s;
		p = s;
	}
}
*/
void ShowList(List head)
{
	LinkNode* p = head->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Nul.\n");
}
//����������Դ �༶�������1�� ѧ�ţ�1652228
#define _CRT_SECURE_NO_WARNINGS

#define ELEMTYPE_IS_INT
typedef int ElemType;

#define OK 1
#define TJOVERFLOW -2

#include <stdio.h>
#include <stdlib.h>		
#include <math.h>

#define FFLUSH while(getchar()!='\n')
#define opFor(i,r,l) for(int i=r;i>=l;--i)

typedef int Status;

typedef struct LNode 
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList *L)
{
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(TJOVERFLOW);
	(*L)->next = *L;
	return OK;
}

Status ListInsert(LinkList *L, ElemType e)
{
	LinkList s, p = *L;

	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL)
		return TJOVERFLOW;

	s->data = e;

	s->next = p->next;
	p->next = s;
	return OK;
}

LinkList ListDelete(LinkList *cur, int i, ElemType *e, LinkList L)
{
	LinkList q, p = *cur;
	int pos = 0;
	if (p->next == L)
		p = p->next;
	while (pos < i - 1) 
	{
		p = p->next;
		if (p->next == L)
			continue;
		pos++;
	}

	q = p->next;
	if (q == L)
		q = q->next;
	p->next = q->next;
	*e = q->data;

	free(q);
	return p;
}

Status DestroyList(LinkList *L)
{
	LinkList q, p = *L;

	while (p != *L) 
	{
		q = p->next;
		free(p);
		p = q;
	}

	*L = NULL;
	return OK;
}

void init(int *n, int *m, int *k)
{
	while (1)
	{
		printf("����������n=");
		if (!scanf(" %d", n))
			*n = 0;
		if (*n <= 0)
		{
			FFLUSH;
			continue;
		}
		break;
	}
	while (1)
	{
		printf("�������˳�����������m=");
		if (!scanf(" %d", m))
			*m = 0;
		if (*m <= 0)
		{
			FFLUSH;
			continue;
		}
		break;
	}
	while (1)
	{
		printf("��������ʼ���˱��k=");
		if (!scanf(" %d", k))
			*k = 0;
		if (*k <= 0)
		{
			FFLUSH;
			continue;
		}
		break;
	}
	*k %= *n;
	if (!*k)
		*k = *n;
}

void work(int n, int m, int k)
{
	LinkList L;
	InitList(&L);
	opFor(i, n, 1)
		ListInsert(&L, i);
	printf("����˳��Ϊ:\n");
	LinkList cur = L;
	opFor(i, n, 1)
	{
		int res = 0;
		int N = i == n ? k - 1 + m : m;
		N %= i;
		if (!N)
			N = i;
		
		cur = ListDelete(&cur, N, &res, L);
		printf("%d�ų���\n", res);
	}
}

int main()
{
	int n, m, k;
	init(&n, &m, &k);
	work(n, m, k);
	return 0;
}
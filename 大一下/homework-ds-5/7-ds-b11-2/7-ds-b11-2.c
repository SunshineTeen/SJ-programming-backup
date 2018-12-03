//姓名：王哲源 班级：计算机1班 学号：1652228
#define _CRT_SECURE_NO_WARNINGS

#define ELEMTYPE_IS_INT
typedef int ElemType;

#define OK 1
#define TJOVERFLOW -2

#include <stdio.h>
#include <stdlib.h>		
#include <math.h>

#define FFLUSH while(getchar()!='\n')
#define For(i,l,r) for(int i=l;i<=r;++i)
#define opFor(i,r,l) for(int i=r;i>=l;--i)

typedef int Status;

typedef struct LNode 
{
	ElemType data;
	struct LNode *next;
	struct LNode *prior;
} LNode, *LinkList;

Status InitList(LinkList *L)
{
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(TJOVERFLOW);
	(*L)->next = *L;
	(*L)->prior = *L;
	return OK;
}

Status ListInsert(LinkList *L, ElemType e)
{
	LinkList s, p = (*L)->next;

	s = (LinkList)malloc(sizeof(LNode)); 
	if (s == NULL)
		return TJOVERFLOW;

	s->data = e;

	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

LinkList ListDelete(LinkList *cur, int i, ElemType *e, LinkList L)
{
	LinkList q, p = *cur;
	int pos = 0;

	while (pos < i - 1) 
	{
		p = p->prior;
		if (p == L)
			continue;
		++pos;
	}

	q = p->prior;
	if (q == L)
		q = q->prior;

	q->prior->next = q->next;
	q->next->prior = q->prior;

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
		printf("请输入人数n=");
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
		printf("请输入退出的人所报数m=");
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
		printf("请输入起始的人编号k=");
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
	For(i, 1, n)
		ListInsert(&L, i);
	printf("出列顺序为:\n");
	LinkList cur = L;
	opFor(i, n, 1)
	{
		int res = 0;
		int N = i == n ? k - 1 + m : m;
		N %= i;
		if (!N)
			N = i;

		cur = ListDelete(&cur, N, &res, L);
		printf("%d号出列\n", res);
	}
}

int main()
{
	int n, m, k;
	init(&n, &m, &k);
	work(n, m, k);
	return 0;
}
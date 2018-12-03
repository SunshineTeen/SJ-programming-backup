//����������Դ �༶�������1�� ѧ�ţ�1652228

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		
#include <math.h>
#include <string.h>
#include <conio.h>

#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define TJOVERFLOW	-2

#define FFLUSH while(getchar()!='\n')

typedef int Status;

typedef struct
{
	double coef;
	int expn;
} ElemType;

typedef struct LNode 
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

const double eps = 1e-6;

Status InitList(LinkList *L)
{
	if ((*L = (LNode *)malloc(sizeof(LNode))) == NULL)
		exit(OVERFLOW);
	(*L)->next = NULL;
	return OK;
}

Status DestroyList(LinkList *L)
{
	LinkList q, p = *L;
	while (p) 
	{
		q = p->next;
		free(p);
		p = q;
	}
	*L = NULL;
	return OK;
}

Status ListEmpty(LinkList L)
{
	return L->next == NULL;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
	LinkList p = L->next;
	int pos = 1; 
	while (p != NULL && pos < i) 
		p = p->next,++pos;
	if (!p || pos > i)
		return ERROR;
	*e = p->data;
	return OK;
}

LinkList LocateElem(LinkList L, double expn1)
{
	LinkList p = L->next;
	while (p && fabs(p->data.expn - expn1) > eps) 
		p = p->next;
	return p;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList s, p = *L;
	int pos = 0;
	while (p && pos < i - 1) 
		p = p->next,++pos;
	if (p == NULL || pos > i - 1)
		return ERROR;

	if ((s = (LinkList)malloc(sizeof(LNode))) == NULL)
		return OVERFLOW;

	s->data=e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList *L, LinkList del)
{
	LinkList q, p = *L;
	while (p->next && p->next != del)
		p = p->next;

	if (p->next == NULL)
		return ERROR;
	q = p->next;
	p->next = q->next;
	free(q);
	return OK;
}

Status ListTraverse(LinkList L, Status(*visit)(ElemType e))
{
	LinkList p = L->next;

	while (p && (*visit)(p->data) == TRUE)
		p = p->next;
	if (p)
		return ERROR;

	printf("\n");
	return OK;
}

Status MyVisit(ElemType e)
{
	if (e.coef > 0)
		printf("+");
	printf("%.6lfx^%d", e.coef, e.expn);
	return OK;
}

Status init(LinkList *L, const int i)
{
	InitList(L);
	printf("\n");
	printf("����������");
	printf(i == 1 ? "һ" : "��");
	printf("������ʽ��\n");
	while (1)
	{
		int n;
		printf("����������");
		if (!scanf(" %d", &n))
		{
			FFLUSH;
			n = 0;
		}
		if (n <= 0)
		{
			printf("��������,");
			continue;
		}
		for (int i = 1; i <= n; ++i)
		{
			printf("�������%d���ϵ����ָ��:", i);
			ElemType e;
			if (!scanf(" %lf %d", &(e.coef), &(e.expn)))
			{
				FFLUSH;
				i -= 1;
				printf("��������,");
				continue;
			}
			ListInsert(L, 1, e);
		}
		break;
	}
	printf("����Ķ���ʽΪ:\n");
	ListTraverse(*L, MyVisit);
	printf("\n");
	return OK;
}

Status add(LinkList *La, LinkList *Lb, int op)
{
	if (*La == NULL || *Lb == NULL)
	{
		printf("��ǰ�޶���ʽ�����ȴ�����");
		return ERROR;
	}

	
	LinkList p = (*Lb)->next;
	while (p != NULL)
	{
		p->data.coef *= op;
		LinkList tmp = LocateElem(*La, p->data.expn);
		if (tmp == NULL)
			ListInsert(La, 1, p->data);
		else 
		{
			tmp->data.coef += p->data.coef;
			if (fabs(tmp->data.coef) < eps)
				ListDelete(La, tmp);
		}
		p = p->next;
	}

	printf("������ʽ��");
	printf(op == 1 ? "��" : "��");
	printf("Ϊ:\n");
	ListTraverse(*La, MyVisit);
	
	printf("\n���������������ʽ�ѱ����٣�");
	return OK;
}

int main()
{
	LinkList  La = NULL, Lb = NULL;

	while (1) 
	{
		system("cls");
		printf("----------------------\n");
		printf("1.��������ʽ\n");
		printf("2.��ǰ������ʽ��\n");
		printf("3.��ǰ������ʽ��\n");
		printf("4.ɾ����ǰ����Ķ���ʽ\n");
		printf("0.�˳�\n");
		printf("----------------------\n");
		printf("��ѡ��ģʽ[0-3]��");

		int mode;
		if (!scanf(" %d", &mode))
		{
			FFLUSH;
			mode = -1;
		}
		if (mode < 0 || mode>4)
			continue;
		if (!mode)
			break;
		
		if (mode == 1)
		{
			if (La != NULL || Lb != NULL)
			{
				printf("��ǰ�Ѵ��ڶ���ʽ������ɾ�������س�����ѡ��");
				while (_getch() != '\r');
				continue;
			}
			init(&La, 1);
			init(&Lb, 2);

			printf("\n�����ɹ����밴�س�����");
			while (_getch() != '\r');
			continue;
		}

		if (mode == 4)
		{
			DestroyList(&La);
			DestroyList(&Lb);
			printf("\nɾ���ɹ����밴�س�����");
			while (_getch() != '\r');
			continue;
		}

		add(&La, &Lb, mode == 2 ? 1 : -1);
		printf("���س�����");
		DestroyList(&La);
		DestroyList(&Lb);
		while (_getch() != '\r');
	}
	DestroyList(&La);
	DestroyList(&Lb);

	return 0;
}
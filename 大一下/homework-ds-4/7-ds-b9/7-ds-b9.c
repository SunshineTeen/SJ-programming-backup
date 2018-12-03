//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>		
#include <math.h>
#include <string.h>

#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define TJOVERFLOW	-2
#define MAX_NUM_PER_LINE 	5

typedef int Status;

int line_count;

typedef struct student
{
	int num;
	char name[10];
	char sex;
	float score;
	char addr[30];
} ElemType;
typedef struct LNode
{
	ElemType *data;
	struct LNode *next;
	struct LNode *prior;
} DulNode, *DuLinkList;

ElemType e[] = {
	{ 1001, "张三", 'M', 76.5, "上海市杨浦区" },
	{ 1002, "李四", 'F', 87, "上海市普陀区" },
	{ 1003, "王五", 'M', 80, "浙江省杭州市" },
	{ 1004, "赵六", 'M', 54, "浙江省绍兴市" },
	{ 1005, "牛七", 'F', 85, "江苏省南京市" },
	{ 1006, "马八", 'M', 60, "江苏省苏州市" } };

Status MyVisit(ElemType e)
{
	printf("num:%d name:%s sex:%c score:%.2f addr:%s ->\n", e.num, e.name, e.sex, e.score, e.addr);
	return OK;
}
Status ListTraverse(DuLinkList L, Status(*visit)(ElemType e))
{
	DuLinkList p = L->prior;

	line_count = 0;
	while (p != L && (*visit)(*(p->data)) == TRUE)
		p = p->prior;

	if (p)
		return ERROR;

	printf("\n");
	return OK;
}

DuLinkList GetElemP_Dul(DuLinkList *L, int i)
{
	DuLinkList p = (*L)->next;
	int ti = 1;
	while (p != (*L) && ti != i)
		++ti, p = p->next;
	return p;
}
Status ListDelete_Dul(DuLinkList *L, int i, ElemType *e)
{
	DuLinkList p;
	if (!(p = GetElemP_Dul(L, i)))
		return ERROR;

	(*e) = *(p->data);
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p->data);
	free(p);
	return OK;
}
Status ListInsert_Dul(DuLinkList *L, int i, ElemType e)
{
	DuLinkList p, s;
	ElemType *d;

	if (!(p = GetElemP_Dul(L, i)))
		return ERROR;
	if (!(s = (DuLinkList)malloc(sizeof(DulNode))))
		return ERROR;
	if (!(d = (ElemType *)malloc(sizeof(ElemType))))
		return ERROR;

	*d = e;
	s->data = d;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

Status InitList(DuLinkList *L)
{
	*L = (DulNode *)malloc(sizeof(DulNode));
	if (*L == NULL)
		exit(TJOVERFLOW);

	(*L)->next = (*L)->prior = *L;
	return OK;
}
Status DestroyList(DuLinkList *L)
{
	DuLinkList p = (*L)->next;

	while (p != (*L))
	{
		DuLinkList q = p->next;
		free(p);
		p = q;
	}

	DuLinkList tmp = *L;
	*L = NULL;
	free(tmp);
	return OK;
}

int main()
{
	DuLinkList  L;
	ElemType tmpe;

	int INSERT_NUM = 25;
	InitList(&L);

	for (int i = 5; i >= 0; --i)
		ListInsert_Dul(&L, 1, e[i]);
	printf("初始链表:\n");
	ListTraverse(L, MyVisit);

	printf("\n\n删除表头元素:\n");
	ListDelete_Dul(&L, 1, &tmpe);
	printf("被删除的元素是:num:%d name:%s sex:%c score:%.2f addr:%s\n", tmpe.num, tmpe.name, tmpe.sex, tmpe.score, tmpe.addr);
	printf("当前链表(倒序):\n");
	ListTraverse(L, MyVisit);

	printf("\n\n删除表中元素:\n");
	ListDelete_Dul(&L, 3, &tmpe);
	printf("被删除的元素是:num:%d name:%s sex:%c score:%.2f addr:%s\n", tmpe.num, tmpe.name, tmpe.sex, tmpe.score, tmpe.addr);
	printf("当前链表(倒序):\n");
	ListTraverse(L, MyVisit);

	printf("\n\n删除表尾元素:\n");
	ListDelete_Dul(&L, 4, &tmpe);
	printf("被删除的元素是:num:%d name:%s sex:%c score:%.2f addr:%s\n", tmpe.num, tmpe.name, tmpe.sex, tmpe.score, tmpe.addr);
	printf("当前链表(倒序):\n");
	ListTraverse(L, MyVisit);

	DestroyList(&L);
	return 0;
}

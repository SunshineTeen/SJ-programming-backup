//姓名：王哲源 班级：计算机1班 学号：1652228

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "7-ds-b2-linear_list_L.h"

/* 初始化线性表 */
Status InitList(LinkList *L)
{
	*L = NULL;
	return OK;
}

/* 删除线性表 */
Status DestroyList(LinkList *L)
{
	LinkList cur = *L;
	while (cur) 
	{
		LinkList tmp= cur->next;
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
		free(cur->data);
#endif
		free(cur);
		cur = tmp;
	}
	*L = NULL;
	return OK;
}

/* 清除线性表（与删除相同） */
Status ClearList(LinkList *L)
{
	LinkList cur = *L;
	while (cur)
	{
		LinkList tmp = cur->next;
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
		free(cur->data);
#endif
		free(cur);
		cur = tmp;
	}
	*L = NULL;
	return OK;
}

/* 判断是否为空表 */
Status ListEmpty(LinkList L)
{
	return L == NULL;
}

/* 求表的长度 */
int ListLength(LinkList L)
{
	int len = 0;
	LinkList p = L;
	while (p != NULL)
		len++, p = p->next;
	return len;
}

/* 取表中元素 */
Status GetElem(LinkList L, int i, ElemType *e)
{
	LinkList p = L;
	int pos = 1;
	while (p != NULL && pos < i) 
		pos++, p = p->next;
	if (p == NULL || pos > i)
		return ERROR;
#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	strcpy(*e, p->data);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(e, &p->data, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	memcpy(*e, p->data, sizeof(ET));
#else
	*e = p->data;
#endif
	return OK;
}

/* 查找符合指定条件的元素 */
int LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType e1, ElemType e2))
{
	LinkList p = L;
	int pos = 1;
	while (p != NULL && (*compare)(e, p->data) == FALSE)
		pos++, p = p->next;
	return p ? pos : 0;
}

/* 查找符合指定条件的元素的前驱元素 */
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e, Status (*compare)(ElemType e1, ElemType e2))
{
	LinkList p = L;
	if (p == NULL)
		return ERROR;

	while (p->next && (*compare)(cur_e, p->next->data) == FALSE)
		p = p->next;
	if (p->next == NULL)
		return ERROR;
#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	strcpy(*pre_e, p->data);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(pre_e, &p->data, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	memcpy(*pre_e, p->data, sizeof(ET));
#else
	*pre_e = p->data;
#endif
	return OK;
}

/* 查找符合指定条件的元素的后继元素 */
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e, Status (*compare)(ElemType e1, ElemType e2))
{
	LinkList p = L;
	if (p == NULL)
		return ERROR;
	while (p->next && (*compare)(cur_e, p->data) == FALSE)
		p = p->next;
	if (p->next == NULL)
		return ERROR;
#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	strcpy(*next_e, p->next->data);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(next_e, &p->next->data, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	memcpy(*next_e, p->next->data, sizeof(ET));
#else
	*next_e = p->next->data;
#endif
	return OK;
}

/* 在指定位置前插入一个新元素 */
Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList p = *L;
	int pos = 1;
	while (p != NULL && pos < i - 1)
		pos++, p = p->next;
	if (i != 1 && (p == NULL || pos > i - 1))
		return ERROR;

	LinkList New = (LinkList)malloc(sizeof(LNode));
	if (New == NULL)
		return TJOVERFLOW;
#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
#if defined (ELEMTYPE_IS_CHAR_P)
	New->data = (ElemType)malloc(strlen(e) * sizeof(ElemType));
#else
	New->data = (ElemType)malloc(sizeof(ET));
#endif
	if (New->data == NULL)
		return TJOVERFLOW;
#endif

#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	strcpy(New->data, e);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(&(New->data), &e, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	memcpy(New->data, e, sizeof(ET));
#else
	New->data = e;
#endif
	if (i == 1)
		New->next = *L, *L = New;
	else
		New->next = p->next, p->next = New;
	return OK;
}

/* 删除指定位置的元素，并将被删除元素的值放入e中返回 */
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	LinkList p = *L;
	int pos = 1;
	while (p->next && pos < i - 1)
		p = p->next, pos++;
	if (i == 1)
	{
		if (p == NULL)
			return ERROR;
	}
	else if (p->next == NULL || pos > i - 1)
		return ERROR;

	LinkList tmp;
	if (i == 1)
		tmp = *L, *L = tmp->next;
	else
		tmp = p->next, p->next = tmp->next;
#if defined (ELEMTYPE_IS_CHAR_ARRAY) || defined (ELEMTYPE_IS_CHAR_P)
	strcpy(*e, tmp->data);
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
	memcpy(e, &tmp->data, sizeof(ElemType));
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	memcpy(*e, tmp->data, sizeof(ET));
#else 
	*e = tmp->data;
#endif 

#if defined (ELEMTYPE_IS_CHAR_P) || defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
	free(tmp->data);
#endif
	free(tmp);
	return OK;
}

/* 遍历线性表 */
Status ListTraverse(LinkList L, Status (*visit)(ElemType e))
{
	extern int line_count;
	LinkList p = L;

	line_count = 0;
	while (p && (*visit)(p->data) == TRUE)
		p = p->next;
	if (p != NULL)
		return ERROR;

	printf("\n");
	return OK;
}

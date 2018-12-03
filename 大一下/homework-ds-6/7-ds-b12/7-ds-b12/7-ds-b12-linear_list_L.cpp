//姓名：王哲源 班级：计算机1班 学号：1652228

#include"7-ds-b12-linear_list_L.h"

template<class ElemType>
LinkList<ElemType>::LinkList()
{
	head = new(nothrow) LNode<ElemType>;
	if (head == NULL)
		exit(TJOVERFLOW);

	head->next = NULL;
}
template<class ElemType>
LinkList<ElemType>::~LinkList() 
{
	LNode<ElemType> *cur = head;
	while (cur != NULL)
	{
		LNode<ElemType> *nxt = cur->next;
		delete cur;
		cur = nxt;
	}
	head = NULL;
}
template<class ElemType>
Status LinkList<ElemType>::ClearList()const
{
	LNode<ElemType> *cur = head->next;
	while (cur != NULL)
	{
		LNode<ElemType> *nxt = cur->next;
		delete cur;
		cur = nxt;
	}
	head->next = NULL;
	return OK;
}

template<class ElemType>
Status LinkList<ElemType>::ListEmpty()const
{
	return head->next == NULL ? TRUE : FALSE;
}
template<class ElemType>
Status LinkList<ElemType>::ListLength()const
{
	LNode<ElemType> *cur = head->next;
	int res = 0;
	while (cur != NULL)
		cur = cur->next, ++res;
	return res;
}

template<class ElemType>
Status LinkList<ElemType>::GetElem(const int i,ElemType &res)const
{
	LNode<ElemType> *cur = head->next;
	int pos = 1;
	while (cur != NULL && pos < i)
		cur = cur->next, ++pos;
	if (cur == NULL || pos > i)
		return ERROR;
	res = cur->data;
	return OK;
}

template<class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &rhs)const
{
	LNode<ElemType> *cur = head->next;
	int pos = 1;
	while (cur != NULL && cur->data != rhs)
		cur = cur->next, ++pos;
	return cur == NULL ? 0 : pos;
}
template<class ElemType>
Status LinkList<ElemType>::PriorElem(const ElemType &rhs, ElemType &res)const
{
	LNode<ElemType> *cur = head->next;
	if (cur == NULL)
		return ERROR;

	while (cur->next != NULL && cur->next->data != rhs)
		cur = cur->next;
	if (cur->next == NULL)
		return ERROR;
	res = cur->data;
	return OK;
}
template<class ElemType>
Status LinkList<ElemType>::NextElem(const ElemType &rhs, ElemType &res)const
{
	LNode<ElemType> *cur = head->next;
	if (cur == NULL)
		return ERROR;

	while (cur->next != NULL && cur->data != rhs)
		cur = cur->next;
	if (cur->next == NULL)
		return ERROR;
	res = cur->next->data;
	return OK;
}

template<class ElemType>
Status LinkList<ElemType>::ListInsert(const int i, const ElemType &rhs)const
{
	LNode<ElemType> *cur = head;
	int pos = 0;
	while (cur != NULL && pos + 1 < i)
		cur = cur->next, ++pos;
	if (cur == NULL || pos + 1 > i)
		return ERROR;

	LNode<ElemType> *New = new(nothrow) LNode<ElemType>;
	if (New == NULL)
		return TJOVERFLOW;
	New->data = rhs;
	New->next = cur->next;
	cur->next = New;
	return OK;
}
template<class ElemType>
Status LinkList<ElemType>::ListDelete(const int i, ElemType &res)const
{
	LNode<ElemType> *cur = head;
	int pos = 0;
	while (cur->next != NULL && pos + 1 < i)
		cur = cur->next, ++pos;
	if (cur->next == NULL || pos + 1 > i)
		return ERROR;

	LNode<ElemType> *Old = cur->next;
	cur->next = Old->next;
	res = Old->data;
	delete Old;
	return OK;
}

template<class ElemType>
Status LinkList<ElemType>::ListTraverse()const
{
	int line_count = 0;
	LNode<ElemType> *cur = head->next;
	while (cur != NULL)
	{
		cout << cur->data << "->";
		if ((++line_count) == 5)
			cout << endl;
		cur = cur->next;
	}
	cout << endl;
	return OK;
}

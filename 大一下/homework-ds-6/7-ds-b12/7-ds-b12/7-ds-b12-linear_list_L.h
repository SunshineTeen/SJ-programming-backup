//姓名：王哲源 班级：计算机1班 学号：1652228

#include"7-ds-b12-student.h"
#include"7-ds-b12-double1.h"

#define TRUE             1
#define FALSE            0
#define OK               1
#define ERROR            -1
#define INFEASIBLE       -2
#define TJOVERFLOW         -3

#define LIST_INIT_SIZE   100
#define LISTINCREMENT    10

typedef int Status;

template<class ElemType>
class LinkList;

template<class ElemType>
class LNode
{
public:
	friend class LinkList<ElemType>;
protected:
	ElemType data;
	LNode *next;
};
template<class ElemType>
class LinkList
{
public:
	LinkList();
	~LinkList();
	Status ClearList()const;

	Status ListEmpty()const;
	Status ListLength()const;

	Status GetElem(const int, ElemType &)const;

	int LocateElem(const ElemType &)const;
	Status PriorElem(const ElemType &, ElemType &)const;
	Status NextElem(const ElemType &, ElemType &)const;

	Status ListInsert(const int, const ElemType &)const;
	Status ListDelete(const int, ElemType &)const;

	Status ListTraverse()const;
protected:
	LNode<ElemType> *head;
};

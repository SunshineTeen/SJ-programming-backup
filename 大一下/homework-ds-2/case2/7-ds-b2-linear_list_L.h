//姓名：王哲源 班级：计算机1班 学号：1652228

//#define ELEMTYPE_IS_INT
//#define ELEMTYPE_IS_DOUBLE
//#define ELEMTYPE_IS_CHAR_ARRAY
//#define ELEMTYPE_IS_CHAR_P
//#define ELEMTYPE_IS_STRUCT_STUDENT
#define ELEMTYPE_IS_STRUCT_STUDENT_P

#ifdef ELEMTYPE_IS_DOUBLE
typedef double ElemType;
#elif defined (ELEMTYPE_IS_CHAR_ARRAY)
typedef char ElemType[10];
#elif defined (ELEMTYPE_IS_CHAR_P)
typedef char* ElemType;
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT)
typedef struct student {
	int num;
	char name[10];
	char sex;
	float score;
	char addr[30];
} ElemType;
#elif defined (ELEMTYPE_IS_STRUCT_STUDENT_P)
typedef struct student {
	int num;
	char name[10];
	char sex;
	float score;
	char addr[30];
} ET, *ElemType;
#else
typedef int ElemType;
#endif


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define TJOVERFLOW -2

typedef int Status;

typedef struct LNode 
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList *L); 
Status DestroyList(LinkList *L);  
Status ClearList(LinkList *L);
Status ListEmpty(LinkList L);  
int ListLength(LinkList L);  
Status GetElem(LinkList L, int i, ElemType *e);  
int LocateElem(LinkList L, ElemType e,  
	Status(*compare)(ElemType e1, ElemType e2)); 
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e,
	Status(*compare)(ElemType e1, ElemType e2));
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e,
	Status(*compare)(ElemType e1, ElemType e2));
Status ListInsert(LinkList *L, int i, ElemType e);  
Status ListDelete(LinkList *L, int i, ElemType *e); 
Status ListTraverse(LinkList L, Status(*visit)(ElemType e)); 

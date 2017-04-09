/*
	Author: Xefvan

	实现线性表(顺序存储)
	基本操作：
		InitList() 		: 初始化一个线性表
		DestroyList() 	: 删除一个线性表
		ClearList()	  	: 清空一个线性表
		ListEmpty()		: 判断新性表是否为空
		GetElem()		: 返回第i个元素
		LocateElem()	: 判断是否满足否中关系的元素存在
		PriorElem()		: 找到前驱元素
		NextElem()		: 找到后继元素
		ListInsert()	: 插入一个元素
		ListInsertInIndex : 在Index下标插入一个元素
		ListDelete()	: 删除一个元素
		ListDeleteInIndex : 在Index下标删除一个元素
		ListTraverse()	: 遍历线性表
*/

#include <stdio.h>
#include <stdlib.h>
#define Print_State(x) printf(x)
#define OVERFLOW 		0		// 分配内存失败
#define OUTOFINDEX 		0		// 下标越界
#define LIST_INIT_SIZE 	100		// 顺序存储的初始化大小为100
#define ElemType 		int
#define TRUE 			1
#define FALSE 			0

// 参数操作基本返回状态
typedef enum Status {
	ERROR,						// 错误
	OK,							// 正确
	INSERTERROR,				// 插入失败
	DELETEERROR					// 删除失败
} Status;

typedef struct
{
	ElemType* elem;				// 存储空间地址
	int length;					// 当前长度
	int listsize;				// 当前分配的存储容量
} SqList;

// 菜单栏
void main_memuBar();
void child_memuBar();

// 顺序表操作
Status InitList(SqList* list);				// 初始化线性表，如果成功返回OK
Status DestroyList(SqList* list); 			// 删除线性表，如果成功返回OK
Status ClearList(SqList* list);				// 清空一个线性表，如果成功返回OK
int ListEmpty(SqList* list);				// 判断线性表是否为空，为空返回TRUE，不为空返回FALSE
int ListLength(SqList* list);				// 返回线性表长度
Status GetElem(SqList* list, int index, ElemType* e);					// 根据下标返回元素
int LocateElem(SqList* list, ElemType e, int(*)(ElemType e1, ElemType e2));
Status PriorElem(SqList* list, ElemType cur_e, ElemType* pre_e);		// 返回cur_e的前驱pre_e
Status NextElem(SqList* list, ElemType cur_e, ElemType* next_e);		// 返回cur_e的后继next_e
Status ListInsert(SqList* list, ElemType e);							// 插入一个元素
Status ListInsertInIndex(SqList* list, ElemType e, int index);			// 在Index下下插入一个元素
Status ListDelete(SqList* list, ElemType* e);							// 删除末尾元素
Status ListDeleteInIndex(SqList* list, ElemType* e, int index);			// 删除Index下标的元素
void ListTraverse(SqList* list);										// 遍历一个顺序表
Status Transpose(SqList* list);											// 顺序表转置

// 辅助函数，用于比较两个元素是否相等
int compare(ElemType e1, ElemType e2)
{
	if (e1 == e2) {
		return TRUE;
	}
	return FALSE;
}

// 主函数
int main(int argc, char const *argv[])
{
	main_memuBar();
	return 0;
}

// 菜单栏
void main_memuBar()
{
	// 初始化
	SqList list;

	// 子菜单
	child_memuBar();
	int selectNum;
	printf("You Select : ");
	while (scanf("%d", &selectNum)) {
		switch (selectNum) {
		case 1: {
			InitList(&list);
		}
		break;
		case 2: {
			DestroyList(&list);
		}
		break;

		case 3: {
			ClearList(&list);
			printf("Clear !\n");
		}
		break;

		case 4: {
			if (ListEmpty(&list)) {
				printf("The sequential list is empty!\n");
			}
			else {
				printf("The sequential list is not empty!\n");
			}
		}
		break;

		case 5: {
			printf("The sequential list's length is : %d", ListLength(&list));
		}
		break;

		case 6: {
			ElemType e;
			printf("Please enter a subscript for the element you want to return: ");
			int index;
			if (scanf("%d", &index) == 1) {
				if (GetElem(&list, index, &e)) {
					printf("The element = %d\n", e);
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 7: {
			ElemType e;
			printf("Please enter the number which you want to compare: ");
			if (scanf("%d", &e) == 1) {
				if (LocateElem(&list, e, compare)) {
					printf("Yes!The element which you enter is equal in the list!\n");

				}
				else {
					printf("Sorry!Can't find a element equal!\n");
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 8: {
			ElemType e, pre_e;
			printf("Please enter the number which you want to find the Prior Elememt: ");
			if (scanf("%d", &e) == 1) {

				if (PriorElem(&list, e, &pre_e)) {
					printf("The prior element is : %d\n", pre_e);
				}
				else {
					printf("Can't find a prior element!\n");
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 9: {
			ElemType e, next_e;
			printf("Please enter the number which you want to find the Next Elememt: ");
			if (scanf("%d", &e) == 1) {

				if (NextElem(&list, e, &next_e)) {
					printf("The next element is : %d\n", next_e);
				}
				else {
					printf("Can't find a next element!\n");
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 10: {
			int times;
			printf("Please enter the number which the times you want to insert: ");
			if (scanf("%d ", &times) == 1) {
				while (times--) {
					ElemType e;
					printf("Please enter the number which you want to insert: ");
					if (scanf("%d", &e) == 1) {
						if (ListInsert(&list, e)) {
							printf("Insert Ok!\n");
						}
					}
					else {
						printf("Please enter again!\n");
						times++;
					}
					fflush(stdin);
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 11: {
			int times;
			printf("Please enter the number which the times you want to insert: ");
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					printf("Please enter the number which you want to insert: ");
					if (scanf("%d", &e) == 1) {
						int index;
						printf("Please enter the index where you want to insert: ");
						if (scanf("%d", &index) == 1) {
							if (ListInsertInIndex(&list, e, index)) {
								printf("Insert Ok!\n");
							}
						}
						else {
							printf("Your input is wrong!\n");
							times++;
						}
						fflush(stdin);
					}
					else {
						printf("Your input is wrong!\n");
						times++;
					}
					fflush(stdin);
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 12: {
			int times;
			printf("Please enter the number which the times you want to delete: ");
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					if (ListDelete(&list, &e)) {
						printf("The delete element is : %d\n", e);
					}
					else {
						printf("Delete Wrong!\n");
					}
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 13: {
			int times;
			printf("Please enter the number which the times you want to insert: ");
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					int index;
					printf("Please enter the index where you want to delete: ");
					if (scanf("%d", &index) == 1) {
						if (ListDeleteInIndex(&list, &e, index)) {
							printf("The delete element is : %d\n", e);
						}
						else {
							printf("Delete Wrong!\n");
						}
					}
					else {
						printf("Your input is wrong!\n");
						times++;
					}
					fflush(stdin);
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 14: {
			if (ListLength(&list) != 0) {
				printf("The sequential list: \n");
				ListTraverse(&list);
			}
			else {
				printf("The sequential list is empty!\n");
			}
		}
		break;

		case 15: {
			if (Transpose(&list)) {
				printf("After chain transpose: ");
				ListTraverse(&list);
			}
		}
		break;

		default:
			printf("Please Enter Again!\n");
			break;
		}

		printf("\n\n");
		child_memuBar();
		printf("You Select : ");
		fflush(stdin);
	}
}

// 子菜单
void child_memuBar()
{
	printf("==========================================================\n");
	printf("    	    This is a sequential list.\n  Please select the number before the required operation \n");
	printf("==========================================================\n");
	printf("	1) Init			2) Delete\n");
	printf("	3) Clear		4) Empty\n");
	printf("	5) Length		6) GetElem\n");
	printf("	7) LocateElem		8) PriorElem\n");
	printf("	9) NextElem		10) ListInsert\n");
	printf("	11) ListInsertInIndex	12) ListDelete\n");
	printf("	13) ListDeleteInIndex	14) ListTraverse\n");
	printf("	15) Transpose\n");
	printf("	q) Quit(q to quit)\n");
	printf("==========================================================\n");
}


// 初始化线性表，如果成功返回OK
Status InitList(SqList* list)
{
	list->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (NULL == list->elem) {
		Print_State("The allocation of memory failed");
		exit(OVERFLOW);
	}
	list->length = 0;
	list->listsize = LIST_INIT_SIZE;
	return OK;
}

// 删除线性表，如果成功返回OK
Status DestroyList(SqList* list)
{
	if (list->elem != NULL) {
		free(list->elem);
	}
	list->length = 0;
	list->listsize = 0;
	return OK;
}

// 清空一个线性表
Status ClearList(SqList* list)
{
	list->length = 0;
	return OK;
}

// 判断线性表是否为空，为空返回TRUE，不为空返回FALSE
int ListEmpty(SqList* list)
{
	if (list->length == 0) {
		return TRUE;
	}
	return FALSE;
}

// 返回线性表长度
int ListLength(SqList* list)
{
	return list->length;
}

// 根据下标返回元素
Status GetElem(SqList* list, int index, ElemType* e)
{
	if (index < 0 || index >= ListLength(list)) {
		Print_State("Out of index");
		// exit(OUTOFINDEX);
		return ERROR;
	}
	// e =  &(list->elem[index]);
	*e = list->elem[index];
	return OK;
}

// 判断是否满足否中关系的元素存在
int LocateElem(SqList* list, ElemType e, int(*compare)(ElemType e1, ElemType e2))
{
	int i;
	for (i = 0; i < list->length; ++i) {
		if (compare(e, list->elem[i])) {
			return TRUE;
		}
	}
	return FALSE;
}

// 返回cur_e的前驱pre_e
Status PriorElem(SqList* list, ElemType cur_e, ElemType* pre_e)
{
	if (ListEmpty(list)) {
		printf("The list is empty!\n");
		return ERROR;
	}
	if (cur_e == list->elem[0]) {
		printf("The current element is in first!\n");
		return ERROR;
	}
	ElemType tmp = list->elem[0];
	int i;
	for (i = 1; i < list->length; ++i) {
		if (list->elem[i] != cur_e) {
			tmp = list->elem[i];
		}
		else {
			*pre_e = tmp;
			break;
		}

		if (i == list->length - 1) {
			return ERROR;
		}
	}
	return OK;
}

// 返回cur_e的后继next_e
Status NextElem(SqList* list, ElemType cur_e, ElemType* next_e)
{
	if (ListEmpty(list)) {
		printf("The list is empty!\n");
		return ERROR;
	}
	if (cur_e == list->elem[list->length - 1]) {
		printf("The current element is in end!\n");
		return ERROR;
	}
	int i;
	for (i = 0; i < list->length - 1; ++i) {
		if (list->elem[i] == cur_e) {
			*next_e = list->elem[i + 1];
			return OK;
		}
	}
	return ERROR;
}

// 插入一个元素
Status ListInsert(SqList* list, ElemType e)
{
	if (list->length >= list->listsize)	{
		return INSERTERROR;
	}
	list->elem[list->length++] = e;
	return OK;
}

// 在任意位置插入一个元素
Status ListInsertInIndex(SqList* list, ElemType e, int index)
{
	if (index < 0 || index > list->length) {
		return INSERTERROR;
	}
	int i;
	for (i = list->length; i > index; --i) {
		list->elem[i] = list->elem[i - 1];
	}
	list->elem[index] = e;
	list->length++;
	return OK;
}

// 删除末尾元素
Status ListDelete(SqList* list, ElemType* e)
{
	if (!ListEmpty(list)) {
		*e = list->elem[--list->length];
		return OK;
	}
	return DELETEERROR;
}

// 删除Index下标的元素
Status ListDeleteInIndex(SqList* list, ElemType* e, int index)
{
	if (ListEmpty(list)) {
		return DELETEERROR;
	}

	if (index < 0 || index > list->length) {
		return DELETEERROR;
	}

	*e = list->elem[index - 1];
	int i;
	for (i = index; i < list->length; ++i) {
		list->elem[i - 1] = list->elem[i];
	}
	--list->length;
	return OK;
}

// 遍历一个顺序表
void ListTraverse(SqList* list)
{
	int i;
	for (i = 0; i < list->length; ++i) {
		printf("%d ", list->elem[i]);
	}
	printf("\n");
}

// 顺序表转置
Status Transpose(SqList* list)
{
	if(ListEmpty(list))	{
		return OK;
	}
	int length = ListLength(list);
	int i;
	for(i = 0; i < length / 2; ++i) {
		ElemType temp = list->elem[i];
		list->elem[i] = list->elem[length - i - 1];
		list->elem[length - i - 1] = temp;
	}
	return OK;
}
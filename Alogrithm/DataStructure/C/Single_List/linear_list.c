/*
	Author: Xefvan

	实现线性表（链式存储）
	基本操作：
		Status MakeNode()			: 分配由p指向的值为e的节点，成功返回OK
		void FreeNode()				: 释放p所指节点
		Status InitList()			: 构造一个空的线性链式表L
		Status DestroyList()		: 摧毁线性链表L，L不在存在
		Status ClearList()			: 将线性链表清空
		Status InsFirst()			: 插入到第一个节点之前
		Status DelFirst()			: 删除第一个节点
		Status Append()				: 在尾部添加节点
		Status Remove()				: 删除尾节点
		Status InsBefore()			: 在某个节点之前添加节点
		Status InsAfter()			: 在某个节点之后添加节点
		Status SetCurElem()			: 改变当前节点元素的值
		Status ListEmpty()			: 判断线性链表是否为空
		int ListLength()			: 返回线性链表的长度
		void ListTraverse()			: 遍历线性链表
		Status Transpose()			: 链表转置
*/
#include <stdio.h>
#include <stdlib.h>
#define IS_EMPTY(ptr) (!(ptr))		// 定义链表是否为空
#define IS_NOT_NULL(ptr) ((ptr))	// 定义当前节点不为空
#define IS_NULL(ptr) (!(ptr))		// 定义节点为空
#define Print_State(x) printf(x)
#define OVERFLOW 		0			// 分配内存失败
#define OUTOFINDEX 		0			// 下标越界
#define LIST_INIT_SIZE 	100			// 顺序存储的初始化大小为100
#define ElemType 		int
#define TRUE 			1
#define FALSE 			0

// 参数操作基本返回状态
typedef enum Status {
	ERROR,	// 错误
	OK,		// 正确
	INSERTERROR,	// 插入失败
	DELETEERROR		// 删除失败
} Status;

// 定义节点结构
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
} LNode, *Link, *LinkList;

// 菜单栏
void main_memuBar();
void child_memuBar();

// 链表操作
Status MakeNode(Link* pLink, ElemType e);					// 分配有p指向的值为e的节点，并返回OK
void FreeNode(Link* pLink);									// 删除分配的节点
Status InitList(LinkList* list);							// 构造一个空的线性链表
Status DestroyList(LinkList* list);							// 删除线性链表
Status ClearList(LinkList* list);							// 清空一个线性表
Status InsFirst(LinkList* list, ElemType e);				// 插入到第一个节点之前
Status DelFirst(LinkList* list, ElemType* e);				// 删除第一个节点
Status Append(LinkList* list, ElemType e);					// 在尾部添加节点
Status Remove(LinkList* list, ElemType* e);					// 在尾部删除节点
Status InsBefore(LinkList* list, LNode* pLink, ElemType e);	// 在某个节点之前添加元素
Status InsAfter(LinkList* list, LNode* pLink, ElemType e);	// 在某个节点之后添加元素
Status SetCurElem(LinkList* list, LNode* pLink, ElemType e);// 改变当前元素的值
int ListEmpty(LinkList list);								// 判断链表是否为空
int ListLength(LinkList list);								// 返回一个链表的长度
void ListTraverse(LinkList list);							// 遍历线性链表
Status Transpose(LinkList* list);							// 链表转置

int main(int argc, char const *argv[])
{
	main_memuBar();
	return 0;
}

void main_memuBar()
{
	// 初始化
	LinkList list;

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
			int times;
			printf("Please enter the number which the times you want to insert: ");
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					printf("Please enter the number which you want to insert: ");
					if (scanf("%d", &e) == 1) {
						if (InsFirst(&list, e)) {
							printf("Insert Ok!\n");
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

		case 5: {
			int times;
			printf("Please enter the number which the times you want to insert: ");
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					if (DelFirst(&list, &e)) {
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

		case 6: {
			int times;
			printf("Please enter the number which the times you want to insert: ");
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					printf("Please enter the number which you want to insert: ");
					if (scanf("%d", &e) == 1) {
						if (Append(&list, e)) {
							printf("Insert Ok!\n");
						}
					}
					else {
						printf("Your input is wrong\n");
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

		case 7: {
			int times;
			printf("Please enter the number which the times you want to insert: ");
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					if (Remove(&list, &e)) {
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

		case 8: {
			int times;
			printf("Please enter the number which the times you want to insert: ");
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					printf("Please enter the number which you want to insert: ");
					if (scanf("%d", &e) == 1) {
						LNode* p = (LNode*)malloc(sizeof(LNode));
						p->next = NULL;
						printf("Please enter the Node where you want to insert: ");
						if (scanf("%d", &p->data) == 1) {
							if (InsBefore(&list, p, e)) {
								printf("Insert Ok!\n");
							}
						}
						else {
							printf("Your input is wrong!\n");
							times++;
						}
						free(p);
						fflush(stdin);
					}
					else {
						printf("Your input is wrong!\n");
						times++;
					}
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 9: {
			int times;
			printf("Please enter the number which the times you want to insert: ");
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					printf("Please enter the number which you want to insert: ");
					if (scanf("%d", &e) == 1) {
						LNode* p = (LNode*)malloc(sizeof(LNode));
						p->next = NULL;
						printf("Please enter the Node where you want to insert: ");
						if (scanf("%d", &p->data) == 1) {
							if (InsAfter(&list, p, e)) {
								printf("Insert Ok!\n");
							}
						}
						else {
							printf("Your input is wrong!\n");
							times++;
						}
						free(p);
						fflush(stdin);
					}
					else {
						printf("Your input is wrong!\n");
						times++;
					}
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
			if (scanf("%d", &times) == 1) {
				while (times--) {
					ElemType e;
					printf("Please enter the number which you want to modify: ");
					if (scanf("%d", &e) == 1) {
						LNode* p = (LNode*)malloc(sizeof(LNode));
						p->next = NULL;
						printf("Please enter the Node where you want to insert: ");
						if (scanf("%d", &p->data) == 1) {
							if (SetCurElem(&list, p, e)) {
								printf("Modify Ok!\n");
							}
						}
						else {
							printf("Your input is wrong!\n");
							times++;
						}
						free(p);
						fflush(stdin);
					}
					else {
						printf("Your input is wrong!\n");
						times++;
					}
				}
			}
			else {
				printf("Your input is wrong!\n");
			}
		}
		break;

		case 11: {
			if (ListEmpty(list)) {
				printf("The Single list is empty!\n");
			}
			else {
				printf("The Single list is not empty!\n");
			}
		}
		break;

		case 12: {
			printf("The Single list's length is : %d", ListLength(list));
		}
		break;

		case 13: {
			ListTraverse(list);
		}
		break;

		case 14: {
			if (Transpose(&list)) {
				printf("After chain transpose: ");
				ListTraverse(list);
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
	printf("    	   	This is a Single list.\nPlease select the number before the required operation \n");
	printf("==========================================================\n");
	printf("	1) Init			2) Delete\n");
	printf("	3) Clear		4) InsFirst\n");
	printf("	5) DelFirst		6) Append\n");
	printf("	7) Remove		8) InsBefore\n");
	printf("	9) InsAfter		10) SetCurElem\n");
	printf("	11) ListEmpty		12) ListLength\n");
	printf("	13) ListTraverse    	14) Transpose\n");
	printf("	q) Quit(q to quit)\n");
	printf("==========================================================\n");
}

// 分配有p指向的值为e的节点，并返回OK
Status MakeNode(Link* pLink, ElemType e)
{
	(*pLink) = (LNode*)malloc(sizeof(LNode));
	if (!pLink) {
		Print_State("The allocation of memory failed");
		exit(OVERFLOW);
	}
	(*pLink)->data = e;
	(*pLink)->next = NULL;
	return OK;
}

// 删除分配的节点
void FreeNode(Link* pLink)
{
	if (IS_NOT_NULL(pLink)) {
		free(pLink);
		pLink = NULL;
	}
}

// 构造一个空的线性链式表L
Status InitList(LinkList* list)
{
	(*list) = (LinkList)malloc(sizeof(LNode));
	if (IS_NOT_NULL(list)) {
		(*list)->data = -1;
		(*list)->next = NULL;
		return OK;
	}
	return ERROR;
}

// 删除一个链表
Status DestroyList(LinkList* list)
{
	LinkList tmp = *list;
	while (IS_NOT_NULL(*list)) {
		(*list) = (*list)->next;
		free(tmp);
		tmp = *list;
	}
	*list = NULL;
	return OK;
}

// 清空一个链表
Status ClearList(LinkList* list)
{
	(*list)->next = NULL;
	return OK;
}

// 加入到第一个节点之前
Status InsFirst(LinkList* list, ElemType e)
{
	Link pLink;
	MakeNode(&pLink, e);
	if (IS_NOT_NULL(*list)) {
		LinkList* nex_list = (LinkList*)(*list)->next;
		(*list)->next = pLink;
		pLink->next = (Link)nex_list;
		return OK;
	}
	return INSERTERROR;
}

// 删除第一个节点
Status DelFirst(LinkList* list, ElemType* e)
{
	if (ListLength(*list) < 1) {
		return DELETEERROR;
	}
	*e = (*list)->next->data;
	LinkList first_node = (*list)->next;
	LinkList next_node = (*list)->next->next;
	(*list)->next = next_node;
	free(first_node);
	return OK;
}

// 在尾部添加节点
Status Append(LinkList* list, ElemType e)
{
	Link pLink;
	MakeNode(&pLink, e);
	if (IS_NOT_NULL(*list)) {
		if (ListLength(*list) == 0) {
			InsFirst(list, e);
		}
		else {
			LinkList head = (*list)->next;
			while (IS_NOT_NULL(head->next)) {
				head = head->next;
			}
			head->next = pLink;
			return OK;
		}
	}
	return INSERTERROR;
}

// 删除尾部节点
Status Remove(LinkList* list, ElemType* e)
{
	if (IS_NOT_NULL(*list) && ListLength(*list) >= 1) {
		LinkList tail = (*list)->next;
		LinkList tmp = *list;
		while (IS_NOT_NULL(tail->next)) {
			tail = tail->next;
			tmp = tmp->next;
		}
		*e = tail->data;
		tmp->next = NULL;
		free(tail);
		return OK;
	}
	return DELETEERROR;
}

// 在某个节点之前添加元素
Status InsBefore(LinkList* list, LNode* p, ElemType e)
{
	Link pLink;
	MakeNode(&pLink, e);
	if (IS_NOT_NULL(*list)) {
		LinkList tail = (*list)->next;
		LinkList tmp = *list;
		while (tail->data != p->data && tail->next != NULL) {
			tail = tail->next;
			tmp = tmp->next;
		}
		if (tail->data == p->data) {
			tmp->next = pLink;
			pLink->next = tail;
			return OK;
		}
	}
	return INSERTERROR;
}

// 在某个节点之后添加元素
Status InsAfter(LinkList* list, LNode* p, ElemType e)
{
	Link pLink;
	MakeNode(&pLink, e);
	if (IS_NOT_NULL(*list)) {
		LinkList tail = (*list)->next;
		while (tail->data != p->data && tail->next != NULL) {
			tail = tail->next;
		}
		if (tail->data == p->data) {
			pLink->next = tail->next;
			tail->next = pLink;
			return OK;
		}
	}
	return INSERTERROR;
}

// 改变当前元素的值
Status SetCurElem(LinkList* list, LNode* p, ElemType e)
{
	if (IS_NOT_NULL(*list)) {
		LinkList tail = (*list)->next;
		while (tail->data != p->data && tail->next != NULL) {
			tail = tail->next;
		}
		if (tail->data == p->data) {
			tail->data = e;
			return OK;
		}
	}
	return ERROR;
}

// 判断链表是否为空
int ListEmpty(LinkList list)
{
	if (ListLength(list) == 0) {
		return TRUE;
	}
	return FALSE;
}

// 返回链表长度
int ListLength(LinkList list)
{
	if (IS_NULL(list)) {
		printf("The List is not exist!\n");
		return -1;
	}
	int count = 0;
	LinkList tmp = list->next;
	while (IS_NOT_NULL(tmp)) {
		++count;
		tmp = tmp->next;
	}
	return count;
}

// 遍历链表
void ListTraverse(LinkList list)
{
	if (IS_NOT_NULL(list->next)) {
		LinkList tmp = list->next;
		while (IS_NOT_NULL(tmp->next)) {
			printf("%d->", tmp->data);
			tmp = tmp->next;
		}
		printf("%d\n", tmp->data);
	}
}

// 链表转置
Status Transpose(LinkList* list)
{
	if (ListEmpty(*list) || ListLength(*list) == 1) {
		return ERROR;
	}
	LinkList prev = NULL;
	LinkList nextNode = NULL;
	LinkList initList;
	InitList(&initList);
	(*list) = (*list)->next;
	while(*list) {
		nextNode = (*list)->next;
		(*list)->next = prev;
		prev = *list;
		*list = nextNode;
	}
	initList->next = prev;
	*list = initList;
	return OK;
}
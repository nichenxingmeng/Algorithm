#include<iostream>
using namespace std;

//判断单链表是否存在环
bool HasCircle(Node *head)
{
	if (head == NULL)
		return false;
	Node *slow = head, *fast = head;
	while (fast != NULL && fast -> next!=NULL)
	{
		slow = slow -> next;
		fast = fast -> next -> next;
		if (slow == fast)
			return true;
	}
	return false;
}

//在有序链表中寻找中位数
while (fast && slow)
{
	if (fast -> next == NULL)
		return slow -> data;
	else if (fast -> next != NULL && fast -> next ->next == NULL)
		return (slow -> data + slow -> next -> data) / 2;
	else
	{
		fast = fast -> next;
		fast = fast -> next;
		slow = slow -> next;
	}
}

//输出链表中的倒数第K个节点(即正数第K-1个节点)
ListNode * RGetKthNode(ListNode * pHead, unsigned int k)
{
	if (k == 0 || pHead = NULL)
		return NULL;

	ListNode * pAhead = pHead;
	ListNode * pBehind = pHead;
	for (int i = 0; i < k - 1; i++)
	{
		pAhead = pAhead -> next;
		if (pAhead == NULL)
			return NULL
	}
	while (pAhead -> next != NULL)
	{
		pBehind = pBehind -> next;
		pAhead = pAhead -> next;
	}
	return pBehind;
}

//判断链表是否存在环，如果存在，找到环入口
node* findLoopPort(node *head) {
	node *fast, *slow;
	fast = slow = head;
	while (fast && fast -> next) {
		slow = slow -> next;
		fast = fast -> next -> next;
		if (slow == fast) {
			break;
		}
	}
	if ((fast == NULL) || (fast -> next == NULL)) {
		return NULL;
	}
	slow = head;
	while (slow != fast) {
		slow = slow -> next;
		fast = fast -> next;
	}
	return slow;
}

//判断两个单链表是否相交，如果相交，找到他们的第一个公共节点
void Is_2List_Intersect(LinkList L1, LinkList L2) {
	if (L1 == NULL || L2 == NULL) {
		exit(ERROR);
	}
	LinkList p = L1;
	LinkList q = L2;
	int L1_length = 0;
	int L2_length = 0;
	int len = 0;

	while (p -> next) {
		L1_length ++;
		p = p -> next; 
	}
	while (q -> next) {
		L2_length ++;
		q = q -> next;
	}

	printf("p: = %d\n", p);
	printf("q: = %d\n", q);

	printf("L1_length: = %d\n", L1_length);
	printf("L2_length: = %d\n", L2_length);

	if (p == q) {
		printf("相交\n");

		if (L1_length > L2_length) {
			len = L1_length - L2_length;
			p = L2;
			q = L1;
		}
		else {
			len = L2_length - L1_length;
			p = L1;
			q = L2;
		}

		while (len) {
			q = q -> next;
			len--;
		}
		while (p != q) {
			p = p -> next;
			q = q -> next;
		}
		printf("相交的第一个结点是: %d\n", p -> data);
	}
	else {
		print("不相交 \n");
	}
}

//
int Is_ListLoop(LinkList L) {
	LinkList fast, slow;
	if (L == NULL || L -> next == NULL) {
		exit(ERROR);
	}

	fast = slow = L;

	while (fast -> next != NULL && fast -> next -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
		if (fast == slow) {
			return True;
		}
	}
	return False;
}

int Find_Loop(LinkList L) {
	LinkList fast, slow;

	if (L == NULL || L -> next == NULL) {
		exit(ERROR);
	}

	fast = slow = L;

	while (fast -> next != NULL && fast -> next -> next != NULL) {
		slow = slow -> next;
		fast = fast -> next -> next;
		if (fast == slow) {
			break;
		}
	}

	slow = L;
	while (fast != slow) {
		slow = slow -> next;
		fast = fast -> next;
	}
	printf("%d\n", slow -> data);

	return TRUE;
}

void Is_2List_Intersect2(LinkList L1, LinkList L2) {
	if (L1 == NULL || L2 == NULL) {
		exit(ERROR);
	}
	LinkList p = L1;
	LinkList q = L2;

	while (p -> next) {
		p = p -> next;
	}

	p -> next = L1 -> next;

	if (Is_ListLoop(L2)) {
		printf("相交\n");
        printf("相交的第一个结点是：");
        Find_Loop(L2);
	}
	else {
		printf("不相交\n");
	}
}
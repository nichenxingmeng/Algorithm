#include<iostream>
using namespace std;

//�жϵ������Ƿ���ڻ�
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

//������������Ѱ����λ��
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

//��������еĵ�����K���ڵ�(��������K-1���ڵ�)
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

//�ж������Ƿ���ڻ���������ڣ��ҵ������
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

//�ж������������Ƿ��ཻ������ཻ���ҵ����ǵĵ�һ�������ڵ�
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
		printf("�ཻ\n");

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
		printf("�ཻ�ĵ�һ�������: %d\n", p -> data);
	}
	else {
		print("���ཻ \n");
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
		printf("�ཻ\n");
        printf("�ཻ�ĵ�һ������ǣ�");
        Find_Loop(L2);
	}
	else {
		printf("���ཻ\n");
	}
}
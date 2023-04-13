//双向链表的基本实现
#include <iostream>

typedef struct node{
	int value;
	node* next;
	node* prev;
}node;
typedef node* List;
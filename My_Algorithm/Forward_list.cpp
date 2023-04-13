//单向链表的基本实现
#include <iostream>

typedef struct node {
	int value;
	node* next;
}node;
typedef node* Forward_list;
typedef node* pos;

void Insert(Forward_list L, pos p, int v)
{
	node* t = new node;
	t->value = v;
	t->next = p->next;
	p->next = t;
};



int main(void)
{

}
//AC�Զ���
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#define ALPHABET (26)

using namespace std;

typedef struct AC_Node
{
	AC_Node* child[ALPHABET];
	AC_Node* fail;//������ܾ���ͺ�KMP��next������
	vector<int> exist;
	AC_Node()
	{
		fail = nullptr;
		memset(child, NULL, ALPHABET * sizeof(AC_Node*));
	}
}AC_Node;
typedef
void insert

int main(void)
{

}
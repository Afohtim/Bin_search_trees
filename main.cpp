#include "AVL_Tree.h"
#include "BS_Tree.h"

int main()
{
	AVL_Tree *tree = new AVL_Tree;
	tree->insert(5);
	tree->insert(4);
	tree->insert(7);
	tree->insert(3);
	tree->insert(15);
	tree->insert(13);
	tree->insert(1);
	tree->insert(37);
	tree->insert(9);
	tree->insert(11);
	//tree->erase(10);
	//tree->erase(7);
	tree->cout_hight();
	system("pause");
	return 0;
}
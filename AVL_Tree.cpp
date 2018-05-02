#include "AVL_Tree.h"


void check_hight(Node *node)
{
	int l_hight = node->left == nullptr ? 0 : node->left->hight;
	int r_hight = node->right == nullptr ? 0 : node->right->hight;
	node->hight = (l_hight > r_hight ? l_hight : r_hight) + 1;

}

void AVL_Tree::insert_balance(Node *node)
{
	if (node == root)
		return;

	Node *parent = node->par;
	int l_hight, r_hight;
	if (node == parent->left)
	{
		l_hight = node->hight;
		r_hight = parent->right == nullptr ? 0 : parent->right->hight;
		if (l_hight - r_hight == 2)
		{
			rotate_right(parent);
		}
	}
	else
	{
		r_hight = node->hight;
		l_hight = parent->left == nullptr ? 0 : parent->left->hight;
		if (r_hight - l_hight == 2)
		{
			rotate_left(parent);
		}
	}
	check_hight(parent);
	insert_balance(parent);
	
}

void AVL_Tree::delete_balance(Node *node)
{
	if (node == nullptr)
	{
		return;
	}
	int l_hight = node->left == nullptr ? 0 : node->left->hight;
	int r_hight = node->right == nullptr ? 0 : node->right->hight;
	if (r_hight - l_hight == 2)
	{
		rotate_left(node);
	}
	else if (l_hight - r_hight == 2)
	{
		rotate_right(node);
	}
	check_hight(node);
	delete_balance(node->par);
}

void AVL_Tree::rotate_left(Node *node)
{

	Node *pivot = node->right;
	int r_hight = node->left == nullptr ? 0 : node->left->hight;
	int l_hight = pivot->right == nullptr ? 0 : pivot->right->hight;
	int m_hight = pivot->left == nullptr ? 0 : pivot->left->hight;
	if (m_hight <= l_hight)
	{
		node->right = pivot->left;
		if (pivot->left != nullptr)
			pivot->left->par = node;
		pivot->left = node;
		pivot->par = node->par;
		node->par = pivot;

		check_hight(node);
		check_hight(pivot);
		if (pivot->par == nullptr)
			root = pivot;
	}
	else
	{
		node->right = pivot->left->left;
		if (pivot->left->left != nullptr)
			pivot->left->left->par = node;
		pivot->left->left = node;
		pivot->left->par = node->par;
		node->par = pivot->left;

		pivot->left = node->par->right;
		if (node->par->right != nullptr)
			node->par->right->par = pivot;
		node->par->left = pivot;
		pivot->par = node->par;

		check_hight(node);
		check_hight(pivot);
		check_hight(pivot->par);
		if (pivot->par->par == nullptr)
			root = pivot->par;

	}
}

void AVL_Tree::rotate_right(Node * node)
{

	Node *pivot = node->left;
	int r_hight = node->right == nullptr ? 0 : node->right->hight;
	int l_hight = pivot->left == nullptr ? 0 : pivot->left->hight;
	int m_hight = pivot->right == nullptr ? 0 : pivot->right->hight;
	if (m_hight <= l_hight)
	{
		node->left = pivot->right;
		if (pivot->right != nullptr)
			pivot->right->par = node;
		pivot->right = node;
		pivot->par = node->par;
		node->par = pivot;

		check_hight(node);
		check_hight(pivot);
		if (pivot->par == nullptr)
			root = pivot;
	}
	else
	{
		node->left = pivot->right->right;
		if (pivot->right->right != nullptr)
			pivot->right->right->par = node;
		pivot->right->right = node;
		pivot->right->par = node->par;
		node->par = pivot->right;

		pivot->right = node->par->left;
		if (node->par->left != nullptr)
			node->par->left->par = pivot;
		node->par->right = pivot;
		pivot->par = node->par;

		check_hight(node);
		check_hight(pivot);
		check_hight(pivot->par);
		if (pivot->par->par == nullptr)
			root = pivot->par;

	}
}

AVL_Tree::AVL_Tree()
{
	root = nullptr;
}


AVL_Tree::~AVL_Tree()
{
	del_subtree(root);
}

void AVL_Tree::insert(int key)
{
	Node *node = push_node(key);
	insert_balance(node);
}

void AVL_Tree::erase(int key)
{
	Node *node = del_node(key);
	if (node == nullptr)
		return;
	if (node == root)
	{
		delete root;
		root = nullptr;
		return;
	}
	Node *parent = node->par;
	if (node == parent->left)
	{
		parent->left = nullptr;
	}
	else
	{
		parent->right = nullptr;
	}
	delete node;
	check_hight(parent);
	delete_balance(parent);
}

void AVL_Tree::cout_hight()
{
	Node *node = root;
	while (node != nullptr)
	{
		if (node->left != nullptr && !node->left->used)
		{
			node = node->left;
			continue;
		}
		if (node->right != nullptr && !node->right->used)
		{
			node = node->right;
			continue;
		}
		std::cout << node->val << ' ' << node->hight << '\n';
		node->used = true;
		node = node->par;
	}
}



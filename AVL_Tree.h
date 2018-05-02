#pragma once
#include "BS_Tree.h"
#include <cmath>
#include <iostream>

class AVL_Tree : public BS_Tree
{
private:
	void insert_balance(Node *node);
	void delete_balance(Node *node);
	void rotate_left(Node *node);
	void rotate_right(Node *node);
public:
	AVL_Tree();
	~AVL_Tree();

	void insert(int key) override;
	void erase(int key) override;
	void cout_hight();
};


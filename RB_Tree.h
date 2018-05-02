#pragma once
#include "BS_Tree.h"
class RB_Tree : public BS_Tree
{
private:
	void insert_balance(Node *node);
	void delete_balance(Node *node);
	void rotate_left(Node *node);
	void rotate_right(Node *node);
public:
	RB_Tree();
	~RB_Tree();
	/*void insert(int key) override;
	void erase(int key) override;*/
};


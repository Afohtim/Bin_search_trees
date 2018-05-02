#pragma once

enum color {Black, Red};

struct Node
{
	Node(int key, Node *parent = nullptr);
	int val;
	Node *par;
	Node *left, *right;
	unsigned hight = 1;
	color col;
	bool used;
};


class BS_Tree
{
protected:
	void del_subtree(Node *node);
	Node* root;
	Node* push_node(int key);
	Node* del_node(int key);
public:
	BS_Tree();
	~BS_Tree();

	virtual void insert(int key);
	virtual void erase(int key);
};


#include<string>
#include<vector>
#include<iostream>


//   A
//  / \
//  B C

template<typename T> struct BinaryTree;

template<typename T> struct Node
{
	T value= T();
	Node<T> *left{nullptr}, *right{nullptr}, * parent {nullptr};
	BinaryTree<T> *tree{nullptr};
	Node( T value) :value (value){}
	Node( T value, Node<T> *left, Node<T> *right) :value(value),left(left),right(right)
	{
		this->left->tree= this->right->tree=tree;
		this->left->parent= this->right->parent= this;
	}

	void set_tree(BinaryTree<T> *t)
	{
		tree=t;
		if(left) left->set_tree(t);
		if(right) right->set_tree(t);
	}

	~Node()
	{
		if(left) delete left;
		if(right) delete right;
	}

};


template<typename T> struct BinaryTree
{
	Node<T> *root{nullptr};
	BinaryTree(Node<T> *root) :root(root)
	{
		root->set_tree(this);
	}


	~BinaryTree() {if(root) delete root;}

	template<typename U> struct PreOrderIterator
	{
		Node<U> *current;
		PreOrderIterator(Node<U> *current) :current(current){}
		bool operator != (const PreOrderIterator<U> & other)
		{
};




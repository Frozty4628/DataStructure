#pragma once
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Lists;

class Node {
public:
	friend Lists;
	Node(Node * p);
	Node(const int datain, Node * p);
	friend void Intersection(Lists & a, Lists & b, Lists & answer);
	friend void UnionSet(Lists & a, Lists & b, Lists & answer);
	friend void swap_node(Node * a, Node * b);
	friend void sort(Lists & list);
	~Node();

private:
	int data;
	Node * next;

};

class Lists {
public:
	Lists();
	~Lists();
	void Input_WithEndtag(int endtag = 0);
	void Insert(int position, int datain);
	void RemoveNode_ValueMatched(int dataremove);
	int FindNodePosition_ValueMatched(int datafind);
	void OutputList();
	friend void Intersection(Lists & a, Lists & b, Lists & answer);
	friend void UnionSet(Lists & a, Lists & b, Lists & answer);
	friend void swap_node(Node * a, Node * b);
	friend void sort(Lists & list);

private:
	Node * first;
	Node *current;
	int length;
};

void Intersection(Lists & a, Lists & b, Lists & answer);
void UnionSet(Lists & a, Lists & b, Lists & answer);
void swap_node(Node * a, Node * b);
void sort(Lists & list);

#pragma once
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class List;

class Node {
public:
	friend List;
	Node(Node * p = nullptr);
	Node(const int datain, Node * p = nullptr);
	friend void Intersection(List & a, List & b, List & answer);
	friend void UnionSet(List & a, List & b, List & answer);
	~Node();

private:
	int data;
	Node * next;

};

class List {
public:
	List();
	~List();
	void Input_WithEndtag(int endtag = 0);
	void Insert(int position, int datain);
	void RemoveNode_ValueMatched(int dataremove);
	int FindNodePosition_ValueMatched(int datafind);
	void OutputList();
	friend void Intersection(List & a, List & b, List & answer);
	friend void UnionSet(List & a, List & b, List & answer);

private:
	Node * first;
	Node *current;
	int length;
};

void Intersection(List & a, List & b, List & answer);
void UnionSet(List & a, List & b, List & answer);
#pragma once
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Expression_Queue;

class Node {
	friend Expression_Queue;
public:
	Node(int exp_in = 0, int coef_in = 0, Node * p = nullptr);
private:
	int exp;
	int coef;
	Node * next;
};

class Expression_Queue {
public:
	Expression_Queue(Node * head = nullptr, Node * tail = nullptr); //done
	void make_empty(); //done
	int get_length(); //done
	void append_node(int exp_in, int coef_in); //done
	void retrieve(int & exp_out, int & coef_out); //done
	void delete_head(); //done
	int is_empty(); //done
	void output(); //done
private:
	Node * head;
	Node * tail;
	int length;
};
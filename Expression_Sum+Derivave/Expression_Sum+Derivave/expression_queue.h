#pragma once
#include <iostream>
#include <stdlib.h>
#include <math.h>
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
	void input();
	void append_node(int exp_in, int coef_in); //done
	void retrieve(int & exp_out, int & coef_out); //done
	void delete_head(); //done
	int is_empty(); //done
	void output(); //done
	//求多项式和函数
	void sum_expression(Expression_Queue b, Expression_Queue & answer);
	//求多项式导数函数
	void derivative_expression(Expression_Queue & answer);
	//求多项式值函数
	int evaluate_expression(int x_in);
	int power(int bottom, int exp);
private:
	Node * head;
	Node * tail;
	int length;
};
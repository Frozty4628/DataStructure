#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
const int maxn = 256;
const char parentheses[8] = { '{', '[', '(', '<', '}', ']', ')', '>' };

class Stack;
class Pairing;
class Node {
	friend Stack;
	friend Pairing;
public:
	Node(char ch, Node * p);
private:
	char symbol;
	Node * next;
};

class Stack {
	friend Pairing;
public:
	Stack(Node * p);
	void pushin(char chin);
	char popout();
	char taketop();
private:
	Node * top;
	int length;
};

class Pairing {
public:
	Pairing();
	void input();
	void pairing();
	inline int isparenthese(char chin);
	char anotherpair(char chin);
	void setempty();
private:
	char symbolstring[maxn];
	Stack symbolstack;
};
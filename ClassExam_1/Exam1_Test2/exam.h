#pragma once
#include <assert.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct StackNode {
public:
	char  data;
	StackNode *link;
	StackNode(char d = 0, StackNode *next = NULL) : data(d), link(next) {}
	~StackNode() {};
};

class LinkedStack {
private:
	StackNode * top;
public:
	LinkedStack() : top(NULL) {}
	void Push(char &x);
	int  Pop(char & x);
	friend int huiwen(char s[]);
	friend ostream & operator << (ostream& os, LinkedStack& s);
};
ostream& operator << (ostream& os, LinkedStack& S) {
	// //���ջԪ�ص����ز��� <<

	StackNode *p = S.top; int i = 0;
	while (p != NULL) {
		os << ++i << ":" << p->data << endl; p = p->link;
	}
	return os;
};

void LinkedStack::Push(char &x) {
	//��Ԫ��ֵx���뵽��ʽջ��ջ��,����ͷ��
	top = new StackNode(x, top);	//�����½��
	assert(top != NULL);		//����ʧ���˳�
};

int LinkedStack::Pop(char & x) {
	//ɾ��ջ�����, ���ر�ɾջ��Ԫ�ص�ֵ��
	if (top == NULL) return 0;         //ջ�շ���
	StackNode *p = top;		            //�ݴ�ջ��Ԫ��
	top = top->link;			      //��ջ��ָ��
	x = p->data;
	delete p;		          //�ͷŽ��
	return 1;
};
int huiwen(char s[]) {
	LinkedStack stack;
	char chout;
	for (int i = 1; i <= strlen(s); i++) {
		if (i <= strlen(s) / 2) {
			stack.Push(s[i - 1]);
		} else {
			stack.Pop(chout);
			if (chout != s[i - 1]) {
				return 0;
			}
		}
	}
	return 1;
}

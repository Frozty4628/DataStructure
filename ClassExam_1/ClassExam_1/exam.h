#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class List; //前视定义,否则友元无法定义
class LinkNode {
	friend  class List; //链表结点类的定义
private:
	LinkNode * link;
	int data;
public:
	LinkNode(LinkNode *ptr = NULL) {
		link = ptr;
	}
	LinkNode(const int & item, LinkNode *ptr = NULL) {
		data = item; link = ptr;
	}
	~LinkNode() {
	};
};

class List {//单链表类的定义
private:
	LinkNode * first; //指向首结点的指针          
public:
	List(int x) {
		first = new LinkNode(x);
	}   // 带头结点
	~List() {
		MakeEmpty();
	}         //析构函数
	void MakeEmpty();      //链表置空    
	void input(int  endTag);
	void reverse();
	void output();
};
void List::MakeEmpty() {
	LinkNode *q;
	while (first->link != NULL) {
		q = first->link;
		first->link = q->link;//将表头结点后第一个结点从链中摘下
		delete q;        //释放它 
	}
}

void List::input(int endTag) {
	LinkNode  *newnode;
	int val;
	cin >> val;
	while (val != endTag) {
		newnode = new LinkNode(val);
		if (newnode == NULL) {
			cerr << "存储分配错误" << endl; exit(1);
		}
		newnode->link = first->link;
		first->link = newnode;
		cin >> val;
	}
}

void List::reverse() {
	LinkNode * p = first->link;
	LinkNode *q = p->link;
	while (q != nullptr) {
		p->link = q->link;
		q->link = first->link;
		first->link = q;
		q = p->link;
	}
}

void List::output() {//依次输出各结点的值
	LinkNode  *p = first->link;
	while (p != NULL) {
		cout << p->data << ' ';
		p = p->link;
	}
	cout << endl;
}

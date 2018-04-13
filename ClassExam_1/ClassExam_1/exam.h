#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class List; //ǰ�Ӷ���,������Ԫ�޷�����
class LinkNode {
	friend  class List; //��������Ķ���
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

class List {//��������Ķ���
private:
	LinkNode * first; //ָ���׽���ָ��          
public:
	List(int x) {
		first = new LinkNode(x);
	}   // ��ͷ���
	~List() {
		MakeEmpty();
	}         //��������
	void MakeEmpty();      //�����ÿ�    
	void input(int  endTag);
	void reverse();
	void output();
};
void List::MakeEmpty() {
	LinkNode *q;
	while (first->link != NULL) {
		q = first->link;
		first->link = q->link;//����ͷ�����һ����������ժ��
		delete q;        //�ͷ��� 
	}
}

void List::input(int endTag) {
	LinkNode  *newnode;
	int val;
	cin >> val;
	while (val != endTag) {
		newnode = new LinkNode(val);
		if (newnode == NULL) {
			cerr << "�洢�������" << endl; exit(1);
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

void List::output() {//�������������ֵ
	LinkNode  *p = first->link;
	while (p != NULL) {
		cout << p->data << ' ';
		p = p->link;
	}
	cout << endl;
}

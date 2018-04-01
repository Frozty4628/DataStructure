#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "linklist_test.h"
using namespace std;

int main() {


	system("pause");
	return 0;
}

//Node��ĺ���ʵ��
inline Node::Node(Node * p = nullptr) {
	next = p;
}

inline Node::Node(const int datain, Node * p) {
	data = datain;
	next = p;
}

inline Node::~Node() {
}

//List��ĺ���ʵ��
inline List::List() {
	first = new Node();
	current = first;
	length = 0;
}

inline List::~List() {
}

inline void List::Input_WithEndtag(int endtag) {
	//ʹ�ú�巨
	int datain;
	while (true) {
		cin >> datain;
		if (datain == endtag) {
			break;
		}
		Node * p = new Node(datain);
		current->next = p;
		current = current->next;
		length++;
	}
}

inline void List::Insert(int position, int datain) {
	Node * p = first->next;
	Node * newnode = new Node(datain);
	for (int i = 1; i <= position; i++) {
		p = p->next;
	}
	newnode->next = p->next;
	p->next = newnode;
	current = current->next;
	length++;
}

inline void List::RemoveNode_ValueMatched(int dataremove) {
	//������ַ
	Node * p = first;
	int i = 1;
	while (i <= length) {
		if (p->next->data == dataremove) {
			break;
		}
		p = p->next;
		i++;
	}
	if (i <= length) {
		Node * q = p->next;
		p->next = q->next;
		delete q;
		length--;
	}
}

inline int List::FindNodePosition_ValueMatched(int datafind) {
	int i = 1;
	Node * p = first->next;
	while (i <= length) {
		if (p->data == datafind) {
			break;
		}
		p = p->next;
		i++;
	}
	if (i > length) {
		return 0;
	} else {
		return i;
	}
}

void List::OutputList() {
	int i = 1;
	Node * p = first->next;
	while (i <= length) {
		cout << " " << p->data;
		i++;
	}
}

//������������ʵ��

inline void Intersection(List & a, List & b, List & answer) {
	/*
		//����a��answer����
		answer.length = a.length;
		int i = 1;
		Node * p = a.first->next;
		Node * q = answer.first->next;
		while (i <= answer.length) {
		q->data = p->data;
		i++;
		}

	*/
	//�󽻼�
	Node * p = a.first->next;
	Node * q = b.first->next;
	int i = 1;
	int j = 1;
	int position = 1;
	while (i <= a.length) {
		while (j <= b.length) {
			if (p->data == q->data) {
				answer.Insert(position, p->data);
				position++;
				j = 1;
				break;
			}
			j++;
			q = q->next;
		}
		i++;
		p = p->next;
	}
}

inline void UnionSet(List & a, List & b, List & answer) {
	//����a��answer����
	answer.length = a.length;
	int i = 1;
	Node * p = a.first->next;
	Node * q = answer.first->next;
	while (i <= answer.length) {
		q->data = p->data;
		i++;
	}
	//�󲢼�
	p = a.first->next;
	q = b.first->next;
	i = 1;
	int j = 1;
	int position = answer.length + 1;
	while (i <= a.length) {
		while (j <= b.length) {
			if (p->data != q->data) {
				answer.Insert(position, p->data);
				position++;
				j = 1;
				break;
			}
			j++;
			q = q->next;
		}
		i++;
		p = p->next;
	}
}

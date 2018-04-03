#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "linklist_test.h"
using namespace std;

int main() {
	Lists a;
	//����һ�����������־
	int end_tag;
	cin >> end_tag;
	//�������Ա�A
	a.Input_WithEndtag(end_tag);
	cout << "A is created as:";
	a.OutputList();
	cout << endl;
	//��2λ�ò���Ԫ��10
	int position, value;
	cin >> position >> value;
	a.Insert(position, value);
	cout << "After inserted A is";
	a.OutputList();
	cout << endl;
	//ɾ��ֵΪ10��Ԫ��
	cin >> value;
	a.RemoveNode_ValueMatched(value);
	cout << "After deleted A is";
	a.OutputList();
	cout << endl;
	//����Ԫ��9
	cin >> value;
	int find_result;
	find_result = a.FindNodePosition_ValueMatched(value);
	if (find_result) {
		cout << value << " is located at index of " << find_result << endl;
	} else {
		cout << value << " is not found" << endl;
	}
	//����Ԫ��22
	cin >> value;
	find_result = a.FindNodePosition_ValueMatched(value);
	if (find_result) {
		cout << value << " is located at index of " << find_result << endl;
	} else {
		cout << value << " is not found" << endl;
	}
	//����һ�����������־
	Lists b;
	cin >> end_tag;
	//�������Ա�B
	b.Input_WithEndtag(end_tag);
	cout << "B is created as:";
	b.OutputList();
	cout << endl;
	//�󽻼�
	Lists intersection_list;
	Intersection(a, b, intersection_list);
	cout << "A cross B is";
	intersection_list.OutputList();
	cout << endl;
	//�󲢼�
	Lists unionset_list;
	UnionSet(a, b, unionset_list);
	cout << "A union B is";
	unionset_list.OutputList();
	cout << endl;
	//�������Ĳ���
	sort(unionset_list);
	cout << "A union B in sequence is";
	unionset_list.OutputList();
	cout << endl;

	//system("pause");
	return 0;
}

//Node��ĺ���ʵ��
inline Node::Node(Node * p = nullptr) {
	next = p;
}

inline Node::Node(const int datain, Node * p = nullptr) {
	data = datain;
	next = p;
}

inline Node::~Node() {
}

//Lists��ĺ���ʵ��
inline Lists::Lists() {
	first = new Node();
	current = first;
	length = 0;
}

inline Lists::~Lists() {
}

inline void Lists::Input_WithEndtag(int endtag) {
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

inline void Lists::Insert(int position, int datain) {
	Node * p = first;
	Node * newnode = new Node(datain);
	for (int i = 1; i < position; i++) {
		p = p->next;
	}
	newnode->next = p->next;
	p->next = newnode;
	if (newnode->next == nullptr) {
		current = newnode;
	}
	length++;
}

inline void Lists::RemoveNode_ValueMatched(int dataremove) {
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

inline int Lists::FindNodePosition_ValueMatched(int datafind) {
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

void Lists::OutputList() {
	int i = 1;
	Node * p = first->next;
	while (i <= length) {
		cout << " " << p->data;
		p = p->next;
		i++;
	}
}

//������������ʵ��

inline void Intersection(Lists & a, Lists & b, Lists & answer) {
	//�󽻼�
	Node * p = a.first->next;
	Node * q = b.first->next;
	int i = 1;
	int j = 1;
	int position = 1;
	while (i <= a.length) {
		if (b.FindNodePosition_ValueMatched(p->data)) {
			answer.Insert(position, p->data);
			position++;
		}
		i++;
		p = p->next;
	}
}

inline void UnionSet(Lists & a, Lists & b, Lists & answer) {
	//����a��answer����
	int i = 1;
	Node * p = a.first;
	int position = 1;
	while (i <= a.length) {
		p = p->next;
		answer.Insert(position, p->data);
		position++;
		i++;
	}
	//debug
	//answer.OutputList();
	//�󲢼�
	p = b.first;
	i = 1;
	position = answer.length + 1;
	while (i <= b.length) {
		p = p->next;
		if (a.FindNodePosition_ValueMatched(p->data) == 0) {
			answer.Insert(position, p->data);
			position++;
		}
		i++;
	}
}

inline void swap_node(Node * a, Node * b) {
	//�����������
	int tmp;
	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

inline void sort(Lists & list) {
	//ʹ��ð������
	//�����жϽ������Ƿ�<=1
	if (list.length <= 1) {
		return;
	}
	//֮��ʼ����
	Node * p = list.first->next;
	for (int i = 1; i <= list.length; i++) {
		Node * q = p->next;
		for (int j = i + 1; j <= list.length; j++) {
			if (p->data > q->data) {
				swap_node(p, q);
			}
			q = q->next;
		}
		p = p->next;
	}
}

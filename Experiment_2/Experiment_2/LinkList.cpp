#include "LinkList.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void List::make_list_empty() {
	while (true) {
		LinkNode * p = first->link;
		if (p == current) {
			first = nullptr;
			current = first;
		}
		first->link = p->link;
		delete p;
	}
	length;
}

int List::get_length() {
	return length;
}

LinkNode * List::get_head_node() {
	return first;
}

LinkNode * List::find_node_match_value(int x) {
	if (is_empty_or_not()) {
		return nullptr;
	} else {
		LinkNode * p = first;
		int flag = 0;
		for (int i = 1; i <= length; i++) {
			p = p->link;
			if (p->data == x) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			return p;
		} else {
			return nullptr;
		}
	}
}

LinkNode * List::locate_address_of_node_i(int i) {
	if (is_empty_or_not()) {
		return nullptr;
	} else {
		LinkNode * p = first;
		for (int i = 1; i <= length; i++) {
			p = p->link;
		}
		return p;
	}
}

int List::get_data_of_node_i(int i) {
	if (is_empty_or_not()) {
		return -1;
	} else {
		LinkNode * p = first;
		for (int j = 1; j <= i; j++) {
			p = p->link;
		}
		return p->data;
	}
}

void List::set_data_of_node_i(int i, int x) {
}

bool List::insert_node_at_i(int i, int x) {
	LinkNode * p = first;
	LinkNode * in = new LinkNode(x);
	if (length == 0) {
		first->link = in;
		return true;
	} else if (i > length + 1) {
		return false;
	} else if (i == length + 1) {
		current->link = in;
		current = in;
		return true;
	} else {
		for (int j = 1; j <= i; j++) {
			p = p->link;
		}
		in->link = p->link;
		p->link = in;
		return true;
	}
}

int List::remove_node_at_i(int i, int & x) {
	if (is_empty_or_not()) {
		return -1; //返回值1代表因表空而移除失败
	} else {
		length--;
		return 0;
	}
}

bool List::is_empty_or_not() {
	return first->link == nullptr;
}

void List::input(int end_tag = -1) {
	//使用后插法
	int value;
	while (true) {
		cout << "Please enter the value of new node: " << endl;
		cin >> value;
		if (value = end_tag) {
			break;
		}
		LinkNode * p = new LinkNode(value);
		current->link = p;
		length++;
	}
}

void List::output() {
	if (is_empty_or_not()) {
		cout << "The current list is empty. " << endl;
	} else {
		LinkNode * p = first->link;
		cout << "The current length of list is " << length << endl;
		for (int i = 1; i <= length; i++) {
			cout << "No." << i << ": " << p->data << endl;
		}
	}
}



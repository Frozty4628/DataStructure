#include "expression_queue.h"

//Node类成员函数的实现
Node::Node(int exp_in, int coef_in, Node * p) {
	this->exp = exp_in;
	this->coef = coef_in;
	this->next = p;
}

//Expression_Queue类成员函数的实现

Expression_Queue::Expression_Queue(Node * head, Node * tail) {
	this->head = head;
	this->tail = tail;
	this->length = 0;
}

void Expression_Queue::make_empty() {
	int i = 1;
	while (i <= length) {
		delete_head();
		i++;
	}
	head = nullptr;
	tail = nullptr;
	length = 0;
}

int Expression_Queue::get_length() {
	return length;
}

void Expression_Queue::append_node(int exp_in, int coef_in) {
	Node * p = new Node(exp_in, coef_in);
	if (is_empty()) {
		head = tail = p;
	} else {
		tail->next = p;
		tail = p;
	}
	length++;
}

void Expression_Queue::retrieve(int & exp_out, int & coef_out) {
	exp_out = head->exp;
	coef_out = head->coef;
	delete_head();
}

void Expression_Queue::delete_head() {
	Node * p = head;
	head = head->next;
	delete p;
}

int Expression_Queue::is_empty() {
	if (head == tail && head == nullptr) {
		return 1;
	} else {
		return 0;
	}
}

void Expression_Queue::output() {
	int i = 1;
	Node * p = head;
	while (i <= length) {
		if (p->coef != 1) {
			cout << p->coef;
		}
		cout << "x";
		if (p->exp != 1) {
			cout << "^" << p->exp;
		}
		if (i != length) {
			cout << "+";
		}
		p = p->next;
		i++;
	}
	cout << endl;
}

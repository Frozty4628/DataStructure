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

void Expression_Queue::input() {
	int number, exp_in, coef_in;
	int i = 1;
	//cout << "num input here: ";
	cin >> number;
	while (i <= number) {
		//cout << "data input here: ";
		cin >> coef_in >> exp_in;
		append_node(exp_in, coef_in);
		i++;
	}
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
	if (head == nullptr) {
		return 1;
	} else {
		return 0;
	}
}

void Expression_Queue::output() {
	int i = 1;
	Node * p = head;
	while (i <= length) {
		if (p->exp == 0) {
			cout << p->coef;
		} else {
			if (p->coef > 0 && p != head) {
				cout << "+";
			}
			if (p->coef != 1) {
				cout << p->coef;
			}
			cout << "x";
			if (p->exp != 1) {
				cout << "^" << p->exp;
			}
		}
		/*if (i != length) {
			cout << "+";
		}*/
		p = p->next;
		i++;
	}
	cout << endl;
}

void Expression_Queue::sum_expression(Expression_Queue b, Expression_Queue & answer) {
	//先求和,然后判断,再插入. 判断插入的条件是系数是否为0
	int coef_sum;
	/*if (this->length <= b.length) {
		Node * p = this->head;
		Node * q = b.head;
	} else {
		Node * q = this->head;
		Node * q = b.head;
	}
	*/
	Node * p = this->head;
	Node * q = b.head;
	while (p != nullptr || q != nullptr) {
		if (q == nullptr) {
			//将a剩余的项依次插入到answer里
			while (p != nullptr) {
				answer.append_node(p->exp, p->coef);
				p = p->next;
			}
			break;
		}
		if (p == nullptr) {
			//将b剩余的项依次插入到answer里
			while (q != nullptr) {
				answer.append_node(q->exp, q->coef);
				q = q->next;
			}
			break;
		}
		if (p->exp == q->exp) {
			coef_sum = p->coef + q->coef;
			if (coef_sum != 0) {
				answer.append_node(p->exp, coef_sum);
			}
			p = p->next;
			q = q->next;
			continue;
		}
		if (p->exp < q->exp) {
			answer.append_node(p->exp, p->coef);
			p = p->next;
			continue;
		}
		if (p->exp > q->exp) {
			answer.append_node(q->exp, q->coef);
			q = q->next;
			continue;
		}
	}
}

void Expression_Queue::derivative_expression(Expression_Queue & answer) {
	//coef = coef × exp, exp-1
	int coef_derivative, exp_derivative;
	Node * p = head;
	while (p != nullptr) {
		coef_derivative = p->coef * p->exp;
		exp_derivative = p->exp - 1;
		answer.append_node(exp_derivative, coef_derivative);
		p = p->next;
	}
}

int Expression_Queue::evaluate_expression(int x_in) {
	int exp_out, coef_out;
	int answer = 0;
	while (is_empty() == 0) {
		retrieve(exp_out, coef_out);
		answer += coef_out * power(x_in, exp_out);
	}
	return answer;
}

int Expression_Queue::power(int bottom, int exp) {
	int answer = 1;
	int i = 1;
	if (exp == 0) {
		return 1;
	}
	while (i <= exp) {
		answer *= bottom;
		i++;
	}
	return answer;
}
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "expression_queue.h"
using namespace std;

int main() {
	Expression_Queue a, b;
	a.input();
	b.input();
	int x_in;
	cin >> x_in;
	//a.output();
	//b.output();
	//system("pause");
	//����ʽ���
	Expression_Queue sum_answer;
	a.sum_expression(b, sum_answer);
	cout << "A(x)+B(x)=";
	sum_answer.output();
	//����ʽ��
	Expression_Queue derivative_answer;
	a.derivative_expression(derivative_answer);
	cout << "A'(x)=";
	derivative_answer.output();
	//����ʽ��ֵ
	int sumanswer = a.evaluate_expression(x_in);
	cout << "A(" << x_in << ")=" << sumanswer;
	cout << endl;
	system("pause");
	return 0;
}
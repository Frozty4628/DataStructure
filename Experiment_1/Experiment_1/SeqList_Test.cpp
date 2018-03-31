#include <iostream>
#include <stdlib.h>
#include "SeqList_Test.h"
using namespace std;

int main() {
	//ifstream file_input;
	//file_input.open("Text.txt");

	//�����������Ա�A��B
	Seq a(100), b(100);
	//�������Ա�A������
	a.input();
	cout << "A is created as:";
	a.output();
	cout << endl;
	//A: �ڵڶ���λ�ò���10
	int i, x;
	cin >> i >> x;
	a.insert(i, x);
	cout << "After inserted A is";
	a.output();
	cout << endl;
	//A: ��ʾɾ��ֵ=10������Ԫ��
	cin >> x;
	a.remove(x);
	cout << "After deleted A is";
	a.output();
	cout << endl;
	//A: ����Ԫ��9
	cin >> x;
	i = a.find(x);
	if (i != 0) {
		cout << x << " is located at index of " << a.find(x) << endl;
	} else {
		cout << x << " is not found" << endl;
	}
	//A: ����Ԫ��22
	cin >> x;
	i = a.find(x);
	if (i) {
		cout << x << " is located at index of " << a.find(x) << endl;
	} else {
		cout << x << " is not found" << endl;
	}
	//�������Ա�B
	b.input();
	cout << "B is created as:";
	b.output();
	cout << endl;
	//������Ž���Ķ���
	Seq cross_list(100);
	//�󽻼�
	cross(a, b, cross_list);
	cout << "A cross B is";
	cross_list.output();
	cout << endl;
	//�½���һ����Ž���Ķ���
	Seq convergence_list(100);
	//�󲢼�
	convergence(a, b, convergence_list);
	cout << "A union B is";
	convergence_list.output();
	cout << endl;
	//�������������
	sort(convergence_list);
	cout << "A union B in sequence is";
	convergence_list.output();
	cout << endl;
	system("pause");
	return 0;
}

inline Seq::Seq(int size) {
	max_size = size;
	data = new int[size];
	last = -1;
	length = 0;
	if (data == nullptr) {
		cerr << "Memory error. " << endl;
		exit(1);
	}
}

inline Seq::~Seq() {
	delete[] data;
}

inline void Seq::input() {
	//"��ʾ����"
	int size_t;
	cin >> size_t;
	for (int i = 0; i < size_t; i++) {
		cin >> data[i];
		last++;
	}
	length = last + 1;
}

inline void Seq::output() {
	for (int i = 0; i <= last; i++) {
		cout << " " << data[i];
	}
}

inline void Seq::insert(int i, int x) {
	last++;
	length++;
	int j;
	for (j = last; j > i - 1; j--) {
		data[j] = data[j - 1];
	}
	data[j] = x;
}

inline bool Seq::remove(int x) {
	int i = find(x);
	if (i) {
		last--;
		length--;
		for (int j = i - 1; j <= last; j++) {
			data[j] = data[j + 1];
		}
		return true;
	} else {
		return false;
	}
}

inline int Seq::find(int x) {
	for (int i = 0; i < length; i++) {
		if (x == data[i]) {
			return i + 1;
		}
	}
	return 0;
}

inline void cross(Seq &list_a, Seq &list_b, Seq &answer) {
	//����a��answer��,����ĺ���Ҳ��������
	int x;
	//memcpy(answer.data, list_a.data, list_a.length);
	for (int i = 0; i < list_a.length; i++) {
		x = list_a.data[i];
		if (list_b.find(x)) {
			answer.insert(i + 1, x);
		}
	}
}

inline void convergence(Seq &list_a, Seq &list_b, Seq &answer) {
	//����a��answer��,����ĺ���Ҳ��������
	int x;
	for (int i = 0; i <= list_a.last; i++) {
	answer.data[i] = list_a.data[i];
	}
	//memcpy(answer.data, list_a.data, list_a.length);
	answer.last = list_a.last;
	answer.length = list_a.length;
	int position;
	for (int i = 0; i < list_b.length; i++) {
		x = list_b.data[i];
		if (answer.find(x) == 0) {
			position = answer.length + 1;
			answer.insert(position, x);
		}
	}
}

inline void sort(Seq &list) {
	for (int i = 0; i < list.length; i++) {
		for (int j = i; j < list.length; j++) {
			if (list.data[i] >= list.data[j]) {
				list.swap(list.data[i], list.data[j]);
			}
		}
	}
}

inline void Seq::swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}



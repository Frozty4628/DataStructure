#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "SeqList_Test.h"
using namespace std;

int main() {
	ifstream file_input;
	file_input.open("Text.txt");

	//�����������Ա�A��B
	//�������Ա�A������
	//A: �ڵڶ���λ�ò���10
	//A: ��ʾɾ��ֵ=10������Ԫ��
	//A: ����Ԫ��9
	//A: ����Ԫ��22
	//�������Ա�B
	//������Ž���Ķ���
	//�󽻼�
	//ɾ����Ž���Ķ���,���½���Ž���Ķ���
	//�󲢼�
	//�������������
	return 0;
}

Seq::Seq(int size) {
	max_size = size;
	if (data == nullptr) {
		cerr << "Memory error. " << endl;
		exit(1);
	}
}

Seq::~Seq() {
	delete[] data;
}

void Seq::input() {
	//"��ʾ����"
	for (int i = 0; i < max_size - 1; i++) {
		cin >> data[i];
		last++;
	}
	length = last + 1;
}

void Seq::output() {
	for (int i = 0; i < last; i++) {
		cout << data[i];
	}
}

bool Seq::insert(int i, int x) {
	return false;
}

bool Seq::remove(int x) {
	int i = find(x);
	if (i) {
		last--;
		for (int j = i - 1; j <= last; j++) {
			data[j] = data[j + 1];
		}
	} else {
		return false;
	}
}

int Seq::find(int x) {
	for (int i = 0; i < last; i++) {
		if (x == data[i]) {
			return i + 1;
		}
	}
	return 0;
}

void Seq::crossa_and_b(Seq &list_a, Seq &list_b, Seq &answer) {
}

void Seq::union_a_and_b(Seq &list_a, Seq &list_b, Seq &answer) {
}

void Seq::sort(Seq & list) {
}



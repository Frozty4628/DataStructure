#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "SeqList_Test.h"
using namespace std;

int main() {
	ifstream file_input;
	file_input.open("Text.txt");

	//定义两个线性表A和B
	//输入线性表A的数据
	//A: 在第二个位置插入10
	//A: 表示删除值=10的数据元素
	//A: 查找元素9
	//A: 查找元素22
	//输入线性表B
	//建立存放结果的东西
	//求交集
	//删除存放结果的东西,再新建存放结果的东西
	//求并集
	//将并集结果排序
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
	//"提示输入"
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



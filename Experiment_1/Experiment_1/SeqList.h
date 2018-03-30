#pragma once
#include <iostream>
#include <stdlib.h>
#include "SeqList_Test.h"
using namespace std;

typedef int T;
class SeqList {
public:
	SeqList(int sz);
	~SeqList();
	int Length() const;
	int Find(T&x) const;
	int Insert(T&x, int i); //插入函数的定义已经修改！！
	int Remove(T&x);
	int isEmpty() const;
	int isFull() const;
	T GetData(int i) const;
	int SetData(int i, T&x);
	void input();
	void output() const;
	int GetLast() const;
	void SetEmpty();
	T GetValue(int i);
	int FindYN(T&x);

private:
	T * data;
	int MaxSize;
	int last;
};

class SetOperations {
public:
	void Union(SeqList MyList, SeqList YourList); //并集
	void Intersection(SeqList MyList, SeqList YourList); //交集

};

//SeqList函数的实现
SeqList::SeqList(int sz) { //构造函数,通过指定sz,来定义数组的长度
	if (sz > 0) {
		data = new T[sz];
		if (data != NULL) {
			MaxSize = sz;
			this->last = -1;
		} else {
			cerr << "存储分配错误" << endl;
			exit(1);
		}
	} else {
		cerr << "输入有误，定义的数组长度必须是不小于0的整数" << endl;
		exit(1);
	}
}

SeqList::~SeqList() { //析构函数删除数组
	delete[] data;
}

int SeqList::Length() const { //求目前的表长
	cout << "长度为" << this->last + 1 << endl;
	return last + 1;
}

int SeqList::Find(T&x) const { //定位元素i的位置
							   //从前向后逐个查找
	int i = 0;
	while (i <= last && data[i] != x) {
		i++;
	}
	if (i > last) {
		cout << "查找失败，没找到这个元素" << endl;
		return -1;
	} else {
		cout << "这个元素的位置是第" << i + 1 << "个" << endl;
		return i + 1;
	}

}

int SeqList::Insert(T&x, int i) { //在第i个位置插入一个元素
								  //此处需要修改！！
								  //判断插入位置是否合理以及表是否满了
	if (i < 1 || i > last + 2) {
		cerr << "您输入的值不合理" << endl;
		return 0;
	}
	if (last + 1 == MaxSize) {
		cerr << "很抱歉，表已经满了" << endl;
		exit(1);
	}
	//进行移动，移动后面的数
	//已修改好
	this->last++;
	for (int j = last; j >= i; j--) {
		data[j] = data[j - 1];
	}
	data[i - 1] = x;
	return 0;
}

int SeqList::Remove(T&x) { //移除某一个元素
						   //首先定位元素的下标
	int i = Find(x) - 1;
	if (i >= 0) {
		for (int j = i; j < last; j++) {
			data[j + 1] = data[j];
		}
		this->last--;
		cout << "移除成功" << endl;
	} else {
		cout << "移除失败，没找到这个元素或者出现了其他错误" << endl;
	}
	return 0;
}

int SeqList::isEmpty() const { //判断表是否为空的
	return last == -1;
}

int SeqList::isFull() const { //判断表是否为满的
	return last + 1 == MaxSize;
}

T SeqList::GetData(int i) const { //获取第i个位置的元素
	cout << "这个元素的值是" << data[i - 1] << endl;
	return 0;
}

int SeqList::SetData(int i, T&x) { //设置第i个元素的值
	if (i > 0 && i <= last + 1) {
		data[i - 1] = x;
		cout << "设置成功" << endl;
		return 0;
	} else {
		cerr << "您输入的位置有误" << endl;
		return 1;
	}
}

void SeqList::input() { //向顺序表中输入数据
						//获取用户的元素数量并判断是否符合要求
	int last;
	cout << "正在填充数据，请输入元素数量" << endl;
	while (true) {
		cin >> last;
		if (last <= MaxSize && last > 0) {
			break;
		}
		cout << "输入的元素个数有误，范围应该是1到" << MaxSize - 1 << "，请重新输入：" << endl;
	}
	//判断结束开始录入数据
	for (int i = 0; i < last; i++) {
		cout << "请输入第" << i + 1 << "个元素：" << endl;
		cin >> data[i];
	}
	last--;
	this->last = last;
	cout << "数据表已建立完成" << endl;
}

void SeqList::output() const { //输出目前表中所有的元素
							   //将元素个数和每个元素输出到屏幕上
	cout << "数据表元素个数为：" << last + 1 << endl;
	for (int i = 0; i <= last; i++) {
		cout << i + 1 << "：" << data[i] << endl;
	}
}

int SeqList::GetLast() const {
	return this->last + 1;
}

void SeqList::SetEmpty() {
	this->last = -1;
}

T SeqList::GetValue(int i) {
	return data[i];
}

int SeqList::FindYN(T & x) {
	//定位元素i的位置
	//从前向后逐个查找
	int i = 0;
	while (i <= last && data[i] != x) {
		i++;
	}
	if (i > last) {
		return -1;
	} else {
		return i + 1;
	}
}

void SetOperations::Union(SeqList MyList, SeqList YourList) { //实现两个顺序表的并集
															  //定义合适长度的顺序表存放并集结果
	int leng = MyList.Length() + YourList.Length();
	SeqList UnionList(leng);
	//开始计算
	int i, j, last;
	last = MyList.GetLast();
	for (i = 0; i <= last - 1; i++) {
		T x = MyList.GetValue(i);
		UnionList.Insert(x, i + 1);
	}
	//UnionList.output();
	last = YourList.GetLast();
	for (j = 0; j <= last - 1; j++) {
		T x = YourList.GetValue(j);
		if (MyList.FindYN(x) == -1) {
			UnionList.Insert(x, i + 1);
			i++;
		}
	}
	cout << "以下是所求并集" << endl;
	UnionList.output();
}

void SetOperations::Intersection(SeqList MyList, SeqList YourList) { //实现两个顺序表的交集
																	 //定义合适长度的顺序表存放交集结果
	int leng = MyList.Length() + YourList.Length();
	SeqList UnionList(leng);
	//开始计算
	int i, j, last;
	last = YourList.GetLast();
	for (j = 0, i = 0; j <= last - 1; j++) {
		T x = YourList.GetValue(j);
		if (MyList.FindYN(x) != -1) {
			UnionList.Insert(x, i + 1);
			i++;
		}
	}
	cout << "以下是所求并集" << endl;
	UnionList.output();
	//开始计算
}
#pragma once
#include <iostream>
#include <stdlib.h>
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

//SeqList::SeqList(int sz)
//{
//	//构造函数,通过指定sz,来定义数组的长度
//	if (sz > 0)
//	{
//		data = new T[sz];
//		if (data != NULL)
//		{
//			MaxSize = sz;
//			last = -1;
//		}
//		else
//		{
//			cerr << "存储分配错误" << endl;
//			exit(1);
//		}
//	}
//	else
//	{
//		cerr << "输入有误，定义的数组长度必须是不小于0的整数" << endl;
//		exit(1);
//	}
//}
//
//SeqList::~SeqList()
//{
//	delete[] data;
//}
//
//int SeqList::Length() const
//{
//	return last + 1;
//}
//
//int SeqList::Find(T & x) const
//{
//	//从前向后逐个查找
//	int i = 0;
//	while (i <= last && data[i] != x)
//	{
//		i++;
//	}
//	if (i > last)
//	{
//		return -1;
//	}
//	else
//	{
//		return i + 1;
//	}
//}
//
//int SeqList::Insert(T & x, int i)
//{
//	//允许的插入位置从第一位到最后一位的后一位
//	if (i <= 0 || i > last + 1)
//	{
//		cerr << "您输入的值超出了表能存储的范围" << endl;
//		exit(1);
//	}
//	//满了的情况下不允许插入
//	if (last + 1 == MaxSize)
//	{
//		cerr << "很抱歉，顺序表满了，无法存储更多数据" << endl;
//		exit(1);
//	}
//	//先从后往前移动元素，空出位置再放入值
//	for (int j = last; j > i; j--)
//	{
//		data[j] = data[j - 1];
//	}
//	data[i] = x;
//	last++;
//	return 0;
//}
//
//int SeqList::Remove(T & x)
//{
//	//先搜索有没有x这个元素
//	int i = Find(x) - 1;
//	if (i >= 0)
//	{
//		for (int j = i; j <= last; j++)
//		{
//			data[j] = data[j + 1];
//			last--;
//		}
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int SeqList::isEmpty() const
//{
//	return last == -1;
//}
//
//int SeqList::isFull() const
//{
//	return last == MaxSize - 1;
//}
//
//T SeqList::GetData(int i) const
//{
//	return data[i - 1];
//}
//
//void SeqList::SetData(int i, T & x)
//{
//	if (i > 0 && i <= last + 1)
//	{
//		data[i - 1] = x;
//	}
//}
//
//void SeqList::input()
//{
//	//获取用户的元素数量并判断是否符合要求
//	cout << "正在建立数据表，请输入元素数量" << endl;
//	while (true)
//	{
//		int last;
//		cin >> last;
//		if (last <= MaxSize && last > 0)
//		{
//			break;
//		}
//		cout << "输入的元素个数有误，范围应该是1到" << MaxSize - 1 << "，请重新输入：" << endl;
//	}
//	//判断结束开始录入数据
//	for (int i = 0; i < last; i++)
//	{
//		cout << "请输入第" << i + 1 << "个元素：" << endl;
//		cin >> data[i];
//	}
//	last--;
//	cout << "数据表已建立完成" << endl;
//}
//
//void SeqList::output() const
//{
//	//将元素个数和每个元素输出到屏幕上
//	cout << "数据表元素个数为：" << last + 1 << endl;
//	for (int i = 0; i <= last; i++)
//	{
//		cout << i + 1 << "：" << data[i] << endl;
//	}
//}

//this is a test.

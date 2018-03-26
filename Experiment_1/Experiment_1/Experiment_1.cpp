// Experiment_1.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stdlib.h>
#include "SeqList.h"
using namespace std;
typedef int T;

int main()
{
	//建立一个数据表
	SeqList MyList(100);
	while (true)
	{
		cout << "这个100元素数据表可以实现如下功能:" << endl;
		cout << "1,input data\n" << "2,insert data\n" << "3,delete data\n"
			<< "4,search data position\n" << "5,get length of list\n" << "6,set a data\n"
			<< "7,get value of data\n" << "8,output data\n" << "0,exit\n" << endl;
		cout << "目前表中的元素数量：" << MyList.GetLast() << endl;
		int choice = -1;
		cout << "请输入要实现的功能：" << endl;
		cin >> choice;

		int i;
		T x;
		switch (choice)
		{

		case 1:
			//输入数据
			MyList.input();
			break;
		case 2:
			//插入
			cout << "请输入插入的元素的值以及插入的位置，用空格隔开：" << endl;
			cin >> x >> i;
			MyList.Insert(x, i);
			break;
		case 3:
			//删除
			cout << "请输入想要删除的位置：" << endl;
			cin >> i;
			MyList.Remove(x);
			break;
		case 4:
			//搜索
			cout << "请输入想要查找的元素的值：" << endl;
			cin >> x;
			MyList.Find(x);
			break;
		case 5:
			//求长度
			MyList.Length();
			break;
		case 6:
			//设置数据
			cout << "请输入想要设置元素的位置以及新的值，用空格隔开：" << endl;
			cin >> i >> x;
			MyList.SetData(i, x);
			break;
		case 7:
			//获取数据
			cout << "请输入想要查找的元素的位置：" << endl;
			cin >> i;
			MyList.GetData(i);
			break;
		case 8:
			//输出
			MyList.output();
			break;
		case 0:
			break;
		default:
			cout << "你输入了错误的选项，请重新输入\n" << endl;
		}

		if (choice == 0)
		{
			cout << "欢迎再次使用......" << endl;
			break;
		}
	}
	return 0;
}


//SeqList函数的实现
SeqList::SeqList(int sz)
{ //构造函数,通过指定sz,来定义数组的长度
	if (sz > 0)
	{
		data = new T[sz];
		if (data != NULL)
		{
			MaxSize = sz;
			this->last = -1;
		}
		else
		{
			cerr << "存储分配错误" << endl;
			exit(1);
		}
	}
	else
	{
		cerr << "输入有误，定义的数组长度必须是不小于0的整数" << endl;
		exit(1);
	}
}

SeqList::~SeqList()
{ //析构函数删除数组
	delete[] data;
}

int SeqList::Length() const
{ //求目前的表长
	cout << "长度为" << this->last + 1 << endl;
	return 0;
}

int SeqList::Find(T&x) const
{ //定位元素i的位置
  //从前向后逐个查找
	int i = 0;
	while (i <= last && data[i] != x) {
		i++;
	}
	if (i > last)
	{
		cout << "查找失败，没找到这个元素" << endl;
		return -1;
	}
	else
	{
		cout << "这个元素的位置是第" << i + 1 << "个" << endl;
		return i + 1;
	}

}

int SeqList::Insert(T&x, int i)
{ //在第i个位置插入一个元素
  //此处需要修改！！
  //判断插入位置是否合理以及表是否满了
	if (i <= 1 || i > last + 1)
	{
		cerr << "您输入的值不合理" << endl;
		return 0;
	}
	if (last + 1 == MaxSize)
	{
		cerr << "很抱歉，表已经满了" << endl;
		exit(1);
	}
	//进行移动，移动后面的数
	//已修改好
	this->last++;
	for (int j = last; j >= i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i - 1] = x;
	return 0;
}

int SeqList::Remove(T&x)
{ //移除某一个元素
  //首先定位元素的下标
	int i = Find(x) - 1;
	if (i >= 0)
	{
		for (int j = i; j < last; j++)
		{
			data[j + 1] = data[j];
		}
		this->last--;
		cout << "移除成功" << endl;
	}
	else
	{
		cout << "移除失败，没找到这个元素或者出现了其他错误" << endl;
	}
	return 0;
}

int SeqList::isEmpty() const
{ //判断表是否为空的
	return last == -1;
}

int SeqList::isFull() const
{ //判断表是否为满的
	return last + 1 == MaxSize;
}

T SeqList::GetData(int i) const
{ //获取第i个位置的元素
	cout << "这个元素的值是" << data[i - 1] << endl;
	return 0;
}

int SeqList::SetData(int i, T&x)
{ //设置第i个元素的值
	if (i > 0 && i <= last + 1)
	{
		data[i - 1] = x;
		cout << "设置成功" << endl;
		return 0;
	}
	else
	{
		cerr << "您输入的位置有误" << endl;
		return 1;
	}
}

void SeqList::input()
{ //向顺序表中输入数据
  //获取用户的元素数量并判断是否符合要求
	int last;
	cout << "正在填充数据，请输入元素数量" << endl;
	while (true)
	{
		cin >> last;
		if (last <= MaxSize && last > 0)
		{
			break;
		}
		cout << "输入的元素个数有误，范围应该是1到" << MaxSize - 1 << "，请重新输入：" << endl;
	}
	//判断结束开始录入数据
	for (int i = 0; i < last; i++)
	{
		cout << "请输入第" << i + 1 << "个元素：" << endl;
		cin >> data[i];
	}
	last--;
	this->last = last;
	cout << "数据表已建立完成" << endl;
}

void SeqList::output() const
{ //输出目前表中所有的元素
  //将元素个数和每个元素输出到屏幕上
	cout << "数据表元素个数为：" << last + 1 << endl;
	for (int i = 0; i <= last; i++)
	{
		cout << i + 1 << "：" << data[i] << endl;
	}
}

int SeqList::GetLast() const
{
	return this->last + 1;
}

//this is a test.

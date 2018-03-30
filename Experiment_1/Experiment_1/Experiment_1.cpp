// Experiment_1.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <stdlib.h>
#include "SeqList.h"
using namespace std;
typedef int T;

int experiment_1_main()
{
	//建立一个数据表
	SeqList MyList(100);
	SeqList YourList(100);
	SetOperations setcalc;
	while (true)
	{
		cout << "这个100元素数据表可以实现如下功能:" << endl;
		cout << "1,input data\n" << "2,insert data\n" << "3,delete data\n"
			<< "4,search data position\n" << "5,get length of list\n" << "6,set a data\n"
			<< "7,get value of data\n" << "8,output data\n"
			<< "9,work out union set of 2 lists\n" << "10,work out intersection set of 2 lists\n"
			<< "0,exit\n" << endl;
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
		case 9:
			//求并集
			cout << "请输入第二个顺序表的元素个数" << endl;
			YourList.input();
			setcalc.Union(MyList, YourList);
			YourList.SetEmpty();
			break;
		case 10:
			//求交集
			cout << "请输入第二个顺序表的元素个数" << endl;
			YourList.input();
			setcalc.Intersection(MyList, YourList);
			YourList.SetEmpty();
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




//this is a test.

// Experiment_1.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <stdlib.h>
#include "SeqList.h"
using namespace std;
typedef int T;

int experiment_1_main()
{
	//����һ�����ݱ�
	SeqList MyList(100);
	SeqList YourList(100);
	SetOperations setcalc;
	while (true)
	{
		cout << "���100Ԫ�����ݱ����ʵ�����¹���:" << endl;
		cout << "1,input data\n" << "2,insert data\n" << "3,delete data\n"
			<< "4,search data position\n" << "5,get length of list\n" << "6,set a data\n"
			<< "7,get value of data\n" << "8,output data\n"
			<< "9,work out union set of 2 lists\n" << "10,work out intersection set of 2 lists\n"
			<< "0,exit\n" << endl;
		cout << "Ŀǰ���е�Ԫ��������" << MyList.GetLast() << endl;
		int choice = -1;
		cout << "������Ҫʵ�ֵĹ��ܣ�" << endl;
		cin >> choice;

		int i;
		T x;
		switch (choice)
		{

		case 1:
			//��������
			MyList.input();
			break;
		case 2:
			//����
			cout << "����������Ԫ�ص�ֵ�Լ������λ�ã��ÿո������" << endl;
			cin >> x >> i;
			MyList.Insert(x, i);
			break;
		case 3:
			//ɾ��
			cout << "��������Ҫɾ����λ�ã�" << endl;
			cin >> i;
			MyList.Remove(x);
			break;
		case 4:
			//����
			cout << "��������Ҫ���ҵ�Ԫ�ص�ֵ��" << endl;
			cin >> x;
			MyList.Find(x);
			break;
		case 5:
			//�󳤶�
			MyList.Length();
			break;
		case 6:
			//��������
			cout << "��������Ҫ����Ԫ�ص�λ���Լ��µ�ֵ���ÿո������" << endl;
			cin >> i >> x;
			MyList.SetData(i, x);
			break;
		case 7:
			//��ȡ����
			cout << "��������Ҫ���ҵ�Ԫ�ص�λ�ã�" << endl;
			cin >> i;
			MyList.GetData(i);
			break;
		case 8:
			//���
			MyList.output();
			break;
		case 9:
			//�󲢼�
			cout << "������ڶ���˳����Ԫ�ظ���" << endl;
			YourList.input();
			setcalc.Union(MyList, YourList);
			YourList.SetEmpty();
			break;
		case 10:
			//�󽻼�
			cout << "������ڶ���˳����Ԫ�ظ���" << endl;
			YourList.input();
			setcalc.Intersection(MyList, YourList);
			YourList.SetEmpty();
			break;
		case 0:
			break;
		default:
			cout << "�������˴����ѡ�����������\n" << endl;
		}

		if (choice == 0)
		{
			cout << "��ӭ�ٴ�ʹ��......" << endl;
			break;
		}
	}
	return 0;
}




//this is a test.

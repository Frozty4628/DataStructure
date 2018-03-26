// Experiment_1.cpp: �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <stdlib.h>
#include "SeqList.h"
using namespace std;
typedef int T;

int main()
{
	//����һ�����ݱ�
	SeqList MyList(100);
	while (true)
	{
		cout << "���100Ԫ�����ݱ����ʵ�����¹���:" << endl;
		cout << "1,input data\n" << "2,insert data\n" << "3,delete data\n"
			<< "4,search data position\n" << "5,get length of list\n" << "6,set a data\n"
			<< "7,get value of data\n" << "8,output data\n" << "0,exit\n" << endl;
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


//SeqList������ʵ��
SeqList::SeqList(int sz)
{ //���캯��,ͨ��ָ��sz,����������ĳ���
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
			cerr << "�洢�������" << endl;
			exit(1);
		}
	}
	else
	{
		cerr << "�������󣬶�������鳤�ȱ����ǲ�С��0������" << endl;
		exit(1);
	}
}

SeqList::~SeqList()
{ //��������ɾ������
	delete[] data;
}

int SeqList::Length() const
{ //��Ŀǰ�ı�
	cout << "����Ϊ" << this->last + 1 << endl;
	return 0;
}

int SeqList::Find(T&x) const
{ //��λԪ��i��λ��
  //��ǰ����������
	int i = 0;
	while (i <= last && data[i] != x) {
		i++;
	}
	if (i > last)
	{
		cout << "����ʧ�ܣ�û�ҵ����Ԫ��" << endl;
		return -1;
	}
	else
	{
		cout << "���Ԫ�ص�λ���ǵ�" << i + 1 << "��" << endl;
		return i + 1;
	}

}

int SeqList::Insert(T&x, int i)
{ //�ڵ�i��λ�ò���һ��Ԫ��
  //�˴���Ҫ�޸ģ���
  //�жϲ���λ���Ƿ�����Լ����Ƿ�����
	if (i <= 1 || i > last + 1)
	{
		cerr << "�������ֵ������" << endl;
		return 0;
	}
	if (last + 1 == MaxSize)
	{
		cerr << "�ܱ�Ǹ�����Ѿ�����" << endl;
		exit(1);
	}
	//�����ƶ����ƶ��������
	//���޸ĺ�
	this->last++;
	for (int j = last; j >= i; j--)
	{
		data[j] = data[j - 1];
	}
	data[i - 1] = x;
	return 0;
}

int SeqList::Remove(T&x)
{ //�Ƴ�ĳһ��Ԫ��
  //���ȶ�λԪ�ص��±�
	int i = Find(x) - 1;
	if (i >= 0)
	{
		for (int j = i; j < last; j++)
		{
			data[j + 1] = data[j];
		}
		this->last--;
		cout << "�Ƴ��ɹ�" << endl;
	}
	else
	{
		cout << "�Ƴ�ʧ�ܣ�û�ҵ����Ԫ�ػ��߳�������������" << endl;
	}
	return 0;
}

int SeqList::isEmpty() const
{ //�жϱ��Ƿ�Ϊ�յ�
	return last == -1;
}

int SeqList::isFull() const
{ //�жϱ��Ƿ�Ϊ����
	return last + 1 == MaxSize;
}

T SeqList::GetData(int i) const
{ //��ȡ��i��λ�õ�Ԫ��
	cout << "���Ԫ�ص�ֵ��" << data[i - 1] << endl;
	return 0;
}

int SeqList::SetData(int i, T&x)
{ //���õ�i��Ԫ�ص�ֵ
	if (i > 0 && i <= last + 1)
	{
		data[i - 1] = x;
		cout << "���óɹ�" << endl;
		return 0;
	}
	else
	{
		cerr << "�������λ������" << endl;
		return 1;
	}
}

void SeqList::input()
{ //��˳�������������
  //��ȡ�û���Ԫ���������ж��Ƿ����Ҫ��
	int last;
	cout << "����������ݣ�������Ԫ������" << endl;
	while (true)
	{
		cin >> last;
		if (last <= MaxSize && last > 0)
		{
			break;
		}
		cout << "�����Ԫ�ظ������󣬷�ΧӦ����1��" << MaxSize - 1 << "�����������룺" << endl;
	}
	//�жϽ�����ʼ¼������
	for (int i = 0; i < last; i++)
	{
		cout << "�������" << i + 1 << "��Ԫ�أ�" << endl;
		cin >> data[i];
	}
	last--;
	this->last = last;
	cout << "���ݱ��ѽ������" << endl;
}

void SeqList::output() const
{ //���Ŀǰ�������е�Ԫ��
  //��Ԫ�ظ�����ÿ��Ԫ���������Ļ��
	cout << "���ݱ�Ԫ�ظ���Ϊ��" << last + 1 << endl;
	for (int i = 0; i <= last; i++)
	{
		cout << i + 1 << "��" << data[i] << endl;
	}
}

int SeqList::GetLast() const
{
	return this->last + 1;
}

//this is a test.

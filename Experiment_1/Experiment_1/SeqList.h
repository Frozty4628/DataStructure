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
	int Insert(T&x, int i); //���뺯���Ķ����Ѿ��޸ģ���
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
	void Union(SeqList MyList, SeqList YourList); //����
	void Intersection(SeqList MyList, SeqList YourList); //����

};

//SeqList::SeqList(int sz)
//{
//	//���캯��,ͨ��ָ��sz,����������ĳ���
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
//			cerr << "�洢�������" << endl;
//			exit(1);
//		}
//	}
//	else
//	{
//		cerr << "�������󣬶�������鳤�ȱ����ǲ�С��0������" << endl;
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
//	//��ǰ����������
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
//	//����Ĳ���λ�ôӵ�һλ�����һλ�ĺ�һλ
//	if (i <= 0 || i > last + 1)
//	{
//		cerr << "�������ֵ�����˱��ܴ洢�ķ�Χ" << endl;
//		exit(1);
//	}
//	//���˵�����²��������
//	if (last + 1 == MaxSize)
//	{
//		cerr << "�ܱ�Ǹ��˳������ˣ��޷��洢��������" << endl;
//		exit(1);
//	}
//	//�ȴӺ���ǰ�ƶ�Ԫ�أ��ճ�λ���ٷ���ֵ
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
//	//��������û��x���Ԫ��
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
//	//��ȡ�û���Ԫ���������ж��Ƿ����Ҫ��
//	cout << "���ڽ������ݱ�������Ԫ������" << endl;
//	while (true)
//	{
//		int last;
//		cin >> last;
//		if (last <= MaxSize && last > 0)
//		{
//			break;
//		}
//		cout << "�����Ԫ�ظ������󣬷�ΧӦ����1��" << MaxSize - 1 << "�����������룺" << endl;
//	}
//	//�жϽ�����ʼ¼������
//	for (int i = 0; i < last; i++)
//	{
//		cout << "�������" << i + 1 << "��Ԫ�أ�" << endl;
//		cin >> data[i];
//	}
//	last--;
//	cout << "���ݱ��ѽ������" << endl;
//}
//
//void SeqList::output() const
//{
//	//��Ԫ�ظ�����ÿ��Ԫ���������Ļ��
//	cout << "���ݱ�Ԫ�ظ���Ϊ��" << last + 1 << endl;
//	for (int i = 0; i <= last; i++)
//	{
//		cout << i + 1 << "��" << data[i] << endl;
//	}
//}

//this is a test.

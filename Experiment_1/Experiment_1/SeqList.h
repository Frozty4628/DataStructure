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

//SeqList������ʵ��
SeqList::SeqList(int sz) { //���캯��,ͨ��ָ��sz,����������ĳ���
	if (sz > 0) {
		data = new T[sz];
		if (data != NULL) {
			MaxSize = sz;
			this->last = -1;
		} else {
			cerr << "�洢�������" << endl;
			exit(1);
		}
	} else {
		cerr << "�������󣬶�������鳤�ȱ����ǲ�С��0������" << endl;
		exit(1);
	}
}

SeqList::~SeqList() { //��������ɾ������
	delete[] data;
}

int SeqList::Length() const { //��Ŀǰ�ı�
	cout << "����Ϊ" << this->last + 1 << endl;
	return last + 1;
}

int SeqList::Find(T&x) const { //��λԪ��i��λ��
							   //��ǰ����������
	int i = 0;
	while (i <= last && data[i] != x) {
		i++;
	}
	if (i > last) {
		cout << "����ʧ�ܣ�û�ҵ����Ԫ��" << endl;
		return -1;
	} else {
		cout << "���Ԫ�ص�λ���ǵ�" << i + 1 << "��" << endl;
		return i + 1;
	}

}

int SeqList::Insert(T&x, int i) { //�ڵ�i��λ�ò���һ��Ԫ��
								  //�˴���Ҫ�޸ģ���
								  //�жϲ���λ���Ƿ�����Լ����Ƿ�����
	if (i < 1 || i > last + 2) {
		cerr << "�������ֵ������" << endl;
		return 0;
	}
	if (last + 1 == MaxSize) {
		cerr << "�ܱ�Ǹ�����Ѿ�����" << endl;
		exit(1);
	}
	//�����ƶ����ƶ��������
	//���޸ĺ�
	this->last++;
	for (int j = last; j >= i; j--) {
		data[j] = data[j - 1];
	}
	data[i - 1] = x;
	return 0;
}

int SeqList::Remove(T&x) { //�Ƴ�ĳһ��Ԫ��
						   //���ȶ�λԪ�ص��±�
	int i = Find(x) - 1;
	if (i >= 0) {
		for (int j = i; j < last; j++) {
			data[j + 1] = data[j];
		}
		this->last--;
		cout << "�Ƴ��ɹ�" << endl;
	} else {
		cout << "�Ƴ�ʧ�ܣ�û�ҵ����Ԫ�ػ��߳�������������" << endl;
	}
	return 0;
}

int SeqList::isEmpty() const { //�жϱ��Ƿ�Ϊ�յ�
	return last == -1;
}

int SeqList::isFull() const { //�жϱ��Ƿ�Ϊ����
	return last + 1 == MaxSize;
}

T SeqList::GetData(int i) const { //��ȡ��i��λ�õ�Ԫ��
	cout << "���Ԫ�ص�ֵ��" << data[i - 1] << endl;
	return 0;
}

int SeqList::SetData(int i, T&x) { //���õ�i��Ԫ�ص�ֵ
	if (i > 0 && i <= last + 1) {
		data[i - 1] = x;
		cout << "���óɹ�" << endl;
		return 0;
	} else {
		cerr << "�������λ������" << endl;
		return 1;
	}
}

void SeqList::input() { //��˳�������������
						//��ȡ�û���Ԫ���������ж��Ƿ����Ҫ��
	int last;
	cout << "����������ݣ�������Ԫ������" << endl;
	while (true) {
		cin >> last;
		if (last <= MaxSize && last > 0) {
			break;
		}
		cout << "�����Ԫ�ظ������󣬷�ΧӦ����1��" << MaxSize - 1 << "�����������룺" << endl;
	}
	//�жϽ�����ʼ¼������
	for (int i = 0; i < last; i++) {
		cout << "�������" << i + 1 << "��Ԫ�أ�" << endl;
		cin >> data[i];
	}
	last--;
	this->last = last;
	cout << "���ݱ��ѽ������" << endl;
}

void SeqList::output() const { //���Ŀǰ�������е�Ԫ��
							   //��Ԫ�ظ�����ÿ��Ԫ���������Ļ��
	cout << "���ݱ�Ԫ�ظ���Ϊ��" << last + 1 << endl;
	for (int i = 0; i <= last; i++) {
		cout << i + 1 << "��" << data[i] << endl;
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
	//��λԪ��i��λ��
	//��ǰ����������
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

void SetOperations::Union(SeqList MyList, SeqList YourList) { //ʵ������˳���Ĳ���
															  //������ʳ��ȵ�˳����Ų������
	int leng = MyList.Length() + YourList.Length();
	SeqList UnionList(leng);
	//��ʼ����
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
	cout << "���������󲢼�" << endl;
	UnionList.output();
}

void SetOperations::Intersection(SeqList MyList, SeqList YourList) { //ʵ������˳���Ľ���
																	 //������ʳ��ȵ�˳����Ž������
	int leng = MyList.Length() + YourList.Length();
	SeqList UnionList(leng);
	//��ʼ����
	int i, j, last;
	last = YourList.GetLast();
	for (j = 0, i = 0; j <= last - 1; j++) {
		T x = YourList.GetValue(j);
		if (MyList.FindYN(x) != -1) {
			UnionList.Insert(x, i + 1);
			i++;
		}
	}
	cout << "���������󲢼�" << endl;
	UnionList.output();
	//��ʼ����
}
#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

class List;
class LinkNode { //����һ�������
	friend List;

public:
	LinkNode(LinkNode * ptr = NULL);
	LinkNode(const int & item, LinkNode * ptr = NULL);
	~LinkNode();

private:
	LinkNode * link;
	int data;
};

class List { //����һ����������
public:
	List();
	~List();
	void make_list_empty(); //�����ÿ� done.
	int get_length(); //��ȡ������ done.
	LinkNode * get_head_node(); //��ȡͷ���ĵ�ַ done.
	LinkNode * find_node_match_value(int x); //��ȡ����ֵ�Ľ�� done.
	LinkNode * locate_address_of_node_i(int i); //��ȡ��i�����ĵ�ַ done.
	int get_data_of_node_i(int i); //��ȡ��i������dataֵ done.
	void set_data_of_node_i(int i, int x); //����ֵ
	bool insert_node_at_i(int i, int x); //����һ���ڵ�
	int remove_node_at_i(int i, int & x); //�Ƴ�λ��i��Ԫ�ز����ر�ɾ��Ԫ�ص�dataֵ
	bool is_empty_or_not(); //�ж������Ƿ�Ϊ�� done.
	void input(int end_tag); //���뺯��,���ҹ涨һ�����������־ done.
	void output(); //��� done.

private:
	LinkNode * first; //����һ��ָ��ͷ����ָ��
	LinkNode * current; //����һ��ָ��ǰ���Ԫ�ص�ָ��
	int length;
};

List::List() {
	first = new LinkNode();
	current = first;
	length = 0;
}

List::~List() {

}

inline LinkNode::LinkNode(LinkNode * point = nullptr) {
	link = point;
}

inline LinkNode::LinkNode(const int & value, LinkNode * point = nullptr) {
	data = value;
	link = point;
}

LinkNode::~LinkNode() {
}
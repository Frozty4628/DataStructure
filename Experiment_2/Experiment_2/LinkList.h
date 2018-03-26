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
	void make_list_empty();
	int get_length();
	LinkNode * get_head_node();
	LinkNode * find_node_match_value(int x);
	LinkNode * locate_address_of_node_i(int i);
	int get_data_of_node_i(int i);
	void set_data_of_node_i(int i, int x);
	bool insert_node_at_i(int i, int x);
	int remove_node_at_i(int i, int & x); //�Ƴ�λ��i��Ԫ�ز����ر�ɾ��Ԫ�ص�dataֵ
	bool is_empty_or_not();
	void input(int end_tag); //���뺯��,���ҹ涨һ�����������־
	void output();

private:
	LinkNode * first; //����һ��ֻ��ͷ����ָ��
};

List::List() {
	first = new LinkNode();
}

List::~List() {

}

LinkNode::LinkNode(LinkNode * ptr = NULL) {
}

inline LinkNode::LinkNode(const int & item, LinkNode * ptr) {
}

LinkNode::~LinkNode() {
}
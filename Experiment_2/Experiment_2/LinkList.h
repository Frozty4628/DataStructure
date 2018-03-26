#pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

class List;
class LinkNode { //定义一个结点类
	friend List;

public:
	LinkNode(LinkNode * ptr = NULL);
	LinkNode(const int & item, LinkNode * ptr = NULL);
	~LinkNode();

private:
	LinkNode * link;
	int data;
};

class List { //定义一个单链表类
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
	int remove_node_at_i(int i, int & x); //移除位于i的元素并返回被删除元素的data值
	bool is_empty_or_not();
	void input(int end_tag); //输入函数,并且规定一个输入结束标志
	void output();

private:
	LinkNode * first; //定义一个只想头结点的指针
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
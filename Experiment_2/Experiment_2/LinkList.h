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
	void make_list_empty(); //链表置空 done.
	int get_length(); //获取链表长度 done.
	LinkNode * get_head_node(); //获取头结点的地址 done.
	LinkNode * find_node_match_value(int x); //获取符合值的结点 done.
	LinkNode * locate_address_of_node_i(int i); //获取第i个结点的地址 done.
	int get_data_of_node_i(int i); //获取第i个结点的data值 done.
	void set_data_of_node_i(int i, int x); //设置值
	bool insert_node_at_i(int i, int x); //插入一个节点
	int remove_node_at_i(int i, int & x); //移除位于i的元素并返回被删除元素的data值
	bool is_empty_or_not(); //判断链表是否为空 done.
	void input(int end_tag); //输入函数,并且规定一个输入结束标志 done.
	void output(); //输出 done.

private:
	LinkNode * first; //定义一个指向头结点的指针
	LinkNode * current; //定义一个指向当前最后元素的指针
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
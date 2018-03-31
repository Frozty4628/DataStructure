#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
using namespace std;

class Seq {
public:
	Seq(int size); //done
	~Seq(); //done
	void input(); //done
	void output(); //done
	void insert(int i, int x); //done
	bool remove(int x); //done
	int find(int x); //done
	friend void cross(Seq &list_a, Seq &list_b, Seq &answer);
	friend void convergence(Seq &list_a, Seq &list_b, Seq &answer);
	friend void sort(Seq &list);
	void swap(int &a, int &b);

private:
	int max_size;
	int length;
	int last;
	int * data;
};

void cross(Seq &list_a, Seq &list_b, Seq &answer);
void convergence(Seq &list_a, Seq &list_b, Seq &answer);
void sort(Seq &list);
//insert_replace
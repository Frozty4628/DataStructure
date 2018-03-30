#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class Seq {
public:
	Seq(int size);
	~Seq();
	void input();
	void output();
	bool insert(int i, int x);
	bool remove(int x);
	int find(int x);
	void crossa_and_b(Seq &list_a, Seq &list_b, Seq &answer);
	void union_a_and_b(Seq &list_a, Seq &list_b, Seq &answer);
	void sort(Seq &list);

private:
	int max_size;
	int length;
	int last;
	int * data;
};

//insert_replace
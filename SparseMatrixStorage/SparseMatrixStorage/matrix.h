#pragma once
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Matrix;
class Element {
	friend Matrix;
private:
	int row;
	int column;
	int value;
	void operator=(Element & datain); //���ں�����,�򻯸�ֵ���
};

class Matrix {
public:
	Matrix(int rows_in, int columns_in, int terms_in);
	void sum(Matrix & b, Matrix & sum);
	void transpose(Matrix & rslt);
private:
	int rows;
	int columns;
	int terms;
	int max_terms;
	Element * array;
};
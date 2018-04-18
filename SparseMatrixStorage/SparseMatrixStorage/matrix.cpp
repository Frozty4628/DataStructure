#include "matrix.h"

void Element::operator=(Element & datain) {
	this->row = datain.row;
	this->column = datain.column;
	this->value = datain.value;
}

Matrix::Matrix(int rows_in, int columns_in, int terms_in) {
	this->rows = rows_in;
	this->columns = columns_in;
	this->terms = terms_in;
	this->max_terms = this->rows*this->columns;
	array = new Element[max_terms];
	if (array = nullptr) {
		cerr << "Storage allocation failed." << endl;
		exit(1);
	}
}

void Matrix::sum(Matrix & b, Matrix & sum) {
	int i = 0;
	int j = 0;
	int a_index = 0;
	int b_index = 0;
	int valuesum;
	while (i < terms && j < b.terms) {
		a_index = columns * array[i].row + array[i].column;
		b_index = columns * b.array[j].row + b.array[j].column;
		if (a_index < b_index) {
			sum.array[sum.terms] = array[i];
			i++;
		} else if (a_index > b_index) {
			sum.array[sum.terms] = b.array[j];
			j++;
		} else {
			valuesum = array[i].value + b.array[j].value;
			if (valuesum) {
				sum.array[sum.terms] = array[i];
				sum.array[sum.terms].value = valuesum;
				i++;
				j++;
			}
		}
		sum.terms++;
	}
	for (; i < terms; i++) {
		sum.array[sum.terms] = array[i];
		sum.terms++;
	}
	for (; j < b.terms; j++) {
		sum.array[sum.terms] = b.array[j];
		sum.terms++;
	}
}

void Matrix::transpose(Matrix & rslt) {
	int * rowsize = new int[columns];
	int * rowstart = new int[columns];
	while (terms > 0) {
		int i, j;
		for (i = 0; i < columns; i++) {
			rowsize[i] = 0;
		}
		for (i = 0; i < terms; i++) {
			rowsize[array[i].column]++;
		}
		rowstart[0] = 0;
		for (i = 1; i < columns; i++) {
			rowstart[i] = rowstart[i - 1] + rowsize[i - 1];
		}
		for (i = 0; i < terms; i++) {
			j = rowstart[array[i].column];
			rslt.array[j].row = array[i].column;
			rslt.array[j].column = array[i].row;
			rslt.array[j].value = array[i].value;
			rowstart[array[i].column]++;
		}
	}
	delete[] rowsize;
	delete[] rowstart;
}

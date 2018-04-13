#include "exam.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
	char s[100];
	gets_s(s);
	int i = huiwen(s);
	cout << i << endl;
	system("pause");
	return 1;
}

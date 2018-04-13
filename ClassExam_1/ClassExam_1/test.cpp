#include "exam.h"
using namespace std;

int  main() {
	List l(0);
	l.input(0);
	l.reverse();
	cout << "the result is:" << endl;
	l.output();
	system("pause");
	return 1;
}

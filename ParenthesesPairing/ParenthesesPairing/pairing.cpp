#include "pairing.h"

Node::Node(char ch = '#', Node * p = nullptr) {
	symbol = ch;
	next = p;
}

Stack::Stack(Node * p = nullptr) {
	top = p;
	length = 0;
}

void Stack::pushin(char chin) {
	top = new Node(chin, top);
	//_ASSERT(top != nullptr);
	length++;
}

char Stack::popout() {
	if (length) {
		char chout;
		Node * tmp = top;
		top = top->next;
		chout = tmp->symbol;
		length--;
		return chout;
	} else {
		return '#';
	}
}

char Stack::taketop() {
	if (length) {
		return top->symbol;
	} else {
		return '#';
	}
}

Pairing::Pairing() {
	symbolstack.pushin('#');
}

void Pairing::input() {
	cin.getline(symbolstring, maxn);
}

void Pairing::pairing() {
	//入栈并匹配,默认设计情况是正确情况,遇到错误情况处理
	int i = 0;
	int state = 0;
	for (i = 0; i < strlen(symbolstring); i++) {
		switch (isparenthese(symbolstring[i])) {
		case 1:
			symbolstack.pushin(symbolstring[i]);
			continue;
		case 2:
			//匹配成功则进入下一字符
			if (anotherpair(symbolstring[i]) == symbolstack.taketop()) {
				symbolstack.popout();
				continue;
			}
			//符号不匹配说明右括号错误, 包括了符号栈空的情况, 因栈底有'#'
			if (symbolstring[i] != '#' && anotherpair(symbolstring[i]) != symbolstack.taketop()) {
				state = 1;
				break;
			}
			//符号序列到结尾而栈还不空, 说明缺右括号
			if (symbolstring[i] == '#' && symbolstack.length > 1) {
				state = 2;
				break;
			}
		case 0:
			continue;
		}
		if (state) {
			break;
		}
	}
	//情况输出/处理
	switch (state) {
	case 0:
		cout << "right." << endl;
		break;
	case 1:
		cout << "The " << i + 1 << " character '" << symbolstring[i] << "' is wrong." << endl;
		break;
	case 2:
		cout << "loss of right character ";
		while (symbolstack.length > 1) {
			cout << anotherpair(symbolstack.popout());
		}
		cout << "." << endl;
		break;
	}
}

inline int Pairing::isparenthese(char chin) {
	//判断这个字符是不是括号以及是左/右括号
	int i;
	if (chin=='#') {
		return 2;
	}
	for (i = 0; i < sizeof(parentheses); i++) {
		while (chin == parentheses[i]) {
			if (i < 4) {
				return 1;
			} else {
				return 2;
			}
		}
	}
	return 0;
}

inline char Pairing::anotherpair(char chin) {
	if (chin == '{') {
		return '}';
	} else if (chin == '[') {
		return ']';
	} else if (chin == '(') {
		return ')';
	} else if (chin == '<') {
		return '>';
	} else if (chin == '}') {
		return '{';
	} else if (chin == ']') {
		return '[';
	} else if (chin == ')') {
		return '(';
	} else {
		return '<';
	}
}

void Pairing::setempty() {
	symbolstring[0] = '\0';
}

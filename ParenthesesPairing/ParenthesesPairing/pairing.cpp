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
	//��ջ��ƥ��,Ĭ������������ȷ���,���������������
	int i = 0;
	int state = 0;
	for (i = 0; i < strlen(symbolstring); i++) {
		switch (isparenthese(symbolstring[i])) {
		case 1:
			symbolstack.pushin(symbolstring[i]);
			continue;
		case 2:
			//ƥ��ɹ��������һ�ַ�
			if (anotherpair(symbolstring[i]) == symbolstack.taketop()) {
				symbolstack.popout();
				continue;
			}
			//���Ų�ƥ��˵�������Ŵ���, �����˷���ջ�յ����, ��ջ����'#'
			if (symbolstring[i] != '#' && anotherpair(symbolstring[i]) != symbolstack.taketop()) {
				state = 1;
				break;
			}
			//�������е���β��ջ������, ˵��ȱ������
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
	//������/����
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
	//�ж�����ַ��ǲ��������Լ�����/������
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

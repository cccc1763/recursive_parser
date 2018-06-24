//
// 52121729 ������
// Project 3. recursive-descent parser
// S -> aAb
// A -> aS | b
// 

#include <iostream>
using namespace std;

// functions of
// Terminal a,b
// Non-Terminal S, A
void pa();
void pb();
void pS();
void pA();

// Handle of error
void errorHandling(char* msg);

// 32 bytes size char Memory Assignment
char* nextSymbol = new char[32];
// get_nextSymbol ��� �ε��� ���.
int idx = -1;

int main() {
	// infinite loop for input
	while (1) {
		cout << "input String end with $. " << endl;
		cin >> nextSymbol;
		// ù ���ڸ� ����Ű�� ���� �ε��� +1, get_nextSymbol ��� �ε��� ���.
		idx++;
		pS();
		// ���� �ɺ��� $�� ���.
		if (nextSymbol[idx] == '$') {
			cout << "$ right" << endl;
			idx = -1;
		}
		else
			errorHandling("error occured at star");
	}
	return 0;
}

void pa() {
	// idx++�� ���� ���ǹ� ���� ���� ���ڿ��� ����Ŵ.
	if (nextSymbol[idx++] == 'a')
		// a ��Ʈ���� �������� ������ ���.
		cout << "a";
	else
		errorHandling("error occured at star");

}

void pb() {
	// idx++�� ���� ���ǹ� ���� ���� ���ڿ��� ����Ŵ.
	if (nextSymbol[idx++] == 'b')
		// b ��Ʈ���� �������� ���� ���.
		cout << "b";
	else
		errorHandling("error occured at star");
}

void pS() {
	if (nextSymbol[idx] == 'a') {
		// S->aAb
		pa(); pA(); pb();
	}
	else
		errorHandling("error occured at star");
}

void pA() {
	switch (nextSymbol[idx]) {
	case 'a':
		// A->aS
		pa(); pS();
		break;
	case 'b':
		// A->b
		pb();
		break;
	default:
		errorHandling("error occured at star");
	}
}

// ������ �ش� ��ġ* ��� �� ���� ���� �����޼��� ��� �� ���α׷� ����.
void errorHandling(char* msg) {
	cout << "*" << endl;
	cout << msg << endl;
	exit(1);
}
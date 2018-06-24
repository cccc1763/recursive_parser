//
// 52121729 최주헌
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
// get_nextSymbol 대신 인덱스 사용.
int idx = -1;

int main() {
	// infinite loop for input
	while (1) {
		cout << "input String end with $. " << endl;
		cin >> nextSymbol;
		// 첫 글자를 가리키기 위해 인덱스 +1, get_nextSymbol 대신 인덱스 사용.
		idx++;
		pS();
		// 현재 심볼이 $일 경우.
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
	// idx++를 통해 조건문 이후 다음 문자열을 가리킴.
	if (nextSymbol[idx++] == 'a')
		// a 루트로의 정상적인 진행을 출력.
		cout << "a";
	else
		errorHandling("error occured at star");

}

void pb() {
	// idx++를 통해 조건문 이후 다음 문자열을 가리킴.
	if (nextSymbol[idx++] == 'b')
		// b 루트로의 정상저인 진행 출력.
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

// 에러시 해당 위치* 출력 후 한줄 비우고 에러메세지 출력 후 프로그램 종료.
void errorHandling(char* msg) {
	cout << "*" << endl;
	cout << msg << endl;
	exit(1);
}
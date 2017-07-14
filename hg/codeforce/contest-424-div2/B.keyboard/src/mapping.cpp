#include <iostream>
#include <string>
using namespace std;

char mapper[26];

bool isCapital(char a) {
	return a >= 'A' && a <= 'Z';
}
bool isLower(char a) {
	return a >= 'a' && a <= 'z';
}
char capitalize(char ch) {
	return ch - 'a' + 'A';
}
char toLower(char ch) {
	return ch + 'a' - 'A';
}

int main() {
	string str1, str2;
	string prob;
	string answer = "";
	cin >> str1;
	cin >> str2;
	for (int i=0; i < str1.length(); i++) {
		char ch1 = str1[i];
		char ch2 = str2[i];
		mapper[ch1 - 'a'] = ch2;
	}
	cin >> prob;
	for (int i=0; i < prob.length(); i++) {
		char ch = prob[i];
		
		if (isCapital(ch)) {
			answer += capitalize(mapper[toLower(ch) - 'a']);
		} else if (isLower(ch)) {
			answer += mapper[ch - 'a'];
		} else {
			answer += ch;
		}
	}
	cout << answer << endl;
}
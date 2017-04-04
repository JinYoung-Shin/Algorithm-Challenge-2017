#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <stdlib.h>

using namespace std;

vector<char> dic;

typedef struct _node {
	int l, i; //length, index
	char c; //current character
	
	struct _node *p; //previous pointer
} node;

stack<node*> open;
vector<node*> answer;
vector<string> r;
void dump_dic() {
	for(int i=0;i<dic.size();i++) {
		cout << dic[i] << " ";
	}
}
bool valid(string& s) {
	int num_moeum = 0;
	int num_jaeum = 0;
	for (int i=0; i < s.length(); i++) {
		switch(s.at(i)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				num_moeum++;
				break;
			default:
				num_jaeum++;
		}
	}
	if (num_moeum >= 1 && num_jaeum >= 2) {
		return true;
	} else {
		return false;
	}
}
string p_a(node* ptr) {
	string str = "";
	stack<char> s;
	while (ptr && ptr->c) {
		s.push(ptr->c);
		ptr = ptr->p;
	}
	while(!s.empty()) {
		str += s.top();
		s.pop();
	}
	return str;
}
int main() {
	int L, C; //암호길이, 문자개수
	
	cin >> L >> C;
	dic.reserve(C);
	for (int i=0;i<C;i++) {
		char temp;
		cin >> temp;
		dic.push_back(temp);
	}
	
	sort(dic.begin(), dic.end());
	
	//initialization
	for (int i=0; i<dic.size();i++) {
		node *temp = (node*)malloc(sizeof(node));
		temp->l = 1;
		temp->i = i;
		temp->c = dic[i];
		open.push(temp);
	}
	
	while(!open.empty()) {
		node* cur = open.top();

		open.pop();
		
		if (cur->l == L) {
			// 길이가 완전하면 넣는다.
			// p_a(cur);
			answer.push_back(cur);
			continue;
		}

		for (int i= cur->i + 1; i < C; i++) {
			node *temp = (node*)malloc(sizeof(node));
			temp->l = cur->l + 1;
			temp->i = i;
			temp->c = dic[i];
			temp->p = cur;
			open.push(temp);
		}
	};
	
	r.reserve(answer.size());
	for (int i=0; i < answer.size(); i++) {
		string temp = p_a(answer[i]);
		if (valid(temp)) {
			r.push_back(p_a(answer[i]));
		}
	}
	sort(r.begin(), r.end());
	
	for (int i=0;i<r.size();i++) {
		cout << r[i] << endl;
	}
}
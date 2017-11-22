#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
class QuadTree{
	public:
	char data;
	QuadTree* child[4];
	
	QuadTree(char data) {
		this->data = data;
		this->child[0] = this->child[1] = this->child[2] = this->child[3] = NULL;
	}
	QuadTree() {
		this->data = '\0';
		this->child[0] = this->child[1] = this->child[2] = this->child[3] = NULL;
	}
	void print() {
		printf("%c", this->data);
		for (int i=0; i < 4; i++) {
			if (this->child[i]) {
				this->child[i]->print();
			}
		}
	}
	void reverse() {
		if (this->data == 'x') {
			for (int i=0; i< 4; i++) {
				this->child[i]->reverse();
			}
		}
		swap(this->child[0], this->child[2]);
		swap(this->child[1], this->child[3]);
	}
	void __print() {
		printf("%c", this->data);
		for (int i=0; i < 4; i++) {
			int x = (i+2) % 4;
			if (this->child[x]) {
				this->child[x]->__print();
			}
		}
	}
	int MakeTree(string& str, int index) {
		int processed = 1;
		char ch = str[index];
		if (ch == 'w' || ch == 'b') {
			this->data = ch;
			return 1;
		} else if (ch == 'x') {
			this->data = ch;
			for (int i=0; i < 4; i++) {
				this->child[i] = new QuadTree();
				processed += this->child[i]->MakeTree(str, index + processed);
			}
			return processed;
		}
		return 0;
	}
	~QuadTree() {
		this->data = '\0';
		for (int i=0; i < 4; i++) {
			if (this->child[i]) {
				this->child[i]->~QuadTree();
				this->child[i] = NULL;
			}
		}
		// printf("Destructor for %c\n", this->data);
	}
};

int main() {
	QuadTree root;
	int C;
	cin >> C;
	string str;
	
	for (int i=0; i < C; i++) {
		cin >> str;
		root.MakeTree(str, 0);

		// root.reverse();
		// root.print();
		root.__print();
		printf("\n");
		root.~QuadTree();
	}

}
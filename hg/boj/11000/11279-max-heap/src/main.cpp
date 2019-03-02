#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define MAX_SIZE 100001

class max_heap {
	private:
	vector<int> data;
	public:
	
	max_heap() {
		this->data.push_back(-1); // index 0 means dummy data
	}
	max_heap(int size) {
		this->data.reserve(size);
		this->data.push_back(-1); //index 0 is dummy data
	}
	int pop() {
		if (this->data.size() <= 1) {
			//heap is empty
			return 0;
		}
		int current = 1;
		int left_child = 2;
		int right_child = 3;
		int ret = this->data[current];
		int last = this->data.size() - 1;
		
		swap(this->data[current], this->data[last]);
		this->data.pop_back();
		while (this->data.size() > left_child) { //when left child exist
			int larger_index = left_child;
			if (this->data.size() > right_child) { //when right child exist
				if (this->data[right_child] > this->data[left_child]) {
					larger_index = right_child;
				}
			}
			if (this->data[larger_index] > this->data[current]) {
				swap(this->data[current], this->data[larger_index]);
				current = larger_index;
				left_child = current * 2;
				right_child = left_child + 1;
			} else {
				break;
			}
		}
		return ret;
		
	}
	bool push(int val) {
		this->data.push_back(val);
		int current = data.size() - 1;
		int parent = current/2;
		while (parent > 0 && this->data[current] > this->data[parent]) {
			swap(this->data[current], this->data[parent]);
			current = parent;
			parent = current/2;
		}
	}
};


int main() {
	max_heap heap(MAX_SIZE);
	int n;
	cin >> n;
	for (int i=0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > 0) {
			heap.push(tmp);
		} else {
			cout << heap.pop() << endl;
		}
	}
	return 0;
}
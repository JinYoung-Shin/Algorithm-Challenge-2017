#include <stdio.h>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> arr; //기본애들
vector<int> elite; //뽑힌애들
set<int> set1, set2;
int N;

void arr_dump();
void set_dump(set<int> a);
bool is_equal(set<int>, set<int>);
int main() {
	
	int temp;
	scanf("%d\n", &N);
	arr.reserve(N+1);
	arr.push_back(892);
	for (int i=0; i<N; i++) {
		scanf("%d\n", &temp);
		arr.push_back(temp);
	}
	
	// arr_dump();
	for(int i=1; i< arr.size(); i++) {
		set1.insert(arr[i]);
	}
	// cout << "set1 : ";
	// set_dump(set1);
	for (set<int>::iterator pos = set1.begin(); pos != set1.end(); pos++) {
		set2.insert(arr[*pos]);
	}
	// cout << "set2 : ";
	// set_dump(set2);
	// cout << "is_equal " << is_equal(set1, set2) << endl;
	

	do {
		set1 = set2;
		set2.clear();
		for (set<int>::iterator pos = set1.begin(); pos != set1.end(); pos++) {
			set2.insert(arr[*pos]);
		}
		
	} while(!is_equal(set1, set2));
	// cout << "fin";
	// set_dump(set1);
	printf("%lu", set1.size());
	set_dump(set1);
}

void arr_dump() {
	for (int i=1; i<arr.size(); i++) {
		printf("%d ", arr[i]);
	}
}
void set_dump(set<int> a) {
	cout << endl;
	for (set<int>::iterator IterPos = a.begin(); IterPos != a.end(); IterPos++) {
		cout << *IterPos << endl;
	}
}
bool is_equal(set<int> a, set<int> b) {
	if (a.size() != b.size()) {
		return false;
	}
	set<int>::iterator ai, bi;
	ai = a.begin();
	bi = b.begin();
	while (ai != a.end()) {
		if (*ai != *bi) {
			return false;
		}
		ai++;
		bi++;
	}
	return true;
}
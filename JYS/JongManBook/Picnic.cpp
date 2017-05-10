//
//  main.cpp
//  icpc
//
//  Created by Spiritsensor on 2017. 3. 9..
//  Copyright © 2017년 JYS. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int n, m;
bool friends[15][15] = {false};
bool done[15] = {false};

int f1, f2;
int firstFree;

int paring(bool done[15]) {
	firstFree = -1;
	for(int i = 0;  i < n; i++) {
		if(!done[i]) {
			firstFree = i;
			break;
		}
	}
	
	if(firstFree == -1) {
		return 1;
	}
	int ans = 0;
	// pair with next friends
	for(int i = firstFree+1; i < n; i++) {
		if(friends[firstFree][i] && !done[i]) {
			done[firstFree] = done[i] = true;
			ans += paring(done);
			done[firstFree] = done[i] = false;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &f1, &f2);
			friends[f1][f2] = friends[f2][f1] = true;
		}
	}
	// print available pair
	printf("%d", paring(done));
	return 0;
}

/*
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

bool friends[15][15] = { false };
vector<bool> pair(15);

int test_case;
int n, m;
int f1, f2;

int pair_friends(vector<bool>& _pair) {
    int firstFree = -1;
    for(int i = 0; i < n; ++i) {
        if(!_pair[i]) {
            firstFree = i;
            break;
        }
    }
    
    if(firstFree == - 1) return 1;
    int ret = 0;
    for(int i = firstFree+1; i < n; ++i) {
        _pair[firstFree] = true;
        _pair[i] = true;
        ret += pair_friends(_pair);
        _pair[firstFree] = false;
        _pair[i] = false;
    }
    
    return ret;
}

int main(int argc, const char * argv[]) {
    scanf("%d", &test_case);
    for(int t = 1; t <= test_case; t++) { // Test Times
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++) {
            scanf("%d %d", &f1, &f2);
            friends[f1][f2] = true;
            friends[f2][f1] = true;
        }
        
        print("%d\n", pair_friends(pair));
        
    }
    return 0;
}
*/

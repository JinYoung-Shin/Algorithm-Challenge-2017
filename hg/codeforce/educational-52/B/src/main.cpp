#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll vertex, edge;
    cin >> vertex >> edge;
    ll max_cover = edge * 2; //edge개로 커버할수 있는 최대 버택스 개수
    ll min_cover = 0; //edge개로 커버할 수 있는 최소 버택스 개수
    
    for (int i=0; i <= 100001; i++) { //i는 버텍스 개수
        ll mcover = 1LL * i * (i - 1) / 2;
        if (edge <= mcover) {
            min_cover = i;
            break;
        }
    }
    
    cout << max(0LL, vertex - max_cover) << ' ';
    cout << max(0LL,vertex - min_cover) << endl;
	return 0;
}


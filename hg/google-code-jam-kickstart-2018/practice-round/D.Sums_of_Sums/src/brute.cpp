#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> arr;
vector<ll> processed;
vector<ll> accumul;
int main() {
    int t;
    cin >> t;
    for (int tc=1; tc <= t; tc++) {
        printf("Case #%d:\n", tc);
        int n, q;
        cin >> n >> q;
        // arr.reserve(n);
        ll sum = 0;
        arr.push_back(sum);
        for (int i=0; i< n; i++) {
            ll tmp;
            cin >> tmp;
            sum += tmp;
            arr.push_back(sum);
        }
        
        // for (size_t i=0; i < arr.size(); i++) {
        //     cout << arr[i] << ' ';   
        // }
        // cout << '\n';
        // processed.reserve(n*(n+1)/2);
        for (int l = 1; l <= n; l++) {
            for (int i=l; i <= n; i++) {
                int start = i - l;
                int end = i;
                processed.push_back(arr[end] - arr[start]);
            }
        }
        sort(processed.begin(), processed.end());
        
        accumul.reserve(processed.size() + 1);
        sum = 0;
        accumul.push_back(sum);
        for (size_t i=0; i < processed.size(); i++) {
            sum += processed[i];
            accumul.push_back(sum);    
        }
        for (int i=0; i < q; i++) {
            ll src, dst;
            cin >> src >> dst;
            cout << (accumul[dst] - accumul[src-1]) << '\n';
        }
        
        arr.clear();
        processed.clear();
        accumul.clear();
        
        // for (size_t i=0; i < processed.size(); i++) {
        //     cout << processed[i] << ' ';
        // }
        // cout << '\n';
        
    }
	return 0;
}


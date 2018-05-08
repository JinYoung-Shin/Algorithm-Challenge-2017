#include <bits/stdc++.h>
using namespace std;

class Data {
    public:
    int start, end;
    Data(int start, int end) {
        this->start = start;
        this->end = end;
    }
    bool operator <(const Data& rhs) const {
        if (end == rhs.end) {
            return start < rhs.start;
        } else {
            return end < rhs.end;
        }
    }
    void dump() {
        printf("%d %d\n", start, end);
    }
};

vector<Data> arr;


int main() {
    int n;
    cin >> n;
    arr.reserve(n);
    for (int i=0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(Data(a, b));
    }
    
    sort(arr.begin(), arr.end());
    
    int end = 0;
    int ans = 0;
    for (int i=0; i< n;i++) {
        auto& obj = arr[i];
        if (end <= obj.start) {
            end = obj.end;
            ans++;
        }
        
        // obj.dump();
    }
    
    cout << ans << endl;
	return 0;
}


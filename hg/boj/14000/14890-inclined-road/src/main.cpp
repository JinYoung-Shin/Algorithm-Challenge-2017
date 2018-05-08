#include <bits/stdc++.h>
using namespace std;

int field[105][105];
int road[105];
typedef pair<int, int> pii;
int main() {
    int n;
    int l;
    cin >> n >> l;
    int ans = 0;
    for (int i=1; i <= n; i++) {
        for (int j=1;j <= n; j++) {
            cin >> field[i][j];
        }
    }
    
    //garo check
    vector<pii> arr; //값, 연속개수
    for (int i=1; i <= n; i++) {
        arr.clear();
        int prev = field[i][1];
        int prev_num = 1;
        for (int j=2; j <= n ;j++) {
            auto& cur = field[i][j];
            if (cur != prev) {
                arr.push_back(make_pair(prev, prev_num));
                prev_num = 0;
            }
            prev_num++;
            prev = cur;
        }
        arr.push_back(make_pair(prev, prev_num));

        bool correct = true;
        for (int k=1; k < (int)arr.size(); k++) {
            auto& p_height = arr[k-1].first;
            auto& p_length = arr[k-1].second;
            auto& c_height = arr[k].first;
            auto& c_length = arr[k].second;
            int delta = p_height - c_height;
            if (delta*delta > 1) {
                correct = false;
                break;
            }
            if (p_height == c_height+1) {
                c_length -= l;
                if (c_length < 0) {
                    correct = false;
                }
            } else if (p_height+1 == c_height) {
                p_length -= l;
                if (p_length < 0) {
                    correct = false;
                }
            }
        }
        
        if (correct) {
            ans++;
        }
    }
    
    //sero check
    for (int i=1; i <= n; i++) {
        arr.clear();
        int prev = field[1][i];
        int prev_num = 1;
        for (int j=2; j <= n ;j++) {
            auto& cur = field[j][i];
            if (cur != prev) {
                arr.push_back(make_pair(prev, prev_num));
                prev_num = 0;
            }
            prev_num++;
            prev = cur;
        }
        arr.push_back(make_pair(prev, prev_num));

        bool correct = true;
        for (int k=1; k < (int)arr.size(); k++) {
            auto& p_height = arr[k-1].first;
            auto& p_length = arr[k-1].second;
            auto& c_height = arr[k].first;
            auto& c_length = arr[k].second;
            int delta = p_height - c_height;
            if (delta*delta > 1) {
                correct = false;
                break;
            }
            if (p_height == c_height+1) {
                c_length -= l;
                if (c_length < 0) {
                    correct = false;
                }
            } else if (p_height+1 == c_height) {
                p_length -= l;
                if (p_length < 0) {
                    correct = false;
                }
            }
        }
        
        if (correct) {
            ans++;
        }
    }
    
    cout << ans << endl;
    
	return 0;
}


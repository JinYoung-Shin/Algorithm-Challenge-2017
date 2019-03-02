#include <bits/stdc++.h>
using namespace std;

class TwoDiagonals {
    public:
    int maxPoints(vector<int> x, vector<int> y) {
        size_t len = x.size();
        int add[1999];
        int sub[1999];
        memset(add, 0, sizeof(add));
        memset(sub, 0, sizeof(sub));
        set<pair<int, int> > pos;
        for (size_t i=0; i < len; i++) {
            int xval = x[i];
            int yval = y[i];
            pos.insert(make_pair(xval, yval));
            add[xval + yval]++;
            sub[yval - xval + 999]++;
        }
        int add_max = add[0]; 
        for (int i=1; i <= 1998; i++) {
            add_max = max(add_max, add[i]);
        }
        int sub_max = sub[0];
        for (int i=1; i <= 1998; i++) {
            sub_max = max(sub_max, sub[i]);
        }
        vector<int> add_max_entry;
        vector<int> sub_max_entry;
        for (int i=0; i <= 1998; i++) {
            if (add[i] == add_max) {
                add_max_entry.push_back(i);
            }
            if (sub[i] == sub_max) {
                sub_max_entry.push_back(i);
            }
        }
        // printf("add_max: %d\nsub_max: %d\n", add_max, sub_max);
        // printf("y-x=%d, y+x=%d\n", add_max_entry[0], sub_max_entry[0]-999);
        int ret = add_max + sub_max;
        int subtract = 1;
        for (size_t i=0; i < add_max_entry.size(); i++) {
            for (size_t j=0; j < sub_max_entry.size(); j++) {
                int y_minus_x = sub_max_entry[j]-999;
                int y_plus_x = add_max_entry[i];
                if ( (y_minus_x + y_plus_x) % 2 != 0 ) return ret;
                int yy = (y_minus_x + y_plus_x) / 2;
                int xx = y_plus_x - yy;
                // printf("intersection (%d, %d)\n", xx, yy);
                if (pos.find(make_pair(xx, yy)) == pos.end()) {
                    // printf("it is not crossed\n");
                    return ret;
                } else {
                    // printf("it crossed\n");
                }
            }
        }
        return ret - subtract;
    }
};

int main() {
    vector<int> x;
    vector<int> y;
    TwoDiagonals obj;
    int n;
    cin >> n;
    for (int i=0;i < n; i++) {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    for (int i=0; i < n; i++) {
        int tmp;
        cin >> tmp;
        y.push_back(tmp);
    }
    cout << obj.maxPoints(x, y) << endl;
    return 0;
}
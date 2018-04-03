#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ll n, k;
    cin >> n >> k;
    ll carriage = 0;
    ll box_type = 1;
    ll box_number = 0;
    for (int i=1; i <= k; i++) {
        ll current_box_capa;
        cin >> current_box_capa;
        ll current_box_number = n / current_box_capa;
        ll current_carriage = current_box_capa * current_box_number;
        if (carriage < current_carriage) {
            carriage = current_carriage;
            box_type = i;
            box_number = current_box_number;
        }
    }
    cout << box_type << ' ' << box_number << endl;
    
	return 0;
}


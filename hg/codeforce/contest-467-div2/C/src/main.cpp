#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, bool> plb;
int main() {
    // vector<plb> period;
    ll k, d, t; //켜져있는시간, 확인하는텀, 굽는대시간
    cin >> k >> d >> t;
    ll kdfloor = (k + d-1)/d;
    ll period = kdfloor * d; //한 주기
    ll goal = 2*t;
    double ans = 0;

        
    ll amount_for_single_period = 2*k + period-k; //한 주기에 굽는 양

    
    ll elapsed_time = goal / amount_for_single_period * period; //주기단위로 굽은 시간
    ll grilled_amount = goal / amount_for_single_period * amount_for_single_period; //주기단위로 구운 양
    ans += elapsed_time;
    goal -= grilled_amount;
    
    // cout << ans << endl << goal << endl;
    
    if (goal >= 2*k) { //hot시간보다 더 구워야 할 경우
        goal -= 2*k; //구운 양
        ans += k; //구운 시간
        if (goal > 0) {
            ans += goal; //warm시간에 구운 양
        }
    } else {
        ans += (double)goal/2; //hot시간보다 덜 구워야 할 경우
    }
    
    // cout << ans << '\n';
    printf("%.11lf\n", ans);
	return 0;
}


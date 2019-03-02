#include <iostream>

using namespace std;

int next(int n) {
    int new_n = (n % 10) + (n / 10);
    return n%10*10 + new_n%10;
}
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int m = n;
    do {
        m = next(m);
        cnt++;
    } while(n != m);
    cout << cnt << endl;
    return 0;
}
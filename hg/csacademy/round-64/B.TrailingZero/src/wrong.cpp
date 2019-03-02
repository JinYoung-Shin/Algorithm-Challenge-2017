#include <iostream>

using namespace std;

inline void ans(int a) {
    printf("A %d\n", a);
    fflush(stdout);
}
inline bool query(int a) { // at least A!
    int ret;
    printf("Q %d\n", a);
    fflush(stdout);
    scanf("%d", &ret);
    fflush(stdin);
    return ret == 1 ? true : false;
}
int binary_search(int start, int end) { // inclusive range
    // if (start == end) return start;
    if (end - start == 1) return start;
    if (start < end + 1) {
        int mid = (start + end) / 2;
        if (query(mid)) {
            return binary_search(mid, end);
        } else {
            return binary_search(start, mid);
        }
    }
    return -1; //invalid value
}
int leading_zero_to_N(int x) {
    int n = 5;
    int mantisa = 12;
    int expon = 1;
    while (true) {
        if (expon == x) return n;
        n++;
        mantisa *= n;
        while (mantisa % 10 == 0) {
            mantisa /= 10;
            expon ++;
        }
        mantisa %= 100;
    }
}
int main() {
    int x = binary_search(0, 1000000);
    ans(leading_zero_to_N(x));
    return 0;
}
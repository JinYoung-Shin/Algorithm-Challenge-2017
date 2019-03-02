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

int binary_search(int start, int end) { // inclusive-exclusive range [)
    if (end - start == 1) return start;

    if (start < end + 1) {
        int mid = (start+ end) / 2;
        if (query(mid)) {
            return binary_search(mid, end);
        } else {
            return binary_search(start, mid);
        }
    }
    return -1; //invalid value
}

int leading_zero_to_N(int target) {
    int cnt = 0;
    for (int n = 5; ; n++) {
        int x = n;
        while (x % 5 == 0) {
            x /= 5;
            cnt++;
        }
        if (cnt >= target) {
            return n;
        }
    }
    return -1;
}
int main() {
    
    int x = binary_search(1, 1000001);
    if (x == -1) {
        int a = 0;
        int b = 50/a;
    }
    
    ans(leading_zero_to_N(x));
    return 0;
}
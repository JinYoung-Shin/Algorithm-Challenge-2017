#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define STAT_OO 0
#define STAT_IO 2
#define STAT_I  1

int main() {
    int n, m;
    scanf("%d\n%d\n", &n, &m);
    int stat = STAT_OO;
    int current_len = 0;
    int ans = 0;
    for (int i=0; i < m; i++) {
        char ch;
        scanf("%c", &ch);
        switch(stat) {
            case STAT_OO:
            if (ch == 'I') {
                stat = STAT_I;
            }
            break;
            
            case STAT_I:
            if (ch == 'I') {
                ans += max(current_len - n + 1, 0);
                current_len = 0;
            } else {
                stat = STAT_IO;
            }
            break;
            case STAT_IO:
            if (ch == 'I') {
                stat = STAT_I;
                current_len++;
            } else {
                stat = STAT_OO;
                ans += max(current_len - n + 1, 0);
                current_len = 0;
            }
            break;
            
            default:
            fprintf(stderr, "invalid input\n");
            exit(EXIT_FAILURE);
        }
    }
    ans += max(current_len - n + 1, 0);
    current_len = 0;
    cout << ans << '\n';
    
	return 0;
}


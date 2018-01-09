#include <bits/stdc++.h>
using namespace std;

bool dp[101][101];
bool chk[101][101];
string pattern;
string str;
set<string> answer;
bool get(int pi, int si) { //pattern index, string index
    if (chk[pi][si]) {
        return dp[pi][si];
    }
    char pc = pattern[pi];
    char sc = str[si];
    if ( pi == pattern.length() ) { //패턴이 끝났을때
        if ( si == str.length() ) { // 문자열도 끝나면 성공
            chk[pi][si] = true;
            return dp[pi][si] = true;    
        } else { //문자열이 남으면 실패
            chk[pi][si] = false;
            return dp[pi][si] = false;    
        }
    }
    if ( si == str.length() ) { //문자열이 끝낫을때
        bool ret = false;
        if (pc == '*') {
            ret = get(pi+1, si);
        }
        chk[pi][si] = true; //패턴이 안끝났으면 실패
        return dp[pi][si] = ret;
    }
    if (pc == sc or pc == '?') { //패턴과 문자가 일치하거나, ?일경우 진행
        chk[pi][si] = true;
        return dp[pi][si] = get(pi+1, si+1);
    }
    if (pc == '*') {
        bool ret = false;
        chk[pi][si] = true;
        ret |= get(pi+1, si); //매치 안되는경우
        ret |= get(pi, si+1); //매치 되는 경우
        return dp[pi][si] = ret;
    }
    //exception
    
    chk[pi][si] = true;
    return dp[pi][si] = false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        
        cin >> pattern;
        int n;
        cin >> n;
        while (n--) {
            
            cin >> str;
            memset(dp, 0, sizeof(dp));
            memset(chk, 0, sizeof(dp));
            if (get(0, 0)) {
                answer.insert(str);
            }
        }
        for (auto it : answer) {
            cout << it << '\n';
        }
        answer.clear();
    }
	return 0;
}


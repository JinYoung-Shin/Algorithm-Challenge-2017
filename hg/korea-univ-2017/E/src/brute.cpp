#include <bits/stdc++.h>
using namespace std;

const int CH_NUM = 26;

string decrypt(string& src, int shift) {
    string ret = "";
    for (size_t i=0; i < src.length(); i++) {
        char ch = src[i];
        char new_ch = (ch - 'a' + shift) % 26 + 'a';
        ret += new_ch;
    }
    return ret;
}
vector<string> words;
bool chk(string& src) {
    for (size_t i=0; i < words.size(); i++) {
        if (src.find(words[i]) != std::string::npos)
            return true;
    }
    return false;
}
int main() {
    string src;
    cin >> src;
    int n;
    cin >> n;
    words.reserve(n);
    while(n--) {
        string next;
        cin >> next;
        words.push_back(next);
    }
    for (int i=0;i < 26; i++) {
        string decrypted = decrypt(src, i);
        if( chk(decrypted) ) {
            cout << decrypted << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
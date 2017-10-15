#include <string>
#include <iostream>
#include <algorithm>
#include <clocale>

using namespace std;

bool solution(string a, string b)
{
    bool answer = true;
    int indexA[27] = {0};
    int indexB[27] = {0};
    int sum = 0;
    
    // tolower(a);
    // tolower(b);
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    
    // 같은 문자열 수 입력된다고 가정하면 알파벳 개수(합) 같으면 된다
    // cout << a.length() << ' ' << b.length();
    for(int i = 0; i < a.length(); i++)
        indexA[a[i]-'a']++;
    for(int i = 0; i < b.length(); i++)
        indexB[b[i]-'a']++;
    
    for(int i = 0; i < 26; i++) {
        sum += abs(indexA[i] - indexB[i]);
    }
    
    if(sum != 0) answer = false;
    
    return answer;
}
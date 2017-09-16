#include <string>
#include <vector>
#include <algorithm>
using namespace std;
static string reverse(const string &input)
{
 string temp(input);
 reverse(temp.begin(), temp.end());
 return temp;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i=0; i < n; i++) {
        int line = (arr1[i] | arr2[i]);
        string row("");
        for (int i=0; i < n; i++) {
            if (line & 1) {
                row += "#";
            } else {
                row += " ";
            }
            line /= 2;
        }
        answer.push_back(reverse(row));
    }
    return answer;
}
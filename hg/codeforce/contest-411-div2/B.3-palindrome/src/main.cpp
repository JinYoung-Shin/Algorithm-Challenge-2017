#include <iostream>
#include <string>

using namespace std;
/* a,b,c 이용해서 이름을 만들되, 
 * 길이 3인 palindrome이 없고,
 * c를 최소한 적게 쓰도록
*/
int main() {
	int n;
	string answer;
	cin >> n;
	bool is_a = true;
	while (n) {
		if (n == 1) {
			if (is_a) {
				answer += "a";
			} else {
				answer += "b";
			}
			is_a = !is_a;
			n--;
		} else if (n > 1) {
			if (is_a) {
				answer += "aa";
			} else {
				answer += "bb";
			}
			is_a = !is_a;
			n -= 2;
			
		}
	}
	
	cout << answer << endl;
}
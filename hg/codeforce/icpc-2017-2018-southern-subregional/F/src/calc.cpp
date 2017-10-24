#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> ss;

std::string ReplaceAll(std::string &str, const std::string& from, const std::string& to){
    size_t start_pos = 0; //string처음부터 검사
    while((start_pos = str.find(from, start_pos)) != std::string::npos)  //from을 찾을 수 없을 때까지
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // 중복검사를 피하고 from.length() > to.length()인 경우를 위해서
    }
    return str;
}

string process(string& str) {
	while (true) {
		string cache = str;
		while (true) {
			string after = ReplaceAll(str, "kh", "h");
			if (str == after) break;
		}
		while(true) {
			// string after = ReplaceAll(str, "oo", "u");
			string after = ReplaceAll(str, "u", "oo");
			if (str == after) break;
		}
		if (cache == str) break;
	}
	
	return str;
}

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i=0; i < n; i++) {
		string str;
		cin >> str;
		// cout << str << " - ";
		str = process(str);
		// cout << str << endl;
		if (ss.insert(str).second == false) {
			ans++;
		}
	}
	// cout << ans << endl;
	cout << ss.size() << endl;
	// for (set<string>::iterator ptr = ss.begin(); ptr != ss.end(); ptr++) {
	// 	cout << *ptr << endl;
	// }
}
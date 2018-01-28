#include <bits/stdc++.h>
using namespace std;

class BigInteger{
    public:
    vector<char> arr;
    
    BigInteger() {
    }
    BigInteger(string str) {
        arr.reserve(str.length());
        for (size_t i=0; i< str.length(); i++) {
            char ch = str[i];
            arr.push_back(ch);
        }
    }
    BigInteger(vector<char> arr) {
        this->arr = arr;
    }
    void setVal(string str) {
        arr.clear();
        arr.reserve(str.length());
        for (size_t i=0; i< str.length(); i++) {
            char ch = str[i];
            arr.push_back(ch);
        }
    }
    vector<char>& getVal() {
        return arr;
    }
    string getString() {
        string str("");
        for (size_t i=0; i< arr.size(); i++) {
            str += arr[i];
        }
        return str;
    }
    BigInteger operator+(BigInteger& rhs) {
        if (arr.size() < rhs.arr.size()) return rhs + *this;
        int lptr = arr.size() - 1;
        int rptr = rhs.arr.size() - 1;
        int carry = 0;
        vector<char> ret_arr;
        while(lptr >= 0) {
            char lval = arr[lptr] - '0';
            char rval = (rptr >= 0 ? rhs.arr[rptr] - '0' : 0);
            char nval = lval + rval + carry;
            carry = nval / 10;
            nval %= 10;
            ret_arr.push_back(nval + '0');
            lptr--;
            rptr--;
        }
        if (carry != 0) {
            ret_arr.push_back(carry + '0');
        }
        reverse(ret_arr.begin(), ret_arr.end());
        return BigInteger(ret_arr);
    }
    
};
int main() {
    BigInteger a, b;
    string str;
    cin >> str;
    a = BigInteger(str);
    cin >> str;
    b = BigInteger(str);
    
    BigInteger c = a+b;
    cout << c.getString() << endl;
    
	return 0;
}


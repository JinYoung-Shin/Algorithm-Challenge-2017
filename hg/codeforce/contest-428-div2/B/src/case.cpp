#include <iostream>
#include <cstdlib>

using namespace std;
void fail() {
	cout << "NO" << endl;
	exit(EXIT_SUCCESS);
}
int main() {
	int n, k;// n= num of row, k= num of group;
	
	int seat2, seat4, seat1 = 0;
	cin >> n >> k;
	seat2 = n * 2;
	seat4 = n;
	
	for (int i=0; i < k; i++) {
		int num;
		cin >> num;
		if (num % 4 == 1) { //4n + 1의 경우
			if (seat1 > 0) {
				seat1--;
				num -= 1;
			} else if (seat4 > 0) { //4인 좌석에 1명 앉힘
				seat4--;
				seat2++;
				num -= 1;
			} else if (seat2 > 0) { //2인 좌석에 1명 앉힘
				seat2--;
				num -= 1;
			} else {
				fail();
			}
		} else if (num % 4 == 2) { // 4n + 2의 경우
			if (seat2 > 0) {
				seat2--;
				num -= 2;
			} else if (seat4 > 0) {
				seat4--;
				seat1++;
				num -= 2;
			} else if (seat1 > 1) {
				seat1 -= 2;
				num -= 2;
			} else {
				fail();
			}
		} else if (num % 4 == 3) {
			if (seat2 >0 && seat1 > 0) {
				seat2--;
				seat1--;
				num -= 3;
			} else if (seat4 >0) {
				seat4--;
				num -= 3;
			} else if (seat2 > 1) {
				seat2 -= 2;
				num -= 3;
			} else if (seat1 > 2) {
				seat1 -= 3;
				num -= 3;
			} else {
				fail();
			}
		}
			

		//4로 나누어떨어지는 경우, 4자리짜리
		while(num > 0) {
			if (seat4 > 0) { // 4인 좌석에 앉힘
				int req_seat4 = num / 4;
				if (req_seat4 > 0) {
					if (req_seat4 > seat4) {
						num -= 4 * seat4;
						seat4 = 0;
					} else {
						num = 0;
						seat4 -= req_seat4;
					}
				}
			} else if (seat2 > 0) { // 2인 좌석에 앉힘
				int req_seat2 = num / 2;
				if (req_seat2 > 0) {
					if (req_seat2 > seat2) {
						num -= 2 * seat2;
						seat2 = 0;
					} else {
						num = 0;
						seat2 -= req_seat2;
					}
				}
			} else if (seat1 > 0) {// 1인 좌석에 앉힘
				seat1--;
				num -= 1;
			} else {
				fail();
			}
		}
		
		
	}
	cout << "YES" << endl;
	return 0;
}
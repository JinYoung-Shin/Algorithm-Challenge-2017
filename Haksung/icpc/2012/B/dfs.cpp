#include <cstdio>
#include <algorithm>

int  V, MAX, map[15];



int main() {
	int n, m;
	scanf("%d", &n);
	while(n--) {
		init_map();
		scanf("%d", &m);
		while(m--) color_map();
		print_max()l
	}

	return 0;
}

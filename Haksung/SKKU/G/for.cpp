#include <cstdio>

int N, l, M, x[110], y[110], half, max;

int main() {
	int ti, tj, tx, ty, count;
	// input
	scanf("%d %d %d", &N, &l, &M);
	half = l/2;
	for(int i=1; i<=M; i++)	scanf("%d %d", &x[i], &y[i]);
	// first fish to last fish + all combination of fishes' x, y
	for(int i=1; i<=M; i++) {
		for(int j=1; j<=M; j++) {
			ti = x[i]; tj = y[j];
			for(int k=1; k<half; k++) {
				tx = k; ty = half-k; count = 0;
				for(int p=1; p<=M; p++)
					if(x[p]<=ti+tx && x[p]>=ti && y[p]<=tj+ty && y[p]>=tj)	count++;
				if(count > max)	max = count;
			}
		}
	}
	printf("%d", max);
	
	return 0;
}

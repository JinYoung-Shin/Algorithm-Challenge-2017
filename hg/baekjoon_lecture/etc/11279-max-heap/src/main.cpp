#include <stdio.h>

#define HEAP_CAP 2000000
// #define TYPE long long
#define TYPE heap_data

typedef struct _heap_data {
	int a, b, size;
} heap_data;


TYPE data[HEAP_CAP];
int size;

inline int pri(int x) { return data[x].size; }
// #define pri(x) (data[x].size)


void heapify() {
	int pointer = 0;
	while (pointer * 2 + 1 < size) {
		// if (data[pointer * 2 + 1].size > data[pointer * 2 + 2].size) {
		if (pri(pointer * 2 + 1) > pri(pointer * 2 + 2)) {
			TYPE temp = data[pointer];
			data[pointer] = data[pointer * 2 + 1];
			data[pointer * 2 + 1] = temp;
			pointer = pointer * 2 + 1;
		} else {
			TYPE temp = data[pointer];
			data[pointer] = data[pointer * 2 + 2];
			data[pointer * 2 + 2] = temp;
			pointer = pointer * 2 + 2;
		}
	}
}
void push(TYPE val) {
	int pointer;
	if (size == HEAP_CAP) {
		printf("Heap is full!\n");
		return;
	}
	
	data[size] = val;
	pointer = size;
	size++;
	
	// while (pointer > 0 && data[pointer] > data[ (pointer - 1) / 2 ]) {
	while (pointer > 0 && pri(pointer) > pri( (pointer-1) / 2) ) {
		TYPE temp = data[pointer];
		data[pointer] = data[ (pointer - 1) / 2];
		data[ (pointer - 1) / 2 ] = temp;
		pointer = (pointer - 1) / 2;
	}
}

TYPE pop() {
	TYPE val;
	if (size == 0) {
		// printf("Heap is empty!\n");
		val.size = 0;
		return val;
	}
	val = data[0];
	data[0] = data[--size];
	data[size].size = 0;
	
	heapify();
	return val;
}
int main() {
	TYPE tmp;
	size = 0;
	int N;
	int temp;
	
	scanf("%d\n", &N);
	while(N--) {
		scanf("%d\n", &temp);
		if (temp > 0) {
			tmp.size = temp;
			push(tmp);
		} else {
			printf("out : %d\n", pop().size);
		}
	}
}
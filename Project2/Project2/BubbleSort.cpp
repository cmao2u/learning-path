#include "BubbleSort.h"
void BubbleSort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < (len - i - 1); j++) {
			if (arr[j] > arr[j + 1]) {
				swap2(&arr[j], &arr[j + 1]);
			}
		}
	}
}
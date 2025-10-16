#include "swap2.h"
void swap2(int*p1, int*p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
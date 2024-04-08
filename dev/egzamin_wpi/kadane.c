int max(int value1, int value2) {
	return value1 > value2 ? value1 : value2;
}

int kadane(int A[], int size) {
	if (size == 0) return 0;
	
	int maxGlobal = A[0];
	int maxCurrent = A[0];
	int i = 1;
	
	while (i < size) {
		maxCurrent = max(A[i], maxCurrent + A[i]);
		maxGlobal = max(maxCurrent, maxGlobal);
		i++;
	}
	
	return maxGlobal;
}

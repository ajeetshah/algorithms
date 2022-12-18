#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
	int currSum = 0;
	int count = 0;

	// add all a's
	int i = 0;
	while((i<a_count) && (currSum + *(a+i) <= maxSum)) {
		currSum += *(a+i);
		count++;
		i++;
	}
	i--;
	int maxCount = count;

	// add b's (and remove a's when needed)
	int j = 0;
	while(1) {
		if(j<b_count && (currSum + *(b+j) <= maxSum)) {
			currSum += *(b+j);
			count++;
			j++;
			if (count > maxCount) {
				maxCount = count;
			}
			continue;
		} else if(j<b_count && i>=0 && (currSum + *(b+j) > maxSum)) {
			currSum -= *(a+i);
			count--;
			i--;
			if (count > maxCount) {
				maxCount = count;
			}
			continue;
		} else {
			break;
		}
	}

	return maxCount;
}

int main() {
	int a[4] = {5, 5, 10, 10};
	int b[5] = {9, 9, 1, 1, 5};
	printf("%d\n", twoStacks(20, 4, a, 5, b));

        int a2[5] = {4, 2, 4, 6, 1};
        int b2[4] = {2, 1, 8, 5};
        printf("%d\n", twoStacks(10, 5, a2, 4, b2));

	return 0;
}


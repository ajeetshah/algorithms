#include<stdio.h>
#include<stdlib.h>

int* slidingMaximum(const int* A, int n1, int B, int *len1) {
    
    int i;
    int j;
    int max;

    int *C = malloc((n1-B+1) *sizeof(int));
    *len1 = 0;

    
    /*if(n1==0){
        return 0;
    }*/
    
    if (n1 == B) {
        max = *A;
        for (j=0;j<n1;j++) {
            if(max < *(A+j)) {
                max = *(A+j);                
            }    
        }
	*(C+*len1) = max;
	(*len1)++;
        return C;
    }
    
    for(i=0; i<n1-B; i++) {
        max = *(A+i);
        for(j=i; j<i+B; j++) {
            if(max < *(A+j)) {
                max = *(A+j);                
            }
        }
        *(C+(*len1)) = max;
        (*len1)++;     
    }
    
    return C;
}

int main() {
	const int A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int* len1;
	int* C = slidingMaximum(A, 10, 1, len1);
	int i;
	for(i=0; i<*len1; i++) {
		printf("%d\n", C[i]);
	}
	return 0;
}

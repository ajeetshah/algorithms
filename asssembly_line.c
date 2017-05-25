#include<stdio.h>
#define LINES 2
#define STATIONS 4

int min(int a, int b) {
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

void nl() {
	printf("\n");
}

int main() {
	int A[LINES][STATIONS];
	int T[LINES][STATIONS-1];
	int E[LINES];
	int X[LINES];

	int i, j;
	
	// inputs
	printf("Assembly times %d x %d:\n", LINES, STATIONS);
	for(i=0; i<LINES; i++){
		for(j=0; j<STATIONS; j++){
			scanf("%d", &A[i][j]);
		}
	}
	
	printf("Transition times %d x %d:\n", LINES, STATIONS-1);
	for(i=0; i<LINES; i++){
		for(j=0; j<STATIONS-1; j++){
			scanf("%d", &T[i][j]);
		}
	}
	
	printf("Entry times %d:\n", LINES);
	for(i=0; i<LINES; i++){
		scanf("%d", &E[i]);
	}

	printf("Exit times %d:\n", LINES);
	for(i=0; i<LINES; i++){
		scanf("%d", &X[i]);
	}
	
	nl();
	
	// calculation
	int MinTime[LINES][STATIONS]; // min time passing stations

	MinTime[0][0] = A[0][0] + E[0];
	MinTime[1][0] = A[1][0] + E[1];
	
	for(j = 1; j<STATIONS; j++) {
		for(i=0; i<LINES; i++) {
			int Time1 = MinTime[i][j-1] + A[i][j];
			int Time2 = MinTime[!i][j-1] + T[!i][j-1] + A[i][j];
			MinTime[i][j] = min(Time1, Time2);
		}
	}

	// output the result
	for(i=0; i<LINES; i++){
		for(j=0; j<STATIONS; j++){
			printf("%d ", MinTime[i][j]);
		}
		nl();
	}

	int min_pass_time_exit = min(MinTime[0][STATIONS-1] + X[0], MinTime[1][STATIONS-1] + X[1]);

	printf("\nMinimum time exiting assemly line: %d\n", min_pass_time_exit);

	return 0;
}


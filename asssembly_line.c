#include<stdio.h>
#define LINES 2
#define STATIONS 6

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

void nl2() {
	printf("\n\n");
}

void printPathInc(int line, int station, int from[][STATIONS-1]) {
        if (station == -1) {
                return;
        }
        printPathInc(from[line][station], station-1, from);
        printf("Line %d, Station %d\n", line, station);
}

int main() {
	/* int LINES, STATIONS;
	printf("Number of lines and stations: ");
	scanf("%d %d", &LINES, &STATIONS);*/

	int A[LINES][STATIONS] = {
		7, 9, 3, 4, 8, 4,
		8, 5, 6, 4, 5, 7
	};
	int T[LINES][STATIONS-1] = {
		2, 3, 1, 3, 4,
		2, 1, 2, 2, 1
	};
	int E[LINES] = {2, 4};
	int X[LINES] = {3, 2};

	int i, j;
	
	// inputs
	/* printf("Assembly times %d x %d:\n", LINES, STATIONS);
	for(i=0; i<LINES; i++){
		for(j=0; j<STATIONS; j++){
			scanf("%d", &A[i][j]);
		}
	}*/
	
	/* printf("Transition times %d x %d:\n", LINES, STATIONS-1);
	for(i=0; i<LINES; i++){
		for(j=0; j<STATIONS-1; j++){
			scanf("%d", &T[i][j]);
		}
	}*/
	
	/* printf("Entry times %d:\n", LINES);
	for(i=0; i<LINES; i++){
		scanf("%d", &E[i]);
	}*/

	/* printf("Exit times %d:\n", LINES);
	for(i=0; i<LINES; i++){
		scanf("%d", &X[i]);
	}*/
	
	nl();
	
	// calculation
	int MinTime[LINES][STATIONS]; // min time passing stations
	int from[LINES][STATIONS-1];

	MinTime[0][0] = A[0][0] + E[0];
	MinTime[1][0] = A[1][0] + E[1];
	
	for(j = 1; j<STATIONS; j++) {
		for(i=0; i<LINES; i++) {
			int Time1 = MinTime[i][j-1] + A[i][j];
			int Time2 = MinTime[!i][j-1] + T[!i][j-1] + A[i][j];
			int t = min(Time1, Time2);
			if(t == Time1 && t == Time2) {
				from[i][j-1] = -1;
			}
			else if(t == Time1){
				from[i][j-1] = i;
			}
			else {
				from[i][j-1] = !i;
			}
			MinTime[i][j] = t;

		}
	}

	// output the result
	for(i=0; i<LINES; i++){
		for(j=0; j<STATIONS; j++){
			printf("%d ", MinTime[i][j]);
		}
		nl();
	}

	nl();

	for(i=0; i<LINES; i++) {
		for(j=0; j<STATIONS-1; j++) {
			printf("%d ", from[i][j]);
		}
		nl();
	}

	int t0 =  MinTime[0][STATIONS-1] + X[0];
	int t1 =  MinTime[1][STATIONS-1] + X[1];

	int t = min(t0, t1);

	int lastLine;
	if(t == t0 && t == t1) {
		lastLine = -1;
	} else if(t == t0) {
		lastLine = 0;
	} else {
		lastLine = 1;
	}

	int min_pass_time_exit = t;
	printf("\nMinimum time exiting assemly line: %d\n", min_pass_time_exit);

	nl();

	// print the path
	if (lastLine == -1) {
		printf("Time of passing Station %d is same for all %d lines.", STATIONS-1, LINES);
		printf("Which one would you like to choose? Line %d or Line %d?", LINES-2, LINES-1);
		scanf("%d", &lastLine);
	}
	printf("Line %d, Station %d\n", lastLine, STATIONS-1);

	int line = lastLine;
	for(i=STATIONS-2; i>=0; i--) {
		line = from[line][i];
		
		if (line == -1) {
			printf("Time of passing Station %d is same for all %d lines.", i, LINES);
			printf("Which one would you like to choose? Line %d or Line %d?", LINES-2, LINES-1);
			scanf("%d", &line);
		}
		printf("Line %d, Station %d\n", line, i);
		line = from[line][i];
	}

	// print path in increasing order
	printPathInc(lastLine, STATIONS-1, from);
	
	return 0;
}


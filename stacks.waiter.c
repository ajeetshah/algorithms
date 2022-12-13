#include<assert.h>
#include<ctype.h>
#include<limits.h>
#include<math.h>
#include<stdbool.h>
#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);
int* get_primes(int*, int);
int* filter(int, int*, int*, int*, int*, int it, int q);
int main2();

int* waiter(int number_count, int* number, int q, int* result_count) {
	/*for(int i = 0; i<number_count; i++) {
		printf("number+%d: %d\n", i, *(number+i));
	}*/

	int* primes = malloc(q * sizeof(int));
	primes = get_primes(primes, q);

	/*for(int i=0; i<q; i++){
		printf("primes %d: %d\n", i, *(primes+i));
	}*/

	int* result = malloc(0);
	*result_count = 0;
	int it = 1;
	result = filter(number_count, number, result_count, result, primes, it, q);
	
	/*for(int i=0; i<*result_count; i++) {
		printf("result: %d,", *(result+i));
	}*/

	return result;
}

int* filter (int number_count, int* number_o, int* result_count, int* result, int* primes, int it, int q) {

	int* number = malloc(number_count * sizeof(int));
        for(int i=0; i<number_count; i++){
                *(number+i) = *(number_o+number_count-i-1);
        }

	int* ai = malloc(0);
	int ai_count = 0;
	int* bi = malloc(0);
	int bi_count = 0;

	for(int i=0; i<number_count; i++) {
		if(*(number+i) % *(primes+it-1) != 0) {
			ai = realloc(ai, (ai_count + 1)*sizeof(int));
			*(ai+ai_count) = *(number+i);
			ai_count++;
		} else {
			bi = realloc(bi, (bi_count + 1)*sizeof(int));
			*(bi+bi_count) = *(number+i);
			bi_count++;
		}
	}

	/*for(int i=0; i<ai_count; i++) {
		printf("ai: %d, ", *(ai+i));
	}
	for(int i=0; i<bi_count; i++) {
		printf("bi: %d, ", *(bi+i));
	}*/
	
	if(bi_count > 0) {
		result = realloc(result, (*result_count + bi_count)*sizeof(int));
		for(int i=0; i<bi_count; i++) {
			*(result+*result_count+i) = *(bi+bi_count-i-1);
		}
		*result_count += bi_count;
	}

	if(it < q) {
		return filter(ai_count, ai, result_count, result, primes, it+1, q);
	} else {
		result = realloc(result, (*result_count + ai_count)*sizeof(int));
		for(int i=0; i<ai_count; i++) {
			*(result + *result_count + i) = *(ai+ai_count-i-1);
		}
		*result_count += ai_count;
		return result;
	}
}

int main() {
	int number[6] = {2,3,4,5,6,7};
	int* result_count;
	*result_count = 0;
	int* result = waiter(6, number, 3, result_count);
	
	/*int number[5] = {3,4,7,6,5};
        int* result_count;
        *result_count = 0;
        int* result = waiter(5, number, 1, result_count);*/

	/*int number[5] = {3,3,4,4,9};
        int* result_count;
        *result_count = 0;
        int* result = waiter(5, number, 2, result_count);*/


	return 0;
}

int main2()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int q = parse_int(*(first_multiple_input + 1));

    char** number_temp = split_string(rtrim(readline()));

    int* number = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int number_item = parse_int(*(number_temp + i));

        *(number + i) = number_item;
    }

    int result_count;
    int* result = waiter(n, number, q, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

int *get_primes(int *primes, int count) {

        int i = 0;
        primes[i] = 2;
        i++;

        int j = 0;
        int number = 3;

        while(1) {
                if (i == count) {
                        break;
                }

                if (sqrt(number) < (double) primes[j]) { // a prime
                        primes[i] = number;
                        i++;
                        number++;
                        j = 0;
                        continue;
                }

		if (number % primes[j] == 0) { // not a prime
                        number++;
                        j = 0;
                        continue;
                }
                j++;
        }

        return primes;
}


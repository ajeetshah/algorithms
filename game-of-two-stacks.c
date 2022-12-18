#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* newNode(int data) {
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

int isEmpty(struct Node* root) {
	return !root;
}

void push(struct Node** root, int data) {
	struct Node* node = newNode(data);
	node->next = *root;
	*root = node;
	printf("%d pushed to stack\n", data);
}

int pop(struct Node** root) {
	if(isEmpty(*root)) {
		return INT_MIN;
	}
	struct Node* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}

int peek(struct Node** root) {
	if(isEmpty(*root)) {
		return INT_MIN;
	}
	return (*root)->data;
}

int twoStacks(int maxSum, int a_count, int* a, int b_count, int* b) {
	for(int i; i<a_count; i++) {
		printf("%d ", *(a+i));
	}
	printf("\n");
	for(int j; j<b_count; j++) {
		printf("%d ", *(b+j));
	}
	printf("\n");

        int currSum = 0;
	
	int i = 0;
	int j = 0;
	
	while(1) {
		if (currSum > maxSum){
			return i+j-1;
		}

		if(i<a_count && j<b_count) {
			if(*(a+i) < *(b+j)) {
				currSum += *(a+i);
				i++;
			} else if(*(a+i) > *(b+j)) {
				currSum += *(b+j);
				j++;
			} else {
				currSum += *(a+i);
				i++;
			}
		} else if(i<a_count){
			currSum += *(a+i);
			i++;
		} else if(j<b_count){
			currSum += *(b+j);
			j++;
		} else {
			return i+j;
		}
	}

	return i+j;
}

int main() {
	/*
	struct Node* root = NULL;
	push(&root, 10);
	push(&root, 20);
	push(&root, 30);
	printf("%d popped from stack\n", pop(&root));
	printf("Top element is %d\n", peek(&root));
	*/
	
	int a[5] = {4, 2, 4, 6, 1};
	int b[4] = {2, 1, 8, 5};
	printf("%d\n", twoStacks(10, 5, a, 4, b));

	return 0;
}

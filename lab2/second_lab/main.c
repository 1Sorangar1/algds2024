#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int value;
	struct node* left;
	struct node* right;
} node;


void ll_rotation_test() {
	node* top = (node*)malloc(sizeof(node));
	top->value = 10;
	node* left = (node*)malloc(sizeof(node));
	left->value = 5;
	node* leftleft = (node*)malloc(sizeof(node));
	leftleft->value = 1;

	top->right = NULL;
	top->left = left;
	left->right = NULL;
	left->left = leftleft;
	leftleft->left = NULL;
	leftleft->right = NULL;

	node* current = left->right;
	left->right = top;
	top->left = current;

	printf("%d %d %d", left->left->value, left->value, left->right->value);
}





int main() {

	ll_rotation_test();


	return 0;
}

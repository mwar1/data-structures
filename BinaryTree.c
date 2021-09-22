#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} TreeNode;

void printPreOrder(TreeNode *root) {
	printf("%i\n", root->data);
	if (root->left != NULL) {
		printPreOrder(root->left);
	}
	if (root->right != NULL) {
		printPreOrder(root->right);
	}
}

void printInOrder(TreeNode *root) {
	if (root->left != NULL) {
		printInOrder(root->left);
	}
	printf("%i\n", root->data);
	if (root->right != NULL) {
		printInOrder(root->right);
	}
}

void printPostOrder(TreeNode *root) {
	if (root->left != NULL) {
		printPostOrder(root->left);
	}
	if (root->right != NULL) {
		printPostOrder(root->right);
	}
	printf("%i\n", root->data);
}

void addNode(TreeNode *root, int data) {
	TreeNode *next;
	if (data <= root->data) {
		if (root->left == NULL) {
			TreeNode *new = (TreeNode *) malloc(sizeof(TreeNode));
			new->data = data;
			new->left = NULL;
			new->right = NULL;

			root->left = new;
		} else {
			addNode(root->left, data);
		}
	} else {
		if (root->right == NULL) {
			TreeNode *new = (TreeNode *) malloc(sizeof(TreeNode));
			new->data = data;
			new->left = NULL;
			new->right = NULL;

			root->right = new;
		} else {
			addNode(root->right, data);
		}
	}
}

bool isInTree(TreeNode *root, int data) {
	bool found = false;

	if (root->data == data) {
		return true;
	}

	if (root->left != NULL) {
		found = isInTree(root->left, data);
	}
	if (root->right != NULL && !found) {
		found = isInTree(root->right, data);
	}
	return found;
}

int main() {
	TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
	root->data = 12;
	root->left = NULL;
	root->right = NULL;

/*
	int testData[6] = {7, 6, 12, 18, 3, 11};

	for (int i=0; i<6; i++) {
		addNode(root, testData[i]);
	}
*/

	for (int i=0; i<11; i+=2) {
		addNode(root, i);
	}

	for (int j=0; j<13; j++) {
		printf("%i - %i\n", j, isInTree(root, j));
	}

	return 0;
}
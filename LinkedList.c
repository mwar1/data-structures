#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} node_t;

void listInsert(node_t *head, int pos, int val) {
	node_t *current = head;
	for (int i=0; i<pos-1; i++) {
		current = current->next;
	}

	node_t *insert = (node_t *) malloc(sizeof(node_t));
	insert->data = val;
	insert->next = current->next;
	current->next = insert;
}

void listPush(node_t *head, int val) {
	node_t *current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = (node_t *) malloc(sizeof(node_t));
	current->next->data = val;
	current->next->next = NULL;
}

int listGetFirst(node_t **head) {
	int result = -1;

    if (*head == NULL) {
        return -1;
    }

    node_t *next_node = NULL;
    next_node = (*head)->next;
    result = (*head)->data;
    free(*head);
    *head = next_node;

    return result;
}

int listPop(node_t *head) {
	int result;
	if (head->next == NULL) {
		result = head->data;
		free(head);
		return result;
	}

	node_t *current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

 	result = current->next->data;
 	free(current->next);
	current->next = NULL;
	return result;
}

int listRemove(node_t **head, int pos) {
	int result = -1;
	node_t *current = *head;
	node_t *tempNode = NULL;

	if (pos == 0) {
		return listGetFirst(head);
	}

	for (int i=0; i<pos-1; i++) {
		if (current->next == NULL) {
			return result;
		}
		current = current->next;
	}

	tempNode = current->next;
	result = tempNode->data;
	current->next = tempNode->next;
	free(tempNode);

	return result;	
}

void printLinkedList(node_t *head) {
	printf("%i\n", head->data);
	if (head->next != NULL) {
		printLinkedList(head->next);
	}
}

int main() {
	node_t *head = NULL;
	head = (node_t *) malloc(sizeof(node_t));
	head->data = 0;
	head->next = NULL;
 
	for (int i=0; i<5; i++) {
		listAppend(head, i+1);
	}


	printf("\n");
	printLinkedList(head);

	int x = listRemove(&head, 3);
	printf("\nX - %i\n", x);
	printLinkedList(head);

	return 0;
}
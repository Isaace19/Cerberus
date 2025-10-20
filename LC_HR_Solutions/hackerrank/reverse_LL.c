typedef struct Node {
	int data;
	struct Node* next;
} Node;

void reverse (Node** head_reference_node) {
	Node* prev = NULL;
	Node* curr = *head_reference_node;
	Node* next = NULL;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*head_reference_node = prev;
}

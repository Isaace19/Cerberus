typdef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} Node;

void inOTrav(Node* root) {
	if (root != NULL) {
		inOTrav(root->left);
		printf("%d", root->data);
		in0Trav(root->right);
	}
}

/* Dynamic programming based solution for Vertex Cover problem for a Binary Tree */
#include <iostream>
#include <cstdlib>

int min(int x, int y) { return (x < y) ? x : y; }

/* A binary tree node has data, pointer to left child and a pointer to 
right child */
struct node{
    int data;
    int vc;
    struct node *left, *right;
    node(int data) : data(data),vc(-1),left(NULL),right(NULL){}
};
// A dynamic programmic based solution that returns size of the minimum vertex cover.
int vertexCover(struct node *root){
    // The size of minimum vertex cover is zero if tree is empty or there is only one node i.e. root.
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;

    // If vertex cover for this node is already evaluated, then return it.
    // to save recomputation of same subproblem again.
    if (root->vc != -1)
        return root->vc;

    // Calculate size of vertex cover when root is part of it
    int size_root_inc = 1 + vertexCover(root->left) + vertexCover(root->right);

    // Calculate size of vertex cover when root is not part of it
    int size_root_exc = 0;
    if (root->left)
        size_root_exc += 1 + vertexCover(root->left->left) + vertexCover(root->left->right);
    if (root->right)
        size_root_exc += 1 + vertexCover(root->right->left) + vertexCover(root->right->right);

    // Minimum of two values is vertex cover, store it before returning.
    root->vc = min(size_root_inc, size_root_exc);

    // returning minimum of the two.
    return root->vc;
}

struct node *newNode(int data){
    struct node *temp = new node(data);
    return temp;
};

int main(){
	int k=10;
	
	// The tree graph structure
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->right->right = newNode(6);
    root->right->right->left = newNode(7);
    root->right->right->right->left = newNode(8);
    root->right->right->right->right = newNode(9);
    root->right->right->right->left->left = newNode(10);
    root->right->right->right->left->right = newNode(11);
    root->right->right->right->left->left->right = newNode(12);
    root->right->right->right->left->left->left = newNode(13);
    root->right->right->right->right->left = newNode(14);
    root->right->right->right->right->right = newNode(15);
    root->right->right->right->right->left = newNode(16);
    root->right->right->right->right->right->right = newNode(17);
    root->right->right->right->right->right->left = newNode(18);
    root->right->right->right->right->left->left = newNode(19);
    root->right->right->right->right->left->right = newNode(20);
    
    int vc_size = vertexCover(root); // Store size of vertex cover

	// Output size of minimum vertex cover and if vertex cover within size k is found or not
    std::cout << "\nSize of the minimum vertex cover is " << vc_size;
    std::cout << "\nVertex cover size smaller or equal to k = " << k << " : ";
    if(vc_size <= k)
    	std::cout << "TRUE";
    else
    	std::cout << "FALSE";
    
    return 0;
}


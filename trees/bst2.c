#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}tr;
struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{
    if (!root)
    {
        struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
        new_node->val = val;
        new_node->left = NULL;
        new_node->right = NULL;
         
	    return new_node;
    }
			
    if (val > root->val)
		root->right = insertIntoBST(root->right, val);
    else 
		root->left = insertIntoBST(root->left, val);
			
    return root;
}
int main() {
    int c,n,p;
    struct TreeNode *root;
    while(1) {
        printf("\n \n1.Insert\t2.Inorder traversal\t3.Preorder Traversal\t4.Postorder traversal\t5.Delete\t6.Exit\n\n");
        printf("Enter choice\t");
        scanf("%d", &c);
        switch(c){
            case 1:{
                printf("Enter value\t");
                scanf("%d", &n);
                root=insertIntoBST(root,n);
            }
            default: exit(0);
        }
    }printf("%d\n",root->val);
}
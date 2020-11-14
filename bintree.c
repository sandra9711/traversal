struct Node{
    int key;
    struct Node *left, *right}
    
struct Node * newNode(int key){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->key=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void inorder(struct Node* temp){
    if(!temp){
        return;
    }
    inorder(temp->left);
    printf("%d",temp->key);
    inorder(temp->right);

}
void preorder(struct Node* temp){
    if(!temp){
        return;
    }
     
    printf("%d",temp->key);
    inorder(temp->left);
    inorder(temp->right);

}
void postorder(struct Node* temp){
    if(!temp){
        return;
    }
    inorder(temp->left);
     
    inorder(temp->right);
    printf("%d",temp->key);

}
void delete(struct Node* root, struct Node* n_d){
    
}
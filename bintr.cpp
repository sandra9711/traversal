#include <iostream>

// C++ program to delete element in binary tree 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has key, pointer to left 
child and a pointer to right child */
struct Node { 
	int key; 
	struct Node *left, *right; 
}; 

/* function to create a new node of tree and 
return pointer */
struct Node* newNode(int key) 
{ 
	struct Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return temp; 
}; 

/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp) 
{ 
	if (!temp) 
		return; 
	inorder(temp->left); 
	cout << temp->key << " "; 
	inorder(temp->right); 
} 
void preorder(struct Node* temp) 
{ 
	if (!temp) 
		return; 
	  
	cout << temp->key << " "; 
    inorder(temp->left);
	inorder(temp->right); 
}
void postorder(struct Node* temp) 
{ 
	if (!temp) 
		return; 
	inorder(temp->left); 
    inorder(temp->right);
	cout << temp->key << " "; 
	 
}

/* function to delete the given deepest node 
(d_node) in binary tree */
void deletDeepest(struct Node* root, 
				struct Node* d_node) 
{ 
	queue<struct Node*> q; 
	q.push(root); 

	// Do level order traversal until last node 
	struct Node* temp; 
	while (!q.empty()) { 
		temp = q.front(); 
		q.pop(); 
		if (temp == d_node) { 
			temp = NULL; 
			delete (d_node); 
			return; 
		} 
		if (temp->right) { 
			if (temp->right == d_node) { 
				temp->right = NULL; 
				delete (d_node); 
				return; 
			} 
			else
				q.push(temp->right); 
		} 

		if (temp->left) { 
			if (temp->left == d_node) { 
				temp->left = NULL; 
				delete (d_node); 
				return; 
			} 
			else
				q.push(temp->left); 
		} 
	} 
} 

/* function to delete element in binary tree */
Node* deletion(struct Node* root, int key) 
{ 
	if (root == NULL) 
		return NULL; 

	if (root->left == NULL && root->right == NULL) { 
		if (root->key == key) 
			return NULL; 
		else
			return root; 
	} 

	queue<struct Node*> q; 
	q.push(root); 

	struct Node* temp; 
	struct Node* key_node = NULL; 

	// Do level order traversal to find deepest 
	// node(temp) and node to be deleted (key_node) 
	while (!q.empty()) { 
		temp = q.front(); 
		q.pop(); 

		if (temp->key == key) 
			key_node = temp; 

		if (temp->left) 
			q.push(temp->left); 

		if (temp->right) 
			q.push(temp->right); 
	} 

	if (key_node != NULL) { 
		int x = temp->key; 
		deletDeepest(root, temp); 
		key_node->key = x; 
	} 
	return root; 
} 
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->key = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
/*void insert(struct Node* r){
    int n,p;
    cout << "enter value to insert";
    cin >> n;
    cout << "Add at left-1,Add at right-0";
    cin >> p;
    if(p==1){
        r->left=newNode(n);
    }else{
        r->right=newNode(n);
    }
}*/
Node* InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
 
    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}
// Driver code 
int main() 
{ int c,key,val,n;
  cout << "Enter root value";
  cin >> n;
  struct Node* root = newNode(n);
	while(1){
        cout << "\n\n1.Insert 2.Delete 3.Inorder 4.Preorder 5.Postorder 6.Exit\n\n";
        cout << "Enter choice";
        cin  >> c;
        switch(c){
            case 1:{cout << "enter value to insert";
                    cin >> val;
              root=InsertNode(root,val); break;}
            case 2:{ cout << "enter value to be deleted";
                     cin >> key;
                root=deletion(root,key); break;}
            case 3: inorder(root); break;
            case 4: preorder(root); break;
            case 5: postorder(root); break;
            case 6: exit(0); break;
            default: cout << "invalid choice";
        }
    } 
	

	return 0; 
} 
 
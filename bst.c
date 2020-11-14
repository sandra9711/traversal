#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root;
int main(){
    while(1){
        int ch,d,x;
        printf("\n \t 1. Insert in Binary Tree  ");
		printf("\n\t 2. Delete from Binary Tree ");
		printf("\n\t 3. Inorder traversal of Binary tree");
		printf("\n\t 4. Postorder traversal of Binary tree");
		printf("\n\t 5. Preorder traversal of Binary tree");
		
		printf("\n\t 6. Exit ");
        printf("Enter choice\t");
        scanf("%d", &ch);
        switch (ch) { 
            case 1:{
                printf("enter value\t");
                scanf("%d", &d);
                insert(d);
                break;
            }
            case 2:{
                inorder(root);
                break;
            }
            case 3:{
                preorder(root);
                break;
            }
            case 4:{
                postorder(root);
                break;
            }
            case 5:{
                printf("\n	Enter data to delete : ");
				scanf("%d",&x);
				delete(root,x,NULL);
				break;
            }
            case 6:{
                exit(0);
            }
        }
             
        
    }
}
void insert(int x)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->left=NULL;
	p->right=NULL;
	p->data=x;

	if(root==NULL)
	{
		root=p;
	}
	else 
	{
		struct node* q=root;
		struct node* parent;

		while(q!=NULL)
		{
			parent=q;
			if(x<q->data)
			{
				q=q->left;
			}
			else
			{
				q=q->right;
			}
		}
		if(x<parent->data)
		{
			parent->left=p;
		}
		else
		{
			parent->right=p;
		}
	}
}

void preorder(struct node * p)
{
	if(p!=NULL)
	{
		printf(" \t %d\n",p->data);
		preorder(p->left);
		preorder(p->right);
	}
	else
		return;
}
void postorder(struct node * p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf(" \t %d\n",p->data);
	}
	else
		return;
}
void inorder(struct node * p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("\t %d\n",p->data);
		inorder(p->right);
	}
	else
		return;

}

void delete(struct node* curr,int x,struct node* parent)
{
	struct node* p=curr;
	struct node* q;
	//struct node* parent=NULL;
	int y;

	if(root==NULL)
	{
		printf("BST is empty..");
	}
	else if(p==NULL)
	{
		return;
	}
	else if(!search(x))
	{
		printf("BST do not contain %d",x);
	}
	else
	{
		while(p->data!=x && p!=NULL)
		{
			parent=p;
			if(x<p->data)
			{
				p=p->left;
			}
			else
			{
				p=p->right;
			}

		}

		if(p->left==NULL && p->right==NULL)//leaf node ie. no child nodes
		{
			if(p==root)
			{
				root=NULL;
			}
			else
			{
				if(parent->left==p)
				{
					parent->left=NULL;
				}
				else
				{
					parent->right=NULL;
				}
			}
			free(p);
			//printf("	%d is deleted from BST",x);
		}
		else if(p->left==NULL)//only right child
		{
			if(p!=root)
			{
				if(parent->left==p)
				{
					parent->left=p->right;
				}
				else
				{
					parent->right=p->right;
				}
				p->right=NULL;
			}
			else
			{
				root=p->right;
			}
			free(p);
			//printf("	%d is deleted from BST",x);
		}
		else if(p->right==NULL)//only left child
		{
			//q=p;
			//p=p->left;
			if(p!=root)
			{
				if(parent->left==p)
				{
					parent->left=p->left;
				}
				else
				{
					parent->right=p->left;
				}
				p->left=NULL;
			}
			else
			{
				root=p->left;
			}
			free(p);
			//printf("	%d is deleted from BST",x);
		}
		else//both childs present
		{			
			y=find_min(p->right);
			p->data=y;
			delete(p->right,y,p);
		}
			
	}
}
 int find_min(struct node* p)
{
	
	while(p!=NULL && p->left!=NULL)
	{
		p=p->left;
	}
	return p->data;
}

int search(int x)
{
	struct node* p=root;
	int flag=0;
	while(p!=NULL)
	{
		if(p->data==x)
		{
			flag=1;
			break;
		}
		else if(x<p->data)
		{
			p=p->left;
		}
		else
		{
			p=p->right;
		}
	}
	if(flag==0)
	{
		return 0;
	}
	return 1;
}
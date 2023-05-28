#include<stdio.h>
#include<stdlib.h>

typedef struct Node
    {
        int data ;
        struct Node * left ;
        struct Node * right ;
    }   node ;

    node * root = NULL ;

    void inorder(node * root )
        {
            if (root == NULL)
            return ;
            inorder(root->left);
            printf("%d ", root->data);
            inorder(root->right);
        }

    void preorder(node * root)
        {
            if(root==NULL)
            return ;
            printf("%d " , root->data);
            preorder(root->left);
            preorder(root->right);
        }
    void postorder(node * root)
        {
            if (root == NULL)
            return;

            postorder(root->left);
            postorder(root->right);
            printf("%d ", root->data);
        }
        
        void display(node * root)
        {
            printf("Inorder");
            inorder(root);
            printf("\n");

            printf("Preorder");
            preorder(root);
            printf("\n");

            printf("Postorder");
            postorder(root);
            printf("\n \n \n");
        }

        node * createNode(int data)
            {
                node * new = (node*)malloc(sizeof(node));
                new->data = data;
                new->left = NULL;
                new->right =NULL;
                return new;
            }
        
        node * createTreeNode( node * root , int data )
            {
                if (root == NULL)
                {
                    return createNode(data);
                }
                else
                {
                    if (data <= root->data)
                    {
                        root->left = createTreeNode(root->left, data);
                    }
                    else
                    {
                        root->right = createTreeNode(root->right, data);
                    }
                }
            }
        
        node * creatingTree(node * root)
            {
                root = createTreeNode( root, 8 );
                root= createTreeNode(root , 3 );
                root = createTreeNode(root , 10 );
                display(root);
                return root; 
            }
        
        
        node * insert(node* root , int data)
            {
                if(root ==NULL)
                {
                    return createNode(data);
                }

                else 
                {if (data<= root->data)
                    {
                        root->left = insert(root->left , data);
                    }
                else  
                    {
                        root->right = insert(root->right , data);
                    }
                    
                }
                //display(root);
                return root;
            }
        
        node * delete(node * root , int target)
            {
                if(root == NULL)
                    {
                        return root ;
                    }
                if (target < root->data)
                    {
                        root->left = delete(root->left, target);

                    }
                else if (target > root->data)
                    {
                        root->right = delete(root->right , target);
                    }
                else 
                    {
                        if (root->left == NULL)
                        {
                            node* temp = root->right;
                            free(root);
                            return temp;
                        }
                        else if (root->right == NULL)
                        {
                            node * temp = root->left;
                            free(root);
                            return temp;
                        }
                        

                    }
                    return root;
            }










int main()
{   
    root  = creatingTree(root);
    root = insert(1);
    root = insert(6);
    root = insert(14);
    root = insert(4);
    root = insert(7);
    root = delete(3);

    
    return 0;
}
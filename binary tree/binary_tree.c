#include <stdio.h>
#include <stdlib.h>
#define right ptr_to_right_node
#define left ptr_to_left_node

typedef struct _NODE
{
    int number;
    struct _NODE *right;
    struct _NODE *left;
} Node;

Node * new_node(int val){
    Node* data = (Node *) malloc(sizeof(Node));
    data->number = val;
    data->right = NULL;
    data->left = NULL;
}

Node* buildTree(int* Inorder, int* Preorder, int inorder_start, int inorder_end)
{
    Node* tree;
    int temp;

    for(temp=inorder_start; temp <=inorder_end; ++temp){
        if(Inorder[temp] == *Preorder) break;
    }
    if(inorder_start <= inorder_end){    
        tree = (Node *) malloc(sizeof(Node));
        tree->number = *Preorder;
        tree->left  = NULL;
        tree->right = NULL;
        // tree = new_node(*Preorder);

        if(inorder_start < inorder_end){
            tree->left  = buildTree(Inorder, Preorder+1, inorder_start, temp-1);
            tree->right = buildTree(Inorder, Preorder+1 + temp - inorder_start, temp+1, inorder_end);
        }
    }
    else{
        tree = NULL;
    }
    return tree;
}
void showPostorder(Node* root)
{
    if(root){
        showPostorder(root->left );
        printf("%d ", root->number);
        showPostorder(root->right);
    }
}

void freeTree(Node *root)
{
    if(root){
        freeTree(root->left );
        freeTree(root->right);
        free(root);
    }
}


    // {4 8 2 5 1 6 3 7} 
    // {8 4 5 2 6 7 3 1} 
    // 1 2 4 8 5 3 6 7
    //  {1 2 4 8 9 5 3 6 7} 
    //  {8 9 4 5 2 6 7 3 1}; 
    // 8 4 9 2 5 1 6 3 7

int n;
int main(void)
{
    int id = 1;
    while( ~scanf( "%d", &n ) )
    {
        int inorder[100], preorder[100];
        for( int i = 0; i < n; i++ )
            scanf( "%d", &inorder[i] );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &preorder[i] );
        Node *root = buildTree( inorder, preorder, 0, n-1 );
        printf( "testcase%d: ", id++ );
        showPostorder( root );
        printf( "\n" );
        freeTree( root );
    }
    return 0;
}
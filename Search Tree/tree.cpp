#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef left 
#define left left_child
#define right right_child
#endif

typedef struct _NODE {
    int level;
    struct _NODE *left_child, *right_child;
} Node;

void build_tree( Node ** now, int *arr, int l, int r){
    int mid = l + (r-l)/2;
    if(l<=r){
        *now = (Node*) malloc(sizeof(Node));
        (*now)->level = arr[mid];
        (*now)->left_child = (*now)->right_child = NULL;
        build_tree(&(*now)->left_child, arr, l, mid-1);
        build_tree(&(*now)->right_child, arr, mid+1, r);
    }
}

int query_heatstroke(Node* now, int x){
    if(now){
        if(now->level == x) return 1;
        if(now->level < x) return query_heatstroke(now->right_child, x);
        return query_heatstroke(now->left_child, x);
    }
    return 0;
}

void eat_rat(Node **root, int x){
    if(((*root)->level) > x) eat_rat(&(*root)->left_child, x);
    else if(((*root)->level) < x) eat_rat(&(*root)->right_child, x);
    else{
        if(!((*root)->left_child)){
            Node* temp=*root;
            *root = (*root)->right_child;
            free(temp);
            return;
        }
        else if(!((*root)->right_child)){
            Node* temp=*root;
            *root = (*root)->left_child;
            free(temp);
            return;
        }
        Node* temp = (*root)->right_child;
        while(temp->left_child) temp = temp->left_child;
        (*root)->level = temp->level;
        eat_rat(&(*root)->right_child, temp->level);
    }
    return;
}

void buy_rat(Node** root, int x){
    if(!(*root)){
        *root = (Node*) malloc (sizeof(Node));
        (*root)->level = x;
        (*root)->left_child = (*root)->right_child = NULL;
        return;
    }
    if((*root)->level < x) buy_rat(&(*root)->right_child, x);
    else buy_rat(&(*root)->left_child, x);
    return;
}

void burnTree(Node* root){
    if(root){
        burnTree(root->left);
        burnTree(root->right);
        free(root);
    }
}

int main(){
    int *arrr = (int*) malloc(1000005 * sizeof(int));
    int n, q, x;
    Node* curr;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arrr[i]);
    }
    build_tree(&curr, arrr, 1, n);
    scanf("%d", &q);
    char command[20];
    while(q--){
        scanf("%s", command);
        scanf("%d", &x);
        if(!strcmp(command, "heatstroke")){
            if(query_heatstroke(curr, x)) {
                eat_rat(&curr, x);
                printf("We might as well eat it.\n");
            }
            else printf("No dinner tonight.\n");
        }
        else {
            buy_rat((&curr), x);
        }
    }
    burnTree(curr);
    free(arrr);
}
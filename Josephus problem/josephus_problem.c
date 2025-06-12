#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int number;
    struct _Node* next;
}Node;
Node *createList(int);
void freeList(Node*);
int solveJosephus(Node **, int);
Node * createList(int n){
    Node* p = NULL;
    for (int i=1; i<=n; i++){
        Node* data = (Node*) malloc(sizeof(Node));
        data->number = i;
        data->next = data;
        if(p != NULL){
            data->next = p->next;
            p->next = data;
        }
        p = data;
    }
    p = p->next;
    return p;
}
void freeList(Node* head){
    Node* hp = head;
    while(hp->next != hp){
        Node* np = hp->next;
        hp->next = np->next;
        free(np);
    }
    free(hp);
}

int solveJosephus(Node **head, int step){
    static int num=0, tnum;
    int temp;
    Node* tm = *head;
    if(!num){
        while(tm->next != *head){
            num++;
            tm = tm->next;
        }
        num++;
        tnum = num;
    }
    if(num== 1) return 1;
    else{
        num--;
        temp = (solveJosephus(head, step) + (step-1))%(num+1) +1;
        num++;
        if(num == tnum) num = 0;
        return temp;
    }
}


// #endif
int main()
{
    int n, k;
    while( scanf("%d%d", &n, &k)!=EOF )
    {
        Node *head;
        head = createList(n);
        printf( "%d\n", solveJosephus(&head, k) );
        freeList(head);
    }
    return 0;
}
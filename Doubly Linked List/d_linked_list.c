#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_{
    int num;
    struct node_* next;
    struct node_* prev;
}Node;

void show(Node**);
Node* move(Node**, int);
void erase(Node**, int);
void insert(Node**, int, int);

int main(){
    char buf[100];
    int x, n, val1, val2;
    scanf("%d%d", &x, &n);
    Node* head = (Node*) malloc (sizeof(Node));
    Node* now;
    head->num = x;
    head->next = head->prev = head;
    now = head;
    while(n--){
        scanf("%s", buf);
        if(!strcmp(buf, "insert")){
            scanf("%d %d", &val1, &val2);
            insert(&now, val1, val2);
        }
        else if(!strcmp(buf, "erase")){
            scanf("%d", &val1);
            erase(&now, val1);
        }
        else if(!strcmp(buf, "move")){
            scanf("%d", &val1);
            now = move(&now, val1);
        }
        else if(!strcmp(buf, "show")){
            show(&now);
        }
    }
}

void insert(Node** curr, int val, int n){
    Node* now = *curr;
    while(n--){
        Node* data = (Node*) malloc(sizeof(Node));
        data->num = val;
        data->prev = now;
        data->next = now->next;
        if(now->next->prev == now && now->next!=now)
            now->next->prev = data;
        now->next = data;
        if(now->prev == now)
            now->prev = data;
    }
}

void erase(Node** curr, int num){
    Node* now = *curr;
    while(num--){
        Node* temp = now->next;
        now->next = temp->next;
        if(temp->next == now)
            now->prev = now;
        if(temp->next != now)
            temp->next->prev = now;
        free(temp);
    }
}

void show(Node** curr){
    Node* now = *curr;
    // printf("%d_%d_%d", now->prev->num, now->num, now->next->num);
    printf("%d", now->num);
    if(now->next != *curr)
        printf(" ");
    else
        printf("\n");
    while(now->next!= *curr){
        // printf("asdafsasf\n");
        now = now->next;
        printf("%d", now->num);
        // printf("%d_%d_%d", now->prev->num, now->num, now->next->num);
        if(now->next != *curr)
            printf(" ");
        else
            printf("\n");

    }
}

Node* move(Node** curr, int x){
    Node* now = *curr;
    int total =1;
    while(now->next != *curr){
        now = now->next;
        total++;
    }
    now = now->next;
    if(x>0){
        x %= total;
        while(x--){
            now = now->next;
        }
    }
    else{
        while(x++){
            now = now->prev;
        }
    }
    return now;
}
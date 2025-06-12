// #include "function.h"
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define ll long long int
#define next ptr_to_next_node
#define prev ptr_to_prev_node
#define ch character

typedef struct _NODE
{
	char character;
	struct _NODE *ptr_to_next_node;
	struct _NODE *ptr_to_prev_node;
} Node;



int n, num;
char buf[10], intype;
Node *cursor;
Node *head, *tail;

void show()
{
	if(head == NULL){
		printf("\n");
		return;
	}
	Node *now = head->next;
	while(now != head)
	{
		printf("%c_%c_%c ", now->prev->ch, now->ch,now->next->ch);
		now = now->next;
	}
	printf(" __%c_%c_%c\n", cursor->prev->character, cursor->character, cursor->next->character);
}


#ifndef prev
#define ll long long int
#define next ptr_to_next_node
#define prev ptr_to_prev_node
#define ch character
#endif

void insert(Node **cur, char c)
{
    tail = head->prev;
    Node* data = (Node*) malloc(sizeof(Node));
    Node* now = *cur;
    data->character = c;
    data->prev = now;
    data->next = now->next;
    if(now->next != now && now->next->prev == now)
        now->next->prev = data;
    if(now->prev == now)
        now->prev = data;
    now->next = data;
    tail = head->prev;
    *cur = now;
}

void deletion(Node **cur)
{
    Node* now = *cur;
    tail = head->prev;
    if(now != tail ){
        Node* temp = now->next;
        now->next = temp->next;
        temp->next->prev = now;
        free(temp);
    }
    tail = head->prev;
    *cur = now;
}

void backspace(Node **cur)
{
    Node* now = *cur;
    tail = head->prev;  
    if(now != head){
        Node* temp = now;
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        if(now == tail)
            tail = temp->prev;
        // else now = temp->next;
        *cur = now->prev;
        free(temp);
    }
}

void go_left(Node **cur, int t)
{
    Node* now = *cur;
    while(t--){
        now = now->prev;
        // if(now == head)
        //     now = now->prev;
    }
    *cur = now;
}

void go_right(Node **cur, int t)
{
    Node* now = *cur;
    while(t--){
        now = now->next;
        // if(now == tail)
        //     now = head;
    }
    *cur = now;
}

void go_home(Node **cur)
{
    tail = head->prev;
    *cur = head;
}

void go_end(Node **cur)
{
    tail = head->prev;
    *cur = tail;
}
int main()
{
	scanf("%d",&n);
	head = (Node*)malloc(sizeof(Node));
	head->next = head->prev = head;
	cursor = tail = head;
	while(n--)
	{       
		scanf("%s",buf);
		if(!strcmp(buf,"insert"))
		{
			getchar();
			scanf("%c",&intype);
			insert(&cursor, intype); 
		}
		else if(!strcmp(buf,"deletion"))
		{
			deletion(&cursor); 
		}
		else if(!strcmp(buf,"backspace"))
		{
			backspace(&cursor); 
		}
		else if(!strcmp(buf,"go_left"))
		{
            scanf("%d", &num);
			go_left(&cursor, num); 
		}
        else if(!strcmp(buf,"go_right"))
		{
            scanf("%d", &num);
			go_right(&cursor, num); 
		}
        else if(!strcmp(buf,"go_home"))
		{
			go_home(&cursor); 
		}
        else if(!strcmp(buf,"go_end"))
		{
			go_end(&cursor); 
		}
		else if(!strcmp(buf,"show"))
		{
			show();
		}
	}
	return 0;
}
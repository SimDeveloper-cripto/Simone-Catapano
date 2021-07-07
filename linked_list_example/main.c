#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} list;


void push_head(list** head, int val){
    list* new_node = (list*)malloc(sizeof(list));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void push_tail(list** head, int val){
    if(head == NULL) push_head(head, val);

    list* new_node = *head;

    while(new_node->next != NULL){
        new_node = new_node->next;
    }
    push_head(&new_node->next, val);
}

void pop_head(list** head){
    list* temp = *head;
    *head =  (*head)->next;
    free(temp);
}

void pop_tail(list* head){
    if(head == NULL) return;

    list *toDelete, *secondlastnode;
    toDelete = head;
    secondlastnode = head;

    while(toDelete->next != NULL){
        secondlastnode = toDelete;
        toDelete = secondlastnode->next;
    }
    if(toDelete == head) head = NULL;
    else secondlastnode->next = NULL;

    free(toDelete);
}

void rev(list** head, int val){
    list* temp = *head;
    list* prev = NULL;

    if(temp != NULL && temp->val == val){
        *head = temp->next;
        free(temp);
    } else {
        while(temp != NULL && temp->val != val){
            prev = temp;
            temp = temp->next;
        } 
        if(temp == NULL) return;

        prev->next = temp->next;
        free(temp);
    }
}

void stampa(list* head){
    if(head == NULL){
        printf(" NULL\n\n");
        return;
    } else {
        printf("[ %d ] --> ", head->val);
        stampa(head->next);
    }
}

int main(int argc, char* argv[]){
    list* head = NULL;

    push_head(&head, 20);
    push_head(&head, 30);
    push_head(&head, 40);
    push_head(&head, 50);
    push_head(&head, 60);
    push_head(&head, 70);
    push_head(&head, 80);
    stampa(head);

    push_tail(&head, 100);
    stampa(head);

    pop_head(&head);
    stampa(head);

    pop_tail(head);
    stampa(head);

    rev(&head, 40);
    stampa(head);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define DIM 20

typedef struct code_node {
    char code;
    struct code_node *next;
} list;

list *l = NULL;

void push_head(list **head, char code);
char cerca_in_lista(list *head, char find);
void find_code(char input[]);
// void print_list(list *head);
void init();

int main(int argc, char* argv[]){
    int totale_gruppi = 0, i, j = 0;
    char input[DIM];
    init();

    fflush(stdin);
    printf("Quanti gruppi da quattro caratteri ha la tua stringa binaria?: ");
    scanf("%d", &totale_gruppi);

    printf("Totale gruppi: %d\n", totale_gruppi);
    while(i < totale_gruppi){ 
        do {
            fflush(stdin);
            printf("Digitare blocco n.%d --> ", i + 1);
            scanf("%s", input);
        } while(strlen(input) <= 0 || strlen(input) > 4);
        
        find_code(input);
        ++i;
    }
    // print_list(l);
    return 0;
}

void push_head(list **head, char code){
    list *new_node = (list*) malloc(sizeof(list));
    new_node->code = code;
    new_node->next = *head;
    *head = new_node;
}

/*
    void print_list(list *head){
        if(head != NULL){
            printf("[ %c ] --> ", head->code);
            print_list(head->next);
        } else {
            printf("NULL \n");
        }
    }
*/

void init(){
    push_head(&l, '1');
    push_head(&l, '2');
    push_head(&l, '3');
    push_head(&l, '4');
    push_head(&l, '5');
    push_head(&l, '6');
    push_head(&l, '7');
    push_head(&l, '8');
    push_head(&l, '9');
    push_head(&l, 'A');
    push_head(&l, 'B');
    push_head(&l, 'C');
    push_head(&l, 'D');
    push_head(&l, 'E');
    push_head(&l, 'F');
}

char cerca_in_lista(list *head, char find){
    while(head != NULL){
        if(head->code == find) return head->code;
        head = head->next;
    }
}

void find_code(char input[]){
    char codice;
    if(strcmp(input, "0001") == 0){
        codice = cerca_in_lista(l, '1');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "0010") == 0){
        codice = cerca_in_lista(l, '2');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "0011") == 0){
        codice = cerca_in_lista(l, '3');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "0100") == 0){
        codice = cerca_in_lista(l, '4');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "0101") == 0){
        codice = cerca_in_lista(l, '5');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "0110") == 0){
        codice = cerca_in_lista(l, '6');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "0111") == 0){
        codice = cerca_in_lista(l, '7');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "1000") == 0){
        codice = cerca_in_lista(l, '8');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "1001") == 0){
        codice = cerca_in_lista(l, '9');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "1010") == 0){
        codice = cerca_in_lista(l, 'A');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "1011") == 0){
        codice = cerca_in_lista(l, 'B');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "1100") == 0){
        codice = cerca_in_lista(l, 'C');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "1101") == 0){
        codice = cerca_in_lista(l, 'D');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "1110") == 0){
        codice = cerca_in_lista(l, 'E');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
    if(strcmp(input, "1111") == 0){
        codice = cerca_in_lista(l, 'F');
        printf("       ---> [%c]", codice);
        printf("\n");
    }
}
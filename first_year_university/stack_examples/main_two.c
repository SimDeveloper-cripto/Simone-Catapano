#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// DICHIARAZIONE DELLA STRUTTURA
struct nodo_stack{
	int info;
	struct nodo_stack *link;
};
typedef struct nodo_stack tnode;
typedef tnode *type_stack;

type_stack create(type_stack root){
	type_stack head = root;
	head = NULL;
	return head;
}

// PROCEDURA DI PUSH
type_stack push(type_stack head,int data){
	type_stack newnode;
	
	// allocazione di spazio per il nuovo nodo
	newnode = (tnode*)malloc(sizeof(tnode)); 
	
	// aggiornamento dei campi info e link
	newnode->info = data;
	newnode->link = head;
	
	// dichiarazione della nuova "testa" dello stack
	head = newnode;
	
	return head;
}

// PROCEDURA DI STAMPA
void stampa(type_stack head){
	type_stack curr = head;
	int data;
	
	while(curr != NULL){
		printf("%d\t", curr->info);
		curr = curr->link;
		printf("\n");
	}
} 

int main(int argc, char *argv[]) {
	type_stack stack;
	int n = 0, i, num = 0;
	
	// creazione dello stack vuoto
	create(stack); 
	
	// otteniamo in input il totale di elementi da inserire nello stack
	printf("Quanti numeri vuoi inserire?: ");
	scanf("%d", &n);
	
	// procedimento per inserire nello stack i vari elementi
	for(i = 0; i < n; i++){
		printf("Inserisci un numero: ");
		scanf("%d", &num);
		stack = push(stack,num);
	}
	
	printf("\nStack creato:\n");
	// procedimento di stampa dello stack creato
	stampa(stack);
	
	getch();
	return 0;
}

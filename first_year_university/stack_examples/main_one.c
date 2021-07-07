#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo_stack {
	int info;
	struct nodo_stack* link;
};

struct nodo_stack* nuovo_nodo(int data){ // la funzione si chiama "nuovo_nodo"
	struct nodo_stack* nodo = (struct nodo_stack*)malloc(sizeof(struct nodo_stack)); // ALLOCAZIONE SPAZIO PER UN NUOVO NODO
	// CREAZIONE DEL NUOVO NODO
    nodo->info = data;
    nodo->link = NULL;
    return nodo;	
}

int isEmpty(struct nodo_stack* root){ // root punta al nodo stack
	return !root;
}

void push(struct nodo_stack** root, int data) {
    struct nodo_stack* nuovo = nuovo_nodo(data); // creiamo il nuovo nodo
    // pushiamo
    nuovo->link = *root;
    *root = nuovo; // assegnamo il valore di testa a nuovo.
    printf("%d pushed to stack\n", data);
}

int pop(struct nodo_stack** root){
	if(isEmpty(*root))
		return INT_MIN;
	// cancellazione
	struct nodo_stack* temp = *root; 
	*root = (*root)->link; // il penultimo nodo dello stack diventa testa
    int popped = temp->info;
    free(temp); // deallochiamo spazio occupato dalla precedente testa
	printf("\n%d has been popped from stack", popped);
    return popped; // ritorniamo il valore prelevato dallo stack
}

void stampa(struct nodo_stack* root){
	struct nodo_stack* first = root;
	while(first != NULL){
		printf("\n%d", first->info); // accediamo al campo di un puntatore.
		first = first->link;
	}
}


int main(int argc, char* argv[]){
	struct nodo_stack* lista = NULL; // lista nulla 

	push(&lista, 20);
	push(&lista, 40);
	stampa(lista);
	// printf("%d", isEmpty(lista));
	pop(&lista);
	printf("\n");
	stampa(lista);
	pop(&lista);
	printf("\n");
	stampa(lista);
	printf("\n\n%d", isEmpty(lista));
	
	getch();
	return 0;
}

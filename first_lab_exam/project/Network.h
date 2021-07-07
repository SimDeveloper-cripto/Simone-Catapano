#pragma once
#ifndef _NETWORK_H 
#define _NETWORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h> 
#include <stdbool.h>

// Struttura rappresentante i post.
struct Post
{
	char text[256];
	//punteggio che rappresenta il numero di volte in cui il post è stato visualizzato
	int points;
};

// Lista dei post.
typedef struct nodo_post
{
	struct Post l_post;
	struct nodo_post *l_next_post;
}Lista_Post;

// Lista degli account. 
typedef struct nodo_account
{
	struct Account* l_account;
	struct nodo_account* l_next_account;
}Lista_Account;

// Struttura rappresentante gli account.
struct Account
{
	char s_user_name[16];
	char s_passwd[16];
	Lista_Account* s_account_seguiti;
	Lista_Post* s_post_list;
	unsigned short int s_tot_post;
};

extern struct Account* null_account; // Struttura rappresentante l'account nullo (viene ritornato quando non viene trovato un account).
extern Lista_Account* account_list; // Dichiarazione lista globale degli account.

/*			--- Prototipi delle funzioni principali --- 			*/

void MENU(); // Starting point dell'applicazione!
void SIGN_UP(); // Procedure di registrazione dell'utente.
void LOGIN(); // Procedure di accesso all'account da parte dell'utente registrato.
void AreaPrivata(struct Account* p_myaccount); // Accediamo all'area privata relativa all'account.


/*			--- Prototipi delle funzioni --- 			*/

struct Account* Create_Account(char p_name[], char p_passwd[]); // Funzione per la creazione di un account.
struct Post Create_Post(char p_text[]); // Funzione per la creazione di un post.
struct Account* search_by_name(char p_name[],Lista_Account* p_account_list); // Funzione di ricerca all'interno della lista di account.
bool verify_existing_username(char p_username[], Lista_Account* p_account_list); // Helper function che verifica il nome non sia gia'  utilizzato.
bool verify_valid_credentials(char p_username[], char p_passwd[], Lista_Account* p_account_list); // Verifichiamo le credenziali dell'account per i login.
void remove_account(Lista_Account** account_list,struct Account* p_account); // Funzione di Rimozione di un account dalla lista account.
void Print_list(Lista_Account* p_account_list); // Funzione implementata per stampare la lista degli account.
void Print_post_list(Lista_Post* p_post_list); // Funzione implementata per la stampa dei post.
void Push_Account(Lista_Account** p_account_list,struct Account* p_account); // Funzione per push alla testa un account nella lista degli account.
void Push_Post(Lista_Post** p_post_list, struct Post p_post); // Funzione che aggiunge un post alla lista post dell'account.
void Pop_Post(Lista_Post** p_post_list); // Rimozione di un post alla tail della lista dei post.
void Unfollow(Lista_Account** p_account_seguiti , struct Account* p_account); // Procedura di rimozione di un account dalla lista degli account seguiti.
void Follow(Lista_Account** p_account_seguiti , struct Account* p_account); // Funzione che permette ad un account di seguire un'altro account.
void Order_follow_list(Lista_Account* p_list); // Procedura di ordinamento alfabetico della lista degli account seguiti.

/*			--- Prototipi delle funzioni di appoggio --- 			*/

void clearscr(void); // Funzione per la pulizia dello schermo.
void concatena_stringa(char p_stringa1[],char p_stringa2[]); // Funzione per la concatenazione di due stringhe.
const char* to_lower_string(char string[]); // Funzione costum che rende ogni carattere della sctringa minuscolo.
void scrivi_post(struct Account* p_account, char text[]); // Funzione per la scrittura di un post (implementa Push_Post e Create_Post).

#endif 
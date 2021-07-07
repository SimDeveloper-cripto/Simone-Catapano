#include "Network.h"

struct Account* null_account = NULL; // Rappresenta l'account nullo  viene ritornato quando non viene trovato un account).
Lista_Account* account_list = NULL; // Inizializzo lista globale degli account.

/*
	Questa funzione permettere di pulire lo schermo.
	Cio' rende l'interfaccia utente molto piu' leggibile!
	Importante: bisogna riconoscere su quale sistema operativo viene eseguito il programma.
*/
void clearscr(void)
{
	// Se siamo su sistema operativo windows la funzione e' system("cls").
	#ifdef _WIN32 
	    system("cls");
	// Se siamo su sistema operativo che non sia windows la funzione e' system("clear").
	#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
	    system("clear");
	#else
	    #error "OS non supportato."
	#endif
}

/*
	Funzione di appoggio che permette la concatenazione di due stringhe.
	Questa funzione e' implementata per permettere di nominare come si deve il file di testo relativo al runtime dell'applicazione.
	L'utilizzo di tale funzione sarà presente nella funzione appena successiva.
*/
void concatena_stringa(char p_stringa1[], char p_stringa2[])
{
	size_t i;
	int len = strlen(p_stringa1); // ci salviamo la lunghezza della prima stringa.

	// la concatenazione della seconda stringa avra' inizio a partire dalla fine della prima stringa.
    for(i = 0; (p_stringa1[i+len] = p_stringa2[i]) != '\0'; i++) {
        p_stringa1[i+len] = p_stringa2[i];
    }
}

/*
	L'idea di questa procedura nasce dal voler salvare in un file di testo tutte le informazioni relative al runtime dell'applicazione.
	Il suo funzionamento e' davvero semplice!
*/
void Save(Lista_Account* p_account_list){
  	time_t t = time(NULL);
	FILE *fp;

	// creiamo il nostro file "DatiRuntine.txt" e lo salviamo nella cartella "Data" del nostro progetto.
	fp = fopen("Data/DatiRuntime.txt","w");

	/* 
		Nel file salviamo tutte le informazioni relative agli account presenti nella lista degli account. 
		Per farlo dobbiamo iterare per tutta la lista.
	*/
	while(p_account_list != NULL)
	{
		/* la funzione fprintf() serve per inserire nel file le informazioni di cui abbiamo bisogno. */
		/* 
			Nel file inseriremo le seguenti informazioni:
			--> username.
			--> password.
			-->	i suoi post.
			--> lista degli account seguiti.
		*/
		fprintf(fp, "# 				USER_NAME\n %s\n# 				PASSWORD\n %s\n# 				POST_LIST\n", p_account_list->l_account->s_user_name, p_account_list->l_account->s_passwd);
		// iteriamo per tutta la lista dei post per stampare i post.
		while(p_account_list->l_account->s_post_list != NULL)
		{
			fprintf(fp, "%s     points : %d\n", p_account_list->l_account->s_post_list->l_post.text,p_account_list->l_account->s_post_list->l_post.points); // inseriamo nel file le informazioni.
			p_account_list->l_account->s_post_list = p_account_list->l_account->s_post_list->l_next_post; // procediamo con il prossimo nodo della lista.
		}

		fprintf(fp, "# 				ACCOUNT_SEGUITI\n");
		// iteriamo per tutta la lista degli account seguiti per stamparli.
		while(p_account_list->l_account->s_account_seguiti != NULL)
		{
			fprintf(fp, "%s\n",p_account_list->l_account->s_account_seguiti->l_account->s_user_name); // inseriamo nel file le informazioni.
			p_account_list->l_account->s_account_seguiti = p_account_list->l_account->s_account_seguiti->l_next_account; // procediamo con il prossimo nodo della lista.
		}
		p_account_list = p_account_list->l_next_account;
	}

	// chiusura del file.
	fclose(fp);

	// Salviamoci le informazioni per rinominare il file con la relativa data ed orario di esecuzione.
	char str[18] = "Data/DatiRuntime-";
	char str_time[27];	
	strcpy(str_time,asctime(localtime(&t))); // otteniamo la data effettiva con anche giorno ed orario.
	// E' importante eliminare i ":" che la funzione inserisce nella stringa dato che il file non puo' essere rinominato con tale carattere!
	str_time[13] = '-'; 
	str_time[16] = '-';	
	concatena_stringa(str,str_time); // chiamata a sottoprogramma della procedura di concatenazione di due stringhe.
	str[strlen(str) - 1] = '\0'; // eliminiamo l'ultimo carattere della stringa, ovvero ENTER.
    concatena_stringa(str,".txt"); // chiamata a sottoprogramma della procedura di concatenazione di due stringhe.
	printf("I dati relaviti al runtime sono presenti in %s ",str);
	
	rename("Data/DatiRuntime.txt",str); // Per essere piu' specifici rinominiamo il file che creiamo alla fine dell'esecuzione.
}



/*
	Procedura per la conversione di una stringa i cui caratteri vengono resi minuscoli.
	La funzione serve per effettuare alcuni controlli relativi agli input.
	Tali controlli saranno presenti piu' avanti nel codice.
*/
const char* to_lower_string(char string[])
{
	char* lower = (char*) malloc(sizeof(char));
	// convertiamo ogni carattere della stringa in minuscolo per poter fare il controllo, per esempio, delle credenziali.
	for (size_t i = 0; i < strlen(string); ++i) {
        lower[i] = tolower((unsigned char)string[i]);
    }
    return lower; // alla fine ritorniamo la stringa i cui caratteri sono tutti minuscoli.
}

/*
	Procedura dedicata alla creazione di un account!
*/
struct Account* Create_Account(char p_name[], char p_passwd[])
{
	struct Account* new_account = (struct Account*) malloc(sizeof(struct Account)); // allocazione di spazio in memoria per l'account.
	// Salviamo i dati dell'account che vogliamo creare. Per farlo dobbiamo usare la funzione "strcpy()".
	strcpy(new_account->s_user_name, p_name);
	strcpy(new_account->s_passwd, p_passwd);
	new_account->s_tot_post = 0;
	new_account->s_post_list = NULL; // Inizializzo lista dei post di tale account.
	new_account->s_account_seguiti = NULL; // Inizializzo lista account seguiti relativa all'account.
	return new_account;
}

/*
	Funzione di ordinamento alfabetico della lista degli account.
	Come parametro otteniamo la lista degli account.
*/
void Order_list(Lista_Account* p_list)
{
	bool swapped; // variabile sfruttata come una flag.
	Lista_Account* ptr1;
	Lista_Account* lptr = NULL;

	// se la lista e' vuota semplicemente interrompiamo l'esecuzione della procedura.
	if (p_list == NULL)
		return;

	// L'ordinamento e' effettuato all'interno di un do-while che si ripetere finche' la flag swapped vale true.
	do
	{
		swapped = false;
		ptr1 = p_list; // ci salviamo l'informazione relativa alla lista per poi poter iterare.
		// finche' nella lista e' presente un nodo successivo: 
		while(ptr1->l_next_account != lptr)
		{	
			// effettuiamo l'ordinamento alfabetico. Confrontiamo carattere per carattere i codici ASCII.
			if (strcmp(ptr1->l_account->s_user_name, ptr1->l_next_account->l_account->s_user_name) > 0)
			{
				// effettuiamo l'ordinamento! Esso sfrutta sempre la funzione strcpy().
			    struct Account* temp = NULL;
			    temp = ptr1->l_account;
			    ptr1->l_account = ptr1->l_next_account->l_account;
			   	ptr1->l_next_account->l_account = temp;
				swapped = true;
			}
			ptr1 = ptr1->l_next_account; // andiamo avanti con l'account successivo.
		}
		lptr = ptr1;
	}
	while(swapped);
}

/*
	Procedura di stampa della lista degli account.
	Riceve come parametro la lista.
	--> Sfruttiamo un approccio ricorsivo!
*/
void Print_list(Lista_Account* p_account_list)
{
	// la lista va stampata finche' l'ultimo elemento ha come successivo = NULL.
	if(p_account_list != NULL){
		printf("\nUSERNAME : %s \t", p_account_list->l_account->s_user_name); // stampa degli username.
		Print_list(p_account_list->l_next_account); // andiamo avanti con l'account successivo.
	}
}

/* 
	Procedura di inserimento in testa nella lista degli account. 
	La funzione per poter lavorare necessita di ottenere come parametri la lista degli account e l'account effettivo da pushare.
*/
void Push_Account(Lista_Account** p_account_list, struct Account* p_account)
{
	// allochiamo spazio per il nuovo nodo da inserire nella lista.
	Lista_Account* new_account = NULL;
	new_account = (Lista_Account*) malloc(sizeof(Lista_Account));
	// salviamo l'account nella lista e aggiorniamo la testa.
	new_account->l_account = p_account;
	new_account->l_next_account = *p_account_list;	
	*p_account_list = new_account; // aggiornamento della testa. 
}

/* 
	Procedura di inserimento in testa nella lista dei post. 
	La funzione per poter lavorare necessita di ottenere come parametri la lista dei posti e il post effettivo.
*/
void Push_Post(Lista_Post** p_post_list, struct Post p_post)
{
	// allochiamo spazio per il nuovo nodo da inserire nella lista.
	Lista_Post* new_post = (Lista_Post*) malloc(sizeof(Lista_Post));
	// salviamo il post nella lista e aggiorniamo la testa.
	new_post->l_post = p_post;
	new_post->l_next_post = *p_post_list;	
	*p_post_list = new_post; // aggiornamento della testa. 
}

/*
	Procedura di rimozione di un post dalla lista dei post.
	La rimozione avviene all'ultimo elemento della lista poichÃ¨ dobbiamo mantenere memoria al massimo di 10 post i quali sono inseriti in testa.
	Come parametro definiamo un doppio puntatore alla List_Poist per permettere il cambiamento diretto del puntatore della testa invece di ritornarne una nuova.
	--> Sfruttiamo un approccio ricorsivo.																	
*/
void Pop_Post(Lista_Post** p_post_list){
	// puntatore1 = puntatore2 ----> puntatore1 contiene l'indirizzo del puntatore2.
	Lista_Post* temp = *p_post_list; // ci salviamo l'indirizzo della head.
	// Dobbiamo come sempre scorrere la lista finchÃ¨ non raggiungiamo l'ultimo nodo.
	if(temp != NULL){
		// Una volta raggiunto l'ultimo elemento: 
		if(temp->l_next_post == NULL){
			// Il penultimo elemento *p_post_list deve diventare l'ultimo, ovvero (*p_post_list)->l_next_post.
			*p_post_list = (*p_post_list)->l_next_post; 
			// eliminazione dell'ultimo nodo.
    		free(temp);
			return; // interrompiamo l'esecuzione della funzione.
		}
		Pop_Post(&temp->l_next_post); // chiamata ricorsiva
	} else {
		// Ovviamente se la lista e' vuota sin dall'inizio e' inutile continuare l'esecuzione della procedura.
		return;
	} 
}

/*
	Questa funzione permette di determinare se un account e' presente oppure no nella lista.
*/
struct Account* search_by_name(char p_name[], Lista_Account* p_account_list)
{
	// Scorriamo tutta la lista.
	while(p_account_list != NULL){ 
		// Per determinare se l'account e' stato trovato bisogna sfruttare la funzione "strcmp() relativi agli user_name degli account".
		if (strcmp(p_account_list->l_account->s_user_name, p_name) == 0)
		{
			return p_account_list->l_account; // ritorniamo l'account appena trovato.
		}
		p_account_list = p_account_list->l_next_account; // controlliamo il prossimo nodo della lista.
	}
	// Se l'account non e' presente ritorniamo un account nullo!
	return null_account;
}

/* 
	Helper function che verifica se lo user_name non sia giÃ  utilizzato.
	Funzione necessaria per l'algorimo di sign-up.
	--> Approccio ricorsivo.
*/
bool verify_existing_username(char p_username[], Lista_Account* p_account_list)
{
	// scorriamo gli elementi della lista fino all'ultimo [ ma non necessariamente! ].
	while(p_account_list != NULL){
		// La verifica di esistenza la effettuiamo con il controllo sullo user_name.
		if(strcmp(p_account_list->l_account->s_user_name, p_username) == 0)
		{
			// una volta trovato ritorniamo un riscontro positivo!.
			return true;
		}
		p_account_list = p_account_list->l_next_account; // procediamo con il nodo successivo.
	}
	// se la lista e' vuota semplicemente vuol dire che non l'abbiamo trovato a prescindere.
	return false;
}

/*
	Funzione che permette la registrazione di un nuovo utente nel social network!
*/
void SIGN_UP()
{	
	bool created = false; // flag necessaria al funzionamento dell'algoritmo.
	char user_name[16];	
	char passwd[16];
	// il ciclo si deve ripetere finche' l'account non viene creato.
	do
	{
		// pulizia del buffer di input.
		fflush(stdin);
		// chiediamo all'utente le credenziali di registrazione.
		printf("				-------- REGISTRAZIONE UTENTE -------- \n\n");
		printf("Inserisci il tuo user_name : [MAX 16 CARATTERI] :");
		scanf("%s", user_name);
		printf("Inserisci la tua password : [MAX 16 CARATTERI] :");
		scanf("%s", passwd);
		/* 
			L'account viene creato se le credenziali hanno una lunghezza accettabile e se ovviamente l'account da creare non esiste gia'.
			L'utente non puo' chiamarsi "nessuno", poiche' questo e' un nome sfruttato per terminare un algoritmo di ricerca che vedremo piu' avanti nel codice.
		*/
		if ((strlen(user_name) <= 16) && (strlen(passwd) <= 16))
		{
			// Se le condizioni sono rispettate creiamo l'account e usciamo dal ciclo do-while. In questo modo termina la registrazione.
			if (!verify_existing_username(user_name, account_list) && strcmp(to_lower_string(user_name),"nessuno") != 0)
			{
				created = true; // assegnamo la flag al valore true per terminare il ciclo.
				// Bisogno ricordare che la funzione Create_Account ritorna un account.
				Push_Account(&account_list, Create_Account(user_name, passwd)); // inseriamo l'account nella lista degli account!
			}
			else
			{
				// Pulizia interfaccia utente.
				printf("\nCREDENZIALI NON VALIDE! RIPROVA!\n");
				fflush(stdin); // pulizia del buffer di input.
				printf("//// PREMI INVIO PER REINSERIRE LE CREDENZIALI ////\n");
				getchar(); 
				clearscr();			
			}				
		}
		else
		{
			// Pulizia interfaccia utente.
			printf("\nLA LUNGHEZZA DI USER_NAME E PASSWORD DEVE ESSERE DI MAX 16 CARATTERI!\n");	
			fflush(stdin); // pulizia del buffer di input.
			printf("//// PREMI INVIO PER REINSERIRE LE CREDENZIALI ////\n");
			getchar();
			clearscr();
		}
	} while(!created);		

	Order_list(account_list);
	AreaPrivata(search_by_name(user_name, account_list)); // L'utente, una volta registrato, deve accedere alla sua area riservata!
}

/*
	La seguente funzione nasce per semplificare l'algoritmo implementato nella funzione di Login.
	Tale procedura permettere di verificare ritornando un valore booleano se l'account e' gia' presente nella lista.
*/
bool verify_valid_credentials(char p_username[], char p_passwd[], Lista_Account* p_account_list)
{
	/*
		Come sempre, per controllare dobbiamo iterare per tutta la lista.
		Controlliamo la password solo se valido l'username.
	*/
	while(p_account_list != NULL) // finche' nella lista e' presente ancora un nodo.
	{
		// Effettuiamo i dovuti controlli.
		if (strcmp(p_account_list->l_account->s_user_name, p_username) == 0)
		{
			if (strcmp(p_account_list->l_account->s_passwd, p_passwd) == 0)
			{
				return true; // ritorniamo il valore booleano true per dare un riscontro positivo.
			}		
		}
		p_account_list = p_account_list->l_next_account; // controlliamo il nodo successivo.
	}
	return false; // ritorniamo il valore booleano false per dare un riscontro negativo.
}

/*
	Funzione di Login.
*/
void LOGIN()
{
	char user_name[16];
	char passwd[16];
	bool logged = false; // variabile sfruttata come flag.
	// il ciclo si deve ripetere finche' l'account non ha effettuato l'accesso alla sua area riservata.
	do
	{
		clearscr();
		printf("				-------- Benvenuto nel LOGIN --------  \n");
		printf("Inserisci il tuo user_name : ");
		scanf("%s",user_name);
		printf("Inserisci la tua password : ");
		scanf("%s",passwd);
		// Verifichiamo che le credenziali inserite abbiano una lunghezza accettabile.
		if (strlen(user_name) <= 16 && strlen(passwd) <= 16)
		{
			// se le credenziali inserite sono corrette ed esistono nella lista.
			if (verify_valid_credentials(user_name, passwd, account_list)){
				// interrompiamo il ciclo impostando la flag al valore true.
				logged = true;
				// accediamo all'area privata.
				AreaPrivata(search_by_name(user_name, account_list));
			}
			else // se le credenziali non sono corrette.
			{
				clearscr();
				printf("CREDENZIALI INSERITE NON VALIDE\n");
				// se comunque lo user_name inserito e' corretto ed e' sbagliata la password: 
				if (search_by_name(user_name, account_list) != null_account)
				{
					bool login_return = false;
					/* 
						Implementiamo un altro ciclo guidato dalla flag login_return, la quale inizialmente vale false.
						Questo ciclo da' la possibilita' all'utente di cambiare password oppure di re-inserire le sue credenziali.
					*/
					do
					{
						clearscr();
						printf("				-------- CAMBIO PASSWORD --------  \n\n");
						printf("[1] Ho dimenticato la password\n[2] Reinserire le credenziali\nInserisci la tua scelta --> ");
						int input = 0;
						// Se l'input inserito non e' corretto forziamo la condizione di default del costrutto di selezione multipla.
						if (scanf("%d",&input) == 0)
						{
							fflush(stdin);
							input = 3;
						}

						switch(input)
						{
							// Se digitiamo 1 diamo all'utente la possibilita' di cambiare la password.
							case 1:
							{
								bool changed = false;
								do
								{
									fflush(stdin);	
									printf("CAMBIA LA TUA PASSWORD \n");
									printf("Inserisci la tua NUOVA password : [MAX 16 CARATTERI] :");
									scanf("%s",passwd);
									if (strlen(passwd) <= 16)
									{
										changed = true;
									}
									// La password relativa all'utente verra' sostituita con la funzione "strcpy()".					
								}while(!changed);
								fflush(stdin);
								strcpy(search_by_name(user_name, account_list)->s_passwd, passwd); 
								break;								
							}
							// Se digitiamo 2 ritorniamo al login interrompendo il ciclo piu' interno.
							case 2:
								login_return = true;
								break;
							default:
								printf("SCELTA NON VALIDA!\n");
								fflush(stdin);
								printf("PREMI INVIO PER RIPROVARE\n");
								getchar();
								break;
						}					
					}while(!login_return);
				} else {
					fflush(stdin); // pulizia buffer di input.
					printf("VUOI RIPETERE L'OPERAZIONE (y/n) \n");					
					printf("\nInserisci la tua scelta --> ");
					char c = tolower(getchar());
					switch(c)
					{
						case 'y':
							break;
						case 'n':
							return;
						default:
							fflush(stdin);
							printf("INSERISCI UN CARATTERE ACCETTABILE  ! \n");
							getchar();
							break;
					}
				} 
			}			
		}
		else
		{
			printf("\nLUNGHEZZA CREDENZIALI NON VALIDA\n");
			fflush(stdin); // pulizia buffer di input.
			printf("PREMI INVIO PER RIPROVARE\n");
			getchar();		
		}
	} while(!logged);
}

/*
	Procedura di rimozione di un account dalla lista.
	Tale procedura e' stata concepita per dare la possibilita' all'utente di eliminare il proprio account.
*/
void remove_account(Lista_Account** account_list, struct Account* p_account){
	// puntatore1 = puntatore2 ----> puntatore1 contiene l'indirizzo del puntatore2.
    Lista_Account* temp = *account_list; // temp contiene l'indirizzo di account_list.
    Lista_Account* prev = NULL;

    // Se l'account da eliminare e' presente in testa:
    if (temp != NULL && strcmp(temp->l_account->s_user_name, p_account->s_user_name) == 0){
        *account_list = temp->l_next_account; // ci salviamo il successivo per eliminare la testa.
		// liberiamo lo spazio occupato in memoria.
        free(temp->l_account);
		free(temp);
		// interrompiamo l'esecuzione della funzione.
        return;
    } else { 
		// Se l'account non e' presente in testa, bisogna cercare nel resto della lista.
		/*
			Una volta trovato l'account si collega bisogna collegare il link del precedente con il successivo del nodo da eliminare.
			Consideriamo anche il nodo precedente: 
		*/
        while (temp != NULL && strcmp(temp->l_account->s_user_name, p_account->s_user_name) != 0){
            prev = temp;
            temp = temp->l_next_account;
        }
        if (temp == NULL) // se il valore non e' presente, terminiamo l'esecuzione della procedura.
            return;

		// effettuiamo il collegamento del link del precedente con il successivo del nodo che dobbiamo eliminare.
        prev->l_next_account = temp->l_next_account; 
		// liberiamo lo spazio occupato in memoria.
		free(temp->l_account);
        free(temp);
    }
}

/*
	Procedure che permette la visualizzazione dei post.
	--> Approccio ricorsivo.
*/
void Print_post_list(Lista_Post* p_post_list)
{
	// finche' nella lista dei post e' presente un nodo:
	if(p_post_list != NULL){
		++p_post_list->l_post.points;	
		printf("[#] %s   punteggio : %d \n", p_post_list->l_post.text,p_post_list->l_post.points); // stampiamo il post tramite l'accesso al campo text del post.
		Print_post_list(p_post_list->l_next_post); // procediamo con il nodo successivo della lista. 
	}		
}

/*
	Questa funzione permette la visualizzazione del post piu' recente relativo all'account che l'utente decide di seguire (Follow).
	--> Approccio iterativo.
*/
void Visualize_recent_post(Lista_Account* p_account_seguiti)
{
	// Bisogna iterare per tutta la lista degli account seguiti.
	while(p_account_seguiti != NULL)
	{
		++p_account_seguiti->l_account->s_post_list->l_post.points;		
		// stampiamo il post più recente relativo agli account seguiti dall'utente.
		printf("[#] Post di %s :: %s    punteggio : %d \n", p_account_seguiti->l_account->s_user_name, p_account_seguiti->l_account->s_post_list,p_account_seguiti->l_account->s_post_list->l_post.points);
		p_account_seguiti = p_account_seguiti->l_next_account; // procediamo con il nodo successivo della lista. 
	}			
}

/*
	Procedura di gestione dell'area privata relativa agli account.
*/
void AreaPrivata(struct Account* p_myaccount){
	if (p_myaccount == NULL)
		return;

	struct Account* my_account = p_myaccount;
	bool exited = false; // flag booleana .
	int input = 0;
	// L'intero programma è guidato da un ciclo do-while finche' la flag exited vale false.
	do
	{	
		clearscr(); // pulizia schermo.
		printf("				-------- BENVENTO NELL'AREA RISERVATA -------- \n");
		printf("Tu sei l'utente: [ %s ] \n", p_myaccount->s_user_name);		
		printf("\nChe cosa vuoi fare?: \n\n[1] Delete Account\n[2] Ricerca un utente\n[3] logout\n[4] Scrivi Post\n[5] Visualizza account seguiti\n[6] Cambia Nickname\n[7] Cambia password");
		printf("\n \n");
		// stampiamo dalla lista dei post.
		printf("I tuoi post: \n");
		Print_post_list(my_account->s_post_list); // chiamata a sottoprogramma della procedura per stampare i post.
		printf("\n- - - - - - - - - - - - - -\nPost recenti degli account da te seguiti: \n");
		// relativamente per ogni account seguito dobbiamo stampare il post piu' recente.
		Visualize_recent_post(my_account->s_account_seguiti); 
				
		// Se l'input non e' corretto, liberiamo il buffer degli input.
		printf("\n - - - - - - - - - - - - - -\nInserisci la tua scelta --> ");
		if (scanf("%d",&input) == 0)
		{
			fflush(stdin); // liberiamo il buffer di input.
			input = 10; // forziamo la condizione di default del costrutto di selezione multipla.  
		}
		
		switch(input)
		{
			// Delete account.
			case 1:
				remove_account(&account_list, my_account); // chiamata a sottoprogramma per eliminare l'account.
				// Ritorniamo al Menu().
				exited = true;
				break;
			/* 
				Ricerca dell'utente.
				L'intero processo e' gestito da un ciclo while guidato dalla flag searching, la quale deve valere true.
			*/
			case 2:
			{
				bool searching = true;
				while(searching)
				{
					clearscr(); // pulire lo schermo.
					// visualizza la lista di tutti gli utenti
					printf("Lista degli utenti presenti nel social: \n");
					// ordina la lista in ordine alfabetico
					Order_list(account_list);
					Print_list(account_list); // chiamata a sottoprogramma della procedura di Print_List().
		
					printf("\n\nQuale utente vuoi cercare? (Scrivi 'nessuno' per tornare al profilo): \n");
					char nome_utente[16];
					printf("Inserisci la tua scelta --> "); 
					scanf("%16s",&nome_utente);

					// Se digitiamo "nessuno", ritorniamo all'inizio dell'area riservata.
					if (strcmp(to_lower_string(nome_utente),"nessuno") == 0)
					{
						searching = false;
					}
					/*
						Altrimenti, possiamo decidere se fare un Follow, Unfollow oppure di ritornare al proprio profilo.
					*/
					else 
					{
						struct Account* searched_account = search_by_name(nome_utente,account_list); // ci salviamo l'account che vogliamo cercare.
						// Se non esiste, mandare un feedback all'utente.
						if(searched_account == null_account)
						{
							printf("!! UTENTE NON PRESENTE !!");
						}
						else
						{
								clearscr(); // pulizia schermo.
								printf("USER NAME : %s \n", nome_utente);
								printf("[1] Follow\n[2] Unfollow\n[3] Torna al profilo\n\n");
								printf("Post di [ %s ]: \n\n", searched_account->s_user_name);
								Print_post_list(searched_account->s_post_list); // stampiamo i post dell'account cercato.
								
								printf("\nInserisci la tua scelta --> ");
								int _input = 0;
								// controllo dell' input.
								if (scanf("%d",&_input) == 0)
								{
									fflush(stdin); // liberiamo buffer di input.
								}
								switch(_input)
								{ 
									// Opzione di follow.
									case 1:
										// Ovviamente non possiamo seguire noi stessi!
										if (strcmp(my_account->s_user_name,nome_utente) == 0)
										{
											printf("NON PUOI SEGUIRE TE STESSO !\n");
										}
										else // Altrimenti...
										{
											// Assicuriamoci che l'account non e' gia' seguito da parte nostra.
											if (search_by_name(searched_account->s_user_name, my_account->s_account_seguiti) == null_account)
											{
												// Se non e' gia' seguito da parte nostra effettuiamo la chiamata a sottoprogramma della procedura di Follow().
												Follow(&my_account->s_account_seguiti,searched_account);
												printf("HAI SEGUITO %s !\n",searched_account->s_user_name);					
											}
											else
												printf("ACCOUNT GIA' SEGUITO\n");							
										}
										break;
									// Operazione Unfollow
									case 2:
										// Ovviamente non possiamo smettere di seguire noi stessi!
										if (strcmp(my_account->s_user_name, nome_utente) == 0)
										{
											printf("NON PUOI SEMTTERE DI SEGUIRE TE STESSO !\n");
										}
										else
										{	printf("HAI SMESSO DI SEGUIRE %s \n", nome_utente);
											Unfollow(&my_account->s_account_seguiti, searched_account);	// chiamata a sottoprogramma della procedura di Unfollow().														
										}										
										break;
									// Ritorna al profilo cambiando il valore della nostra flag "searching".
									case 3:
										searching = false;
										break;
									default:
										printf("SCELTA NON VALIDA\n");	
										break;
								}
								
								if (searching) // se stiamo ancora cercando...
								{
									printf("PREMI INVIO PER CONTINUARE...\n");
									fflush(stdin); // liberiamo il buffer di input.
									getchar();												
								}
			
						}				
					}
				}							
			}
			break;
			// Effettuiamo l'operazione di logout.
			case 3:
				// puliamo lo schermo e torniamo al menu().
				clearscr(); 
				exited = true;
				break;
			// Scrivi Post
			case 4:
				printf("A cosa stai pensando? [ MAX 256 CARATTERI ]-> ");
				char text[256];
				// liberiamo il buffer di input.
			    fflush(stdin);	
				// permette di leggere in input una stringa con spazi, senza l'utilizzo di fgets(), finche' l'input inserito non e' il carattere ENTER.
				scanf("%[^\n]s", &text);		
				fflush(stdin); // liberiamo il buffer di input.
				if(strlen(text) <= 256) {
					/* 
						text[strlen(text)-1] = '\0'; // L'ultimo carattere sarÃ  sempre ENTER, dunque lo cancelliamo.
						fgets() contava come carattere (l'ultimo) il carattere ENTER. 
						L'operazione descritta nella prima riga di commento, evitava che quel carattere venisse memorizzato nella stringa.
					*/
					scrivi_post(my_account,text);	
					// Se i post sono piu' di 10 bisogna eliminare quello meno recente tra tutti.
					if(my_account->s_tot_post > 10) Pop_Post(&my_account->s_post_list); // Pop_Post elimina alla tail.
				} else { 
					// controllo del numero di caratteri inseriti in input.
					printf("Hai superato il numero massimo di caratteri.\n");
					printf("Hai scritto: %d caratteri!", strlen(text));
					printf("\nPREMI INVIO PER CONTINUARE...\n");
					fflush(stdin); // liberiamo il buffer di input.
					getchar();
				}
				break;
			// Visualizzazione account seguiti.
			case 5:
				printf("I tuoi account seguiti: \n \n");
				Order_list(my_account->s_account_seguiti); // chiamata a sottoprogramma per ordinare in ordine alfabetico la lista.
				Print_list(my_account->s_account_seguiti); // chiamata a sottoprogramma per stampare la lista degli account seguiti.
				printf("PREMI INVIO PER CONTINUARE...\n");
				fflush(stdin); // liberiamo il buffer di input.
				getchar();									
				break;
			// Cambio del nickname.
			case 6: 
			{
				char nick[16];
				clearscr(); // pulizia dello schermo.
				fflush(stdin); // liberiamo il buffer di input.
				printf("				-------- CAMBIO NICKNAME --------  \n");
				printf("Che nickname desideri avere? --> ");
				scanf("%s", nick);	
				// Se la lunghezza del nickname e' accettabile e il nickname non e' presente nella lista.
				if((strlen(nick) <= 16) && (search_by_name(nick, account_list) == null_account))
				{
					// cambiamo il nickname!
					strcpy(my_account->s_user_name, nick);
					Order_list(account_list);	
				}					
				break;
			}
			case 7:
			{
				char passwd[16];
				bool changed = false;
				do
				{
					clearscr();		
					fflush(stdin);	
					printf("CAMBIA LA TUA PASSWORD \n");
					printf("Inserisci la tua NUOVA password : [MAX 16 CARATTERI] :");
					scanf("%s",passwd);
					if (strlen(passwd) <= 16)
					{
						changed = true;
					}
										
				}while(!changed);
					fflush(stdin);
					// La password relativa all'utente verra' sostituita con la funzione "strcpy()".		
					strcpy(my_account->s_passwd, passwd); 
				break;						
			}

			// Se l'input non e' corretto ritorniamo allo starting point dell'area riservata.
			default:
				printf("Hai inserito un valore non valido!\n");
				printf("PREMI INVIO PER CONTINUARE...\n");
				fflush(stdin);	// come sempre liberiamo il buffer di input	
				getchar();									
				exited = false;
		}
	} while(!exited);
}

/*
	Procedure di creazione del post.
*/
struct Post Create_Post(char p_text[])
{
	struct Post new_post;
	// nel campo text del post dobbiamo inserire il testo digitato dall'utente. Sfruttiamo la funzione strcpy().
	strcpy(new_post.text, p_text);
	// inizializziamo il campo "points" a zero.
	new_post.points = 0; 
	return new_post;
}

/*
	Questa funzione si occupa di dell'opzione "follow".
	Ogni account ha la possibilita' di seguire gli altri.
*/
void Follow(Lista_Account** p_account_seguiti , struct Account* p_account)
{
	// Creiamo spazio per l'inserimento di un nuovo nodo nella lista degli account seguiti.
	Lista_Account* new_followed_account = (Lista_Account*) malloc(sizeof(Lista_Account));
	// Facciamo spazio per l'account da inserire nella lista degli account seguiti.
	new_followed_account->l_account = (struct Account*) malloc(sizeof(struct Account));
	// L'algoritmo implementato è praticamente quello di push.
	*new_followed_account->l_account = *p_account;
	new_followed_account->l_next_account = *p_account_seguiti;	
	*p_account_seguiti = new_followed_account;			
}

/*
	Procedura di rimozione di un account dalla lista degli account seguiti.
	Tale procedura e' stata concepita per dare la possibilita' all'utente di smettere di seguire un account.
*/
void Unfollow(Lista_Account** p_account_seguiti , struct Account* p_account)
{
	// puntatore1 = puntatore2 ----> puntatore1 contiene l'indirizzo del puntatore2.
    Lista_Account* temp = *p_account_seguiti; // temp contiene l'indirizzo di p_account_seguiti.
    Lista_Account* prev = NULL;

    // Se l'account di cui eliminare il follow e' presente in testa:
    if (temp != NULL && strcmp(temp->l_account->s_user_name,p_account->s_user_name) == 0){
        *p_account_seguiti = temp->l_next_account; // ci salviamo il successivo per eliminare la testa.
		// liberiamo lo spazio occupato in memoria.
        free(temp->l_account);
        free(temp);
		// interrompiamo l'esecuzione della funzione.
        return;
    } else { 
		// Se l'account non e' presente in testa, bisogna cercare nel resto della lista.
		/*
			Una volta trovato l'account si collega bisogna collegare il link del precedente con il successivo del nodo da eliminare.
			Consideriamo anche il nodo precedente: 
		*/
        while (temp != NULL && strcmp(temp->l_account->s_user_name,p_account->s_user_name) != 0){
            prev = temp;
            temp = temp->l_next_account;
        }
        if (temp == NULL) // se il valore non e' presente, terminiamo l'esecuzione della procedura.
        	printf("NON SEGUI QUESTO ACCOUNT\n");
            return;

		// effettuiamo il collegamento del link del precedente con il successivo del nodo che dobbiamo eliminare.
        prev->l_next_account = temp->l_next_account;
		// liberiamo lo spazio occupato in memoria.
        free(temp->l_account);
        free(temp);
    }
}

/*
	Procedura per la scrittura di un post.
	Essa implementa Push_Post() e Create_Post.
*/
void scrivi_post(struct Account* p_account, char text[])
{
	/* 
		Ogni volta che scriviamo un post dobbiamo contare quanti post abbiamo scritto. 
		Questo perche' per ogni account manteniamo memoria di massimo 10 post.
	*/
	++p_account->s_tot_post; 
	Push_Post(&p_account->s_post_list, Create_Post(text)); // chiamata a sottoprogramma della procedura di Push_Post().
}

/*
	Starting point dell'applicazione.
*/
void MENU() 
{
	unsigned int input = 0;
	bool accepted = false;	
	// Sfrutteremo una variabile booleana per continuare il ciclo.
	do 
	{
		clearscr(); // pulizia dello schermo.
		printf("				-------- SOCIAL-C NOOBIES -------- \n");
		printf("[1] Crea un account\n[2] Accedi al tuo account\n[3] Esci dal programma\n");	
		printf("\nInserisci la tua scelta --> ");
		/* 
			Effettuiamo un check se l'input non e' corretto (Ex. carattere). Se cosi', bisogna liberare il buffer di input.
			Inoltre forziamo la condizione di default del costrutto di selezione multipla.
		*/
		if (scanf("%u", &input) == 0){
			fflush(stdin);
			input = 10;
		}
		// Essendo un menu', sfruttiamo il costrutto di selezione multipla.
		switch(input)
		{
			// Se digitiamo 1, procediamo con la chiamata della funzione SING_UP().
			case 1:
				clearscr();		
				SIGN_UP();
				break;	
			// Se digitiamo 2, procediamo con la chiamata della funzione LOGIN().		
			case 2:
				clearscr();
				LOGIN();			
				break;
			// Se digitiamo 3, salviamo i dati relativi al runtime nel file di testo. Per farlo usiamo la funzione Save().			
			case 3:
				Save(account_list);
				accepted = true; // Terminiamo il ciclo settando a true la variabile booleana.
				break;
			// se l'input inserito non e' corretto dobbiamo ripetere l'operazione del Menu().
			default:
				printf("Spiacente, ma la tua scelta non e' disponibile!\n");
				printf("PREMI INVIO PER CONTINUARE...\n");
				fflush(stdin); // puliamo il buffer di input.
				getchar();	
				accepted = false;
		}		
	} while(!accepted);
}
#include "Network.h" // Inclusione della libreria locale da noi creata.

void setup_default_account(){


	// Crezione dei 5 account di default.
	Push_Account(&account_list, Create_Account("Carmine","fra127"));
	Push_Account(&account_list, Create_Account("Simone","pluto"));
	Push_Account(&account_list, Create_Account("Enrico","password123"));
	Push_Account(&account_list, Create_Account("Antonio","pippo"));
	Push_Account(&account_list, Create_Account("Davide","d1ablo_22"));

		
	// Setup dei post di "Carmine".
	scrivi_post(search_by_name("Carmine", account_list),"Ciao, sono Carmine!");
	scrivi_post(search_by_name("Carmine", account_list),"Ho 20 anni.");
	scrivi_post(search_by_name("Carmine", account_list),"Sono di nazionalita' italiana.");
	scrivi_post(search_by_name("Carmine", account_list),"Frequento l'universita' di Napoli.");
	scrivi_post(search_by_name("Carmine", account_list),"Sono al primo anno.");
	scrivi_post(search_by_name("Carmine", account_list),"Studio informatica.");
	scrivi_post(search_by_name("Carmine", account_list),"Numero preferito: 10.");
	scrivi_post(search_by_name("Carmine", account_list),"Colore preferito: Rosso.");
	scrivi_post(search_by_name("Carmine", account_list),"Cibo preferito: Pizza.");
	scrivi_post(search_by_name("Carmine", account_list),"Materia scolastica preferita: Informatica.");
	// Setup dei post di "Simone".
	scrivi_post(search_by_name("Simone", account_list),"Ciao, sono Simone!");
	scrivi_post(search_by_name("Simone", account_list),"Ho 19 anni.");
	scrivi_post(search_by_name("Simone", account_list),"Sono di nazionalita' italiana.");
	scrivi_post(search_by_name("Simone", account_list),"Frequento l'universita' di Roma.");
	scrivi_post(search_by_name("Simone", account_list),"Sono al secondo anno.");
	scrivi_post(search_by_name("Simone", account_list),"Studio scienze sociali.");
	scrivi_post(search_by_name("Simone", account_list),"Numero preferito: 7.");
	scrivi_post(search_by_name("Simone", account_list),"Colore preferito: Blue.");
	scrivi_post(search_by_name("Simone", account_list),"Cibo preferito: Hamburger.");
	scrivi_post(search_by_name("Simone", account_list),"Materia scolastica preferita: Filosofia.");
	// Setup dei post di "Enrico".
	scrivi_post(search_by_name("Enrico", account_list),"Ciao, sono Enrico!");
	scrivi_post(search_by_name("Enrico", account_list),"Ho 19 anni.");
	scrivi_post(search_by_name("Enrico", account_list),"Sono di nazionalita' italiana.");
	scrivi_post(search_by_name("Enrico", account_list),"Frequento l'universita' di Milano.");
	scrivi_post(search_by_name("Enrico", account_list),"Sono al primo anno.");
	scrivi_post(search_by_name("Enrico", account_list),"Studio intelligenze artificiali.");
	scrivi_post(search_by_name("Enrico", account_list),"Numero preferito: 11.");
	scrivi_post(search_by_name("Enrico", account_list),"Colore preferito: Blue.");
	scrivi_post(search_by_name("Enrico", account_list),"Cibo preferito: Pasta.");
	scrivi_post(search_by_name("Enrico", account_list),"Materia scolastica preferita: Telecomunicazioni.");
	// Setup dei post di "Antonio".
	scrivi_post(search_by_name("Antonio", account_list),"Ciao, sono Antonio!");
	scrivi_post(search_by_name("Antonio", account_list),"Ho 20 anni.");
	scrivi_post(search_by_name("Antonio", account_list),"Sono di nazionalita' italiana.");
	scrivi_post(search_by_name("Antonio", account_list),"Frequento l'universita' di Napoli.");
	scrivi_post(search_by_name("Antonio", account_list),"Sono al terzo anno.");
	scrivi_post(search_by_name("Antonio", account_list),"Studio informatica.");
	scrivi_post(search_by_name("Antonio", account_list),"Numero preferito: 9.");
	scrivi_post(search_by_name("Antonio", account_list),"Colore preferito: Arancione.");
	scrivi_post(search_by_name("Antonio", account_list),"Cibo preferito: fish and chips.");
	scrivi_post(search_by_name("Antonio", account_list),"Materia scolastica preferita: programmazione.");
	// Setup dei post di "Davide".
	scrivi_post(search_by_name("Davide", account_list),"Ciao, sono Davide!");
	scrivi_post(search_by_name("Davide", account_list),"Ho 21 anni.");
	scrivi_post(search_by_name("Davide", account_list),"Sono di nazionalita' italiana.");
	scrivi_post(search_by_name("Davide", account_list),"Frequento l'universita' di Bologna.");
	scrivi_post(search_by_name("Davide", account_list),"Sono al secondo anno.");
	scrivi_post(search_by_name("Davide", account_list),"Studio giurisprudenza.");
	scrivi_post(search_by_name("Davide", account_list),"Numero preferito: 17.");
	scrivi_post(search_by_name("Davide", account_list),"Colore preferito: Blue.");
	scrivi_post(search_by_name("Davide", account_list),"Cibo preferito: Pizza.");
	scrivi_post(search_by_name("Davide", account_list),"Materia scolastica preferita: Legge.");

}


int main(void)
{

	setup_default_account(); // prima di avviare il programma dobbiamo inizializzare gli account
	MENU(); // questa procedura rappresenta lo starting point della nostra applicazione.

	return 0;
}
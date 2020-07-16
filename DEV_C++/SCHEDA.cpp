// PROGRAMMA SCHEDA ALIMENTARE // 
#include <iostream>
#include <string>
using namespace std;

struct scheda{
    int orario1;
    int orario2;
    int orario3;
    int orario4;
    int orario5;
    string alimento1;
    string alimento2;
    string alimento3;
    string alimento4;
    string alimento5;
    string giorno;
};

int main(){
	
	cout << "\t\t\t\t SCHEDA ALIMENTARE DELLA SETTIMANA" << endl << endl;
	scheda sc[7];
	// LUNEDI //
	sc[0].giorno = "LUNEDI";
	sc[0].orario1 = 6.30;
	sc[0].alimento1 = "FETTE BISCOTTATE + MARMELLATA";
	sc[0].orario2 = 11.00;
	sc[0].alimento2 = "BARRETTA PROTEICA";
	sc[0].orario3 = 13.30;
	sc[0].alimento3 = "PASTA INTEGRALE AL POMODORO + TONNO";
	sc[0].orario4 = 17.30;
	sc[0].alimento4 = "BANANA / MELA";
	sc[0].orario5 = 19.30;
	sc[0].alimento5 = "BASTONCINI DI VERDURE";
	// MARTEDI // 
	sc[1].giorno = "MARTEDI";
	sc[1].orario1 = 6.30;
	sc[1].alimento1 = "YOGURT + FRUTTA SECCA + MAGNESIO + MULTIVITAMINICO";
	sc[1].orario2 = 11.00;
	sc[1].alimento2 = "5 GALLETTE DI MAIS";
	sc[1].orario3 = 13.30;
	sc[1].alimento3 = "RISO CON TONNO / PATATE / POMODORO / POLLO";
	sc[1].orario4 = 17.30;
	sc[1].alimento4 = "BANANA / FRUTTA SECCA";
	sc[1].orario5 = 19.30;
	sc[1].alimento5 = "PETTO DI POLLO";
	// MERCOLEDI // 
	sc[2].giorno = "MERCOLEDI";
	sc[2].orario1 = 6.30;
	sc[2].alimento1 = "YOGURT + FRUTTA SECCA";
	sc[2].orario2 = 11.00;
	sc[2].alimento2 = "BARRETTA";
	sc[2].orario3 = 13.30;
	sc[2].alimento3 = "PASTA CON ZUCCA / ZUCCHINE";
	sc[2].orario4 = 17.30;
	sc[2].alimento4 = "BANANA";
	sc[2].orario5 = 19.30;
	sc[2].alimento5 = "UOVA";
	// GIOVEDI // 
	sc[3].giorno = "GIOVEDI";
	sc[3].orario1 = 6.30;
	sc[3].alimento1 = "FETTE BISCOTTATE + MARMELLATA + MAGNESIO + MULTIVITAMINICO";
	sc[3].orario2 = 11.00;
	sc[3].alimento2 = "5 GALLETTE DI MAIS";
	sc[3].orario3 = 13.30;
	sc[3].alimento3 = "RISO";
	sc[3].orario4 = 17.30;
	sc[3].alimento4 = "BANANA";
	sc[3].orario5 = 19.30;
	sc[3].alimento5 = "MERLUZZO";
	// VENERDI // 
	sc[4].giorno = "VENERDI";
	sc[4].orario1 = 6.30;
	sc[4].alimento1 = "LATTE + CEREALI";
	sc[4].orario2 = 11.00;
	sc[4].alimento2 = "BARRETTA";
	sc[4].orario3 = 13.30;
	sc[4].alimento3 = "PASTA CON CECI";
	sc[4].orario4 = 17.30;
	sc[4].alimento4 = "YOGURT MAGRO";
	sc[4].orario5 = 19.30;
	sc[4].alimento5 = "BASTONCINI DI VERDURE / MERLUZZO";
	// SABATO // 
	sc[5].giorno = "SABATO";
	sc[5].orario1 = 6.30;
	sc[5].alimento1 = "YOGURT + FRUTTA SECCA";
	sc[5].orario2 = 11.00;
	sc[5].alimento2 = "BANANA";
	sc[5].orario3 = 13.30;
	sc[5].alimento3 = "PASTA INTEGRALE CON POMODORO";
	sc[5].orario4 = 17.30;
	sc[5].alimento4 = "BANANA";
	sc[5].orario5 = 19.30;
	sc[5].alimento5 = "PIZZA";
	// DOMENICA // 
	sc[6].giorno = "DOMENICA";
	sc[6].orario1 = 6.30;
	sc[6].alimento1 = "YOGURT + FRUTTA SECCA";
	sc[6].orario2 = 11.00;
	sc[6].alimento2 = "BANANA";
	sc[6].orario3 = 13.30;
	sc[6].alimento3 = "TORTELLINI / GNOCCHI";
	sc[6].orario4 = 17.30;
	sc[6].alimento4 = "BANANA / MELA";
	sc[6].orario5 = 19.30;
	sc[6].alimento5 = "MERLUZZO / CARNE";
	
	
	// OUTPUT // 
	cout <<"\t\t\t"<< sc[0].giorno << endl;
	cout << sc[0].orario1 << "\t" << sc[0].alimento1 << endl;
	cout << sc[0].orario2 << "\t" << sc[0].alimento2 << endl;
	cout << sc[0].orario3 << "\t" << sc[0].alimento3 << endl;
	cout << sc[0].orario4 << "\t" << sc[0].alimento4 << endl;
	cout << sc[0].orario5 << "\t" << sc[0].alimento5 << endl;
	cout << "---------------------------------------"<< endl;

	cout <<"\t\t\t"<< sc[1].giorno << endl;
	cout << sc[1].orario1 << "\t" << sc[1].alimento1 << endl;
	cout << sc[1].orario2 << "\t" << sc[1].alimento2 << endl;
	cout << sc[1].orario3 << "\t" << sc[1].alimento3 << endl;
	cout << sc[1].orario4 << "\t" << sc[1].alimento4 << endl;
	cout << sc[1].orario5 << "\t" << sc[1].alimento5 << endl;
	cout << "---------------------------------------"<< endl;
	
	cout <<"\t\t\t"<< sc[2].giorno << endl;
	cout << sc[2].orario1 << "\t" << sc[2].alimento1 << endl;
	cout << sc[2].orario2 << "\t" << sc[2].alimento2 << endl;
	cout << sc[2].orario3 << "\t" << sc[2].alimento3 << endl;
	cout << sc[2].orario4 << "\t" << sc[2].alimento4 << endl;
	cout << sc[2].orario5 << "\t" << sc[2].alimento5 << endl;
	cout << "---------------------------------------"<< endl;
	
	cout <<"\t\t\t"<< sc[3].giorno << endl;
	cout << sc[3].orario1 << "\t" << sc[3].alimento1 << endl;
	cout << sc[3].orario2 << "\t" << sc[3].alimento2 << endl;
	cout << sc[3].orario3 << "\t" << sc[3].alimento3 << endl;
	cout << sc[3].orario4 << "\t" << sc[3].alimento4 << endl;
	cout << sc[3].orario5 << "\t" << sc[3].alimento5 << endl;
	cout << "---------------------------------------"<< endl;
	
	cout <<"\t\t\t"<< sc[4].giorno << endl;
	cout << sc[4].orario1 << "\t" << sc[4].alimento1 << endl;
	cout << sc[4].orario2 << "\t" << sc[4].alimento2 << endl;
	cout << sc[4].orario3 << "\t" << sc[4].alimento3 << endl;
	cout << sc[4].orario4 << "\t" << sc[4].alimento4 << endl;
	cout << sc[4].orario5 << "\t" << sc[4].alimento5 << endl;
	cout << "---------------------------------------"<< endl;
	
	cout <<"\t\t\t"<< sc[5].giorno << endl;
	cout << sc[5].orario1 << "\t" << sc[5].alimento1 << endl;
	cout << sc[5].orario2 << "\t" << sc[5].alimento2 << endl;
	cout << sc[5].orario3 << "\t" << sc[5].alimento3 << endl;
	cout << sc[5].orario4 << "\t" << sc[5].alimento4 << endl;
	cout << sc[5].orario5 << "\t" << sc[5].alimento5 << endl;
	cout << "---------------------------------------"<< endl;
	
	cout <<"\t\t\t"<< sc[6].giorno << endl;
	cout << sc[6].orario1 << "\t" << sc[6].alimento1 << endl;
	cout << sc[6].orario2 << "\t" << sc[6].alimento2 << endl;
	cout << sc[6].orario3 << "\t" << sc[6].alimento3 << endl;
	cout << sc[6].orario4 << "\t" << sc[6].alimento4 << endl;
	cout << sc[6].orario5 << "\t" << sc[6].alimento5 << endl;
	cout << "---------------------------------------"<< endl;
		
	system("pause");
}

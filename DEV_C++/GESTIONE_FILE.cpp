// ESEMPIO DI DATABASE:
// FILE DI TESTO AL CUI INTERNO SONO INSERITI: NOME ETA E GUADAGNO DELL'IMPIEGATO
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

void input();
void searchname();
void searchage();
void searchsalary();
void quit();
void displayall();
void search();
void deleteFile();
void editFile();

int main() {      
   system ("title Primo Database");
   system ("cls");
   system ("color 0F");
       int choice;
       cout << "1.Inserisci un nuovo file" << endl;
       cout << "2.Cerca database dell'impiegato" << endl;
       cout << "3.Pulisci il registro" << endl;
       cout << "4.Modifica il file" << endl;
       cout << "5.Esci dal programma" << endl << endl;
       cout << "Attesa Input: "; cin >> choice;

switch (choice){
       case 1:
            input();
            break;
       case 2:
            search();
            break;
       case 3:
            deleteFile();
            break;
       case 4:
            editFile();
            break;
       case 5:
            quit();
            break;
            
       cin.get();     
    }
}
void editFile()
{
 string name, input, newName,decision;
 int age;
 double salary;
 ifstream employee("file-data.txt");
 if (!employee.eof()){
employee >> name >> age >> salary;
}
 system("cls");
 
 cout << "Inserisci il nome dell'impiegato:";
 cin >> input;

 if (input == name)
 {
     
     cout << name << ' ' << age << ' ' << salary << endl;
     cout << "E'la persona giusta?[y][n]:";
     cin >> decision;
     if (decision == "y"){
     cout << "Inserisci un nuovo nome:";
     cin >> newName;
     name = newName;      
           } 
            
     employee.close();
     }
    
     ofstream employee2("file-data2.txt", ios::app);
     employee2 << name << ' ' << age << ' ' << salary << endl;
     employee2.close();
 system("pause");
 main();
     }
     
void input()
{       
 string name;
 int age; 
 long int salary;
 ofstream newemployee("newemployee.txt", ios::app);
 system("cls");
 cout << "Inserisci il nome del nuovo impiegato" << endl;
 cin >> name;
 cin.sync();
 system("cls");
 cout << "Inserisci la sua eta':" << endl;
 cin >> age;
 system("cls");
 
 cout << "Digita il suo guadagno annuale: " << endl;
 cin >> salary;

        
 newemployee << name << ' ' << age << ' ' << salary << endl;     
 newemployee.close(); 
 main();
     }
void searchname()
{
     ifstream employee("newemployee.txt");
     string name;
     string str, line;
     int age, offset;
     long int salary;
     system("CLS");
     cout << "Digita il nome dell'impiegato:";
     cin >> str;
              
     while (employee >> name >> age >> salary){  
           if (str == name){
     system ("CLS");
     cout << "Impiegato trovato!" << endl;
     cout << "Nome" << ' ' << "ETA'" << ' ' << "GUADAGNO" << endl;
     cout << "------------------------------------------" << endl;     
     cout << name << ' '<< age << ' ' << "$" <<  salary << endl;
     }
     }

            
     while (employee >> name ){
                 if (str != name){
                 system ("CLS") ;   
                 cout << "Non esiste nessuno con questo nome!..." << endl;     
                      
                      }
                      }
     system ("pause");
     main();
     
     
 }
void searchage()
 {
     ifstream employee("newemployee.txt");
     string name;
     int age ;
     int fage;
     long int salary;
     system ("CLS");
     cout << "Digita l'eta dell'impiegato:";
     cin >> fage;
     while (employee >> name >> age >> salary){
           if (fage == age){
                    system ("CLS");
                    cout << "Impiegato trovato!" << endl;
                    cout << "NOME" << ' ' << "ETA'" << ' ' << "GUADAGNO" << endl;
                    cout << "------------------------------------------" << endl;
                    cout << name << ' ' << age << ' ' << "$" << salary << endl;
                    }
                    }
     while (employee >> age){      
           if (fage != age){
                    system ("CLS");
                    cout << "Nessun impiegato trovato!..."<< endl;
                    
                    
                    }  
           }
           system ("pause");
           cin.get();
           main();
  }
void searchsalary()
{
     ifstream employee ("newemployee.txt");
     string name;
     int age ;
     long int salary;
     long int fsalary;
     system ("CLS");
     cout << "Inserisci il guadagno dell'impiegato:";
     cin >> fsalary;
     while (employee >> name >> age >> salary){
           if (fsalary == salary ){
                       system ("cls");
                       cout << "Impiegato trovato!"<< endl;
                       cout << "NOME" << ' ' << "ETA'" << ' ' << "GUADAGNO" << endl;
                       cout << "---------------" << endl;
                       cout << name << ' ' << age << ' ' << "$" << salary << endl;;
                       
                       }
                       }
     while (employee >> salary){
            if (fsalary != salary){
                system ("CLS");
                cout << "Impiegato non trovato!" << endl;
                }
           }
     system("pause");
     cin.get();
     main();
 }
 
void quit()
{
 system ("CLS");
 cout << "Grazie per aver usato il database di Simone Catapano!" << endl << endl;
 system ("pause");
 cin.get();
} 

void displayall()
{
     ifstream employee("newemployee.txt");
     int age;
     long int salary;
     string name;
     system ("CLS");
     cout << "Entire employee database"<< endl;
     cout << "Name" << ' ' << "Age" << ' ' << "Salary" << endl;
     cout << "---------------" << endl;
     while (employee >> name >> age >> salary){
     cout << name << ' ' << age << ' ' << "$" << salary << endl ;
     }
     system ("pause");
     cin.get();
     main();
     
     }
void search()
{
     int age;
     string name;
     long double salary;
     int choice2;
     system ("CLS");
     
     cout << "1.Cerca per nome" << endl;
     cout << "2.Cerca per eta" << endl;
     cout << "3.Cerca per guadagno" << endl;
     cout << "4.Mostra tutti gli impiegati" << endl;
     cout << "5.Indietro" << endl;
     cout << "6.Esci dal programma" << endl;
     cin >> choice2;
     
     switch (choice2){
            case 1:
                 searchname();
                 break;
            case 2:
                 searchage();
                 break;
            case 3:
                 searchsalary();
                 break;
            case 4:
                 displayall();
                 break;
            case 5:
                 main();
                 break;
            case 6:
                 quit();
                 break;
                 }
            }
void deleteFile()
{
     string decision;
     cout << "Sei sicuro?[Y]es[N]o" << endl;
     cin >> decision;
     if (decision == "y"){
     ofstream employee("newemployee.txt");
     system("cls");
     cout << "Successfully Completed!" << endl;
     system("pause");
     employee.close();
     main();
     }
     else{
          main();
          }
}

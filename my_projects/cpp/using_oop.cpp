#include <iostream>
#include <string>
using namespace std;

class MyClass {       
  public:             
    int numero = 0;        
    string frase = "";  
};

int main() {
  MyClass Obj;

  Obj.numero = 60; 
  Obj.frase = "Prima prova con C++ ad oggetti!";

  cout << "La classe <Obj> ha il numero: "<< Obj.numero << "\n";
  cout << "La classe <Obj> ha la frase: "<< Obj.frase << "\n";
  return 0;
}

#include <iostream>

using namespace std;

bool primo(int);

int main(){
  
 int n;
 int contadorPrimo = 0;

 cout << "Ingrese un numero(CORTA CON CERO): ";
 cin >> n;
 while (n != 0)
 {

  contadorPrimo += (primo(n)) ? 1 : contadorPrimo = 0;

  if(contadorPrimo == 4){
    cout << "REPONER INSUMOS" << endl;
    cout << "Ingrese un cero para finalizar: ";
    cin >> n;    
  } 


  if(n != 0){
     cout << "Ingrese un numero(CORTA CON CERO): ";
     cin >> n;
     if(n == 0){
      cout << "EXITOSO";
    } 
  } 
}

  
  

  return 0;
}


bool primo(int n){
  int contPrimo = 0; 
  for(int x = 1; x <= n; x++){
    if(n % x == 0){
      contPrimo ++;
    }
  }
  return (contPrimo == 2) ? true : false;
}

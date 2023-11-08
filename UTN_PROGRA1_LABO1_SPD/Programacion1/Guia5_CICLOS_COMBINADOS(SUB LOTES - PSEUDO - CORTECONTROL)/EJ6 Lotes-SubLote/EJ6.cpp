#include <iostream>
using namespace std;

int main() 
{

  for(int x = 0; x < 4; x ++)
  { 
    int n, numeroAnterior, contPrimoPorGrupo = 0, minimoPar, posicion1 = 0, posicion2 = 0;
    bool banderaMinimoPar = false, banderaAnteUltimoUltimo = false;

    cout << "Ingrese un numero: ";
    cin >> n;
    numeroAnterior = n;
    while (n >= numeroAnterior)
    { 
      int contPrePrimo = 0;
      for (int i = 1; i <= n; i ++)
        if(n%i == 0)  
          contPrePrimo ++;
      
      if(contPrePrimo == 2)
        contPrimoPorGrupo ++;
      
      if(n % 2 == 0)
      {
        if(!banderaMinimoPar)
        {
          minimoPar = n;
          banderaMinimoPar = true;
        }
        else
        {
          if(n < minimoPar)
          {
            minimoPar = n;
          }
        }
      }  
      
      if(n > 0)
      {
        if(!banderaAnteUltimoUltimo){
          posicion1 = n;
          posicion2 = posicion1;
          banderaAnteUltimoUltimo = true;
        }else{
          posicion2 = posicion1;
          posicion1 = n;
        }
      }

      cout << "Ingrese un numero while: ";
      cin >> n;
      if(n > numeroAnterior)
       numeroAnterior = n;
    }

    cout << endl << "grupo " << x+1 << ")" << endl;
    cout << "Posee la cantidad de " << contPrimoPorGrupo << " numeros primos." << endl;
    cout << "El minimo numero par ingresado es: " << minimoPar << endl;
    cout << "El ultimo numero positivo: " << posicion1 << endl;
    cout << "El anteultimo numero positivo: " << posicion2 << endl << endl;
  } 
 
  return 0;
}
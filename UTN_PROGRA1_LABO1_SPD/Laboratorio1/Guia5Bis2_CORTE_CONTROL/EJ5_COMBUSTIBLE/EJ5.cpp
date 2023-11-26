#include <iostream>

using namespace std;

int main(){
  int numSucursal, numSucAnterior, dia, tipoDia, tipoCombustible;
  float litrosVendidos, importe;

  float maxLitros, maxTipoCombustible1, maxTipoCombustible2, maxTipoCombustible3, maxTipoCombustible4; //PTOA
  int tipoMax; //PTOA

  cout << "Ingrese numero sucursal (1 al 15) (CORTA CON CERO):  "; 
  cin >> numSucursal;
  while(numSucursal !=0)
  {
    maxTipoCombustible1 = maxTipoCombustible2 = maxTipoCombustible3 = maxTipoCombustible4 = 0.0; //PTOA

    numSucAnterior = numSucursal;
    while (numSucursal == numSucAnterior)
    { 
      cout << "Ingrese el dia de la venta (1 al 30): "; 
      cin >> dia;
      cout << "Tipo de dia (1-Habil, 2-find e semana): "; 
      cin >> tipoDia;
      cout << "Tipo de combustible (1-Extra, 2-super, 3-comun, 4-gasoil): "; 
      cin >> tipoCombustible;
      cout << "Importe de la venta ($): "; 
      cin >> importe;
      cout << "Libros vendidos: "; 
      cin >> litrosVendidos;

      switch (tipoCombustible)
      {
      case 1:
        maxTipoCombustible1 += litrosVendidos;
        break;
      case 2:
         maxTipoCombustible2 += litrosVendidos;
         break;
      case 3:
         maxTipoCombustible3 += litrosVendidos;
         break;
      case 4:
         maxTipoCombustible4 += litrosVendidos;
         break;       
      }



     cout << "Ingrese numero sucursal (1 al 15) (CORTA CON CERO):  "; 
     cin >> numSucursal;
    }

    if(maxTipoCombustible1 > maxTipoCombustible2 && maxTipoCombustible1 > maxTipoCombustible3 && maxTipoCombustible1 > maxTipoCombustible4){
      maxLitros = maxTipoCombustible1;
      tipoMax = 1;
    }else if(maxTipoCombustible2 > maxTipoCombustible1 && maxTipoCombustible2 > maxTipoCombustible3 && maxTipoCombustible2 > maxTipoCombustible4){
      maxLitros = maxTipoCombustible2;
      tipoMax = 2;
    }else if (maxTipoCombustible3 > maxTipoCombustible1 && maxTipoCombustible3 > maxTipoCombustible2 && maxTipoCombustible3 > maxTipoCombustible4){
      maxLitros = maxTipoCombustible3;
      tipoMax = 3;
    }else if(maxTipoCombustible4 > maxTipoCombustible1 && maxTipoCombustible4 > maxTipoCombustible2 && maxTipoCombustible4 > maxTipoCombustible3){
      maxLitros = maxTipoCombustible4;
      tipoMax = 4;
    }

    cout << endl << "PTOA => SUCURSAL: " << numSucAnterior << " tipo combustible mas vendido ";
    if(tipoMax == 1){
      cout << "Extra ";
    }else if (tipoMax == 2){
      cout << "SUPER ";
    }else if(tipoMax == 3){
      cout << "comun ";
    }else if(tipoMax == 4){
      cout << "gasoil ";
    }    
    
    cout << "cantidad de litros: " << maxLitros << endl;





  }  


  


  return 0;
}
#include <iostream>

using namespace std;

int main (){
  int sucursal, diaVenta, tipoCombustible, tipoPago;
  float importeVenta, litrosVendidos;
  char tipoDia, ubicacionSucursal;

  float acumLitros1, acumLitros2, acumLitros3, acumLitros4; // PTOA
  float  recaudacionTotal; //PTOB
  float maxRec1 = 0.0, subMaxRec1 = 0.0, maxRec2 = 0.0, subMaxRec2 = 0.0, maxRec3 = 0.0, subMaxRec3 = 0.0;
  int maxUnoDonTor = 0, maxDosDonTor = 0, maxUnoTigre = 0, maxDosTigre = 0, maxUnoPacheco = 0, maxDosPacheco = 0; 

  cout << "Ingrese numero sucursal (1 a 15)(CORTA CON CERO): ";
  cin >> sucursal;
  while(sucursal != 0){
    acumLitros1 = acumLitros2 = acumLitros3 = acumLitros4 = 0;//PTOA
    recaudacionTotal = 0;
          
    int sucursalAnterior = sucursal;
     
    while(sucursal == sucursalAnterior){
      cout << "Ubicación de la Sucursal (D=Don Torcuato,T=Tigre, P=Pacheco): ";
      cin >> ubicacionSucursal;
      cout << "Ingrese el dia de la venta(1 a 30): ";
      cin >> diaVenta;
      cout << "Ingrese el tipo de dia(H Habil - F fin de semana): ";
      cin >> tipoDia;
      cout << "Tipo de combustible vendido(1=extra, 2=super, 3=comun, 4 gasoil): ";
      cin >> tipoCombustible;
      cout << "Importe de la venta: ";
      cin >> importeVenta;
      cout << "Litros vendidos: ";
      cin >> litrosVendidos;
      cout << "Tipo de pago (1= Efectivo, 2= Tarjeta, 3= Ticket): ";
      cin >> tipoPago;
      
      recaudacionTotal += importeVenta; // PTOB

      if(tipoPago != 3)
      {
        switch (tipoCombustible)
        {
        case 1:
          acumLitros1 += litrosVendidos;
          break;
        case 2:
          acumLitros2 += litrosVendidos;
          break;  
        case 3:
          acumLitros3 += litrosVendidos;
          break;
        case 4:
          acumLitros4 += litrosVendidos;
          break;  
        }
      }
      
      cout << "Ingrese numero sucursal (1 a 15)(CORTA CON CERO): ";
      cin >> sucursal;
    }

    cout << "PUNTO A: " << "SUCURSAL: #" << sucursalAnterior  << " - TIPO COMBUSTIBLE MAX VENDIDO ES: ";
    if(acumLitros1 > acumLitros2 && acumLitros1 > acumLitros3 && acumLitros1 > acumLitros4){
       cout << "EXTRA" << endl;
    }else if (acumLitros2 > acumLitros1 && acumLitros2 > acumLitros3 && acumLitros2 > acumLitros4){
      cout << "SUPER" << endl;
    }else if (acumLitros3 > acumLitros1 && acumLitros3 > acumLitros2 && acumLitros3 > acumLitros4){
      cout << "COMUN" << endl;
    }else{
      cout << "GASOIL" << endl;
    }

    //PTO B
    switch (ubicacionSucursal)
    {
      case 'D':
        if(recaudacionTotal > maxRec1){
          subMaxRec1 = maxRec1;
          maxRec1 = recaudacionTotal;
          maxDosDonTor = maxUnoDonTor;
          maxUnoDonTor = sucursalAnterior;
        }else if(recaudacionTotal > subMaxRec1){
          subMaxRec1 =  recaudacionTotal;
          maxDosDonTor = sucursalAnterior;
        }
        break;
      case 'T':
        if(recaudacionTotal > maxRec2){
          subMaxRec2 = maxRec2;
          maxRec2 = recaudacionTotal;
          maxDosTigre = maxUnoTigre;
          maxUnoTigre = sucursalAnterior;
        }else if(recaudacionTotal > subMaxRec2){
          subMaxRec2 =  recaudacionTotal;
          maxDosTigre = sucursalAnterior;
        }
        break;
      case 'P':
        if(recaudacionTotal > maxRec3){
          subMaxRec3 = maxRec3;
          maxRec3 = recaudacionTotal;
          maxDosPacheco = maxUnoPacheco;
          maxUnoPacheco = sucursalAnterior;
        }else if(recaudacionTotal > subMaxRec3){
          subMaxRec3 =  recaudacionTotal;
          maxDosPacheco = sucursalAnterior;
        }
        break;    
    }
  }

  cout << endl;
  cout << "PUNTO B" << endl;
  cout << "DON TOR CUATO: MAXIMA REC SUCURSAL " << maxUnoDonTor << " - SEGUNDA MAX " << maxDosDonTor << endl;
  cout << "TIGRE: MAXIMA REC SUCURSAL " << maxUnoTigre << " - SEGUNDA MAX " << maxDosTigre << endl;
  cout << "PACHECO: MAXIMA REC SUCURSAL " << maxUnoPacheco << " - SEGUNDA MAX " << maxDosPacheco;

  return 0;
}
#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
#include <vector> //es para verctor dinamico STL
#include <ctime> //es para la hs
#include <cstdlib>  // Necesario para std::rand y std::srand

//setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */


const int VUELOS = 3;

/*
- Número de Vuelo (1 a 50)
- Ciudad Origen (1 a 20)
- Ciudad Destino (1 a 20)
- Costo del pasaje (por Persona)
- Distancia en millas del vuelo*/

void fCarga(int [], int [], float [], float []);
void fProceso(float [], float []);
void buscarMax(float []);

int main()
{
  int v_origen[VUELOS] , v_destino[VUELOS];
  float v_costo[VUELOS], v_distancia[VUELOS];

  float millasPTA[150] = {};//PTOA

  fCarga(v_origen, v_destino, v_costo,  v_distancia);
  fProceso(millasPTA, v_distancia);

  buscarMax(millasPTA);




 
}





void fCarga(int v_origen [], int v_distino[], float v_costo [], float v_distancia []){
  int ciudad_origen, ciudad_destino;
  float costo, distancia; 

  for(int x = VUELOS-1; x >= 0; x --){

    cout << x+1 << ") Ingrese la Ciudad de Origen(1 - 20): ";
    cin >> ciudad_origen;
    cout << x+1 << ") Ingrese el destino(1 - 20): ";
    cin >> ciudad_destino;
    cout << x+1 << ") Ingrese el costo del pasaje (por persona): ";
    cin >> costo;
    cout << x+1 << ") Ingrese la distancia(en millas): ";
    cin >> distancia;
    cout << endl;

    v_origen[x] = ciudad_origen;
    v_distancia[x] = ciudad_destino;
    v_costo[x] = costo;
    v_distancia[x] = distancia;
  }
}
void fProceso(float millasPTA[], float v_distancia[]){
  int nroCliente, codVuelo, dia, mes, cantPasaje, nroVendedor;
  cout <<" Ingrese el numero de cliente (1 - 150): ";
  cin >> nroCliente;
  cout <<" Ingrese el codigo de vuelo (1 - 50): ";
  cin >> codVuelo;
  cout <<" Ingrese el dia de la venta (1 - 31)(CORTA CON CERO): ";
  cin >> dia;
  while(dia != 0)
  {
    cout <<" Ingrese el mes de la venta (1 - 12): ";
    cin >> mes;
    cout <<" Ingrese la cantidad de pasajes adquiridos: ";
    cin >> cantPasaje;
    cout <<" Ingrese el numero del vendedor (1 - 8): ";
    cin >> nroVendedor;
    cout << endl;

    //PTOA
    millasPTA[nroCliente-1] += v_distancia[codVuelo-1]*cantPasaje;





    
    cout <<" Ingrese el numero de cliente (1 - 150): ";
    cin >> nroCliente;
    cout <<" Ingrese el codigo de vuelo (1 - 50): ";
    cin >> codVuelo;
    cout <<" Ingrese el dia de la venta (1 - 31)(CORTA CON CERO): ";
    cin >> dia;
  }




}

void buscarMax(float millasPTA[]){
  float max;
  int clienteMax;
  max = millasPTA[0];
  clienteMax = 1;
  
  for(int x = 1;x < 50; x++){
    if(millasPTA[x] > max){
      max = millasPTA[x];
      clienteMax = x + 1;
    }
  }

  cout << "El cliente que mas millas recorrio es el Numero " << clienteMax << " y lo hizo con " << max << " millas" << endl;

}





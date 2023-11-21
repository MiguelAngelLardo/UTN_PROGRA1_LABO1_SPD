#include <iostream>
#include <vector> //STL, Standard Template Library
#include "funciones.h"
#include "estructuras.h"
using namespace std;

struct Empleado{
  int nroEmpleado; // buscamos indice
  int categoria;
  int antiguedad;
};

void carga(vector<Empleado> &);
void proceso (vector<Empleado> &, int [], int []);
void FuncionPTA (vector<Empleado> &, int [], int [], int, int, int);

int main()
{
  vector<Empleado> empleados1;
  carga(empleados1);

  //en tiempo de ejecucion no puedo modificar ARRAY por eso uso VECTOR y ese tamaño DINAMICO lo asigno a CONSTANTE
  const int MAX_EMPLEADO = empleados1.size();
  int empleadoDia[MAX_EMPLEADO] = {}, empleadoHoras [MAX_EMPLEADO]= {};//PTA

  proceso (empleados1, empleadoDia, empleadoHoras);

  return 0;
}

void carga(vector<Empleado> &empleados){
  for(int i = 0; i < 200; i ++ ){
    empleados.push_back(Empleado());// Agregar un nuevo elemento al final del vector

    cout << i+1 << ") Ingrese el nro de empleado (digitios no correlativos): ";
    cin >> empleados[i].nroEmpleado;
    cout << i+1 << ")Ingrese la categoria (1 a 20)(CORTA CON CERO): ";
    cin >> empleados[i].categoria;
    cout <<  i+1 << ") Antiguedad: ";
    cin >> empleados[i].antiguedad;
    
    if(!empleados[i].categoria){   
      i = 200;
      cout << "saliendo de fcarga";
      empleados.pop_back();
    }
  }
}

void proceso (vector<Empleado> &empleados1, int empleadoDia [], int empleadoHoras []){
  int dia, nroEmpleado, horasTrabajadas;
  float jornal;

  cout << "Ingrese el dia (1 a 31): ";
  cin >> dia;
  cout << "Ingrese el nro de empleado(3 digitos no correlativos)(CORTA CON CERO): ";
  cin >> nroEmpleado;
  while (nroEmpleado != 0)
  {
    cout << "Ingrese las HS trabajadas: ";
    cin >> horasTrabajadas;
    cout << "Ingrese el jornal cobrado en el dia: ";
    cin >> jornal;  

    FuncionPTA (empleados1, empleadoDia, empleadoHoras, nroEmpleado, horasTrabajadas, dia);

    cout << "Ingrese el dia (1 a 31): ";
    cin >> dia;
    cout << "Ingrese el nro de empleado(e digitos no correlativos): ";
    cin >> nroEmpleado;
  }
}

void FuncionPTA (vector<Empleado> &empleados1, int empleadoDia [], int empleadoHoras [], int nroEmpleado, int horasTrabajadas, int dia){
  for(int i = 0; i < empleados1.size(); i ++){
    if(empleados1[i].nroEmpleado == nroEmpleado)
    {
      if(horasTrabajadas > empleadoHoras [i])
      {
        empleadoHoras[i] = horasTrabajadas;
        empleadoDia [i] = dia;
      }
    }
  }
}
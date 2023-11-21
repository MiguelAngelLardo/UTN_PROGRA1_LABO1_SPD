#include <iostream>
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
  int numeroPelicula, calificacion, nroSocio, tipoSocio, diaAlquiler, numeroPeliculaAnterior;
  char generoPelicula, sexo;
  float costoAlquiler;
  int contadorAccion, contadorComedia, contadorTerror, maxAccion, maxComedia, maxTerror, maxNroAccion, maxNroComedia, maxNroTerror; //A)
  maxAccion = maxComedia = maxTerror = 0; //A)
  int contMasculino, contFemenino, maxMasculino, maxFemenino, maxCalificacionEnMasculino, maxCalificacionEnFemenino; //B)
  maxMasculino = maxFemenino = 0; //B)
  float recaudacionSocio1 = 0.0, recaudacionSocio2 =0.0, recaudacionSocio3 = 0.0;

  cout << "Ingrese el numero de pelicula (1000 a 2000): ";
  cin >> numeroPelicula;
  
  while(numeroPelicula !=0)
  { 
    contadorAccion = contadorComedia = contadorTerror = 0;//A)
    contMasculino = contFemenino = 0;//B)

    numeroPeliculaAnterior = numeroPelicula;
    while (numeroPelicula == numeroPeliculaAnterior)
    {
    //PROCESAR-LISTAR DATOS DE CADA PELICULA
      cout << "Ingrese el genero (A accion, C comedia, T terror): "; //se repite en cada nro de pelicula
      cin >> generoPelicula;
      cout << "Ingrese la calificacion (0 ATP, 13 mayor de 13, 16 mayor de 16): "; ////se repite en cada nro de pelicula
      cin >> calificacion;
      cout << "numero socio que alquilo ( 1 al 500): ";
      cin >> nroSocio;
      cout << "Ingrese el sexo (M masculino, F femenino): ";
      cin >> sexo;
      cout << "Ingrese el tipo de socio(1 normal, 2 exclusivo, 3 vip): ";
      cin >> tipoSocio;
      cout << "Ingrese el dia del alquiler (1 a 30): ";
      cin >> diaAlquiler;
      cout << "Costo del alquiler: ";
      cin >> costoAlquiler;

      switch (generoPelicula)
      {
        //PROCESAR A)
        case 'A':
          contadorAccion ++;          
        break;
        case 'C':
          contadorComedia ++;          
        break;
        case 'T':
          contadorTerror ++;          
        break; 
      }      

      //PROCESAR B)
      if(diaAlquiler >= 1 && diaAlquiler <= 15)
        if (sexo == 'M')
          contMasculino ++;
        else if (sexo == 'F')
          contFemenino ++;  
      
      //PROCESAR C)
      switch (tipoSocio)
      {
      case 1:
        recaudacionSocio1 += costoAlquiler;
        break;
      case 2:
        recaudacionSocio2 += costoAlquiler;
        break;
      case 3: 
        recaudacionSocio3 += costoAlquiler;
        break;
      }

      cout << "Ingrese el numero de pelicula (1000 a 2000)(CORTA CON CERO): ";
      cin >> numeroPelicula;
    }
    //PROCESAR-LISTAR EL SUB LOTE
    
    //PROCESAR A)
    if(contadorAccion > maxAccion){ 
      maxAccion = contadorAccion;
      maxNroAccion = numeroPeliculaAnterior;
    }
    if(contadorComedia > maxComedia){
    maxComedia = contadorComedia;
    maxNroComedia = numeroPeliculaAnterior;
    }
    if(contadorTerror > maxTerror){
    maxTerror = contadorTerror;
    maxNroTerror = numeroPeliculaAnterior;
    }

    //PROCESAR B)
    if(contMasculino > maxMasculino){
      maxMasculino = contMasculino;
      maxCalificacionEnMasculino = calificacion;
    }
    if(contFemenino > maxFemenino){
      maxFemenino = contFemenino;
      maxCalificacionEnFemenino = calificacion;
    }
  }




  //PROCESAR-LISTAR DATOS GLOBALES
  

  cout << "PUNTO A) MAX ALQUILER PARA LOS  GENEROS " << endl;
  cout << "Genero Accion: " << maxNroAccion << ". Genero Comedia: " << maxNroComedia << ". Genero Terror: " << maxNroTerror << endl;

  cout << endl << "PUNTO B" << endl;
  cout << "MASCULINO: " << maxCalificacionEnMasculino << endl;
  cout << "FEMENINO : " << maxCalificacionEnFemenino << endl;

  cout << endl << "PUNTO C" << endl;
  cout << "Porcentaje SOCIO TIPO 1: " << fixed << setprecision(2) << recaudacionSocio1 /(recaudacionSocio1 + recaudacionSocio2 + recaudacionSocio3) * 100 << endl;
  cout << "Porcentaje SOCIO TIPO 2: " << recaudacionSocio2 /(recaudacionSocio1 + recaudacionSocio2 + recaudacionSocio3) * 100 << endl;
  cout << "Porcentaje SOCIO TIPO 3: " << recaudacionSocio3 /(recaudacionSocio1 + recaudacionSocio2 + recaudacionSocio3) * 100 << endl;













  return 0;
}
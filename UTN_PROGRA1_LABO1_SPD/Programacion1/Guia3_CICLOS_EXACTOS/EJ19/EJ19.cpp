#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
 
  int n, contador = 0;

  cout << "Ingrese un numero: ";
  cin >> n; 
  for (int x = 1; x <= n; x++){
    if(n % x == 0)
    contador ++;
  }

  if (contador == 2)
      cout << "Es primo";
  return 0;
}
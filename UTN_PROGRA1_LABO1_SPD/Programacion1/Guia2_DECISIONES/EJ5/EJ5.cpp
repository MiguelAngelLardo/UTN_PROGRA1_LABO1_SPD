#include <iostream>

int main() {
    
    int importe;
    std::cin >> importe;
    
    if(importe > 500)
         importe = importe * 0.85;        
    else if (importe >= 100 && importe <= 500)
         importe = importe * 0.90;
    else
        importe = importe * 0.95;
    
    
    std::cout << importe;

    return 0;
}
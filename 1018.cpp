#include <iostream>

using namespace std;

int main()
{
    int n, aux;
    
    cin >> n;
    cout <<n <<endl;
    aux = n/100;
    cout << aux << " nota(s) de R$ 100,00" << endl;
    n = n%100;
    aux = n/50;
    cout << aux << " nota(s) de R$ 50,00" << endl;
    n = n%50;
    aux = n/20;
    cout << aux << " nota(s) de R$ 20,00" << endl;
    n = n%20;
    aux = n/10;
    cout << aux << " nota(s) de R$ 10,00" << endl;
    n = n%10;
    aux = n/5;
    cout << aux << " nota(s) de R$ 5,00" << endl;
    n = n%5;
    aux = n/2;
    cout << aux << " nota(s) de R$ 2,00" << endl;
    n = n%2;
    aux = n/1;
    cout << aux << " nota(s) de R$ 1,00" << endl;
    

    return 0;
}

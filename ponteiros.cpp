#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
#include <stdexcept>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");


    int *pi = new int;                         // alocação dinâmica de memória para um inteiro
    *pi = 1001;                                // atribuição de valor ao inteiro alocado dinamicamente
    std::cout << "Valor inteiro = " << *pi << endl; // exibição do valor do inteiro alocado dinamicamente
    std::cout << "Localização = " << pi << endl;   // exibição do endereço de memória onde o inteiro está alocado

    double *pd = new double;                           // alocação dinâmica de memória para um double
    *pd = 500.35;                                      // atribuição de valor ao double alocado dinamicamente
    std::cout << "Valor ponto-flutuante = " << *pd << endl; // exibição do valor do double alocado dinamicamente
    std::cout << "Localização = " << pd << endl
         << endl; // exibição do endereço de memória onde o double está alocado

    std::cout << " tamanho de pi = " << sizeof(pi) << endl;   // exibição do tamanho do ponteiro para inteiro
    std::cout << " tamanho de *pi = " << sizeof(*pi) << endl; // exibição do tamanho do inteiro alocado dinamicamente
    std::cout << " tamanho de pd = " << sizeof(pd) << endl;   // exibição do tamanho do ponteiro para double
    std::cout << " tamanho de *pd = " << sizeof(*pd) << endl; // exibição do tamanho do double alocado dinamicamente
}

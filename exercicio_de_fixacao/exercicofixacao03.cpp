// aula 15.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Conta Bancaria: 

#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
using namespace std;

class ContaBancaria
{
private:
    std::string titular;
    float saldo;

public:
    ContaBancaria(std::string titular, float saldo)
    {
        this->titular = titular;
        this->saldo = saldo;
    }

    void depositar(float valor)
    {
        this->saldo = this->saldo + valor;
    }

    void sacar(float valor)
    {
        this->saldo = this->saldo - valor;
    }

    void mostrarSaldo()
    {
        std::cout << "Titular: " << this->titular << std::endl;
        std::cout << "Saldo final: R$ " << this->saldo << std::endl;
    }
};

int main()
{
    std::setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    ContaBancaria conta1("Lucivaldo", 100);

    conta1.depositar(50);
    conta1.sacar(30);
    conta1.mostrarSaldo();

    return 0;
}
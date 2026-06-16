// aula 16.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 02

#include <iostream>
#include <string>

using namespace std;

class ContaBancaria
{
private:
    std::string titular;
    double saldo;

public:
    ContaBancaria(string t, double s) : titular(t), saldo(s) {}

    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }

    void depositar(double valor)
    {
        if (valor > 0)
        {
            saldo += valor;
            cout << "Deposito de R$ " << valor << " realizado" << endl;
        }
        else
        {
            cout << "Valor invalido para deposito!" << endl;
        }
    }

    bool sacar(double valor)
    {
        if (valor > 0 && valor <= saldo)
        {
            saldo -= valor;
            cout << "Saque realizado de R$ " << valor << endl;
            return true;
        }
        else
        {
            cout << "Saldo insuficiente ou valor invalido" << endl;
            return false;
        }
    }
};

int main()
{
    ContaBancaria conta("Lucivaldo", 1000.00);

    cout << "Titular: " << conta.getTitular() << endl;
    cout << "Saldo: R$ " << conta.getSaldo() << endl;

    conta.depositar(500.00);
    conta.sacar(200.00);
    conta.sacar(2000.00);

    cout << "Saldo Final: R$ " << conta.getSaldo() << endl;

    return 0;
}

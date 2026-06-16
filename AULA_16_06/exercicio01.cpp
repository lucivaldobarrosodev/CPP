// aula 16.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 01

# include <iostream>

using namespace std;

class  ContaBancaria {
public: 
string titular;
double saldo;

};

int main () {
ContaBancaria conta;
conta.titular = "João";
conta.saldo = 1000,00;

conta.saldo = -500,00;
cout << "saldo" << conta.saldo << endl;
return 0;

}
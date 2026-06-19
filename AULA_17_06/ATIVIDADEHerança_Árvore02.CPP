// aula 17.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 02 - Heranca e Arvore

#include <iostream>
using namespace std;

class Funcionario
{
protected:
    double salario;

public:
    Funcionario(double salario)
    {
        this->salario = salario;
    }

    void mostrarSalario()
    {
        cout << "Salario: R$ " << this->salario << endl;
    }
};

class Gerente : public Funcionario
{
public:
    Gerente(double salario) : Funcionario(salario)
    {
    }

    void mostrarSalario()
    {
        double salarioComBonus = this->salario + (this->salario * 0.20);

        cout << "Salario com bonus de 20%: R$ " << salarioComBonus << endl;
    }
};

int main()
{
    Funcionario funcionario1(2000);
    Gerente gerente1(3000);

    funcionario1.mostrarSalario();
    gerente1.mostrarSalario();

    return 0;
}

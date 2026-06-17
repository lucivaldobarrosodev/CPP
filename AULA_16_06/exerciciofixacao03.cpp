// aula 16.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio de Fixacao 03

#include <iostream>
#include <string>
using namespace std;

class Carro
{
private:
    string marca;
    int velocidade;

public:
    Carro(string marca)
    {
        this->marca = marca;
        this->velocidade = 0;
    }

    void acelerar(int valor)
    {
        this->velocidade = this->velocidade + valor;
    }

    void frear(int valor)
    {
        this->velocidade = this->velocidade - valor;

        if (this->velocidade < 0)
        {
            this->velocidade = 0;
        }
    }

    string getMarca()
    {
        return this->marca;
    }

    int getVelocidade()
    {
        return this->velocidade;
    }
};

int main()
{
    Carro carro1("Toyota");

    carro1.acelerar(80);
    carro1.frear(30);
    carro1.frear(100);

    cout << "Marca: " << carro1.getMarca() << endl;
    cout << "Velocidade: " << carro1.getVelocidade() << endl;

    return 0;
}

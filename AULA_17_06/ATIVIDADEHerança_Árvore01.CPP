// aula 17.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 01 - Heranca e Arvore

#include <iostream>
#include <string>
using namespace std;

class Veiculo
{
protected:
    string marca;

public:
    Veiculo(string marca)
    {
        this->marca = marca;
    }
};

class Carro : public Veiculo
{
private:
    string modelo;

public:
    Carro(string marca, string modelo) : Veiculo(marca)
    {
        this->modelo = modelo;
    }

    void exibir()
    {
        cout << "Marca: " << this->marca << endl;
        cout << "Modelo: " << this->modelo << endl;
    }
};

int main()
{
    Carro carro1("Toyota", "Corolla");

    carro1.exibir();

    return 0;
}

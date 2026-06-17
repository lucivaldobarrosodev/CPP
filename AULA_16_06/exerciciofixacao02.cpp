// aula 16.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio de Fixacao 02

#include <iostream>
#include <string>
using namespace std;

class Produto
{
private:
    string nome;
    double preco;

public:
    void setNome(string nome)
    {
        this->nome = nome;
    }

    void setPreco(double preco)
    {
        if (preco > 0)
        {
            this->preco = preco;
        }
        else
        {
            cout << "Preco invalido!" << endl;
        }
    }

    string getNome()
    {
        return this->nome;
    }

    double getPreco()
    {
        return this->preco;
    }
};

int main()
{
    Produto produto1;
    Produto produto2;

    produto1.setNome("Arroz");
    produto1.setPreco(25.50);

    produto2.setNome("Feijao");
    produto2.setPreco(8.90);

    cout << "Produto: " << produto1.getNome() << endl;
    cout << "Preco: " << produto1.getPreco() << endl;

    cout << "Produto: " << produto2.getNome() << endl;
    cout << "Preco: " << produto2.getPreco() << endl;

    return 0;
}

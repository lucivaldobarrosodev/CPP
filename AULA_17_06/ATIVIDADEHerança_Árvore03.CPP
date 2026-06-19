// aula 17.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 03 - Heranca e Arvore

#include <iostream>
#include <string>
using namespace std;

class Produto
{
protected:
    string nome;
    double preco;

public:
    Produto(string nome, double preco)
    {
        this->nome = nome;
        this->preco = preco;
    }

    void imprimirDados()
    {
        cout << "Nome: " << this->nome << endl;
        cout << "Preco: R$ " << this->preco << endl;
    }
};

class Livro : public Produto
{
private:
    string autor;

public:
    Livro(string nome, double preco, string autor) : Produto(nome, preco)
    {
        this->autor = autor;
    }

    void imprimirDados()
    {
        cout << "Livro" << endl;
        cout << "Nome: " << this->nome << endl;
        cout << "Preco: R$ " << this->preco << endl;
        cout << "Autor: " << this->autor << endl;
    }
};

class Eletronico : public Produto
{
private:
    string marca;

public:
    Eletronico(string nome, double preco, string marca) : Produto(nome, preco)
    {
        this->marca = marca;
    }

    void imprimirDados()
    {
        cout << "Eletronico" << endl;
        cout << "Nome: " << this->nome << endl;
        cout << "Preco: R$ " << this->preco << endl;
        cout << "Marca: " << this->marca << endl;
    }
};

int main()
{
    Livro livro1("Dom Casmurro", 35.50, "Machado de Assis");
    Livro livro2("Iracema", 28.90, "Jose de Alencar");

    Eletronico eletronico1("Celular", 1500.00, "Samsung");
    Eletronico eletronico2("Notebook", 3500.00, "Dell");

    livro1.imprimirDados();
    livro2.imprimirDados();

    eletronico1.imprimirDados();
    eletronico2.imprimirDados();

    return 0;
}

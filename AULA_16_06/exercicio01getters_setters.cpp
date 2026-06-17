// aula 16.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 01 - Getters e Setters

#include <iostream>
#include <string>
using namespace std;

class Restaurante
{
private:
    string nome;
    string cardapio[10];
    int quantidadePratos;

public:
    Restaurante(string nome)
    {
        this->nome = nome;
        this->quantidadePratos = 0;
    }

    string getNome()
    {
        return this->nome;
    }

    void setNome(string novo_nome)
    {
        if (novo_nome != "")
        {
            this->nome = novo_nome;
        }
    }

    void adicionarPrato(string prato)
    {
        int existe = 0;

        for (int i = 0; i < this->quantidadePratos; i++)
        {
            if (this->cardapio[i] == prato)
            {
                existe = 1;
            }
        }

        if (existe == 0)
        {
            this->cardapio[this->quantidadePratos] = prato;
            this->quantidadePratos++;
        }
    }

    void listarCardapio()
    {
        cout << "Cardapio:" << endl;

        for (int i = 0; i < this->quantidadePratos; i++)
        {
            cout << this->cardapio[i] << endl;
        }
    }

    void atenderCliente(string nome_cliente, string prato)
    {
        int existe = 0;

        for (int i = 0; i < this->quantidadePratos; i++)
        {
            if (this->cardapio[i] == prato)
            {
                existe = 1;
            }
        }

        if (existe == 1)
        {
            cout << "Pedido confirmado para " << nome_cliente << ": " << prato << endl;
        }
        else
        {
            cout << "O prato " << prato << " nao existe no cardapio." << endl;
        }
    }
};

int main()
{
    Restaurante restaurante("Sabor Caseiro");

    restaurante.adicionarPrato("Arroz com frango");
    restaurante.adicionarPrato("Macarrao");
    restaurante.adicionarPrato("Feijoada");

    cout << "Restaurante: " << restaurante.getNome() << endl;
    restaurante.listarCardapio();

    restaurante.atenderCliente("Joao", "Macarrao");
    restaurante.atenderCliente("Maria", "Pizza");

    restaurante.setNome("Sabor da Casa");
    cout << "Novo nome: " << restaurante.getNome() << endl;

    return 0;
}

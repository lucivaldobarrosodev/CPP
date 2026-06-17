// aula 16.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 02 - Getters e Setters

#include <iostream>
#include <string>
using namespace std;

class Biblioteca
{
private:
    string nome;
    string livros[10];
    int quantidadeLivros;

public:
    Biblioteca(string nome)
    {
        this->nome = nome;
        this->quantidadeLivros = 0;
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

    void adicionarLivro(string titulo)
    {
        int existe = 0;

        for (int i = 0; i < this->quantidadeLivros; i++)
        {
            if (this->livros[i] == titulo)
            {
                existe = 1;
            }
        }

        if (titulo != "" && existe == 0)
        {
            this->livros[this->quantidadeLivros] = titulo;
            this->quantidadeLivros++;
        }
    }

    void listarLivros()
    {
        if (this->quantidadeLivros == 0)
        {
            cout << "Nenhum livro cadastrado." << endl;
        }
        else
        {
            cout << "Livros cadastrados:" << endl;

            for (int i = 0; i < this->quantidadeLivros; i++)
            {
                cout << this->livros[i] << endl;
            }
        }
    }
};

int main()
{
    Biblioteca biblioteca("Biblioteca Central");

    biblioteca.adicionarLivro("Dom Casmurro");
    biblioteca.adicionarLivro("O Cortico");
    biblioteca.adicionarLivro("Iracema");
    biblioteca.adicionarLivro("Dom Casmurro");

    cout << "Biblioteca: " << biblioteca.getNome() << endl;
    biblioteca.listarLivros();

    biblioteca.setNome("Biblioteca da Escola");
    cout << "Novo nome: " << biblioteca.getNome() << endl;

    return 0;
}

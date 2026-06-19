// aula 18.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Desafio 01 - Floresta Encantada

#include <iostream>
#include <string>
using namespace std;

class Personagem
{
protected:
    string nome;
    int nivelPoder;
    string tipo;

public:
    Personagem(string nome, int nivelPoder, string tipo)
    {
        this->nome = nome;
        this->nivelPoder = nivelPoder;
        this->tipo = tipo;
    }

    int getNivelPoder()
    {
        return this->nivelPoder;
    }

    virtual void exibir()
    {
        cout << "Nome: " << this->nome << endl;
        cout << "Nivel de poder: " << this->nivelPoder << endl;
        cout << "Tipo: " << this->tipo << endl;
    }
};

class ChefeFloresta : public Personagem
{
private:
    string reino;

public:
    ChefeFloresta(string nome, int nivelPoder, string tipo, string reino) : Personagem(nome, nivelPoder, tipo)
    {
        this->reino = reino;
    }

    void exibir()
    {
        cout << "Nome: " << this->nome << endl;
        cout << "Nivel de poder: " << this->nivelPoder << endl;
        cout << "Tipo: " << this->tipo << endl;
        cout << "Reino: " << this->reino << endl;
    }
};

class No
{
public:
    Personagem* personagem;
    No* esquerda;
    No* direita;

    No(Personagem* personagem)
    {
        this->personagem = personagem;
        this->esquerda = NULL;
        this->direita = NULL;
    }
};

class ArvoreFloresta
{
private:
    No* raiz;

    No* adicionar(No* atual, Personagem* personagem)
    {
        if (atual == NULL)
        {
            return new No(personagem);
        }

        if (personagem->getNivelPoder() < atual->personagem->getNivelPoder())
        {
            atual->esquerda = adicionar(atual->esquerda, personagem);
        }
        else
        {
            atual->direita = adicionar(atual->direita, personagem);
        }

        return atual;
    }

    void percorrerEmOrdem(No* atual)
    {
        if (atual != NULL)
        {
            percorrerEmOrdem(atual->esquerda);

            atual->personagem->exibir();
            cout << endl;

            percorrerEmOrdem(atual->direita);
        }
    }

    void apagar(No* atual)
    {
        if (atual != NULL)
        {
            apagar(atual->esquerda);
            apagar(atual->direita);
            delete atual->personagem;
            delete atual;
        }
    }

public:
    ArvoreFloresta()
    {
        this->raiz = NULL;
    }

    ~ArvoreFloresta()
    {
        apagar(this->raiz);
    }

    void adicionarPersonagem(Personagem* personagem)
    {
        this->raiz = adicionar(this->raiz, personagem);
    }

    void percorrerEmOrdem()
    {
        percorrerEmOrdem(this->raiz);
    }
};

int main()
{
    ArvoreFloresta arvore;

    arvore.adicionarPersonagem(new Personagem("Lupi", 30, "Animal"));
    arvore.adicionarPersonagem(new Personagem("Mago Merlin", 80, "Mago"));
    arvore.adicionarPersonagem(new ChefeFloresta("Dragao", 100, "Chefe", "Reino do Fogo"));
    arvore.adicionarPersonagem(new Personagem("Fada Luna", 45, "Fada"));
    arvore.adicionarPersonagem(new ChefeFloresta("Rainha Elfa", 90, "Chefe", "Reino das Folhas"));
    arvore.adicionarPersonagem(new Personagem("Guerreiro Thorin", 60, "Guerreiro"));

    cout << "Personagens do menos poderoso para o mais poderoso:" << endl;
    cout << endl;

    arvore.percorrerEmOrdem();

    return 0;
}

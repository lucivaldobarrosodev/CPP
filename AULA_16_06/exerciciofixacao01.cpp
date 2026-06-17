// aula 16.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio de Fixacao 01

#include <iostream>
#include <string>
using namespace std;

class Aluno
{
private:
    string nome;
    double nota;

public:
    Aluno(string nome)
    {
        this->nome = nome;
        this->nota = 0;
    }

    void setNota(double nota)
    {
        if (nota >= 0 && nota <= 10)
        {
            this->nota = nota;
        }
        else
        {
            cout << "Nota invalida!" << endl;
        }
    }

    double getNota()
    {
        return this->nota;
    }

    string getNome()
    {
        return this->nome;
    }
};

int main()
{
    Aluno aluno1("Ana");

    aluno1.setNota(8);

    cout << "Aluno: " << aluno1.getNome() << endl;
    cout << "Nota: " << aluno1.getNota() << endl;

    return 0;
}

// aula 16.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 03 - Getters e Setters

#include <iostream>
#include <string>
using namespace std;

class Aluno
{
private:
    string nome;
    int idade;
    string curso;

public:
    Aluno()
    {
        this->nome = "";
        this->idade = 0;
        this->curso = "";
    }

    Aluno(string nome, int idade, string curso)
    {
        this->setNome(nome);
        this->setIdade(idade);
        this->setCurso(curso);
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

    int getIdade()
    {
        return this->idade;
    }

    void setIdade(int nova_idade)
    {
        if (nova_idade > 0)
        {
            this->idade = nova_idade;
        }
    }

    string getCurso()
    {
        return this->curso;
    }

    void setCurso(string novo_curso)
    {
        if (novo_curso != "")
        {
            this->curso = novo_curso;
        }
    }

    string apresentar()
    {
        return "Nome: " + this->nome + " | Idade: " + to_string(this->idade) + " | Curso: " + this->curso;
    }
};

class Escola
{
private:
    string nome;
    Aluno alunos[10];
    int quantidadeAlunos;

public:
    Escola(string nome)
    {
        this->nome = nome;
        this->quantidadeAlunos = 0;
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

    void adicionarAluno(Aluno aluno)
    {
        this->alunos[this->quantidadeAlunos] = aluno;
        this->quantidadeAlunos++;
    }

    void listarAlunos()
    {
        if (this->quantidadeAlunos == 0)
        {
            cout << "Nenhum aluno matriculado." << endl;
        }
        else
        {
            cout << "Alunos matriculados:" << endl;

            for (int i = 0; i < this->quantidadeAlunos; i++)
            {
                cout << this->alunos[i].apresentar() << endl;
            }
        }
    }
};

int main()
{
    Escola escola("Escola Futuro");

    Aluno aluno1("Joao", 20, "Informatica");
    Aluno aluno2("Maria", 18, "Administracao");

    escola.adicionarAluno(aluno1);
    escola.adicionarAluno(aluno2);

    cout << "Escola: " << escola.getNome() << endl;
    escola.listarAlunos();

    aluno1.setCurso("Desenvolvimento de Sistemas");
    aluno1.setIdade(21);

    cout << aluno1.apresentar() << endl;

    return 0;
}

// aula 15.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 05

#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
using namespace std;

class Aluno
{
private:
    std::string nome;
    double nota1;
    double nota2;

public:
    Aluno(std::string nome, double nota1, double nota2)
    {
        this->nome = nome;
        this->nota1 = nota1;
        this->nota2 = nota2;
    }

    double calcularMedia()
    {
        return (this->nota1 + this->nota2) / 2;
    }

    void mostrarResultado()
    {
        double media = calcularMedia();

        std::cout << "Aluno: " << this->nome << std::endl;
        std::cout << "Media: " << media << std::endl;

        if (media >= 7)
        {
            std::cout << "Aprovado" << std::endl;
        }
        else
        {
            std::cout << "Reprovado" << std::endl;
        }
    }
};

int main()
{
    std::setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    Aluno aluno1("Lucivaldo", 8, 9);
    Aluno aluno2("Maria", 5, 6);

    aluno1.mostrarResultado();
    aluno2.mostrarResultado();

    return 0;
}

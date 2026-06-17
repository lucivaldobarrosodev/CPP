// aula 15.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 02

#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
using namespace std;




   class Pessoa
{
private:
    std::string nome;
    int idade;

public:
    Pessoa(std::string nome, int idade)
    {
        this->nome = nome;
        this->idade = idade;
    }

    void pessoa()
    {
        std::cout << this->nome << " e o seu nome" << std::endl;
        std::cout << this->idade << " anos" << std::endl;
    }
};

Pessoa p1("Lucivaldo", 20);
Pessoa p2("Maria", 18);
  
    int main()
{
std::setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    p1.pessoa();
    p2.pessoa();
  
    
    return 0;
}
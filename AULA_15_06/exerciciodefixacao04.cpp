// aula 15.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio Cachorro

#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
using namespace std;

class Cachorro
{
private:
    std::string nome;
    std::string raca;

public:
    Cachorro(std::string nome, std::string raca)
    {
        this->nome = nome;
        this->raca = raca;
    }

    void latir()
    {
        std::cout << "Au Au! O cachorro " << this->nome << " esta latindo." << std::endl;
    }
};

int main()
{
    std::setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    Cachorro cachorro1("Rex", "Pastor Alemao");

    cachorro1.latir();

    return 0;
}

// aula 15.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 06

#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
using namespace std;

class Animal
{
private:
    std::string especie;
    std::string som;

public:
    Animal(std::string especie, std::string som)
    {
        this->especie = especie;
        this->som = som;
    }

    void emitir_som()
    {
        std::cout << "O animal " << this->especie << " faz " << this->som << std::endl;
    }
};

int main()
{
    std::setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    Animal animal1("Cachorro", "Au au");

    animal1.emitir_som();

    return 0;
}

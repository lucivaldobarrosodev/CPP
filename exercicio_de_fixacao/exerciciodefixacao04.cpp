// aula 15.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// chamada animal

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
        std::cout << "Este animal " << this->especie << " faz " << this->som << std::endl;
    }
};

Animal animal1("Cachorro", "Au au");
Animal animal2("gato", "miau miau");

    int main()
{
    std::setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    animal1.emitir_som();
    animal2.emitir_som();

    return 0;
}

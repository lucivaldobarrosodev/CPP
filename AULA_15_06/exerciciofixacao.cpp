// aula 15.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo

#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
using namespace std;

class Semaforo
{
private:
    std::string acao;

public :
Semaforo(std::string nome){
     this->acao = acao;
}

void siga()
{
    std::cout << this->acao << "Pode Seguir" << std::endl;
}
void atencao()
{
    std::cout << this->acao << "Tenha atenção" << std::endl;
}
void pare()
{
    std::cout << this->acao << "Pare" << std::endl;
}
};

    Semaforo verde("siga");
    Semaforo amrarelo("atenacao");
    Semaforo vermelho("pare");

    int main()
{
std::setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    verde.siga();
    amrarelo.atencao();
    vermelho.pare();
    
    return 0;
}
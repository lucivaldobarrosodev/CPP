// aula 16.06.2026
// Aluno: Lucivaldo oliveira Barroso
// Turma: Tarde
//  Aula: Poo
// Exercicio 03

#include <iostream>
#include <string>

using namespace std;

class BolaoCopa
{
private:
    std::string jogador;
    double aposta;

public:
    BolaoCopa(string j, double a) : jogador(j), aposta(a) {}

    string getJogador() const { return jogador; }
    double getAposta() const { return aposta; }
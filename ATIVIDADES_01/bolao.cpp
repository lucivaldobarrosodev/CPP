//ALUNO: LUCIVALDO OLIVEIRA BARROSO
//TURMA: TARDE

#include <iostream>
#include <string>
#include <iomanip>
#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

struct Jogo {
    string timeA;
    string timeB;
    int golsA;
    int golsB;
};

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF8");
    #endif
    
    // Cadastro dos 5 jogos com placar real
    Jogo jogos[5] = {
        {"BRA", "EGT", 3, 0},
        {"RSA", "MAR", 1, 1},
        {"FRA", "ARG", 1, 2},
        {"GER", "COS", 4, 2},
        {"MEX", "AFS", 2, 0}
    };
    
    int pontos = 0;
    string nome;
    
    cout << "=== Sistema de Apostas ===\n";
    cout << "Digite seu nome: ";
    cin >> nome;
    cout << "Tente acertar o placar dos 5 jogos!\n\n";
    
    for (int i = 0; i < 5; i++) {
        int palpiteA, palpiteB;
        cout << jogos[i].timeA << " x " << jogos[i].timeB << endl;
        cout << "Digite o placar para " << jogos[i].timeA << ": ";
        cin >> palpiteA;
        cout << "Digite o placar para " << jogos[i].timeB << ": ";
        cin >> palpiteB;

        if (palpiteA == jogos[i].golsA && palpiteB == jogos[i].golsB) {
            cout << "✅ Placar exato! +10 pontos\n\n";
            pontos += 10;
        } else {
            // Verifica vencedor ou empate
            int resultadoReal = (jogos[i].golsA > jogos[i].golsB) ? 1 :
                                (jogos[i].golsA < jogos[i].golsB) ? -1 : 0;
            int resultadoPalpite = (palpiteA > palpiteB) ? 1 :
                                   (palpiteA < palpiteB) ? -1 : 0;

            if (resultadoReal == resultadoPalpite) {
                cout << "⚽ Acertou o vencedor ou empate! +5 pontos\n\n";
                pontos += 5;
            } else {
                cout << "❌ Errou! Placar real: "
                     << jogos[i].golsA << " x " << jogos[i].golsB << "\n\n";
            }
        }
    }

    // Tabela de pontuação (Garante que esta parte esteja dentro do main)
    cout << "=== Tabela de Pontuação ===\n";
    cout << left << setw(15) << "Apostador" << setw(10) << "Pontos" << endl;
    cout << "---------------------------------\n";
    cout << left << setw(15) << nome << setw(10) << pontos << endl;

    return 0;
}
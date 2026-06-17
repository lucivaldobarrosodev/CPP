// ALUNO: LUCIVALDO OLIVEIRA BARROSO
// TURMA: TARDE
// Bolao da Copa 2026 - Atividade Pratica 2

#include <iostream>
#include <string>
#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

class Jogo
{
public:
    string timeCasa;
    string timeFora;
    int golsCasa;
    int golsFora;

    Jogo()
    {
        this->timeCasa = "";
        this->timeFora = "";
        this->golsCasa = 0;
        this->golsFora = 0;
    }

    Jogo(string timeCasa, string timeFora, int golsCasa, int golsFora)
    {
        this->timeCasa = timeCasa;
        this->timeFora = timeFora;
        this->golsCasa = golsCasa;
        this->golsFora = golsFora;
    }

    void exibir()
    {
        cout << this->timeCasa << " " << this->golsCasa << " x " << this->golsFora << " " << this->timeFora << endl;
    }
};

class Apostador
{
private:
    string nome;
    int pontuacao;
    Jogo* palpites;
    int qtdJogos;

public:
    Apostador()
    {
        this->nome = "";
        this->pontuacao = 0;
        this->qtdJogos = 4;
        this->palpites = new Jogo[this->qtdJogos];
    }

    ~Apostador()
    {
        delete[] this->palpites;
    }

    void cadastrarPalpites(Jogo jogos[], int n)
    {
        cout << "\nDigite o nome do apostador: ";
        cin >> this->nome;

        cout << "\nPalpites de " << this->nome << endl;

        for (int i = 0; i < n; i++)
        {
            this->palpites[i].timeCasa = jogos[i].timeCasa;
            this->palpites[i].timeFora = jogos[i].timeFora;

            cout << "\nJogo " << i + 1 << ": " << jogos[i].timeCasa << " x " << jogos[i].timeFora << endl;
            cout << "Gols do " << jogos[i].timeCasa << ": ";
            cin >> this->palpites[i].golsCasa;
            cout << "Gols do " << jogos[i].timeFora << ": ";
            cin >> this->palpites[i].golsFora;
        }
    }

    void calcularPontuacao(Jogo jogos[], int n)
    {
        this->pontuacao = 0;

        for (int i = 0; i < n; i++)
        {
            if (this->palpites[i].golsCasa == jogos[i].golsCasa && this->palpites[i].golsFora == jogos[i].golsFora)
            {
                this->pontuacao = this->pontuacao + 10;
            }
            else
            {
                int resultadoReal = 0;
                int resultadoPalpite = 0;

                if (jogos[i].golsCasa > jogos[i].golsFora)
                {
                    resultadoReal = 1;
                }
                else
                {
                    if (jogos[i].golsCasa < jogos[i].golsFora)
                    {
                        resultadoReal = -1;
                    }
                }

                if (this->palpites[i].golsCasa > this->palpites[i].golsFora)
                {
                    resultadoPalpite = 1;
                }
                else
                {
                    if (this->palpites[i].golsCasa < this->palpites[i].golsFora)
                    {
                        resultadoPalpite = -1;
                    }
                }

                if (resultadoReal == resultadoPalpite)
                {
                    this->pontuacao = this->pontuacao + 5;
                }
                else
                {
                    int diferencaReal = jogos[i].golsCasa - jogos[i].golsFora;
                    int diferencaPalpite = this->palpites[i].golsCasa - this->palpites[i].golsFora;

                    if (diferencaReal < 0)
                    {
                        diferencaReal = diferencaReal * -1;
                    }

                    if (diferencaPalpite < 0)
                    {
                        diferencaPalpite = diferencaPalpite * -1;
                    }

                    if (diferencaReal == diferencaPalpite)
                    {
                        this->pontuacao = this->pontuacao + 2;
                    }
                }
            }
        }
    }

    string getNome()
    {
        return this->nome;
    }

    int getPontuacao()
    {
        return this->pontuacao;
    }
};

void mostrarMenu()
{
    cout << "\n=== BOLAO DA COPA 2026 ===" << endl;
    cout << "1 - Registrar resultados oficiais dos jogos" << endl;
    cout << "2 - Registrar apostas dos jogadores" << endl;
    cout << "3 - Calcular pontuacao e exibir ranking" << endl;
    cout << "4 - Sair do programa" << endl;
    cout << "Escolha uma opcao: ";
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF8");
#endif

    Jogo jogosReais[4];
    Apostador* apostadores = new Apostador[3];

    int opcao = 0;
    int resultadosRegistrados = 0;
    int apostasRegistradas = 0;

    while (opcao != 4)
    {
        mostrarMenu();
        cin >> opcao;

        if (opcao == 1)
        {
            jogosReais[0] = Jogo("BRA", "EGT", 3, 0);
            jogosReais[1] = Jogo("RSA", "MAR", 1, 1);
            jogosReais[2] = Jogo("FRA", "ARG", 1, 2);
            jogosReais[3] = Jogo("GER", "COS", 4, 2);

            resultadosRegistrados = 1;

            cout << "\nResultados oficiais registrados:" << endl;

            for (int i = 0; i < 4; i++)
            {
                cout << "Jogo " << i + 1 << ": ";
                jogosReais[i].exibir();
            }
        }
        else
        {
            if (opcao == 2)
            {
                if (resultadosRegistrados == 1)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        apostadores[i].cadastrarPalpites(jogosReais, 4);
                    }

                    apostasRegistradas = 1;
                }
                else
                {
                    cout << "Registre primeiro os resultados oficiais dos jogos." << endl;
                }
            }
            else
            {
                if (opcao == 3)
                {
                    if (resultadosRegistrados == 1 && apostasRegistradas == 1)
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            apostadores[i].calcularPontuacao(jogosReais, 4);
                        }

                        int ranking[3] = {0, 1, 2};

                        for (int i = 0; i < 2; i++)
                        {
                            for (int j = i + 1; j < 3; j++)
                            {
                                if (apostadores[ranking[j]].getPontuacao() > apostadores[ranking[i]].getPontuacao())
                                {
                                    int aux = ranking[i];
                                    ranking[i] = ranking[j];
                                    ranking[j] = aux;
                                }
                            }
                        }

                        cout << "\n=== RANKING DO BOLAO ===" << endl;
                        cout << "Colocacao - Nome - Pontuacao" << endl;

                        for (int i = 0; i < 3; i++)
                        {
                            cout << i + 1 << " - " << apostadores[ranking[i]].getNome() << " - " << apostadores[ranking[i]].getPontuacao() << " pontos" << endl;
                        }
                    }
                    else
                    {
                        cout << "Registre os resultados e as apostas primeiro." << endl;
                    }
                }
                else
                {
                    if (opcao != 4)
                    {
                        cout << "Opcao invalida." << endl;
                    }
                }
            }
        }
    }

    delete[] apostadores;

    return 0;
}

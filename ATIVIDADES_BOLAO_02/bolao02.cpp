// ALUNO: LUCIVALDO OLIVEIRA BARROSO
// TURMA: TARDE

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

    void exibir()
    {
        cout << timeCasa << " " << golsCasa << " x " << golsFora << " " << timeFora << endl;
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

    void cadastrarNome(string nome)
    {
        this->nome = nome;
    }

    void cadastrarPalpites(Jogo jogos[], int n)
    {
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

    void liberarMemoria()
    {
        delete[] this->palpites;
    }
};

void mostrarMenu()
{
    cout << "\n=== SISTEMA DE BOLAO DA COPA ===" << endl;
    cout << "1 - Cadastrar resultados dos jogos" << endl;
    cout << "2 - Cadastrar palpites dos apostadores" << endl;
    cout << "3 - Calcular pontuacao" << endl;
    cout << "4 - Exibir ranking" << endl;
    cout << "0 - Sair" << endl;
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

    int opcao = -1;
    int resultadosCadastrados = 0;
    int palpitesCadastrados = 0;
    int pontuacaoCalculada = 0;

    apostadores[0].cadastrarNome("Joao");
    apostadores[1].cadastrarNome("Maria");
    apostadores[2].cadastrarNome("Pedro");

    while (opcao != 0)
    {
        mostrarMenu();
        cin >> opcao;

        if (opcao == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                cout << "\nJogo " << i + 1 << endl;
                cout << "Time da casa: ";
                cin >> jogosReais[i].timeCasa;
                cout << "Time de fora: ";
                cin >> jogosReais[i].timeFora;
                cout << "Gols do " << jogosReais[i].timeCasa << ": ";
                cin >> jogosReais[i].golsCasa;
                cout << "Gols do " << jogosReais[i].timeFora << ": ";
                cin >> jogosReais[i].golsFora;
            }

            resultadosCadastrados = 1;
            pontuacaoCalculada = 0;
        }
        else
        {
            if (opcao == 2)
            {
                if (resultadosCadastrados == 1)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        apostadores[i].cadastrarPalpites(jogosReais, 4);
                    }

                    palpitesCadastrados = 1;
                    pontuacaoCalculada = 0;
                }
                else
                {
                    cout << "Cadastre primeiro os resultados dos jogos." << endl;
                }
            }
            else
            {
                if (opcao == 3)
                {
                    if (resultadosCadastrados == 1 && palpitesCadastrados == 1)
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            apostadores[i].calcularPontuacao(jogosReais, 4);
                        }

                        pontuacaoCalculada = 1;
                        cout << "Pontuacao calculada." << endl;
                    }
                    else
                    {
                        cout << "Cadastre os resultados e os palpites primeiro." << endl;
                    }
                }
                else
                {
                    if (opcao == 4)
                    {
                        if (pontuacaoCalculada == 1)
                        {
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

                            for (int i = 0; i < 3; i++)
                            {
                                cout << i + 1 << " - " << apostadores[ranking[i]].getNome() << " - " << apostadores[ranking[i]].getPontuacao() << " pontos" << endl;
                            }
                        }
                        else
                        {
                            cout << "Calcule a pontuacao primeiro." << endl;
                        }
                    }
                    else
                    {
                        if (opcao != 0)
                        {
                            cout << "Opcao invalida." << endl;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        apostadores[i].liberarMemoria();
    }

    delete[] apostadores;

    return 0;
}

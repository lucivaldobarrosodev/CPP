#include <iostream>
#include <string>
#include <locale.h>
#include <Windows.h>
#include <stdexcept>
using namespace std;
int main()
{
    string login, senha;
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    std::cout << "Digite seu login: ";
    std::cin >> login;
    std::cout << "Digite sua senha: ";
    std::cin >> senha;
    // para fazer laço pada dar três tentaivas para o usuario digitar o login e senha corretos
    int tentativas = 0;
    const int tentativas_maximas = 3;
    // setlocale(LC_ALL, "Portuguese");

    try
    {
        while (login != "admin" || senha != "1234") // condição é executavel enquanto o login for diferente de "admin" ou a senha for diferente de "1234" (verdadeira)
        {
            std::cout << "Login ou senha incorretos!" << endl;
            std::cout << "Digite seu login: ";

            cin >> login;
            std::cout << "Digite sua senha: ";
            cin >> senha;
            tentativas++;
            if (tentativas >= tentativas_maximas)
            {
                std::throw runtime_error("Numero maximo de tentativas excedido!");
                return 1; // encerra o programa com código de erro
            }

            std::cout << "Login ou senha incorretos!" << endl;

            std::cout << "Digite seu login: ";
            cin >> login;

            std::cout << "Digite sua senha: ";
            cin >> senha;
        }
        std::cout << "Login bem-sucedido!" << endl;
    }
}
catch (const exception &erro)
{
    std::cout << "Erro: " << erro.what() << endl;
    return 1;
}
#include <iostream>
#include <clocale>
#include <locale.h>
#include <Windows.h>

int main() {
    // Configura o terminal para exibir acentos corretamente
    std::setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, ".UTF-8");

    int termos;
    unsigned long long t1 = 0, t2 = 1, proximoTermo = 0;

    std::cout << "Quantos termos da sequência de Fibonacci você quer ver?: ";
    std::cin >> termos;

    std::cout << "Sequência de Fibonacci: ";

    for (int i = 1; i <= termos; ++i) {
        // Imprime o termo atual
        if (i == 1) {
            std::cout << t1;
            continue;
        }
        if (i == 2) {
            std::cout << ", " << t2;
            continue;
        }
        
        // Calcula o próximo termo e atualiza as variáveis
        proximoTermo = t1 + t2;
        t1 = t2;
        t2 = proximoTermo;
        
        std::cout << ", " << proximoTermo;
    }
    
    std::cout << std::endl;
    return 0;
}

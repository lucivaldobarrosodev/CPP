#include <iostream>
#include <clocale>

int fatorial(int n) {
    if (n == 1) {
        return 1; // Fatorial de 1 é 1
    }
    return n * fatorial(n - 1); // Chamada recursiva
}

int main() {
    // Configura o terminal para exibir acentos corretamente
    std::setlocale(LC_ALL, "");

    int numero;
    unsigned long long fatorial = 1; // Suporta números maiores

    std::cout << "Digite um número inteiro positivo: ";
    std::cin >> numero;

    if (numero < 0) {
        std::cout << "Erro: Não existe fatorial de número negativo!" << std::endl;
    } else {
        // Multiplica o valor acumulado de 1 até o número digitado
        for (int i = 1; i <= numero; ++i) {
            fatorial *= i;
        }
        std::cout << "O fatorial de " << numero << " é: " << fatorial << std::endl;
    }

    return 0;
}

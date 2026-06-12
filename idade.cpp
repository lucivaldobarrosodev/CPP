#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int idade;
    cout << "Digite sua idade: ";
    cin >> idade;
    cout << "sua idade é " << idade << " anos" << endl;
    cout << fixed << setetprecision(2) << "sua idade em meses é " << idade * 12 << " meses" << endl;
    return 0;
}
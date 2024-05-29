#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n; 
    string cod, ghici;
    cin >> cod >> ghici;

    //tablouri pentru a număra frecvența apariției fiecărui caracter
    int contor_cod[26] = {0}; 
    int contor_ghici[26] = {0}; 

    //variabile pentru a număra potrivirile exacte și potrivirile de culoare.
    int potriviri_exacte = 0;
    int potriviri_culoare = 0;

    for (int i = 0; i < n; ++i) {
        //verific dacă caracterele de la aceeași poziție din cele două șiruri sunt identice.
        if (cod[i] == ghici[i]) {
            // dacă sunt identice, cresc potrivirile
            potriviri_exacte++;
        } else {
            // dacă nu sunt identice, actualizez contorul
            contor_cod[cod[i] - 'A']++; 
            contor_ghici[ghici[i] - 'A']++;
        }
    }
        // calculează potrivirile de culoare pentru fiecare literă din alfabet. 
        // potrivirea de culoare înseamnă că acel caracter apare în ambele șiruri, dar nu la aceeași poziție. 
        // Se adaugă numărul minim de apariții ale caracterului în cele două șiruri.
    for (int i = 0; i < 26; ++i) {
        potriviri_culoare += min(contor_cod[i], contor_ghici[i]);
    }
    
    cout << potriviri_exacte << " " << potriviri_culoare << endl;

    return 0;
}

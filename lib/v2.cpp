/**
 * Fichier Application
 * Cible d'exécution : Windows
 * Nom du fichier : v2
 * Description : Programme pour trouver deux carrés dont la somme est égale à un nombre donné.
 * Dépendances : <iostream>, <Windows.h>, <cmath>, <chrono>
 * Auteur : [Votre nom ou pseudo]
 **/

#include <iostream>
#include <Windows.h> // Affichage des caractères UTF-8 dans la console
#include <cmath>
#include <chrono>
using namespace std::chrono;
using namespace std;

#define limiteRecherche 0xFFFF // Limite de recherche pour les nombres non signés sur 32 bits.

int main()
{
    SetConsoleOutputCP(CP_UTF8); // Activation de l'affichage des caractères UTF-8 dans la console
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    int nbSaisi;
    cout << "Entrez la valeur à tester : ";
    cin >> nbSaisi;

    int a;
    int b;

    auto start = high_resolution_clock::now();

    int carre = sqrt(nbSaisi / 2);
    int sommeC = 0;
    int cpt = 0;

    for (a = 0; a < nbSaisi; a++)
    {
        for (b = 0; b < nbSaisi; b++)
        {
            sommeC = (a * a) + (b * b);
            if (sommeC == nbSaisi)
            {
                cout << "Le nombre que vous avez choisi peut aussi s'écrire sous la forme : " << a << "²"
                     << " + " << b << "²" << endl;
                cpt = cpt + 1;
            }
        }
    }

    if (cpt <= 0)
    {
        cout << "Le nombre choisi n'est pas la somme de deux carrés" << endl;
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Et cela en " << duration.count() << "μs" << endl;

    return 0;
}

//------------------------------------------------------------------------------
// Labo           : labo_03_Taxi
// Fichier        : labo_03_Taxi.cpp
// Auteur(s)      : Klasen Leonard & Rodrigues Fraga Brian
// Date           : 11.10.2022
// But            : Un programme qui calcule le prix d’une course en € en taxi
// Modifications  :
// Remarque(s)    :
//------------------------------------------------------------------------------

#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    // ================ Déclaration de variables ===============================
    const double TAXE_CHARGE         = 5.00;
    const double TAXE_BAGAGE         = 2.60;
    const double TARIF_MINUTE_JOUR   = 1.00;
    const double TARIF_MINUTES_NUIT  = 1.60;

    const int width = 22;           //Largeur de l'affichage "Les conditions".
    const int widthCommande = 27;   //Largeur de l'affichage "Votre commande".
    const int widthTicket = 7;      //Largeur de l'affichage "Votre ticket".

    double prixTrajet;
    double prixBagage;
    double prixCourse;

    int heureDepart;
    int distanceParcourue;
    int vitesse;
    int nbrBagage;
    int tempsTrajet;

    cout << fixed << setprecision(2); //défini le nombre de décimaux à 2.

    // ================ Début du programme =====================================

    // ================ Voici les conditions ===================================
    cout << "Bonjour, ce programme affiche les conditions du taxi"  << endl
         << "Voici les conditions : "   << endl
         << "=========================" << endl

         << setw(width) << left << "- Prise en charge  : " << right << TAXE_CHARGE        << endl
         << setw(width) << left << "- Supp par bagage  : " << right << TAXE_BAGAGE        << endl
         << setw(width) << left << "- Tarif/min (jour) : " << right << TARIF_MINUTE_JOUR  << endl
         << setw(width) << left << "- Tarif/min (nuit) : " << right << TARIF_MINUTES_NUIT << endl
         << setw(width) << left << "- Prise en charge  : " << right << TAXE_CHARGE        << endl
         << setw(width) << left << "- Heures de jour   : " << right << "[8 - 20]"         << endl;

    // ================ Votre commande =========================================
    cout << endl;
    cout << "Votre commande" << endl;
    cout << "==============" << endl;

    // ---------------- Nombre bagage ------------------------------------------
    cout << setw(widthCommande) << left << "- Nbr de bagage [0 - 4]";
    cout << ": ";
    cin  >> nbrBagage;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // Vérifie si le nombre entré par l'utilisateur est incorrect.
    if (nbrBagage > 4 or nbrBagage < 0) {
        // Si cela est le cas, cela quitte le programme avec un message
        cout << "Nombre de bagage incorrect.";
        cout << "Appuyez sur \"Entrer\" pour quitter";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return EXIT_SUCCESS;
    }
    else {
        // Sinon, cela calcul le prix des bagages
        prixBagage = nbrBagage * TAXE_BAGAGE;
    }

    // ---------------- Distance parcourue -------------------------------------
    cout << setw(widthCommande) << left << "- Distance [0 - 500]";
    cout << ": ";
    cin  >> distanceParcourue;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // Vérifie si le nombre entré par l'utilisateur est incorrect.
    if (distanceParcourue > 500 or distanceParcourue < 0 ) {
        // Si cela est le cas, cela quitte le programme avec un message
        cout << "Distance parcourue incorrecte";
        cout << "Appuyez sur \"Entrer\" pour quitter";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return EXIT_SUCCESS;
    }

    // ---------------- Vitesse moyenne ----------------------------------------
    cout << setw(widthCommande) << left << "- Vitesse [50 - 120]";
    cout << ": ";
    cin  >> vitesse;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // Vérifie si le nombre entré par l'utilisateur est incorrect.
    if (vitesse > 120 or vitesse < 50) {
        // Si cela est le cas, cela quitte le programme avec un message
        cout << "Vitesse incorrect.";
        cout << "Appuyez sur \"Entrer\" pour quitter";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return EXIT_SUCCESS;
    } else {
        // Sinon, calcule le temps de trajet en minutes
        tempsTrajet = (distanceParcourue / vitesse) * 60;
    }

    // ---------------- Heure de départ ----------------------------------------
    cout << setw(widthCommande) << left << "- Heure de depart [0 - 23]";
    cout << ": ";
    cin  >> heureDepart;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // Vérifie si le nombre entré par l'utilisateur est :
    // un tarif de jour
    if (heureDepart >= 8 and heureDepart < 20) {
        prixTrajet = tempsTrajet * TARIF_MINUTE_JOUR;
        prixCourse = prixTrajet + TAXE_CHARGE + prixBagage;
    }
    // un tarif de nuit
    else if (heureDepart < 8 or heureDepart > 20) {
        prixTrajet = tempsTrajet * TARIF_MINUTES_NUIT;
        prixCourse = prixTrajet + TAXE_CHARGE + prixBagage;
    }
    // Sinon, l'heure entrée est incorrecte
    else {
        //cela quitte le programme avec un message
        cout << "Heure de depart incorrect.";
        cout << "Appuyez sur \"Entrer\" pour quitter";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return EXIT_SUCCESS;
    }

    // ================ Votre ticket ===========================================
    cout << endl;
    cout << "Votre ticket : "      << endl
         << "==============="      << endl

         << setw(width)         << left << "- Prise en charge" << " : "
         << setw(widthTicket)   << right << TAXE_CHARGE << endl

         << setw(width)         << left << "- Supp par bagage" << " : "
         << setw(widthTicket)   << right << prixBagage << endl

         << setw(width)         << left << "- Prix de la course" << " : "
         << setw(widthTicket)   << right << prixTrajet << endl

         << setw(width)         << left << "TOTAL" << " : "
         << setw(widthTicket)   << right << prixCourse    << endl;

    // Pressez entrer pour quitter
    cout << endl << "Appuyez sur \"Entrer\" pour quitter";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    // Fin du programme
    return EXIT_SUCCESS;
}



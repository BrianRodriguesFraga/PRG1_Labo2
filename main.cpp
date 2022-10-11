//---------------------------------------------------------
// Labo           : labo_03_Taxi
// Fichier        : labo_03_Taxi
// Auteur(s)      : Klasen Leonard & Rodrigues Fraga Brian
// Date           : 2022-06-10
// But            : Un programme qui calcule le prix d’une course en € en taxi
// Modifications  :
// Remarque(s)    :
//---------------------------------------------------------

#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
    const double TAXE_CHARGE         = 5.00;
    const double TAXE_BAGAGE         = 2.60;
    const double TARIF_MINUTE_JOUR   = 1.00;
    const double TARIF_MINUTES_NUIT  = 1.60;

    int heureDepart;
    int distanceParcourue;
    int vitesseMoy;
    int nbrBagage;

    double tempsTrajet;
    double prixTrajetJour;
    double prixTrajetNuit;
    double coutBagage;

    const int width = 25; //largeur de l'affichage des conditions
    const int widthCommande = 7; //largeur de l'affichage "votre commande"

    //=====================================================================

    //Tous les calculs nécessaires pour le programme.

    //calcul du temps du trajet et du tarif dépendant des heures de jour.

    tempsTrajet = vitesseMoy / distanceParcourue;
    prixTrajetJour = tempsTrajet * TARIF_MINUTE_JOUR;
    prixTrajetNuit = tempsTrajet * TARIF_MINUTES_NUIT;

    //calcul des taxes vis-à-vis du nbr de bagage.

    coutBagage = nbrBagage * TAXE_BAGAGE;

    //======================================================================

    //définis le nombre de décimal.

    cout << fixed << setprecision(2);

    cout << "Bonjour, ce programme..."  << endl
         << "Voici les conditions : "   << endl
         << "========================"  << endl
         << setw(width) << left << "- Prise en charge  : " << right << TAXE_CHARGE        << endl
         << setw(width) << left << "- Supp par bagage  : " << right << TAXE_BAGAGE        << endl
         << setw(width) << left << "- Tarif/min (jour) : " << right << TARIF_MINUTE_JOUR  << endl
         << setw(width) << left << "- Tarif/min (nuit) : " << right << TARIF_MINUTES_NUIT << endl
         << setw(width) << left << "- Prise en charge  : " << right << TAXE_CHARGE        << endl
         << setw(width) << left << "- Heures de jour   : " << right << "[8 - 20]"         << endl;

    cout << endl;
    cout << "Votre commande" << endl;
    cout << "==============" << endl;
    cout << setw(widthCommande) << left << "- Nbr de bagage : ";
    cin  >> nbrBagage;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if (nbrBagage > 4 or nbrBagage < 0)
    {
        cout << "Nombre de bagage invalid.";

        return EXIT_SUCCESS;
    }

    cout << setw(widthCommande) << left << "- Distance : ";
    cin  >> distanceParcourue;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if (distanceParcourue > 500 or distanceParcourue < 0 )
    {
        cout << "Distance parcourue incorrect";

        return EXIT_SUCCESS;
    }

    cout << setw(widthCommande) << left << "- Vitesse moyenne : ";
    cin  >> vitesseMoy;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if (vitesseMoy > 120 or vitesseMoy < 50)
    {
        cout << "Vitesse incorrect.";

        return EXIT_SUCCESS;
    }

    cout << setw(widthCommande) << left << "- Heure de depart : ";
    cin  >> heureDepart;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if (heureDepart > 23 or heureDepart < 0)
    {
        cout << "Heure de depart incorrect.";

        return EXIT_SUCCESS;
    }

    //condition du prix du taxi dépendant de l'heure de depart

    if (heureDepart >= 8 && heureDepart <= 20)
    {
        cout << "Prix de la course : " << prixTrajetJour << endl;
    }

    if (heureDepart < 8 or heureDepart > 20)
    {
        prixTrajetNuit = tempsTrajet * TARIF_MINUTES_NUIT;
    }



return EXIT_SUCCESS;




}



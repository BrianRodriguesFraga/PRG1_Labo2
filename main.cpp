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
    double prixTrajet;
    double coutBagage;
    double prixCourse;

    const int width = 20; //largeur de l'affichage des conditions
    const int widthCommande = 18; //largeur de l'affichage "Votre commande"
    const int widthTicket = 6; //largeur de l'affichage pour "Votre ticket"

    //======================================================================

    //définis le nombre de décimal.

    cout << fixed << setprecision(2);

    cout << "Bonjour, ce programme..."  << endl
         << "Voici les conditions : "   << endl
         << "========================"  << endl
         << setw(width) << left << "- Prise en charge  : " << left << TAXE_CHARGE        << endl
         << setw(width) << left << "- Supp par bagages : " << left << TAXE_BAGAGE        << endl
         << setw(width) << left << "- Tarif/min (jour) : " << right << TARIF_MINUTE_JOUR  << endl
         << setw(width) << left << "- Tarif/min (nuit) : " << right << TARIF_MINUTES_NUIT << endl
         << setw(width) << left << "- Prise en charge  : " << right << TAXE_CHARGE        << endl
         << setw(width) << left << "- Heures de jour   : " << right << "[8 - 20]"         << endl;

    cout << endl;
    cout << "Votre commande" << endl;
    cout << "==============" << endl;
    cout << setw(widthCommande) << left << "- Nbr de bagages";
    cout << ": ";
    cin  >> nbrBagage;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if (nbrBagage > 4 or nbrBagage < 0)
    {
        cout << "Nombre de bagages incorrect.";

        return EXIT_SUCCESS;
    }
    coutBagage = nbrBagage * TAXE_BAGAGE;

    cout << setw(widthCommande) << left << "- Distance";
    cout << ": ";
    cin  >> distanceParcourue;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if (distanceParcourue > 500 or distanceParcourue < 0 )
    {
        cout << "Distance parcourue incorrecte.";

        return EXIT_SUCCESS;
    }

    cout << setw(widthCommande) << left << "- Vitesse moyenne";
    cout << ": ";
    cin  >> vitesseMoy;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    if (vitesseMoy > 120 or vitesseMoy < 50)
    {
        cout << "Vitesse moyenne incorrecte.";

        return EXIT_SUCCESS;
    }

    //=====================================================================

    //Tous les calculs nécessaires pour le programme.

    //calcul du temps du trajet et du tarif dépendant des heures de jour.

    tempsTrajet = ((double)vitesseMoy / distanceParcourue) * 60;

    //====================================================================


    cout << setw(widthCommande) << left << "- Heure de depart";
    cout << ": ";
    cin  >> heureDepart;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');


    if (heureDepart >= 8 && heureDepart <= 20)
    {
        prixTrajet = tempsTrajet * TARIF_MINUTE_JOUR;
        cout << "Prix de la course : " << prixTrajet << endl;
    }
    else if (heureDepart < 8 || heureDepart > 20)
    {
        prixTrajet = tempsTrajet * TARIF_MINUTES_NUIT;
    }
    else
    {
        cout << "Heure de depart incorrecte.";
        return EXIT_SUCCESS;
    }

    prixCourse = prixTrajet + TAXE_CHARGE + coutBagage;
    //affichage des résultats plus dernier calcul pour finir le programme
    cout << "Votre ticket : "  << endl
         << "==============="  << endl
         << setw(width) << left << "- Prise en charge   : " << setw(widthTicket) << right << TAXE_CHARGE << endl
         << setw(width) << left << "- Supp par bagage   : " << setw(widthTicket) << right << coutBagage  << endl
         << setw(width) << left << "- Prix de la course : " << setw(widthTicket) << right << prixTrajet  << endl
         << setw(width) << left << "              TOTAL : " << setw(widthTicket) << right << prixCourse  << endl
         << endl;
    return EXIT_SUCCESS;

return EXIT_SUCCESS;




}



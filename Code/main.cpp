#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstring>
#include <vector>
#include <form_lexeur.h>

using namespace std;



int main(void)
{
    Form_Lexeur mon_fichier;

    mon_fichier.choix_fichier();
    mon_fichier.Lecture_fichier();
    mon_fichier.ajout_espace();
    mon_fichier.enregistrer_commentaire();
    mon_fichier.decoupage_mots();
    mon_fichier.lire_vecteur();

}

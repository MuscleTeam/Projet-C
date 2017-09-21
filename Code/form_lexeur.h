#ifndef FORM_LEXEUR_H
#define FORM_LEXEUR_H

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Form_Lexeur
{
public:
    Form_Lexeur();
    void Lecture_fichier();
    void choix_fichier();
    void decoupage_mots();
    void minuscule();
    void ajout_espace();
    void enregistrer_commentaire();
    void lire_vecteur();

    string chemin_fichier;
    string ligne;
    int num_ligne = 1;

    vector<string> vecteur_mot;
    vector<int> vecteur_ligne_mot;
    vector<string> vecteur_commentaire;
    vector<int> vecteur_ligne_commentaire;



};

#endif // FORM_LEXEUR_H

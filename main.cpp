#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;



void Lecture_fichier(string);
string choix_fichier(void);
void lecture_liste(std::list<string>);
void suppresion_commentaires(std::list<string>);



std::list<string> liste_ligne;
std::list<string> liste_ligne_sans_commentaire;

int main(void)
{
    cout << endl;
    Lecture_fichier(choix_fichier());
    suppresion_commentaires(liste_ligne);
    lecture_liste(liste_ligne_sans_commentaire);

}

string choix_fichier(void) // permet de récupérer le chemin d'accé de notre fichier
{
    string chemin_fichier;
    cout << "Faites glisser le fichier à ouvrir dans le Terminal : ";
    cin  >> chemin_fichier;

    return chemin_fichier;
}

void Lecture_fichier(string chemin) // lis le fichier et stock le contenu de chaque ligne dans une liste
{
    ifstream fichier(chemin,ios::in);

    if (fichier)
    {
        string ligne;

        while (getline(fichier,ligne))
        {
            liste_ligne.push_back(ligne);
        }

        fichier.close();
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
}


void lecture_liste(std::list<string> ma_liste)
{
    std::list<string>::iterator i = ma_liste.begin();
    while(i != ma_liste.end())
    {
        cout << *i << endl;
        i++;
    }
}

void suppresion_commentaires(std::list<string> ma_liste)
{
    list<string>::iterator i = ma_liste.begin();
    size_t found = 0;

    while(i != ma_liste.end())
    {
        string ligne = *i;
        found = ligne.find("--");
        i++;
        liste_ligne_sans_commentaire.push_back(ligne.substr(0,found));
    }
}



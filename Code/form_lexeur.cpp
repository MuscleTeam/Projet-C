#include "form_lexeur.h"

Form_Lexeur::Form_Lexeur()
{

}

void Form_Lexeur::choix_fichier(void) // permet de récupérer le chemin d'accès de notre fichier
{
    cout << "Faites glisser le fichier à ouvrir dans le Terminal : ";
    cin  >> this->chemin_fichier;

}

void Form_Lexeur::Lecture_fichier() // lis le fichier et stock le contenu de chaque ligne dans une liste
{
    ifstream fichier(this->chemin_fichier,ios::in);

    if (fichier)
    {

        while (getline(fichier,this->ligne))
        {
            transform(this->ligne.begin(), this->ligne.end(), this->ligne.begin(), ::tolower); // conversion en minuscule
            ajout_espace();
            enregistrer_commentaire();
            decoupage_mots();
            this->num_ligne++;
        }

        fichier.close();
    }
    else
    {
        cout << "Impossible d'ouvrir le fichier" << endl;
    }
}

void Form_Lexeur::ajout_espace()
{
    string x;


    for (int i=0 ; i<this->ligne.size() ; i++)
    {
       switch(this->ligne[i])
       {
        case ',' :  x = x + " , " ; break;
        case '!' :  x = x + " ! " ; break;
        case '\'' :  x = x + " \ " ; break;
        case '#' :  x = x + " # " ; break;
        case '$' :  x = x + " $ " ; break;
        case '%' :  x = x + " % " ; break;
        case '&' :  x = x + " & " ; break;
        case '\"' :  x = x + " \" " ; break;
        case '(' :  x = x + " ( " ; break;
        case ')' :  x = x + " ) " ; break;
        case '*' :  x = x + " * " ; break;
        case '+' :  x = x + " + " ; break;
        case '-' :  x = x + " - " ; break;
        case '.' :  x = x + " . " ; break;
        case '/' :  x = x + " / " ; break;
        case ':' :  x = x + " : " ; break;
        case ';' :  x = x + " ; " ; break;
        case '<' :  x = x + " < " ; break;
        case '?' :  x = x + " ? " ; break;
        case '@' :  x = x + " @ " ; break;
        case '[' :  x = x + " [ " ; break;
        case '\\' :  x = x + " \\ " ; break;
        case ']' :  x = x + " ] " ; break;
        case '>' :  x = x + " > " ; break;
        case '{' :  x = x + " { " ; break;
        case '}' :  x = x + " } " ; break;
        case '~' :  x = x + " ~ " ; break;

        default : x = x + this->ligne[i];
       }
    }

    this->ligne = x;

}


void Form_Lexeur::enregistrer_commentaire()
{
    size_t found = 0;
    found = this->ligne.find(" -  - ");

    if( found != 18446744073709551615)
    {
        this->vecteur_commentaire.push_back(this->ligne.substr(found,this->ligne.length()));
        this->vecteur_ligne_commentaire.push_back(this->num_ligne);
    }

    this->ligne  = this->ligne.substr(0,found);

}


void Form_Lexeur::decoupage_mots()
{
    char * pch;

    pch = strtok( (char*)this->ligne.c_str() , " \t"); // coupe au niveau des tabulations et espaces
    while( pch != NULL)
    {
        this->vecteur_mot.push_back(pch);
        this->vecteur_ligne_mot.push_back(this->num_ligne);
        pch = strtok( NULL , " ");
    }
}

void Form_Lexeur::lire_vecteur()
{
    for(int i=0 ; i< this->vecteur_mot.size() ; i++)
    {
        cout << this->vecteur_ligne_mot[i] << " : " << this->vecteur_mot[i] << endl;
    }
}


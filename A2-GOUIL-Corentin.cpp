// DM1/A2-GOUIL-Corentin.cpp
// Affichage d'une forme géométrique défini (carre, triangle rectangle, triangle rectangle inverse, triangle, triangle inverse, losange) suivant la taille, le décalage et le caractere voulu
// C.GOUIL 24.10.2019
#include <iostream>
#include <fstream>
#include <string>

void afficherCarre(int uneTaille, int unDecalage, char unChar, bool unRemplissage) //Fonction affichant un carré
{
    for(int leI = 1; leI <= uneTaille; leI++) //Boucle for affichant un carré non plein par rapport à la taille de celui ci
    {
        if(leI == 1 || leI == uneTaille) //Condition permetant d'afficher la première et dernières ligne pleine
        {
            for(int leJ = 1; leJ <= unDecalage; leJ++) //Créer le décalage dans la ligne
            {
                std::cout << ' '; 
            }
            for(int leJ = 1; leJ <= uneTaille; leJ++) //Boucle for permettant d'afficher une ligne pleine
            {
                std::cout << unChar; 
            }
            std::cout << '\n';
        }
        else //Affichera les lignes intermediaire afin de faire le carré de la bonne dimmension
        {
            for(int leJ = 1; leJ <= unDecalage; leJ++) //Créer le décalage dans la ligne
            {
                std::cout << ' ';
            }
            for(int leJ = 1; leJ <= uneTaille; leJ++) //Boucle for permettant d'afficher la ligne non pleine
            {
                if(leJ == 1 || leJ == uneTaille) //Affiche un caratère en début et fin de ligne
                {
                    std::cout << unChar;
                }
                else if(unRemplissage == true) //Rempli avec un caractère si le remplissage est défini
                {
                    std::cout << unChar;
                }
                else //Rempli avec des espaces
                {
                    std::cout << ' ';
                }
            }
            std::cout << '\n';
        }
    }
}

void afficherTriangleRectangle(int uneTaille, int unDecalage, char unChar, bool unRemplissage) //Fonction affichant un triangle rectangle
{
    for(int leI = 1; leI <= uneTaille; leI++) //Creer une ligne du triangle
    {
        for(int leJ = 1; leJ <= unDecalage; leJ++) //Creer le décalage si il existe
        {
            std::cout << ' ';
        }
        if(leI == 1 || leI == uneTaille) //Rempli la ligne si il s'agit de la premiere ou la derniere
        {
            for(int leJ = 1; leJ <= leI; leJ++)
            {
                std::cout << unChar;
            }
        }
        else 
        {
            for(int leJ = 1; leJ <= leI; leJ++) //Creer les éléments d'une ligne du triangle rectangle suivant le nombre de ligne existante
            {
                if(leJ == 1 || leJ == leI) //Ajoute un caractère en fin et début de ligne
                {
                    std::cout << unChar;
                }
                else if(unRemplissage == true) //Rempli avec un caractère si le remplissage est défini
                {
                    std::cout << unChar;
                }
                else //Rempli avec des espaces
                {
                    std::cout << ' ';
                }
            }
        }
        std::cout << '\n';
    }
}

void afficherTriangleRectangleInverse(int uneTaille, int unDecalage, char unChar, bool unRemplissage) //Fonction affichant un triangle rectangle inversé
{
    
    for(int leI = uneTaille; leI >= 1; leI--) //Creer une ligne du triangle dans le sens inverse du triangle "normal"
    {
        for(int leJ = 1; leJ <= unDecalage; leJ++) //Creer le décalage si il existe
        {
            std::cout << ' ';
        }
        if(leI == 1 || leI == uneTaille) //Rempli la ligne si il s'agit de la premiere ou la derniere
        {
            for(int leJ = 1; leJ <= leI; leJ++)
            {
                std::cout << unChar;
            }
        }
        else 
        {
            for(int leJ = 1; leJ <= leI; leJ++) //Creer les éléments d'une ligne du triangle rectangle suivant le nombre de ligne existante
            {
                if(leJ == 1 || leJ == leI) //Ajoute un caractère en fin et début de ligne
                {
                    std::cout << unChar;
                }
                else if(unRemplissage == true) //Rempli avec un caractère si le remplissage est défini
                {
                    std::cout << unChar;
                }
                else //Rempli avec des espaces
                {
                    std::cout << ' ';
                }
            }
        }
        std::cout << '\n';
    }
}

void afficherTriangle(int uneTaille, int unDecalage, char unChar, bool unRemplissage) //Fonction affichant un triangle
{
    for(int leI = 1; leI <= uneTaille; leI += 2) //Creer les lignes du triangle
    {
        for(int leJ = 1; leJ <= unDecalage; leJ++) //Creer le decalage s'il existe
        {
            std::cout << ' ';
        }
        for(int leJ = 1; leJ <= uneTaille; leJ++) //Creer les elements d'une ligne
        {
            if(leI == 1) //Rempli la premiere ligne
            {
                std::cout << unChar;
            }
            else if(leJ == leI/2+1 || leJ == uneTaille-leI/2) //Affiche un caractère lorsque le l'emplacement de la colonne correspond a la moitier de celui la ligne +1 ou à celui de la taille - la moitier de la ligne
            {
                std::cout << unChar;
            }
            else if (unRemplissage == true && leJ >= leI/2+1 && leJ <= uneTaille-leI/2) //Rempli avec un caractère
            {
                std::cout << unChar;
            }
            else //Rempli avec un espaces
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}

void afficherTriangleInverse(int uneTaille, int unDecalage, char unChar, bool unRemplissage) //Fonction affichant un triangle inverse
{
    for(int leI = uneTaille; leI >= 0; leI -= 2) //Creer les lignes du triangle dans le sens inverse du triangle "normal"
    {
        for(int leJ = 1; leJ <= unDecalage; leJ++) //Creer le decalage s'il existe
        {
            std::cout << ' ';
        }
        for(int leJ = 1; leJ <= uneTaille; leJ++) //Creer les elements d'une ligne
        {
            if(leI == 1) //Rempli la premiere ligne
            {
                std::cout << unChar;
            }
            else if(leJ == leI/2+1 || leJ == uneTaille-leI/2) //Affiche un caractère lorsque le l'emplacement de la colonne correspond a la moitier de celui la ligne +1 ou à celui de la taille - la moitier de la ligne
            {
                std::cout << unChar;
            }
            else if (unRemplissage == true && leJ >= leI/2+1 && leJ <= uneTaille-leI/2) //Rempli avec un caractère
            {
                std::cout << unChar;
            }
            else //Rempli avec un espace
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}

void afficherLosange(int uneTaille, int unDecalage, char unChar, bool unRemplissage) //Fonction affichant un losange
{
    for(int leI = uneTaille-1+uneTaille%2; leI >= 2; leI -= 2) //Creer les lignes du triangle du haut du losagne
    {
        for(int leJ = 1; leJ <= unDecalage; leJ++) //Creer le decalage s'il existe
        {
            std::cout << ' ';
        }
        for(int leJ = 1; leJ <= uneTaille; leJ++) //Creer les elements d'une ligne
        {
            if(leJ == leI/2+1 || leJ == uneTaille-leI/2)
            {
                std::cout << unChar;
            }
            else if (unRemplissage == true && leJ >= leI/2+1 && leJ <= uneTaille-leI/2)
            {
                std::cout << unChar;
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
    for(int leI = 1; leI <= uneTaille; leI += 2) //Creer les lignes du triangle du bas du losange (dont la ligne centrale)
    {
        for(int leJ = 1; leJ <= unDecalage; leJ++) //Creer le decalage s'il existe
        {
            std::cout << ' ';
        }
        for(int leJ = 1; leJ <= uneTaille; leJ++) //Creer les elements d'une ligne
        {
            if(leJ == leI/2+1 || leJ == uneTaille-leI/2)
            {
                std::cout << unChar;
            }
            else if (unRemplissage == true && leJ >= leI/2+1 && leJ <= uneTaille-leI/2)
            {
                std::cout << unChar;
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}

int main()
{
    int laTaille, leDecalage; 
    char leChar;
    std::string laForme, leRemplissage;
    bool leRempBool;
    std::ifstream leFichierLu ("figure.txt"); //Ouverture du fichier "figure.txt"
    while (!leFichierLu.eof()) //Boucle while permettant la lecture du fichier lu
    {
        getline(leFichierLu, laForme); //Va lire la forme de la figure
        leFichierLu >> laTaille; //Va lire la taille de la figure
        leFichierLu.ignore(); //Va ignorer le retour a la ligne
        leFichierLu >> leDecalage; //Va lire le décalage de la figure
        leFichierLu.ignore(); //Va ignorer le retour a la ligne
        leFichierLu >> leChar; //Va lire le caractère qui va composer la figure
        leFichierLu.ignore(); //Va ignorer le retour a la ligne
        getline(leFichierLu, leRemplissage); //Va lire le remplissage de la figure
        if(leRemplissage == "fill") //Si "fill" à été lu et assigner à la variable leRemplissage, leRempBool va devenir vrai
        {
            leRempBool = true;
        }
        else ////Si "fill" n'à pas été lu et assigner à la variable leRemplissage, leRempBool va devenir faux
        {
            leRempBool = false;
        }
        if(laForme == "carre") //Si la forme est carré, va appeller la fonction afficherCarre avec les parametres correspondant
        {
            afficherCarre(laTaille,leDecalage,leChar,leRempBool);
        }
        else if(laForme == "triangle rectangle") //Si la forme est triangle rectangle, va appeller la fonction afficherTriangleRectangle avec les parametres correspondant
        {
            afficherTriangleRectangle(laTaille,leDecalage,leChar,leRempBool);
        }
        else if(laForme == "triangle rectangle inverse") //Si la forme est triangle tectangle tnverse, va appeller la fonction afficherTriangleRectangleInverse avec les parametres correspondant
        {
            afficherTriangleRectangleInverse(laTaille,leDecalage,leChar,leRempBool);
        }
        else if(laForme == "triangle") //Si la forme est triangle, va appeller la fonction afficherTriangle avec les parametres correspondant
        {
            afficherTriangle(laTaille,leDecalage,leChar,leRempBool);
        }
        else if(laForme == "triangle inverse") //Si la forme est triangle inverse, va appeller la fonction afficherTriangleInverse avec les parametres correspondant
        {
            afficherTriangleInverse(laTaille,leDecalage,leChar,leRempBool);
        }
        else //Si la forme n'est aucune des précedentes, elle est censé etre losange, va appeller la fonction afficherLosange avec les parametres correspondant
        {
            afficherLosange(laTaille,leDecalage,leChar,leRempBool);
        }
    }
    leFichierLu.close();
    return 0;
}

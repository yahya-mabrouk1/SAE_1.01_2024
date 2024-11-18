#include "fonctions.h"


int saisieNumeroEtudiant(void)
{
    int numeroEtudiant;            
    int numeroEtudiant_Saisie;   
    int reference_stage;          
    int noteFinale;               
    FILE *fichier_Etudiants;      
    printf("Saisissez votre numero etudiant : \n");
    scanf("%d", &numeroEtudiant_Saisie);

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL)
    {
        printf("Probleme d'ouverture du fichier des etudiants.\n");
        exit(1);
    }

    fscanf(fichier_Etudiants, "%d%d%d", &numeroEtudiant, &reference_stage, &noteFinale);
    while (!feof(fichier_Etudiants)) 
    {
        if (numeroEtudiant_Saisie == numeroEtudiant)
        {
            fclose(fichier_Etudiants);
            return numeroEtudiant_Saisie;
        }
        fscanf(fichier_Etudiants, "%d%d%d", &numeroEtudiant, &reference_stage, &noteFinale);
    }

    fclose(fichier_Etudiants);

    return -1;
}

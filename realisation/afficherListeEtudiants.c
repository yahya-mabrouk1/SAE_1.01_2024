#include "fonctions.h"

void afficherListeEtudiants(void)
{
    FILE *fichier_Etudiants;
    int numeroEtudiant, referenceStage, noteFinale;

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des étudiants.\n");
        exit(1);
    }

    printf("Liste des étudiants :\n");
    printf("Numéro de l'étudiant | Référence du stage | Note finale\n");
    printf("-------------------------------------------------------\n");

    while (fscanf(fichier_Etudiants, "%d %d %d", &numeroEtudiant, &referenceStage, &noteFinale) == 3)
    {
        printf("%d\t\t\t\t%d\t\t%d\n", numeroEtudiant, referenceStage, noteFinale);
    }

    fclose(fichier_Etudiants);
}

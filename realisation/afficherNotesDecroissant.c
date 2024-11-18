#include "fonctions.h"
#include <stdio.h>
#include <string.h>

void afficherNotesDecroissant(void)
{
    int tabNumeroEtudiant[1000], tabReferenceStage[1000];
    float tabNoteFinale[1000]; 
    int nbLignes = 0;
    int i, j, menuQuitter;

    FILE *fichier_Etudiants;

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des étudiants.\n");
        return;
    }

    while (fscanf(fichier_Etudiants, "%d %d %f", &tabNumeroEtudiant[nbLignes], &tabReferenceStage[nbLignes], &tabNoteFinale[nbLignes]) == 3)
    {
        nbLignes++;
    }
    fclose(fichier_Etudiants); 

    for (i = 0; i < nbLignes - 1; i++)
    {
        for (j = 0; j < nbLignes - i - 1; j++)
        {
            if (tabNoteFinale[j] < tabNoteFinale[j + 1]) 
            {
                float tempNote = tabNoteFinale[j];
                tabNoteFinale[j] = tabNoteFinale[j + 1];
                tabNoteFinale[j + 1] = tempNote;

                int tempNumero = tabNumeroEtudiant[j];
                tabNumeroEtudiant[j] = tabNumeroEtudiant[j + 1];
                tabNumeroEtudiant[j + 1] = tempNumero;

                int tempReference = tabReferenceStage[j];
                tabReferenceStage[j] = tabReferenceStage[j + 1];
                tabReferenceStage[j + 1] = tempReference;
            }
        }
    }

    printf("\nNotes des étudiants par ordre décroissant :\n");
    printf("Numéro d'étudiant | Référence stage | Note finale\n");
    printf("---------------------------------------------------\n");

    for (i = 0; i < nbLignes; i++)
    {
        printf("%d\t\t\t%d\t\t%.2f\n", tabNumeroEtudiant[i], tabReferenceStage[i], tabNoteFinale[i]);
    }
    printf("\n");


    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;
}

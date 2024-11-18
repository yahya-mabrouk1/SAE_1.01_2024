#include "fonctions.h"

void chercherStageSelonEtudiant(void)
{
    int numeroEtudiantRecherche;
    int tabNumeroEtudiant[1000] = {0}, tabReferenceStage[1000] = {0};
    float tabNoteFinale[1000] = {0};
    int i = 0, positionEtudiant = -1, menuQuitter;
    FILE *fichier_Etudiants;

    printf("Saisissez le numéro de l'étudiant : ");
    scanf("%d", &numeroEtudiantRecherche);

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des étudiants.\n");
        return;
    }

    while (fscanf(fichier_Etudiants, "%d%d%f", &tabNumeroEtudiant[i], &tabReferenceStage[i], &tabNoteFinale[i]) == 3)
    {
        if (tabNumeroEtudiant[i] == numeroEtudiantRecherche)
        {
            positionEtudiant = i; 
        }
        i++;
    }
    fclose(fichier_Etudiants);

    if (positionEtudiant == -1)
    {
        printf("Erreur : l'étudiant avec le numéro %d est introuvable.\n", numeroEtudiantRecherche);
        return;
    }

    if (tabReferenceStage[positionEtudiant] == -1)
    {
        printf("Erreur : l'étudiant %d n'a pas de stage.\n", numeroEtudiantRecherche);
    }
    else
    {
        printf("L'étudiant %d est affecté au stage de référence %d.\n",
               numeroEtudiantRecherche, tabReferenceStage[positionEtudiant]);
    }

    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;
}

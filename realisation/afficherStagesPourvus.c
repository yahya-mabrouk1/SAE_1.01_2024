#include "fonctions.h"


void afficherStagesPourvus(void)
{
    int tabNumeroEtudiant[1000] = {0}, tabReferenceStage[1000] = {0};
    float tabNoteFinale[1000] = {0};
    int i = 0, compteur = 0, menuQuitter;
    FILE *fichier_Etudiants;

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des étudiants.\n");
        return;
    }

    while (fscanf(fichier_Etudiants, "%d%d%f", &tabNumeroEtudiant[i], &tabReferenceStage[i], &tabNoteFinale[i]) == 3)
    {
        i++;
    }
    fclose(fichier_Etudiants);

    printf(">>>>>>>>>> Stages pourvus avec les étudiants affectés : <<<<<<<<<<\n");
    printf("Référence stage\tNuméro étudiant\n");
    printf("---------------------------------\n");

    for (int j = 0; j < i; j++)
    {
        if (tabReferenceStage[j] != -1)
        {
            printf("%d\t\t%d\n", tabReferenceStage[j], tabNumeroEtudiant[j]);
            compteur = compteur+1; 
        }
    }

    if (compteur==0)
    {
        printf("Aucun stage pourvu trouvé.\n");
    }


    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;
}

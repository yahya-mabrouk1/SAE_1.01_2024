#include "fonctions.h"


void informationsStage(void)
{
    int referenceStageRecherchee;
    int tabReferenceStage[1000] = {0}, tabDepartementStage[1000] = {0}, tabStatutStage[1000] = {0};
    int tabNombreCandidats[1000] = {0}, tabNumerosCandidats[3000] = {0};
    int referenceStage, departementStage, statutStage, nombreCandidats, numeroCandidat;
    int i = 0, j, positionStage = -1, a, menuQuitter;
    FILE *fichier_Stages;

    printf("Saisissez la référence du stage souhaité : ");
    scanf("%d", &referenceStageRecherchee);

    fichier_Stages = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Stages == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des offres de stages.\n");
        return;
    }

    while (fscanf(fichier_Stages, "%d%d%d", &referenceStage, &departementStage, &statutStage) == 3)
    {
        tabReferenceStage[i] = referenceStage;
        tabDepartementStage[i] = departementStage;
        tabStatutStage[i] = statutStage;

        if (statutStage == 0)
        {
            fscanf(fichier_Stages, "%d", &nombreCandidats);
            tabNombreCandidats[i] = nombreCandidats;

            a = i * 3;
            for (j = 0; j < nombreCandidats; j++)
            {
                fscanf(fichier_Stages, "%d", &numeroCandidat);
                tabNumerosCandidats[a + j] = numeroCandidat;
            }
        }
        i++;
    }
    fclose(fichier_Stages);

    for (j = 0; j < i; j++)
    {
        if (tabReferenceStage[j] == referenceStageRecherchee)
        {
            positionStage = j;
            break;
        }
    }

    if (positionStage == -1)
    {
        printf("Erreur : le stage avec la référence %d est introuvable.\n", referenceStageRecherchee);
        return;
    }

    printf(">>>>>>>>>> Informations du stage : <<<<<<<<<<\n");
    printf("Référence : %d\n", tabReferenceStage[positionStage]);
    printf("Département : %d\n", tabDepartementStage[positionStage]);
    printf("Statut : %d\n", tabStatutStage[positionStage]);

    if (tabStatutStage[positionStage] == 0)
    {
        printf("Nombre de candidats : %d\n", tabNombreCandidats[positionStage]);
        if(tabNombreCandidats[positionStage]!=0)
        {
            printf("Numéros des candidats : ");
            a = positionStage * 3;
            for (j = 0; j < tabNombreCandidats[positionStage]; j++)
            {
                printf("%d ", tabNumerosCandidats[a + j]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Ce stage est pourvu.\n");



    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;    }
}

#include "fonctions.h"

void chercherToutStagesSelonDepartement(void)
{
    int departementRecherche;
    int tabReferenceStage[1000] = {0}, tabDepartementStage[1000] = {0}, tabStatutStage[1000] = {0};
    int tabNombreCandidats[1000] = {0}, tabNumerosCandidats[3000] = {0}; 
    int referenceStage, departementStage, statutStage, nombreCandidats, numeroCandidat;
    int i = 0, j, a, compteur = 0, menuQuitter;
    FILE *fichier_Stages;

    printf("Saisissez le département souhaité : ");
    scanf("%d", &departementRecherche);

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

    printf(">>>>>>>>>> Stages du département %d : <<<<<<<<<<\n", departementRecherche);
    printf("Référence\tDépartement\tStatut\tNombre de candidats\tNuméros des candidats\n");

    for (j = 0; j < i; j++)
    {
        if (tabDepartementStage[j] == departementRecherche)
        {
            printf("%d\t\t%d\t\t%d", tabReferenceStage[j], tabDepartementStage[j], tabStatutStage[j]);

            if (tabStatutStage[j] == 0)
            {
                printf("\t\t%d\t\t\t", tabNombreCandidats[j]);
                a = j * 3;
                for (int k = 0; k < tabNombreCandidats[j]; k++)
                {
                    printf("%d ", tabNumerosCandidats[a + k]);
                }
            }
            printf("\n");
            compteur = compteur+1;
        }
    }

    if (compteur==0)
    {
        printf("Aucun stage trouvé pour le département %d.\n", departementRecherche);
    }



    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;
}

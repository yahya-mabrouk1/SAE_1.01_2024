#include "fonctions.h"


void supprimerStage(void)
{
    int referenceStageASupprimer;
    int tabReferenceStage[1000] = {0}, tabDepartementStage[1000] = {0}, tabStatutStage[1000] = {0};
    int tabNombreCandidats[1000] = {0}, tabNumerosCandidats[3000] = {0}; 
    int reference_stage, departement_stage, statu_stage, nombre_Candidats, numeroCandidat;
    int i = 0, j, a, b = 0, positionStage = -1;
    int menuQuitter;
    FILE *fichier_Offres;

    afficherToutStagesStatue0();

    printf("Saisissez la référence du stage à supprimer :\n");
    scanf("%d", &referenceStageASupprimer);

    fichier_Offres = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Offres == NULL)
    {
        printf("Erreur d'ouverture du fichier des offres de stages.\n");
        exit(1);
    }

    while (fscanf(fichier_Offres, "%d%d%d", &reference_stage, &departement_stage, &statu_stage) == 3)
    {
        tabReferenceStage[i] = reference_stage;
        tabDepartementStage[i] = departement_stage;
        tabStatutStage[i] = statu_stage;

        if (statu_stage == 0)
        {
            fscanf(fichier_Offres, "%d", &nombre_Candidats);
            tabNombreCandidats[i] = nombre_Candidats;

            a = i * 3; 
            for (j = 0; j < nombre_Candidats; j++)
            {
                fscanf(fichier_Offres, "%d", &numeroCandidat);
                tabNumerosCandidats[a + j] = numeroCandidat;
            }
        }
        i++;
    }
    fclose(fichier_Offres);

    for (b = 0; b < i; b++)
    {
        if (tabReferenceStage[b] == referenceStageASupprimer)
        {
            positionStage = b; 
            break;
        }
    }

    if (positionStage == -1)
    {
        printf("Erreur : le stage avec la référence %d est introuvable.\n", referenceStageASupprimer);
        return;
    }

    fichier_Offres = fopen("Fichier_Offres_De_Stages.txt", "w");
    if (fichier_Offres == NULL)
    {
        printf("Erreur d'ouverture du fichier des offres de stages pour mise à jour.\n");
        exit(1);
    }

    for (b = 0; b < i; b++)
    {
        if (b != positionStage)
        {
            fprintf(fichier_Offres, "%d %d\n%d\n", tabReferenceStage[b], tabDepartementStage[b], tabStatutStage[b]);

            if (tabStatutStage[b] == 0)
            {
                fprintf(fichier_Offres, "%d\n", tabNombreCandidats[b]);
                a = b * 3; 
                for (j = 0; j < tabNombreCandidats[b]; j++)
                {
                    fprintf(fichier_Offres, "%d\n", tabNumerosCandidats[a + j]);
                }
            }
        }
    }
    fclose(fichier_Offres);

    printf("Le stage avec la référence %d a été supprimé avec succès.\n", referenceStageASupprimer);

    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;
}

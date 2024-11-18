#include "fonctions.h"



void ajouterStage(void)
{
    int departementStage;
    int tabReferenceStage[1000] = {0}, tabDepartementStage[1000] = {0}, tabStatutStage[1000] = {0};
    int reference_stage, departement_stage, statu_stage;
    int i = 0, j;
    int nouvelleReferenceStage = 0;
    int menuQuitter;
    FILE *fichier_Stages;

    fichier_Stages = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Stages == NULL)
    {
        printf("Erreur d'ouverture du fichier des offres de stages.\n");
        exit(1);
    }

    while (fscanf(fichier_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage) == 3)
    {
        tabReferenceStage[i] = reference_stage;
        tabDepartementStage[i] = departement_stage;
        tabStatutStage[i] = statu_stage;

        
        if (statu_stage == 0)
        {
            int nombreCandidats, numeroCandidat;
            fscanf(fichier_Stages, "%d", &nombreCandidats);
            for (j = 0; j < nombreCandidats; j++)
            {
                fscanf(fichier_Stages, "%d", &numeroCandidat);
            }
        }
        i++;
    }

    if (i > 0)
    {
        nouvelleReferenceStage = tabReferenceStage[i - 1] + 1;
    }
    else
    {
        nouvelleReferenceStage = 1; 
    }
    fclose(fichier_Stages);

    printf("Saisissez le departement du nouveau stage : ");
    scanf("%d", &departementStage);

    fichier_Stages = fopen("Fichier_Offres_De_Stages.txt", "a");
    if (fichier_Stages == NULL)
    {
        printf("Erreur d'ouverture du fichier des offres de stages pour ajout.\n");
        exit(1);
    }

    fprintf(fichier_Stages, "%d %d\n0\n0\n", nouvelleReferenceStage, departementStage);
    fclose(fichier_Stages);

    printf("Le nouveau stage avec la reference %d et le departement %d a ete ajoute avec succes.\n",
           nouvelleReferenceStage, departementStage);


    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;

}
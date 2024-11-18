#include "fonctions.h"

void candidaterStage(int *numeroEtudiant) {
    int reference_Stage_Candidature;
    int tabReferenceStage[1000] = {0}, tabDepartementStage[1000] = {0}, tabStatueStage[1000] = {0}, tabNombreCandidats[1000] = {0}, tabNumerosCandidats[5000] = {0};
    int reference_stage, departement_stage, statu_stage, nombre_Candidats, numeroCandidat;
    int i = 0, a, j, b = 0, position_Reference_Stage = -1;
    int menuQuitter;
    FILE *fichier_Ofrres_De_Stages;

    printf("Voici la liste des stages disponibles :\n");
    consulterOffresStagesDisponibles();
    printf("Saisissez la reference du stage souhaite :\n");
    scanf("%d", &reference_Stage_Candidature);

    fichier_Ofrres_De_Stages = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Ofrres_De_Stages == NULL) {
        printf("Erreur d'ouverture du fichier des offres de stages.\n");
        exit(1);
    }

    while (fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage) == 3) {
        tabReferenceStage[i] = reference_stage;
        tabDepartementStage[i] = departement_stage;
        tabStatueStage[i] = statu_stage;

        if (statu_stage == 0) {
            fscanf(fichier_Ofrres_De_Stages, "%d", &nombre_Candidats);
            tabNombreCandidats[i] = nombre_Candidats;

            a = i * 5;  
            for (j = 0; j < nombre_Candidats; j++) {
                fscanf(fichier_Ofrres_De_Stages, "%d", &numeroCandidat);
                tabNumerosCandidats[a + j] = numeroCandidat;
            }
        }
        i++;
    }
    fclose(fichier_Ofrres_De_Stages);

    for (b = 0; b < i; b++) {
        if (tabReferenceStage[b] == reference_Stage_Candidature && tabStatueStage[b] == 0) {
            position_Reference_Stage = b;
            break;
        }
    }

    if (position_Reference_Stage == -1) {
        printf("Stage avec reference %d introuvable ou non disponible pour candidature.\n", reference_Stage_Candidature);
        return;
    }

    int indexCandidat = position_Reference_Stage * 5 + tabNombreCandidats[position_Reference_Stage];
    tabNumerosCandidats[indexCandidat] = *numeroEtudiant;
    tabNombreCandidats[position_Reference_Stage]++;

    fichier_Ofrres_De_Stages = fopen("Fichier_Offres_De_Stages.txt", "w");
    if (fichier_Ofrres_De_Stages == NULL) {
        printf("Erreur d'ouverture du fichier des offres de stages pour mise a jour.\n");
        exit(1);
    }

    for (b = 0; b < i; b++) {
        fprintf(fichier_Ofrres_De_Stages, "%d %d\n%d\n", tabReferenceStage[b], tabDepartementStage[b], tabStatueStage[b]);
        
        if (tabStatueStage[b] == 0) {
            fprintf(fichier_Ofrres_De_Stages, "%d\n", tabNombreCandidats[b]);
            
            for (j = 0; j < tabNombreCandidats[b]; j++) {
                fprintf(fichier_Ofrres_De_Stages, "%d\n", tabNumerosCandidats[b * 5 + j]);
            }
        }
    }

    fprintf(fichier_Ofrres_De_Stages, "\n");
    fclose(fichier_Ofrres_De_Stages);

    printf("Candidature ajoutee avec succes au stage %d.\n", reference_Stage_Candidature);

}
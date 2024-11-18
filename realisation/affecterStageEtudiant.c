#include "fonctions.h"

void affecterStageEtudiant(void)
{
    int referenceStage, numeroEtudiant;
    int tabReferenceStage[1000] = {0}, tabDepartementStage[1000] = {0}, tabStatutStage[1000] = {0};
    int tabNombreCandidats[1000] = {0}, tabNumerosCandidats[3000] = {0}; 
    int tabNumeroEtudiant[1000] = {0}, tabReferenceStageEtudiant[1000] = {0}, tabNoteFinale[1000] = {0};
    int reference_stage, departement_stage, statu_stage, nombre_Candidats, numeroCandidat;
    int numeroEtudiantDansLigne, reference_stageLigne, noteFinaleligne;
    int i = 0, j, a, positionStage = -1, positionEtudiant = -1, candidatTrouve = 0;
    int menuQuitter;
    FILE *fichier_Offres, *fichier_Etudiants;

    printf("Saisissez la référence du stage : ");
    scanf("%d", &referenceStage);


    printf("Saisissez le numéro de l'étudiant : ");
    scanf("%d", &numeroEtudiant);
    
    fichier_Offres = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Offres == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des offres de stages.\n");
        return;
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

    for (j = 0; j < i; j++)
    {
        if (tabReferenceStage[j] == referenceStage)
        {
            positionStage = j;
            break;
        }
    }

    if (positionStage == -1)
    {
        printf("Erreur : le stage avec la référence %d est introuvable.\n", referenceStage);
        return;
    }

    if (tabStatutStage[positionStage] == 1)
    {
        printf("Erreur : le stage avec la référence %d est déjà pourvu.\n", referenceStage);
        return;
    }

    if (tabNombreCandidats[positionStage] == 0)
    {
        printf("Erreur : le stage avec la référence %d n'a aucun candidat.\n", referenceStage);
        return;
    }

    a = positionStage * 3;
    for (j = 0; j < tabNombreCandidats[positionStage]; j++)
    {
        if (tabNumerosCandidats[a + j] == numeroEtudiant)
        {
            candidatTrouve = 1;
            break;
        }
    }

    if (candidatTrouve == 0)
    {
        printf("Erreur : l'étudiant %d n'a pas candidaté à ce stage.\n", numeroEtudiant);
        return;
    }

    tabStatutStage[positionStage] = 1; 
    tabNombreCandidats[positionStage] = 0; 

    fichier_Offres = fopen("Fichier_Offres_De_Stages.txt", "w");
    if (fichier_Offres == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des offres de stages pour mise à jour.\n");
        return;
    }

    for (j = 0; j < i; j++)
    {
        fprintf(fichier_Offres, "%d %d\n%d\n", tabReferenceStage[j], tabDepartementStage[j], tabStatutStage[j]);
        if (tabStatutStage[j] == 0)
        {
            fprintf(fichier_Offres, "%d\n", tabNombreCandidats[j]);
            a = j * 3;
            for (int k = 0; k < tabNombreCandidats[j]; k++)
            {
                fprintf(fichier_Offres, "%d\n", tabNumerosCandidats[a + k]);
            }
        }
    }
    fclose(fichier_Offres);

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des étudiants.\n");
        return;
    }

    i = 0;
    while (fscanf(fichier_Etudiants, "%d%d%d", &numeroEtudiantDansLigne, &reference_stageLigne, &noteFinaleligne) == 3)
    {
        tabNumeroEtudiant[i] = numeroEtudiantDansLigne;
        tabReferenceStageEtudiant[i] = reference_stageLigne;
        tabNoteFinale[i] = noteFinaleligne;

        if (numeroEtudiantDansLigne == numeroEtudiant)
        {
            positionEtudiant = i;
        }
        i++;
    }
    fclose(fichier_Etudiants);

    if (positionEtudiant == -1)
    {
        printf("Erreur : l'étudiant %d est introuvable.\n", numeroEtudiant);
        return;
    }

    tabReferenceStageEtudiant[positionEtudiant] = referenceStage;

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "w");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des étudiants pour mise à jour.\n");
        return;
    }

    for (j = 0; j < i; j++)
    {
        fprintf(fichier_Etudiants, "%d %d %d\n", tabNumeroEtudiant[j], tabReferenceStageEtudiant[j], tabNoteFinale[j]);
    }
    fclose(fichier_Etudiants);

    printf("L'étudiant %d a été affecté au stage %d avec succès.\n", numeroEtudiant, referenceStage);

    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;
}

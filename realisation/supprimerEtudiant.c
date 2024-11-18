#include "fonctions.h"


void supprimerEtudiant(void)
{
    int numeroEtudiantASupprimer;
    int tabNumeroEtudiant[1000] = {0}, tabReferenceStage[1000] = {0}, tabNoteFinale[1000] = {0};
    int tabReferenceStageOffre[1000] = {0}, tabDepartementStage[1000] = {0}, tabStatutStage[1000] = {0}, tabNombreCandidats[1000] = {0}, tabNumerosCandidats[5000] = {0};
    int numeroEtudiant, reference_stage, noteFinale, reference_stageFichier, departement_stage, statu_stage, nombre_Candidats, numeroCandidat;
    int i = 0, j, k, a, b = 0, positionEtudiant = -1;
    int menuQuitter;
    FILE *fichier_Etudiants, *fichier_Offres;

    afficherListeEtudiants();
    printf("Saisissez le numéro de l'étudiant à supprimer :\n");
    scanf("%d", &numeroEtudiantASupprimer);

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur d'ouverture du fichier des étudiants.\n");
        exit(1);
    }

    while (fscanf(fichier_Etudiants, "%d%d%d", &numeroEtudiant, &reference_stage, &noteFinale) == 3)
    {
        tabNumeroEtudiant[i] = numeroEtudiant;
        tabReferenceStage[i] = reference_stage;
        tabNoteFinale[i] = noteFinale;

        if (numeroEtudiant == numeroEtudiantASupprimer)
        {
            positionEtudiant = i; 
        }
        i++;
    }
    fclose(fichier_Etudiants);

    if (positionEtudiant == -1)
    {
        printf("Erreur : étudiant avec le numéro %d introuvable.\n", numeroEtudiantASupprimer);
        return;
    }

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "w");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur d'ouverture du fichier des étudiants pour mise à jour.\n");
        exit(1);
    }

    for (j = 0; j < i; j++)
    {
        if (j != positionEtudiant)
        {
            fprintf(fichier_Etudiants, "%d %d %d\n", tabNumeroEtudiant[j], tabReferenceStage[j], tabNoteFinale[j]);
        }
    }
    fclose(fichier_Etudiants);

    fichier_Offres = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Offres == NULL)
    {
        printf("Erreur d'ouverture du fichier des offres de stages.\n");
        exit(1);
    }

    i = 0;
    while (fscanf(fichier_Offres, "%d%d%d", &reference_stageFichier, &departement_stage, &statu_stage) == 3)
    {
        tabReferenceStageOffre[i] = reference_stageFichier;
        tabDepartementStage[i] = departement_stage;
        tabStatutStage[i] = statu_stage;

        if (statu_stage == 0)
        {
            fscanf(fichier_Offres, "%d", &nombre_Candidats);
            tabNombreCandidats[i] = nombre_Candidats;

            a = i * 5; 
            for (j = 0; j < nombre_Candidats; j++)
            {
                fscanf(fichier_Offres, "%d", &numeroCandidat);
                tabNumerosCandidats[a + j] = numeroCandidat;
            }
        }
        i++;
    }
    fclose(fichier_Offres);

    fichier_Offres = fopen("Fichier_Offres_De_Stages.txt", "w");
    if (fichier_Offres == NULL)
    {
        printf("Erreur d'ouverture du fichier des offres de stages pour mise à jour.\n");
        exit(1);
    }

    for (b = 0; b < i; b++)
    {
        fprintf(fichier_Offres, "%d %d\n%d\n", tabReferenceStageOffre[b], tabDepartementStage[b], tabStatutStage[b]);

        if (tabStatutStage[b] == 0)
        {
            int nouveauxCandidats = 0;
            a = b * 5;

            for (j = 0; j < tabNombreCandidats[b]; j++)
            {
                if (tabNumerosCandidats[a + j] != numeroEtudiantASupprimer)
                {
                    tabNumerosCandidats[a + nouveauxCandidats] = tabNumerosCandidats[a + j];
                    nouveauxCandidats++;
                }
            }

            fprintf(fichier_Offres, "%d\n", nouveauxCandidats);
            for (j = 0; j < nouveauxCandidats; j++)
            {
                fprintf(fichier_Offres, "%d\n", tabNumerosCandidats[a + j]);
            }
        }
    }
    fclose(fichier_Offres);

    printf("L'étudiant avec numéro %d a été supprimé avec succès.\n", numeroEtudiantASupprimer);

    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;
}

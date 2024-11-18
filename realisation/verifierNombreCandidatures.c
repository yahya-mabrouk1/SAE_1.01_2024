#include "fonctions.h"


int verifierNombreCandidatures(int *numeroEtudiant)
{
    int reference_stage, departement_stage, statu_stage, nombre_Candidats;
    int tab_numeros_des_candidats[100]; 
    int i; 
    FILE *fichier_Ofrres_De_Stages, *fichier_Etudiants;
    int nombreCandidatures = 0; 
    int numeroEtudiantDansLigne, reference_stageLigne, noteFinaleligne; 
    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL)
    {
        printf("Problème d'ouverture du fichier des étudiants.\n");
        exit(1);
    }

    fscanf(fichier_Etudiants, "%d%d%d", &numeroEtudiantDansLigne, &reference_stageLigne, &noteFinaleligne);
    while (!feof(fichier_Etudiants))
    {
        if (numeroEtudiantDansLigne == *numeroEtudiant)
        {
            if (reference_stageLigne != -1)
            {
                fclose(fichier_Etudiants);
                return 5;
            }
        }
        fscanf(fichier_Etudiants, "%d%d%d", &numeroEtudiantDansLigne, &reference_stageLigne, &noteFinaleligne);
    }

    fclose(fichier_Etudiants);

    fichier_Ofrres_De_Stages = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Ofrres_De_Stages == NULL)
    {
        printf("Erreur d'ouverture du fichier des offres de stages.\n");
        exit(1);
    }

    fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage);
    while (!feof(fichier_Ofrres_De_Stages))
    {
        if (statu_stage == 0)
        {
            fscanf(fichier_Ofrres_De_Stages, "%d", &nombre_Candidats);

            if (nombre_Candidats > 0)
            {
                i = 0;
                while (i < nombre_Candidats)
                {
                    fscanf(fichier_Ofrres_De_Stages, "%d", &tab_numeros_des_candidats[i]);
                    if (tab_numeros_des_candidats[i] == *numeroEtudiant)
                    {
                        nombreCandidatures++;
                    }
                    i++;
                }
            }
        }

        fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage);
    }

    fclose(fichier_Ofrres_De_Stages);

    return nombreCandidatures;
}

#include "fonctions.h"


int chercherMesCandidatures(int *numeroEtudiant)
{
    int reference_stage, departement_stage, statu_stage, nombre_Candidats;
    int tab_numeros_des_candidats[100]; 
    int i; 
    FILE *fichier_Ofrres_De_Stages, *fichier_Etudiants;
    int nombreCandidatures = 0; 
    int numeroEtudiantDansLigne, reference_stageLigne, noteFinaleligne; 
    int menuQuitter;

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL) {
        printf("Probleme d'ouverture du fichier des etudiants.\n");
        exit(1);
    }

    fscanf(fichier_Etudiants, "%d%d%d", &numeroEtudiantDansLigne, &reference_stageLigne, &noteFinaleligne);
    while (!feof(fichier_Etudiants)) {
        if (numeroEtudiantDansLigne == *numeroEtudiant) {
            if (reference_stageLigne != -1) {
                printf("Felicitation! vous etes accepte dans le stage de reference '%d'!\n", reference_stageLigne);
                fclose(fichier_Etudiants);
                exit(1);
            }
        }
        fscanf(fichier_Etudiants, "%d%d%d", &numeroEtudiantDansLigne, &reference_stageLigne, &noteFinaleligne);
    }

    fclose(fichier_Etudiants);

    fichier_Ofrres_De_Stages = fopen("Fichier_Offres_De_Stages.txt", "r");
    if (fichier_Ofrres_De_Stages == NULL) {
        printf("Erreur d'ouverture du fichier des offres de stages.\n");
        exit(1);
    }

    printf("Reference de stage :\tDepartement :\tNombre des candidats :\n");

    fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage);
    while (!feof(fichier_Ofrres_De_Stages)) {
        if (statu_stage == 0) {
            fscanf(fichier_Ofrres_De_Stages, "%d", &nombre_Candidats);

            if (nombre_Candidats > 0) {
                i = 0;
                while (i < nombre_Candidats) {
                    fscanf(fichier_Ofrres_De_Stages, "%d", &tab_numeros_des_candidats[i]);
                    if (tab_numeros_des_candidats[i] == *numeroEtudiant) 
                    {
                        printf("\t%d\t\t\t%d\t\t%d\n", reference_stage, departement_stage, nombre_Candidats);
                        nombreCandidatures++;
                    }
                    i++;
                }
            }
        }

        fscanf(fichier_Ofrres_De_Stages, "%d%d%d", &reference_stage, &departement_stage, &statu_stage);
    }

    if (nombreCandidatures == 0) {
        printf("\n\n>>>>>>>>>>Aucune candidature a l'instant !<<<<<<<<<<\n");
    }

    fclose(fichier_Ofrres_De_Stages);

    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return nombreCandidatures;

}

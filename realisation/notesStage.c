#include "fonctions.h"

void notesStage(void)
{
    int numeroEtudiant, menuQuitter;
    int choix, nouvelleNote = 0;
    float noteEntreprise, noteRapport, noteSoutenance, moyenne = 0.0;
    float tabNoteFinale[1000] = {0}; 
    int tabNumeroEtudiant[1000] = {0}, tabReferenceStage[1000] = {0};
    int numeroEtudiantDansLigne, reference_stageLigne;
    float noteFinaleLigne;
    int i = 0, positionEtudiant = -1;
    FILE *fichier_Etudiants;

    printf("Saisissez le numéro de l'étudiant : ");
    scanf("%d", &numeroEtudiant);


    printf("Choisi :\n");
    printf("1 - Pour donner des notes maintenant\n");
    printf("2 - Pour donner la mention -99 (stage en cours)\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    if ((choix!= 1) && (choix != 2))
    {
        printf("Erreur : choix invalide. Veuillez réessayer.\n");
        return;
    }

    if (choix == 1)
    {
        printf("Entrez la note de l'entreprise (sur 20) : ");
        scanf("%f", &noteEntreprise);
        printf("Entrez la note du rapport (sur 20) : ");
        scanf("%f", &noteRapport);
        printf("Entrez la note de la soutenance (sur 20) : ");
        scanf("%f", &noteSoutenance);

        moyenne = (2 * noteEntreprise + noteRapport + noteSoutenance) / 4;
    }
    else
    {
        moyenne = -99;  
    }

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "r");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des étudiants.\n");
        return;
    }

    while (fscanf(fichier_Etudiants, "%d%d%f", &numeroEtudiantDansLigne, &reference_stageLigne, &noteFinaleLigne) == 3)
    {
        tabNumeroEtudiant[i] = numeroEtudiantDansLigne;
        tabReferenceStage[i] = reference_stageLigne;
        tabNoteFinale[i] = noteFinaleLigne;

        if (numeroEtudiantDansLigne == numeroEtudiant)
        {
            positionEtudiant = i; 
        }
        i++;
    }
    fclose(fichier_Etudiants);

    if (positionEtudiant == -1)
    {
        printf("Erreur : l'étudiant avec le numéro %d est introuvable.\n", numeroEtudiant);
        return;
    }

    tabNoteFinale[positionEtudiant] = moyenne;

    fichier_Etudiants = fopen("Fichier_Etudiants.txt", "w");
    if (fichier_Etudiants == NULL)
    {
        printf("Erreur : impossible d'ouvrir le fichier des étudiants pour mise à jour.\n");
        return;
    }

    for (int j = 0; j < i; j++)
    {
        if (tabNoteFinale[j] == -99 || tabNoteFinale[j] == -1)
        {
            fprintf(fichier_Etudiants, "%d %d %.0f\n", tabNumeroEtudiant[j], tabReferenceStage[j], tabNoteFinale[j]);
        }
        else
        {
            fprintf(fichier_Etudiants, "%d %d %.2f\n", tabNumeroEtudiant[j], tabReferenceStage[j], tabNoteFinale[j]);
        }
    }
    fclose(fichier_Etudiants);

    if ((int)moyenne == -99)
    {
        printf("La mention '-99' (stage en cours) a été attribuée à l'étudiant %d avec succès.\n", numeroEtudiant);
    }
    else
    {
        printf("La note finale %.2f a été attribuée à l'étudiant %d avec succès.\n", moyenne, numeroEtudiant);
    }

    printf("/\n/\n/\n/\n");
    printf("Choisi :\n\t1- Pour retourner au menu.\n\t2- Pour quiter.\n");
    scanf("%d", &menuQuitter);
    if (menuQuitter==1)
        test();
    if(menuQuitter==2)
        return;
}

#include "fonctions.h"

void test (void)
{
    int choixIdentification, choixMenuEtudiant, choixMenuResponsable;
    int numeroEtudiant;
    int nombreCandidatures;
    FILE *fichier_Etudiants, *fichier_Ofrres_De_Stages;


    choixIdentification = identification();

    if (choixIdentification==1)
    {

        numeroEtudiant = saisieNumeroEtudiant();
        while(numeroEtudiant==-1)
            {
            numeroEtudiant = saisieNumeroEtudiant();
            }


        choixMenuEtudiant = menuEtudiant();


        switch (choixMenuEtudiant)
        {
            case 1:
                consulterOffresStagesDisponibles();
                break;

            case 2:
                nombreCandidatures = chercherMesCandidatures(&numeroEtudiant);
                break;

            case 3:
                consulterOffresStagesDisponiblesSelonDepartement();
                break;

            case 4:
                nombreCandidatures = verifierNombreCandidatures(&numeroEtudiant);

                if ((nombreCandidatures != 3) && (nombreCandidatures != 5))
                {
                    candidaterStage(&numeroEtudiant);
                }
                else if (nombreCandidatures == 3)
                {
                    printf("Vous avez atteint le nombre maximum des candidatures possibles.\n");
                }
                else if (nombreCandidatures == 5)
                {
                    printf("Vous êtes déjà accepté dans un stage, vous ne pouvez pas candidater sur un autre.\n");
                }
                break;

            default:
                printf("Option invalide.\n");
                break;
        }

    }



    if (choixIdentification==2)
    {
        choixMenuResponsable = menuResponsable();

        switch (choixMenuResponsable)
        {
            case 1:
                supprimerEtudiant();
                break;
            
            case 2:
                ajouterStage();
                break;

            case 3:
                supprimerStage();
                break;

            case 4:
                affecterStageEtudiant();
                break;

            case 5:
                notesStage();
                break;
                
            case 6:
                afficherNotesDecroissant();
                break;

            case 7:
                afficherStagesPourvus();
                break;
                
            case 8:
                afficherToutStagesStatue0();
                break;

            case 9:
                afficherEtudiantsSansStage();
                break;
                
            case 10:
                informationsStage();
                break;
                
            case 11:
                chercherStageSelonEtudiant();
                break;

            case 12:
                chercherToutStagesSelonDepartement();
                break;
                
            default:
                break;
        }

        
    }
}






int main (void)
{
    test();
    return 0;
}
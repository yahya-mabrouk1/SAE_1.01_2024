/**
 * \file fonctions.h
 * \brief Déclare les fonctions principales pour la gestion des stages.
 * \author Yahya Mabrouk / Ismail Kssiouar
 * \date 01/11/2024
 *
 * Ce fichier regroupe les prototypes des fonctions utilisées pour la gestion 
 * des fonctions dans l'application.
*/

// Pour utiliser printf, scanf, fprintf, ...
#include <stdio.h>
// Pour utiliser exit
#include <stdlib.h>
// Pour utiliser les chaines des caracteres
#include<string.h>


/**
 * \brief Permet d'identifier l'utilisateur.
 * \return Un entier correspondant au choix de l'utilisateur :
 *           1 pour un étudiant.
 *           2 pour le responsable des stages.
 *         Si l'utilisateur entre un choix invalide, une erreur est affichée et
 *         un nouveau choix est demandé.
 */
int identification(void);


/**
 * \brief Affiche le menu principal pour un étudiant et récupère son choix.
 * \return Un entier correspondant au choix de l'étudiant :
 *           1 pour consulter la liste des offres de stages disponibles.
 *           2 pour afficher ses candidatures.
 *           3 pour consulter les offres disponibles selon le numéro du département.
 *           4 pour candidater à un stage.
 *         En cas de saisie invalide, un message d'erreur est affiché et une nouvelle saisie est demandée.
 */
int menuEtudiant(void);


/**
 * \brief Affiche la liste des offres de stages disponibles.
 *
 * Cette fonction lit le fichier contenant les offres de stages ("Fichier_Offres_De_Stages.txt") 
 * et affiche les offres disponibles, c'est-à-dire celles qui ne sont pas encore pourvues 
 * (statut == 0) et qui n'ont pas atteint le nombre maximum de candidatures (3).
 * 
 * La fonction affiche pour chaque offre disponible :
 * - La référence du stage.
 * - Le département où se déroule le stage.
 * - Le nombre de candidats actuels.
 * - Les numéros des candidats si applicable.
 *
 * Si le fichier ne peut pas être ouvert, un message d'erreur est affiché et l'exécution s'arrête.
 * Si aucune offre disponible n'est trouvée, un message approprié est affiché.
 */
void consulterOffresStagesDisponibles(void);


/**
 * \brief Permet à un étudiant de saisir son numéro et vérifie sa validité.
 *
 * Cette fonction demande à l'utilisateur de saisir son numéro étudiant, puis vérifie 
 * s'il existe dans le fichier "Fichier_Etudiants.txt". 
 * - Si le numéro est valide (existe dans le fichier), il est retourné.
 * - Si le numéro est invalide ou si le fichier ne peut pas être ouvert, un message d'erreur 
 *   est affiché et l'exécution s'arrête.
 * - Si le numéro n'est pas trouvé dans le fichier, la fonction retourne -1.
 *
 * \return Le numéro d'étudiant validé ou -1 si le numéro est introuvable.
 */
int saisieNumeroEtudiant(void);


/**
 * \brief Recherche et affiche les candidatures d'un étudiant sur des stages.
 *
 * Cette fonction vérifie les candidatures de l'étudiant dans deux fichiers :
 * - Dans "Fichier_Etudiants.txt" : Si l'étudiant a déjà été accepté dans un stage, 
 *   un message de félicitations est affiché et l'exécution s'arrête.
 * - Dans "Fichier_Offres_De_Stages.txt" : Elle recherche les stages pour lesquels 
 *   l'étudiant a postulé et affiche leurs informations (référence, département, 
 *   et nombre de candidats).
 *
 * Si l'étudiant n'a aucune candidature en cours, un message approprié est affiché.
 *
 * \param numeroEtudiant [in] Pointeur sur le numéro de l'étudiant à rechercher.
 * \return Le nombre de candidatures trouvées pour l'étudiant.
 */
int chercherMesCandidatures(int *numeroEtudiant);



/**
 * \brief Affiche les offres de stages disponibles pour un département spécifique.
 *
 * Cette fonction permet à l'utilisateur de saisir un numéro de département, puis
 * affiche les offres de stages disponibles dans ce département. Les informations 
 * affichées incluent :
 * - La référence du stage.
 * - Le numéro du département.
 * - Le nombre de candidats actuels.
 * - Les numéros des candidats (le cas échéant).
 *
 * La fonction traite uniquement les stages qui :
 * - Sont disponibles (statut == 0).
 * - N'ont pas atteint le nombre maximum de candidatures (moins de 3).
 *
 * Si aucune offre n'est trouvée dans le département spécifié, un message approprié
 * est affiché.
 *
 * \note Si le fichier des offres de stages ne peut pas être ouvert, l'exécution s'arrête
 *       avec un message d'erreur.
 */
void consulterOffresStagesDisponiblesSelonDepartement(void);



/**
 * \brief Permet à un étudiant de candidater à un stage.
 *
 * Cette fonction permet à un étudiant, identifié par son numéro, de postuler 
 * pour un stage en spécifiant la référence du stage souhaité. Elle met à jour 
 * les données des offres de stages dans le fichier "Fichier_Offres_De_Stages.txt".
 *
 * Étapes principales :
 * - L'utilisateur saisit la référence du stage souhaité.
 * - Le fichier des offres de stages est ouvert et lu pour vérifier la disponibilité du stage.
 * - Si le stage est disponible (statut == 0 et nombre de candidatures < 3), 
 *   la candidature est ajoutée et le nombre de candidats est mis à jour.
 * - Les nouvelles données sont réécrites dans le fichier.
 *
 * En cas d'erreur :
 * - Si le fichier ne peut pas être ouvert, un message d'erreur est affiché et 
 *   l'exécution s'arrête.
 * - Si le stage est introuvable ou non disponible, un message d'information est affiché.
 *
 * \param numeroEtudiant [in] Pointeur sur le numéro de l'étudiant postulant.
 */
void candidaterStage(int *numeroEtudiant);




/**
 * \brief Vérifie le nombre de candidatures effectuées par un étudiant.
 *
 * Cette fonction détermine combien de candidatures un étudiant a déjà soumises. 
 * Elle recherche également si l'étudiant a été accepté dans un stage.
 *
 * Fonctionnement :
 * - Vérifie d'abord dans le fichier "Fichier_Etudiants.txt" si l'étudiant a 
 *   été affecté à un stage. Si c'est le cas, elle retourne 5 (indiquant une 
 *   acceptation dans un stage).
 * - Parcourt ensuite le fichier "Fichier_Offres_De_Stages.txt" pour compter 
 *   les candidatures en cours de l'étudiant.
 *
 * \param numeroEtudiant [in] Pointeur sur le numéro de l'étudiant à vérifier.
 * \return 
 *         - 5 si l'étudiant a déjà été accepté dans un stage.
 *         - Le nombre de candidatures en cours pour l'étudiant, sinon.
 */
int verifierNombreCandidatures(int *numeroEtudiant);


/**
 * \brief Affiche le menu principal pour le responsable des stages et récupère son choix.
 *
 * Cette fonction présente un menu avec les différentes options disponibles pour le
 * responsable des stages. Elle demande à l'utilisateur de sélectionner une option
 * en entrant un entier entre 1 et 12.
 *
 * \return Un entier correspondant au choix de l'utilisateur :
 *         - 1 : Supprimer un étudiant.
 *         - 2 : Ajouter une offre de stage.
 *         - 3 : Supprimer une offre de stage.
 *         - 4 : Affecter un stage à un étudiant.
 *         - 5 : Donner trois notes à un étudiant.
 *         - 6 : Afficher les notes des étudiants par ordre décroissant.
 *         - 7 : Afficher les stages pourvus avec les étudiants affectés à ces stages.
 *         - 8 : Afficher les stages non pourvus.
 *         - 9 : Afficher les étudiants n’ayant pas de stages.
 *         - 10 : Afficher les informations sur un stage donné.
 *         - 11 : Chercher un stage selon le numéro de l'étudiant accepté.
 *         - 12 : Chercher des stages selon le département.
 *
 */
int menuResponsable(void);

/**
 * \brief Supprime un étudiant et met à jour les fichiers associés.
 *
 * Cette fonction permet au responsable de supprimer un étudiant à partir de son numéro.
 * Elle effectue les étapes suivantes :
 * - Charge les données des étudiants depuis le fichier "Fichier_Etudiants.txt".
 * - Vérifie si l'étudiant existe et supprime ses informations du fichier.
 * - Met à jour le fichier "Fichier_Offres_De_Stages.txt" en supprimant l'étudiant
 *   des listes de candidats des stages où il a postulé.
 * - Affiche un message confirmant la suppression de l'étudiant.
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 *
 */
void supprimerEtudiant(void);


/**
 * \brief Ajoute un nouveau stage dans le fichier des offres de stages.
 *
 * Cette fonction permet au responsable d'ajouter un nouveau stage dans le système.
 * Elle effectue les étapes suivantes :
 * - Charge les données des stages existants depuis le fichier "Fichier_Offres_De_Stages.txt".
 * - Détermine automatiquement la référence du nouveau stage (incrémentée à partir
 *   de la dernière référence existante ou initialisée à 1 si aucun stage n'existe).
 * - Demande à l'utilisateur de saisir le département du nouveau stage.
 * - Ajoute le nouveau stage avec un statut par défaut de `0` (non pourvu) et aucun candidat.
 * - Met à jour le fichier "Fichier_Offres_De_Stages.txt".
 * - Affiche un message confirmant l'ajout réussi du stage.
 *
 *
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 *
 */
void ajouterStage(void);

/**
 * \brief Supprime une offre de stage du fichier des stages.
 *
 * Cette fonction permet au responsable de supprimer une offre de stage à partir de sa référence.
 * Elle effectue les étapes suivantes :
 * - Affiche tous les stages non pourvus (statut = 0).
 * - Demande au responsable de saisir la référence du stage à supprimer.
 * - Charge les données des stages depuis le fichier "Fichier_Offres_De_Stages.txt".
 * - Vérifie si la référence existe dans le fichier.
 * - Si la référence est trouvée, elle supprime l'entrée correspondante et met à jour
 *   les informations restantes dans le fichier.
 *
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void supprimerStage(void);


/**
 * \brief Affiche la liste des étudiants inscrits dans le fichier des étudiants.
 *
 * Cette fonction lit les données du fichier "Fichier_Etudiants.txt" et affiche
 * les informations suivantes pour chaque étudiant :
 * - Numéro de l'étudiant
 * - Référence du stage associé
 * - Note finale (si disponible)
 *
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void afficherListeEtudiants(void);

/**
 * \brief Affiche tous les stages non pourvus (statut différent de 1).
 *
 * Cette fonction lit les données du fichier "Fichier_Offres_De_Stages.txt" et affiche
 * les informations des stages non pourvus. Pour chaque stage, elle affiche :
 * - La référence du stage
 * - Le département associé au stage
 * - Le nombre de candidats associés au stage
 * - Les numéros des candidats (si disponibles)
 *
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 *
 */
void afficherToutStagesStatue0(void);


/**
 * \brief Affecte un étudiant à un stage spécifique.
 *
 * Cette fonction permet au responsable d'affecter un étudiant à un stage donné, à condition que :
 * - Le stage soit disponible (statut = 0).
 * - L'étudiant ait postulé pour ce stage.
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void affecterStageEtudiant(void);


/**
 * \brief controler tout les fonctions.
 *
 * Cette fonction est la fonction globale.
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void test (void);

/**
 * \brief Attribue une note finale ou une mention "stage en cours" à un étudiant.
 *
 * Cette fonction permet au responsable de gérer la note finale d'un étudiant :
 * - Soit en attribuant une mention spéciale `-99` qui signifie "stage en cours".
 * - Soit en calculant et en enregistrant une note moyenne basée sur trois composantes
 *   (note d'entreprise, note de rapport, et note de soutenance).
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void notesStage(void);


/**
 * \brief Affiche les notes finales des étudiants par ordre décroissant.
 *
 * Cette fonction lit les données du fichier "Fichier_Etudiants.txt" et affiche les
 * informations des étudiants (numéro, référence de stage et note finale) triées par
 * note finale dans l'ordre décroissant.
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void afficherNotesDecroissant(void);


/**
 * \brief Affiche les stages pourvus avec les étudiants qui leur sont affectés.
 *
 * Cette fonction parcourt les données du fichier "Fichier_Etudiants.txt" pour identifier
 * les stages pourvus, c'est-à-dire les stages ayant une référence différente de `-1`. Elle
 * affiche ensuite les informations suivantes pour chaque stage pourvu :
 * - La référence du stage.
 * - Le numéro de l'étudiant affecté.
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void afficherStagesPourvus(void);

/**
 * \brief Affiche les étudiants qui n'ont pas encore été affectés à un stage.
 *
 * Cette fonction parcourt les données du fichier "Fichier_Etudiants.txt" pour identifier
 * les étudiants dont la référence de stage est égale à `-1`, indiquant qu'ils n'ont pas
 * encore de stage. Elle affiche les informations suivantes :
 * - Le numéro de l'étudiant.
 * - La référence de stage (toujours égale à `-1` pour ces étudiants).
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void afficherEtudiantsSansStage(void);


/**
 * \brief Affiche les informations détaillées sur un stage spécifique.
 *
 * Cette fonction permet de rechercher et d'afficher les informations d'un stage
 * spécifique, en fonction de sa référence, dans le fichier "Fichier_Offres_De_Stages.txt".
 * Les informations incluent :
 * - La référence du stage.
 * - Le département.
 * - Le statut du stage (pourvu ou non).
 * - Le nombre de candidats (si le stage n'est pas pourvu).
 * - Les numéros des candidats (si le stage n'est pas pourvu et a des candidats).
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 *
 */
void informationsStage(void);

/**
 * \brief Recherche le stage auquel un étudiant est affecté.
 *
 * Cette fonction permet de rechercher un stage associé à un étudiant spécifique,
 * en fonction de son numéro d'étudiant. Elle affiche l'une des informations suivantes :
 * - Si l'étudiant a un stage, affiche la référence du stage.
 * - Si l'étudiant n'a pas de stage, affiche un message d'erreur.
 * - Si l'étudiant est introuvable dans le fichier, affiche un message d'erreur.
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void chercherStageSelonEtudiant(void);

/**
 * \brief Affiche tous les stages d'un département spécifique.
 *
 * Cette fonction permet de rechercher et d'afficher les informations des stages
 * associés à un département donné. Les informations affichées incluent :
 * - La référence du stage.
 * - Le numéro du département.
 * - Le statut du stage (0 pour non pourvu, 1 pour pourvu).
 * - Le nombre de candidats (si le statut est 0).
 * - Les numéros des candidats (si le statut est 0 et qu'il y a des candidats).
 *
 * \param Aucun paramètre en entrée.
 * \return Aucun retour (void).
 */
void chercherToutStagesSelonDepartement(void);
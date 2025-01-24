# FICHE DESCRIPTIVE de la SAé S1.01 – Implémentation d’un besoin client

## Objectif
Cette SAÉ permet une première mise en pratique du développement autour d'un besoin client.

## Organisation
- **Travail en groupe** : 2 ou 3 étudiants (à préciser avec l’enseignant).
- **Date de rendu** : Vendredi 15/11/2024.

## Production attendue
- Code de l'application.
- Traces d'exécution des jeux d'essais.

---

## 1. Titre de la SAé
**Gestion des stages**

---

## 2. Résumé de la SAé
Cette SAÉ consiste en la conception et le développement d'une application pour la gestion des stages dans un département informatique. 

### Fonctionnalités principales :
1. **Pour le responsable des stages** :
   - Ajouter ou supprimer une offre de stage.
   - Affecter un stage à un étudiant.
2. **Pour les étudiants** :
   - Consulter la liste des offres de stages disponibles.
   - Postuler à un ou plusieurs stages (avec un maximum de 3 candidatures par étudiant).
3. **Pour le jury** :
   - À la fin de l'année, noter les stages effectués.
   - Afficher les notes par ordre décroissant.

---

## 3. Objectifs et contraintes
### Représentation des données :
- **Offre de stage** : référence (entier) et département.
- **Étudiant** : numéro unique, liste de candidatures (max 3), stage affecté.

### Contraintes :
- Maximum 3 candidatures par étudiant.
- Maximum 3 candidatures par stage.
- Suppression des candidatures non retenues après une affectation.

---

## 4. Réalisation

### 4.1 Constitution des fichiers
1. **Fichier des étudiants** :
   - Contient le numéro de chaque étudiant, la référence de son stage et sa note finale.
2. **Fichier des offres de stages** :
   - Contient les références des stages, leur département, leur statut (pourvu/non pourvu) et les candidats.

### 4.2 Candidature
- Un étudiant peut candidater à un stage s'il respecte les contraintes de candidatures.

### 4.3 Affectation
- Affectation quotidienne des stages par le responsable des stages.

### 4.4 Jury
- Attribue des notes en fin d'année :
  - Note d'entreprise (coefficient 2).
  - Note du rapport (coefficient 1).
  - Note de soutenance (coefficient 1).
- Calcul de la note finale.

### 4.5 Affichage
1. **Responsable des stages** :
   - Stages pourvus et étudiants affectés.
   - Stages non pourvus.
   - Liste des étudiants sans stage.
   - Informations sur un stage spécifique.
   - Recherche de stages par critère.
2. **Étudiants** :
   - Stages non pourvus.
   - Leurs candidatures ou stage affecté.
   - Stages par département.

### 4.6 Résultat final
- Classement des étudiants par note finale en ordre décroissant.
- Gestion des cas où un stage est en cours.

### 4.7 Sauvegarde des données
- Sauvegarde automatique des fichiers étudiants et offres de stages à chaque sortie.
- Chargement des données au lancement de l'application.

### 4.8 Fonctionnalités supplémentaires
- Libre aux développeurs d'ajouter des fonctionnalités complémentaires.

---

## 5. Consignes de réalisation

### Spécification
- Liste des fonctionnalités implémentées.
- Description des comportements de chaque fonction.

### Conception
- Structures de données.
- Interaction entre les composants.
- Algorithmes utilisés.

### Développement
- Code de l'application.
- Tests et validations.

---

## Livrables et Évaluation

### Livrables :
1. **Code source de l'application**.
2. **Documentation Doxygen**.
3. **Document descriptif** :
   - Structures de données.
   - Fonctionnalités réalisées.
   - Traces d'exécutions et jeux d'essais.

### Évaluation :
- **Oral avec l'enseignant**.
- **Critères techniques** :
  - Utilisation des notions de : alternatives, fonctions, pointeurs, tableaux, fichiers.
  - Respect des principes algorithmiques.
  - Qualité du code et de sa documentation.

---

**Bon développement !**

#include "entreeSortieLC.h"

void menu(){

    printf("===================================\n");
    printf("Faites votre choix:\n");
    printf("0-Sortie du programme\n");
    printf("1-Affichage de la bibliothèque\n");
    printf("2-Ajouter un ouvrage\n");
    printf("3-Supprimer un ouvrage\n");
    printf("===================================\n");
}

int main(int argc, char** argv){

    if (argc < 3) {
        printf("Usage : %s <fichier.txt> <un_entier>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Récupérer le nom du fichier passé en argument
    char *filename = argv[1];
    int n_entrees = atoi(argv[2]);

    // Vérifier si l'extension est ".txt"
    if (strlen(filename) < 4 || strcmp(filename + strlen(filename) - 4, ".txt") != 0) {
        printf("Erreur : Le fichier doit être un .txt\n");
        return EXIT_FAILURE;
    }

    int choix;
    int num;
    char titre[30]; 
    char auteur[30];

    Biblio* B = charger_n_entrees(filename, n_entrees);
    enregistrer_biblio(B, "Livre_a_lire.txt");

    do{
        
        menu();
        scanf("%d", &choix);

        switch (choix){
            case 0:
                printf("FIN PROGRAMME\n");
                break;
            case 1:
                afficher_biblio(B);
                break;
            case 2:
                printf("Numero, TITRE, Auteur:\n");
                scanf("%d %s %s", &num, titre, auteur);
                inserer_en_tete(B, num, titre, auteur);
                break;
            case 3:
                printf("Numero, TITRE, Auteur:\n");
                scanf("%d %s %s", &num, titre, auteur);
                supprime_Livre(B, num, auteur, titre);
            default:
                
        }

    } while (choix != 0);
    
    liberer_biblio(B);
    return 0;
}
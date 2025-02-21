#include "entreeSortieLC.h"

void menu(){

    printf("===================================\n");
    printf("Faites votre choix:\n");
    printf("0-Sortie du programme\n");
    printf("1-Affichage de la bibliothèque\n");
    printf("2-Ajouter un ouvrage\n");
    printf("3-Supprimer un ouvrage\n");
    printf("4-Rechercher un ouvrage\n");
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

    int num,n;
    char auteur[256], titre[256];
    entree = atoi(argv[2]);
    Biblio* Bibliotheque;
    if (entree == 0) {
        printf("Erreur d'entrée clavier\nSortie du programme\n");
        exit(1);
    }

    Bibliotheque = charger_n_entrees(argv[1],entree);
    do {

    menu();
    printf("Choisissez un chiffre ci-dessus\n");
    scanf("%d",&num);

        switch(num) {
        
        case 0 :

            break;

        case 1 :

            afficher_biblio(Bibliotheque);
            break;

        case 2 :

            do {
            
                printf("+----------------------------------+\n");
                printf("|-1 - Retour au menu principal     |\n");
                printf("| 0 - Sortie du programme          |\n");  
                printf("+----------------------------------+\n");
                printf("|           Recherche              |\n");            
                printf("| 1 - Des ouvrages d'un auteur     |\n");
                printf("| 2 - D'un ouvrage par numéro      |\n");
                printf("| 3 - D'un ouvrage par titre       |\n");
                printf("+----------------------------------+\n");
                printf("Veuillez entrer un chiffre ci-dessus\n");
                scanf("%d",&num);
                switch(num) {
                
                    case -1:
                        break;
                
                    case 1 :
                
                        printf("\n+--------------------------------------+\n");
                        printf("| Recherche des ouvrages d'un auteur |\n");
                        printf("+------------------------------------+\n");
                        printf("Choisissez le nom de l'auteur à rechercher\n");
                        scanf("%s",auteur);
                        Biblio* tmp = recherche_auteur(Bibliotheque, auteur);
                        afficher_biblio(tmp);
                        liberer_biblio(tmp);
                        break;
                
                case 2 :

                    do {
                        printf("\n+-----------------------------------+\n");
                        printf("| Recherche d'un ouvrage par numéro |\n");
                        printf("+-----------------------------------+\n\n");
                        printf("Choisissez le numéro du livre à rechercher\n");
                        printf("Ou entrez -1 pour revenir au menu précédent\n\n");
                        scanf("%d",&n);
                        if (n != -1)
                            recherche_numero(Bibliotheque,n);
                    } while(n!=-1);
                    break;

                case 3 :

                    do {
                        printf("\n+----------------------------------+\n");
                        printf("| Recherche d'un ouvrage par titre |\n");
                        printf("+----------------------------------+\n\n");
                        printf("Choisissez le titre du livre à rechercher\n");
                        printf("Ou entrez -1 pour revenir au menu précédent\n\n");

                        if (scanf("%s",titre) > 0 && atoi(titre)!=-1)
                            recherche_titre(Bibliotheque,titre);
                    } while(atoi(titre)!=-1);
                    break;

                default :

                    printf("\n\nVeuillez entrer un chiffre dans le menu\n\n");
                    break;

                }
            } while(num!=-1 && num != 0);
            break;

        case 3 :

            do {
                printf("\n+---------------------------------------+\n");
                printf("| Ajout d'un livre dans la bibliothèque |\n");
                printf("+---------------------------------------+\n");
                printf("Veuillez entrer un numéro, puis un titre et un auteur\n");
                printf("Ou entrez -1 pour revenir au menu principal\n\n");
                printf("Vous ne pouvez donc pas ajouter de livre ayant comme numéro -1\n");
                printf("----------------------------------------------------------------\n");
                printf("Choix du numéro\n");
                scanf("%d",&n);
                if (n != -1) {
                    printf("Choix du titre et de l'auteur\n");
                    if (scanf("%s %s",titre,auteur)==2) {
                        inserer_en_tete(Bibliotheque,n,titre,auteur);
                        printf("Ajout réalisé\n");
                    }
                    else
                        printf("L'ajout n'a pas été fait\n");
                }
            } while (n != -1);
            break;

        case 4 :

            do {
                printf("\n+-------------------------------------------+\n");
                printf("| Suppression d'un livre de la bibliothèque |\n");
                printf("+-------------------------------------------+\n\n");
                printf("Veuillez entrer un numéro, puis un titre et un auteur\n");
                printf("Ou entrez -1 pour revenir au menu principal\n\n");
                printf("Vous ne pouvez donc pas supprimer de livre ayant comme numéro -1\n");
                printf("----------------------------------------------------------------\n");
                printf("Choix du numéro\n");
                scanf("%d",&n);
                if (n != -1) {
                    printf("Choix du titre et de l'auteur\n");
                    if (scanf("%s %s",titre,auteur)==2) 
                        supprimer_ouvrage(Bibliotheque,n,titre,auteur);
                    else 
                        printf("Erreur de saisie: la suppression n'a pas été réalisée\n");
                }
            } while (n != -1);
            break;
        
        default :

            printf("\n\nVeuillez entrer un chiffre dans le menu\n\n");
            break;     
    } while(num!=0);

    liberer_biblio(Bibliotheque);
    printf("Sortie du programme\nMerci et au revoir!\n");
    return 0;
}
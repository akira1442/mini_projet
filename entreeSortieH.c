#include "entreeSortieH.h"
#include "BiblioH.h"

BiblioH* charger_n_entreesH(char* nomfic, int n) {
    
    if (n < 1) {
        return NULL;
    }

    FILE* f = fopen(nomfic,"r");

    if (f == NULL) {
        fprintf(stderr,"Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    BiblioH* b = creer_biblioH(n);

    int i = 0, num;
    char auteur[256];
    char titre[256];

    while (i < n && fscanf(f,"%d %s %s",&num,titre,auteur) == 3) {
        inserer(b, num, titre, auteur);
        i++;
    }
    
    fclose(f);
    
    return b;
}

void enregistrer_biblioH(BiblioH* b, char* nomfic){
    
    if (b == NULL) {
        fprintf(stderr, "Paramètre invalide\n");
        return;
    }

    FILE* f = fopen(nomfic,"w");
    
    if (f == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier\n");
        return;
    }

    LivreH* tmp = NULL;

    for (int i = 0; i < b->m; i++) {
        tmp = b->T[i];
        while (tmp != NULL){
            fprintf(f, "%d %s %s\n", tmp->num, tmp->titre, tmp->auteur);
            tmp = tmp->suivant;
        }
    }
    fclose(f);
}
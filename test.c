#include "entreeSortieLC.h"

int main(){

    Biblio* B = creer_biblio();
    Biblio* B2 = creer_biblio;

    B = charger_n_entrees("GdeBiblio.txt", 13);

    afficher_biblio(B);

    inserer_en_tete(B, 42, "LA_VIE", "Richard_ENG");
    inserer_en_tete(B, 15, "TETRIS_POUR_LES_NULLS", "Richard_ENG");

    B2 = recherche_Livre_auteur(B, "Richard_ENG");
    Livre* l1 = recherche_Livre_num(B->L ,14)

}
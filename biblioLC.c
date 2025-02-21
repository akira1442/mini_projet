#include "biblioLC.h" 


Livre* creer_livre(int num,char* titre,char* auteur){

	Livre* nouv = (Livre*)malloc(sizeof(Livre));

	nouv->num=num;
	nouv->titre=strdup(titre);
	nouv->auteur=strdup(auteur);
	nouv->suiv = NULL;

	return nouv;
}

void liberer_livre(Livre* l){

	if (l != NULL){
		free(l->titre);
		free(l->auteur);
		free(l);
	}
}

Biblio* creer_biblio(){

	Biblio* b = (Biblio*)malloc(sizeof(Biblio));

	b->L = NULL;
	return b;
}

void liberer_biblio(Biblio* b){

	Livre* tmp = b->L;
	Livre* supp = tmp;
	while (tmp != NULL){
		supp = tmp;
		tmp = tmp->suiv;
		liberer_livre(supp);
	}
	
	free(b);
}

void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur){

	Livre* new_livre = creer_livre(num, titre, auteur);
	
	if (b->L == NULL){
		b->L=new_livre;
	}else{
		new_livre->suiv = b->L;
		b->L = new_livre;
	}
}

void affiche_livre(Livre* l){
	
	if (l == NULL) return;

	printf("%d, %s, %s\n", l->num, l->auteur, l->titre);	
}

void afficher_biblio(Biblio* b){	

	if ((b == NULL) || (b->L == NULL)) {return;}

	Livre* temp = b ->L;
	while (temp){
		affiche_livre(temp);
		temp=temp->suiv;
	}
}

Livre* recherche_Livre_num(Biblio* b, int num){

	if ((b == NULL) || (b->L == NULL)) {return NULL;}

	Livre* temp = b->L;
	
	while (temp){
		if(temp->num == num){
			return temp;
		}
		temp=temp->suiv;
	}
	return temp;
}

Livre* recherche_Livre_titre(Livre* l, char* titre){

	if (l == NULL) {return NULL;}

	Livre* temp = l;

	while (temp != NULL){
		if(strcmp(temp->titre, titre)==0){
			return temp;
		}
		temp=temp->suiv;
	}
	return NULL;
}

Biblio* recherche_Livre_auteur(Biblio* b, char* auteur){

	if ((b == NULL) || (b->L == NULL)) {return NULL;}

	Livre* temp = b->L;
	Biblio* biblio_aut=creer_biblio();
	while(temp){
		if (strcmp(temp->auteur, auteur)==0){
			inserer_en_tete(biblio_aut, temp->num, temp->titre, temp->auteur);
		}
		temp=temp->suiv;
	}
	return biblio_aut;
}

void supprime_Livre(Biblio* b, int num, char* auteur, char* titre){
	
	if ((b == NULL) || (b->L == NULL)){
		return;
	}
	
	Livre* prec = NULL;
	Livre* curr = b->L;

	while(curr){
		if ((curr->num == num) &&  (strcmp(auteur, curr->auteur) == 0) && (strcmp(titre, curr->titre) == 0)){
			// Cas ou la suppression se fait en tête
			if (prec == NULL){
				curr = b->L;
				b->L = b->L->suiv;
			}
			// Cas ou la suppression se fait au milieu ou en queue
			else{
				prec->suiv = curr->suiv;
			}
			liberer_livre(curr);
			printf("%d, %s, %s a ete suppprime\n", num, auteur, titre);
			return;
		}
		prec = curr;
		curr = curr->suiv;
	}
	printf("%d, %s, %s n'est pas dans la bibliotheque\n", num, titre, auteur);
}

void fusion(Biblio** b1, Biblio* b2){

	if ((b2 == NULL) || (b2->L == NULL)) {
		free(b2);
		return;
	}

	Livre* tmp = b2->L;

	// Ajout de b2 en tête de b1 
	// b2 est ajouté a l'en vers
	while (tmp){
		inserer_en_tete(*b1, tmp->num, tmp->titre, tmp->auteur);
		tmp = tmp->suiv;
	}

	liberer_biblio(b2);
}

Livre* recherche_ouvrage(Biblio* b){

	if (b == NULL || b->L == NULL){return NULL;}

	Livre* curr = b->L;
	Livre* head = NULL;
	Livre* tmp = NULL;

	while(curr){
		Livre* rech = recherche_Livre_titre(curr->suiv, curr->titre);
		while(rech != NULL){
			if (head == NULL){
				head = creer_livre(rech->num, rech->titre, rech->auteur); 
			}else{
				tmp = creer_livre(rech->num, rech->titre, rech->auteur);
				tmp->suiv = head;
				head = tmp;
			}
			rech = recherche_Livre_titre(rech->suiv, curr->titre);
		}
		rech = NULL;
		curr = curr->suiv;
	}
	return head;
}

/*Livre* recherche_ouvrage(Biblio* b) {
    if (b==NULL || b->L==NULL) {
        return NULL;
    }
    Livre* tete = NULL;
    Livre* res = NULL;
    Livre* tmp=b->L;
    int nbEx=1;

    while (tmp->suiv != NULL) {
        Livre* suiv = tmp;
        while (suiv != NULL) {
            if ((tmp->num != suiv->num) && (strcmp(suiv->titre,tmp->titre) == 0) && (strcmp(suiv->auteur,tmp->auteur) == 0)) {
                if (nbEx == 1) {
                    if (tete==NULL) {
                        tete=creer_livre(tmp->num,tmp->titre,tmp->auteur);
                        res=tete;
                    }
                    else {
                        res->suiv=creer_livre(tmp->num,tmp->titre,tmp->auteur);
                        res=res->suiv;
                        nbEx++;
                    }
                }
                res->suiv=creer_livre(suiv->num,suiv->titre,suiv->auteur);
                res=res->suiv;
            }
            suiv=suiv->suiv;
        }
        if (nbEx > 1) {
            nbEx=1;
        }
        tmp=tmp->suiv;
    }
    return tete;
}*/


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

	free(l->titre);
	free(l->auteur);
	free(l);
}

Biblio* creer_biblio(){
	Biblio* b = (Biblio*)malloc(sizeof(Biblio));
	b->L = NULL;
	return b;
}

void liberer_biblio(Biblio* b){

	Livre* tmp = b->L;

	while(tmp){
		b->L = b->L->suiv;
		liberer_livre(tmp);
		tmp = b->L;
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

Livre* recherche_Livre_titre(Biblio* b, char* titre){

	if ((b == NULL) || (b->L == NULL)) {return NULL;}

	Livre* temp = b->L;
	while (temp){
		if(strcmp(temp->titre, titre)){
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
		if (strcmp(temp->auteur, auteur)){
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
				b->L = curr->suiv;
				curr = b->L;
			}
			// Cas ou la suppression se fait au milieu ou en queue
			else{
				prec->suiv = curr->suiv;
			}
			liberer_livre(curr);
			printf("%d, %s, %s a ete suppprime\n", num, auteur, titre);
			break;
		}
		curr = curr->suiv;
		prec = prec->suiv;
	}
	printf("%d, %s, %s n'est pas dans la bibliotheque\n", num, titre, auteur);
}

void fusion(Biblio** b1, Biblio* b2){

	if (((b1 == NULL) || ((*b1)->L == NULL)) || ((b2 == NULL) || (b2->L == NULL))) {return;}

	Livre* tmp = b2->L;

	// Ajout de b2 en tête de b1 
	// b2 est ajouté a l'en vers
	while (tmp){
		inserer_en_tete(*b1, tmp->num, tmp->titre, tmp->auteur);
		tmp = tmp->suiv;
	}

	liberer_biblio(b2);
}

Livre* recherche_doublons(Biblio* b){

	Livre* liste = b->L;
	Livre* res_L = NULL;
	Livre* doublon = NULL;

	while (liste){
		doublon = liste->suiv;
		while (doublon && res_L){
			
			if (strcmp(liste->titre, doublon->titre) && strcmp(liste->auteur, doublon->auteur)){
				res_L = (Livre*)malloc(sizeof(Livre));
				res_L->titre = strdup(doublon->titre);
				res_L->auteur = strdup(doublon->auteur);
				res_L->num = doublon->num;
				res_L->suiv = NULL;
				res_L = res_L->suiv;
			}	
		}
	}
	return NULL;
}


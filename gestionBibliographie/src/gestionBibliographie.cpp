//============================================================================
// Name        : gestionBibliographie.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "classe_reference.h"
using namespace std;
using namespace biblio;

/**
 * \brief boucle pour demander les informations a l'utilisateur lors
 * de la creation d'un ouvrage
 */

Ouvrage BoucleCreationOuvrage(){
	std::string p_auteur;
	std::string p_titre;
	std::string p_identifiant;
	std::string p_ville;
	std::string p_editeur;
	int p_annee;

	while(true){
		cout<<"entrez l'auteur de l'ouvrage"<<endl;
		getline(cin, p_auteur);
		if(util::NOM(p_auteur)){
			cout<<"auteur valide"<<endl;
			break;
		}
	}

	while(true){
		cout<<"entrez le titre de l'ouvrage"<<endl;
		getline(cin, p_titre);
		if(util::NOM(p_titre)){
			cout<<"titre valide"<<endl;
			break;
		}
	}

	while(true){
		cout<<"entrez la ville de l'ouvrage"<<endl;
		getline(cin, p_ville);
		if(util::NOM(p_ville)){
			cout<<"ville valide"<<endl;
			break;
		}
	}

	while(true){
		cout<<"entrez l'editeur de l'ouvrage"<<endl;
		getline(cin, p_editeur);
		if(util::NOM(p_editeur)){
			cout<<"editeur valide"<<endl;
			break;
		}
	}

	while(true){
		cout<<"entrez le titre de l'ouvrage"<<endl;
		cin>>p_annee;
		if(p_annee>0){
			cout<<"annee valide"<<endl;
			break;
		}
	}

	while(true){
		cout<<"entrez l'identifiant de l'ouvrage"<<endl;
		getline(cin, p_identifiant);
		if(util::NOM(p_identifiant)){
			cout<<"identifiant valide"<<endl;
			break;
		}
	}

	Ouvrage ouvrage(p_annee, p_titre, p_auteur, p_identifiant, p_ville, p_editeur);
	return ouvrage;
}

int main() {
	cout<<"direct"<<endl;
	return 0;
}

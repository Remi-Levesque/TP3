//============================================================================
// Name        : gestionBibliographie.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "classe_reference.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "Bibliographie.h"
#include <string>
#include <limits>
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

	//bool condition_auteur = false;
	//bool condition_titre = false;
	//bool condition_identifiant = false;
	//bool condition_ville = false;
	//bool condition_editeur = false;
	//bool condition_annee = false;


	while(true){
		cout<<"entrez l'auteur de l'ouvrage"<<endl;
		getline(cin, p_auteur);
		if(util::NOM(p_auteur) == true){
			cout<<"auteur valide"<<endl;
			break;
		}
		cout<<"auteur invalide"<<endl;
	}

	while(true){
		cout<<"entrez le titre de l'ouvrage"<<endl;
		getline(cin, p_titre);
		if(util::NOM(p_titre)){
			cout<<"titre valide"<<endl;
			break;
		}
		cout<<"titre invalide"<<endl;
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

	/// problème de cin à l'infini mon grand pirate des caraïbes
	while(true){
		cout<<"entrez l'annee de l'ouvrage"<<endl;
		cin>>p_annee;
		cin.ignore();
		if(p_annee>0 && p_annee <= 2019){
			cout<<"annee valide"<<endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cin.ignore();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout<<"annee invalide"<<endl;
	}

	while(true){
		cout<<"entrez l'identifiant de l'ouvrage"<<endl;
		getline(cin, p_identifiant);
		if(util::ISBN(p_identifiant) == true || util::ISSN(p_identifiant)){
			cout<<"identifiant valide"<<endl;
			break;
		}
		cout<<"identifiant invalide"<<endl;
	}

	Ouvrage ouvrage(p_annee, p_titre, p_auteur, p_identifiant, p_ville, p_editeur);
	return ouvrage;
}

Journal BoucleCreationJournal(){

	std::string p_auteur;
	std::string p_titre;
	std::string p_identifiant;
	std::string p_nom;
	int p_annee;
	int p_volume;
	int p_numero;
	int p_page;

	while(true){
		cout<<"entrez l'auteur de l'ouvrage"<<endl;
		getline(cin, p_auteur);
		if(util::NOM(p_auteur) == true){
			cout<<"auteur valide"<<endl;
			break;
		}
		cout<<"auteur invalide"<<endl;
	}

	while(true){
			cout<<"entrez le titre de l'ouvrage"<<endl;
			getline(cin, p_titre);
			if(util::NOM(p_titre)){
				cout<<"titre valide"<<endl;
				break;
			}
			cout<<"titre invalide"<<endl;
		}

	while(true){
		cout<<"entrez le nom de l'ouvrage"<<endl;
		getline(cin, p_nom);
		if(util::NOM(p_nom)){
			cout<<"nom valide"<<endl;
			break;
		}
		cout<<"nom invalide"<<endl;
	}

	while(true){
		cout<<"entrez le volume de l'ouvrage"<<endl;
		cin>>p_volume;
		if(p_volume>0){
			cout<<"volume valide"<<endl;
			break;
		}
		cin.clear();
		cin.ignore();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout<<"volume invalide"<<endl;
	}

	while(true){
		cout<<"entrez le numero de l'ouvrage"<<endl;
		cin>>p_numero;
		if(p_numero>0){
			cout<<"numero valide"<<endl;
			break;
		}
		cin.clear();
		cin.ignore();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout<<"numero invalide"<<endl;
	}

	while(true){
		cout<<"entrez la de page de l'ouvrage"<<endl;
		cin>>p_page;
		if(p_page>0){
			cout<<"page valide"<<endl;
			break;
		}
		cin.clear();
		cin.ignore();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout<<"page invalide"<<endl;
	}

	while(true){
		cout<<"entrez l'année de l'ouvrage"<<endl;
		cin>>p_annee;
		if(p_annee>0 && p_annee<=2019){
			cout<<"année valide"<<endl;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cin.ignore();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout<<"année invalide"<<endl;
	}

	while(true){
		cout<<"entrez l'identifiant de l'ouvrage"<<endl;
		getline(cin, p_identifiant);
		if(util::ISBN(p_identifiant) == true || util::ISSN(p_identifiant)){
			cout<<"identifiant valide"<<endl;
			break;
		}
		cout<<"identifiant invalide"<<endl;
	}
	Journal journal(p_annee, p_titre, p_auteur, p_identifiant, p_nom, p_volume,
			p_numero, p_page);
	return journal;
}

int main() {
	Bibliographie biblio("Utilisation");
	cout<<"création de la première référence (Ouvrage)"<<endl;
	biblio.ajouterReference(BoucleCreationOuvrage());
	cout<<"création de la deuxième référence (Ouvrage)"<<endl;
	biblio.ajouterReference(BoucleCreationOuvrage());
	cout<<"création de la troisième référence (Journal)"<<endl;
	biblio.ajouterReference(BoucleCreationJournal());
	cout<<"création de la quatrième référence (Journal)"<<endl;
	biblio.ajouterReference(BoucleCreationJournal());
	cout<<biblio.reqBibliographieFormate();
	return 0;
}

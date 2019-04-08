/**
 *
 * \file gestionReferences.cpp
 * \brief programme qui s'occupe de la gestion des références
 * \author rémi lévesque
 * \version 0.1
 * \date 28 février 2019
 *
 * pogramme qui utilise les fonctions du tp1 pour faire la gestion des référencesà
 * de l'utilisateur
 *
 */

#include "classe_reference.h"
#include <math.h>
using namespace std;
using namespace biblio;
using namespace util;


int main(){
    string auteur;
    string titre;
    string issn;
    bool annee_valide = false;
    bool auteur_valide = false;
    bool identifiant_valide = false;
    bool titre_valide = false;
    int annee;
    bool reponse_auteur = false;
    string reponse_a;
    string input_annee;

    /**
     * \fn int main()
     * \brief on fait des boucles sur chacun des critères d'entrés et on boucle
     * en dehors seulement si la condition est respectée.
     */

    while(auteur_valide == false){
        cout<<"Veuillez entrer le nom de l'auteur: "<<endl;
        getline(cin, auteur);

        if(util::NOM(auteur)){
            cout<<"entrée acceptée"<<endl;
            auteur_valide = true;
        }else{
        	cout<<"entrée invalide"<<endl;
        }
    }

    while(titre_valide == false){
        cout<<"Veuillez entrer le titre de l'oeuvre : "<<endl;
        getline(cin, titre);

        if(util::NOM(titre)){
            cout<<"entrée acceptée"<<endl;
            titre_valide = true;
        }else{
        	cout<<"entrée invalide"<<endl;
        }
    }



    while (identifiant_valide == false) {
        cout<<"Veuillez entrer un identifiant valide : "<<endl;
        //cin.ignore();
        getline(cin, issn);

        if(util::ISBN(issn) || util::ISSN(issn)){
            cout<<"entrée acceptée"<<endl;
            identifiant_valide = true;
        }else{
        	cout<<"entrée invalide"<<endl;
        	continue;
        }
    }


    while(annee_valide == false){
    	label:
		annee = 0;
		cout<<"Veuillez entrer l'année de production de l'oeuvre : "<<endl;
		getline(cin, input_annee);
		for(int i=0;i<int(input_annee.length());i++){
			if(int(input_annee[i]) >= 48 and int(input_annee[i])<=57){
				annee += int((input_annee[i])-48)*int(pow(10, int(input_annee.length()-i-1)));
				continue;
			}else{
				cout<<"entrée invalide"<<endl;
				goto label;
			}
		}

		break;
    }

    while(reponse_auteur == false){
    	cout<<"voulez vous changer les noms d'auteurs? 'oui' ou 'non'"<<endl;
    	getline(cin, reponse_a);
    	if(reponse_a == "oui"){
    		auteur_valide = false;
    		while(auteur_valide == false){
    		        cout<<"Veuillez entrer le nom de l'auteur: "<<endl;
    		        getline(cin, auteur);

    		        if(util::NOM(auteur)){
    		            cout<<"entrée acceptée"<<endl;
    		            auteur_valide = true;
    		        }else{
    		        	cout<<"entrée invalide"<<endl;
    		        }
    		    }
    		}
    	else if(reponse_a == "non"){
    		reponse_auteur = true;
    		break;
    	}else{
    		cout<<"entrée invalide"<<endl;
    		continue;
    	}
    	}

    //biblio::reference une_reference(annee, auteur, titre, issn);
    //cout<<une_reference.reqReferenceFormate()<<endl;
}

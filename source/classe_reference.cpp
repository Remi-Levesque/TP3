/**
 *
 * \file classes_references.cpp
 * \brief ajout du constructeur et de getters/setters
 * \author rémi lévesque
 * \version 0.1
 * \date 28 février 2019
 *
 */

#include "classe_reference.h"
#include "ContratException.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace util;
using namespace biblio;



	/**
     * \fn reference::reference(int p_annee, string& p_auteur, string& p_titre, string& p_identifiant)
     * \brief on fait des boucles sur chacun des critères d'entrés et on boucle
     * en dehors seulement si la condition est respectée.
     */

	//biblio::reference* biblio::reference::clone() const{
	//
	//}

	void biblio::reference::verifieInvariant() const{
		INVARIANT(m_annee>0);
	}


	reference::reference(int p_annee,const string& p_auteur,const string& p_titre,const string& p_identifiant):
			m_annee(p_annee), m_auteurs(p_auteur), m_titre(p_titre), m_identifiant(p_identifiant){
		PRECONDITION(m_annee>=0);
		PRECONDITION(m_annee<=2019);
		PRECONDITION(!(m_titre.empty()));
		PRECONDITION(!(m_auteurs.empty()));
		PRECONDITION(!(m_identifiant.empty()));
		PRECONDITION(util::NOM(m_titre)==true);
		PRECONDITION(util::NOM(m_auteurs)==true);
		PRECONDITION(util::ISSN(m_identifiant)==true || util::ISBN(m_identifiant)==true);
		POSTCONDITION(m_annee == p_annee);
		POSTCONDITION(m_auteurs == p_auteur);
		POSTCONDITION(m_identifiant == p_identifiant);
		POSTCONDITION(m_titre == p_titre);
        //}else{cout<<"année négative"<<endl;}



    }
    string biblio::reference::reqReferenceFormate() const{
            ostringstream os;
            os << m_auteurs<<". "<<m_titre<<".";
            return os.str();
        }

    reference::~reference(){}



    //string biblio::reference::reqReferenceFormate(){
    //    ostringstream os;
     //   os << m_auteurs<<", "<<m_titre<<", "<<m_annee<<", "<<m_identifiant;
     //   return os.str();
    //}

    int reference::reqAnnee() const{
    	return m_annee;
    }

    string reference::reqAuteurs() const{
    	return m_auteurs;
    }

    string reference::reqTitre() const{
        	return m_titre;
        }
    string reference::reqIdentifiant() const{
    	return m_identifiant;
    }


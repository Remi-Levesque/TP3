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
 * \fn reference::verifieInvariant()
 * \brief définition de la méthode verifieinvariant qui vérifie l'invariant
 * \pre invariant sur tous les paramètres privés de la classe
 * pour s'assurer du respect des variables avec les fonction du namespace util
 */

	void biblio::reference::verifieInvariant() const{
		INVARIANT(m_annee>0);
		INVARIANT(m_annee<=2019);
		INVARIANT(util::NOM(m_auteurs) == true);
		INVARIANT(util::NOM(m_titre) == true);
		INVARIANT((util::ISBN(m_identifiant) || util::ISSN(m_identifiant))==true);
	}

	/**
	 * \fn reference::reference()
	 * \brief définition du constructeur de base pour la classe reference
	 * \param[in] p_annee année de publication
	 * \param[in] p_titre titre de la publication
	 * \param[in] p_identifiant identifiant de la publication
	 * \param[in] p_auteur auteur de l'oeuvre
	 * \pre p_annee supérieur à 0
	 * \pre p_annee inférieur ou égal à 2019
	 * \pre p_titre n'est pas vide
	 * \pre p_auteur n'est pas vide
	 * \pre p_identifiant n'est pas vide
	 * \pre p_titre respecte les normes selon la fonction verifieNom()
	 * \pre p_auteur respecte les normes selon la fonction verifieNom()
	 * \pre p_indentifiant respecte les normes selon la fonction verifieISBN() ou verifieISSN()
	 *
	 */

	biblio::reference::reference(int p_annee,const string& p_auteur,const string& p_titre,const string& p_identifiant):
			m_annee(p_annee), m_auteurs(p_auteur), m_titre(p_titre), m_identifiant(p_identifiant){
		PRECONDITION(p_annee>=0);
		PRECONDITION(p_annee<=2019);
		PRECONDITION(!(p_titre.empty()));
		PRECONDITION(!(p_auteur.empty()));
		PRECONDITION(!(p_identifiant.empty()));
		PRECONDITION(util::NOM(p_titre)==true);
		PRECONDITION(util::NOM(p_auteur)==true);
		PRECONDITION(util::ISSN(p_identifiant)==true || util::ISBN(p_identifiant)==true);
		POSTCONDITION(m_annee == p_annee);
		POSTCONDITION(m_auteurs == p_auteur);
		POSTCONDITION(m_identifiant == p_identifiant);
		POSTCONDITION(m_titre == p_titre);
		INVARIANTS();
    }


	/**
	 * \fn reference::reqReferenceFormate()
	 * \brief définition de la méthode de la référence formatée qui affiche la référence
	 */

    string biblio::reference::reqReferenceFormate() const{
            ostringstream os;
            os << m_auteurs<<". "<<m_titre<<".";
            return os.str();
        }
    /**
         * \fn reference::~reference()
         * \brief définition du destructeur de la classe purement virtuelle reference
         */

    reference::~reference(){}



    //string biblio::reference::reqReferenceFormate(){
    //    ostringstream os;
     //   os << m_auteurs<<", "<<m_titre<<", "<<m_annee<<", "<<m_identifiant;
     //   return os.str();
    //}

    /**
     * \fn reference::reqAnnee()
     * \brief définition de la méthode d'affichage de l'année
     */
    int reference::reqAnnee() const{
    	return m_annee;
    }
    /**
     * \fn reference::reqAuteurs()
     * \brief définition de la méthode d'affichage de l'auteur
     */
    string reference::reqAuteurs() const{
    	return m_auteurs;
    }
    /**
     * \fn reference::reqTitre()
     * \brief définition de la méthode d'affichage du titre
     */
    string reference::reqTitre() const{
        	return m_titre;
        }
    /**
         * \fn reference::reqIdentifiant()
         * \brief définition de la méthode d'affichage de l'identifiant
         */
    string reference::reqIdentifiant() const{
    	return m_identifiant;
    }
    /**
         * \fn reference::asgAuteurs()
         * \brief définition de la méthode d'assignation de l'auteur
         * \pre p_auteurs respecte les normes de la fonction verifieNom() du namespace util
         * \pre p_auteurs n'est pas vide
         * \pre appel des invariants
         */
    void reference::asgAuteurs(const std::string& p_auteurs){
    	PRECONDITION(util::NOM(p_auteurs)==true);
    	PRECONDITION(!(p_auteurs.empty()));
    	if(util::NOM(p_auteurs)==true){
    		m_auteurs = p_auteurs;
    	}
    	POSTCONDITION(m_auteurs == p_auteurs);
    	INVARIANTS();
    }


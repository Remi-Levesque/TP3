/*
 * Ouvrage.cpp
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */

/**
 * \file Ouvrage.cpp
 * \brief fichier de la classe Ouvrage
 * \date 10 avril mon ami
 */

#include "Ouvrage.h"
#include "classe_reference.h"
#include "ContratException.h"
#include <string>

/**
 * \fn Ouvrage::reqReferenceFormate()
 * \brief définition de la méthode reqreferenceformate qui s'occupe de l'affichage de la bibliographie
 */

std::string biblio::Ouvrage::reqReferenceFormate() const{
	std::ostringstream os;
	os<< biblio::reference::reqReferenceFormate()<<" "<<m_ville<<": "<<m_editeur<<", "<<m_annee<<". "<<m_identifiant<<".";;
	return os.str();
}

/**
 * \fn reference::reference()
 * \brief définition du constructeur de base pour la classe Ouvrage
 * \param[in] p_annee année de publication
 * \param[in] p_titre titre de la publication
 * \param[in] p_identifiant identifiant de la publication
 * \param[in] p_auteurs auteur de l'oeuvre
 * \param[in] p_ville ville de l'oeuvre
 * \param[in] p_editeur editeur de l'oeuvre
 * \pre p_annee supérieur à 0
 * \pre p_annee inférieur ou égal à 2019
 * \pre p_titre n'est pas vide
 * \pre p_auteur n'est pas vide
 * \pre p_identifiant n'est pas vide
 * \pre p_ville n'est pas vide
 * \pre p_editeur n'est pas vide
 * \pre p_titre respecte les normes selon la fonction verifieNom()
 * \pre p_auteur respecte les normes selon la fonction verifieNom()
 * \pre p_ville respecte les normes selon la fonction verifieNom()
 * \pre p_editeur respecte les normes selon la fonction verifieNom()
 * \pre p_indentifiant respecte les normes selon la fonction verifieISBN() ou verifieISSN()
 */

biblio::Ouvrage::Ouvrage(int p_annee,const std::string& p_titre,const std::string& p_auteurs,const std::string& p_identifiant,const std::string& p_ville,const std::string& p_editeur):biblio::reference(p_annee, p_auteurs, p_titre, p_identifiant), m_ville(p_ville), m_editeur(p_editeur)
{
	PRECONDITION(p_annee>0);
	PRECONDITION(p_annee<=2019);
	PRECONDITION(util::NOM(p_titre)==true);
	PRECONDITION(util::NOM(p_auteurs)==true);
	PRECONDITION(util::ISSN(p_identifiant)==true or util::ISBN(p_identifiant)==true);
	PRECONDITION(util::NOM(p_ville)==true);
	PRECONDITION(util::NOM(p_editeur)==true);
	PRECONDITION(!(p_ville.empty()));
	PRECONDITION(!(p_editeur.empty()));
	PRECONDITION(!(p_titre.empty()));
	PRECONDITION(!(p_identifiant.empty()));
	POSTCONDITION(m_annee==p_annee);
	POSTCONDITION(m_titre==p_titre);
	POSTCONDITION(m_auteurs==p_auteurs);
	POSTCONDITION(m_identifiant==p_identifiant);
	POSTCONDITION(m_ville==p_ville);
	POSTCONDITION(m_editeur==p_editeur);
	INVARIANTS();
}

/**
 * \fn Ouvrage::verifieInvariant()
 * \brief définition de la méthode verifieInvariant qui vérifie les invariants mon grand ami
 */

void biblio::Ouvrage::verifieInvariant() const{
	INVARIANT(m_annee>0);
	INVARIANT(m_annee<=2019);
	INVARIANT(!(m_titre.empty()));
	INVARIANT(!(m_identifiant.empty()));
	INVARIANT(!(m_auteurs.empty()));
	INVARIANT(!(m_ville.empty()));
	INVARIANT(!(m_titre.empty()));
	INVARIANT(util::NOM(m_titre)==true);
	INVARIANT(util::NOM(m_auteurs)==true);
	INVARIANT(util::ISSN(m_identifiant)==true || util::ISBN(m_identifiant)==true);
	INVARIANT(util::NOM(m_ville)==true);
	INVARIANT(util::NOM(m_editeur)==true);
}

/**
 * \fn Ouvrage::reqEditeur()
 * \brief définition de la méthode reqEditeur qui retourne la valeur privée de m_editeur
 */

const std::string biblio::Ouvrage::reqEditeur() const{return m_editeur;}

/**
 * \fn Ouvrage::reqVille()
 * \brief définition de la méthode reqVille qui retourne la valeur privée de m_ville
 */

const std::string biblio::Ouvrage::reqVille() const{return m_ville;}

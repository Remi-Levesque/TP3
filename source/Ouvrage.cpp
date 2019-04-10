/*
 * Ouvrage.cpp
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */

#include "Ouvrage.h"
#include "classe_reference.h"
#include "ContratException.h"
#include <string>


std::string biblio::Ouvrage::reqReferenceFormate() const{
	std::ostringstream os;
	os<< biblio::reference::reqReferenceFormate()<<" "<<m_ville<<": "<<m_editeur<<", "<<m_annee<<". "<<m_identifiant<<".";;
	return os.str();
}

// were initialised here... à travailler manque d'excellence
biblio::Ouvrage::Ouvrage(int p_annee,const std::string& p_titre,const std::string& p_auteurs,const std::string& p_identifiant,const std::string& p_ville,const std::string& p_editeur):biblio::reference(p_annee, p_auteurs, p_titre, p_identifiant), m_ville(p_ville), m_editeur(p_editeur)
{
	/// besoin de copier ce qui a déjà été fait dans le reference pour
	/// les conditions ou pas besoin???
	PRECONDITION(m_annee>0);
	PRECONDITION(util::NOM(m_titre)==true);
	PRECONDITION(util::NOM(m_auteurs)==true);
	PRECONDITION(util::ISSN(m_identifiant)==true || util::ISBN(m_identifiant)==true);
	PRECONDITION(util::NOM(m_ville)==true);
	PRECONDITION(util::NOM(m_editeur)==true);
	PRECONDITION(!(m_ville.empty()));
	PRECONDITION(!(m_editeur.empty()));
	PRECONDITION(!(m_titre.empty()));
	PRECONDITION(!(m_identifiant.empty()));
}

void biblio::Ouvrage::verifieInvariant() const{
	INVARIANT(m_annee>0);
}

const std::string biblio::Ouvrage::reqEditeur() const{return m_editeur;}

const std::string biblio::Ouvrage::reqVille() const{return m_ville;}

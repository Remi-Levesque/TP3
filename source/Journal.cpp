/*
 * Journal.cpp
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */

#include "Journal.h"
#include "ContratException.h"
#include <string>

std::string biblio::Journal::reqReferenceFormate() const{
	std::ostringstream os;
	os<<biblio::reference::reqReferenceFormate()<<" "<<m_nom<<", vol. "<<m_volume<<", no. "<<m_numero<<", pp. "<<m_page<<", "<<m_annee<<". "<<m_identifiant<<".";
	return os.str();
}


biblio::Journal::Journal(int p_annee,const std::string& p_titre,const std::string& p_auteurs,const std::string& p_identifiant,const std::string& p_nom, int p_volume, int p_numero, int p_page):biblio::reference(p_annee, p_auteurs, p_titre, p_identifiant), m_nom(p_nom), m_volume(p_volume), m_numero(p_numero), m_page(p_page)
{
	PRECONDITION(m_annee>0);
	PRECONDITION(m_volume>0);
	PRECONDITION(m_numero>0);
	PRECONDITION(m_page>0);
	PRECONDITION(!(m_nom.empty()));
	PRECONDITION(!(m_titre.empty()));
	PRECONDITION(!(m_auteurs.empty()));
	PRECONDITION(!(m_identifiant.empty()));
	PRECONDITION(util::NOM(m_titre)==true);
	PRECONDITION(util::NOM(m_auteurs)==true);
	PRECONDITION(util::ISSN(m_identifiant)==true || util::ISBN(m_identifiant)==true);
	PRECONDITION(util::NOM(m_nom)==true);

}


std::string biblio::Journal::reqNom() const{
	return m_nom;
}

int biblio::Journal::reqPage() const{
	return m_page;
}

int biblio::Journal::reqNumero() const{
	return m_numero;
}

int biblio::Journal::reqVolume() const{
	return m_volume;
}

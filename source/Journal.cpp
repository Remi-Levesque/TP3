/*
 * Journal.cpp
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */

#include "Journal.h"
#include <string>

std::string biblio::Journal::reqReferenceFormate() const{
	std::ostringstream os;
	os<<biblio::reference::reqReferenceFormate()<<" "<<m_nom<<" "<<m_volume<<"no. "<<m_page<<", "<<m_annee<<". "<<m_identifiant;
	return os.str();
}


biblio::Journal::Journal(int p_annee,const std::string& p_titre,const std::string& p_auteurs,const std::string& p_identifiant,const std::string& p_nom, int p_volume, int p_numero, int p_page):biblio::reference(p_annee, p_titre, p_identifiant, p_auteurs), m_nom(p_nom), m_volume(p_volume), m_numero(p_numero), m_page(p_page)
{

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

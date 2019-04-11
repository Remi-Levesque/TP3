/*
 * Journal.h
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */


#ifndef JOURNAL_H_
#define JOURNAL_H_

#include <string>
#include <iostream>
#include <sstream>
#include "classe_reference.h"

namespace biblio{
class Journal: public virtual reference
{
/**
 * \brief définition de la classe Journal qui hérite publiquement de la
 * classe virtuelle pure reference
 */
private:
	std::string m_nom;
	int m_volume;
	int m_numero;
	int m_page;
public:
	void verifieInvariant() const;
	std::string reqNom() const;
	int reqVolume() const;
	int reqPage() const;
	int reqNumero() const;
	Journal(int p_annee,const std::string& p_titre,const std::string& p_auteurs,const std::string& p_identifiant,const std::string& p_nom, int p_volume, int m_numero, int m_page);
	virtual reference* clone() const {return new Journal(*this);};
	std::string reqReferenceFormate() const;
};
}


#endif /* JOURNAL_H_ */

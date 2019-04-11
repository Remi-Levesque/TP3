/*
 * Ouvrage.h
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */
/**
 * \file Ouvrage.h
 * \brief header du fichier de Ouvrage.cpp
 * \date 10 avril mon ami
 */

#ifndef OUVRAGE_H_
#define OUVRAGE_H_

#include <string>
#include <iostream>
#include <sstream>
#include "classe_reference.h"

namespace biblio{
/**
* \brief définition de la classe Ouvrage qui hérite publiquement de la classe reference
*/
class Ouvrage: public virtual reference
{
private:
	std::string m_editeur;
	std::string m_ville;
	void verifieInvariant() const;
public:
	std::string reqReferenceFormate() const;
	const std::string reqVille() const;
	const std::string reqEditeur() const;
	Ouvrage(int p_annee,const std::string& p_titre,const std::string& p_auteurs,const std::string& p_identifiant,const std::string& p_ville,const std::string& p_editeur);
	virtual reference* clone() const {return new biblio::Ouvrage(*this);};
	// j'y vais au son
};

}

#endif /* OUVRAGE_H_ */

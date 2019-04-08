/*
 * Bibliographie.h
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */

#ifndef BIBLIOGRAPHIE_H_
#define BIBLIOGRAPHIE_H_

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "classe_reference.h"

namespace biblio{
class Bibliographie
{
private:
	bool ReferenceEstDejaPresente(const std::string& p_identifiant) const;
	std::vector<reference*> m_vReferences;
	std::string m_nomBiblio;
public:
	Bibliographie(std::string p_nomBibliographie);
	void ajouterReference (const reference& p_nouvelleReference);
	~Bibliographie();
	std::string reqBibliographieFormate() const;
};

}

#endif /* BIBLIOGRAPHIE_H_ */

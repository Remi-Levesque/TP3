/*
 * Bibliographie.cpp
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */
#include "Bibliographie.h"
#include "classe_reference.h"
#include "ContratException.h"
#include <vector>
#include <iostream>
#include <sstream>

/**
 * \brief définition de la fonction ajouterReference
 * \param[in] p_nouvelleReference
 * \pre identifiant est egal à un identifiant déjà présent dans la bibliographie
 * \pre p_nouvelleReference est respecté par la fonction validerNom()
 */

void biblio::Bibliographie::ajouterReference(const reference& p_nouvelleReference){
	for(unsigned int i=0;i<m_vReferences.size();i++){
		PRECONDITION(p_nouvelleReference.reqIdentifiant() != m_vReferences[i]->reqIdentifiant());
		PRECONDITION(util::ISSN(p_nouvelleReference.reqIdentifiant())==true or util::ISBN(p_nouvelleReference.reqIdentifiant())==true);
	}
	m_vReferences.push_back(p_nouvelleReference.clone());
}


/**
 * \brief définition de la fonction referenceEstDejaPresente et regarde si un
 * identifiant est déjà présent dans la bibliographie
 * \param[in] p_identifiant
 * \pre p_identifiant est respecté par la fonction validerNom()
 */

bool biblio::Bibliographie::ReferenceEstDejaPresente(const std::string& p_identifiant) const
{
	PRECONDITION(util::NOM(p_identifiant) == true);
	for(unsigned int i=0;i<m_vReferences.size();i++){
		if(m_vReferences[i]->reqIdentifiant() == p_identifiant){
			return true;
		}
	}
	return false;
}


/**
 * \brief définition du constructeur de base pour la classe Bibliographie
 * \param[in] p_nomBibliographie
 * \pre p_nomBibliographie est respecté par la fonction validerNom()
 * \pre p_nomBibliographie n'est pas vide
 */

biblio::Bibliographie::Bibliographie(std::string p_nomBibliographie):m_nomBiblio(p_nomBibliographie)
{
	PRECONDITION(util::NOM(p_nomBibliographie)==true);
	PRECONDITION(!(p_nomBibliographie.empty()));
}

void biblio::Bibliographie::verifieInvariant() const{
	INVARIANT(util::NOM(m_nomBiblio)==true)
}

/**
 * \brief définition du destructeur de la classe bibliographie
 */

biblio::Bibliographie::~Bibliographie(){
	for(unsigned int i=0;i<m_vReferences.size();i++){
		delete m_vReferences[i];
	}
	//delete(this);

	//for(vector<reference*>::iterator i = m_vReferences.begin(); i != m_vReferences.end(); ++i)
	//	{
	// 		delete *i;
	//	}
}

/**
 * \brief définition du getter  reqNomBiblio() qui retourne le nom de la bibliographie
 */

std::string biblio::Bibliographie::reqNomBiblio() const{
	return m_nomBiblio;
}

/**
 * \brief définition de reqBibliographieFormate qui retourne la bibliographie
 * formatée
 */

std::string biblio::Bibliographie::reqBibliographieFormate() const
{
	using namespace std;
	ostringstream os;
	os.str("");
	os.clear();
	os<<"Bibliographie"<<"\n"<<"==============================="<<"\n";
	for(unsigned int i=0; i<m_vReferences.size();i++){
		os <<"["<<i+1<<"]"<<" "<<m_vReferences[i]->reqReferenceFormate()<<"\n";
	}
	return os.str();
}

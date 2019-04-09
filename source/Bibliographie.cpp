/*
 * Bibliographie.cpp
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */
#include "Bibliographie.h"

void biblio::Bibliographie::ajouterReference(const reference& p_nouvelleReference){
	m_vReferences.push_back(p_nouvelleReference.clone());
}

bool biblio::Bibliographie::ReferenceEstDejaPresente(const std::string& p_identifiant) const
{
	for(unsigned int i=0;i<m_vReferences.size();i++){
		if(m_vReferences[i]->reqIdentifiant() == p_identifiant){
			return true;
		}
	}
	return false;
}

biblio::Bibliographie::Bibliographie(std::string p_nomBibliographie):m_nomBiblio(p_nomBibliographie)
{
}

// à faire
biblio::Bibliographie::~Bibliographie(){
}

std::string biblio::Bibliographie::reqNomBiblio() const{
	return m_nomBiblio;
}

std::string biblio::Bibliographie::reqBibliographieFormate() const
{
	using namespace std;
	ostringstream os;
	os.str("");
	os.clear();
	for(unsigned int i=0; i<m_vReferences.size();i++){
		os<<"Bibliographie"<<"\n"<<"===============================";
		os <<"["<<i+1<<"]"<<m_vReferences[i]->reqReferenceFormate()<<"\n";
	}
	return os.str();
}

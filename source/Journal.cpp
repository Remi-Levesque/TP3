/*
 * Journal.cpp
 *
 *  Created on: 2019-03-30
 *      Author: etudiant
 */

#include "Journal.h"
#include "ContratException.h"
#include <string>

/**
 * \fn Journal::reqReferenceFormate()
 * \brief définition de la méthode reqReferenceFormate qui retourne la référence formatée
 */


std::string biblio::Journal::reqReferenceFormate() const{
	std::ostringstream os;
	os<<biblio::reference::reqReferenceFormate()<<" "<<m_nom<<", vol. "<<m_volume<<", no. "<<m_numero<<", pp. "<<m_page<<", "<<m_annee<<". "<<m_identifiant<<".";
	return os.str();
}

/**
 * \fn Journal::Journal()
 * \brief définition du constructeur de base pour la classe Ouvrage
 * \param[in] p_annee année de publication
 * \param[in] p_titre titre de la publication
 * \param[in] p_identifiant identifiant de la publication
 * \param[in] p_auteurs auteur de l'oeuvre
 * \param[in] p_nom nom de l'oeuvre
 * \param[in] p_volume volume de l'oeuvre
 * \param[in] p_numero numero de l'oeuvre
 * \param[in] p_page page de l'oeuvre
 * \pre p_annee supérieur à 0
 * \pre p_volume supérieur à 0
 * \pre p_numero supérieur à 0
 * \pre p_annee inférieur ou égal à 2019
 * \pre p_titre n'est pas vide
 * \pre p_auteur n'est pas vide
 * \pre p_identifiant n'est pas vide
 * \pre p_nom n'est pas vide
 * \pre p_titre respecte les normes selon la fonction verifieNom()
 * \pre p_auteur respecte les normes selon la fonction verifieNom()
 * \pre p_nom respecte les normes selon la fonction verifieNom()
 * \pre p_identifiant respecte les normes selon la fonction verifieISBN() ou verifieISSN()
 */

biblio::Journal::Journal(int p_annee,const std::string& p_titre,const std::string& p_auteurs,const std::string& p_identifiant,const std::string& p_nom, int p_volume, int p_numero, int p_page):biblio::reference(p_annee, p_auteurs, p_titre, p_identifiant), m_nom(p_nom), m_volume(p_volume), m_numero(p_numero), m_page(p_page)
{
	PRECONDITION(p_annee>0);
	PRECONDITION(p_volume>0);
	PRECONDITION(p_numero>0);
	PRECONDITION(p_page>0);
	PRECONDITION(!(p_nom.empty()));
	PRECONDITION(!(p_titre.empty()));
	PRECONDITION(!(p_auteurs.empty()));
	PRECONDITION(!(p_identifiant.empty()));
	PRECONDITION(util::NOM(p_titre)==true);
	PRECONDITION(util::NOM(p_auteurs)==true);
	PRECONDITION(util::ISSN(p_identifiant)==true || util::ISBN(m_identifiant)==true);
	PRECONDITION(util::NOM(p_nom)==true);
	POSTCONDITION(m_annee==p_annee);
	POSTCONDITION(m_titre==p_titre);
	POSTCONDITION(m_auteurs==p_auteurs);
	POSTCONDITION(m_identifiant==p_identifiant);
	POSTCONDITION(m_nom==p_nom);
	POSTCONDITION(m_volume==p_volume);
	POSTCONDITION(m_numero==p_numero);
	POSTCONDITION(m_page==p_page);
	INVARIANTS();
}

/**
 * \fn Journal::verifieInvariant()
 * \brief définition de la méthode verifieInvariant qui vérifie les invariants mon grand ami
 */

void biblio::Journal::verifieInvariant() const{
	INVARIANT(m_annee>0);
	INVARIANT(m_annee<=2019);
	INVARIANT(m_page>0);
	INVARIANT(m_numero>0);
	INVARIANT(m_volume>0);
	INVARIANT(!(m_titre.empty()));
	INVARIANT(!(m_identifiant.empty()));
	INVARIANT(!(m_auteurs.empty()));
	INVARIANT(!(m_nom.empty()));
	INVARIANT(!(m_titre.empty()));
	INVARIANT(util::NOM(m_titre)==true);
	INVARIANT(util::NOM(m_auteurs)==true);
	INVARIANT(util::ISSN(m_identifiant)==true || util::ISBN(m_identifiant)==true);
	INVARIANT(util::NOM(m_nom)==true);
}

/**
 * \fn Journal::reqNom()
 * \brief définition de la méthode reqNom qui retourne la valeur privée de m_nom
 */

std::string biblio::Journal::reqNom() const{
	return m_nom;
}

/**
 * \fn Journal::reqPage()
 * \brief définition de la méthode reqPage qui retourne la valeur privée de m_page
 */

int biblio::Journal::reqPage() const{
	return m_page;
}

/**
 * \fn Journal::reqNumero()
 * \brief définition de la méthode reqNumero qui retourne la valeur privée de m_numero
 */

int biblio::Journal::reqNumero() const{
	return m_numero;
}

/**
 * \fn Journal::reqVolume()
 * \brief définition de la méthode reqVolume qui retourne la valeur privée de m_volume
 */

int biblio::Journal::reqVolume() const{
	return m_volume;
}

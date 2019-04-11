/*
 * Bibliographie_Testeur.cpp
 *
 *  Created on: 2019-04-08
 *      Author: etudiant
 */

#include "Bibliographie.h"
#include "Ouvrage.h"
#include "Journal.h"
#include "gtest/gtest.h"
#include "ContratException.h"

using namespace biblio;

/**
 * \brief test de la construction d'une instance de la classe Bibliographie
 * Cas valide:
 * construction avec paramètres valides qui respectent les fonctions dans le namespace util
 * Cas invalides:
 * constructeur: nom vide de bibliographie
 */

TEST(Bibliographie, constructeur){
	ASSERT_THROW(Bibliographie biblio_test("");, PreconditionException);
}

/**
 * \class JournalTesteur : public ::testing::Test
 * \brief création d'une bibliographie pour tester l'ensemble des méthodes de la classe
 */

class BibliographieTesteur : public ::testing::Test
{
public:
	BibliographieTesteur():t_biblio("nom de test"){};
	Bibliographie t_biblio;
};

/**
 * \brief test de la méthode reqNomBiblio
 * cas valide: le nom de biblio. utilisé lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: le nom de biblio. utilisé lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(BibliographieTesteur, reqNomBiblio){
	EXPECT_EQ((const std::string)"nom de test", t_biblio.reqNomBiblio());
}

/**
 * \brief test de la méthode reqBibliographieFormate
 * cas valide: la référence utilisée lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: la référence utilisée lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(BibliographieTesteur, reqBibliographieFormate){
	Ouvrage t_ouvrage(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "Springer");
	std::ostringstream os;
	t_biblio.ajouterReference(t_ouvrage);
	os <<"Bibliographie"<<"\n";
	os<<"==============================="<<"\n";
	os<<"["<<1<<"]"<<" "<<t_ouvrage.reqReferenceFormate()<<std::endl;
	EXPECT_EQ(os.str(), t_biblio.reqBibliographieFormate());
}


/**
 * \brief test de la méthode ReferenceEstDejaPresente
 * cas valide: la référence est détectée si on essaie de la dubliquer, sinon tout est beau
 * cas invalide: incapable de faire la distinction entre  deux oeuvres pour savoir si on duplique des oeuvres
 */

TEST_F(BibliographieTesteur, ReferenceEstDejaPresente){
	Ouvrage t_ouvrage(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "Springer");
	//Journal t_ouvrage2(1989, "belle journee ensoleillee", "picasso", "ISBN 978-3-16-148410-0", "direct", 10, 6, 17);
	// a verifier pour la suite
	t_biblio.ajouterReference(t_ouvrage);
	//EXPECT_EQ(t_biblio.ReferenceEstDejaPresente(t_ouvrage2.reqIdentifiant()), true);
}

/**
 * \brief test de la méthode ajouterReference
 * cas valide: la référence est détectée si on essaie de la dubliquer, sinon tout est beau
 * cas invalide: incapable de faire la distinction entre  deux oeuvres pour savoir si on duplique des oeuvres, donc on les ajoute quand même
 */

TEST_F(BibliographieTesteur, ajouterReference){
	Ouvrage t_ouvrage(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "Springer");
	Ouvrage t_ouvrage2(1999, "Benjie", "direct", "ISBN 978-3-16-148410-0", "LA", "Poche");
	// a verifier pour la suite
	t_biblio.ajouterReference(t_ouvrage);
	ASSERT_THROW(t_biblio.ajouterReference(t_ouvrage2), PreconditionException);
}



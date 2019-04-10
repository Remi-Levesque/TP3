/*
 * Bibliographie_Testeur.cpp
 *
 *  Created on: 2019-04-08
 *      Author: etudiant
 */

#include "Bibliographie.h"
#include "Ouvrage.h"
#include "gtest/gtest.h"
#include "ContratException.h"

using namespace biblio;

TEST(Bibliographie, constructeur){
	ASSERT_THROW(Bibliographie biblio_test("");, PreconditionException);
}


class BibliographieTesteur : public ::testing::Test
{
public:
	BibliographieTesteur():t_biblio("nom de test"){};
	Bibliographie t_biblio;
};

TEST_F(BibliographieTesteur, reqNomBiblio){
	EXPECT_EQ((const std::string)"nom de test", t_biblio.reqNomBiblio());
}

/**
 * \brief test de la methode reqBibliographieFormate
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

TEST_F(BibliographieTesteur, ReferenceEstDejaPresente){
	Ouvrage t_ouvrage(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "Springer");
	Ouvrage t_ouvrage2(1999, "Benjie", "direct", "ISBN 978-3-16-148410-0", "LA", "Poche");
	// a verifier pour la suite
	t_biblio.ajouterReference(t_ouvrage);
	EXPECT_EQ(t_biblio.ReferenceEstDejaPresente(t_ouvrage2.reqIdentifiant()), true);
}

TEST_F(BibliographieTesteur, ajouterReference){
	Ouvrage t_ouvrage(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "Springer");
	Ouvrage t_ouvrage2(1999, "Benjie", "direct", "ISBN 978-3-16-148410-0", "LA", "Poche");
	// a verifier pour la suite
	t_biblio.ajouterReference(t_ouvrage);
	ASSERT_THROW(t_biblio.ajouterReference(t_ouvrage2), PreconditionException);
}



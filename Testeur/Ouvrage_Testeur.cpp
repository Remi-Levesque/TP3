/*
 * Ouvrage_Testeur.cpp
 *
 *  Created on: 2019-04-07
 *      Author: etudiant
 */

#include "Ouvrage.h"
#include "classe_reference.h"
#include "gtest/gtest.h"
#include "ContratException.h"

using namespace biblio;

TEST(Ouvrage, ConstructeurParams){
	Ouvrage ouvrage_a_tester(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "Springer");
	EXPECT_EQ(1999, ouvrage_a_tester.reqAnnee());
	EXPECT_EQ("Homayoon Beigi", ouvrage_a_tester.reqAuteurs());
	EXPECT_EQ("Fundamentals of Speaker Recognition", ouvrage_a_tester.reqTitre());
	EXPECT_EQ("ISBN 978-3-16-148410-0", ouvrage_a_tester.reqIdentifiant());
	EXPECT_EQ("New York", ouvrage_a_tester.reqVille());
	EXPECT_EQ("Springer", ouvrage_a_tester.reqEditeur());

}

TEST(Ouvrage, villeValide){
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Benjie", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", " ", "Springer");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Benjie", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "9 New York", "Springer");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Benjie", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York 9", "Springer");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Benjie", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "", "Springer");, PreconditionException);
}

TEST(Ouvrage, editeurValide){
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Benjie", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", " ");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Benjie", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "direct 9");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Benjie", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Benjie", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "9 direct");, PreconditionException);
}

class OuvrageTesteur: public ::testing::Test
{
public:
	OuvrageTesteur():t_ouvrage(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0", "New York", "Springer"){};
	Ouvrage t_ouvrage;

};

TEST_F(OuvrageTesteur, reqVille){
	EXPECT_EQ("New York", t_ouvrage.reqVille());
}

TEST_F(OuvrageTesteur, reqEditeur){
	EXPECT_EQ("Springer", t_ouvrage.reqEditeur());
}

TEST_F(OuvrageTesteur, reqReferenceFormate){
	EXPECT_EQ("Homayoon Beigi. Fundamentals of Speaker Recognition. New York : Springer, 2011. ISBN 978-0-387-77591-3.",
			t_ouvrage.reqReferenceFormate());
}

/**
 * \brief test de la methode clone. On suppose que si la reference est affichee de manière identique,
 * on aura cree une copie avec succes
 */

TEST_F(OuvrageTesteur, clone){
	reference* ouvrage_clone = t_ouvrage.clone();
	EXPECT_EQ(ouvrage_clone->reqReferenceFormate(), t_ouvrage.reqReferenceFormate());
}



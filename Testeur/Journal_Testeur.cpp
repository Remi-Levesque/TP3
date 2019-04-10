/*
 * Journal_Testeur.cpp
 *
 *  Created on: 2019-04-08
 *      Author: etudiant
 */

#include "Journal.h"
#include "gtest/gtest.h"
#include "ContratException.h"

using namespace biblio;

/**
 *
 * \brief test du constructeur avec paramètres avant la création du fixture
 */

TEST(Journal, constructeurAvecParams){
	Journal journal_a_tester(2009, "titre", "auteurs", "ISSN 1937-4771", "nom", 20, 1, 17);
	EXPECT_EQ(2009, journal_a_tester.reqAnnee());
	EXPECT_EQ("auteurs", journal_a_tester.reqAuteurs());
	EXPECT_EQ("titre", journal_a_tester.reqTitre());
	EXPECT_EQ("ISSN 1937-4771", journal_a_tester.reqIdentifiant());
	EXPECT_EQ("nom", journal_a_tester.reqNom());
	EXPECT_EQ(20, journal_a_tester.reqVolume());
	EXPECT_EQ(1, journal_a_tester.reqNumero());
	EXPECT_EQ(17, journal_a_tester.reqPage());
}

TEST(Journal, nomInvalide){

	ASSERT_THROW(Journal journal_a_tester(2009, "titre", "auteurs", "ISSN 1937-4771", "", 20, 1, 17);,
	PreconditionException);
}

TEST(Journal, VolumeInvalide){

	ASSERT_THROW(Journal journal_a_tester(2009, "titre", "auteurs", "ISSN 1937-4771", "nom", -1, 1, 17);,
	PreconditionException);
}

TEST(Journal, NumeroInvalide){

	ASSERT_THROW(Journal journal_a_tester(2009, "titre", "auteurs", "ISSN 1937-4771", "nom", 20, -1, 17);,
	PreconditionException);
}

TEST(Journal, PageInvalide){

	ASSERT_THROW(Journal journal_a_tester(2009, "titre", "auteurs", "ISSN 1937-4771", "nom", 20, 1, -1);,
	PreconditionException);
}

/**
 *\brief fixture pour tester l'ensemble des méthodes
 */

class JournalTesteur: public ::testing::Test
{
public:
	JournalTesteur(): t_journal(1999, "belle journee ensoleillee", "picasso", "ISSN 1937-4771", "direct", 10, 6, 17),
	t_journal2(2009,"A survey of source code management tools for programming courses", "Hart", "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, 113){};
	Journal t_journal;
	Journal t_journal2;
};

TEST_F(JournalTesteur, clone){
	reference* journal_clone = t_journal2.clone();
	EXPECT_EQ(t_journal2.reqReferenceFormate(), journal_clone->reqReferenceFormate());
}

TEST_F(JournalTesteur, reqNom){
	EXPECT_EQ("direct", t_journal.reqNom());
}

TEST_F(JournalTesteur, reqVolume){
	EXPECT_EQ(10, t_journal.reqVolume());
}

TEST_F(JournalTesteur, reqNumero){
	EXPECT_EQ(6, t_journal.reqNumero());
}

TEST_F(JournalTesteur, reqPage){
	EXPECT_EQ(17, t_journal.reqPage());
}

/**
 *\brief on suppose que si la reference formatee est identique, on aura fait une copie avec succès
 */

TEST_F(JournalTesteur, reqReferenceFormate){
	EXPECT_EQ("Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.",
			t_journal2.reqReferenceFormate());
}



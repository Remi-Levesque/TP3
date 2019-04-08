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
	EXPECT_EQ("ISSN 1937-4771", journal_a_tester.reqNom());
	EXPECT_EQ(20, journal_a_tester.reqVolume());
	EXPECT_EQ(1, journal_a_tester.reqNumero());
	EXPECT_EQ(17, journal_a_tester.reqPage());
}

/**
 *\brief fixture pour tester l'ensemble des méthodes
 */

class JournalTesteur: public ::testing::Test
{
public:
	JournalTesteur(): t_journal(1999, "belle journee ensoleillee", "picasso", "ISSN 1937-4771", "direct", 10, 6, 17){};
	Journal t_journal;
};
/**
 * \brief test de la méthode reqAnnee
 */

TEST_F(JournalTesteur, reqNom){
	EXPECT_EQ("direct", t_journal.reqNom());
}

TEST_F(JournalTesteur, reqVolume){
	EXPECT_EQ(20, t_journal.reqVolume());
}

TEST_F(JournalTesteur, reqNumero){
	EXPECT_EQ(6, t_journal.reqNumero());
}

TEST_F(JournalTesteur, reqPage){
	EXPECT_EQ(17, t_journal.reqPage());
}



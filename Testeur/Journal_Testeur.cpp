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
 * \brief test de la construction d'une instance de la classe Journal
 * Cas valide:
 * ConstructeurAvecParams: construction avec paramètres valides qui respectent les fonctions dans le namespace util
 * Cas invalides:
 * NomInvalide: nom vide, utilisation de caractères autres que l'ascii, utilisation de chiffres
 * VolumeInvalide: volume négatif
 * NumeroInvalide: numero négatif
 * PageInvalide: page négative
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
	ASSERT_THROW(Journal journal_a_tester(2009, "titre", "auteurs", "ISSN 1937-4771", "boi &&123", 20, 1, 17);,
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
 * \class JournalTesteur : public ::testing::Test
 * \brief création de 2 journaux pour tester l'ensemble des méthodes de la classe
 */

class JournalTesteur: public ::testing::Test
{
public:
	JournalTesteur(): t_journal(1999, "belle journee ensoleillee", "picasso", "ISSN 1937-4771", "direct", 10, 6, 17),
	t_journal2(2009,"A survey of source code management tools for programming courses", "Hart", "ISSN 1937-4771", "Journal of Computing Sciences in Colleges", 24, 6, 113){};
	Journal t_journal;
	Journal t_journal2;
};

/**
 * \brief test de la methode clone. On suppose que si la reference est affichee de manière identique,
 * on aura cree une copie avec succès
 */

TEST_F(JournalTesteur, clone){
	reference* journal_clone = t_journal2.clone();
	EXPECT_EQ(t_journal2.reqReferenceFormate(), journal_clone->reqReferenceFormate());
}

/**
 * \brief test de la méthode reqNom
 * cas valide: le nom utilisé lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: le nom utilisé lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(JournalTesteur, reqNom){
	EXPECT_EQ("direct", t_journal.reqNom());
}

/**
 * \brief test de la méthode reqVolume
 * cas valide: le volume utilisé lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: le volume utilisé lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(JournalTesteur, reqVolume){
	EXPECT_EQ(10, t_journal.reqVolume());
}

/**
 * \brief test de la méthode reqNumero
 * cas valide: le numero utilisé lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: le numero utilisé lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(JournalTesteur, reqNumero){
	EXPECT_EQ(6, t_journal.reqNumero());
}

/**
 * \brief test de la méthode reqPage
 * cas valide: la page utilisée lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: la page utilisée lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(JournalTesteur, reqPage){
	EXPECT_EQ(17, t_journal.reqPage());
}

/**
 *\brief test de reqReferenceFormate, on suppose que si la reference formatee est identique, on aura fait une copie avec succès
 */

TEST_F(JournalTesteur, reqReferenceFormate){
	EXPECT_EQ("Hart. A survey of source code management tools for programming courses. Journal of Computing Sciences in Colleges, vol. 24, no. 6, pp. 113, 2009. ISSN 1937-4771.",
			t_journal2.reqReferenceFormate());
}



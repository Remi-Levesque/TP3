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

/**
 * \brief test de la construction d'une instance de la classe Ouvrage
 * Cas valide:
 * ConstructeurParams: construction avec paramètres valides qui respectent les fonctions dans le namespace util
 * Cas invalides:
 * villeInvalide: ville vide, utilisation de caractères autres que l'ascii, utilisation de chiffres
 * editeurInvalide: éditeur vide, utilisation de caractères autres que l'ascii, utilisation de chiffres
 */

TEST(Ouvrage, ConstructeurParams){
	Ouvrage ouvrage_a_tester(1999,"Fundamentals of Speaker Recognition", "Homayoon Beigi", "ISBN 978-3-16-148410-0", "New York", "Springer");
	EXPECT_EQ(1999, ouvrage_a_tester.reqAnnee());
	EXPECT_EQ("Homayoon Beigi", ouvrage_a_tester.reqAuteurs());
	EXPECT_EQ("Fundamentals of Speaker Recognition", ouvrage_a_tester.reqTitre());
	EXPECT_EQ("ISBN 978-3-16-148410-0", ouvrage_a_tester.reqIdentifiant());
	EXPECT_EQ("New York", ouvrage_a_tester.reqVille());
	EXPECT_EQ("Springer", ouvrage_a_tester.reqEditeur());

}

TEST(Ouvrage, villeValide){
	ASSERT_THROW(Ouvrage ouvrage_test(1999,"Fundamentals of Speaker Recognition", "Benjie",  "ISBN 978-3-16-148410-0", "", "Springer");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Fundamentals of Speaker Recognition", "Benjie",  "ISBN 978-3-16-148410-0", "9 New York", "Springer");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Fundamentals of Speaker Recognition", "Benjie",  "ISBN 978-3-16-148410-0", "New York 9", "Springer");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Fundamentals of Speaker Recognition", "Benjie",  "ISBN 978-3-16-148410-0", "", "Springer");, PreconditionException);
}

TEST(Ouvrage, editeurValide){
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Fundamentals of Speaker Recognition", "Benjie", "ISBN 978-3-16-148410-0", "New York", "");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Fundamentals of Speaker Recognition", "Benjie", "ISBN 978-3-16-148410-0", "New York", "direct 9");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Fundamentals of Speaker Recognition", "Benjie", "ISBN 978-3-16-148410-0", "New York", "");, PreconditionException);
	ASSERT_THROW(Ouvrage ouvrage_test(1999, "Fundamentals of Speaker Recognition", "Benjie", "ISBN 978-3-16-148410-0", "New York", "9 direct");, PreconditionException);
}

/**
 * \class OuvrageTesteur : public ::testing::Test
 * \brief création d'un ouvrage pour tester l'ensemble des méthodes de la classe
 */

class OuvrageTesteur: public ::testing::Test
{
public:
	OuvrageTesteur():t_ouvrage(1999, "Fundamentals of Speaker Recognition", "Homayoon Beigi", "ISBN 978-3-16-148410-0", "New York", "Springer"){};
	Ouvrage t_ouvrage;

};

/**
 * \brief test de la méthode reqVille
 * cas valide: la ville utilisée lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: la ville utilisée lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(OuvrageTesteur, reqVille){
	EXPECT_EQ("New York", t_ouvrage.reqVille());
}

/**
 * \brief test de la méthode reqEditeur
 * cas valide: l'éditeur utilisé lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: l'éditeur utilisé lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(OuvrageTesteur, reqEditeur){
	EXPECT_EQ("Springer", t_ouvrage.reqEditeur());
}

/**
 * \brief test de la méthode reqVille
 * cas valide: la référence utilisée lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: la référence utilisée lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(OuvrageTesteur, reqReferenceFormate){
	EXPECT_EQ("Homayoon Beigi. Fundamentals of Speaker Recognition. New York: Springer, 1999. ISBN 978-3-16-148410-0.",
			t_ouvrage.reqReferenceFormate());
}

/**
 * \brief test de la methode clone. On suppose que si la reference est affichee de manière identique,
 * on aura cree une copie avec succès
 */

TEST_F(OuvrageTesteur, clone){
	reference* ouvrage_clone = t_ouvrage.clone();
	EXPECT_EQ(ouvrage_clone->reqReferenceFormate(), t_ouvrage.reqReferenceFormate());
}



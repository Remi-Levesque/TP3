/*
 * Reference_Testeur.cpp
 *
 *  Created on: 2019-04-07
 *      Author: etudiant
 */

#include "classe_reference.h"
#include "gtest/gtest.h"
#include "ContratException.h"


using namespace biblio;

/**
 * \class Reference_t : public reference
 * \brief construction d'une classe non virtuelle pure
 * pour tester les méthodes de la classe reference
 */

class Reference_t : public reference
{
public:
	Reference_t(int p_annee,const std::string& p_auteurs,const std::string& p_titre,const std::string& p_identifiant):
		reference(p_annee, p_auteurs, p_titre, p_identifiant)
			{};
	virtual std::string reqReferenceFormate() const
		{
			return reference::reqReferenceFormate();
		};
	virtual reference* clone() const
	{
		return new Reference_t(*this);
	};

};

/**
 * \class UneReference : public ::testing::Test
 * \brief fixture pour faire les tests de la classe Reference_t (donc reference aussi)
 */

class UneReference : public ::testing::Test
{
public:
	UneReference():
		reference_1(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0"),
		reference_2(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0"),
		reference_3(1999, "fabio", "direct", "ISBN 978-3-16-148410-0")

	{};
	Reference_t reference_1;
	Reference_t reference_2;
	Reference_t reference_3;
};

/**
 * \brief test de la construction d'une instance de la classe Reference_t
 * Cas valide: construction avec 4 paramètres valides qui respectent les fonctions dans le namespace util
 * Cas invalides:
 * NomInvalide: nom vide, utilisation de caractères autres que l'ascii, utilisation de chiffres
 * anneeInvalide: année négative, année future
 * titreInvalide: utilisation de texte non ascii, titre vide
 * codeIdentifiantInvalide: code ISBN traité comme un ISSN, et vice-versa, sans tirets, sans l'identifiant de début
 */

TEST(reference, ConstructeurParams){
	Reference_t reference_a_tester(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");
	EXPECT_EQ(1999, reference_a_tester.reqAnnee());
	EXPECT_EQ("Homayoon Beigi", reference_a_tester.reqAuteurs());
	EXPECT_EQ("Fundamentals of Speaker Recognition", reference_a_tester.reqTitre());
	EXPECT_EQ("ISBN 978-3-16-148410-0", reference_a_tester.reqIdentifiant());
}

TEST(reference, NomInvalide){
	ASSERT_THROW(Reference_t reference_test(1999, "", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "benjie-xd", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "oofers 987", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");, PreconditionException);
}

TEST(reference, anneeInvalide){
	ASSERT_THROW(Reference_t reference_test(-69, "sup", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(2020, "tyrone", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");, PreconditionException);

}

TEST(reference, titreInvalide){
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "Fundamentals_of & Speaker Recognition", "ISBN 978-3-16-148410-0");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "", "ISBN 978-3-16-148410-0");, PreconditionException);
}

TEST(reference, codeIdentifiantInvalide){
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "Fundamentals_of & Speaker Recognition", "ISSN 978-3-16-148410-0");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "Fundamentals_of & Speaker Recognition", "ISBN 2049-3630");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "Fundamentals_of & Speaker Recognition", "ISBN 9783161484100");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "Fundamentals_of & Speaker Recognition", "ISSN 20493630");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "Fundamentals_of & Speaker Recognition", "2049-3630");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "Fundamentals_of & Speaker Recognition", "978-3-16-148410-0");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "Fundamentals_of & Speaker Recognition", "20493630");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "sup", "Fundamentals_of & Speaker Recognition", "9783161484100");, PreconditionException);
}


/**
 * \brief test de la méthode reqAnnee
 * cas valide: l'année utilisée lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: l'année utilisée lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(UneReference, reqAnnee){
	EXPECT_EQ(1999, reference_1.reqAnnee());
}

/**
 * \brief test de la méthode asgAuteurs
 * cas valide: on retourne la même valeur pour l'assignation d'un auteur et lors de l'utilisation de la méthode reqAuteurs()
 * cas invalide: on ne reçoit pas la même valeur
 */

TEST_F(UneReference, asgAuteurs){
	reference_1.asgAuteurs("fabio");
	EXPECT_EQ("fabio", reference_1.reqAuteurs());
	reference_1.asgAuteurs("Homayoon Beigi");
	EXPECT_EQ("Homayoon Beigi", reference_1.reqAuteurs());
}

/**
 * \brief test de la méthode reqReferenceFormate
 * cas valide: la référence utilisée lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: la référence utilisée lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(UneReference, referenceFormatee){
	EXPECT_EQ("Homayoon Beigi. Fundamentals of Speaker Recognition.", reference_1.reqReferenceFormate());
}

/**
 * \brief test de la méthode "=="
 * cas valide: on a une égalité entre deux références identiques et une différence lors de la comparaison de deux référence différentes
 * cas invalide: incapable de faire la distinction entre deux oeuvres identiques/différentes
 */

TEST_F(UneReference, operateurEgal){
	ASSERT_TRUE(reference_1 == reference_2);
	ASSERT_FALSE(reference_2 == reference_3);
	ASSERT_FALSE(reference_1 == reference_3);
}

/**
 * \brief test de la méthode clone()
 * cas valide: on a une égalité entre deux références lors de la comparaison de leur affichage de référence
 * cas invalide: incapable de reproduire une copie et d'afficher la référence correctement
 */

TEST_F(UneReference, fonctionCopie){
	reference *direct = reference_2.clone();
	EXPECT_EQ(reference_2.reqReferenceFormate(), direct->reqReferenceFormate());
}

/**
 * \brief test de la méthode reqIdentifiant
 * cas valide: l'identifiant utilisé lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: l'identifiant utilisé lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(UneReference, reqIdentifiant){
	EXPECT_EQ(reference_1.reqIdentifiant(), "ISBN 978-3-16-148410-0");
}

/**
 * \brief test de la méthode reqTitre
 * cas valide: le titre utilisé lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: le titre utilisé lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(UneReference, reqTitre){
	EXPECT_EQ(reference_1.reqTitre(), "Fundamentals of Speaker Recognition");
}

/**
 * \brief test de la méthode reqAuteurs
 * cas valide: l'auteur utilisé lors de la construction de l'objet correspond à la valeur retournée par le getter
 * cas invalide: l'auteur utilisé lors de la construction de l'objet ne correspond pas à la valeur retournée par le getter
 */

TEST_F(UneReference, reqAuteurs){
	EXPECT_EQ(reference_3.reqAuteurs(), "fabio");
}

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
 * \brief test du constructeur sans paramètres
 * cas valide: configuration par défaut
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

class UneReference : public ::testing::Test
{
	UneReference():
		reference_1(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0")
	{};
	Reference_t reference_1;
};

/**
 * on teste le constructeur, ensuite on pourra tester les fonctions avec le fixture
 */

TEST(reference, ConstructeurParams){
	Reference_t reference_a_tester(1999, "Homayoon Beigi", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");
	EXPECT_EQ(1999, reference_a_tester.reqAnnee());
	EXPECT_EQ("Homayoon Beigi", reference_a_tester.reqAuteurs());
	EXPECT_EQ("Fundamentals of Speaker Recognition", reference_a_tester.reqTitre());
	EXPECT_EQ("ISBN 978-3-16-148410-0", reference_a_tester.reqIdentifiant());
}

TEST(reference, NomInvalide){
	ASSERT_THROW(Reference_t reference_test(1999, " ", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, "benjie-xd", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");, PreconditionException);
	ASSERT_THROW(Reference_t reference_test(1999, " adslkj", "Fundamentals of Speaker Recognition", "ISBN 978-3-16-148410-0");, PreconditionException);
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

// fixture à faire mon énorme ami

//TEST_F(Reference_t, reqAnnee){
//	EXPECT_EQ(1999, reference_1.reqAnnee);
//}


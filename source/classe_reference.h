/**
 *
 * \file classes_references.h
 * \brief header file pour l'ensemble du programme
 * \author rémi lévesque
 * \version 0.1
 * \date 28 février 2019
 *
 */


#ifndef classe_reference_h
#define classe_reference_h

#include <string>
#include <iostream>


namespace util
{
    bool NOM(std::string&);
    bool ISSN(std::string&);
    bool ISBN(std::string&);
}

namespace biblio {


class reference
{
public:
    bool operator==(const reference& p_reference){
        return (p_reference.m_annee == m_annee && p_reference.m_titre == m_titre && p_reference.m_auteurs == m_auteurs && p_reference.m_identifiant == m_identifiant);
    }
    reference(int,const std::string&,const std::string&,const std::string&);
    //std::string reqReferenceFormate();
    virtual std::string reqReferenceFormate() const=0;
    int reqAnnee() const;
    std::string reqTitre() const;
    std::string reqAuteurs() const;
    std::string reqIdentifiant() const;
    virtual ~reference();
    virtual reference* clone() const=0;
protected:
   int m_annee;
   const std::string m_titre;
   const std::string m_identifiant;
   const std::string m_auteurs;
   void verifieInvariant() const;
};
}



#endif /* classe_reference_h */

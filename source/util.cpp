/**
 *
 * \file util.cpp
 * \brief intégration namespace util
 * \author rémi lévesque
 * \version 0.1
 * \date 28 février 2019
 *
 */


#include "classe_reference.h"
using namespace std;


/**
 * namespace util
 */

namespace util
{
	/**
	 *
	 */
    bool NOM(const std::string& p_nom){
        int length = int(p_nom.length());
        int check = 0;
        for(int i=0;i<length;i++){
            if((int(p_nom[i])>=65 && int(p_nom[i])<=90) || (int(p_nom[i])>=97 && int(p_nom[i])<=122) || int(p_nom[i]) == 32){
                continue;
            }else{
                check = 1;
                break;
            }
        }
        if(check == 0){
            return true;
        }
        return false;
    }

    bool ISSN(const std::string& p_issn){
        int check = 0;
        int somme = 0;
        int facteur = 8;
        int reponse;
        int length = int(p_issn.length());
        std::string valeur;
        std::string issn = "ISSN ";

        if(length != 14){
            return false;
        }
        //check si les 4 premiers caractères == ISSN
        for(int i=0;i<=4;i++){
            if(int(p_issn[i]) == int(issn[i])){
                continue;
            }else{
                return false;
            }
        }

        for(int i=5; i<length-1;i++){
            if(i == 9 and int(p_issn[i]) == 45){
                continue;
            }
            else if(int(p_issn[i])-48 >= 0 and int(p_issn[i])-48 <= 9){
                somme += int(((p_issn[i])-48)*facteur);
                check = 0;
                facteur--;

            }else if(int (int(p_issn[i]) == 88)){
                somme += 10*facteur;
            }else{
                return false;
            }

        }
        int remainder = somme%11;
        if(remainder == 0){
            reponse = 0;
        }else{
            reponse = 11-remainder;
        }
        if(int(p_issn[13])-48 == reponse){
            return true;
        }else if(check == 0 and int(p_issn[13]) == 88){
            return true;
        }
        return false;
    }

    bool ISBN(const std::string& p_isbn){
        // ISBN-10;
        int somme = 0;
        int length = int(p_isbn.length());
        std::string valeur;
        std::string isbn = "ISBN ";

        if(length == 18){
            int tiret = 3;
            int multiple = 10;
            //check si les 4 premiers caractères == ISSN
            for(int i=0;i<=4;i++){
                if(int(p_isbn[i]) == int(isbn[i])){
                    continue;
                }else{
                    return false;
                }
            }
            for(int i=5;i<length;i++){
                if(int(p_isbn[i]) == 45){
                    tiret--;
                    if(tiret<0){
                        return false;
                    }
                    continue;
                }else if(int(p_isbn[i]-48) >= 0 and int(p_isbn[i]-48) <= 9){
                    somme += (int(p_isbn[i])-48)*multiple;
                    multiple--;
                }else if(int (int(p_isbn[i]) == 88)){
                    somme += 10*multiple;
                }else{
                    return false;
                }
            }
            cout << somme << endl;
            if(somme%11 == 0){
                return true;
            }else{
                return false;
            }


        }

        else if(length == 22){
            int tiret = 4;
            int compteur = 13;

            // check si les premiers caractères sont bien "ISBN"
            for(int i=0;i<=4;i++){
                if(int(p_isbn[i]) == int(isbn[i])){
                    continue;
                }else{
                    return false;
                }
            }
            for(int i=5;i<length;i++){
                if(compteur%2 == 0){
                    if(int(p_isbn[i]) == 45){
                        tiret--;
                        continue;
                    }else if(int(p_isbn[i]-48) >= 0 and int(p_isbn[i]-48) <= 9){
                        somme += int(p_isbn[i]-48)*3;
                        compteur--;
                    }else{
                        return false;
                    }

                }
                else{
                    if(int(p_isbn[i]) == 45){
                        continue;
                    }else if(int(p_isbn[i])-48 >= 0 and int(p_isbn[i])-48 <= 9){
                        somme += int(p_isbn[i])-48;
                        compteur--;
                    }else{
                        return false;
                    }
                }

            }
        }
        else{
            return false;
        }
        if(somme%10 == 0){
            return true;
        }else{
            return false;
        }
    }
}




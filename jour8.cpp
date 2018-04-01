#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

struct registre{
	string nom;
	double val;
};

vector<registre> regi;

void nouvregistre (string nom){
	registre nouv;
	nouv.nom = nom;
	nouv.val = 0;
	regi.push_back(nouv);
}

int verifregistre (string nom){
	bool verif = false;
    int i = 0;
    while(!verif && i < regi.size()){
        if(regi[i].nom == nom) verif= true;
        else i++;
    }
    if (!verif) nouvregistre(nom);
    return i;
}

int main(){
	string stringvalues ;
	double maxi = 0;
	ifstream fichier("input_jour8.txt", ios::in);
	if (fichier){
		string ligne;
		int azert = 0;
        while(getline(fichier, ligne)){
        	int pos = 0;
        	string registre1 = "";
        	int registre11;
        	string action = "";
        	double taille = 0;
            while(ligne[pos] != ' '){
                registre1 += ligne[pos];
                pos++;
            }
            registre11 = verifregistre(registre1);
            pos++;

            while(ligne[pos] != ' '){
                action += ligne[pos];
                pos++;
            }
            pos++;

            int debnb = pos;
            while(ligne[pos] != ' '){
                pos++;
            }
            if(ligne[debnb]=='-'){
            	
        		for (int i = 1; i < pos-debnb; ++i){
        			taille += (ligne[i+debnb] - '0') * pow(10,(pos-debnb-i-1));
        		}
        		taille = -taille;
        	}else{
        		for (int i = 0; i < pos - debnb; ++i){
        			taille += (ligne[i+debnb] - '0') * pow(10,pos-debnb-i-1);
        		}
        	}
        	pos+=4;

        	string registre2 = "";
        	int registre21;
        	while(ligne[pos] != ' '){
                registre2 += ligne[pos];
                pos++;
            }
            registre21 = verifregistre(registre2);
            pos++;

            string comparator = "";
            while(ligne[pos] != ' '){
                comparator += ligne[pos];
                pos++;
            }
            pos++;

            double val = 0;
            if(ligne[pos]=='-'){
        		for (int i = 1; i < ligne.length()-pos; ++i){
        			val += (ligne[i+pos] - '0') * pow(10,(ligne.length()-pos-i-1));
        		}
        		val = -val;
        	}else{
        		for (int i = 0; i < ligne.length()-pos; ++i){
        			val += (ligne[i+pos] - '0') * pow(10,(ligne.length()-pos-i-1));
        		}
        	}

        	if(comparator == "=="){
	        	if((regi[registre21].val) == (val)){
	        		if(action == "dec"){
	        			regi[registre11].val -= taille;
	        		}else{
	        			regi[registre11].val += taille;
	        		}
	        	}
	        }

        	if(comparator == "!="){
	        	if((regi[registre21].val) != (val)){
	        		if(action == "dec"){
	        			regi[registre11].val -= taille;
	        		}else{
	        			regi[registre11].val += taille;
	        		}
	        	}
	        }

        	if(comparator == "<="){
	        	if((regi[registre21].val) <= (val)){
	        		if(action == "dec"){
	        			regi[registre11].val -= taille;
	        		}else{
	        			regi[registre11].val += taille;
	        		}
	        	}
	        }

        	if(comparator == ">="){
	        	if((regi[registre21].val) >= (val)){
	        		if(action == "dec"){
	        			regi[registre11].val -= taille;
	        		}else{
	        			regi[registre11].val += taille;
	        		}
	        	}
	        }

        	if(comparator == "<"){
	        	if((regi[registre21].val) < (val)){
	        		if(action == "dec"){
	        			regi[registre11].val -= taille;
	        		}else{
	        			regi[registre11].val += taille;
	        		}
	        	}
	        }

        	if(comparator == ">"){
	        	if((regi[registre21].val) > (val)){
	        		if(action == "dec"){
	        			regi[registre11].val -= taille;
	        		}else{
	        			regi[registre11].val += taille;
	        		}
	        	}
	        }

			if(regi[registre11].val > maxi) maxi = regi[registre11].val;	        
	        /*if(azert < 50){
	        	cout << regi[registre11].nom << ' ' << action << ' ' << taille << ' ' << regi[registre21].nom << ' ' << comparator << ' ' << val<< endl;
	        	cout << "------------------------------------" << endl;
	        	azert++;
	        }*/
    	}
       	fichier.close();

       	double max = 0;


       	for(int i = 0; i < regi.size(); i++){
       		if(regi[i].val > max) max = regi[i].val;
       	}
       	cout << max << endl;
       	cout << maxi << endl;
	}else cout << "Impossible d'ouvrir le fichier !" << endl;
    return 0;
}

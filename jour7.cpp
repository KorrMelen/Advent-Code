#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;


//vector<string> pile;
//vector<string> fils;

struct disque{
    string element;
    int taille;
    vector<string> fils;
};
vector <disque> pile;

int poids (disque element){
    if(element.fils.size() == 0){
        return element.taille;
    }else{
        vector<int> poids;
        for(int i = 1; i < element.fils.size(); i++){
            for(int j = 0; j < pile.size(); j++){
                if(element.fils[i] == pile[j].element){
                    poids.push_back(poids(pile[j]));
                    break;
                }
            }
        }
        int p = 0;
        for(int i = 0; i < poids.size(); i++){
            p+=poids[i];
        }
        return (p + element.taille);
    }
}

int main(){
	string stringvalues ;
	ifstream fichier("input_jour7.txt", ios::in);
	if (fichier){
		string ligne;
        while(getline(fichier, ligne)){
            disque nouv;
            string element = "";
            int taille = 0;
            int pos = 0;
            while(ligne[pos] != ' '){
                element += ligne[pos];
                pos++;
            }
            nouv.element = element;
            pos+= 2;
            int debnb = pos;
            while(ligne[pos] != ')'){
                pos++;
            }
            for (int i = 0; i < pos-debnb; ++i){
                taille += (ligne[i+debnb] - '0') * pow(10,(pos-debnb-i-1));
            }
            nouv.taille = taille;
            if(pos + 1 != ligne.length()){
                pos += 5;
                string fille = "";
                for(int i = pos; i < ligne.length(); i++){
                    if(ligne[i] != ','){
                        fille += ligne[i];
                    }else{
                        nouv.fils.push_back(fille);
                        fille = "";
                        i++;
                    }
                }
                nouv.fils.push_back(fille);
            }
            pile.push_back(nouv);
        }
       	fichier.close();
 
        /*for(int i = 0; i < fils.size(); i++){
            for (int j = 0; j < pile.size(); j++){
                    if (fils[i] == pile[j]){
                        pile.erase(pile.cbegin() + j);
                        break;
                    }
            }
        }*/
        int i = 0;
        while(pile[i].element != "dtacyn") i++;
        cout << poids(pile[i]) << endl;


        //cout << pile[0].element << endl;


	}else cout << "Impossible d'ouvrir le fichier !" << endl;
    return 0;
}
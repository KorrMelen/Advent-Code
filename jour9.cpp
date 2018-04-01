#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	string stringvalues;
	int score = 0;
	int profondeur = 0;
	int poubelle = 0;
	string etat = "flux";
	ifstream fichier("input_jour9.txt", ios::in);
	if (fichier){
		char caractere;
		while(fichier.get(caractere)){
			if(etat == "flux"){
				if(caractere == '<') etat = "dechet";
				else {
					if (caractere == '{'){
						profondeur++;
						score += profondeur;
					}
					if (caractere == '}'){
						profondeur--;
					}
				}
			}else{
				if (caractere == '!'){
					fichier.get(caractere);
				}else{
					if(caractere == '>') etat = "flux";
					else poubelle++;
				}
			}
		}
		cout << score << endl;
		cout << poubelle << endl;
	}else cout << "Impossible d'ouvrir le fichier !" << endl;

	return 0;
}
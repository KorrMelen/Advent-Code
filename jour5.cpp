#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	string stringvalues ;
	//istringstream iss (stringvalues);
	vector<int> instruction;
	int etape = 0;
	int curseur = 0;
	ifstream fichier("input_jour5.txt", ios::in);
	if (fichier){
		string ligne;
        while(getline(fichier, ligne)){
        	int val = 0;
        	if(ligne[0]=='-'){
        		for (int i = 1; i < ligne.length(); ++i){
        			val += (ligne[i] - '0') * pow(10,(ligne.length()-i-1));
        		}
        		if(ligne.length() == 4) val += 1;
        		val = -val;
        	}else{
        		for (int i = 0; i < ligne.length(); ++i){
        			val += (ligne[i] - '0') * pow(10,(ligne.length()-i-1));
        		}
        	}
        	instruction.push_back(val);
        }
       	fichier.close();
	}else cout << "Impossible d'ouvrir le fichier !" << endl;
	for(int i = 0; i < 115; i++){
		cout << instruction[i] << endl;
	}
	while (curseur < instruction.size()){
		if(instruction[curseur] > 2){
			instruction[curseur]--;
			curseur += instruction[curseur] +1;
			etape++;
		}else{
			instruction[curseur]++;
			curseur += instruction[curseur]-1;
			etape++;
		}
	}
	cout << etape << endl;
	return 0;
}
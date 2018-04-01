#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int tab [256];

int modifindice (int i){
	return i % 256;
}

void inverse (int deb, int fin){
	int temp;
	while (deb < fin){
		temp = tab[modifindice(deb)];
		tab[modifindice(deb)] = tab[modifindice(fin)];
		tab[modifindice(fin)] = temp;
		deb++;
		fin--;
	}
}

string ten_to_sixteen (int val){
	if(val == 0) return "0";
	else if(val == 1) return "1";
	else if(val == 2) return "2";
	else if(val == 3) return "3";
	else if(val == 4) return "4";
	else if(val == 5) return "5";
	else if(val == 6) return "6";
	else if(val == 7) return "7";
	else if(val == 8) return "8";
	else if(val == 9) return "9";
	else if(val == 10) return "a";
	else if(val == 11) return "b";
	else if(val == 12) return "c";
	else if(val == 13) return "d";
	else if(val == 14) return "e";
	else return "f";
}

string conversion (int valeur){
	int diviseur = valeur / 16;
	int reste = valeur % 16;
	return(ten_to_sixteen(diviseur) + ten_to_sixteen(reste));
}

int main() {
	vector<int> instruction;
	string stringvalues;
	ifstream fichier("input_test.txt", ios::in);
	if (fichier){
		char caractere;
		while(fichier.get(caractere)){
			instruction.push_back(caractere);
		}
		instruction.push_back(17);
		instruction.push_back(31);
		instruction.push_back(73);
		instruction.push_back(47);
		instruction.push_back(23);

		for(int i = 0; i < 256; i++){
			tab[i] = i;
		}
		int indice = 0;
		int etape = 0;
		for(int j = 0; j < 64; j++){
			for(int i = 0; i < instruction.size(); i++){
				inverse(indice, indice + instruction[i]);
				indice += instruction[i] + etape;
				etape++;
			}
		}
		int nouvtab [16];
		for(int i = 0; i < 16; i++){
			int temp = 0;
			for(int j = 0; j < 16; j++){
				temp ^=tab[16*i + j];
			}
			nouvtab[i] = temp;
		}
		string output = "";
		for(int i = 0; i < 16; i++){
			output += conversion(nouvtab[i]);
		}
		cout << output << endl;
	}else cout << "Impossible d'ouvrir le fichier !" << endl;

	return 0;
}
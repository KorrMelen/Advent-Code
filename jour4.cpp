#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	vector<string> phrases;
	int res = 0;
	ifstream fichier("input_jour4.txt", ios::in);
	if (fichier){
		string ligne;
        while(getline(fichier, ligne)){
                phrases.push_back(ligne);
        }
		fichier.close();
	}else cout << "Impossible d'ouvrir le fichier !" << endl;
	for(int i=0; i<phrases.size(); i++){
		vector<string> mots;
		string mot = "";
		for (int j=0;j<phrases[i].size();j++){
			if (phrases[i][j] != ' '){
				mot += phrases[i][j];
			}else{
				mots.push_back(mot);
				mot="";
			}
		}
		mots.push_back(mot);
		bool valid = true;
		int j = 0;
		while(j < mots.size()-1 && valid){
			int k = j+1;
			while(k < mots.size() && valid){
				/*if (mots[j] == mots[k]){
					valid = false;
				}*/
				if(mots[j].size() == mots[k].size()){
					int l = 0;
					while (l < mots[j].size()){
						int m = 0;
						while (m < mots[j].size()){
							if(mots[j][l] == mots[k][m]){
								mots[k].erase(m,1);
								break;
							}
							m++;
						}
						l++;
					}
					if(mots[k] == ""){
						valid = false;
					}
				}
				k++;
			}

			j++;
		}
		if (valid){
			res++;
		}
	}
	cout << res <<endl;
	return 0;
}
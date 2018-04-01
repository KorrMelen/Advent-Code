#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int modifindice (int i){
	return i % 16;
}

int main(){
	vector<int> table = {14,0,15,12,11,11,3,5,1,6,8,4,9,1,8,4};
	vector <vector<int>> loop;
	bool trouve = false;
	loop.push_back(table);
	int etape = 0;
	while(trouve == false){
		etape++;
		int max = 0;
		for (int i = 1; i < 16; i++){
			if(table[i] > table[max]){
				max = i;
			}
		}
		int  i = 1;
	 	int val = table[max];
		table[max] = 0;
		while(val > 0){
			table [modifindice (max + i)]++;
			val--;
			i++;
		}
		for (int j = 0; j < loop.size(); j++){
			int l = 0;
			for (int k = 0; k < 16; ++k){
				if(table[k] == loop[j][k]) l++;
			}
			if(l == 16){
				cout << (loop.size()+1) - j<< endl;
				cout << etape << endl;
				trouve = true;
				break;
			}
		}
		loop.push_back(table);
	}
	return 0;

}
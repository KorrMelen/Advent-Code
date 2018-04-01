#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	int input = 265149;
	int taille = sqrt(input);
	if (taille % 2 == 0) taille++;
	else taille+=2;
	
	return 0;
}
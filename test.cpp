#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	string test = "test";
	test +=test[1];
	cout <<test<<endl;
	return 0;
}
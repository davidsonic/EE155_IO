#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int factorial (int i){
	return 6;
}
int main () {
string line;
//create a handle for file name “fact.txt”
ofstream fout("fact.txt");

for(int i=1; i<6; i++){ 
cout    << "F( " << i << ")  " << factorial(i) << endl;		
// output factor(i) and endl in the file
fout<< factorial(i)<<endl;

}
//close the file	
fout.close();
return 0;
}

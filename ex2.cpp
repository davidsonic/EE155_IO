#include <iostream>
#include <fstream>
using namespace std;

int main () {
string line;
//create a handle for file named “fact.txt”
ifstream fin("fact.txt");
if( fin.is_open()){
	//read line from the file repeatedly
	while (getline(fin, line)){ 
		cout << "line = " << line << endl;
	} // while()
} // if()	
//close the input file
fin.close();
return 0;
}

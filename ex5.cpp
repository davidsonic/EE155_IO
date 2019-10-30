#include <iostream>
#include <fstream>
using namespace std;

void create() 
{ 
    // file pointer 
    fstream fout; 
  
    // opens an existing csv file or creates a new file. 
    fout.open("reportcard.csv", ios::out | ios::app); 
  
    cout << "Enter the details of 1 students:"
         << " roll name maths"
    << endl; 
  
    int i, roll, math; 
    string name; 
  
    // Read the input 
    for (i = 0; i < 1; i++) { 
  
        cin >> roll 
            >> name 
            >> math ;
        
        cout<<roll<<" "<<name<<" "<<math<<endl;
        // Insert the data to file 
        fout << roll << ","
             << name << ","
             << math
             << "\n"; 
    } 
} 

int main(){
    create();
    return 0;
}
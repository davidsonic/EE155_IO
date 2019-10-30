#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


void read_record() 
{ 
  
    // File pointer 
    fstream fin; 
  
    // Open an existing file 
    fin.open("reportcard.csv", ios::in); 
  
    // Get the roll number 
    // of which the data is required 
    int rollnum, roll2, count = 0; 
    cout << "Enter the roll number "
         << "of the student to display details: "; 
    cin >> rollnum; 
  
    // Read the Data from the file 
    // as String Vector 
    vector<string> row; 
    string line, word, temp; 
  
    while (fin >> temp) { 
  
        row.clear(); 
  
        // used for breaking words 
        stringstream ss(temp); 
  
        // read every column data of a row and 
        // store it in a string variable, 'word' 
        while (getline(ss, word, ',')) { 
  
            // add all the column data 
            // of a row to a vector 
            row.push_back(word); 
        } 
  
        // convert string to integer for comparision 
        roll2 = stoi(row[0]); 
  
        // Compare the roll number 
        if (roll2 == rollnum) { 
  
            // Print the found data 
            count = 1; 
            cout << "Details of Roll " << row[0] << " : \n"; 
            cout << "Name: " << row[1] << "\n"; 
            cout << "Maths: " << row[2] << "\n"; 
            break; 
        } 
    } 
    if (count == 0) 
        cout << "Record not found\n"; 
} 

int main(){
    read_record();
    return 0;
}
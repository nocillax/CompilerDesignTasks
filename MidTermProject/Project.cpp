#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//Read Data from file
string readFile(string outputString){   
    string x;
    fstream newfile;

    newfile.open("input.txt",ios::in); 
    if (newfile.is_open()){ 
        while(getline(newfile, x)){ 
            outputString = outputString + x + " ";
            return outputString;
        }
    newfile.close();
    }
}


int main(){
   
   // Read Data from file and convert to string
    string text;
    text = readFile(text);


    // Assign all the characters into a character vector -> v
    vector<char> v;
    for (int i = 0; i < text.size(); i++){
        v.push_back(text[i]);
    }


    // Seperate all the words into a string vector -> value
    vector<string> value;
    string word; 

    for (int i = 0; i < v.size(); i++){

        word += v[i]; 

        if(v[i]==' '|| v[i]=='+'){
            word.pop_back();
            if(!word.empty()) value.push_back(word);
            word = "";
        }
    }

    // Remove " " from string
    for(int i = 0; i < value.size(); i++){  
        if(value[i].at(0)=='"' && value[i].at(value[i].size()-1)=='"'){
           value[i].erase(value[i].begin());
           value[i].erase(value[i].end()-1);
        }
    }



      for(int i = 0; i < value.size(); i++){
        cout << value[i]<<endl;
    }
}

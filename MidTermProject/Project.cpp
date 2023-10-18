#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
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

    // Remove Punctuation from string
    for(int i = 0; i < value.size(); i++){  

        if(value[i].at(0)=='"' && value[i].at(value[i].size()-1)=='"'){ // Remove " from string front and end
           value[i].erase(value[i].begin());
           value[i].erase(value[i].end()-1);
        }
        if(value[i].at((value[i].size()-1))==')' || value[i].at(0)=='}' || value[i].at(0)==']'){ // Remove ) from string from end
            value[i].erase(value[i].end()-1);
        }
        if(value[i].at(0)=='(' || value[i].at(0)=='{' || value[i].at(0)=='['){ // Remove ( from string from front
            value[i].erase(value[i].begin());
        }
    }

    // Check Punctuation
    set<char> punc;
    string punctuation = ".,;:\"'()[]{}";

    for(int i=0; i<v.size(); i++) {
        int ind = -1;
        ind = punctuation.find(v[i]);

        if(ind>-1){
            punc.insert(v[i]);
        }
    }

    set<char> :: iterator it;

    cout<<"Puntuations are : ";
    for(it = punc.begin(); it!=punc.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // Check Operators
    set<char> opr;
    string operators = "+-*/%=><&|!^~";

    for(int i=0; i<v.size(); i++) {
        int index = -1;
        index = operators.find(v[i]);

        if(index>-1){
            opr.insert(v[i]);
        }
    }

    cout<<"Operators are : ";
    for(it = opr.begin(); it!=opr.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    // Check Keywords
    set<string> key;
    unordered_set<string> keywords = {
        "if", "else", "switch", "case", "default",
        "for", "while", "do", "break", "continue", "return",
        "int", "char", "float", "double", "string", "bool", "void", "auto", "const",
        "static", "extern", "register", "mutable", "class", "struct", "this",
        "new", "delete", "public", "private", "protected",
        "namespace", "try", "catch", "throw", "true", "false",
        "inline", "explicit", "virtual"
    };

    for(int i = 0; i<value.size(); i++) {

        if(keywords.find(value[i]) != keywords.end()){
            key.insert(value[i]);
        }

    }
        
    set<string> :: iterator sit;

    cout<<"Keywords are : ";
    for(sit = key.begin(); sit!=key.end(); sit++){
        cout<<*sit<<" ";
    }
    cout<<endl;



    
    
    
    
    
    
    
    
    for(int i = 0; i < value.size(); i++){
        cout << value[i]<<endl;
    }
}

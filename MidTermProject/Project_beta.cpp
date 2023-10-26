#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>
#include <cctype>
using namespace std;

// Function to read the file
string readFile() {
    string outputString = "";
    string x;
    fstream newfile;

    newfile.open("input.txt", ios::in);
    if (newfile.is_open()) {
        while (getline(newfile, x)) {
            outputString += x + "\n";
        }
        newfile.close();
    } else {
        cout << "Error: Unable to open the file." << endl;
    }
    return outputString;
}

bool isConstant(const string& word) {
    if (word.empty()) return false;

    bool hasDigit = false;
    bool hasQuotes = false;

    for (char c : word) {
        if (isdigit(c)) {
            hasDigit = true;
        } else if (c == '"' || c == '\'') {
            hasQuotes = !hasQuotes;
        } else {
            return false; // Constants can only contain digits and quotes.
        }
    }

    return hasDigit || hasQuotes;
}

int main() {
    string text;
    text = readFile();

    // Split the text into lines
    stringstream ss(text);
    string line;

    set<string> keywords = {
        "if", "else", "switch", "case", "default",
        "for", "while", "do", "break", "continue", "return",
        "int", "char", "float", "double", "string", "bool", "void", "auto", "const",
        "static", "extern", "register", "mutable", "class", "struct", "this",
        "new", "delete", "public", "private", "protected",
        "namespace", "try", "catch", "throw", "true", "false",
        "inline", "explicit", "virtual"
    };

    set<string> operators = {
        "+", "-", "*", "/", "%", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "~"
    };

    set<string> punctuation = {
        ",", ".", ";", ":", "\"", "'", "(", ")", "[", "]", "{", "}"
    };

    while (getline(ss, line, '\n')) {
        cout << "Analyzing line: " << line << endl;

        istringstream lineStream(line);
        string word;

        map<string, vector<string>> lineCategories;

        while (lineStream >> word) {
            // Process each word in the line

            if (keywords.find(word) != keywords.end()) {
                lineCategories["Keywords"].push_back(word);
            } else if (operators.find(word) != operators.end()) {
                lineCategories["Operators"].push_back(word);
            } else if (punctuation.find(word) != punctuation.end()) {
                lineCategories["Punctuation"].push_back(word);
            } else if (isConstant(word)) {
                lineCategories["Constants"].push_back(word);
            }
        }

        for (const auto &category : lineCategories) {
            if (!category.second.empty()) {
                cout << "In this line, the " << category.first << " are: ";
                for (size_t i = 0; i < category.second.size(); ++i) {
                    cout << category.second[i];
                    if (i < category.second.size() - 1) {
                        cout << ", ";
                    }
                }
                cout << endl;
            }
        }
        cout << endl;
    }
}

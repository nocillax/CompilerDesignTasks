#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string expression = "23+510";
    string temp;
    bool flag = false;

    for(int i=0; i<expression.length(); i++){

        temp = expression[i];
        if(temp== "+" || temp== "-" || temp== "*" || temp== "/" || temp== "="){
            flag = true;
            cout<<"Here "<<temp<<" is an operator"<<endl;
        }
    }

    if (!flag) cout<<"There is no operator"<<endl;
}
//Determine if the user input is a number or not

#include <iostream>
#include <string.h>
using namespace std;

int main(){

    string expression;

    cout<<"Please enter a number: "<<endl;
    cin>>expression;

    char exp;
    bool flag = false;
    bool flag2 = false;

    for(int i=0; i<expression.length(); i++){
        exp = expression[i];
        if(!((exp>=48 && exp<=57))){
            flag = true;
            if (flag) flag2 = true;
        }
        else flag = false;
    }
    if (!flag2) cout<<"This is a Number"<<endl;
    else cout<<"This is not a Number"<<endl;
}

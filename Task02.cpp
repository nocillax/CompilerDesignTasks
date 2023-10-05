//Determine if the string is an identifier or not, if not state why. (example User is an identifier but Use(r is not; reason special character)

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string expression = "USe)r";
    char exp;
    bool flag = false;
    bool flag2 = false;
    bool space = false;
    bool specialChar = false;
    bool num = false;

    for(int i=0; i<expression.length(); i++){
        exp = expression[i];
        if(!((exp>=65 && exp<=90)||(exp>=97 && exp<=122))){
            flag = true;
            if (flag) {
                flag2 = true;

                if(exp == 32) space = true;
                if(exp>=48 && exp<=57) num = true;
                if((exp>=33 && exp<=47) || (exp>=58 && exp<=64) || (exp>=91 && exp<=96) || (exp>=123 && exp<=127)) specialChar = true;

            }
        }
        else flag = false;
    }
    if (!flag2) cout<<"This is a Valid Identifier"<<endl;
    else if (space) cout<<"Space is not a Valid Identifier"<<endl;
    else if (num) cout<<"Number is not a Valid Identifier"<<endl;
    else if (specialChar) cout<<"Special Character is not a Valid Identifier"<<endl;
}

//
//  Main.cpp
//  PG1
//
//  Created by Lawrence Johnson on 8/28/14.
//
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "PG1.h"
using namespace std;

string baseten;
string basetwelve;

int main(int argc, char **argv){
    basetwelve = "";
    
    cout << "Enter a integer number: ";
    getline(cin, baseten);
    
    string input = baseten;
    
    convert(baseten);
    
    cout << "Results:\nBase10: " << input << "\nBase12: " << basetwelve << endl;
    
    system("pause");
    
    return 0;
}

void convert(string input){
    string remaining = "";
    string carry = 0;
    for (int place = 0; place <= input.length() - 1; place++) {
        cout << "place: " << place << " input: " << input[place]
        << " carry: " << carry  << endl;
        int working;
        if (carry.length() > 1) {
            working = (carry[0] - '0') + (carry[1] - '0') + (input[place] - '0');
        }
        else {
            working = (carry[0] - '0') + (input[place] - '0');
        }
        cout << "working: " << working << endl;
        if (working > 9) {
            cout << "Entered If" << endl;
            carry = (working / 12);
            cout << "carry: " << carry << endl;
            
            remaining = (char)(working % 12 + '1');
            if (carry.length() > 1) {
                switch (carry[1]) {
                    case('0') : remaining = 'A'; break;
                    case('1') : remaining = 'B'; break;
                }
            }
            cout << "remaining: " << remaining << endl;
            basetwelve = remaining + basetwelve;
        }
        else {
            cout << "Entered Else" << endl;
            carry = working;
            cout << "carry: " << carry << endl;
        }
        /**
         if (working < 10) {
         remaining = remaining + (char)(working % 12 + '0');
         cout << "remaining: " << remaining << endl;
         }
         else {
         switch (working) {
         case(10): remaining = 'A'; break;
         case(11): remaining = 'B'; break;
         }
         }
         **/
        basetwelve = remaining + basetwelve;
    }
}
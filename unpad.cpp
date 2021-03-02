/*
    CIS4362 - Intro to Cryptology
    Ex02- unpad
    Isabella Castro
    09/22/2020

*/


#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <cstring>
#include <fstream>
using namespace std;


int main(int argc, char** argv)
{
    // Getting input
    
    string y;
    while (getline(cin, y)) {
        string x = "";
        x = x + y;

        string out = "";

        // string of valid input
        string vInput = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.";

        // Getting pad character
        char indicator = x[x.length() - 1];

        // Getting the number of pad characters
        int numPad = -1;
        for (int i = 0; i < vInput.length(); i++) {
            if (vInput[i] == toupper(indicator)) {
                numPad = i;
                break;
            }
        }
        if (numPad == 0) {
            numPad = 37;
        }

        // Checking to see if pad character is valid
        if (numPad == -1) {
            cerr << "Invalid padding";
            exit(0);
        }


        // Removing incorrect characters
        for (int i = 0; i < x.length(); i++) {
            char y = tolower(x[i]);
            if (y == 46 || (y > 47 && y < 58) || (y > 96 && y < 123)) {
                out += y;
            }
        }

        // Removing pad characters
        string cOut = "";
        for (int i = 0; i < (out.length() - numPad); i++) {
            cOut += out[i];
        }
        // Formatting output
        int counter = 1;
        for (int count = 0; count < cOut.length(); count += 5) {
            if (count + 5 >= cOut.length()) {

                cout << cOut.substr(count) << "\n";
            }
            else if (counter == 10) {
                counter = 0;
                cout << cOut.substr(count, 5) << "\n";
            }
            else {
                cout << cOut.substr(count, 5) << " ";
            }
            counter++;
        }
    }


}
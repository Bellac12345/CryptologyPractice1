/*
    CIS4362 - Intro to Cryptology
    Ex02- pad
    Isabella Castro
    09/21/2020

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
    if (argc < 2) {
        cerr << "Missing or invalid factor parameter";
        exit(0);

    }
    stringstream convert{ argv[1] };
    int myint{};
    if (!(convert >> myint)) {
        cerr << "Missing or invalid factor parameter";
        exit(0);
    }
    if (myint < 2 || myint> 37) {
        cerr << "Missing or invalid factor parameter";
        exit(0);
    }


    // Getting input
   
    string y;
    while (getline(cin, y)) {
        string x = "";
        x = x + y;

        string out = "";

        // string of valid input
        string vInput = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.";

        // Removing incorrect characters
        for (int i = 0; i < x.length(); i++) {
            char y = tolower(x[i]);
            if (y == 46 || (y > 47 && y < 58) || (y > 96 && y < 123)) {
                out += y;
            }
        }

        // calculating how many pads we need
        int len = out.length();
        int t = len;
        if (len % myint != 0) {

            while (t % myint != 0) {
                t++;
            }
        }
        int numPads = t - len;

        // Choosing the correct pad character
        if (numPads > 0) {
            char pad;
            if (numPads > 36) {
                pad = tolower(vInput[(numPads % 36) - 1]);
            }
            else {
                pad = tolower(vInput[numPads]);
            }
            for (int i = 0; i < numPads; i++) {
                out += pad;
            }

        }
        

        // Formatting output
        int counter = 1;
        for (int count = 0; count < out.length(); count += 5) {
            if (count + 5 >= out.length()) {

                cout << out.substr(count) << "\n";
            }
            else if (counter == 10) {
                counter = 0;
                cout << out.substr(count, 5) << "\n";
            }
            else {
                cout << out.substr(count, 5) << " ";
            }
            counter++;
        }

    }
}
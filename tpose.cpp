/*
    CIS4362 - Intro to Cryptology
    Ex02 - tpose
    Isabella Castro
    09/23/2020
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <cstring>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    // Checking if key file was passed
    if (argc < 2) {
        cerr << "Missing key file name";
        exit(0);
    }
    string filename = argv[1];
    ifstream inFile;

    inFile.open(filename.c_str());

    // checking that key file can be opened
    if (!inFile)
    {
        cerr << "Key file cannot be opened";
        exit(0);
    }

    // Getting key from key file
    string key = "";
    string y;
    while (getline(inFile, y)) {
        key = key + y;
    }
    inFile.close();

    // Removing white spaces from key
    istringstream iss(key);
    vector<string> keyf(istream_iterator<string>{iss},
        istream_iterator<string>());
    
    // Checking to see if key is valid
    if (keyf.size() > 16) {
        cerr << "Invalid key 1";
        exit(0);

    }
    int keylen = keyf.size();
    int num;
    for (int i = 0; i < keylen; i++) {
        num = i;
        ostringstream strg;
        strg << num;
        string s1 = strg.str();
        if (find(keyf.begin(), keyf.end(), s1) == keyf.end()) {
            cerr << "Invalid key 2";
            exit(0);
        }
         
    }


    // Getting input
    y = "";
    
    while (getline(cin, y)) {
        string in = "";
        in += y;




        // Removing white spaces 
        string inn = "";
        for (int i = 0; i < in.length(); i++) {
            char y = in[i];
            if (y != 32) {
                inn += y;
            }
        }

        // Checking to see if input is valid
        if (inn.length() % keyf.size() != 0) {
            cerr << "Invalid input length";
            exit(0);
        }

        // Transposing
        string out = "";
        for (int i = 0; i <= inn.length() - keyf.size(); i += keyf.size()) {
            string t = inn.substr(i, keyf.size());
            for (string x : keyf) {
                stringstream convert;
                string xx = x + "";
                convert << xx;
                int pos;
                convert >> pos;
                out += t[pos];
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


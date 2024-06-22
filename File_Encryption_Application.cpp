#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Caesar(string hidden,int jump,bool encdec){ // encdec = Encrypt/Decrypt

    for (char &c : hidden){
        if(encdec){
            if(isspace(c))
                continue;
            if(isupper(c))
                c = (c - 'A'+jump) %26 + 'A';
            else
                c = (c - 'a'+jump) %26 + 'a';
        }
        else{
            if(isupper(c))
                c = (c - 'A'-jump) %26 + 'A';
            else
                c = (c - 'a'-jump) %26 + 'a';
        }
    }
    return hidden;
}
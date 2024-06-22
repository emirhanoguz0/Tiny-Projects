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

string rot13encrypt(string text)
{
    string encryptedText = text;
    for (int i = 0; i < text.length(); ++i)
    {
        if (isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            encryptedText[i] = (((text[i] - base) + 13) % 26) + base;
        }
    }
    return encryptedText;
}

string rot13decrypt(string text)
{
    string decryptedText = text;
    for (int i = 0; i < text.length(); ++i)
    {
        if (isalpha(text[i]))
        {
            char base = isupper(text[i]) ? 'A' : 'a';
            decryptedText[i] = (((text[i] - base) - 13) % 26) + base;
        }
    }
    return decryptedText;
}

string file_reading(){

    string message;

        ifstream read("file.txt", ios::in);

        if(!read.is_open()){
            cout<<"Error!! File could not be opened!!";
            exit(1);
        }

        getline(read,message);
        read.close();

    return message;
}

void file_writing(string message2){

    ofstream write("file.txt", ios::trunc);

        if(!write.is_open()){
            cout<<"Error!! File could not be opened!!";
            exit(1);
        }

    write << message2;
    write.close();
}

int main(){

    string text;
    int key, c;
    bool encdec;

    cout<<"Encrypt(1) or decrypt(0): ";
    cin>>encdec;

    cout<<"Which algorithm do you want to use ?\n1-Caesar encryption\n2-Rot13 encryption\n";
    cin>>c;

    switch(c){

        case 1:
            cout<<"key?";
            cin>>key;
            text = Caesar(file_reading(),key,encdec);
            break;
        case 2:
            if(encdec)
                text = rot13encrypt(file_reading());
            else
                text = rot13decrypt(file_reading());
                break;
    }
    file_writing(text);
}
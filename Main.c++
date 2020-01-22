// Project5-Cypher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>

using namespace std;
int main(){
    int selection=0;
    string message = "";
    string oldMessage = "";
    int key = 0;
    //Begin while loop
    while(selection != 3){
        cout << "1) Encoding a message?" << endl;
        cout << "2) Decoding a message?" << endl;
        cout << "3) Exit" << endl;
        cin >> selection;
        //Encoding Function
        if(selection == 1) {
            system("CLS");
            cout << "Enter key" << endl;
            cin >> key;
            cin.ignore(256, '\n');
            cout << "Enter message to encode" << endl;
            getline(cin, message);
            oldMessage = message;
            //takes care of keys bigger than 26
            key = key % 26;
            char ch;
            for (int i = 0; message[i] != '\0'; ++i) {
                ch = message[i];
                //encode for lowercase letter
                if(ch >= 'a' && ch <= 'z') {
                    ch = ch + key;
                    if (ch > 'z') {
                        ch = ch - 'z' + 'a' - 1;
                    }
                    message[i] = ch;
                }
                //encode for uppercase letter
                else if (ch >= 'A' && ch <= 'Z') {
                    ch = ch + key;
                    if (ch > 'Z') {
                        ch = ch - 'Z' + 'A' - 1;
                    }
                    message[i] = ch;
                }
            }
            system("CLS");
            //Output results
            cout << "Your key is: " << key << endl;
            cout << "Your original message was: " << oldMessage << endl;
            cout << "Your encoded message is: " << message << endl << endl;
        }else if(selection==2){
            system("CLS");
            cout << "Enter key" << endl;
            cin >> key;
            cin.ignore(256, '\n');
            cout << "Enter message to encode" << endl;
            getline(cin, message);
            oldMessage = message;
            //Key greater that 26 
            key = key % 26;
            char ch;
            for (int i = 0; message[i] != '\0'; ++i) {
                ch = message[i];
                //decrypt for lowercase letter
                if (ch >= 'a' && ch <= 'z') {
                    ch = ch - key;
                    if (ch < 'a') {
                        ch = ch + 'z' - 'a' + 1;
                    }
                    message[i] = ch;
                }
                //decrypt for uppercase letter
                else if (ch >= 'A' && ch <= 'Z') {
                    ch = ch - key;
                    if (ch < 'A') {
                        ch = ch + 'Z' - 'A' + 1;
                    }
                    message[i] = ch;
                }
            }
            //Output results
            cout << "Your key is: " << key << endl;
            cout << "Your original message was: " << oldMessage << endl;
            cout << "Your decoded message is: " << message << endl << endl;
        }
        else if(selection == 3) {

        }
        else{
            system("CLS");
            cout << "Selection is invalid" << endl;
        }
    }
    //End while loop
    return 0;
}



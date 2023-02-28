#include <iostream>

using namespace std;

// Reverse string
int main(){

    char text[] = "Hello, world!";

    int nChars = sizeof(text) - 1;

    char* pStart = text;
    char* pEnd = pStart + nChars - 1; //if not -1, will get the null end char

    cout << "Input string is: " << text << endl;
    cout << "nChars: " << nChars << endl;
    cout << "pStart: " << *pStart << endl;
    cout << "pEnd: " << *pEnd << endl;

    while(pStart < pEnd){

        char buff = *pStart;
        // Swap char positions
        *pStart = *pEnd;
        *pEnd = buff;

        pStart++;
        pEnd--;
    }

    cout << "Reversed string: " << text << endl;

    cout << "De-reversed string: " << flush;
    for(int k=nChars; k>=0; k--){
        cout << text[k] << flush;
    }
    return 0;
}
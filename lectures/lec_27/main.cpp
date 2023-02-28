#include <iostream>

using namespace std;

int main(){
    char text[] = "Hello world";
    cout << "\n### First" << endl;
    for (int i=0; i<sizeof(text); i++){
        cout << i << ": " << text[i] << endl;
    }

    // Show null end char
    cout << "\n### Second" << endl;
    for(int i=0; i<sizeof(text); i++){
        cout << i << ": " << (int)text[i] << endl;
    }

    cout << "\n### Third" << endl;
    int k = 0;
    while (true){
        if(text[k]==0) break;
        cout << k << ": " << text[k] << endl;

        k++;
    }
    
    return 0;
}
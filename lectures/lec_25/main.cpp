#include <iostream>

using namespace std;

int main(){

    long int seconds = 3457264;
    int hours = seconds / (60*60);
    int minutes = (seconds % (60*60)) / 60;
    int remainSeconds = seconds % 60;

    cout << "Seconds input: " << seconds << endl;
    cout << hours << " hours, " << minutes << " minutes," << remainSeconds << " seconds" << endl;

    cout << "\nProcessing list" << flush;
    for(int i=0; i<10000; i++){
        if(i%100 == 0) {
            cout << "." << flush;
        }
    }
    return 0;
}
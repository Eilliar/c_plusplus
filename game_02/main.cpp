#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int get_level(){

    short int level;

    while(true){
        cout << "Enter a level (1, 2 or 3): " << flush;
        cin >> level;

        if(level<4 & level>0) break;
    }

    return level;
}

int generate_integer(short int level){

    int number = rand() % (int)pow(10, level);

    return number;
}

int main(){
    srand((unsigned int)time(NULL)); // set random seed

    int userAnswer;
    int answer;
    short int level = get_level();
    

    for(int k=0; k<10; k++){
        int x = generate_integer(level);
        int y = generate_integer(level);
        answer = x + y;

        while(true){
            cout << x << " + " << y << " = " << flush;
            cin >> userAnswer;
            
            if(userAnswer == answer) {
                break;
            }
            else {
                cout << "EEE" << endl;
            }
        }
    }
    
    return 0;
}
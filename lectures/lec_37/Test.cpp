#include "Test.h"

int Test::count = 0;

Test::Test(){ 
    this->id = this->count++;
}

Test::~Test(){
    cout << "Object ID " << this->id << " is being destroyed" << endl;
}

void Test::ShowInfo(){ 
    cout << "Object ID: " << this->id << endl; 
};
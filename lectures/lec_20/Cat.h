#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

class Cat {

private:
    // bool happy = true; // available in modern c++
    bool happy; // non initialized, should use a constructor to initialize
public:
    void speak();
    void jump();
    void makeHappy();
    void makeSad();
    Cat();
    ~Cat();
};

#endif
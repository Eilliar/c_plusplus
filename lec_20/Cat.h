#ifndef CAT_H_INCLUDED
#define CAT_H_INCLUDED

class Cat {

private:
    bool happy = true; // available in modern c++
public:
    void speak();
    void jump();
    void makeHappy();
    void makeSad();
};

#endif
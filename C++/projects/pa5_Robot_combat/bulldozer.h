#ifndef BULLDOZER_H
#define BULLDOZER_H
#include <iostream>
#include "robot.h"



// Bulldozer class inherit from robot class
class Bulldozer : public Robot
{
    public:
        // Constructors and display method 
        Bulldozer();
        Bulldozer(int newStrength,int newHitPoint);

        friend ostream& operator<< (ostream& out, const Bulldozer& obj);

    private:
        static int size;
        int index = -1;
};


#endif
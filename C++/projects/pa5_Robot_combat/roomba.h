#ifndef ROOMBA_H
#define ROOMBA_H
#include <iostream>
#include "robot.h"


// NOte Roomba class inherit from robot class

class Roomba : public Robot
{
    public:
        // Constructors 
        Roomba();
        Roomba(int newStrength,int newHitPoint);

        // Special getDamage for this robot so override it 
        int getDamage() const;

        friend ostream& operator << (ostream& out, const Roomba& obj);

    private:

        static int size;
        
        int index = -1;
};


#endif
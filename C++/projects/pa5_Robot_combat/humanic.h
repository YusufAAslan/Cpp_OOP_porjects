#ifndef HUMANIC_H
#define HUMANIC_H
#include <iostream>
#include "robot.h"


// Humanic class to classify the robots 

class Humanic : public Robot
{
    public:

        // Constructor as usual 
        
        Humanic();
        
        Humanic(int newStrength,int newHitPoint);  
        

        // We need here a special getDamage method so we override it 
        // Where humanic robots have a 10% chance of inflicting a tactical
        // Nuke attack which is an additional 50 damage points
        int getDamage() const;
        
        friend ostream& operator << (ostream& out, const Humanic& obj);
    private:
    static int size;
    int index = -1;
};


#endif
#ifndef ROBOCOP_H
#define ROBOCOP_H
#include <iostream>
#include "humanic.h"


// This class inherit from humanic class

class RoboCop : public Humanic
{
    public:
        // Constructors 
        RoboCop();
        
        RoboCop(int newStrength,int newHitPoint);


        // Method for display
        friend ostream& operator << (ostream& out, const RoboCop& obj);
    
    private:
        
        static int size;
    
        int index = -1;
};


#endif
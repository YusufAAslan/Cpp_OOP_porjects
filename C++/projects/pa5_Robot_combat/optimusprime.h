#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H
#include <iostream>
#include "humanic.h"


// OptimusPrime class inherit from humanic class
class OptimusPrime : public Humanic
{
    public:
        

        // Constructors
        OptimusPrime();
        
        OptimusPrime(int newStrength,int newHitPoint);
        
        //  Special damage for this robot 
        // Where OptimusPrime has 15% chance of inflict so override it  
        int getDamage() const;
        friend ostream& operator << (ostream& out, const OptimusPrime& obj);
    private:
        static int size;
        int index = -1;

};


#endif
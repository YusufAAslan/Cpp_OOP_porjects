#include <iostream>
#include "humanic.h"
#include "robot.h"


// All details taken from the given pdf with
// At the start
int Humanic::size = 0;


// Constructors 
Humanic::Humanic()
{
    index = size++;
    type = 5 ;
    strength = 0;
}

Humanic::Humanic(int newStrength,int newHitPoint)
{
    type = 5 ;
    index = size ++;
    strength = newStrength;
    hitPoint = newHitPoint;
}



// Humanic class methods explains it self as its given in the pdf

int Humanic::getDamage() const
{
    int tacticalNukAttack = rand() % 10;
    if(tacticalNukAttack==0)
        return 50 + Robot::getDamage();
        
    return Robot::getDamage();
}


// This to display the details 

ostream& operator<< (ostream& out, const Humanic& obj)
{
    out << "Type: " << obj.getType() << " " << obj.index << std::endl
        << "Strength: " << obj.getStrength() << std::endl
        << "Hit points: " << obj.getHitPoint() << std::endl << std::endl;
    return out;
}



#include "roomba.h"


//  At the start 
int Roomba::size = 0;

// Constructors 
Roomba::Roomba()
{
    index = size++;
    type = 2;
    strength = 3;
    hitPoint = 10;

}
Roomba::Roomba(int newStrength,int newHitPoint)
{
    index = size++;   
    type = 2;
    strength=newStrength;
    hitPoint = newHitPoint;
}



// Get damage special for roomba  
int Roomba::getDamage() const
{
    return Robot::getDamage() + Robot::getDamage();
}



// Display 
ostream& operator<< (ostream& out, const Roomba& obj)
{
    out << "Type: " << obj.getType() << " " << obj.index <<  std::endl
        << "Strength: " << obj.getStrength() << std::endl
        << "Hit points: " << obj.getHitPoint() << std::endl << std::endl;
    return out;
}

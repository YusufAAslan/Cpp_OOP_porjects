#include "bulldozer.h"



// At the start 
int Bulldozer::size = 0;

// Constructors  and details from pdf 
Bulldozer::Bulldozer()
{
    index = size++;
    type = 3;
    strength = 50;
    hitPoint = 200;
}

Bulldozer::Bulldozer(int newStrength,int newHitPoint)
{
    index = size++;
    type = 3;
    strength=newStrength;
    hitPoint = newHitPoint;
}


// Display
ostream& operator<< (ostream& out, const Bulldozer& obj)
{
    out << "Type: " << obj.getType() << " "  << obj.index << std::endl
        << "Strength: " << obj.getStrength() << std::endl
        << "Hit points: " << obj.getHitPoint() << std::endl << std::endl;
    return out;
}

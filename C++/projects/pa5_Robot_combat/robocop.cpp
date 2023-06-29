#include "robocop.h" 


// At the start 
int RoboCop::size = 0;



// Constructors and assign values given in pdf 
RoboCop::RoboCop()
{
    index = size;
    ++size;
    type = 1;
    strength = 30;
    hitPoint = 40;
}

RoboCop::RoboCop(int newStrength,int newHitPoint)
{
    index = size;
    ++size;
    type = 1;
    strength=newStrength;
    hitPoint = newHitPoint;
}



//  Display

ostream& operator<< (ostream& out, const RoboCop& obj)
{
    out << "Type: " << obj.getType() << " "<< obj.index << std::endl
        << "Strength: " << obj.getStrength() << std::endl
        << "Hit Points: " << obj.getHitPoint() << std::endl << std::endl;
    return out;
}

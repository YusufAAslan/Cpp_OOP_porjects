#include "optimusprime.h" 

// At the start 
int OptimusPrime::size = 0;


// Constructors 
OptimusPrime::OptimusPrime()
{
    index = size;
    ++size;
    type = 0;
    // given values from the pdf 
    strength = 100;
    hitPoint = 100;
}

OptimusPrime::OptimusPrime(int newStrength,int newHitPoint)
{
    index = size;
    ++size;
    type = 0;
    strength=newStrength;
    hitPoint = newHitPoint;
}




// OptimusPrime class methods 
int OptimusPrime::getDamage() const
{
    int doubleTheDamage = rand() % 100;
    if(doubleTheDamage < 15)
        return Humanic::getDamage()*2;
    return Humanic::getDamage();
}




// For displaying 
ostream& operator<< (ostream& out, const OptimusPrime& obj)
{
    out << "Type: " << obj.getType() << " "<< obj.index << std::endl
        << "Strength: " << obj.getStrength() << std::endl
        << "Hit Points: " << obj.getHitPoint() << std::endl << std::endl;
    return out;
}

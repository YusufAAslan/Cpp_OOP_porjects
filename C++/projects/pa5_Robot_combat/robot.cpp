#include <iostream>
#include <string.h>

#include "robot.h"

using std::string;


// At the start 
int Robot::size = 0;

Robot::Robot()
{
    // when creat obj make size ++ 
    index = size++;
    type  = 4;
    hitPoint = 0;
    strength = 0;
}

    


Robot::Robot(int newType, int newStrength,int newHit,string name)
{
    // when creat obj make size ++ 
    // Assign the given values 
    index = size++;
    type = newType;
    strength = newStrength;     
    hitPoint = newHit;
    currentName = name;
}



// Classes methods implimentaion explains it self 

string Robot::getType() const
{
    switch(type)
    {

        case 0:     return "optimusprime";
        case 1:     return "robocop";
        case 2:     return "roomba";
        case 3:     return "bulldozer";
    }

    return "unknown";
}






int Robot::getStrength() const
{
    return strength;
}




void Robot::setStrength(int newStrength) 
{
    strength = newStrength;
}




int Robot::getHitPoint() const 
{
    return hitPoint;
}




void Robot::setHitPoint(int newHitPoint)
{
    hitPoint = newHitPoint;
}



string Robot::getName() const 
{
    return currentName;
}





void Robot::setName(string newName)
{
    currentName = newName;
}





int Robot::getDamage() const
{
    if(strength > 0)
        return rand() % strength + 1;
    return 0;
}




ostream& operator<< (ostream& out, const Robot& obj)
{
    out << "Type: " << obj.getType() << " " << obj.index << std::endl
        << "Strength: " << obj.getStrength() << std::endl
        << "Hit Points: " << obj.getHitPoint() << std::endl << std::endl;
    return out;
}


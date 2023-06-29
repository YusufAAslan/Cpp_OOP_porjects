#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string.h>
using std::string;
using std::ostream;


class Robot
{
    



    public:
    //  Default Constructor
    Robot();

    //  Sets the values of variables type,strength and hitpoints and name 
    Robot(int newType, int newStrength, int newHit, string name);



    // getters and setters


    //  Returns the type of object
    string getType() const;

    //  Returns the strength of object
    int getStrength() const;

    //  Sets the strength of object
    void setStrength(int newStrength) ;

    //  Returns the hitpoints of object
    int getHitPoint() const;

    //  Sets the hitpoints of object
    void setHitPoint(int newHit);


    // retrurn the name of object like robocop1 2 3 not only the type 
    string getName() const;
    // set the name of object
    void setName(string newName) ;



    //  Returns the damage that a robot inflict in one round
    
    virtual int getDamage() const;

    //  Returns the properties of the object
    friend ostream& operator << (ostream& out, const Robot& obj);
    
    // The data we want to inherit 
    protected:
    int type;   //  Holds the type 
    int strength;   //  Holds the strength
    int hitPoint;     //  Holds the hitpoints
    string currentName; // Hold the name

    
    private: 
    static int size ;   // Count the number of objects created from this class
    int index;  //  keeps the index of the object
};


#endif


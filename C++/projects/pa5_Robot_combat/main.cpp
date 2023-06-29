// ITS ROBOTS COMBAT SIMULATION  

// NOTE: I didnt make the simulation in grid after I wrote the wanted classes 
// I tested them in main and I made combat as a text messeges as you will see
// in the given tests photos or when you combile and run


// The COMBAT happen between 2 robots 2 robots as you test in main 
// Include all needed header files and namespaces 

#include <iostream>
#include <time.h>
#include "robot.h"
#include "bulldozer.h"
#include "roomba.h"
#include "humanic.h"
#include "optimusprime.h"
#include "robocop.h"

using namespace std;





// This boolean method returns 0 if robot1 wins and return 1 if robot2 wins 
// The winner robot wins when the other has 0 or less hitpoints
bool combat(const Robot& robot1,const Robot& robot2);



int main()
{

    cout<<"\n---------------GAME START---------------"<<endl<<endl;
    

    // Needed for random operations 
    srand(time(NULL));
    
    // Declar the objects for diffrent types  robots that will join the combat


    ////////////////////////////////////////////////////////////////
    // To Test WITH INITIAL VALUES  uncomment the following 6 lines 

    // Robot robot1,robot2(0,100,100,"optimusprime");
    // Humanic humnic1,humnic2;

    // OptimusPrime optimusprime;
    // RoboCop robcob;
    // Roomba roomb1,roomb2;
    // Bulldozer bulldozr;
    ////////////////////////////////////// up to here 

    // TEST WITH OTHER VALUES
    Robot robot1,robot2(0,10,100,"optimusprime");
    Humanic humnic1,humnic2(10,100);

    OptimusPrime optimusprime(100,100);
    RoboCop robcob(10,100);
    Roomba roomb1(10,100),roomb2(10,100);
    Bulldozer bulldozr;



    cout<<"TEST the details of robots:  "<<endl;
    // First display the details by using the written overloaded operators to test them 
    cout << robot1 << robot2 << roomb1 << roomb2 << humnic1 << humnic2 << optimusprime << bulldozr << robcob;
    cout<<"START the combat: "<<endl;
    // Then Let the combat BEGIN --
    if(combat(robot1,robot2))
    {
        cout << "robot2 won !! " << endl<<endl;
    }else
    {
        cout << "robot1 won !! " << endl<<endl;
    }
    if(combat(roomb1,roomb2))
    {
        cout << "room2 won !! " << endl<<endl;
    }else
    {
        cout << "room1 won !! " << endl<<endl;
    }
    if(combat(roomb1,optimusprime))
    {
        cout << "optimusprime won !! " << endl<<endl;
    }else
    {
        cout << "room1 won !! " << endl<<endl;
    }
    if(combat(humnic2,bulldozr))
    {
        cout << "buldozer won !! " << endl<<endl;
    }else
    {
        cout << "humnic2 won !! " << endl<<endl;
    }
    if(combat(robcob,optimusprime))
    {
        cout << "optimusprime won !! " << endl<<endl;
    }else
    {
        cout << "robcob won !! " << endl<<endl;
    }

    cout<<"\n---------------GAME END---------------"<<endl<<endl;    

}







// This metod return 0 if robot 1 is the winner
// And returns 1 if robot 2 is the winner

bool combat(const Robot& robot1,const Robot& robot2)
{
    // Hold the Hit points 
    int firstHitPoints = robot1.getHitPoint();
    int secondHitPoints = robot2.getHitPoint();


    // Hit massage
    // cout<<robot1.getName()<<"hits "<<robot2.getName()<<"with "<<abs(firstHitPoints - secondHitPoints)<<endl;

    // Keep working untill one of the robots dies 
    while(1)
    {

        if(secondHitPoints <= 0)
        {
            return 0;
        }else if(firstHitPoints <= 0)
        {
            return 1;
        }else
        {
            // Decrement the hitpoints from both 
            secondHitPoints -= robot1.getDamage();
            firstHitPoints -= robot2.getDamage();
        }
    }
    return 0;
}
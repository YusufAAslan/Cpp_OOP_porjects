#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;


// Declare our global constants  variabes taken from given pdf that will be used 
const int worldSize = 20 ;   
const int intialAnts = 100;	
const int intialBugs = 5;
const int doodleBug = 1;
const int ant = 2;
const int antBreed = 3;
const int doodleBreed = 8;
const int doodleStarve = 3;


///////////////////////////////////////////END OF CONSTANTS


// Forward declaration of our classes

class Organism ; 
class Doodlebug ;
class Ant;
class World; 


///////////////
// creat a class name world to do and display the simulation at the end and it's friend to all class that we need 

class World
{
	friend class Organism;
	friend class Doodlebug;
	friend class Ant ;

private:
	Organism* grid[worldSize][worldSize];

public:

	//constructor
	World();
	// and of cours desturctor
	~World(){

	};


	//member functions to use 

	Organism* getAt(int x, int y);
	void setAt(int x , int y,Organism *org);
	void display();
	void simulateOneStep();



};
//////////////////////// end of class world




class Organism
{
	friend class World;
public:
	Organism();
	Organism(World *world,int x , int y);
	~Organism();
	virtual void breed() = 0 ;
	virtual void move() = 0 ;
	virtual int getType() = 0 ;
	virtual bool starve() = 0 ;
protected:
	int x , y ;
	bool moved;
	int breedFlag;
	World *world ;

};

///////////////// end pf organism class




///////////////////////////////////////////

class Ant :public Organism
{
	friend class World;
public:
	//constructor
	Ant();
	Ant(World *world , int x ,int y);

	//Methods 
	void breed();
	void move();
	int getType();
	bool starve()
	{
		return false;
	}

};




// creat a class Doodlebug which is derived from organism and has some member functions
class Doodlebug : public Organism
{
	friend class World;
public:
	Doodlebug();
	Doodlebug(World *world,int x,int y);
	void breed();
	void move();
	int getType();
	bool starve();
private:
	int starveFlag;


};




///////////////////////////////////////////////////////////MAIN function

int main()
{


	// and now define world object
	World obj;
	//define random number generator will be used to creat insects to use in simulation
	srand(time(NULL));



	// create doodleBugs randomly and put them in the appropriate cells  
	int countOfDoodle = 0;
	while(countOfDoodle < intialBugs)
	{
		int x = rand() % worldSize;
		int y = rand() % worldSize;

		// create and put new  doodleBug in empty cells only
		if (obj.getAt(x,y) == NULL)
		{
			countOfDoodle++;
			Doodlebug * doodle = new Doodlebug(&obj,x,y);
		}
	}

	///////////


	//also make 100 ants randolmy and put them in the appropriate cells
	int countOfAnts = 0 ;
	while(countOfAnts < intialAnts)
	{
		int x = rand() % worldSize;
		int y = rand() % worldSize;

		//  put new  ants in empty cells only
		if (obj.getAt(x,y) == NULL)
		{
			countOfAnts++;
			Ant * annt = new Ant(&obj,x,y);
		}
	}

	
	//string will be use to take Enter key  from user after every turn 
	string str;
	
	//and now run a simulation which contiune turn after turn with enters from user  until user cancel
	while(true){
		obj.display();	
		obj.simulateOneStep();
		
		cout<<"\nPress enter for next step"<<endl;
		getline(cin,str);
		
	} 



	return 0;
}

///////////////////////////////////////////////////END MAIN



 World::World()
{

	int i , j ;
	for ( i = 0; i < worldSize; ++i)
	{
		for ( j = 0; j <worldSize ; ++j)
		{
			grid[i][j]=NULL;

		}
	}

}




Organism* World::getAt(int x, int y)
{	

	if (( x >= 0) && (x<worldSize) && (y>=0) &&(y<worldSize) )
	{
		return grid[x][y];
	}
	return NULL;

}



void World::setAt(int x , int y, Organism *org)
{
	if ((x>=0) && (x<worldSize) && (y>0) && (y<worldSize))
	{
		grid[x][y] = org;
	}
}



void World::display()
{
	int i , j,counter=0 ;
	cout<<endl<<endl;
	for ( j = 0; j < worldSize; ++j)
	{
		for ( i = 0; i < worldSize; ++i)
		{
			if (grid[i][j] == NULL)
			{
				cout<<".";

			}
			else if (grid[i][j]->getType()==ant) // put o to refer to ant 
			{
				cout<<"o";
			}

			else
				cout<<"X";	//to display doodlebugs 
		}// end for i

		cout<<endl;


	}//end for j



}


//Defintion of simulateOneStep

void World::simulateOneStep()
{
	int i , j ;
	// first reset all creatures to not moved

	for ( i = 0; i < worldSize; ++i)
	{
		for ( j = 0; j < worldSize; ++j)
		{
			if (grid[i][j] != NULL)
			{
				grid[i][j] -> moved =false;
			}
		}// end for i


	}// end for j


	// loop for doodlebug  to check the borders if empty  and move if it's possible
	for ( i = 0; i < worldSize; ++i)
	{
		for (j = 0; j < worldSize; ++j)
		{
			if ((grid[i][j] != NULL) && (grid[i][j]->getType() == doodleBug))
			{
				if (grid[i][j] -> moved == false)
				{
					grid[i][j] -> moved = true;
					grid[i][j] -> move();
				}
			}


		}//end for i


	}//end for j



	// loop for Ant  to check the borders if empty  and move if it's possible
	
	for ( i = 0; i < worldSize; ++i)
		{
			for ( j = 0; j < worldSize; ++j)
			{
				if ((grid[i][j] != NULL) && (grid[i][j] -> getType() == ant))
				{
					if (grid[i][j] -> moved == false)
					{
						grid[i][j] -> moved = true;
						grid[i][j] -> move();
					}
				}
			}  // end for j


		}// end for i




	


		for ( i = 0; i < worldSize; ++i)
		{
			for ( j = 0; j < worldSize; ++j)
			{

			
				if ((grid[i][j] != NULL) && (grid[i][j] -> getType() == doodleBug))
				{
					if (grid[i][j] -> starve())
					{
						delete (grid[i][j]);
						grid[i][j] = NULL;
					}
				}
			}// end for j


		} // end for i



	// loop for ant  to check the borders   and eat(breed) if it's possible
		for ( i = 0; i < worldSize; ++i)
		{
			for ( j = 0; j < worldSize; ++j)
			{
				if ((grid[i][j] != NULL) && (grid[i][j] -> moved == true))
				{
					grid[i][j] -> breed();
				}
			} // end for j


		}// end for i

		

}

// Defualt constructor of organism as a start 

Organism::Organism()
{
	world = NULL;
	moved = false ;
	breedFlag = 0 ;
	x = 0;
	y = 0 ;
}

//parametrised constructor 

Organism::Organism(World *wrld ,int x , int y)
{
	this->world = wrld ;
	moved = false ;
	breedFlag = 0;
	this->x = x;
	this->y = y ;
	wrld->setAt(x,y,this);

}

//Destrutcor

Organism::~Organism()
{	
}



/////////////////////////////

//Defualte consstructorr

Ant::Ant() : Organism()
{	
}

//parametrised constructor

Ant::Ant(World *world,int x ,int y) : Organism(world,x,y)
{	
}

//and here the  defintion of move function  for Ant which can move in four directions 

void Ant::move()
{
	// choose random direction to move
	int direction = rand() % 4 ;
	//try to move up,if not at an edge and empty cell
	if (direction==0)
	{
		if ((y>0)&& (world->getAt(x,y-1) == NULL))
		{
			world->setAt(x,y-1, world->getAt(x,y));

			//Move to new cell

			world->setAt(x,y,NULL);
			y--;
		}
	}

	//try to move down
	else if (direction == 1)
	{
		if ((y < worldSize - 1)&& (world->getAt(x,y+1) == NULL))
		{
			world->setAt(x,y+1, world->getAt(x,y));

			//Move to new cell

			world->setAt(x,y,NULL);
			y++;
		}
	}

	// try to move left
	else if (direction == 2)
	{
		if ((x>0)&& (world->getAt(x-1,y) == NULL))
		{
			world->setAt(x-1,y, world->getAt(x,y));

			//Move to new celll

			world->setAt(x,y,NULL);
			x--;
		}
	}

	// try to move right

	else
	{
		if ((x < worldSize - 1 )&& (world->getAt(x+1,y) == NULL))
		{
			world->setAt(x+1,y, world->getAt(x,y));

			//Move to new spot

			world->setAt(x,y,NULL);
			x++;
		}
	}

}


int Ant::getType()
{
	return ant;
}


void Ant::breed()
{
	breedFlag++;
	if (breedFlag == antBreed)//is survive time of ant  equal to 3 
	{
		breedFlag = 0;
		//try to make new ant either above ,left,right
		if ((y>0) && (world->getAt(x , y - 1) == NULL))
		{
			Ant *newAnt = new Ant(world,x,y-1);
		}
		else if ((y<worldSize -1) && (world -> getAt(x,y+1) == NULL))
		{
			Ant *newAnt = new Ant(world,x,y+1);
		}
		else if ((x>0) && (world->getAt(x-1,y)== NULL))
		{
			Ant *newAnt = new Ant(world,x-1,y);
		}
		else if ((x<worldSize -1) && (world->getAt(x+1,y)== NULL))
		{
			Ant *newAnt = new Ant(world,x+1,y);
		}
	}
}

///////////////////////////////Doodlebugs





Doodlebug::Doodlebug(): Organism()
{
	starveFlag = 0;
}

Doodlebug::Doodlebug(World *world , int x,int y):Organism(world,x,y)
{
	starveFlag = 0;
}

//Define move function for Doodle bug like move function of ant up
void Doodlebug::move()
{
	// The doodle bug can eat ant and sit in it's place 
	if ((y>0) &&(world->getAt(x,y-1))!= NULL && (world->getAt(x,y-1)->getType() == ant))
	{
		delete (world->grid[x][y-1]);
		world->grid[x][y-1] = this;
		world->setAt(x,y,NULL);
		starveFlag = 0;
		y--;
		return;
	}
	else if ((y < worldSize-1) && (world->getAt(x,y+1) != NULL) &&(world->getAt(x,y+1)->getType()== ant))
	{
		delete (world->grid[x][y+1]);
		world->grid[x][y+1] = this;
		world->setAt(x,y,NULL);
		starveFlag = 0;
		y++;
		return;
	}
	else if ((x>0) &&(world->getAt(x-1,y))!= NULL && (world->getAt(x-1,y)->getType() == ant))
	{
		delete (world->grid[x-1][y]);
		world->grid[x-1][y] = this;
		world->setAt(x,y,NULL);
		starveFlag = 0;
		x--;
		return;
	}

	else if ((x < worldSize-1) && (world->getAt(x+1,y) != NULL) &&(world->getAt(x+1,y)->getType()== ant))
	{
		delete (world->grid[x+1][y]);
		world->grid[x+1][y] = this;
		world->setAt(x,y,NULL);
		starveFlag = 0;
		x++;
		return;
	}




	int direction = rand() % 4 ;
	//try to move up ,

	if (direction==0)
	{
		if ((y>0)&& (world->getAt(x,y-1) == NULL))
		{
			world->setAt(x,y-1, world->getAt(x,y));

			//Move to new spot

			world->setAt(x,y,NULL);
			y--;
		}
	}

	//try to move down
	else if (direction == 1)
	{
		if ((y < worldSize - 1)&& (world->getAt(x,y+1) == NULL))
		{
			// move to new spot
			world->setAt(x,y+1, world->getAt(x,y));

			// and set current spot to empty 

			world->setAt(x,y,NULL);
			y++;
		}
	}

	// try to move left
	else if (direction == 2)
	{
		if ((x>0)&& (world->getAt(x-1,y) == NULL))
		{
			// move to new spot
			world->setAt(x-1,y, world->getAt(x,y));

			//and set the current spot to empty

			world->setAt(x,y,NULL);
			x--;
		}
	}

	// try to move right

	else
	{
		if ((x < worldSize - 1 )&& (world->getAt(x+1,y) == NULL))
		{
			//Move to new spot
			world->setAt(x+1,y, world->getAt(x,y));

			// and set current spot to empty
			world->setAt(x,y,NULL);
			x++;
		}
	}
	// end of movement options

	//and now increment starveFlag because it did'nt eat on this turn
	starveFlag++;// to check it later 

	


}


int Doodlebug::getType()
{
	return doodleBug;

}


// define breed function for doodle bug just like ants  but here it will check for 8 times

void Doodlebug::breed()
{
	breedFlag++;
	if (breedFlag == doodleBreed)
	{
		breedFlag = 0;
		//try to make new ant either up,left,down,or right
		if ((y>0) && (world->getAt(x,y-1) == NULL))
		{
			Doodlebug *newDoolde = new Doodlebug(world,x,y-1);
		}
		else if ((y < worldSize-1) && (world->getAt(x,y+1) == NULL))
		{
			Doodlebug *newDoolde = new  Doodlebug(world,x,y+1);
		}
		// end for y states now lets do it for x states
		else if ((x>0) && (world->getAt(x-1,y) == NULL))
		{
			Doodlebug *newDoolde = new Doodlebug(world,x-1,y);
		}
		else 
		{
			Doodlebug *newDoolde = new  Doodlebug(world,x+1,y);
		}
		// end for x states

	}
}


// starve function definition

bool Doodlebug::starve()
{
	//starve if no food eaten in last turn
	if (starveFlag > doodleStarve)
	{
		return true;
	}
	else
		return false;
} 

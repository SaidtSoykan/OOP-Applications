#include <iostream>
#ifndef _H
#define _H
using namespace std;
class Robot {
	private:
		static int unqID;
		string RobotName;
		const string RobotType;
		float speed; // make this random
		int durability; // durability in terms of game turn, make this random
		const int manufactureCost; // constant for specific type
		float maintenanceCost;
		bool canMove;
	
	public:
		Robot(const string type,float speed, int durability, const int manufactureCost, float maintenanceCost);
		
		Robot();
		
		
		void operator= (Robot&);
		void showInfo() const;

		string getName() const;
		void setName(string name);

		string getType() const;

		void setCanMove(bool canMove);
		bool getCanMove()const;

		int getDurability() const;
		void setDurability(int durability);

		float getSpeed() const;	
		void setSpeed(float speed);

		int getManufactureCost() const;

		float getMaintenanceCost() const; 
		void setMaintenanceCost(float maintenanceCost);                
}; 

class Explorer : public Robot{
	private:
		static float totalExploredArea;
		static int totalNumberOfSeleniumArea;
		float exploredArea;
		bool detectedSelenium;
		
		friend class Miner;
		friend class CommandCenter;
	public:
		Explorer(const string type, const float speed, int durability);
		Explorer();
		Explorer(Explorer &RobotObj);
		void operator= (Explorer&);
		
		
		
		void setDetectedSelenium(bool detect);
		bool getDetectedSelenium() const;
		float getExploredArea() const;
		void setExploredArea(float exploredArea);
		bool move();
		void explore(); 
		void showInfo() const;
};

class Miner : public Robot{
	private:
		static int totalGatheredSelenium;
		int gatheredSelenium;
		
		friend class CommandCenter;
		
	public:
		Miner(const string type, const float speed, int durability);
		Miner();
		Miner(Miner &RobotObj);
		
		void operator= (Miner&);

		void setGatheredSelenium(int gatheredSelenium);
		int getGatheredSelenium() const;
		void mine(); 
		bool move();
		
		void showInfo() const;


};


#endif
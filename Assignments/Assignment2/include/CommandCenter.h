#include <iostream>
#include "Robot.h"
using namespace std;

class Crew{
	private:
		int maxExplorers;
		int maxMiners;
		int crewManufactureCost;
		float crewMaintenanceCost;
		int explorerCrewSize;
		int minerCrewSize;
		Explorer **ExplorerCrew;
		Miner **MinerCrew;
		friend class CommandCenter;
	public:
		Crew(int maxExplorers,int maxMiners,int explorerCrewSize, int minerCrewSize);
		~Crew();
		Explorer** getExplorers();
		Miner** getMiners();
		int getMinerCrewSize();
		int getExplorerCrewSize();
		int getCrewManufactureCost();
		float getCrewMaintenanceCost();
		void setCrewMaintenanceCost(float maintenanceCost);
		void updateDurability();
		void showInfo();
		void initMovement();
		Robot* manufactureRobot(string robotType="NaN");
		void operator+= (Robot*);
		
		void operator-= (string robotName);
		
		inline int seqSearch(string name){
			int index = -1;
			string namePrefix = name.substr(0,3);
			if ((namePrefix == "exp")){
				for (int i = 0; i < this->explorerCrewSize; i++)
				{
					if (this->ExplorerCrew[i]->getName() == name){
						
						index = i;
					}
				}

			}
			else if ((namePrefix == "mnr")){
				for (int i = 0; i < this->minerCrewSize; i++)
				{
					if (this->MinerCrew[i]->getName() == name){
						
						index = i;
					}
				}

			}
			else {
				return -1;
			}

			return index;
		}
};

class CommandCenter{
	private:
		const int neededSelenium;
		const float searchArea;
		const int seleniumWorth;
		int turnCount;
		float profit;
		
	public:
		CommandCenter(int targetSeleniumAmount, float searchArea, int seleniumWorth);
		bool isGameEnded() const;
		void calculateProfit(Crew &crew);
		
		void operator++();
		void showInfo(); 


};




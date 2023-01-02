#include <iostream>
#include "Robot.h"
#include "CommandCenter.h"
using namespace std;

void commandMenu(){
	
	cout<<"1. Search for selenium"<<endl;
	cout<<"2. Dig out seleniums"<<endl;
	cout<<"3. Manufacture a Robot"<<endl;
	cout<<"4. Disassemble a Robot"<<endl;
	cout<<"5. Show team information"<<endl;
	cout<<"6. Show stats"<<endl;
	cout<<"7. End Turn"<<endl;
	cout<<"8. Exit Game"<<endl;
	cout<<"Choice:"<<endl;
}


int main(){
	srand(99);
	/*
	Robot* robotPointer = new Explorer("asd","explorer",2,2,2000);
	cout<<robotPointer->getName()<<endl;*/
	/*
	const int n = 2;
	Robot** pointer_arr = new Robot*[n];
	pointer_arr[0] = new Explorer("asd","explorer",2,2,2000);
	pointer_arr[1] = new Explorer("asd2","miner",2,4,2200);
	
	pointer_arr[0]->showInfo();
	pointer_arr[1]->showInfo();
	((Explorer*)pointer_arr[0])->explore();
	cout<<((Explorer*)pointer_arr[0])->getDetectedSelenium()<<endl;
	*/
	bool manualExit = false;
	bool endTurn = false;
	int crewMaxExplorers;
	int crewMaxMiners;
	int explorerCrewSize;
	int minerCrewSize;
	const int seleniumWorth = 30;
	const int seleniumAim = 800;
	const int exploreArea = 13500;
	cout<<"Welcome to the Command Station Chief!"<<endl;
	cout<<"Prepare your Robot Crew and start mining!"<<endl;
	cout<<"Throughout the game you can expand your crew."<<endl;
	cout<<"What should be your maximum explorer crew size (1-5)?"<<endl; //(1-10)?
	cin>>crewMaxExplorers;
	cout<<"What should be your maximum miner crew size (1-5)?"<<endl; //(1-10)?
	cin>>crewMaxMiners;
	cout<<"How many explorers will you manufacture now?"<<endl;
	cin>>explorerCrewSize;
	cout<<"How many miners will you manufacture now?"<<endl;
	cin>>minerCrewSize;
	Crew Crew(crewMaxExplorers,crewMaxMiners,explorerCrewSize,minerCrewSize);
	Crew.showInfo();
	
	CommandCenter commandCenter(seleniumAim,exploreArea,seleniumWorth); // a footbal field is apprx 7000 square meters.
	
	while (true)
	{
		// each turn check if the game can be finished or not.
		if(endTurn){
			if (commandCenter.isGameEnded()){
				break;
			}
			endTurn=false;
		}
		if(manualExit){
			cout<<"Farewell Chief!";
			break;
		}
		int decision;
		commandMenu();
		cin>>decision;
		string robotToBeRemoved = "NaN";
		switch (decision)
		{
		case 1:
			for (int i = 0; i < Crew.getExplorerCrewSize(); i++)
			{ 
				bool isMoving = Crew.getExplorers()[i]->move();
				if (isMoving){
					Crew.getExplorers()[i]->explore();
					Crew.getExplorers()[i]->setCanMove(false);
					Crew.setCrewMaintenanceCost(Crew.getCrewMaintenanceCost()+Crew.getExplorers()[i]->getMaintenanceCost());
				}
				else{
					cout<<Crew.getExplorers()[i]->getName()<<" can't take an action Chief!"<<endl;
				}
				
				
			}
			commandCenter.showInfo();
			break;
		case 2:
			for (int i = 0; i < Crew.getMinerCrewSize(); i++)
			{ 
				
				bool isMoving = Crew.getMiners()[i]->move();
				if (isMoving){
					Crew.getMiners()[i]->mine();
					Crew.getMiners()[i]->setCanMove(false);
					Crew.setCrewMaintenanceCost(Crew.getCrewMaintenanceCost()+Crew.getMiners()[i]->getMaintenanceCost());
					
				}
				else{
					cout<<Crew.getMiners()[i]->getName()<<" can't take an action Chief!"<<endl;
				}
				
				
			}
			commandCenter.showInfo();
			break;
		case 3:
			Crew+=Crew.manufactureRobot();
			Crew.showInfo();
			break;
		case 4:
			
			cout<<"Enter the name of the robot that you want to disassemble"<<endl;
			cin>>robotToBeRemoved;
			Crew-=robotToBeRemoved;
			Crew.showInfo();
			break;
		case 5:
			Crew.showInfo();
			break;
		case 6:
			commandCenter.showInfo();
			break;
		case 7:
			cout<<"Turn ends..."<<endl;
			endTurn = true; // turn is ended.
			Crew.initMovement(); // set your robots' canMove to true
			Crew.updateDurability(); // If durabilities are different than 0, decrement by 1. Then, if any robot's durabilit is
									// equal to 0, set their canMove to false and remove them from the crew.
									// if it is not the single robot in its crew. This control should be done
									// in -= operator overloader function. If crew has single robot, remove operation should not be done.
									// To acquire mines in next turns, you should manufacture new robots. At the end of the next turn, those 
									// robots which could not be removed would be removed since their durability is 0 and the crew 
									// has multiple robots. Ensure that, when manufacturing, you add both explorer and miner.
			commandCenter.calculateProfit(Crew); // calculate profit
			++commandCenter; // increment turn count;
			cout<<"Your robots are ready!"<<endl;
			break;
		case 8:
			manualExit = true;
			break;
		default:
			break;
		}
	}
	
	
	
	/*
    Point pointA(new string("A"));
	Point pointB(new string("B"));
	cout<<"Name: "<<*pointA.getName()<<endl;
	pointA.setCoord(220,130);
	pointA.print();
	cout<<"pointA, X:"<<*pointA.getX()<<endl;
	cout<<"pointA, Y:"<<*pointA.getY()<<endl;
	cout<<"Is pointA at origin? "<<pointA.isAtOrigin()<<endl;
	cout<<"Is pointB at origin? "<<pointB.isAtOrigin()<<endl;
	pointB.print();
	pointB.setCoord(100,50);
	cout<<"pointB, X:"<<*pointB.getX()<<endl;
	cout<<"pointB, Y:"<<*pointB.getY()<<endl;
	cout<<pointA-pointB<<endl;
	cout<<"a"<<endl;
	cout<<"Copy Constructor"<<endl;
	
	Point pointNew(pointB); // same as Point pointNew2 = pointB;
	cout<<*(pointNew.getX())<<","<<*(pointNew.getY())<<endl;
	cout<<*(pointB.getX())<<","<<*(pointB.getY())<<endl;
	pointB.setCoord(10,5);
	cout<<*(pointNew.getX())<<","<<*(pointNew.getY())<<endl;
	cout<<*pointB.getX()<<","<<*pointB.getY()<<endl;

	cout<<"Shallow copy"<<endl;
	Point pointNew2(new string ("new2"));
	pointNew2 = pointB;
	cout<<*pointNew2.getX()<<","<<*pointNew2.getY()<<endl;
	cout<<*pointB.getX()<<","<<*pointB.getY()<<endl;
	pointNew2.setCoord(222,321);
	cout<<*pointNew2.getX()<<","<<*pointNew2.getY()<<endl;
	cout<<*pointB.getX()<<","<<*pointB.getY()<<endl;
	*/
	return 0;

}
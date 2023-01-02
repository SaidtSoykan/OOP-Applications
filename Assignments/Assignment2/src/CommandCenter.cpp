#include "CommandCenter.h"
#include "Robot.h"
#include <iostream>
using namespace std;
/*
****************
BEGIN: CREW CLASS FUNCTION DECLARATIONS 
****************
*/
Crew::Crew(int maxExplorers, int maxMiners, int expCrewSize, int mnrCrewSize):maxExplorers(maxExplorers),maxMiners(maxMiners),explorerCrewSize(expCrewSize), minerCrewSize(mnrCrewSize){
	if (maxExplorers<0 || maxExplorers>5){
		this->maxExplorers=2;
	}
	else{
		this->maxExplorers=maxExplorers;
	}
	if (maxMiners<0 || maxMiners>5){
		this->maxMiners=2;
	}
	else{
		this->maxMiners=maxMiners;
	}
    // crewsize check
    if (expCrewSize<0 || expCrewSize>this->maxExplorers){
		this->explorerCrewSize=this->maxExplorers;
	}
	else{
		this->explorerCrewSize=expCrewSize;
	}
	if (maxMiners<0 || mnrCrewSize>this->maxMiners){
		this->minerCrewSize=this->maxMiners;
	}
	else{
		this->minerCrewSize=mnrCrewSize;
	}

	this->crewManufactureCost=0;
	this->crewMaintenanceCost=0;
	this->ExplorerCrew = new Explorer*[this->maxExplorers];
	this->MinerCrew = new Miner*[this->maxMiners];

	for (int i = 0; i < this->explorerCrewSize; i++)
	{
		this->ExplorerCrew[i] =  (Explorer*)manufactureRobot("explorer"); // ensure that return type is explorer by casting
		
		this->crewManufactureCost+=ExplorerCrew[i]->getManufactureCost();

	}
	for (int i = 0; i < this->minerCrewSize; i++)
	{
		
		this->MinerCrew[i] = (Miner*)manufactureRobot("miner"); // ensure that return type is explorer by casting
		
		this->crewManufactureCost+=MinerCrew[i]->getManufactureCost();
       

	}
	
}
Robot* Crew::manufactureRobot(string robotType){
	string robotPrefix;
	float robotSpeed;
	int robotDurability;
	while (robotType!="explorer" && robotType!="miner"){
	cout<<"Type:";
	cin>>robotType;
	}
	
	
	robotDurability = rand()%5 + 1;

	if (robotType=="explorer") {
		
		float low = 1.5;
		float high = 2.5;
		robotSpeed =  low + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(high-low)));

		return new Explorer(robotType,robotSpeed,robotDurability);	
	}
	else{
		
		float low = 1.0;
		float high = 1.5;
		robotSpeed =  low + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(high-low)));
		
		return new Miner(robotType,robotSpeed,robotDurability);
	}
}
Crew::~Crew(){
	for (int i = 0; i < this->explorerCrewSize; i++)
	{
		delete ExplorerCrew[i];
		
	}
	for (int i = 0; i < this->minerCrewSize; i++)
	{
		delete MinerCrew[i];
		
	}
	delete [] ExplorerCrew;
	delete [] MinerCrew;
 }
Explorer** Crew::getExplorers(){
	
	return ExplorerCrew;
}
Miner** Crew::getMiners(){
	
	return MinerCrew;
}
int Crew::getExplorerCrewSize(){
	return explorerCrewSize;
}
int Crew::getMinerCrewSize(){
	return minerCrewSize;
}
int Crew::getCrewManufactureCost(){
	return crewManufactureCost;
}

float Crew::getCrewMaintenanceCost(){
	return crewMaintenanceCost;
}
void Crew::setCrewMaintenanceCost(float maintenanceCost){
	this->crewMaintenanceCost = maintenanceCost;
}
void Crew::showInfo(){
    cout<<"explorerCrew Size:"<<this->explorerCrewSize<<endl;
    cout<<"minerCrew Size:"<<this->minerCrewSize<<endl;
	for (int i = 0; i < this->explorerCrewSize; i++)
	{
		this->ExplorerCrew[i]->showInfo();
		
	}
	for (int i = 0; i < this->minerCrewSize; i++)
	{
		this->MinerCrew[i]->showInfo();
		
	}
	cout<<"Total manufacture cost: "<< this->crewManufactureCost<<endl;
	cout<<"Total maintenance cost: "<< this->crewMaintenanceCost<<endl;
}
void Crew::initMovement(){
	for (int i = 0; i < this->explorerCrewSize; i++)
	{
		this->ExplorerCrew[i]->setCanMove(true);
		
	}
	for (int i = 0; i < this->minerCrewSize; i++)
	{
		this->MinerCrew[i]->setCanMove(true);
		
	}
}
void Crew::operator+=(Robot *robot) {
	if (robot->getType() == "explorer" && this->explorerCrewSize != maxExplorers){
        robot->setCanMove(false); // spend this turn for manufacturing
		this->ExplorerCrew[explorerCrewSize] = (Explorer*)robot;
		this->explorerCrewSize = explorerCrewSize+1;
		this->crewManufactureCost+=ExplorerCrew[explorerCrewSize-1]->getManufactureCost();
	}
	else if (robot->getType() == "miner" && this->minerCrewSize != maxMiners){
        robot->setCanMove(false); // spend this turn for manufacturing
		this->MinerCrew[minerCrewSize] = (Miner*)robot;
		this->minerCrewSize = minerCrewSize+1;
		this->crewManufactureCost+=MinerCrew[minerCrewSize-1]->getManufactureCost();

	}
	else{
        delete robot;
		cout<<"This robot cannot be added, check maximum size of the crew"<<endl;
	}
	
}
void Crew::operator-=(string name) {
	int index = seqSearch(name);
	string namePrefix = name.substr(0,3);
	if ((namePrefix == "exp")){
	cout<<this->ExplorerCrew[index]->getName()<<": Goodbye"<<endl;

	
	for (int j = index; j < explorerCrewSize-1; j++){
		*(this->ExplorerCrew[j]) = *(this->ExplorerCrew[j+1]);
	}
	;
    if (explorerCrewSize!=1){
	    delete ExplorerCrew[explorerCrewSize-1];
        this->explorerCrewSize-=1;

    }
	
	
	}
	else if ((namePrefix == "mnr")){
	cout<<this->MinerCrew[index]->getName()<<": Goodbye"<<endl;

	
	for (int j = index; j < minerCrewSize-1; j++){
		*(this->MinerCrew[j]) = *(this->MinerCrew[j+1]);
	}
	
    if (minerCrewSize!=1){
	    delete MinerCrew[minerCrewSize-1];
        this->minerCrewSize-=1;
        

    }
	
	
	}
	
		
	
	
}



void Crew::updateDurability(){
	cout<<"Explorer durability is being updated"<<endl;
	for (int i = 0; i < this->explorerCrewSize; i++)
	{
		if (ExplorerCrew[i]->getDurability() != 0){
			ExplorerCrew[i]->setDurability(ExplorerCrew[i]->getDurability()-1);
		}
		if (ExplorerCrew[i]->getDurability() == 0){
			ExplorerCrew[i]->setCanMove(false);
			cout<<ExplorerCrew[i]->getName()<<"'s durability=0"<<endl;
			*this-=ExplorerCrew[i]->getName();
			
		}
	}
	cout<<"Miner durability is being updated"<<endl;
	for (int i = 0; i < this->minerCrewSize; i++)
	{
		if (MinerCrew[i]->getDurability() != 0){
			MinerCrew[i]->setDurability(MinerCrew[i]->getDurability()-1);
		}
		if (MinerCrew[i]->getDurability() == 0){
			MinerCrew[i]->setCanMove(false);
			cout<<MinerCrew[i]->getName()<<"'s durability=0"<<endl;
			*this-=MinerCrew[i]->getName();
			
		}
	}


	
}
/*
****************
END: CREW CLASS FUNCTION DECLARATIONS 
****************
*/
/*
****************
BEGIN: COMMANDCENTER CLASS FUNCTION DECLARATIONS 
****************
*/
CommandCenter::CommandCenter(int targetSeleniumAmount, float searchArea, int seleniumWorth) : neededSelenium(targetSeleniumAmount), searchArea(searchArea), seleniumWorth(seleniumWorth){
	turnCount=1;
	profit = 0;
    totalCrewMaintenanceCost = 0;
}
void CommandCenter::showInfo(){
	cout<<"Current turn: "<<this->turnCount<<endl;
	cout<<"Aim: "<<this->neededSelenium<<" selenium."<<endl;
	cout<<"Collected: "<<Miner::totalGatheredSelenium<<endl;
	cout<<"Total Search Area: "<<this->searchArea<<endl;
	cout<<"Explored Area: "<<Explorer::totalExploredArea<<endl;
	cout<<"Currently, there are "<<Explorer::totalNumberOfSeleniumArea<<" area/s that include selenium."<<endl;
	if(Explorer::totalNumberOfSeleniumArea>0){
		cout<<"Mine these areas if miners have not finished their turn! If you cannot cope with mining, you can always add new miners!"<<endl;
	}

}
void CommandCenter::calculateProfit(Crew &crew) {
	int seleniumRevenue = Miner::totalGatheredSelenium*seleniumWorth;
    //totalCrewMaintenanceCost += crew.getCrewMaintenanceCost();
	float expenses = crew.getCrewMaintenanceCost() + crew.getCrewManufactureCost();
	this->profit = seleniumRevenue - expenses;
	cout<<"Profit:"<<this->profit<<endl;
	cout<<"Expenses:"<<expenses<<endl;
	cout<<"Selenium Revenue:"<<seleniumRevenue<<endl;

}
bool CommandCenter::isGameEnded() const{
	if (Explorer::totalExploredArea>=searchArea){
		cout<<"Area has been fully explored."<<endl;
		cout<<"Aim: "<<this->neededSelenium<<" selenium."<<endl;
		cout<<"Collected: "<<Miner::totalGatheredSelenium<<endl;
		if (Miner::totalGatheredSelenium>=this->neededSelenium && profit>0){
			cout<<"Congrats!"<<endl;

		}
		else {
			cout<<"Mission Failed!"<<endl;
			
		}
		return 1;
	}
	else{
		return 0;
	}
}
void CommandCenter::operator++(){
	turnCount++;
}
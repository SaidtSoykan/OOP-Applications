#include <iostream>
#include <cmath>
using namespace std;
#include "Robot.h"



/*
****************
BEGIN: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/
int Robot::unqID = 1;

Robot::Robot(const string type, float speed, int durability, const int manufactureCost,float maintenanceCost)
:RobotType(type),speed(speed),durability(durability),manufactureCost(manufactureCost),maintenanceCost(maintenanceCost) {
	this->canMove=true;
	string type_prefix = "NaN";
	if (type=="explorer"){
		type_prefix = "exp";
	}
	else if (type == "miner"){
		type_prefix = "mnr";
	}
	else{
		cerr<<"Type cannot be different than explorer and miner"<<endl;
	}
	type_prefix += '-';
	type_prefix += to_string(unqID);
	this->RobotName = type_prefix;
	Robot::unqID++;
}



void Robot::showInfo() const{
	cout<<"Name: "<<this->getName()<<endl;
	cout<<"Type: "<<this->getType()<<endl;
	cout<<"Speed: "<<this->getSpeed()<<endl;
	cout<<"Durability: "<<this->getDurability()<<endl;
	cout<<"ManufactureCost: "<<this->getManufactureCost()<<endl;
	cout<<"MaintenanceCost: "<<this->getMaintenanceCost()<<endl;
	cout<<"Can Move: "<<this->getCanMove()<<endl;

}

void Robot::operator=(Robot &RobotObj){
	this->setName(RobotObj.getName());
	this->setMaintenanceCost(RobotObj.getMaintenanceCost());
	this->setSpeed(RobotObj.getSpeed());
	this->setDurability(RobotObj.getDurability());
	
}


/*
****************
GETTER FUNCTIONS
****************
*/
string Robot::getName()const {
	return this->RobotName;
}
void Robot::setName(string name){
	this->RobotName = name;
}
string Robot::getType()const {
	return this->RobotType;
}
int Robot::getDurability()const {
	return this->durability;
}
void Robot::setDurability(int durability){
	this->durability = durability;
}
float Robot::getSpeed()const {
	return this->speed;
}
void Robot::setSpeed(float speed){
	this->speed =speed;
}
int Robot::getManufactureCost()const {
	return this->manufactureCost;
}
float Robot::getMaintenanceCost()const {
	return this->maintenanceCost;
}
void Robot::setMaintenanceCost(float maintenanceCost){
	this->maintenanceCost=maintenanceCost;
}
void Robot::setCanMove(	bool canMove){
	this->canMove=canMove;
}
bool Robot::getCanMove()const{
	return this->canMove;
}

/*
****************
END: ROBOT CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/
Explorer::Explorer()
: Robot("explorer",1.5,2,3000,280){
	this->detectedSelenium=0;
	this->exploredArea=0;
}
Explorer::Explorer(const string type, const float speed, int durability)
: Robot(type,speed,durability,3000,(450/speed)){
	this->detectedSelenium=0;
	this->exploredArea=0;
}
/*
================
BEGIN: STATIC VARIABLES
================
*/
float Explorer::totalExploredArea=0;
int Explorer::totalNumberOfSeleniumArea=0;
/*
================
END: STATIC VARIABLES
================
*/
Explorer::Explorer(Explorer &RobotObj): Robot(RobotObj.getType(), RobotObj.getSpeed(),RobotObj.getDurability(),RobotObj.getManufactureCost(),RobotObj.getMaintenanceCost()){
	this->detectedSelenium=0;
	this->exploredArea=0;
}
void Explorer::operator=(Explorer &RobotObj){
	this->setName(RobotObj.getName());
	this->setCanMove(RobotObj.getCanMove());
	this->setMaintenanceCost(RobotObj.getMaintenanceCost());
	this->setSpeed(RobotObj.getSpeed());
	this->setDurability(RobotObj.getDurability());
	this->setDetectedSelenium(RobotObj.getDetectedSelenium());
	this->setExploredArea(RobotObj.getExploredArea());

}

bool Explorer::getDetectedSelenium()const {
	return this->detectedSelenium;
}
void Explorer::setDetectedSelenium(bool detect){
	this->detectedSelenium=detect;

}
void Explorer::explore() {
	
	int randNum = rand()%101;
	if (randNum>=40){
		this->setDetectedSelenium(1);
		totalNumberOfSeleniumArea++;
		totalExploredArea+=1500;
		this->exploredArea=1500;
	}
	else{
		this->setDetectedSelenium(0);
		totalExploredArea+=1500;
		this->exploredArea=1500;
	}
}
float Explorer::getExploredArea() const{
	return this->exploredArea;
}
void Explorer::setExploredArea(float exploredArea){
	this->exploredArea = exploredArea;
}

bool Explorer::move(){
	/*
	Move the robot to the area if there is selenium.
	*/
	if (this->getCanMove()){
		return true;
	}
	else{
		return false;
	}

}

void Explorer::showInfo() const{
	cout<<"Name: "<<this->getName()<<endl;
	cout<<"Type: "<<this->getType()<<endl;
	cout<<"Speed: "<<this->getSpeed()<<endl;
	cout<<"Durability: "<<this->getDurability()<<endl;
	cout<<"ManufactureCost: "<<this->getManufactureCost()<<endl;
	cout<<"MaintenanceCost: "<<this->getMaintenanceCost()<<endl;
	cout<<"Can Move: "<<this->getCanMove()<<endl;
	cout<<"explored area: "<<this->getExploredArea()<<endl;
}
/*
****************
END: EXPLORER CLASS FUNCTION DECLARATIONS 
****************
*/

/*
****************
BEGIN: MINER CLASS FUNCTION DECLARATIONS 
****************
*/
Miner::Miner()
: Robot("miner",1,3,5000,750){
	this->gatheredSelenium=0;
}
Miner::Miner(const string type, const float speed, int durability)
: Robot(type,speed,durability,5000,(750/speed)){
	this->gatheredSelenium=0;
}
Miner::Miner(Miner &RobotObj): Robot(RobotObj.getType(), RobotObj.getSpeed(),RobotObj.getDurability(),RobotObj.getManufactureCost(),RobotObj.getMaintenanceCost()){
	this->gatheredSelenium=0;
}


void Miner::operator=(Miner &RobotObj){
	this->setName(RobotObj.getName());
	this->setMaintenanceCost(RobotObj.getMaintenanceCost());
	this->setSpeed(RobotObj.getSpeed());
	this->setDurability(RobotObj.getDurability());
	this->setGatheredSelenium(RobotObj.getGatheredSelenium());


}
/*
================
BEGIN: STATIC VARIABLES
================
*/

int Miner::totalGatheredSelenium = 0;
/*
================
END: STATIC VARIABLES
================
*/
void Miner::setGatheredSelenium(int gatheredSelenium){
	this->gatheredSelenium=gatheredSelenium;
}
int Miner::getGatheredSelenium()const {
	return this->gatheredSelenium;
}

bool Miner::move(){
	/*
	Move the robot to the area if there is selenium.
	*/
	if (Explorer::totalNumberOfSeleniumArea>0 && this->getCanMove()){
		return true;
	}
	else{
		return false;
	}

}
void Miner::mine(){
	int randNum = rand()%91 + 10;
	this->gatheredSelenium = 5*randNum;
	
	Explorer::totalNumberOfSeleniumArea--;
	totalGatheredSelenium += gatheredSelenium;
}
void Miner::showInfo() const{
	cout<<"Name: "<<this->getName()<<endl;
	cout<<"Type: "<<this->getType()<<endl;
	cout<<"Speed: "<<this->getSpeed()<<endl;
	cout<<"Durability: "<<this->getDurability()<<endl;
	cout<<"ManufactureCost: "<<this->getManufactureCost()<<endl;
	cout<<"MaintenanceCost: "<<this->getMaintenanceCost()<<endl;
	cout<<"Can Move: "<<this->getCanMove()<<endl;
	cout<<"# of gathered selenium: "<<this->gatheredSelenium<<endl;	

}
/*
****************
END: MINER CLASS FUNCTION DECLARATIONS 
****************
*/


//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

pokemon::pokemon(){ //Default constructer for pokemon class
    this->name = "";
    this->hpValue = 0;
    this->atkValue = 0;
};

pokemon::pokemon(string name, int atkValue){ //Constructer for pokemon class with given name and atkValue
    this->name = name;
    this->hpValue = 100;
    this->atkValue = atkValue;
};

pokemon::pokemon(pokemon* newPokemon){ //Copy constructer for pokemon class
    this->name = newPokemon->name;
    this->hpValue = newPokemon->hpValue;
    this->atkValue = newPokemon->atkValue;
};

string pokemon::getName() const{ //Get function for pokemon name
    return this->name;
};

int pokemon::getHp() const{ //Get function for pokemon hp
    return this->hpValue;
};

int pokemon::getAtk() const{ //Get function for pokemon atk value
    return this->atkValue;
};

pokedex::pokedex(){ //Default constructer for pokedex class
    this->value = 0;
};

void pokedex::updatePokedex(pokemon* newPokemon){ //Updating pokedex everytime there is a new pokemon
    if(checkIfExist(newPokemon)){ //Checking if the pokemon already discovered
        return;
    }
    this->pokedexArray[this->value] = newPokemon;
    this->value++; 
        
};

void pokedex::printPokedex() const{ //Print function for pokedex
    for(int i = 0; i < this->value; i++){
        cout << pokedexArray[i].getName() << endl;
    }
};

player::player(){ //Default constructer for player class

    this->name = "";
    this->pokemonNumber = 0;
    this->pokeballNumber = 0;
    this->badgeNumber = 0;
    pokemon playerPokemon;
    pokedex playerPokedex;
};

player::player(string newName, pokemon* newPlayerPokemon){ //Constructer for player class with given name and pokemon
    
    this->name = newName;
    this->pokemonNumber = 0;
    this->pokeballNumber = 10;
    this->badgeNumber = 0;
    pokemon playerPokemon(newPlayerPokemon);
    this->playerPokemon = playerPokemon;
};

int player::showPokemonNumber() const{ //Get function for pokemon number
    return this->pokemonNumber;
};

int player::showPokeballNumber() const{ //Get function for pokeball number
    return this->pokeballNumber;
};

int player::showBadgeNumber() const{ //Get function for badge number
    return this->badgeNumber;
};

pokemon player::getPokemon() const{ //Get function for player pokemon 
    return playerPokemon;
};

void player::catchPokemon(){ //Function to increase pokemon number
    this->pokemonNumber++;
    this->pokeballNumber--;
};

void player::battleWon(){ //Function to increase both badge and pokeball number
    this->badgeNumber++;
    this->pokeballNumber += 3;
};

enemy::enemy(){ //Default constructer for enemy class
    this->name = "";
    pokemon enemyPokemon;
};

enemy::enemy(string newName, pokemon* newEnemyPokemon){ //Constructer for enemy class with given name and pokemon
    this->name = newName;
    pokemon enemyPokemon(newEnemyPokemon);
    this->enemyPokemon = enemyPokemon;
};

pokemon enemy::getPokemon() const{ //Get function for enemy pokemon
    return this->enemyPokemon;
};

string enemy::getName() const{ //Get function for enemy name
    return this->name;
};
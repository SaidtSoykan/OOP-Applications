//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

class pokemon{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
        pokemon();
        pokemon(string, int);
        pokemon(pokemon*);
        string getName() const;
        int getHp() const;
        int getAtk() const;
        void printPokemon() const{ //Print function for pokemon class
            cout<<"Name: "<<this->name<<endl;
            cout<<"HP: "<<this->hpValue<<endl;
            cout<<"Attack: "<<this->atkValue<<endl;
            };
};

class pokedex{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        pokemon pokedexArray[100];
        int value;
    public:
        pokedex();
        bool checkIfExist(pokemon* newPokemon){ //Check function to prevent dublicates
            for(int i=0; i<this->value; i++){
                if(this->pokedexArray[i].getName() == newPokemon->getName()){
                    return true;
                }
            }
            return false;
        };
        void updatePokedex(pokemon*);
        void printPokedex () const;
};

class player{
    private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        pokedex playerPokedex;
        player();
        player(string, pokemon*);
        int showPokemonNumber() const;
        int showPokeballNumber() const;
        int showBadgeNumber() const;
        pokemon getPokemon() const;
        void catchPokemon();
        void battleWon();
};

class enemy{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        pokemon enemyPokemon;
    public:
        enemy();
        enemy(string, pokemon*);
        pokemon getPokemon() const;
        string getName() const;
};

#endif
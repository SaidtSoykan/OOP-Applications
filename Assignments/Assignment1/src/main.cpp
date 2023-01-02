//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable its but here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable its but here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
string* readEnemyNames(const char* argv){
    string* enemyNames;
    string name;
    int nameCounter = 0;
    int total;
    bool firstTime = true;
    
    ifstream readEnemyNames;
    readEnemyNames.open(argv);
    
    if(readEnemyNames.is_open()){
        while(!readEnemyNames.eof()){
            if(firstTime){     
                readEnemyNames >> total;
                enemyNames = new string[total];
                firstTime = false;
                continue;
            }

            readEnemyNames >> name; 
            enemyNames[nameCounter] = name;
            nameCounter++;
        }
    }
    readEnemyNames.close();
    return enemyNames;
};
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
string* readPokemonNames(const char* argv){
    string* pokemonNames;
    string name;
    int nameCounter = 0;
    int total;
    bool firstTime = true;
    
    ifstream readPokemonNames;
    readPokemonNames.open(argv);
    
    if(readPokemonNames.is_open()){
        while(!readPokemonNames.eof()){
            if(firstTime){     
                readPokemonNames >> total;
                pokemonNames = new string[total];
                firstTime = false;
                continue;
            }

            readPokemonNames >> name; 
            pokemonNames[nameCounter] = name;
            nameCounter++;
        }
    }
    readPokemonNames.close();
    return pokemonNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    while(true){ //Selecting pokemon and creating both pokemon and player
        if(pokemonChoice == 1){ 
            pokemon newPokemon("Bulbasaur", PLAYER_POKEMON_ATTACK);
            player newPlayer(playerName, &newPokemon);
            return newPlayer;
        }
        else if(pokemonChoice == 2){
            pokemon newPokemon("Charmender", PLAYER_POKEMON_ATTACK);
            player newPlayer(playerName, &newPokemon);
            return newPlayer;
        }
        else if(pokemonChoice == 3){
            pokemon newPokemon("Squirtle", PLAYER_POKEMON_ATTACK);
            player newPlayer(playerName, &newPokemon);
            return newPlayer;
        }
        cout << "Please enter a valid number!!!" << endl;
    }
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs" << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
    pokemon newPokemon(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK);
    POK_COUNTER++;
    string enemyName = enemyNames[NAME_COUNTER]; //Selecting next enemy name
    enemy newEnemy(enemyName, &newPokemon); //Creating new enemy
    NAME_COUNTER++;
    newPlayer->playerPokedex.updatePokedex(&newPokemon);

    //Getting values for easy acces
    int playerPokemonHp = newPlayer->getPokemon().getHp();
    int playerPokemonAtk = newPlayer->getPokemon().getAtk();
    int enemyPokemonHp = newEnemy.getPokemon().getHp();
    int enemyPokemonAtk = newEnemy.getPokemon().getAtk();
    int choice;

    cout << endl;
    cout << "You encounter with " << enemyName << " and his/hers pokemon " << newEnemy.getPokemon().getName()<< endl;
    cout << newEnemy.getPokemon().getName() << " Health: " << enemyPokemonHp << " Attack: " << enemyPokemonAtk << endl;
    
    while(true){ //Fighting Menu
        cout << endl;
        cout << "1- Fight" << endl;
        cout << "2- Runaway" << endl;
        cout << "Choice: ";
        cin >> choice;

        if(choice == 1){ //Fighting option
            playerPokemonHp = playerPokemonHp - enemyPokemonAtk;
            enemyPokemonHp = enemyPokemonHp - playerPokemonAtk;
            cout << "Your Pokemons Healt: " <<  playerPokemonHp << endl;
            cout << enemyName <<" Pokemons Healt: " <<  enemyPokemonHp << endl;
            if(enemyPokemonHp == 0 || enemyPokemonHp < 0){ //If enemy pokemon healt is 0 or less
                cout << "You Won!" <<endl;
                newPlayer->battleWon();
                break;
            }
        }
        else if(choice == 2){ //To runaway
            break;
        }
        else{
            cout << "Please enter a valid number!!!" << endl;
        }
    }
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    
    pokemon newPokemon(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK);
    POK_COUNTER++;
    newPlayer->playerPokedex.updatePokedex(&newPokemon); //Creating a new pokemon

    int choice;
    cout << endl;
    cout << "You encounter with " << newPokemon.getName() << " Health: " << newPokemon.getHp() << " Attack: " << newPokemon.getAtk() << endl;
    while(true){ //Catch Menu
        cout << endl;
        cout << "1- Catch" << endl;
        cout << "2- Runaway" << endl;
        cout << "Choice: ";
        cin >> choice;
        if(choice == 1){ //Catching the pokemon 
            cout << "You catch " << newPokemon.getName() << endl;
            newPlayer->catchPokemon();
            break;
        }
        else if(choice == 2){ //To runaway
            break;
        }
        else{
            cout << "Please enter a valid number!!!" << endl;
        }
    }
};
//--------------------------------------------//

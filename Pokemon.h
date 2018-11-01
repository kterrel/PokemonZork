#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>

using namespace std;

class Pokemon { // No subclasses, just one basic attack, at least for now.

	friend class Character; // So bag contents can modify pokemon health

private:
	int pokedex;
	string type;
	string name; //this is which pokemon it is, e.g. Squirtle.
	int health; // health cap
	int currentHealth;
	int attack;
	int dodge; //chance to dodge out of 100%. higher for lower health pokemon. Does not increase with level.
	int level; //currently no level cap, i'll fix that.
	int experience; //experience per level starts at 50 and increases by 10 per level.
	int choice; //DONT FORGET TO DECLARE YOUR VARIABLES. 
	static string pokeMen[79][5];//this is an array containing the names of all the pokemen in indexes 0-3, and type in index 4. Eventually it will be [79][5]
public:
	Pokemon();
	Pokemon(int); //creates randomized pokemon with stats/evolution based on level
	Pokemon(int, int);
	string getName();
	string getType();
	string getPokedexEntry(int, int);
	int getHealth();
	int getCurrentHealth();
	int getAttack();
	int getDodge();
	int getLevel();
	int getExperience();
	void giveExperience(int); //handles leveling up, but doesn't print anything right now
	void changeCurrentHealth(int); //healthChange is how much to ADD to currentHealth
};

class Character {

	friend class Explore;
	friend class Battle;						//Needed in explore function, wanted to limit access to 
												//all other classes
private:
	
	string name;
	int gender;
	Pokemon party[6];
	Pokemon* currentPokemon;						//The current pokemon the player holds.
	
	int money;
	int pokeBalls;
	int potions;

	int xPosition;								//Needed in explore function
	int yPosition;
	
	int badges;									// increment this as gyms beaten 
public:
	Character();
	Character(std::string);						// create accessors for the items
	Character(std::string, int);
	string getName();
	Pokemon* getPokemon(int);				// takes number 0-5 of desired Pokemon in party
	Pokemon *getParty();
	Pokemon* getCurrentPokemon();				//For getting the currentPokemon the player has.
	Pokemon setCurrentPokemon(int);			//For setting up the currentPokemon. 
	void setCurrentPokemon(Pokemon*);
	
	int getX();
	int getY();

	void usePotion(Pokemon*);
	bool usePokeBall(Pokemon*);
	bool spendMoney(int);
	void forfeitCash(int);
	void addPotion();
	void addPokeBall();
	void addMoney(int);
	int getPotionCount();
	int getPokeBallCount();
	int getMoney();
	void setPos();

	void addPokemon(Pokemon);
	void addPokemon(Pokemon*);
	int getBadges();
};

#endif
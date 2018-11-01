#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <time.h>
#include "battle.h"
#include "Pokemon.h"
#define MAP_SIZE 100
#define WALL 1
#define FOREST 2
#define DESERT 3
#define SWAMP 4
#define TOWN 5

using namespace std;

/*
NOTE: main() function should hold a loop that keeps us on the menu
until the game is exited
*/

class GameEngine;

class Town {

	friend class GameEngine;

	// private methods and fields
	int location[2]; // size-two array, store the x and y indices of town's location on map (a 2x2 matrix)
	string name;
	int level;
	Character gymLeader;
public:
	// public methods and fields
	Town();
	Town(string, int); // Initialize a new town, giving it a name
	void visitTown(GameEngine*); // Enter and interact with a town's features
	bool battleGym(GameEngine*); // includes a call to the Battle class
	void healPokemon(Pokemon*);
	void buyItems(GameEngine*); // open store interface
};

class GameEngine {

	friend class Explore;
	friend class Town;

	private:
		int** newmap;
		Town pew;
		Town cer;
		Town fuch;
		Town cel;
		Character mainCharacter;
		void go(string dir);
		void foundTrainer();
		void foundWildPokemon();
		void foundTown();
		void foundItem();

	public:
		//public ones
		GameEngine(); // Constructor, sequence to create character and choose initial pokemon
		void viewPokedex();
		void viewBag(); // calls accessors of player Character to see inventory counts
		void viewTeam();
		void viewMap();
	};

class Explore
{
public:
	void exploreNow(GameEngine*);	//this is just going directly edit main because expoler an game engine are "friends"

private:
	int freeSteps;
	static string people[20];
	bool trySpace(int, int, GameEngine*);
	void foundForest(GameEngine*);
	void foundDesert(GameEngine*);
	void foundSwamp(GameEngine*);
	void foundWall(GameEngine*);
	void foundTown(GameEngine*, int, int);
	void whatHappened(GameEngine*);
};

//int function to make sure responses are taken as ints.
int getInt();
string getString();

#endif
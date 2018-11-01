#include "gameEngine.h"


// Define functions from header
int main() 
{
	GameEngine game;
	cout << "\n\tWhat do you want to do now?\n\t\t1) Explore\n\t\t2) Veiw the Pokedex\n\t\t3) Veiw your Pokemon\n\t\t4) Veiw your bag\n\t\t5) View Map (Go Fullscreen)\n\t\t6) Quit\n\n\tchoice: ";
	int choice = getInt();
	Explore ex = Explore();
	while (choice != 6) 
	{
		switch (choice) 
		{
		case 1: ex.exploreNow(&game);
			break;
		case 2: game.viewPokedex();
			break;
		case 3: game.viewTeam();
			break;
		case 4: game.viewBag();
			break;
		case 5: game.viewMap();
			break;
			
		}
		cout << "\n\tWhat do you want to do now?\n\t\t1) Explore\n\t\t2) Veiw the Pokedex\n\t\t3) Veiw your Pokemon\n\t\t4) Veiw your bag\n\t\t5) View Map (Go Fullscreen)\n\t\t6) Quit\n\n\tchoice: ";
		choice = getInt();
	}
	cout << "Goodbye!" << endl;
}

void GameEngine::viewTeam()
{
	for(int i = 0; i < 6; i++)
	{
		cout << "Slot " << i << ": " << mainCharacter.getPokemon(i)->getName() << endl;
	}
}

void GameEngine::viewPokedex()
{
	int dex = 1;

	for (int i=0; i<79; i++) 
	{
		for (int j = 0; j<4; j++) 
		{
			cout << dex++ << ": " << mainCharacter.getCurrentPokemon()->getPokedexEntry(i, j) << ", " <<
				mainCharacter.getCurrentPokemon()->getPokedexEntry(i, 4) << " type" << endl;
			if (mainCharacter.getCurrentPokemon()->getPokedexEntry(i, j) == mainCharacter.getCurrentPokemon()->getPokedexEntry(i, j+1)) 
			{
				break;
			}

		}
	}
}

void GameEngine::viewBag()
{
	cout << "You have\n\t" << "$" << mainCharacter.getMoney() << "\n\t" << mainCharacter.getPokeBallCount() <<
		" pokeball(s)\n\t" << mainCharacter.getPotionCount() << " potion(s)" << endl;
}

void GameEngine::viewMap()
{
	cout << "\nOrigin at top left --- Domain of +x and -y" << endl;
	cout << "Key: W = Wall     T = Town     @ = Player" << endl;
	for (int i = 0; i < MAP_SIZE; ++i)
	{
		for (int j = 0; j < MAP_SIZE; ++j)
		{
			if ((j == mainCharacter.getX()) && (i == mainCharacter.getY())) {
				cout << "@";
			}
			else if (newmap[i][j] == TOWN) {
				cout << "T";
			}
			else if (newmap[i][j] == WALL) {
				cout << "W";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
}

string getString()
{
	std::string item;
	bool validInput = false;

	do
	{
		std::cin >> item;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			validInput = false;
		}
		else
		{
			validInput = true;
		}

	} while (!validInput);

	return item;
}

int getInt()
{
	int item;
	bool validInput = false;

	do
	{
		std::cin >> item;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			item = 0;
			validInput = false;
			std::cout << "Invalid Input, try again" << std::endl;
		}
		else
		{
			validInput = true;
		}

	} while (!validInput);

	return item;
}

GameEngine::GameEngine()
{
	int genderChoice;
	int pokeChoice;
	
	string nameChoice;

	cout << "You wake up dazed and confused in a forest." << endl;
	cout << "There is writing on a tree. You approach and it reads 'Welcome to Kanto.'" << endl;
	cout << "Theres a voice in your head. It says 'What is your name?'\n You respond: ";
	nameChoice = getString();
	cout << "What is your gender?'\n Your gender (1. Female, 2. Male): ";
	genderChoice = getInt();
	while (genderChoice != 1 && genderChoice != 2) {
		cout << "Invalid Input, try again" << endl;
		genderChoice = getInt();
	}
	mainCharacter = Character(nameChoice, genderChoice);
	cout << "'I see greatness in you, " << mainCharacter.getName() << ". Become the best, and I will speak with you again.'" << endl;
	cout << "The voice disappeared and 3 Pokeballs appeared." << endl;
	cout << "Grab the 1st, 2nd, or 3rd one? " << endl;
	
	bool valid = false;
	
	do
	{
		pokeChoice = getInt();
		switch(pokeChoice)
		{
			case 1:
			{
				mainCharacter.addPokemon(Pokemon(1,0));
				valid = true;
				break;
			}
			case 2:
			{
				mainCharacter.addPokemon(Pokemon(1,1));
				valid = true;
				break;
			}
			case 3:
			{
				mainCharacter.addPokemon(Pokemon(1,2));
				valid = true;
				break;
			}
			default:
			{
				cout << "Invalid choice. Try again: ";
				valid = false;
			}
		
		}
	} while (!valid);
	
	for (int i = 0; i < 10; ++i) 
	{
		mainCharacter.addPotion();
	}
	
	for (int i = 0; i < 10; ++i) 
	{
		mainCharacter.addPokeBall();
	}
	
	cout << "You got a " << mainCharacter.getPokemon(0)->getName() << "!" << endl;
	cout << "The other pokeballs disappeared before you could grab another." << endl;
	cout << "Your " << mainCharacter.getPokemon(0)->getName() << " is a pokemon." << endl;
	cout << "Use it to battle other trainers and other wild pokemon." << endl;
	
	/** The map will hold ints and the ints will represent as follows: 
	* 0: Character
	* 1: wall		Example output: Its a 40 foot tall concrete wall with barbwire on top. aka Trump's wall
	* 2: forest 		Example output: You are in a forest
	* 3: desert		Example output: You are in a desert
	* 4: swamp		Example output: ...
	* 5: town		Example output: You have found (blank) town
	*/
	
	//should be done now
	newmap = new int*[MAP_SIZE];
	for(int i = 0; i < MAP_SIZE; i++)
	{
		newmap[i] = new int[MAP_SIZE];
	}
	
	for (int i = 0; i < MAP_SIZE / 2; i++) {
		for (int j = 0; j < MAP_SIZE / 2; j++) {
			newmap[i][j] = SWAMP;
		}
	}

	for (int i = 0; i < MAP_SIZE / 2; i++) {
		for (int j = 50; j < MAP_SIZE; j++) {
			newmap[i][j] = FOREST;
		}
	}

	for (int i = 50; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE / 2; j++) {
			newmap[i][j] = FOREST;
		}
	}

	for (int i = 50; i < MAP_SIZE; i++) {
		for (int j = 50; j < MAP_SIZE; j++) {
			newmap[i][j] = DESERT;
		}
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			newmap[i+39][j+39] = FOREST;
		}
	}

	for(int i = 0; i < 100; i++)
	{
		newmap[0][i] = WALL;
		newmap[99][i] = WALL;
		newmap[i][0] = WALL;
		newmap[i][99] = WALL;
	}

	//top = north, right = east
	//town 1, smallest
	pew = Town("Pewter City", 0);

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			//top left corner of town is at coordinate (15,15)
			newmap[i + 15][j + 15] = TOWN;
		}
	}
	
	//town 2, smaller
	fuch = Town("Fuchsia City", 1);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			//top left corner of town is at coordinate (57,57)? i guess, idk, maybe it should be moved
			newmap[i + 57][j + 57] = TOWN;
		}
	}

	//town 3, same size as 2
	cer = Town("Cerulean City", 2);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			//top left corner of town is at coordinate (79,20)? i guess, idk, maybe it should be moved
			newmap[i + 79][j + 20] = TOWN;
		}
	}

	//town 4, big town
	cel = Town("Celadon City", 3);
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			//top left corner of town is at coordinate (10,60)? i guess, idk, maybe it should be moved
			newmap[i + 10][j + 60] = TOWN;
		}
	}

}

void Explore::exploreNow(GameEngine *g)
{	
	// NOTE: Thinking in terms of a 2D array to a xy-plane, where origin (0,0) is
	// at the top left corner

	// NOTE: i and j being parameters for function trySpace() further below
	// i = rows = y-coord, where positive y is down the 2D array
	// j = columns = x-coord, where positive x is across the right of the array

	// North is up (decrease i)
	// South is down (increase i)
	// East is right (increase j)
	// West is left (decrease j)

	bool hasExit = false;
	
	do
	{
		cout << "Where to? (1 = North, 2 = South, 3 = East, 4 = West, or 5 = exit) ";
		int choice = getInt();
		
		if (choice == 1)
		{
			if(trySpace(g->mainCharacter.yPosition - 1, g->mainCharacter.xPosition, g)) g->mainCharacter.yPosition--;
		}
		else if (choice == 2)
		{
			if(trySpace(g->mainCharacter.yPosition + 1, g->mainCharacter.xPosition, g)) g->mainCharacter.yPosition++;
		}
		else if (choice == 3)
		{
			if(trySpace(g->mainCharacter.yPosition, g->mainCharacter.xPosition + 1, g)) g->mainCharacter.xPosition++;
		}
		else if (choice == 4)
		{
			if(trySpace(g->mainCharacter.yPosition, g->mainCharacter.xPosition - 1, g)) g->mainCharacter.xPosition--;
		}
		else if (choice == 5)
		{
			hasExit = true;
		}
		else
		{
			cout << "Invalid Input" << endl;
		}
		
	} while (!hasExit);
	
}

bool Explore::trySpace(int i, int j, GameEngine *g)
{
	if (i > MAP_SIZE || j > MAP_SIZE)
	{
		cout << "Error: explore.cpp trySpace out of bounds exception " << i << " " << j << " " << MAP_SIZE << endl;
		return false;
	}
	
	//cout << "i: " << i << "   j: " << j << "   mainCharacter name: " << g->mainCharacter.getName() << endl; all of this works and then numbers are what they are supposed to be
	int nextSpace = g->newmap[i][j]; 
	
	switch (nextSpace)
	{
		case WALL:
		{
			foundWall(g);
			return false;
			break;
		}
		case FOREST:
		{
			foundForest(g);
			return true;
			break;
		}
		case DESERT:
		{
			foundDesert(g);
			return true;
			break;
		}
		case SWAMP:
		{
			foundSwamp(g);
			return true;
			break;
		}
		case TOWN:
		{
			foundTown(g, i, j);
			return false;
			break;
		}
		default:
		{
			cout << "Error : explore.cpp trySpace mislabled space in map" << endl;
			return false;
			break;
		}
	}
}

void Explore::whatHappened(GameEngine *g)
{
	srand(time(NULL));

	int whatHappened = rand() % 100;
	
	//free steps works as a way to make it more and more likely to be stopped by a trainer or
	//pokemon the more times the player has moved without fighting a player or pokemon
	//we may need to adjust the frequency settings though
	if (whatHappened < (freeSteps*1.7))
	{
		Pokemon joey = Pokemon(g->mainCharacter.getCurrentPokemon()->getLevel());
		cout << "A " << joey.getName() << " has appeared from seemingly nowhere to fight!" << endl;
		freeSteps = 0;
		Battle(&g->mainCharacter, &joey);
	}
	else if (whatHappened > (100 - (freeSteps*1.4)))
	{
		int name = rand() % 20;
		Character joe = Character(people[name], (freeSteps%2) + 1);
		cout << "Trainer " << joe.getName() << " has spotted you! They want to battle!" << endl;
		
		int numberOfPokemon = rand() % 2+1;
		
		for(int i = 0; i < numberOfPokemon; i++)
		{
			joe.addPokemon(Pokemon(g->mainCharacter.getCurrentPokemon()->getLevel()));
		}
		
		freeSteps = 0;
		Battle(&g->mainCharacter, &joe); 
	}
	else
	{
		freeSteps++;
	}
}

void Explore::foundForest(GameEngine *g)
{
	cout << "(" << g->mainCharacter.xPosition << ",-" << g->mainCharacter.yPosition << ") " << "You are in a forest." << endl;
	whatHappened(g);
}

void Explore::foundDesert(GameEngine *g)
{
	cout << "(" << g->mainCharacter.xPosition << ",-" << g->mainCharacter.yPosition << ") " << "You are in a desert." << endl;
	whatHappened(g);
}

void Explore::foundSwamp(GameEngine *g)
{
	cout << "(" << g->mainCharacter.xPosition << ",-" << g->mainCharacter.yPosition << ") " << "You are in a Swamp." << endl;
	whatHappened(g);
}

void Explore::foundTown(GameEngine *g, int y, int x) 
{
	cout << "You have found a town!" << endl;
	if ((x == 15 || x == 16 || x == 17) && (y == 15 || y == 16 || y == 17)) { // Pewter City
		g->pew.visitTown(g);
	}
	else if ((x == 57 || x == 58 || x == 59 || x == 60) && (y == 57 || y == 58 || y == 59 || y == 60)) { // Fuchsia City
		g->fuch.visitTown(g);
	}
	else if ((x == 20 || x == 21 || x == 22 || x == 23) && (y == 79 || y == 80 || y == 81 || y == 82)) { // Cerulean City
		g->cer.visitTown(g);
	}
	else if ((x == 60 || x == 61 || x == 62 || x == 63 || x == 64 || x == 65 || x == 66)
		&& (y == 10 || y == 11 || y == 12 || y == 13 || y == 14 || y == 15 || y == 16)) { // Celadon City
		g->cel.visitTown(g);
	}
	else {
		cout << "ERROR: Coordinate failure (" << x << "," << y << ")" << endl;
	}
}

void Explore::foundWall(GameEngine *g)
{
	cout << "You have found a 40 foot wall concrete that is insermountable. The word TRUMP is written on the side.";
}

string Explore::people[20] = {"Alex", "Jack", "Jamie", "Avery", "Blair", "Christian", "Dane", "Fabian", "Glen", "Hayley", 
	"Kerry", "Lonnie", "Montana", "Noel", "Payton", "Quinn", "Rene", "Shay", "Tory", "Whitney"};

Town::Town()
{
	this->name = "DEFAULT";
	this->level = 0;
}

Town::Town(string name, int level) 
{
	
	this->name = name;
	this->level = level;
	int pokeLevel;
	string gymLeaderName;
	
	switch(level)
	{
		case 0:
		{
			gymLeaderName = "Viscount Jeremiah Geoffrey";
			pokeLevel = 20;
			break;
		}
		case 1: 
		{
			gymLeaderName = "Earl Roland Percy";
			pokeLevel = 40;
			break;
		}
		case 2: 
		{
			gymLeaderName = "Count Humphrey Ridgewell";
			pokeLevel = 60;
			break;
		}
		case 3: 
		{
			gymLeaderName = "Baron Jonathan Jack";
			pokeLevel = 80;
		}
	}
	
	int numberOfPokemon = 6;
	Character joe = Character(gymLeaderName, 2);	
	for(int i = 0; i < numberOfPokemon; i++)
	{
		joe.addPokemon(Pokemon(pokeLevel));
	}
		
	gymLeader = joe;
	
}

void Town::visitTown(GameEngine *g)
{
	bool isVisiting = true;
	cout << "You have entered " + name + ". What would you like to do?\n" << endl;
	while (isVisiting) {
		cout << "\t1) Pokemon Center (Heal)\n\t2) PokeMart (Shop)\n\t3) Challenge Gym (Battle)\n\t4) LEAVE\n\nchoice - ";
		int choice = getInt();
		switch (choice) {
		case 1:
			healPokemon(g->mainCharacter.getParty());
			break;
		case 2:
			buyItems(g);
			break;
		case 3:
			isVisiting = battleGym(g);
			break;
		case 4:
			cout << "You leave for the wilderness" << endl;
			isVisiting = false;
			break;
		}
	}
}

// TODO: implement the gym battle
bool Town::battleGym(GameEngine *g) 
{
	Battle* bat;
	
	if(g->mainCharacter.getBadges() > level)
	{
		cout << "You have already beat this gym!\n" << endl;
	}
	else if (g->mainCharacter.getBadges() < level)
	{
		cout << "You have to beat " << level - g->mainCharacter.getBadges() << " gym(s) before you can do that!\n" << endl;
	}
	else
	{
		cout << "You're going to challenge the city's gym? Are you sure?\n\n1) Yes\n2) No" << endl;
		int decision = getInt();
		while (decision != 1 && decision != 2)  
		{
			cout << "Invalid choice" << endl;
			decision = getInt();
		}
		if (decision == 1) 
		{
			bat = new Battle(&g->mainCharacter, &gymLeader); 
		}
		
		if(!bat->result)
		{
			return false;
		}
	}
	
	return true;
}

void Town::healPokemon(Pokemon* party)
{
	cout << "'Welcome to the Pokemon Center! We can heal your Pokemon to full health! One moment please...'" << endl;
	for (int i = 0; i < 6; ++i) 
	{
		party[i].changeCurrentHealth(999999);
		//cout << "Your  " << party[i].getName() << " has " << party[i].getCurrentHealth() << " hp. " << endl;
	}
	cout << "'Thank you for waiting! Your Pokemon are nice and healthy. Have a good day!'" << endl;
}

void Town::buyItems(GameEngine *g) 
{
	cout << "'Welcome to the Pokemart! What would you like to buy?'\n" << endl;
	bool isShopping = true;
	int amount;
	while (isShopping) 
	{
		cout << "\t1) Pokeball  [ $100 ]\n\t2) Potion  [ $200 ]\n\t3) EXIT\n\nchoice - ";
		int choice = getInt();
		switch (choice) 
		{
			case 1:
			{
				cout << "How many Pokeballs: ";
				amount = getInt();
				if (g->mainCharacter.spendMoney(100 * amount)) {
					for (int i = 0; i < amount; ++i)
					{
						g->mainCharacter.addPokeBall();
					}
					cout << "You purchased " << amount << " Pokeballs! 'Anything else?'" << endl;
				}
				break;
			}
			case 2:
			{
				cout << "How many Potions: ";
				amount = getInt();
				if (g->mainCharacter.spendMoney(200 * amount)) {
					for (int i = 0; i < amount; ++i)
					{
						g->mainCharacter.addPotion();
					}
					cout << "You purchased " << amount << " Potions! 'Anything else?'" << endl;
				}
				break;
			}
			case 3:
			{
				cout << "'Goodbye, please come again!'" << endl;
				isShopping = false;
				break;
			}
		}
	}
}
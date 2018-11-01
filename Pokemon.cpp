#include "gameEngine.h"
#include "Pokemon.h"


//NEED TO SET BADGES TO ZERO IN CONSTRUCOR, NOT IN HEADER FILE.

string Pokemon::pokeMen[79][5] = {{"Bulbasaur", "Ivysaur", "Venusaur", "Venusaur", "grass"},{"Charmander", "Charmeleon", "Charizard", "Charizard", "fire"},
	{"Squirtle", "Wartortle", "Blastoise", "Blastoise", "water"},{"Caterpie", "Metapod", "Butterfree", "Butterfree", "bug"},{"Weedle", "Kakuna", "Beedrill",
	"Beedrill", "bug"},{"Pidgey", "Pidgeotto", "Pidgeot", "Pidgeot", "flying"},{"Rattata", "Raticate", "Raticate", "Raticate", "normal"},{"Spearow", "Fearow",
	"Fearow", "Fearow", "flying"},{"Ekans", "Arbok", "Arbok", "Arbok", "poison"},{"Pikachu", "Raichu", "Raichu", "Raichu", "electric"},{"Sandshrew", "Sandslash",
	"Sandslash", "Sandslash", "ground"},{"Nidoran(f)", "Nidorina", "Nidoqueen", "Nidoqueen", "poison"},{"Nidoran(m)" ,"Nidorino", "Nidoking", "Nidoking", "poison"},
	{"Clefairy", "Clefable", "Clefable", "Clefable", "fairy"},{"Vulpix", "Ninetales", "Ninetales", "Ninetales", "fire"},{"Jigglypuff", "Wigglytuff", "Wigglytuff",
	"Wigglytuff", "fairy"},{"Zubat", "Golbat", "Golbat", "Golbat", "poison"},{"Oddish", "Gloom", "Vileplume", "Vileplume", "grass"},{"Paras", "Parasect", "Parasect",
	"Parasect", "grass"},{"Venonat", "Venomoth", "Venomoth", "Venomoth", "bug"},{"Diglet", "Dugtrio", "Dugtrio", "Dugtrio", "ground"},{"Meowth", "Persian",
	"Persian", "Persian", "normal"},{"Psyduck", "Golduck", "Golduck", "Golduck", "water"},{"Mankey", "Primeape", "Primeape", "Primeape", "fighting"},{"Growlithe",
	"Arcanine", "Arcanine", "Arcanine", "fire"},{"Poliwag", "Poliwhirl", "Poliwrath", "Poliwrath", "water"},{"Abra", "Kadabra", "Alakazam", "Alakazam", "psychic"},
	{"Machop", "Machoke", "Machamp", "Machamp", "fighting"},{"Bellsprout", "Weepinbell", "Victreebel", "Victreebel", "grass"},{"Tentacool", "Tentacruel", "Tentacruel",
	"Tentacruel", "water"},{"Geodude", "Graveler", "Golem", "Golem", "rock"},{"Ponyta", "Rapidash", "Rapidash", "Rapidash", "fire"},{"Slowpoke", "Slowbro", "Slowbro",
	"Slowbro", "psychic"},{"Magnemite", "Magneton", "Magneton", "Magneton", "electric"},{"Farfetch'd", "Farfetch'd", "Farfetch'd", "Farfetch'd", "flying"},{"Doduo",
	"Dodrio", "Dodrio", "Dodrio", "flying"},{"Seel", "Dewgong", "Dewgong", "Dewgong", "water"},{"Grimer", "Muk", "Muk", "Muk", "poison"},{"Shellder", "Cloyster",
	"Cloyster", "Cloyster", "water"},{"Gastly", "Haunter", "Gengar", "Gengar", "ghost"},{"Onix", "Onix", "Onix", "Onix", "rock"},{"Drowzee", "Hypno", "Hypno",
	"Hypno", "psychic"},{"Krabby", "Kingler", "Kingler", "Kingler", "water"},{"Voltorb", "Electrode", "Electrode", "Electrode", "electric"},{"Exeggcute", "Exeggutor",
	"Exeggutor", "Exeggutor", "psychic"},{"Cubone", "Marowak", "Marowak", "Marowak", "ground"},{"Hitmonlee", "Hitmonlee", "Hitmonlee", "Hitmonlee", "fighting"},
	{"Hitmonchan", "Hitmonchan", "Hitmonchan", "Hitmonchan", "fighting"},{"Lickitung", "Lickitung", "Lickitung", "Lickitung", "normal"},{"Koffing", "Weezing",
	"Weezing", "Weezing", "poison"},{"Rhyhorn", "Rhydon", "Rhydon", "Rhydon", "rock"},{"Chansey", "Chansey", "Chansey", "Chansey", "normal"},{"Tangela", "Tangela",
	"Tangela", "Tangela", "grass"},{"Kangaskhan", "Kangaskhan", "Kangaskhan", "Kangaskhan", "normal"},{"Horsea", "Seadra", "Seadra", "Seadra", "water"},{"Goldeen",
	"Seaking", "Seaking", "Seaking", "water"},{"Staryu", "Starmie", "Starmie", "Starmie", "water"},{"Mr. Mime", "Mr. Mime", "Mr. Mime", "Mr. Mime", "psychic"},
	{"Scyther", "Scyther", "Scyther", "Scyther", "bug"},{"Jynx", "Jynx", "Jynx", "Jynx", "psychic"},{"Electabuzz", "Electabuzz", "Electabuzz", "Electabuzz", "electric"},
	{"Magmar", "Magmar", "Magmar", "Magmar", "fire"},{"Pinsir", "Pinsir", "Pinsir", "Pinsir", "bug"},{"Tauros", "Tauros", "Tauros", "Tauros", "normal"},{"Magikarp",
	"Gyarados", "Gyarados", "Gyarados", "water"},{"Lapras", "Lapras", "Lapras", "Lapras", "water"},{"Ditto", "Ditto", "Ditto", "Ditto", "normal"},{"Eevee", "Vaporeon",
	"Jolteon", "Flareon", "normal"},{"Porygon", "Porygon", "Porygon", "Porygon", "normal"},{"Omanyte", "Omastar", "Omastar", "Omastar", "water"},{"Kabuto", "Kabutops",
	"Kabutops", "Kabutops", "water"},{"Aerodactyl", "Aerodactyl", "Aerodactyl", "Aerodactyl", "rock"},{"Snorlax", "Snorlax", "Snorlax", "Snorlax", "normal"},{"Articuno",
	"Articuno", "Articuno", "Articuno", "ice"},{"Zapdos", "Zapdos", "Zapdos", "Zapdos", "electric"},{"Moltres", "Moltres", "Moltres", "Moltres", "fire"},{"Dratini",
	"Dragonair", "Dragonite", "Dragonite", "dragon"},{"Mewtwo", "Mewtwo", "Mewtwo", "Mewtwo", "psychic"},{"Mew", "Mew", "Mew", "Mew", "psychic"}};

// this array contains all of the names and types for each pokemon. the evolution will be chosen during construction based on level.

Pokemon::Pokemon()
{
	this->name = "Empty";
}

Pokemon::Pokemon(int level) 
{
    //names are chosen based on level, so a level one will be squirtle, etc. i haven't yet implemented evelution for EXISTING pokemon on level up.
    this-> choice = rand()%79;
    if(level <= 12) {
        this->name = pokeMen[choice][0];
    }
    else if(level <= 25) {
        this->name = pokeMen[choice][1];
    }
    else {
        this->name = pokeMen[choice][2];
    }
    this->type = pokeMen[choice][3];
    this->experience = 0;
    this->level = level;
    
    //these numbers are obviously subject to change. also we will likely not use rand() in final version since it will create the same pokemon each time the game is run, but that may be useful for debugging
    this->health = (level)*15 + (rand()%79 + 50);
    this->currentHealth = health;
    this->attack = (level)*3 + (rand()%15);
    
    //dodge is a value from 0-25 and is higher for lower health pokemon. i envisioned it being a chance to dodge (out of 100%) to help buff lower health pokemon.
    this->dodge = int((1.0/(health-((level-1)*20)))*1000 + (rand()%10-5));

}

//overloaded constructor for picking starters or simply creating specific pokemon.
Pokemon::Pokemon(int level, int choice) 
{
	this->choice = choice;
    if(level <= 12) {
        this->name = pokeMen[choice][0];
    }
    else if(level <= 25) {
        this->name = pokeMen[choice][1];
    }
    else {
        this->name = pokeMen[choice][2];
    }
    this->type = pokeMen[choice][3];
    this->experience = 0;
    this->level = level;
    
    this->health = (level)*20 + (rand()%151 + 50);
    this->currentHealth = health;
    this->attack = (level)*3 + (rand()%15 + 8);
    this->dodge = int((1.0/(health-((level-1)*20)))*1000 + (rand()%10-5));
}


int Pokemon::getHealth() {
    return health;
}

int Pokemon::getAttack() {
    return attack;
}

int Pokemon::getDodge() {
    return dodge;
}

int Pokemon::getCurrentHealth() {
    return currentHealth;
}

int Pokemon::getLevel() {
    return level;
}

int Pokemon::getExperience() {
    return experience;
}

string Pokemon::getName() {
    return name;
}

string Pokemon::getType() {
    return type;
}

string Pokemon::getPokedexEntry(int i, int j)
{
	if(!(i > 150 && i < 0 && j < 0 && j > 3)) return pokeMen[i][j];
}

//not sure if this should print anything or not, depends on battles, also, note that this INCREASES health by healthChange.
void Pokemon::changeCurrentHealth(int healthChange) {
    if((currentHealth + healthChange) < health) 
    {
        currentHealth += healthChange;
    }
    else {
        currentHealth = health;
    }
    if(currentHealth < 0) {
        currentHealth = 0;
    }
}

//handles leveling up and evolving
void Pokemon::giveExperience(int exp) 
{
    if((experience + exp) < (45 + (5*level))) 
	{
        experience = experience + exp;
		cout << "Your " << name << " has gained " << exp << " experience! - exp: " << experience << "/" << (50 + (10*level)) << "." << endl;
    }
    else if(level < 100)
	{
		experience = 0;
		level += 1;
		health += 20;
		currentHealth += 20;
		attack += 3;
		cout << "Your " << name << " is now level " << level << "! - Health: " << health << " - Attack: " << attack << " - Dodge: " << dodge << "." << endl;
		if((level == 12)&&(pokeMen[choice][0]!=pokeMen[choice][1])) 
		{
			cout << "Your " << name << " has evolved into " << pokeMen[choice][1] << "!" << endl;
			name = pokeMen[choice][1];
		}
		if((level == 25)&&(pokeMen[choice][1]!=pokeMen[choice][2])) 
		{
			cout << "Your " << name << " has evolved into " << pokeMen[choice][2] << "!" << endl;
			name = pokeMen[choice][2];
		}
    }
    else 
	{
		cout << "This " << name << " is already maximum level!" << endl;
    }
}

Character::Character()
{
	//stuff
}

Character::Character(std::string n)
{
	name = n;
	setPos();	
}					

Character::Character(std::string n, int g)
{
	name = n;
	gender = g;
	setPos();						//IMPORTANT!!! WHEN YOU POPULATE THE POKEMON ARRAY ON CREATION, FILL THE EMPTY SLOTS WITH A

	badges = 0;
	money = 500;
	potions = 0;
	pokeBalls = 0;
	
	for(int i = 0; i < 6; i++)
	{
		party[i] = Pokemon();
	}					
}

void Character::setPos()
{
	xPosition = 50;								//From joey, needed in explore function
	yPosition = 50;	
}

string Character::getName()
{
	return name;
}

void Character::addPokemon(Pokemon* p)
{
	bool hasSlot = false;
	bool allEmpty = true;
	int indexOfFirstEmpty;
	for(int i = 0; i < 6; i++)
	{
		if (party[i].getName().compare("Empty") == 0)
		{
			if(!hasSlot) indexOfFirstEmpty = i;
			hasSlot = true;
		}
		else
		{
			allEmpty = false;
		}
	}	
	
	if(allEmpty)
	{
		party[0] = *p;
		setCurrentPokemon(0);
	}
	else if (hasSlot)
	{
		party[indexOfFirstEmpty] = *p;
	}
	else
	{
		cout << "No slots available. Which pokemon would you like to get ride of?" << endl;

		for(int i = 0; i < 6; i++)
		{
			cout << " " << i + 1 << ". " << party[i].getName();
		}
		cout << " " << 7 << ". None";
		
		bool goodInput;
		
		do
		{
			int choice = getInt1() - 1;
			goodInput = true;
			
			switch(choice)
			{
				case 0: 
				{
					cout << party[0].getName() << " was removed and " << p->getName() << " was added.";
					party[0] = *p;
					break;
				}
				case 1: 
				{
					cout << party[1].getName() << " was removed and " << p->getName() << " was added.";
					party[1] =*p;
					break;
				}
				case 2: 
				{
					cout << party[2].getName() << " was removed and " << p->getName() << " was added.";
					party[2] = *p;
					break;
				}
				case 3: 
				{
					cout << party[3].getName() << " was removed and " << p->getName() << " was added.";
					party[3] = *p;
					break;
				}
				case 4: 
				{
					cout << party[4].getName() << " was removed and " << p->getName() << " was added.";
					party[4] = *p;
					break;
				}
				case 5: 
				{
					cout << party[5].getName() << " was removed and " << p->getName() << " was added.";
					party[5] = *p;
					break;
				}
				case 6: 
				{
					cout << p->getName() << " was turned into candy.";
					break;
				}
				default: 
				{
					cout << "Invalid input" << endl;
					goodInput = false;
					break;
				}
			}
		} while(!goodInput);
	}	
}

void Character::addPokemon(Pokemon p)
{
	bool hasSlot = false;
	bool allEmpty = true;
	int indexOfFirstEmpty;
	for(int i = 0; i < 6; i++)
	{
		if (party[i].getName().compare("Empty") == 0)
		{
			if(!hasSlot) indexOfFirstEmpty = i;
			hasSlot = true;
		}
		else
		{
			allEmpty = false;
		}
	}	
	
	if(allEmpty)
	{
		party[0] = p;
		setCurrentPokemon(0);
	}
	else if (hasSlot)
	{
		party[indexOfFirstEmpty] = p;
	}
	else
	{
		cout << "No slots available. Which pokemon would you like to get ride of?" << endl;

		for(int i = 0; i < 6; i++)
		{
			cout << " " << i + 1 << ". " << party[i].getName();
		}
		cout << " " << 7 << ". None";
		
		bool goodInput;
		
		do
		{
			int choice = getInt1() - 1;
			goodInput = true;
			
			switch(choice)
			{
				case 0: 
				{
					cout << party[0].getName() << " was removed and " << p.getName() << " was added.";
					party[0] = p;
					break;
				}
				case 1: 
				{
					cout << party[1].getName() << " was removed and " << p.getName() << " was added.";
					party[1] = p;
					break;
				}
				case 2: 
				{
					cout << party[2].getName() << " was removed and " << p.getName() << " was added.";
					party[2] = p;
					break;
				}
				case 3: 
				{
					cout << party[3].getName() << " was removed and " << p.getName() << " was added.";
					party[3] = p;
					break;
				}
				case 4: 
				{
					cout << party[4].getName() << " was removed and " << p.getName() << " was added.";
					party[4] = p;
					break;
				}
				case 5: 
				{
					cout << party[5].getName() << " was removed and " << p.getName() << " was added.";
					party[5] = p;
					break;
				}
				case 6: 
				{
					cout << p.getName() << " was turned into candy.";
					break;
				}
				default: 
				{
					cout << "Invalid input" << endl;
					goodInput = false;
					break;
				}
			}
		} while(!goodInput);
	}	
}

Pokemon* Character::getPokemon(int i) // takes number 1-6 of desired Pokemon in party
{
	if( i >= 0 && i < 6)
	{		
		return &party[i];
	}
	else 
	{
		cout << "Error in getPokemon.";
		return currentPokemon;
	}
}
				
Pokemon* Character::getCurrentPokemon() //Marco: for getting the currentPokemon the player has.
{
	return currentPokemon;
}		
	
Pokemon Character::setCurrentPokemon(int i)
{
	if ( i >= 0 && i < 6)	
{		
		currentPokemon = &party[i];
		return *currentPokemon;
	}
	else 
	{
		cout << "Error in setCurrentPokemon.";
		return *currentPokemon;
	}
	
}

void Character::setCurrentPokemon(Pokemon* c)
{		
	currentPokemon = c;
}

Pokemon *Character::getParty() {
	return party;
}

// Matt: For bag functioning, healing, catching pokemon

void Character::usePotion(Pokemon *p) {
	if (potions <= 0) {
		cout << "No potions available" << endl;
	}
	else {
		--potions;
		p->changeCurrentHealth(0.50 * p->getHealth()); // Potions restore 50% of max health
	}
}
bool Character::usePokeBall(Pokemon* enemy)
{
	if (pokeBalls == 0) {
		cout << "No pokeballs available" << endl;
		return false;
	}
	else {
		--pokeBalls;
		srand(1337);
		int PokeChance = rand() % 50;
		if (PokeChance >= (int)((enemy->getCurrentHealth()*100) / enemy->getHealth())) {
			cout << "Pokemon was caught!\n" << endl;
			addPokemon(enemy);
			return true;
		}
		else {
			cout << "Pokemon escaped the Pokeball!\n" << endl;
			return false;
		}
		
	}
}

bool Character::spendMoney(int amount) {
	if (money >= amount) {
		money -= amount;
		return true;
	}
	else {
		cout << "You don't have the cash for this!" << endl;
		return false;
	}
}

void Character::forfeitCash(int amount) {
	money -= amount;
	if (money < 0) {
		money = 0;
	}
}

void Character::addPotion() {
	++potions;
}

void Character::addPokeBall() {
	++pokeBalls;
}

void Character::addMoney(int amount) {
	money += amount;
}


int Character::getPotionCount() {
	return potions;
}

int Character::getPokeBallCount() {
	return pokeBalls;
}

int Character::getMoney() {
	return money;
}

int Character::getBadges() {
	return badges;
}

int Character::getX() {
	return xPosition;
}

int Character::getY() {
	return yPosition;
}
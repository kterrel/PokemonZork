#include "battle.h"
#include "Pokemon.h"


using namespace std;

// define functions in header (main() NOT located here)

void Battle::wait(int sec)
{
	int i = 0;
	while(i++ < sec)
	{
		for(int j = 0; j < 100; j++) cout<<"";
		//usleep(1000000);
	}
	cout<<endl;
}

void Battle::attack(int turns, Character* thePlayer, Character* theEnemyPlayer)
{
	Pokemon* currEnemyPok = theEnemyPlayer->getCurrentPokemon();
	Pokemon* currMyPok = thePlayer->getCurrentPokemon();
	
	int dodgechance;
	int damage;
	string person;
	if (turns == 0)
	{
		dodgechance = currMyPok->getDodge();
		person = "You";
	}
	else
	{
		dodgechance = currEnemyPok->getDodge();
		person = "They";
	}
	srand(time(NULL));
	int dodgeroll = rand() % 100+1;
	cout << person << " attack!";
	wait(WAIT);
	if (dodgeroll >= dodgechance) 
	{
		//attack
		if (turns == 0) 
		{
			//Note: attacks have yet to be balanced.
			//mypokemon attacks
			damage = currMyPok->getAttack() * (-0.5);
			//The typeMultiplier represents a double array of gen 1 pokemon type chart multipliers.
			//the pokemon.typenumber
			//damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
			
			currEnemyPok->changeCurrentHealth(damage);
			cout << "Your attack was successful!\n";
			theEnemyPlayer->setCurrentPokemon(currEnemyPok);
		}
		else 
		{
			//enemy pokemon attacks
			damage = currEnemyPok->getAttack() * (-0.5);
			//damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
			currMyPok->changeCurrentHealth(damage);
			cout << "Their attack was successful!\n";
			thePlayer->setCurrentPokemon(currMyPok);
		}
	}
	else
	{
		//attack missed.
		cout << "The attack missed!\n";
	}
	
	if (currMyPok->getCurrentHealth() <= 0) 
	{
		//forces a switch of pokemon if pokemon faints.
		cout << "Your pokemon has fainted!" << endl;
		switchPokemon(thePlayer);
	}

	
	if (currEnemyPok->getCurrentHealth() <= 0) 
	{
		cout << "The enemy pokemon has fainted!";
		//todo: make a loop that checks the next healthy pokemon (and maybe battle type).
		switchPokemon(theEnemyPlayer);
	}
	
};

void Battle::attack(int turns, Character* thePlayer, Pokemon* wildPokemon) 
{
	int dodgechance;
	int damage;
	string person;
	if (turns == 0)
	{
		dodgechance = thePlayer->getCurrentPokemon()->getDodge();
		person = "You";
	}
	else
	{
		dodgechance = wildPokemon->getDodge();
		person = "They";
	}
	srand(time(NULL));
	int dodgeroll = rand() % 100+1;
	cout << person << " attack!" << endl;
	wait(WAIT);
	if (dodgeroll >= dodgechance) 
	{
		if (turns == 0) 
		{
			cout << "Your attack was successful!\n" << endl;
			//Note: attacks have yet to be balanced.
			//mypokemon attacks
			damage = thePlayer->getCurrentPokemon()->getAttack() * (-0.5);
			//The typeMultiplier represents a double array of gen 1 pokemon type chart multipliers.
			//the pokemon.typenumber
			//damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
			
			wildPokemon->changeCurrentHealth(damage);
		}
		else 
		{
			cout << "Their attack was successful!" << endl;
			//enemy pokemon attacks
			damage = wildPokemon->getAttack() * (-0.5);
			//damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
			Pokemon* temp = thePlayer->getCurrentPokemon();
			temp->changeCurrentHealth(damage);
			thePlayer->setCurrentPokemon(temp);
			if (temp->getCurrentHealth() <= 0)
			switchPokemon(thePlayer);
		}
	}
	else
	{
		
		cout << "The attack missed!\n";
	}
};

Pokemon* Battle::switchPokemon(Character* trainer)
{
	//For forced pokemon switch.

	for (int i = 0; i < 6; i++)
	{
		Pokemon* switchPokemon = trainer->getPokemon(i);
		if (switchPokemon->getCurrentHealth() > 0 && switchPokemon->getName().compare("Empty") != 0)
		{
			trainer->setCurrentPokemon(i);
			cout << " Switched to " << switchPokemon->getName() << ".\n";
			break;
		}	
	}
	return trainer->getCurrentPokemon();
};

Pokemon* Battle::switchPokemon(int numPokemon, Character* trainer){
	//For user choice switch.
	Pokemon* currPokemon = trainer->getCurrentPokemon();
	Pokemon* switchPokemon = trainer->getPokemon(numPokemon);
	if (switchPokemon->getCurrentHealth() > 0 && switchPokemon->getName().compare("Empty") != 0)
	{
		trainer->setCurrentPokemon(numPokemon);
		return switchPokemon;
	}
	else 
	{
		cout << "You cannot switch to that pokemon!\n";
	}
	return currPokemon;
};

Battle::Battle(Character* player, Pokemon* enemy) 
{
	result = true;
	Pokemon* currPokemon = player->getCurrentPokemon();
	int action = 0;
	//turn decides who attacks: 0 = you, 1 = enemy.
	bool turn = 0;
	while (action != 4 && (enemy->getCurrentHealth()>0 && currPokemon->getCurrentHealth()>0)) 
	{
		cout << "\nYour " << currPokemon->getName() << " has " << currPokemon->getCurrentHealth() << " hp. ";
		cout << "The enemy pokemon, " << enemy->getName() << ", has " << enemy->getCurrentHealth() << " hp." << endl;
		
		cout << "\nWhat would you like to do?" << endl;
		cout << "\t1) FIGHT\t2) BAG\n\t3) POKEMON\t4) RUN\n\n\tchoice: ";
		action = getInt1();
		switch (action)
		{
		case 1:
			{
				attack(0,player,enemy);
				turn = 1;
				break;
			}
		case 2:
			{
				int bagChoice = 5;//for now but open bag
				int bagOption = 0;
				while (bagChoice > 3 || bagChoice < 1) {
					cout << "You have: \n\t1) " << player->getPokeBallCount() << " pokeballs\n\t2) " << player->getPotionCount() << " health potions";
					cout << "\n\t3)RETURN\nWhat will you use?\n\t\tchoice: ";
					bagChoice = getInt1();
					if (bagChoice == 1) {
						//use Pokeball
						bool caughtPokemon = player->usePokeBall(enemy);
						if (caughtPokemon == true)
							goto caughtPokemon;
					}
					if (bagChoice == 2) {
						//use health potion
						//I have a function available in the Character class that handles the Potion calculations that
						// we can use:

						player->usePotion(currPokemon);
						player->setCurrentPokemon(currPokemon);
					}
				}
				break;
			}
		case 3:
			{
				int pokeswitch = 0;
				Pokemon* beforePokemon = currPokemon;
				while (pokeswitch > 7 || pokeswitch < 1) 
				{
					cout << "Which pokemon would you like to switch to?";
					Pokemon* pok1 = player->getPokemon(0);
					cout << "\n\t1)" << pok1->getName();
					Pokemon* pok2 = player->getPokemon(1);
					cout << "\t2)" << pok2->getName();
					Pokemon* pok3 = player->getPokemon(2);
					cout << "\n\t3)" << pok3->getName();
					Pokemon* pok4 = player->getPokemon(3);
					cout << "\t4)" << pok4->getName();
					Pokemon* pok5 = player->getPokemon(4);
					cout << "\n\t5)" << pok5->getName();
					Pokemon* pok6 = player->getPokemon(5);
					cout << "\t6)" << pok6->getName();
					cout << "\n\t\t7) Exit\n\n\tchoice: ";
					pokeswitch = getInt1();
					switch (pokeswitch) 
					{
						case 1:
							currPokemon = switchPokemon(0,player);
							break;
						case 2:
							currPokemon = switchPokemon(1,player);
							break;
						case 3:
							currPokemon = switchPokemon(2,player);
							break;
						case 4:
							currPokemon = switchPokemon(3,player);
							break;
						case 5:
						currPokemon = switchPokemon(4,player);
						break;
						case 6:
							currPokemon = switchPokemon(5,player);
							break;
					}
					if (pokeswitch > 7 || pokeswitch < 1)
						cout << "Invalid pokemon choice, please try again.\n";
				}
				//if (pokeswitch != 7) turn = 1; (replaced code)
				if (currPokemon->getName() != beforePokemon->getName()) 
				{
					turn = 1;
				}
				break;
			}
		}
		
		if (turn == 1 && enemy->getCurrentHealth() > 0) 
		{
			attack(1, player, enemy);
			turn = 0;
		}
		
		currPokemon = player->getCurrentPokemon();
		wait(WAIT);
	}
	if (currPokemon->getCurrentHealth() <= 0) 
	{
		cout << "You have lost the battle!\n";
		lostMatch(player);
	}
	else if (enemy->getCurrentHealth() <=0 && action != 4) 
	{
		cout << "You have won the battle!" << endl;
		currPokemon->giveExperience(rand()%(29+4*currPokemon->getLevel())+24+4*currPokemon->getLevel());
		//currPokemon = player->getCurrentPokemon();
		//award exp.
	}
	else
	{
		cout << "You ran away!" << endl;
	}
caughtPokemon:;
}
//Battle for a character essentially does the same thing but you cannot run away nor catch.
Battle::Battle(Character* player, Character* opponent) 
{
	result = true;
	Pokemon* currPokemon = player->getCurrentPokemon();
	Pokemon* currEnemyPokemon = opponent->getCurrentPokemon();
	int action = 0;
	//turn decides who attacks: 0 = you, 1 = enemy.
	bool turn = 0;
	
	while (currEnemyPokemon->getCurrentHealth()>0 && currPokemon->getCurrentHealth()>0) 
	{	
		cout << "\nYour " << currPokemon->getName() << " has " << currPokemon->getCurrentHealth() << " hp. ";
		cout << "The enemy pokemon, " << currEnemyPokemon->getName() << ", has " << currEnemyPokemon->getCurrentHealth() << " hp." << endl;
		
		cout << "\nWhat would you like to do?" << endl;
		cout << "\t1) FIGHT\t2) BAG\n\t3) POKEMON\n\n\tchoice: ";
		action = getInt1();
		switch (action) 
		{
		case 1:
			{
				attack(0,player,opponent);
				turn = 1;
				break;
			}
		case 2:
			{
				int bagChoice = 5; //open bag
				int bagOption = 0;
				while (bagChoice > 3 || bagChoice < 1) {
					cout << "You have: \n\t1) " << player->getPokeBallCount() << " pokeballs\n\t2) " << player->getPotionCount() << " health potions";
					cout << "\n\t3)RETURN\nWhat will you use?\n\n\tchoice: ";
					bagChoice = getInt1();
					if (bagChoice == 1){
						//can't use pokeballs here.
						cout << "You can't catch their pokemon!\n";
						bagOption = 0;
					}
					if (bagChoice == 2){
						//use health potion
						//Matt: I have a function available in the Character class that handles the Potion calculations that
						// we can use:

						
						player->usePotion(currPokemon);
						player->setCurrentPokemon(currPokemon);
						//if (player.potions != 0) {
						//	player.potions--;
						//	currPokemon.changeCurrentHealth(currPokemon.getCurrentHealth() + currPokemon.getHealth()*0.5);
						//	if (currPokemon.getCurrentHealth() > currPokemon.getHealth()) {
						//		//Takes away the extra health if it exceeds maxhealth.
						//		currPokemon.changeCurrentHealth(0 - (currPokemon.getCurrentHealth() - currPokemon.getHealth()));
						//	}
						//}
						//else {
						//	cout << "You have no potions!\n";
						//}
					}
				}
				break;
			}
		case 3:
			{
				int pokeswitch = 0;
				Pokemon* beforePokemon = currPokemon;
				while (pokeswitch > 7 || pokeswitch < 1) {
					cout << "Which pokemon would you like to switch to?";
					Pokemon* pok1 = player->getPokemon(0);
					cout << "\n\t1)" << pok1->getName();
					Pokemon* pok2 = player->getPokemon(1);
					cout << "\n\t2)" << pok2->getName();
					Pokemon* pok3 = player->getPokemon(2);
					cout << "\n\t3)" << pok3->getName();
					Pokemon* pok4 = player->getPokemon(3);
					cout << "\n\t4)" << pok4->getName();
					Pokemon* pok5 = player->getPokemon(4);
					cout << "\n\t5)" << pok5->getName();
					Pokemon* pok6 = player->getPokemon(5);
					cout << "\n\t6)" << pok6->getName();
					cout << "\n\t\t7)Exit\n\n\tchoice: ";
					pokeswitch = getInt1();
					switch (pokeswitch) {
					case 1:
						currPokemon = switchPokemon(0, player);
						break;
					case 2:
						currPokemon = switchPokemon(1, player);
						break;
					case 3:
						currPokemon = switchPokemon(2, player);
						break;
					case 4:
						currPokemon = switchPokemon(3, player);
						break;
					case 5:
						currPokemon = switchPokemon(4, player);
						break;
					case 6:
						currPokemon = switchPokemon(5, player);
						break;
					}
					if (pokeswitch > 7 || pokeswitch < 1)
						cout << "Invalid pokemon choice, please try again.\n";
				}
	
				if (currPokemon->getName() != beforePokemon->getName()) {
					turn = 1;
				}
				break;
			}
		}
		
		currEnemyPokemon = opponent->getCurrentPokemon();
		
		if (turn == 1 && currEnemyPokemon->getCurrentHealth() > 0) 
		{
			attack(1, player, opponent);
			turn = 0;
		}
		
		currPokemon = player->getCurrentPokemon();
		
		wait(WAIT);
	}
	
	currPokemon = player->getCurrentPokemon();
	if (currPokemon->getCurrentHealth() <= 0) 
	{
		cout << "You have lost the battle! You pass out!.\n";
		player->forfeitCash(300);
		lostMatch(player);
	}

	else if(currEnemyPokemon->getCurrentHealth() <= 0) 
	{
		cout << "You won the battle! Your opponent gives you $300.\n";
		currPokemon->giveExperience(rand()%(29+4*currPokemon->getLevel())+24+4*currPokemon->getLevel());
		player->addMoney(300);
		//award exp and gold (for trainers).
	}
	
}

void Battle::lostMatch(Character* c)
{
	cout << "\nYou wake up dazed and confused in a forest. Your wallet feels lighter." << endl;
	cout << "The voice in your head returns. It says 'All is well. Continue your journey.'\n";
	cout << "'Next time, try using a potion.'" << endl;
	cout << "You find yourself where you first woke up. " << endl<<endl;
	result = false;
	c->setPos(); 
	c->setCurrentPokemon(0);
	for (int i = 0; i < 6; ++i) 
	{
		c->party[i].changeCurrentHealth(999999);
	}
}

int getInt1() {
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
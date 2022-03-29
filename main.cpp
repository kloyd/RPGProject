#include <iostream>
#include <string>
#include <vector>
#include "Mage.h"
#include "Priest.h"
#include "Warrior.h"

using namespace std;

vector<Player*> players;

void printMainMenu();
void printRaceMenu();

Player* createPlayer(string name, int typeNum, int raceNum);
void doCleanup(vector<Player*> playerList);
Race getRace(int number);

void printAll(vector<Player*> playerList);


int main() {

    int professionChoice = -1;
    int raceNumber;
    string playerName;
    Race race;
    Player* tempPlayer;

    while (professionChoice != 0) {
        printMainMenu();
        cin >> professionChoice;
        if (professionChoice > 0 && professionChoice < 4) {
            cout << "What would you like to name your character?" << endl;
            getline(cin, playerName);
            printRaceMenu();
            cin >> raceNumber;
            tempPlayer = createPlayer(playerName, professionChoice, raceNumber);
            players.push_back(tempPlayer);
        } else {
            if (professionChoice != 0)
                cout << "Invalid profession choice, please try again." << endl;
        }
    }

    printAll(players);

    doCleanup(players);

	return 0;
}

void printMainMenu() {
    cout << "Which of the following would you like?" << endl;
    cout << "\t1 - Create a Warrior" << endl;
    cout << "\t2 - Create a Priest" << endl;
    cout << "\t3 - Create a Mage" << endl;
    cout << "\t0 - Finish creating player characters." << endl;
}

void printRaceMenu() {
    cout << "Now, which race do you want?" << endl;
    cout << "\t1 - Human" << endl;
    cout << "\t2 - Elf" << endl;
    cout << "\t3 - Dwarf" << endl;
    cout << "\t4 - Orc" << endl;
    cout << "\t5 - Troll" << endl;
}

Player* createPlayer(string playerName, int typeNum, int raceNum) {
    Race race = getRace(raceNum);
    Player* newPlayer;
    if (typeNum == 1) {
        newPlayer = new Warrior(playerName, race);
    } else if (typeNum == 2) {
        newPlayer = new Priest(playerName, race);
    } else if (typeNum == 3) {
        newPlayer = new Mage(playerName, race);
    }
    return newPlayer;
}

void printAll(vector<Player*> playerList) {
    for (Player* aPlayer : playerList) {
        cout << aPlayer->getName() << ", " << aPlayer->whatRace() << " " << aPlayer->job() << ", attacks! " << aPlayer->attack() << endl;
    }

}

void doCleanup(vector<Player*> playerList) {
    for (Player* aPlayer : playerList) {
        delete aPlayer;
    }
    playerList.clear();
}

Race getRace(int number) {
    if (number == 1) {
        return HUMAN;
    } else if (number == 2) {
        return ELF;
    } else if (number == 3) {
        return DWARF;
    } else if (number == 4) {
        return ORC;
    } else if (number == 5) {
        return TROLL;
    } else {
        return HUMAN;
    }
}

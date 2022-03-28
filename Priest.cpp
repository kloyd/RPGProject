#include "Priest.h"

Priest::Priest(string name, Race race) : Player(name, race, 100, 200) {

}

string Priest::attack() const {
	return "I will assault you with Holy Wrath!";
}

string Priest::job() {
    return "priest";
}
#include "Mage.h"

Mage::Mage(string name, Race race) : Player(name, race, 150, 150) {}

string Mage::attack() const {
    return "I will crush you with the power of my arcane missiles!";
}

string Mage::job() {
    return "mage";
}
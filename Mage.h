#ifndef MAGE_H
#define MAGE_H

#include "Player.h"

class Mage : public Player {
public:
	Mage(string name, Race race);
	string attack() const;
    string job();
};

#endif

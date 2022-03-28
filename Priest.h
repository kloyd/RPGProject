#ifndef PRIEST_H
#define PRIEST_H

#include "Player.h"

class Priest : public Player {
public:
	Priest(string name, Race race);
	string attack() const;
    string job();
};

#endif

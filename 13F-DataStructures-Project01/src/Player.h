/*
 * Player.h
 *
 *  Created on: Sep 14, 2013
 *      Author: Mark Fontenot
 *
 *  Player represents a player on a Laser Tag team.
 */

#include <string>
using namespace std;

/**
 * Represents a player that is on a Laser Tag Team.  Contains an id and
 * playerName which are currently the only attributes of a team.
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
public:
	Player();
	Player(const string& name, int id);
	~Player();


	//setters and getters
	void setName(const string& newName);
	string getName() const;
	void setPlayerId(int);
	int getPlayerId() const;

private:
	int playerId;
	string playerName;
};

#endif /* PLAYER_H_ */

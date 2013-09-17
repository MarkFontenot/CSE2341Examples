/*
 * Team.h
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 *
 *  Team represents a collection of players in laser-tag
 */

#include <string>
#include <vector>
#include <ostream>
#include <istream>
#include <set>
#include "Player.h"
using namespace std;

/**
 * Team represents a set of players.  A team also
 * has a team name.
 */

#ifndef TEAM_H_
#define TEAM_H_

class Team {
public:
	Team();
	virtual ~Team();

	//will read in data from the input stream argument
	//to initialize the team object
	void initializeTeam(istream&);

	//setters and getters
	void setTeamName(const string& name);
	string getTeamName() const;

	//Adds a player to the team given a particular player object.
	void addPlayer(const Player&);

	//Returns the name of a player based on the id argument.
	//TODO throw an exception if id not found on this team.
	string getPlayerNameById(int id) const;

	//prints the contents of this team to an output stream.
	//this is mostly for debugging.
	void print(ostream&);

	//a predicate function that is used to determine if a particular
	//player id is a member of this particular team.
	bool isTeamMember(int id) const
	{
		for(vector<Player>::const_iterator it = players.begin();
				it != players.end();
				++it)
		{
			if(it->getPlayerId() == id)
				return true;
		}
		return false;
	}

private:
	string name;
	vector<Player> players;
};

#endif /* TEAM_H_ */

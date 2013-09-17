/*
 * Match.h
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include "Team.h"
#include "Tag.h"

/**
 * Match represents a match which contains a set of tags.  It is
 * responsible for maintining the tags for a particular match as well
 * as processing the different levels of output.
 */

#ifndef MATCH_H_
#define MATCH_H_

class Match
{
public:
	Match();
	virtual ~Match();

	//load a match from an input stream.
	void loadMatch(istream& in);

	//print output to output stream - mostly used for debugging.
	void printMatch(ostream& out);

	//low verbosity output method that will use team rosters that
	//are arguments.  reduces coupling between match and team.
	void outputLowVerbosity(ostream& out,
			const Team& t1, const Team& t2);

	//using the tags here and team argument, calculates the score
	//for a particular team.
	int getScoreForTeam(const Team& team);

private:
	vector<Tag*> tags;
};

#endif /* MATCH_H_ */

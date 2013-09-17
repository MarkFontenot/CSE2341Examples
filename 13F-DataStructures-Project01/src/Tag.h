/*
 * Tag.h
 *
 *  Created on: Sep 14, 2013
 *      Author: mark
 */

#include "TaggedLocations.h"

/**
 * Tag represents the event when one player
 * tags another player at a particular time
 * on a particular location.  A set of tags will be used
 * to compose a match.
 */

#ifndef TAG_H_
#define TAG_H_

class Tag
{
public:

	Tag();
	Tag(int, int, int, TaggedLocation);

	virtual ~Tag() {}

	//setters
	void setTagger(int);
	void setTagged(int);
	void setTimeStamp(int);
	void setTaggedLocation(TaggedLocation);

	//getters
	int getTagger();
	int getTagged();
	int getTimeStamp();
	TaggedLocation getTaggedLocation();

	//sub classes will implement the getPoints method based on
	//the location.  Here is is pure virtual.
	virtual int getPoints() = 0;

private:
	int tagger;
	int tagged;
	int timeStamp;
	TaggedLocation location;

};

//Represents a particular tag to the shoulder
class ShoulderTag : public Tag
{
public:
	ShoulderTag(int tag, int tagd, int time, TaggedLocation loc):
		Tag(tag, tagd, time, loc) {}

	virtual int getPoints()
	{
		return 10;
	}
};

//Represents a particular tag to the LaserGun
class LaserGunTag : public Tag
{
public:

	LaserGunTag(int tag, int tagd, int time, TaggedLocation loc):
		Tag(tag, tagd, time, loc) {}

	virtual int getPoints()
	{
		return 15;
	}
};

//Represents a particular tag to the Back
class BackTag : public Tag
{
public:

	BackTag(int tag, int tagd, int time, TaggedLocation loc):
		Tag(tag, tagd, time, loc) {}

	virtual int getPoints()
	{
		return 5;
	}
};

//Represents a particular tag to the Chest
class ChestTag : public Tag
{
public:
	ChestTag(int tag, int tagd, int time, TaggedLocation loc):
		Tag(tag, tagd, time, loc) {}

	virtual int getPoints()
	{
		return 8;
	}
};

#endif /* TAG_H_ */

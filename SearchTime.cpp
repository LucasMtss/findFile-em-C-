#include "SearchTime.h"

SearchTime::SearchTime(time_t initialTime, time_t finalTime)
{
	this->initialTime = initialTime;
	this->finalTime = finalTime;
}

time_t SearchTime::getInitialTime() const
{
	return initialTime;
}

void SearchTime::setInitialTime(time_t tempo)
{
	this->initialTime = tempo;
}

time_t SearchTime::getFinalTime() const
{
	return finalTime;
}

void SearchTime::setFinalTime(time_t tempo)
{
	finalTime = tempo;
}

time_t SearchTime::duration()
{
	return finalTime - initialTime;
}

time_t SearchTime::duration(time_t initialTime, time_t finalTime)
{
	return finalTime - initialTime;
}

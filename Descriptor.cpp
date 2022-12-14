#include "Descriptor.h"

Descriptor::Descriptor(string name)
{
	this->name = name;
	size = 0;
	
}

void Descriptor::setName(string name)
{
	this->name = name;
}

string Descriptor::getName() const
{
	return name;
}

void Descriptor::setPath(string path)
{
	this->path = path;
}

string Descriptor::getPath() const
{
	return path;
}

void Descriptor::setSize(uintmax_t size)
{
	this->size = size;
}

uintmax_t Descriptor::getSize() const
{
	return size;
}

void Descriptor::setDate(string date)
{
	this->date = date;
}

string Descriptor::getDate() const
{
	return date;
}

void Descriptor::setHour(string hour)
{
	this->hour = hour;
}

string Descriptor::getHour() const
{
	return hour;
}

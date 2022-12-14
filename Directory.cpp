#include "Directory.h"
#include <typeinfo>

Directory::Directory(string name)
{
	this->descriptors.push_back(Descriptor(name));
	setName(name);
}

void Directory::add(File file)
{
	descriptors.push_back(file);
}

void Directory::add(Directory subdirectory)
{
	descriptors.push_back(subdirectory);
}

optional<File> Directory::findFile(string nameFile)
{
	/*
	for (const auto& item : descriptors) {
		Descriptor descritor = item;
		if(static_cast<File>(descritor))
			if (desc.getName() == nameFile) {
				File arquivo = static_cast<File>(desc);
			}
				return {desc};
	}
	*/
	return nullopt;
}

optional<Directory> Directory::findDirectory(string nameSubdirectory)
{
	for (Descriptor desc : descriptors) {
		if (desc.getName() == nameSubdirectory) {
			Directory encontrado(desc.getName());
			return optional<Directory>(encontrado);
		}
	}
	return optional<Directory>(nullopt);
}

vector<Descriptor> Directory::getDescriptors()
{
	return descriptors;
}

int Directory::getNumeroSubdiretorios()
{
	return numeroSubdiretorios;
}

void Directory::setNumeroSubdiretorios(int numeroSubdiretorios)
{
	this->numeroSubdiretorios = numeroSubdiretorios;
}

int Directory::getNumeroArquivosTexto()
{
	return numeroArquivosTexto;
}

void Directory::setNumeroArquivosTexto(int numeroArquivosTexto)
{
	this->numeroArquivosTexto = numeroArquivosTexto;
}

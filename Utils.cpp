#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <clocale>
#include <filesystem>
#include <fstream>

using namespace std;

unsigned int contarOcorrenciasStringNaLinha(string linha, string palavraPesquisada)
{
	int count = 0;
	size_t posicao = 0;
	string linhaEmMinusculo = converterParaMinusculo(linha), palavraPesquisadaEmMinusculo = converterParaMinusculo(palavraPesquisada);

	while ((posicao = linhaEmMinusculo.find(palavraPesquisadaEmMinusculo, posicao)) != string::npos){
		count++;
		posicao += palavraPesquisadaEmMinusculo.length();
	}

	return count;
}



vector<string> obterLinhasDoTexto(string texto)
{
	vector<string> result;
	stringstream ss(texto);

	string line;
	while (getline(ss, line))
	{
		result.push_back(line);
	}

	return result;
}

string converterParaMinusculo(string texto)
{
	string copiaTexto = texto;
	for (int i = 0; i < texto.size();i++) {
		copiaTexto[i] = tolower(texto[i]);
	}
	return copiaTexto;
}

string obterNomeArquivo(string path)
{
	string delimitador = "/";
	size_t pos = 0;
	std::string token;
	while ((pos = path.find(delimitador)) != std::string::npos) {
		token = path.substr(0, pos);
		path.erase(0, pos + delimitador.length());
	}
	cout << "\n\nPATH " << path << endl << endl;
	return path;
}

string obterExtensaoArquivo(filesystem::path path) {
	if (path.extension() == ".txt")
		return ".txt";
	else return ".log";
}

int obterNumeroSubdiretorios(filesystem::path path)
{
	int subdiretorios = 0;
	for (auto& f : filesystem::directory_iterator(path)) {
		if (f.is_directory()) {
			subdiretorios+=obterNumeroSubdiretorios(f.path());
		}
	}
	return ++subdiretorios;
}

int obterNumeroArquivosTexto(filesystem::path path)
{
	int arquivosTexto = 0;
	for (auto& f : filesystem::directory_iterator(path)) {
		if (f.is_directory()) {
			arquivosTexto += obterNumeroArquivosTexto(f.path());
		}
		else if (f.path().extension() == ".txt" || f.path().extension() == ".log") {
			arquivosTexto++;
		}
	}
	return arquivosTexto;	
}

string obterHorario(time_t tempo)
{
	cout << "\n\nTEMPO  " << tempo << endl << endl;
	struct tm newtime;
	localtime_s(&newtime, &tempo);

	int hora = newtime.tm_hour;
	int min = newtime.tm_min;
	int sec = newtime.tm_sec;

	return to_string(hora) + ":" + to_string(min) + ":" + to_string(sec);
}

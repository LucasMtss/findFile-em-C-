#include <iostream>
#include <cstdlib>
#include <clocale>
#include <filesystem>
#include <fstream>
#include <ctime>
#include "FindFile.h"
#include "Erros.h"
#include "Utils.h"

using namespace std;

int FindFile::findFile(string searchString, string directory)
{
	File file(directory);
	filesystem::path arquivo(directory);
	file.setSize(filesystem::file_size(directory));
	int totalOcorrencias = 0, numeroLinha = 0;
	printMessagem(directory);
	
	ifstream arquivoAberto(directory);
	string conteudoArquivo((istreambuf_iterator<char>(arquivoAberto)), (istreambuf_iterator<char>()));
	vector<string> splitTexto = obterLinhasDoTexto(conteudoArquivo);
	for (string linha : splitTexto) {
		int ocorrencias = contarOcorrenciasStringNaLinha(linha, searchString);
		file.adicionarLinha(++numeroLinha, ocorrencias);
		totalOcorrencias += ocorrencias;
	}
	FileType tipoArquivo = obterExtensaoArquivo(directory) == ".txt" ? FileType::TXT : FileType::LOG;
	file.setFileType(tipoArquivo);
	this->directory.add(file);
	return totalOcorrencias;
}

int FindFile::findFile(string searchString, Directory directory)
{
	int ocorrenciasPalavra = 0;
	for (auto& f : filesystem::directory_iterator(directory.getName())) {
		uintmax_t tamanhoArquivos = 0;
		if (f.is_directory()) {
			Directory novoDiretorio = Directory(f.path().generic_string());
			novoDiretorio.setNumeroSubdiretorios(obterNumeroSubdiretorios(f.path()));
			novoDiretorio.setNumeroArquivosTexto(obterNumeroArquivosTexto(f.path()));
			this->directory.add(novoDiretorio);
			ocorrenciasPalavra += findFile(searchString, Directory(f.path().generic_string()));
		}
		else if (f.path().extension() == ".txt" || f.path().extension() == ".log") {
			ocorrenciasPalavra += findFile(searchString, f.path().generic_string());
		}
	}
	return ocorrenciasPalavra;
}


optional<Directory> FindFile::readDirectory(string directory)
{
	time_t inicio, fim;
	searchTime.setInitialTime(time(&inicio));
	filesystem::path diretorio(directory);
	this->directory = Directory(directory);
	this->directory.setNumeroSubdiretorios(obterNumeroSubdiretorios(diretorio));
	this->directory.setNumeroArquivosTexto(obterNumeroArquivosTexto(diretorio));
	cout << diretorio << endl << endl;
	for (auto& f : filesystem::directory_iterator(diretorio)) {
		uintmax_t tamanhoArquivos = 0;
		if (f.is_directory()) {
			findFile(searchString, Directory(f.path().generic_string()));
		}
		else if (f.path().extension() == ".txt" || f.path().extension() == ".log") {
			this->directory.add(File(f.path().generic_string()));
			findFile(searchString, f.path().generic_string());
		}

	}
	Directory diretorioRaiz = this->directory;
	searchTime.setFinalTime(time(&fim));
	return optional<Directory>(diretorioRaiz);
}

bool FindFile::createLogFile(string nameFile)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	int dia = newtime.tm_mday;
	int mes = newtime.tm_mon + 1;
	int ano = newtime.tm_year + 1900;

	int hora = newtime.tm_hour;
	int min = newtime.tm_min;
	int sec = newtime.tm_sec;

	cout << "Arquivo findeFile.log criado em " << dia << "/" << mes << "/" << ano << " às " << hora << ":" << min << endl << endl;
	cout << "String pesquisada: \"" << searchString << "\"" << endl << endl;
	return false;
}

void FindFile::showReport(Directory directory, SearchTime searchTime)
{
	cout << "- Diretório: \"" << directory.getName() << "\"" << endl << endl;

	cout << "- Conteúdo do diretório: " << endl;
	cout << "\tArquivos de texto pesquisados: " << obterNumeroArquivosTexto(directory.getName()) << endl;
	cout << "\tNúmero total de subdiretórios: " << obterNumeroSubdiretorios(directory.getName()) << endl << endl;
	cout << "- Tempo da pesquisa: " << endl;
	cout << "\tInício  : " << obterHorario(searchTime.getInitialTime()) << endl;
	cout << "\tTérmino : " << obterHorario(searchTime.getFinalTime()) << endl;
	cout << "\tDuração : " << obterHorario(searchTime.duration()) << endl;
	findFile(searchString, directory.getDescriptors());
}

void FindFile::setSearchString(string searchString)
{
	this->searchString = searchString;
}

int FindFile::findFile(string searchString, vector<Descriptor> files)
{
	
	return 0;
}

void FindFile::printMessagem(string nameFile)
{
	cout << "\tPesquisando no arquivo " << obterNomeArquivo(nameFile) << endl << endl;
}

bool validarNumeroDeArgumentos(int numeroDeArgumentos) {
	if (numeroDeArgumentos > 4 || numeroDeArgumentos < 2)
		return false;
	return true;
}

int testarFindFile(int argc, char* argv[]) {
	setlocale(LC_ALL, "pt-br");
	string nomeDiretorio, palavraBuscada = "teste";
	if (!validarNumeroDeArgumentos(argc)) {
		cout << ERRO_NUMERO_ARGUMENTOS;
		return EXIT_FAILURE;
	}
	if (argc == 4) {
		palavraBuscada = argv[2];
		nomeDiretorio = argv[3];
	}
	FindFile ff = FindFile();
	ff.setSearchString(palavraBuscada);
	cout << palavraBuscada << endl << nomeDiretorio << endl << endl;

	optional<Directory> opt = ff.readDirectory(nomeDiretorio);
	Directory raiz = opt.value();
	optional<Directory> buscado = raiz.findDirectory(nomeDiretorio);

	ff.showReport(buscado.value(), SearchTime());

	return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
	return testarFindFile(argc, argv);
}

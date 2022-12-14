#pragma once

#include "Directory.h"
#include "SearchTime.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/* Representa os serviços do programa findfile. 

   Nota: O template de classe optional representa um objeto que pode ter um valor opcional, ou seja, 
         um valor que pode ou não está presente no objeto.
		 Veja detalhes em: https://en.cppreference.com/w/cpp/utility/optional
*/ 
class FindFile {
public:
	FindFile() = default;

	/* Pesquisa a string em todos os arquivos do diretório. O tipo dos arquivos é definido por File::FILE_TYPE.
	   Retorna o número de arquivos em que a string foi localizada no diretório e/ou subdiretórios ou -1 se não achá-la em nenhum arquivo.
	*/ 
	int findFile(string searchString, string directory);

	/* Pesquisa a string em todos os arquivos do diretório. O tipo dos arquivos é definido por File::FILE_TYPE.
	   Retorna o número de arquivos em que a string foi localizada no diretório e/ou subdiretórios ou -1 se não achá-la em nenhum arquivo.
	*/
	int findFile(string searchString, Directory directory);

	/* Lê o conteúdo do diretório.
	   Cria um objeto File para cada arquivo, um objeto Directory para o diretório da linha de comando e para cada um de seus subdiretórios. 
	   Retorna o diretório com todos os seus atributos.
	*/
	optional<Directory> readDirectory(string directory);

	// Cria o arquivo de log com nome definido por nameFile. Retorna true se o arquivo foi criado com sucesso e false em caso de erro.
	bool createLogFile(string nameFile);

	// Exibe o relatório com o tempo da pesquisa, nome e conteúdo do diretório pesquisado. 
	void showReport(Directory directory, SearchTime searchTime);

	void setSearchString(string searchString);


private:
	// String a ser pesquisada nos arquivos.
	string searchString;

	// Diretório fornecido como parâmetro para o programa findfile.
	Directory directory;

	// Tempo da pesquisa realizada no diretório.
	SearchTime searchTime;

	/* Pesquisa a string em todos os arquivos do vector files. O tipo dos arquivos é definido por File::FILE_TYPE.
	   Retorna o número de arquivos em que a string foi localizada ou -1 se não achá-la em nenhum arquivo.
	*/
	int findFile(string searchString, vector<Descriptor> files);

	// Exibe a mensagem "Pesquisando no arquivo <nomeArquivo>..." e um std::endl, onde <nomeArquivo> é substituído por nameFile.
	void printMessagem(string nameFile);
};
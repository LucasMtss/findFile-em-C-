#pragma once

#include "Descriptor.h"
#include <vector>

enum class FileType { LOG, TXT };

// Representa um arquivo do sistema de arquivos.
class File : public Descriptor {
public:
	const string LOG = "log", TXT = "txt";

	File() = default;
	File(string name);
	
	void setFileType(FileType fileType);
	FileType getFileType() const;

	// Retorna o tipo ou extensão do arquivo.
	string getFileType(FileType fileType) const;

	// Acrescenta a linha onde foi encontrada uma palavra
	void adicionarLinha(int numeroLinha, int ocorrencias);


private:
	// Linhas onde foram encontradas a palavra pesquisada
	vector<int> linhasPalavras;
	// Número de ocorrências da palavra pesquisada
	int ocorrenciasPalavraPesquisada;
	// Tipo do arquivo.
	FileType fileType;
};
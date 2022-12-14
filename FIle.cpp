#include "File.h"

File::File(string name)
{
	Descriptor::setName(name);
	fileType = FileType::TXT;
}

void File::setFileType(FileType fileType)
{

}

FileType File::getFileType() const
{
	return this->fileType;
}

string File::getFileType(FileType fileType) const
{
	if (fileType == FileType::LOG)
		return "."+LOG;
	else return "."+TXT;
}

void File::adicionarLinha(int numeroLinha, int ocorrencias)
{
	linhasPalavras.push_back(numeroLinha);
	ocorrenciasPalavraPesquisada += ocorrencias;
}

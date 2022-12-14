#include <iostream>
#include <clocale>
#include <cstdlib> 
#include <vector>
#include "TestarArquivoTexto.h"

/*
int main() {
	return testarArquivoTexto();
}
*/

int testarArquivoTexto() {
	setlocale(LC_ALL, "pt-BR");

	// A letra L maiúscula é usada para definir uma string literal do tipo wstring.
	vector<wstring> texto1 = { L"Água", L"Fogo", L"Terra", L"Ar", L"Esses são os quatro elementos." };
	vector<wstring> texto2 = { L"Comunicação", L"História", L"Computação" };

	exibir("Investimentos - ANSI", ARQUIVO_TXT_INVESTIMENTOS_ANSI, "pt-BR");
	exibir("Investimentos - UTF-8", ARQUIVO_TXT_INVESTIMENTOS_UTF8, UTF_8);

	escrever(ARQUIVO_TXT_PALAVRAS, texto1, UTF_8);
	exibir("- Escrita e Leitura", ARQUIVO_TXT_PALAVRAS, UTF_8);

	adicionar(ARQUIVO_TXT_PALAVRAS, texto2, UTF_8);
	exibir("- Atualização e Leitura", ARQUIVO_TXT_PALAVRAS, UTF_8);

	arquivoTextoComTamanhoFixo();

	cout << endl;
	return EXIT_SUCCESS;
} 

/* Cria um arquivo texto no diretório atual. Os parâmetros são:

	- nomeArquivo: nome do arquivo texto;
	- texto: vector de wstring a serem escritas no arquivo;
	- codificacao: codificação usada apenas para escrever o texto no arquivo, p. ex., UTF-8 ou pt-BR.
*/
void escrever(string nomeArquivo, vector<wstring> texto, string codificacao)
{
	ArquivoTexto arquivoTexto;

	arquivoTexto.abrir(nomeArquivo, TipoDeAcesso::ESCRITA);

	// Escreve o conteúdo do array no arquivo.
	for (const auto& frase : texto)
		arquivoTexto.escrever(frase, codificacao);

	arquivoTexto.fechar();
} 

/* Cria um arquivo texto no diretório atual. Os parâmetros são:

	- nomeArquivo: nome do arquivo texto;
	- texto: wstring a ser escrita no arquivo;
	- codificacao: codificação usada apenas para escrever o texto no arquivo, p. ex., UTF-8 ou pt-BR.
*/
void escrever(string nomeArquivo, wstring texto, string codificacao) {
	vector<wstring> textoVector(1, texto);

	escrever(nomeArquivo, textoVector, codificacao);
}

/* Adiciona novas linhas de texto no arquivo. Os parâmetros são:

	- nomeArquivo: nome do arquivo texto;
	- texto: conteúdo a ser escrito no arquivo;
	- codificacao: codificação usada apenas para adicionar o texto no arquivo, p. ex., UTF-8 ou pt-BR.
*/
void adicionar(string nomeArquivo, vector<wstring> texto, string codificacao)
{
	ArquivoTexto arquivoTexto;

	arquivoTexto.abrir(nomeArquivo, TipoDeAcesso::ACRESCENTAR);

	// Escreve o conteúdo do array no arquivo.
	for (const auto& frase : texto)
		arquivoTexto.escrever(frase, codificacao);

	arquivoTexto.fechar();
} 

/* Abre e exibe o arquivo texto. Os parâmetros são:

	- mensagem: conteúdo a ser exibido;
	- nomeArquivo: nome do arquivo texto;
	- codificacao: codificação usada apenas para ler o texto do arquivo, p. ex., UTF-8 ou pt-BR.
*/
void exibir(string mensagem, string nomeArquivo, string codificacao)
{
	ArquivoTexto arquivoTexto;

	arquivoTexto.abrir(nomeArquivo, TipoDeAcesso::LEITURA);

	cout << mensagem << "\nArquivo: " << arquivoTexto.getNomeArquivo() << "\n\n";

	// O wcout deve ser usado para exibir objetos wstring.
	wcout<< arquivoTexto.ler(codificacao) << "\n\n";

	arquivoTexto.fechar();
}

/* Exemplifica como realizar um acesso aleatório ou direto com arquivo texto em que todas as 
   linhas possuem o mesmo comprimento (número de caracteres).
 */
void arquivoTextoComTamanhoFixo()
{
	/* Neste exemplo, o tamanho padrão da linha inclui 5 dígitos e os caracteres de controle LF/CR.
	   Esses caracteres são introduzidos no fim de cada linha de texto no Windows. Eles correspondem a tecla ENTER.
	*/
	const int TAMANHO_PADRAO_DA_LINHA = 7;

	vector<wstring> codigos = { L"C0100", L"C0101", L"C0102", L"C0103", L"C0104", L"C0105" };
	wstring linhas[6];

	escrever(ARQUIVO_TXT_CODIGOS, codigos, "pt-BR");
	exibir("- Escrita e Leitura", ARQUIVO_TXT_CODIGOS, "pt-BR");

	ArquivoTexto arquivoTexto;
	arquivoTexto.abrir(ARQUIVO_TXT_CODIGOS, TipoDeAcesso::LEITURA);

	cout << "- Conteúdo invertido do arquivo " << ARQUIVO_TXT_CODIGOS << ":\n\n";
	for (int lin = _countof(linhas) - 1; lin >= 0; lin--)
	{
		/* O parâmetro passado para a função ler da classe ArquivoTexto é calculado
		     passando o deslocamento em bytes a partir do início de cada linha de texto. 
		     Este deslocamento é calculado com base no TAMANHO_PADRAO_DA_LINHA.
		*/
	    linhas[lin] = arquivoTexto.ler(lin * TAMANHO_PADRAO_DA_LINHA);
		wcout << "  Linha " << (lin + 1) << ": " << linhas[lin] << endl;
	}
	arquivoTexto.fechar();
}
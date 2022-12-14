#ifndef TESTAR_ARQUIVO_TEXTO
#define TESTAR_ARQUIVO_TEXTO

#include "ArquivoTexto.h"

const string ARQUIVO_TXT_PALAVRAS = "arquivos\\Palavras.txt",
			 ARQUIVO_TXT_CODIGOS = "arquivos\\Codigos.txt",
	         ARQUIVO_TXT_INVESTIMENTOS_UTF8 = "arquivos\\Investimentos-UTF-8.txt",
			 ARQUIVO_TXT_INVESTIMENTOS_ANSI = "arquivos\\Investimentos-ANSI.txt";

/* Cria um arquivo texto no diretório atual. Os parâmetros são:

	- nomeArquivo: nome do arquivo texto;
	- texto: vector de wstring a serem escritas no arquivo;
	- codificacao: codificação usada apenas para escrever o texto no arquivo, p. ex., UTF-8 ou pt-BR.
*/
void escrever(string nomeArquivo, vector<wstring> texto, string codificacao);

/* Cria um arquivo texto no diretório atual. Os parâmetros são:

	- nomeArquivo: nome do arquivo texto;
	- texto: wstring a ser escrita no arquivo;
	- codificacao: codificação usada apenas para escrever o texto no arquivo, p. ex., UTF-8 ou pt-BR.
*/
void escrever(string nomeArquivo, wstring texto, string codificacao);

/* Adiciona novas linhas de texto no arquivo. Os parâmetros são:

	- nomeArquivo: nome do arquivo texto;
	- texto: conteúdo a ser escrito no arquivo;
	- codificacao: codificação usada apenas para adicionar o texto no arquivo, p. ex., UTF-8 ou pt-BR.
*/
void adicionar(string nomeArquivo, vector<wstring> texto, string codificacao);

/* Abre e exibe o arquivo texto. Os parâmetros são:

	- mensagem: conteúdo a ser exibido;
	- nomeArquivo: nome do arquivo texto;
	- codificacao: codificação usada apenas para ler o texto do arquivo, p. ex., UTF-8 ou pt-BR. 
*/
void exibir(string mensagem, string nomeArquivo, string codificacao);

/* Exemplifica como realizar um acesso aleatório ou direto com arquivo texto em que todas as linhas 
   possuem o mesmo comprimento (número de caracteres).
 */
void arquivoTextoComTamanhoFixo();

// Testa o funcionamento dos métodos da classe ArquivoTexto.
int testarArquivoTexto();

#endif
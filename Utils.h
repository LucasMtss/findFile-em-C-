#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <filesystem>

using namespace std;

// Conta o n�mero de ocrr�ncias da string pesquisada em uma linha
unsigned int contarOcorrenciasStringNaLinha(string linha, string palavraPesquisada);

// Separa um texto pelas quebras de linha
vector<string> obterLinhasDoTexto(string texto);

// Converte string para min�sculo
string converterParaMinusculo(string texto);

// Ot�m nome do arquivo a partir do seu path
string obterNomeArquivo(string path);

// Obtem uma string com a extens�o do arquivo em .log ou .txt
string obterExtensaoArquivo(filesystem::path path);

// Obtem n�mero de subdiret�rios em um diret�rio
int obterNumeroSubdiretorios(filesystem::path path);

// Obtem n�mero de arquivos texto em um diret�rio
int obterNumeroArquivosTexto(filesystem::path path);

// Obt�m hor�rio formatado
string obterHorario(time_t tempo);
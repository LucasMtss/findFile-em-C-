#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <filesystem>

using namespace std;

// Conta o número de ocrrências da string pesquisada em uma linha
unsigned int contarOcorrenciasStringNaLinha(string linha, string palavraPesquisada);

// Separa um texto pelas quebras de linha
vector<string> obterLinhasDoTexto(string texto);

// Converte string para minúsculo
string converterParaMinusculo(string texto);

// Otém nome do arquivo a partir do seu path
string obterNomeArquivo(string path);

// Obtem uma string com a extensão do arquivo em .log ou .txt
string obterExtensaoArquivo(filesystem::path path);

// Obtem número de subdiretórios em um diretório
int obterNumeroSubdiretorios(filesystem::path path);

// Obtem número de arquivos texto em um diretório
int obterNumeroArquivosTexto(filesystem::path path);

// Obtém horário formatado
string obterHorario(time_t tempo);
// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Cauan Marques Santos
//  email: cauanmarqs@gmail.com
//  Matrícula: 20251160040
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>
#include <string.h>

int converter (char texto[]) {
    int i;
	int numero = 0;

    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= '0' && texto[i] <= '9') {
            numero = numero * 10 + (texto[i] - '0');
        } else {
            return -1;
        }
    }

    return numero;
}

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){

	int datavalida = 1;
	int tam = strlen(data);
	int i, j = 0;
	char sDia[3];
	char sMes[3];
	char sAno[5];
	int dia, mes, ano;
	
	
	
	for ( i = 0; i < tam && data[i] != '/'; i++){
		if (j < 2){
			sDia[j++] = data[i];
	}
		else{
		datavalida = 0;
		}
	}
	sDia[j] = '\0';
	
	if (data[i] != '/'){
		datavalida = 0;
	}
	
	i++;
	j = 0;
	
	for (; i < tam && data[i] != '/'; i++){
		if (j < 2){
			sMes[j++] =  data[i];
		} else {
		datavalida = 0;
		}
	}
	sMes[j] = '\0';
	
	if (data[i] != '/'){
		datavalida = 0;
	}
	
	i++;
	j = 0;
	
	for (; i<tam; i++){
		if (j < 4){
			sAno[j++] = data[i];
		} else {
			datavalida = 0;
		}
	}
	sAno[j] = '\0';
	
	dia = converter(sDia);
	mes = converter(sMes);
	
	if (strlen(sAno) == 4){
	ano = converter(sAno);
	} else if (strlen(sAno) == 2){
		ano = converter(sAno) + 2000;
	}
	
	if (mes < 1 || mes > 12) 
	datavalida = 0;
		else if (dia < 1 || dia > 31) 
		datavalida = 0;
			else {
    		if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
       			if (dia > 30) 
				datavalida = 0;
   					} else if (mes == 2) {
      				int bissexto = (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
       					if (bissexto && dia > 29) 
						datavalida = 0;
        					else if (!bissexto && dia > 28) 
							datavalida = 0;
    }	
}
	
	 if (datavalida)
      return 1;
  else
      return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

typedef struct DiasMesesAnos {
	
	int qtdDias;
	int qtdMeses;
	int qtdAnos;
	int retorno;
	
} DiasMesesAnos;

DiasMesesAnos q2(char datainicial[], char datafinal[])
{

   DiasMesesAnos dma;
	int Dia1, Mes1, Ano1;
	int Dia2, Mes2, Ano2;
	char aux[3], aux2[5];
	int tam = strlen(datainicial);
	int tam2 = strlen(datafinal);
	int j = 0;
	int i=0;
	
	if (q1(datainicial) == 0){
		dma.retorno = 2;
		return dma;
	}
	
	if (q1(datafinal) == 0){
		dma.retorno = 3;
		return dma;
	}
	
	for (i=0; i<tam && datainicial[i] != '/'; i++){
		if (j<2){
			aux[j++] = datainicial[i];
		}
	}
	aux[j] = '\0';
	
	Dia1 = converter(aux);
	
	if (datainicial[i] != '/'){
		dma.retorno = 1;
		return dma;
	}
	
	i++;
	j = 0;
	
	for (; i<tam && datainicial[i] != '/'; i++){
		if (j<2){
			aux[j++] = datainicial[i];
		}
	}
	aux[j] = '\0';
	
	Mes1 = converter(aux);
	
	if (datainicial[i] != '/'){
		dma.retorno = 1;
		return dma;
	}
	
	i++;
	j = 0;
	
	for (; i<tam; i++){
		if (j < 4){
			aux2[j++] = datainicial[i];
		} else {
			dma.retorno = 1;
			return dma;
		}
	}
	aux2[j] = '\0';
	
	if (strlen(aux2) == 4){
	Ano1 = converter(aux2);
	} else if (strlen(aux2) == 2){
		Ano1 = converter(aux2) + 2000;
	}
	
	j = 0;
	
	for (i=0; i<tam2 && datafinal[i] != '/'; i++){
		if (j<2){
			aux[j++] = datafinal[i];
		}
	}
	aux[j] = '\0';
	
	Dia2 = converter(aux);
	
	if (datafinal[i] != '/'){
		dma.retorno = 2;
		return dma;
	}
	
	i++;
	j = 0;
	
	for (; i<tam2 && datafinal[i] != '/'; i++){
		if (j<2){
			aux[j++] = datafinal[i];
		}
	}
	aux[j] = '\0';
	
	Mes2 = converter(aux);
	
	if (datafinal[i] != '/'){
		dma.retorno = 2;
		return dma;
	}
	
	i++;
	j = 0;
	
	for (; i<tam2; i++){
		if (j < 4){
			aux2[j++] = datafinal[i];
		} else {
			dma.retorno = 2;
			return dma;
		}
	}
	aux2[j] = '\0';
	
	if (strlen(aux2) == 4){
	Ano2 = converter(aux2);
	} else if (strlen(aux2) == 2){
		Ano2 = converter(aux2) + 2000;
	}
	
	if (Ano1 > Ano2 || (Ano1 == Ano2 && Mes1 > Mes2) || (Ano1 == Ano2 && Mes1 == Mes2 && Dia1 > Dia2)) {
        dma.retorno = 4;
        return dma;
    }
    
    int diasPorMes[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int bissexto = (Ano2 % 400 == 0) || (Ano2 % 4 == 0 && Ano2 % 100 != 0);
	
	if (bissexto){
	diasPorMes[1] = 29;
	}
	
	int d1 = Dia1, d2 = Dia2; 
	int m1 = Mes1, m2 = Mes2; 
	int a1 = Ano1, a2 = Ano2;

    int dias = d2 - d1;
    int meses = m2 - m1;
    int anos = a2 - a1;

    if (dias < 0) {
        meses -= 1;
        int mesAnterior = (m2 - 2 + 12) % 12;
        if (mesAnterior < 0){
			mesAnterior += 12;
		}
        dias += diasPorMes[mesAnterior];
    }

    if (meses < 0) {
        anos -= 1;
        meses += 12;
    }

    dma.qtdDias = dias;
    dma.qtdMeses = meses;
    dma.qtdAnos = anos;
    dma.retorno = 1;

    return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    
	int qtdOcorrencias = -1;
	int ocorrencia = 0;
	int tam = strlen(texto);
	
	if (isCaseSensitive != 1){	
		if (c >= 65 && c <= 90){
			for (int i=0; i<tam; i++){
			if (texto[i] >= 'a' && texto[i] <= 'z'){
				texto[i] = texto[i] - 32;
				}
			}
			for (int i=0; i<tam; i++){
			if (texto[i] == c){
				ocorrencia++;
				}
			}
		}
		
			if (c >= 97 && c <= 122){
				for (int i=0; i<tam; i++){
					if (texto[i] >= 'A' && texto[i] <= 'Z'){
						texto[i] = texto[i] + 32;
					}
				}
				for (int i=0; i<tam; i++){
					if (texto[i] == c){
						ocorrencia++;
						}
					}
				}
	
	qtdOcorrencias = ocorrencia;
	return qtdOcorrencias;
}

	if (isCaseSensitive == 1){
		for (int i=0; i<tam; i++){
			if (texto[i] == c){
				ocorrencia++;
			}
		}
	qtdOcorrencias = ocorrencia;
	return qtdOcorrencias;
	}
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
     int achou;
     return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
} 
}

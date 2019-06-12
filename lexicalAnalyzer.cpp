//--- Analizador Léxico implementado na disciplina de Compiladores - Ciência da Computação - UTFPR/PG
//--- Felipe Felix Ducheiko - RA: 1591363
//--------------INSTRUÇÕES--------------
//--- Insirir o código que deve ser analizado e acrescentrar um ~ para indicar o fim do código. Caso contrário
//--- um erro de falha de segmentação acontecerá.
//--- A saída consiste nos tokens identificados e na respectiva Tabela de Símbolos.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000
#define RW 22

using namespace std;
char symbolTable[1023][1023]; //Armazena os dados da tabela de Simbolos
int ID = 0; //Contator incrementado a cada novo elemento da tabela de Simbolos
char CODE[SIZE]; //Armazena o código que será analizado
int I = 0; //Variável usada para percorrer a String CODE
char *reservedWord[RW] = {
  "begin", "if", "then", "while", "do", "end", "include", "using", "namespace", "std", "for", "define", "char",
  "int", "void", "double", "break", "switch", "case", "cout", "cin", "main"
}; // Vetor de palavras reservadas definidas

//Retorna 1 se o char recebido for uma letra
//Retorna 0 caso contrário
int letter(char c)
{
  if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    return 1;
  else
    return 0;
}

//Retorna 1 se o char recebido for uma número
//Retorna 0 caso contrário
int number(char c)
{
  if(c >= '0' && c <= '9')
    return 1;
  else
    return 0;
}

//Verifica se o Token identificado é uma palavra reservada
//Retorna 1 se é uma palavra reservada
//Retorna 0 caso contrário
int checkReservedWord(){
  for (int j = 0; j < RW; j++) {
    if (strcmp(symbolTable[ID], reservedWord[j]) == 0){
      return 1;
    }
  }
  return 0;
} 

//Verifica se é uma vaviável (identificador)
void checkVariable(){
  char c = CODE[I];
  int j = 0;

  //Primeiro if garante que uma variável não se inicia com número
  if (letter(c)){
      symbolTable[ID][j] = CODE[I];
      j++;

      I++;
      c = CODE [I];
      while (letter(c) || number(c)){
        symbolTable[ID][j] = c;
        j++;
        I++;
        c = CODE[I];
      }

      if (!(letter(c) || number(c))){
        symbolTable[ID][j] = '\0';
        j = 0;
        
        //Usando a função checkReservedWord define se é um Identificador ou Palavra reservada
        if (checkReservedWord()){
          cout << "<" << symbolTable[ID] << ">" << endl;
          
          ID++;
        } else {
          cout << "<" << "ID, " << ID << ">" << endl;
          
          ID++;
        } 
      }
     }
}

//Verifica se é um número (Constante)
void checkNumber(){
  char c = CODE[I];
  int j = 0;

  while (number(c)){
    symbolTable[ID][j] = c;
    j++;
    I++;
    c = CODE[I];

    if (!(number(c))){
    symbolTable[ID][j] = '\0';
    j = 0;
    cout << "<" << symbolTable[ID] << ">" << endl;
    ID++;
    }
  }
        
}

//Verifica se é uma String
void checkString(){
  char c = CODE[I];
  int j = 0;

  if (c == '"'){
    I++;
    c = CODE[I];
    
    while (c != '"'){
      symbolTable[ID][j] = c;
      j++;
      I++;
      c = CODE[I];
    }

    cout << "<" << "ID, " << ID << ">" << endl;
    ID++;
  }

}

void printSymbolTable(){

  cout << endl << endl << "TABELA DE SIMBOLOS" << endl;

  cout << "ID" << " --> " << "Symbol" << endl;

  for (int j = 0; j < ID ; j++){
    cout << j << " --> " << symbolTable[j] << endl;
  }
}

int main() {
  char c = ' ';

  cout << "ANALIZADOR LEXICO" << endl;
  cout << "Exemplo de entrada:" << endl << "int position = initial + rate * 60;" << endl << "~" << endl << endl;
  
  cout << "Insira o codigo: (Acrescentrar ~ para indicar o fim do código" << endl;
  //Le o código
  while(c != '~') {
    c = getchar();
    CODE[I] = c;
    I++;
  }
  // \0 indica o fim da String
  CODE[--I] = '\0';

  cout << endl << endl << "TOKENS" << endl;
  
  //Laço principal que percorreo o vetor código usando a variável I
  for (I = 0; CODE[I] != '\0'; I++){
     
    checkVariable();

    checkNumber();

    checkString();

    c = CODE[I];

    //Utilizado para identificar Operadores e Simbolos especiais
    switch(c){
    case'<':
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'>':
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case':':
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'+':
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'-':
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'*': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'/': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case';': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'(': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case')': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'{': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'}': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'[': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case']': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'#': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;

    case'=': 
      symbolTable[ID][0] = c;
      symbolTable[ID][1] = '\0';
      cout << "<" << symbolTable[ID] << ">" << endl;
      ID++;
      break;
    }
  }

  printSymbolTable();

}
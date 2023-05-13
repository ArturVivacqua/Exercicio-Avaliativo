#include <stdio.h>
#include "functions.h"
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main(void) {
  setlocale(LC_ALL, "portuguese");

  int opcao, continua = 1;

  while(continua == 1){
  printf("\nMENU:\n");
  printf("\n1 - Incluir novo usuário");
  printf("\n2 - Editar usuário");
  printf("\n3 - Excluir usuário");
  printf("\n4 - Buscar usuário");
  printf("\n5 - Mostrar todos os usuários cadastrados");
  printf("\n6 - Restaurar usuários excluídos");
  printf("\n7 - Sair");
  printf("\n");
  printf("\nEscolha a opção desejada:\t");
  scanf("%d", &opcao);
    while (opcao < 1 || opcao > 7){
     printf("\nEscolha uma opção válida:\t");
     scanf("%d", &opcao);
    }
 printf("\033c");
 switch(opcao){
    case 1: 
     incluirusuario();
    break;
    case 2:
     editarusuario();
    break;
    case 3:
     excluirUsuario();
    break;
    case 4:
     buscarUsuario();
    break;
    case 5:
      listaUsuario();
    break;
    case 6:
      backup();
    break;
    case 7:
    break;


  }
   printf("\033c");
   if (opcao == 7){
     printf("\nCerteza que deseja sair? (1 - Não | 2 - Sim)\t");
     scanf("%d", &continua);
     printf("\033c");
   }
   else{
     printf("\nDeseja voltar ao menu? (1 - Sim | 2 - Não)\t");
     scanf("%d", &continua);
     printf("\033c");
   }
  }

  printf("\nAté a próxima!\n");
  return 0;
}
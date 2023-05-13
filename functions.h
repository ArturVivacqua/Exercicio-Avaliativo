#include <stdio.h>
#include "struct.h"
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "flush.h"

int nusuarios = 0, nusuarios2 = 0;
Usuario usuarios[1000], usuarios2[1000];

//CASE 1:
void incluirusuario(){
setlocale(LC_ALL, "portuguese");

Usuario novousuario;
  
  if (nusuarios >=1000){
    printf("\nLimite de usuários atingido.");
  }
  else{
    printf("\nCADASTRO:\n");
    novousuario.id = rand() % 90000 + 10000;
    printf("\nID: %d\n", novousuario.id);
    printf("\nNome:\t");
    scanf(" %100[^\n]s", novousuario.nome);
    printf("\n");
    int x = 0;
    while (!x) {
      printf("\nEmail:\t");
      scanf(" %100[^\n]s", novousuario.email);

      x = (strchr(novousuario.email, '@') != NULL);
      if (!x) {
         printf("\nE-mail inválido! Digite novamente.\n");
       }
    }
    printf("\n");
    fgets(novousuario.sexo, sizeof(novousuario.sexo), stdin);
    novousuario.sexo[strcspn(novousuario.sexo, "\n")] = '\0'; 
    while (strcasecmp(novousuario.sexo, "masculino") != 0 && strcasecmp(novousuario.sexo, "feminino") != 0 && strcasecmp(novousuario.sexo, "indiferente") != 0) {
        printf("\nDigite o gênero (Masculino, Feminino ou Indiferente):\t");
        fgets(novousuario.sexo, sizeof(novousuario.sexo), stdin);
        novousuario.sexo[strcspn(novousuario.sexo, "\n")] = '\0';
    }
    
    printf("\n");
    printf("\nEndereço:\t");
    scanf(" %100[^\n]s", novousuario.endereco);
    printf("\n");
    printf("\nAltura (De 1 a 2 metros):\t");
    scanf("%lf", &novousuario.altura);
      while (novousuario.altura < 1 || novousuario.altura > 2){
        printf("\nDigite uma altura válida (De 1 a 2 metros):\t");
        scanf("%lf", &novousuario.altura);
      }
    printf("\n");
    printf("\nVacinado? (1 - Sim | 2 - Não):\t");
    scanf(" %d", &novousuario.vacina);
      while (novousuario.vacina != 1 && novousuario.vacina != 2){
        printf("\nDigite um valor válido. Vacinado? (1 - Sim | 2 - Não):\t");
        scanf(" %d", &novousuario.vacina);
      }
    printf("\n");

    usuarios[nusuarios++] = novousuario;
    usuarios2[nusuarios2++] = novousuario;

    printf("\nUsuário cadastrado com sucesso!\n");
    sleep(3);
  }
}

//CASE 2:

void editarusuario() {
    int id;
    printf("Digite o ID do usuário que deseja editar: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < nusuarios; i++) {
        if (usuarios[i].id == id) {
            printf("\nNovo nome completo:\t");
            scanf(" %100[^\n]s", usuarios[i].nome);
            usuarios[i].nome[strcspn(usuarios[i].nome, "\n")] = '\0'; 
            printf("\n");
            int x = 0;
            while (!x) {
             printf("\nNovo email:\t");
             scanf(" %100[^\n]s", usuarios[i].email);

            x = (strchr(usuarios[i].email, '@') != NULL);
            if (!x) {
            printf("\nE-mail inválido! Digite novamente.\n");
          }
        }
            printf("\n");
            fgets(usuarios[i].sexo, sizeof(usuarios[i].sexo), stdin);
            usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0'; 
              while (strcasecmp(usuarios[i].sexo, "masculino") != 0 && strcasecmp(usuarios[i].sexo, "feminino") != 0 && 
              strcasecmp(usuarios[i].sexo, "indiferente") != 0) {
              printf("\nDigite o gênero (Masculino, Feminino ou Indiferente):\t");
              fgets(usuarios[i].sexo, sizeof(usuarios[i].sexo), stdin);
              usuarios[i].sexo[strcspn(usuarios[i].sexo, "\n")] = '\0';
             }
            printf("\n");
            printf("\nNovo endereco:\t");
            scanf(" %100[^\n]s", usuarios[i].endereco);
            usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';  
            printf("\n");
            printf("\nNova altura (1-2):\t");
            scanf("%lf", &usuarios[i].altura);
              while (usuarios[i].altura < 1 || usuarios[i].altura > 2){
               printf("\nDigite uma altura válida (De 1 a 2 metros):\t");
               scanf("%lf", &usuarios[i].altura);
             }    
            printf("\n");
            printf("\nVacina (1 - sim / 2 - nao):\t");
            scanf("%d", &usuarios[i].vacina);
              while (usuarios[i].vacina != 1 && usuarios[i].vacina != 2){
               printf("\nDigite um valor válido. Vacinado? (1 - Sim | 2 - Não):\t");
               scanf(" %d", &usuarios[i].vacina);
             }
            printf("\n");

            usuarios2[i] = usuarios[i];
          
            printf("\nUsuário editado com sucesso!\n");
            sleep(3);
            return;
        }
        printf("\nUsuário não encontrado.\n");
        sleep(3);
    }   
}

//CASE 3:

void excluirUsuario() {
    int id;
    printf("\nDigite o ID do usuário que deseja excluir:\t");
    scanf("%d", &id);
  
    int i, ctz;
    for (i = 0; i < nusuarios; i++) {
        if (usuarios[i].id == id) {
            int j;
            printf("\nCerteza que deseja excluir este usuário? (1 - Sim | 2 - Não)\n");
            scanf("%d", &ctz);
              while (ctz !=1 && ctz != 2){
                printf("\nDigite um valor válido. Certeza que deseja excluir este usuário? (1 - Sim | 2 - Não)\t");
                scanf("%d", &ctz);
              }
            if (ctz == 1){
            for (j = i; j < nusuarios - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            nusuarios--;
            printf("\nUsuário excluído com sucesso!\n");
            sleep(3);
            return;
            }
            else{
            printf("\nOperação cancelada.\n");
            sleep(3);  
            return;
            }
        }
    }

    printf("\nUsuário não encontrado.\n");
    sleep(3);
}

//CASE 4:

void buscarUsuario() {
    char email[101];
    printf("\nDigite o email do usuário que deseja buscar:\t");
    scanf(" %100[^\n]s", email);    
    email[strcspn(email, "\n")] = '\0';
    printf("\n");
    for (int i = 0; i < nusuarios; i++) {
        if (strcmp(usuarios[i].email, email) == 0) {
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome completo: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereco: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            if (usuarios[i].vacina == 1){
            printf("Vacina: Sim\n");
            }
            else{
            printf("Vacina: Não\n");
            }
            printf("\nAperte qualquer tecla para continuar.\n");
            flush_stdin();
            getchar();
            return;
        }
    }

    printf("\nUsuário não encontrado.\n");
    sleep(3);
}

//CASE 5:

void listaUsuario() {
    printf("\nLISTA DE USUÁRIOS:\n");
    printf("\n");
    for (int i = 0; i < nusuarios; i++) {
      printf("ID: %d\n", usuarios[i].id);
      printf("Nome completo: %s\n", usuarios[i].nome);
      printf("Email: %s\n", usuarios[i].email);
      printf("Sexo: %s\n", usuarios[i].sexo);
      printf("Endereco: %s\n", usuarios[i].endereco);
      printf("Altura: %.2lf\n", usuarios[i].altura);
        if (usuarios[i].vacina == 1){
         printf("Vacina: Sim\n");
       }
        else{
         printf("Vacina: Não\n");
       }
      printf("\n");
    }
    if (nusuarios == 0){
      printf("\nNão há usuários cadastrados\n");
      sleep(3);
      return;
    }
    printf("\nAperte qualquer tecla para continuar.\n");
    flush_stdin();
    getchar();
}

//CASE 6:

void backup(){
  int escolha;
  printf("\nCerteza que deseja restaurar os dados excluídos? (1 - Sim | 2 - Não\t");
  scanf("%d", &escolha);
  while (escolha != 1 && escolha != 2){
   printf("\nEscolha um valor válido. Certeza que deseja restaurar os dados excluídos? (1 - Sim | 2 - Não\t");
   scanf("%d", &escolha);
  }
  if (escolha == 1){
    nusuarios = nusuarios2;
    for (int i = 0; i < nusuarios; i++){
    usuarios[i] = usuarios2[i];
    }
    printf("\nDados restaurados com sucesso!\n");
    sleep(3);
    return;
  }
  else{
    printf("\nOperação cancelada.\n");
    sleep(3);
  }
}

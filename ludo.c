#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


//funcao que funcionara como dado 

void jogodado(int dados[3]){

 printf("Valores do dado: \n");
  for (int i=0;i<3;i++) {
    dados[i] = (rand() % 6) + 1;
    printf("%d ",dados[i]);
    if(dados[i]!=6){
      break;
    }
  }
   printf("\n");
}

//struct para armazenar os dados dos peoes 

typedef struct peoes{
int posicao;
}peoes;

//funcao para verificar qual jogador vai comecar primeiro 

int comeco(int x){
    srand(time(NULL));
    x=(rand() % 2)+1;
  return x;
}

//funcao para eliminar jogadores e casas especiais

void azulelimina(peoes peoesA[4],peoes peoesV[4]){
 
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        
        if((peoesA[i].posicao==peoesV[j].posicao) && (peoesV[j].posicao==1 || peoesV[j].posicao==9 || peoesV[j].posicao== 14 || peoesV[j].posicao==22 || peoesV[j].posicao==27 || peoesV[j].posicao==35 || peoesV[j].posicao==40 || peoesV[j].posicao==48)){
          printf("Nada acontece, peao em casa segura!\n");
        }
        else if((peoesA[i].posicao==peoesV[j].posicao) && ((peoesV[j].posicao!=0) && (peoesV[j].posicao!=57) && (peoesV[j].posicao!=56) && (peoesV[j].posicao!=55) && (peoesV[j].posicao!=54) && (peoesV[j].posicao!=53) && (peoesV[j].posicao!=52))){
          printf("Peao %d Azul eliminou Peao %d Verde.\n",i+1,j+1);
          peoesV[j].posicao=0;
        }
      }      
    }  
}
void verdeelimina(peoes peoesA[4],peoes peoesV[4]){
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if((peoesV[i].posicao==peoesA[j].posicao) && (peoesA[j].posicao==1 || peoesA[j].posicao==9 || peoesA[j].posicao== 14 || peoesA[j].posicao==22 || peoesA[j].posicao==27 || peoesA[j].posicao==35 || peoesA[j].posicao==40 || peoesA[j].posicao==48)){
          printf("Nada acontece, peao em casa segura!\n");
        }
        else if((peoesV[i].posicao==peoesA[j].posicao) && ((peoesA[j].posicao!=0) && (peoesA[j].posicao!=57) && (peoesA[j].posicao!=56) && (peoesA[j].posicao!=55) && (peoesA[j].posicao!=56) && (peoesA[j].posicao!=55) && (peoesA[j].posicao!=54) && (peoesA[j].posicao!=53) && (peoesA[j].posicao!=52))){
          printf("Peao %d Verde eliminou Peao %d Azul.\n",i+1,j+1);
          peoesA[j].posicao=0;
        }
      }      
    }  
}


int main(){
   
// inicializacao das posicoes dos peoes azuis e verdes
// inicializacao triangulo
  int dados[3];
  peoes peoesA[4], peoesV[4];
  
  peoesA[0].posicao = 0;
  peoesA[1].posicao = 0;
  peoesA[2].posicao = 0;
  peoesA[3].posicao = 0;

  peoesV[0].posicao = 0;
  peoesV[1].posicao = 0;
  peoesV[2].posicao = 0;
  peoesV[3].posicao = 0;
  
  
  // loop principal do jogo 
  printf("**************************************************\n");
  printf("                 Bem-vindo ao Ludo!                \n");  
                        
  printf("         Jogadores azul e verde vao jogar.\n\n");
    printf("**************************************************\n");
  printf("                                                \n");
  printf("           **** Ojetivo do jogo ****               \n");
  printf("                                                \n");
  printf("         Ser o primeiro a levar todos os   \n");
  printf("        peoes do seu time ate a casa final.            \n\n"); printf("**************************************************\n");
  
   //loop principal do jogo
  while((peoesA[0].posicao != 57 || peoesA[1].posicao != 57 || peoesA[2].posicao != 57 || peoesA[3].posicao != 57) && (peoesV[0].posicao != 57 || peoesV[1].posicao != 57 || peoesV[2].posicao != 57 || peoesV[3].posicao != 57)){
  int num;
  int jogadoratual=1;

  while(jogadoratual==1){
    printf("Azul, e sua vez!\n");
    jogodado(dados);
    // passa quando nao sai 6 de primeira 
    if(dados[0]!=6 && peoesA[0].posicao==0 && 
            peoesA[1].posicao==0 && peoesA[2].posicao==0 && 
            peoesA[3].posicao==0){
            printf("Passou a vez!\n");
            jogadoratual++;
            printf("\n");
    }
      
      //passa quando sai tres 6
   else if(dados[0]==6 && dados[1]==6 && dados[2]==6){
      printf("Passou a vez, valor 6 tres vezes.\n");
      jogadoratual++;
      printf("\n");
   }

    else{
      int numjogadas=1;
    for (int i=0;i<2;i++) {
        if (dados[i] == 6) {
          numjogadas++;
        }
      } 
    for(int i=0;i<numjogadas;i++){
      printf("Dado %d\n",i+1);
      printf("Digite o numero do peao que deseja mover?\n");
      for(int i=0;i<4;i++){
      printf("Peao %d - posicao %d\n",i+1,peoesA[i].posicao);
    }
       do {
          scanf("%d", &num);
          if (num != 1 && num != 2 && num != 3 && num != 4) {
            printf("Valor inválido. Digite novamente.\n");
          }
         //nao permite tirar da casa a nao ser que saia 6
         if(peoesA[num-1].posicao==0 && dados[i]!=6){
            printf("Escolha um peao valido. Digite novamente.\n");
          }
         else if(peoesA[num-1].posicao==0 && dados[i]==6){
           peoesA[num - 1].posicao=1;
         }
        //passa se todos precisarem de valores especificos
         else if(peoesA[0].posicao+dados[i]>57 && peoesA[1].posicao+dados[i]>57 && peoesA[2].posicao+dados[i]>57 && peoesA[3].posicao+dados[i]>57){
           printf("Nenhum movimento valido.\n");
           jogadoratual++;
         }
        // se peao passar de 57 e outros posicao 0 passa a vez         //nao move se precisar de um valor especifico
                 
         else if(peoesA[num-1].posicao+dados[i]>57){
          int contador = 0;
          for (int j=0; j<4; j++) {
            if (j != num-1 && peoesA[j].posicao==0 && dados[i]!=6){
               contador++;
            }
          }     
            if(contador!=3){
              printf("Para mover este deve-se obter valor menor ou igual a %d.\n",57-peoesA[num-1].posicao);
           printf("Escolha outro peao para mover.\n");         
            }
           else{
             printf("Nenhum movimento valido.\n");
             jogadoratual++;
           }
         }
           
         else if(peoesA[num-1].posicao+dados[i]==57){
           peoesA[num - 1].posicao += dados[i];
          printf("Peao %d no destino final.\n",num);
           break;
        } 
         else{
           peoesA[num - 1].posicao += dados[i];
         }                   
        } while ((num != 1 && num != 2 && num != 3 && num != 4) || (peoesA[num-1].posicao==0 && dados[i]!=6) || (peoesA[num-1].posicao+dados[i]>57));
                     
           azulelimina(peoesA,peoesV);
          
      
      printf("\n");
    }
      printf("AZUL\n");
      for(int i=0;i<4;i++){
      printf("Peao %d - posicao %d\n",i+1,peoesA[i].posicao);
    }
      printf("________________________");
      printf("\n\n");
    dados[0]=0;
    dados[1]=0;
    dados[2]=0;
    jogadoratual++;
    }   
    }  
    
  while(jogadoratual==2){
    printf("Verde, e sua vez!\n");
    jogodado(dados);

    // passa quando nao sai 6 de primeira
    if(dados[0]!=6 && peoesV[0].posicao==0 && 
            peoesV[1].posicao==0 && peoesV[2].posicao==0 && 
            peoesV[3].posicao==0) {
            printf("Passou a vez!\n");
            jogadoratual--;
            printf("\n");
    }
    //passa quando sai tres 6
    else if(dados[0]==6 && dados[1]==6 && dados[2]==6){
      printf("Passou a vez, valor 6 tres vezes.\n");
      jogadoratual--;
      printf("\n");
    }

    else{
    int numjogadas=1;
    for (int i=0;i<2;i++) {
        if (dados[i] == 6) {
          numjogadas++;
        }
      }
    for(int i=0;i<numjogadas;i++){
      printf("Dado %d\n",i+1);
      printf("Digite o numero do peao que deseja mover?\n");
      for(int i=0;i<4;i++){
      printf("Peao %d - posicao %d\n",i+1,peoesV[i].posicao);
      }
        do {
          scanf("%d", &num);
          if (num != 1 && num != 2 && num != 3 && num != 4) {
            printf("Valor inválido. Digite novamente.\n");
          }
          //nao permite tirar da casa a nao ser que saia 6
          if(peoesV[num-1].posicao==0 && dados[i]!=6){
            printf("Escolha um peao valido. Digite novamente.\n");
          }
          else if(peoesV[num-1].posicao==0 && dados[i]==6){
            peoesV[num - 1].posicao=1;
          }
          //passa se todos precisarem de valores especificos
         else if(peoesV[0].posicao+dados[i]>57 && peoesV[1].posicao+dados[i]>57 && peoesV[2].posicao+dados[i]>57 && peoesV[3].posicao+dados[i]>57){
           printf("Nenhum movimento valido.\n");
           jogadoratual--;
         }
         
       // se peao passar de 57 e outros posicao 0 passa a vez         //nao move se precisar de um valor especifico
                 
         else if(peoesV[num-1].posicao+dados[i]>57){
          int contador = 0;
          for (int j=0; j<4; j++) {
            if (j != num-1 && peoesV[j].posicao==0 && dados[i]!=6){
               contador++;
            }
          }     
            if(contador!=3){
              printf("Para mover este deve-se obter valor menor ou igual a %d.\n",57-peoesV[num-1].posicao);
           printf("Escolha outro peao para mover.\n");         
            }
           else{
             printf("Nenhum movimento valido.\n");
             jogadoratual--;
           }
         }
       
  
        else if(peoesV[num-1].posicao+dados[i]==57){
          peoesV[num - 1].posicao += dados[i];
          printf("Peao %d no destino final.\n",num);
          break;
        }        
          else{
            peoesV[num - 1].posicao += dados[i];
          }
        } while ((num != 1 && num != 2 && num != 3 && num != 4) || (peoesV[num-1].posicao==0 && dados[i]!=6) || (peoesV[num-1].posicao+dados[i]>57));
      
         verdeelimina(peoesA,peoesV);
                
      printf("\n");
    
    }
      printf("VERDE\n");
      for(int i=0;i<4;i++){
      printf("Peao %d - posicao %d\n",i+1,peoesV[i].posicao);
    }
      printf("________________________");
      printf("\n\n");
    dados[0]=0;
    dados[1]=0;
    dados[2]=0;
    jogadoratual--;
  } 
  }
}
   if(peoesA[0].posicao == 57 && peoesA[1].posicao == 57 && peoesA[2].posicao == 57 && peoesA[3].posicao == 57){
     printf("PARABENS! Jogador AZUL venceu!");
     return 0;
   }
  else if(peoesV[0].posicao == 57 && peoesV[1].posicao == 57 && peoesV[2].posicao == 57 && peoesV[3].posicao == 57){
    printf("PARABENS! Jogador VERDE venceu!");
    return 0;
  }     
}
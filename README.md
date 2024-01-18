Meu primeiro projeto, há melhorias a serem feitas!
Desenvolvimento de um jogo de tabuleiro, Ludo, na linguagem C. Prática de conceitos vistos acerca de Algoritmos e Estruturas
de Dados I (estruturas, funções, arrays, alocação dinâmica de memória, ponteiros)

--> Objetivo principal e regras do jogo/execução do programa

1. Ludo é jogado de 2 a 4 jogadores. Cada jogador possui 4 peões. Aquele que levar
os 4 peões até o final (triângulo) primeiro, será declarado o vencedor (seu programa
deverá permitir que o usuário entre com a quantidade de jogadores);
2. O peão só pode ser movido para o início da corrida, na casa de sua respectiva cor,
quando um jogador lançar um 6 no dado;
3. Após colocar um peão no início do tabuleiro o jogador terá um novo lançamento do
dado;
4. Se um jogador tirar 3 vezes seis em sequência deve-se passar a vez.
5. Para chegar à casa final (triângulo), deve-se tirar o valor exato remanescente e terá
direito a outra rodada no dado; se não for o caso, ele deverá mover outra peça, se
não for possível deve-se passar a vez;
6. É possível capturar o peão de outro jogador se cair em uma casa onde tomada por
outro peão. Assim, o(s) peão(ões) adversários voltam, a posição inicial fora da trilha.
Além disso quando uma captura ocorre o jogador pode lançar o dado mais uma vez;
7. As 4 casas que possuem cor são consideradas pontos seguros onde os peões
adversários não podem ser capturados;
8. As 4 casas que possuem estrelas são consideradas pontos seguros onde os peões
adversários não podem ser capturados;
9. Os peões devem se mover e viajar contornando o tabuleiro até chegar na última
casa. A cada rodada do dado o jogador deve-se movimentar, ou seja, não é permitido
abdicar do movimento; salve casos onde o movimento é ilegal;
10. Se um peão chegar ao ponto de origem, o jogador pode lançar o dado mais uma
vez;
11. O programa deve permitir que o usuário escolha qual dos peões (quando possível)
irá se mover;


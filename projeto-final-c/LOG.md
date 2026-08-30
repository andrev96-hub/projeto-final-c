===============================
## Sessao 1
**Funcionalidades implementadas**
Criar a estrutura base do projeto e do loop principal.
Definir o tabuleiro 10 x 20 no terminal.
Criar o shape dos blocos.

**Maior dificuldade encontrada e como resolvi(ou nao resolvi)**
Fazer que a peça escolhida seja aleatoria.
Detecao de colisao com o fim do tabuleiro e com os blocos na base.

**Proximo passo planeado**
Colisao de blocos e tabuleiro.
Fazer que a peça escolhida seja aleatoria.
Leitura de comandos em tempo real.
=================================
## Sessao 2 
**Funcionalidades implementadas**
Detecao de colisao com o fim do tabuleiro e com os blocos na base.
Utilizacao da lib stdlib.h (rand()) para a geracao aleatoria na escolha dos blocos.

**Maior dificuldade encontrada e como resolvi(ou nao resolvi)**
Verificar os limites do tabuleiro e a colisao com blocos ja fixados.
Resolvido usando a matriz da peca em relacao as coordenadas do tabuleiro.

**Proximo passo planeado**
Adicionar um sistema de pontuacao
Leitura de comandos em tempo real

====================================
## Sessao 3
**Funcionalidades implementadas**
Implementacao do funcao lock(), para que o bloco fique permanente no tabuleiro.
Atualizacao da funcao game(), para diferenciar graficamente os blocos em movimento dos blocos ja fixados, e as posicoes vazias.

**Maior dificuldade encontrada e como resolvi(ou nao resolvi)**
Sincronizar as coordenadas dos blocos com as do tabuleiro.

**Proximo passo planeado**
Leitura de comandos em tempo real
Adicionar um sistema de pontuacao



===============================
## Sessao 4
**Funcionalidades implementadas**
Implementacao do movimento da peca por comandos via teclado(A,D,S,W)
Implementacao do rotate_piece
Desenvolvimento do loop principal main() com o ciclo game_over


**Maior dificuldade encontrada e como resolvi(ou nao resolvi)**
Gerir a colisao ao descer o bloco.
Fazer com que o bloco faca o rotate

**Proximo passo planeado**
Criar uma funcao para eliminar linhas completas no tabuleiro.
Adicionar um temporizador.
E implementar gravidade automatica para o bloco cair automaticamente sem depender do utilizador.
Implementar uma condicao de game over quando os blocos atingem o inicio do tabuleiro.
Adicionar Pontuacao ao jogo
Fazer que os blocos desaparecam quando o jogador fizer pontos.


===============================
## Sessao 5
**Funcionalidades implementadas**
Implementacao de  uma condicao de game over quando os blocos atingem o inicio do tabuleiro.
Implementacao da gravidade automatica com temporizador em tempo real utilizando _kbhit() e sleep() para que o bloco desca sem depender dos comandos do utilizador.
Implementacao do clear_lines juntamente com o score do jogo, se os blocos preencherem a linha do tabuleiro, efetua o clear e adiciona 100 pontos.

**Maior dificuldade encontrada e como resolvi(ou nao resolvi)**
Fazer que o clear_lines funciona-se juntamente com o score.
Erros com o kbhit() e sleep()

**Proximo passo planeado**
Remover o "flicker" quando o jogo esta a ser corrido.
Remover o cursor da consola.
Implementar o kbhit() e sleep() a modo que funcione.

===============================
## Sessao 6
**Funcionalidades implementadas**
Removido o flicker do ecra com SetConsoleCursorPosition().
Ocultacao do cursor do jogador.
Implementacao do kbhit() e sleep()
Implementacao do print: GAME OVER/Pontuacao final e o respetivo Score.

**Maior dificuldade encontrada e como resolvi(ou nao resolvi)**
Implementar o kbhit e sleep()
Codigo deixou de funcionar apos adicionar SetConsoleCursorPosition e "cls" e tentar remover o cursor do jogo.

**Proximo passo planeado**
Adicionar "Proxima peca" no painel.
Adicionar Som quando o jogador faz pontos ou quando a peca da lock.


===============================
## Sessao 7
**Funcionalidades implementadas**
Implementacao da visualizacao da "Proxima Peca"
Criacao do painel lateral na interface.

**Maior dificuldade encontrada e como resolvi(ou nao resolvi)**
Implementar a proxima peca no codigo sem dar erro

**Proximo passo planeado**
Adicionar Som ao jogo.



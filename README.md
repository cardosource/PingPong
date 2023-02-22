# ping pong

Este jogo foi desenvolvido utilizando a biblioteca gráfica SFML (Simple and Fast Multimedia Library) e é uma versão simplificada do clássico jogo de arkanoid. O objetivo é mover as barras (jogadores 1 e 2) para evitar que a bola passe e marcar pontos ao fazer a bola passar pela barra do oponente.

Requisitos
- Compilador C++
- Biblioteca SFML
- Arquivo de fonte (Tuffy.ttf)
- Instalação       
 Para instalar o SFML, basta seguir os passos descritos na página oficial: [SFML Instalação](https://www.sfml-dev.org/download.php)


Arquivos incluídos
- main.cpp
- Tuffy.ttf (fonte utilizada no jogo)


Variáveis e Definições
- placarGamer1 e placarGamer2 armazenam o placar de cada jogador.
- eixoX e eixoY armazenam as coordenadas da bola.
- velocidade é a velocidade da bola.
- dificuldade é a dificuldade do jogo.
- modWidth e mofHeight são as dimensões da janela do jogo.


Funcionamento

O jogo é iniciado com uma tela de introdução com a mensagem "Pressione ENTER". Quando o jogador pressiona a tecla ENTER, a mensagem desaparece e o jogo começa.

As barras dos jogadores se movem na vertical ao pressionar as setas para cima e para baixo. A bola se move ao longo do eixo X e Y, com sua velocidade ajustada de acordo com as colisões com as barras e as paredes laterais.





Se a bola sair pela esquerda da tela, o jogador 2 ganha um ponto e a bola é colocada no centro da tela, pronta para recomeçar. O placar é atualizado automaticamente.


O jogo termina quando um dos jogadores alcança uma determinada pontuação previamente estabelecida.


[![](https://raw.githubusercontent.com/cardosource/PingPong/main/inicio.png)](https://www.sfml-dev.org/download.php)


<br/>

Ganha ponto ao ultrapssar o limite do adversário (a) sem que ocorra a rebater o objeti lançado.

<div>
    <img src="https://raw.githubusercontent.com/cardosource/PingPong/main/pontoplay1.png" width="300"/>
  
 <img src="https://raw.githubusercontent.com/cardosource/PingPong/main/pontoplay2.png" width="304" />
  
</div>

<br/>


# Conclusão



![](https://img.shields.io/badge/c%2B%2B-9.4.0-blue)
![](https://img.shields.io/badge/sfml-2.5.1-yellow)

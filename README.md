# Projeto computação movel

## Introdução
O nosso projeto visa fazer um jogo da memória e de perguntas e respostas usando o Arduíno UNO como nossa plataforma, além do uso do Tinkercad como ferramenta para produzirmos o código do jogo, além de executar simulações.
Alguns detalhes dos jogos são:
  - O jogo procura testar a memória do jogador.
  - Serão realizadas perguntas de tema geral.
  - A ordem será primeiro o teste de memória e depois as perguntas.
  - A cada resposta, o jogo deverá emitir um som que indicará se foi certo ou errado.
  - O jogo de memória deve mostrar uma sequência para o jogador decorar.
  - A fase de perguntas será composta apenas por perguntas que serão respondidas por sim ou não.
  - A última fase deve ser uma pergunta fixa.
  - Ao ganhar o jogo, uma música será tocada.

## Jogo da memória

   Os controles do jogo são realizados a partir de dois botões, um representando o LED vermelho e outro o verde. O jogo em si tem uma proposta simples, onde uma sequência será apresentada ao jogador e ele deve repetir a mesma após a exibição da primeira.
  Trata-se de uma sequência de 10 leds formada aleatoriamente e a cada tentativa que o usuário fazer será uma nova sequência. Para avançar para a próxima fase, o jogador deve repetir corretamente a sequência inteira.

## Jogo de perguntas

 O jogo de perguntas compõe as fases finais do jogo, tendo seus controles compostos também por dois botões, porém dessa vez uma representa o "sim" e o outro o "não". A tela do display exibirá por um curto período uma pergunta simples e logo em seguida as opções de resposta para ela (sim ou não) e um timer que contará o tempo disponível para responder à questão, 10 segundos. O jogo será composto por 5 perguntas selecionadas aleatoriamente. Caso todas sejam respondidas corretamente, o jogo irá avançar para seu estágio final, que se trata de uma pergunta fixa que determinará se o jogo foi vencido ou perdido. Cada pergunta deveram ser respondidas dentro de 10 segundos, aos 6 segundos um som será tocado para alertar do iminente fim do tempo, e caso o tempo se esgote, na primeira vez que o tempo acabar a questão será pulada dando uma segunda chance para o jogador, mas caso o tempo se esgote por uma segunda vez o jogo será perdido e reiniciado.

## Metodologia

### Lista de materiais completa com suas funçoes:

- Arduino UNO
> Plataforma de base para o projeto, onde todos os outros componentes foram acoplados.
- 1 LED vermelho.
- 1 LED verde.
> Os leds tem sua função para indicarem a sequencia no jogo de memoria e para indicar qual botão está sendo pressionado.
- 3 botões.
> Os botões compõem os controles dos jogos na primeira fase servindo como um para o LED vermelho e o outro para o verde, na segunda um para o sim e outro para o não. E um último e terceiro botão que fixamente serve para inciar o jogo caso não tenha sido iniciado, e caso ja esteja em andamento o jogo ele serve como um botão para reiniciar o jogo
- Resistores.
- 1 Buzzer
> Serve para gerar os sons necessários para os jogos, como por exemplo a música de vítoria, som de acertos, erros e etc.
- Display LCD 16x2
> Exibição de mensagens do jogo como a introdução, informações gerais, perguntas do jogo, timer e etc.

### Desenvolvimento

  Para do desenvolvimento do projeto usamos principalmente o Tinkercad e o GitHub, o desenvolvimento bruto total além dos testes, foram feitos pelo Tinkercad pela interface que contribuia grandemente com o desenvolvimento por nos possibilitar de fazer simulações com o Arduíno em si sem nem mesmo termos ele em mãos, e o GitHub para conseguirmos desenvolver o codigo individualmente além de salvar o progresso feito durante a duração do projeto. O código comentado está disponível no arquivo [main.cpp](https://github.com/poulison/Projeto-computa-o-movel/blob/main/main.cpp) aqui no GitHub.


### Sistema
![image](https://github.com/user-attachments/assets/1263a761-5ebe-4989-817f-328af6170d91)






  


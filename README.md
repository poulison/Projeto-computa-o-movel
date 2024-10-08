# Projeto computação movel

O nosso projeto tem como objetivo fazer um jogo da memória e de perguntas e respostas usando o arduino UNO como nossa plataforma alem do uso do tinkercard como ferramenta para produzirmos o codigo do jogo alem de executar simulações.
Alguns detalhes dos jogos são:
  - Os jogos tem como objetivo testar a memória do jogador
  - Serão realizadas perguntas de tema geral
  - A ordem será primeiro o teste de memória e depois as perguntas
  - A cada resposta o jogo deverá emitir um som indicara se foi certo ou errado
  - O jogo de memória deve mostrar uma sequência para o jogador decorar
  - A fase de perguntas seram compostas apenas por perguntas que serão respondidas por sim ou não
  - A última fase deve ser uma pergunta fixa
  - Ao ganhar o jogo uma música será tocada

## Jogo da memória

  Os controles do jogo são realizados a partir de dois botões, um representando o LED vermelho e outro o verde, O jogo em si tem uma proposta simples onde uma sequencia sera apresentada ao jogador e ele deve repetir a mesma após a exibição da primeira.
  Trata-se de uma sequencia de 10 leds formada aleatoriamente e a cada tentativa que o usuario fazer será uma nova sequencia. Para avançar para a próxima fase o jogador deve repetir corretamente a sequencia inteira.

## Jogo de perguntas

  O jogo de perguntas compõe as fases finais do jogo, tendo seus controles compostos também por dois botões porém dessa vez uma representa o "sim" e o outo o "não". A tela do display exibira por um curto periodo de tempo uma pergunta simples e logo em seguida as opções de resposta para ela(sim ou não) e um timer que contara o tempo disponivel para responder a questão, 10 segundos. O jogo será composto por 5 perguntas selecionadas aleatoriamente, caso todas sejam respondidas corretamente o jogo ira avançar para seu estagio final que trata-se de uma pergunta fixa que determinara se o jogo foi vencido ou perdido. Cada pergunta deveram ser respondidas dentro de 10 segundos, aos 6 segundos um som será tocado para alertar do iminente fim do tempo, e caso o tempo se esgote, na primeira vez que o tempo acabar a questão será pulada dando uma segunda chance para o jogador mas caso o tempo se esgote por uma segunda vez o jogo será perdido e reiniciado.

## Materiais usados
### Lista de materiais completa com suas funçoes:
- Arduino UNO
> Plataforma de base para 
- 1 LED vermelho
- 1 LED verde
> Os leds tem sua função para indicarem a sequencia no jogo de memoria e para indicar qual botão está sendo pressionado.
- 3 botões
> Os botões compõem os controles dos jogos na primeira fase servindo como um para o LED vermelho e o outro para o verde, na segunda um para o sim e outro para o não. E um último e terceiro botão que fixamente serve para inciar o jogo caso não tenha sido iniciado, e caso ja esteja em andamento o jogo ele serve como um botão para reiniciar o jogo
- Resistores
- 1 Buzzer
- Display LCD 16x2



  


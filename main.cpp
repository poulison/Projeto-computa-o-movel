//Paulo Andre de Oliveira Hirata RA: 24.123.086-1
//Victor Merker Binda RA: 24.223.086-0

// Inclui a biblioteca para o LCD
#include <LiquidCrystal.h>

// Define constantes para as notas musicais
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define PAUSE 0


// Variáveis globais
int segundos2 = 0; // Contador para o tempo da segunda parte
int segundos = 0;  // Contador para o tempo da primeira parte
int vermelho = 6;  // Pino do LED vermelho
int verde = 7;     // Pino do LED verde
int botaostart = 9; // Pino do botão de iniciar
int buzzer = 13;   // Pino do buzzer
const int tamanho = 10; // Tamanho do array de memória
const int numeroDePerguntas = 5; // Número de perguntas
int memoria[tamanho]; // Array para armazenar a sequência de LEDs
int ligaled = 0; // Controle do estado da LED
int indsequeusuario = 0; // Indica a resposta do usuário
int memoriausu[tamanho]; // Array para armazenar as respostas do usuário
int contagemseq = 0; // Contador de sequência
const int tamanhoquest = 9; // Número total de perguntas
bool jogoAtivo = false; // Controla o estado do jogo
bool erro = false; // Controla se houve erro

// Declaração de array de perguntas
String perguntas[tamanhoquest] = {
    "Neymar joga bola?",
    "A terra e plana?",
    "Pedra e dura?",
    "Cego ve?",
    "O sol e quente?",
    "Teclado tem teclas?",
    "A terra gira?",
    "Cachorro assobia?",
    "Fogo cura ferida?"
};

// Declaração do array de respostas
String respostas[tamanhoquest] = {
    "Sim",
    "Nao",
    "Sim",
    "Nao",
    "Sim",
    "Sim",
    "Sim",
    "Nao",
    "Nao"
};
String respusua[numeroDePerguntas];//array que armazena as respostas do usuario
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);//inicia LCD

void setup() {
   pinMode(vermelho, OUTPUT); // Configura o LED vermelho como saída
    pinMode(verde, OUTPUT); // Configura o LED verde como saída
    pinMode(10, INPUT_PULLUP); // Configura pino 10 como entrada com resistor pull-up
    pinMode(8, INPUT_PULLUP); // Configura pino 8 como entrada com resistor pull-up
    pinMode(botaostart, INPUT_PULLUP); // Configura o botão de iniciar como entrada com pull-up
    pinMode(buzzer, OUTPUT); // Configura o buzzer como saída

    lcd_1.begin(16, 2); // Inicializa o LCD com 16 colunas e 2 linhas
    lcd_1.print("Seja bem vindo!"); // Exibe mensagem de boas-vindas
    lcd_1.setCursor(0, 1); // Move o cursor para a segunda linha
    lcd_1.print("Pressione iniciar"); // Instrui o usuário a pressionar iniciar
}

void loop() {
    int estadoBotao = digitalRead(botaostart);

    // Verifica se o botão foi pressionado
    if (estadoBotao == LOW && !jogoAtivo) {
        jogoAtivo = true; // Marca que o jogo começou
        iniciarJogo(); // Chama a função que inicia o jogo
    }

    // Verifica se o botão foi pressionado novamente para reiniciar
    if (estadoBotao == LOW && jogoAtivo) {
        reiniciarJogo();
    }
}

// Função que inicia o jogo
void iniciarJogo() {
    lcd_1.clear(); // Limpa o LCD
    lcd_1.print("Jogo Iniciado"); // Indica que o jogo começou
    delay(1000); // Espera 1 segundo
    lcd_1.clear(); // Limpa o LCD novamente
    lcd_1.print("Memorize as cores"); // Instrui o usuário a memorizar as cores
    lcd_1.setCursor(0, 1); // Move o cursor para a segunda linha
    lcd_1.print("dos LEDs"); // Exibe mensagem sobre os LEDs
    delay(1000); // Espera 1 segundo

    // Gera uma sequência aleatória de LEDs
    for (int i = 0; i < tamanho; i++) {
        randomSeed(analogRead(0)); // Inicializa o gerador de números aleatórios
        memoria[i] = random(2); // Gera um número aleatório (0 ou 1) e armazena em memória
    }
   // Loop que percorre todos os elementos de 'memoria' até o 'tamanho' especificado
for (int i = 0; i < tamanho; i++) {
  
    // Se o valor na memória for 0, ativa o LED vermelho e desativa o verde
    if (memoria[i] == 0) {
        digitalWrite(vermelho, HIGH);  // Acende o LED vermelho
        digitalWrite(verde, LOW);       // Apaga o LED verde
        delay(1000);                    // Aguarda 1 segundo
        digitalWrite(vermelho, LOW);    // Apaga o LED vermelho
        digitalWrite(verde, LOW);       // Garante que o LED verde está apagado
        delay(1000);                    // Aguarda mais 1 segundo
    } else { // Caso contrário, se o valor for diferente de 0
        digitalWrite(verde, HIGH);      // Acende o LED verde
        digitalWrite(vermelho, LOW);    // Apaga o LED vermelho
        delay(1000);                    // Aguarda 1 segundo
        digitalWrite(vermelho, LOW);    // Garante que o LED vermelho está apagado
        digitalWrite(verde, LOW);       // Garante que o LED verde está apagado
        delay(1000);                    // Aguarda mais 1 segundo
    }
}

    // Limpa o LCD e exibe a mensagem para o usuário repetir a sequência
    lcd_1.clear();
    lcd_1.print("Agora repita ");
    lcd_1.setCursor(0, 1);
    lcd_1.print(" a sequencia");
    delay(2000); // Aguarda 2 segundos

    // Inicializa contagem da sequência e variável para erro
    contagemseq = 0;
    bool erro = false;

   // Loop para o usuário repetir a sequência
for (int b = 0; b < tamanho; b++) {
    lcd_1.clear(); // Limpa o LCD
    lcd_1.print("Contagem: "); // Exibe a contagem atual
    lcd_1.print(contagemseq);

    // Loop infinito até que uma ação seja tomada
    while (true) {
        int botaovd = digitalRead(8); // Lê o estado do botão verde
        int botaovm = digitalRead(10); // Lê o estado do botão vermelho
        int estadoBotaoStart = digitalRead(botaostart); // Lê o botão de reinício

        // Se o botão de reinício for pressionado, reinicia o jogo
        if (estadoBotaoStart == LOW) {
            reiniciarJogo();
            return; // Sai da função para interromper o fluxo atual e reiniciar o jogo
        }

        // Se o botão verde for pressionado
        if (botaovd == LOW) {
            indsequeusuario = 1; // Armazena a entrada do usuário
            digitalWrite(verde, HIGH); // Acende o LED verde
            delay(1000); // Aguarda 1 segundo
            digitalWrite(verde, LOW); // Apaga o LED verde
            memoriausu[b] = indsequeusuario; // Salva a sequência do usuário
            contagemseq++; // Incrementa a contagem
            break; // Sai do loop interno
        } 
        // Se o botão vermelho for pressionado
        else if (botaovm == LOW) {
            indsequeusuario = 0; // Armazena a entrada do usuário
            digitalWrite(vermelho, HIGH); // Acende o LED vermelho
            delay(1000); // Aguarda 1 segundo
            digitalWrite(vermelho, LOW); // Apaga o LED vermelho
            memoriausu[b] = indsequeusuario; // Salva a sequência do usuário
            contagemseq++; // Incrementa a contagem
            break; // Sai do loop interno
        }
    }
       // Verifica se a sequência do usuário é diferente da memória
    if (memoriausu[b] != memoria[b]) {
        lcd_1.clear(); // Limpa o LCD
        lcd_1.print("Errou!"); // Exibe mensagem de erro
        musicaerro(); // Toca uma música de erro
        delay(1000); // Aguarda 1 segundo
        erro = true; // Marca como erro
        reiniciarJogo(); // Reinicia o jogo em caso de erro
        return; // Sai da função
    }
}

// Se não houve erro após o loop
if (!erro) {
    lcd_1.clear(); // Limpa o LCD
    lcd_1.print("Parabens!"); // Exibe mensagem de sucesso
    musicaerro(); // Toca uma música de sucesso
    delay(1000); // Aguarda 1 segundo
}

// Exibe instruções para a segunda parte do jogo
lcd_1.clear();
lcd_1.print("segunda parte");
lcd_1.setCursor(0, 1);
lcd_1.print("perguntas");
delay(1000); // Aguarda 1 segundo

lcd_1.clear();
lcd_1.print("Responda");
lcd_1.setCursor(0, 1);
lcd_1.print("Sim ou Nao");
delay(1000); // Aguarda 1 segundo
  
// Embaralha e seleciona as perguntas
    embaralharPerguntas();
    selecionarPerguntas();

// Loop para exibir perguntas ao usuário
  for(int i=0;i<numeroDePerguntas;i++){
      segundos = 0; // Inicializa contagem de segundos
    unsigned long tempoAnterior = 0; // Variável para armazenar o tempo anterior

    lcd_1.clear(); // Limpa o LCD
    lcd_1.print(perguntas[i]); // Exibe a pergunta
    delay(4000); // Aguarda 4 segundos para leitura
    
    
    //fiz o while para so tomar um ação depois que aperta algum botao
    while (true) {
       int botaosim = digitalRead(8);
       int botaonao = digitalRead(10);
      int estadoBotaoStart = digitalRead(botaostart);
      int chance= 0;
          
          	
          	if (estadoBotaoStart == LOW) {
            reiniciarJogo();
            return; // Sai da função para interromper o fluxo atual e reiniciar o jogo
        }
        
        unsigned long tempoAtual = millis(); // Armazena o tempo atual
        
        // Incrementa os segundos a cada 1000ms
        if (tempoAtual - tempoAnterior >= 1000) {
            tempoAnterior = tempoAtual; // Atualiza o tempo anterior
          	segundos++;
            lcd_1.clear();
            lcd_1.print("Tempo: ");
            lcd_1.print(segundos);
            lcd_1.setCursor(0, 1);
            lcd_1.print("Sim ou Nao");
          	
          
          	if (segundos == 6) {
            	musicatempo(); // Chama a função musicatempo
        } 
    }
      	

        // Verifica se o botão "Sim" foi pressionado
        if (botaosim == LOW) {
            respusua[i] = "Sim";
            digitalWrite(verde, HIGH);
            delay(500); // Luz verde acende brevemente para confirmar a resposta
            digitalWrite(verde, LOW);
            break; // Sai do while para a próxima pergunta
        }

        // Verifica se o botão "Nao" foi pressionado
        if (botaonao == LOW) {
            respusua[i] = "Nao";
            digitalWrite(vermelho, HIGH);
            delay(500); // Luz vermelha acende brevemente para confirmar a resposta
            digitalWrite(vermelho, LOW);
            break; // Sai do while para a próxima pergunta
        }
     
      
      

        // Verifica se o tempo acabou (10 segundos)
         if (segundos >= 10) {
                lcd_1.clear();
                lcd_1.print("so tem mais");
                lcd_1.setCursor(0, 1);
                lcd_1.print("uma chance");
                delay(1000);
                chance++;
                break;
            }

            if (chance == 2) {
                lcd_1.clear();
                lcd_1.print("acabou as");
                lcd_1.setCursor(0, 1);
                lcd_1.print("chances");
                delay(1000);
                reiniciarJogo(); // Reinicia o jogo se o tempo esgotar
                return; // Sai da função inteira para reiniciar o jogo
            }
          }
            
    // Verifica se a resposta do usuário está correta e se a resposta correta é "Sim"    
    if(respusua[i]==respostas[i] && respostas[i]=="Sim"){
      lcd_1.clear(); // Limpa o LCD
    lcd_1.print("Resposta correta"); // Exibe mensagem de resposta correta
    lcd_1.setCursor(0, 1); // Define o cursor na segunda linha
    lcd_1.print("*Sim ou Nao"); // Informa que as opções são "Sim" ou "Não"
    delay(1000); // Aguarda 1 segundo
    musicaacerto(); // Toca uma música de acerto
     
    
    }
      // Verifica se a resposta do usuário está correta e se a resposta correta é "Não"
    if(respusua[i]==respostas[i] && respostas[i]=="Nao"){
      lcd_1.clear(); // Limpa o LCD
    lcd_1.print("Resposta correta"); // Exibe mensagem de resposta correta
    lcd_1.setCursor(0, 1); // Define o cursor na segunda linha
    lcd_1.print("Sim ou *Nao"); // Informa que as opções são "Sim" ou "Não"
    delay(1000); // Aguarda 1 segundo
    musicaacerto(); // Toca uma música de acerto
     
    }
    // Verifica se a resposta do usuário está errada e se a resposta do usuário foi "Sim"  
    if(respusua[i]!=respostas[i] && respusua[i]=="Sim"){
       musicaerro(); // Toca uma música de erro
    lcd_1.clear(); // Limpa o LCD
    lcd_1.print("Resposta errada"); // Exibe mensagem de resposta errada
    lcd_1.setCursor(0, 1); // Define o cursor na segunda linha
    lcd_1.print("*Sim ou Nao"); // Informa que as opções são "Sim" ou "Não"
    delay(1000); // Aguarda 1 segundo
    reiniciarJogo(); // Reinicia o jogo em caso de resposta errada
    return; // Sai da função
    }
    // Verifica se a resposta do usuário está errada e se a resposta do usuário foi "Não"
    if(respusua[i]!=respostas[i] && respusua[i]=="Nao"){
      musicaerro(); // Toca uma música de erro
    lcd_1.clear(); // Limpa o LCD
    lcd_1.print("Resposta errada"); // Exibe mensagem de resposta errada
    lcd_1.setCursor(0, 1); // Define o cursor na segunda linha
    lcd_1.print("Sim ou *Nao"); // Informa que as opções são "Sim" ou "Não"
    delay(1000); // Aguarda 1 segundo
    reiniciarJogo(); // Reinicia o jogo em caso de resposta errada
    return; // Sai da função
    }
   }
  
  // Limpa o LCD e exibe uma nova pergunta
lcd_1.clear();
lcd_1.print("eisten era fisico?"); // Pergunta sobre Einstein
delay(4000); // Aguarda 4 segundos para leitura

segundos2 = 0; // Inicializa a contagem de segundos para esta pergunta
unsigned long tempoAnterior2 = 0; // Variável para armazenar o tempo anterior

// Loop infinito para ler as respostas do usuário    
  while (true){
   
    int botaosim = digitalRead(8); // Lê o estado do botão de "Sim"
    int botaonao = digitalRead(10); // Lê o estado do botão de "Não"
    int estadoBotaoStart = digitalRead(botaostart); // Lê o estado do botão de reinício
    int chance = 0; // Variável que pode ser usada para controlar chances, não implementada aqui
    
        unsigned long tempoAtual2 = millis(); // Armazena o tempo atual
        
        // Incrementa os segundos a cada 1000ms
        if (tempoAtual2 - tempoAnterior2 >= 1000) {
            tempoAnterior2 = tempoAtual2; // Atualiza o tempo anterior
            segundos2++;
            lcd_1.clear();
            lcd_1.print("Tempo: ");
            lcd_1.print(segundos2);
            lcd_1.setCursor(0, 1);
            lcd_1.print("Sim ou Nao");
          if (segundos2 == 6) {
            musicatempo(); // Chama a função musicatempo
        } 
        }
            
    if (estadoBotaoStart == LOW) {
            reiniciarJogo();
            return; // Sai da função para interromper o fluxo atual e reiniciar o jogo
        }
    if (botaosim == LOW) {
      		musicaacerto();
            lcd_1.clear();
            lcd_1.print("Acertou");
            digitalWrite(verde, HIGH);
            delay(500); // Luz verde acende brevemente para confirmar a resposta
            digitalWrite(verde, LOW);
            

            delay(1000);
            break; 
        }

        // Verifica se o botão "Nao" foi pressionado
        if (botaonao == LOW) {
         	musicaerro();
            lcd_1.clear();
            lcd_1.print("Errou");
          

            delay(1000);
            digitalWrite(vermelho, HIGH);
            delay(500); // Luz vermelha acende brevemente para confirmar a resposta
            digitalWrite(vermelho, LOW);
          reiniciarJogo;
            return; 
        }
     
      

        // Verifica se o tempo acabou (10 segundos)
         if (segundos2 >= 10) {
                lcd_1.clear();
                lcd_1.print("acabou o tempo");//mensagem que acabou o tempo
                delay(1000);
                lcd_1.clear();
                lcd_1.print("Derrota"); //mensagem de derrota
                lcd_1.setCursor(0, 1);
                lcd_1.print("Reiniciando"); //mensagem indicando que o jogo está reiniciando
                delay(1000);
                reiniciarJogo();//funcao para reiniciar o jogo
           		return;
            }
  }
  
  
  // Limpa o LCD para exibir uma nova mensagem
lcd_1.clear();
lcd_1.print("Prabens voce "); // Mensagem de parabenização
lcd_1.setCursor(0, 1); // Define o cursor na segunda linha
lcd_1.print("concluiu"); // Indica que o usuário concluiu a tarefa
delay(1000); // Aguarda 1 segundo para que o usuário leia a mensagem
  
}



void reiniciarJogo() {
    lcd_1.clear(); // Limpa o LCD para uma nova mensagem
    lcd_1.print("Reiniciando..."); // Exibe a mensagem de reinício
    delay(1000); // Espera 1 segundo para que o usuário veja a mensagem

    // Resetar variáveis de controle do jogo
    contagemseq = 0; // Zera a contagem da sequência, preparando para um novo jogo
    for (int i = 0; i < tamanho; i++) {
        memoriausu[i] = 0; // Zera a sequência de entrada do usuário, limpando as respostas
        memoria[i] = 0; // Opcional: Zera a sequência gerada, para não manter dados antigos
    }
    segundos = 0; // Zera o contador de tempo, garantindo que não haja tempo acumulado de jogos anteriores
    jogoAtivo = false; // Marca que o jogo está inativo, permitindo que seja reiniciado
    erro = false; // Resetar a flag de erro, preparando para um novo jogo sem erros anteriores
    
    lcd_1.clear(); // Limpa o LCD novamente
    lcd_1.print("Pressione iniciar"); // Instrui o usuário a pressionar o botão de iniciar
}

void embaralharPerguntas() {
    for (int i = 0; i < numeroDePerguntas; i++) {
        randomSeed(analogRead(0)); // Inicializa o gerador de números aleatórios com uma leitura analógica
        int j = random(i + 1); // Gera um índice aleatório entre 0 e i
        String tempPergunta = perguntas[i]; // Armazena a pergunta atual em uma variável temporária
        perguntas[i] = perguntas[j]; // Troca a pergunta atual com a pergunta em j
        perguntas[j] = tempPergunta; // Finaliza a troca

        String tempResposta = respostas[i]; // Armazena a resposta atual em uma variável temporária
        respostas[i] = respostas[j]; // Troca a resposta atual com a resposta em j
        respostas[j] = tempResposta; // Finaliza a troca
    }
}

void selecionarPerguntas() {
    String perguntasSelecionadas[numeroDePerguntas];// Cria um array para armazenar as perguntas selecionadas
    String respostasSelecionadas[numeroDePerguntas];

    for (int i = 0; i < numeroDePerguntas; i++) {
        perguntasSelecionadas[i] = perguntas[i];// Copia as perguntas para o array selecionado
        respostasSelecionadas[i] = respostas[i];
    }
}


void musicaacerto(){
   // Melodia curta para o som de acerto
  int melody[] = {
    NOTE_C5, NOTE_E5, NOTE_G5
  };

  // Duração das notas
  int noteDurations[] = {
    8, 8, 4
  };

  // Tocar cada nota
  for (int thisNote = 0; thisNote < 3; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);  // Buzzer no pino 8

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }
}

void musicaerro(){
  int melody[] = {
    NOTE_F4, NOTE_DS4, NOTE_C4, PAUSE, NOTE_C4
  };

  // Duração das notas
  int noteDurations[] = {
    8, 8, 4, 8, 2
  };

  // Tocar cada nota
  for (int thisNote = 0; thisNote < 5; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration); 

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }
}
  


//funcao para o som que alerta o fim do tempo
void musicatempo(){
 int melody[] = {
    NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4
  };//melodia

  // Duração das notas (rápidas para criar urgência)
  int noteDurations[] = {
    8, 8, 8, 8, 8, 8, 8, 8, 4
  };

  // Tocar cada nota
  for (int thisNote = 0; thisNote < 9; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);  

    int pauseBetweenNotes = noteDuration * 1.10;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }


}

//funcao de musica de vitoria
void musicavitoria(){

// Melodia da música de vitória
  int melody[] = {
    NOTE_C5, NOTE_G4, NOTE_E4, NOTE_A4, PAUSE, NOTE_B4, NOTE_C5
  };

  // Duração das notas
  int noteDurations[] = {
    4, 8, 8, 4, 8, 4, 2
  };

  // Tocar cada nota
  for (int thisNote = 0; thisNote < 7; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);  // Buzzer no pino 8

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }




}

//Paulo Andre de Oliveira Hirata RA: 24.123.086-1
//Victor Merker Binda RA: 24.223.086-0

#include <LiquidCrystal.h>
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


int segundos2 = 0;
int segundos = 0;
int vermelho = 6;
int verde = 7;
int botaostart = 9;
int buzzer = 13;
const int tamanho = 10;
const int numeroDePerguntas = 5;
int memoria[tamanho];
int ligaled = 0;
int indsequeusuario = 0;
int memoriausu[tamanho];
int contagemseq = 0;
const int tamanhoquest = 9;
bool jogoAtivo = false; // Variável para controlar o estado do jogo
bool erro = false;      // Variável global para verificar erros
// Declaração de arrays de perguntas e respostas
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
String respusua[numeroDePerguntas];
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup() {
    pinMode(vermelho, OUTPUT);
    pinMode(verde, OUTPUT);
    pinMode(10, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(botaostart, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);

    lcd_1.begin(16, 2); 
    lcd_1.print("Seja bem vindo!");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Pressione iniciar");
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

void iniciarJogo() {
    lcd_1.clear();
    lcd_1.print("Jogo Iniciado");
    delay(1000);
    lcd_1.clear();
    lcd_1.print("Memorize as cores");
    lcd_1.setCursor(0, 1);
    lcd_1.print("dos LEDs");
    delay(1000);

    for (int i = 0; i < tamanho; i++) {
      randomSeed(analogRead(0));
        memoria[i] = random(2); 
    }

    for (int i = 0; i < tamanho; i++) {
      
        if (memoria[i] == 0) {
            digitalWrite(vermelho, HIGH);
            digitalWrite(verde, LOW);
            delay(1000);
            digitalWrite(vermelho, LOW);
            digitalWrite(verde, LOW);
            delay(1000);
        } else {
            digitalWrite(verde, HIGH);
            digitalWrite(vermelho, LOW);
            delay(1000);
            digitalWrite(vermelho, LOW);
            digitalWrite(verde, LOW);
            delay(1000);
        }
      
    }

    lcd_1.clear();
    lcd_1.print("Agora repita ");
    lcd_1.setCursor(0, 1);
    lcd_1.print(" a sequencia");
    delay(2000);

    contagemseq = 0;
    bool erro = false;

    for (int b = 0; b < tamanho; b++) {
        lcd_1.clear();
        lcd_1.print("Contagem: ");
        lcd_1.print(contagemseq);

        while (true) {
            int botaovd = digitalRead(8);
            int botaovm = digitalRead(10);
          	int estadoBotaoStart = digitalRead(botaostart);
          
          	
          	if (estadoBotaoStart == LOW) {
            reiniciarJogo();
            return; // Sai da função para interromper o fluxo atual e reiniciar o jogo
        }
          
          
          

            if (botaovd == LOW) {
                indsequeusuario = 1;
                digitalWrite(verde, HIGH);
                delay(1000);
                digitalWrite(verde, LOW);
                memoriausu[b] = indsequeusuario;
                contagemseq++;
                break;
            } else if (botaovm == LOW) {
                indsequeusuario = 0;
                digitalWrite(vermelho, HIGH);
                delay(1000);
                digitalWrite(vermelho, LOW);
                memoriausu[b] = indsequeusuario;
                contagemseq++;
                break;
            }
        }

        if (memoriausu[b] != memoria[b]) {
            lcd_1.clear();
            lcd_1.print("Errou!");
          	musicaerro();
            delay(1000);
            erro = true;
            reiniciarJogo(); // Reinicia o jogo em caso de erro
            return; // Sai da função
        }
    }

    if (!erro) {
        lcd_1.clear();
        lcd_1.print("Parabens!");
      musicaerro();
        delay(1000);
    }

    lcd_1.clear();
    lcd_1.print("segunda parte");
    lcd_1.setCursor(0, 1);
    lcd_1.print("perguntas");
    delay(1000);
  lcd_1.clear();
    lcd_1.print("Responda");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Sim ou Nao");
    delay(1000);
  

    embaralharPerguntas();
    selecionarPerguntas();
  
  for(int i=0;i<numeroDePerguntas;i++){
        segundos = 0;
    unsigned long tempoAnterior = 0;
    
    lcd_1.clear();
    lcd_1.print(perguntas[i]);
    
    
    delay(4000);
    
    
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
            
       
    
        
    if(respusua[i]==respostas[i] && respostas[i]=="Sim"){
      lcd_1.clear();
    lcd_1.print("Resposta correta");
    lcd_1.setCursor(0, 1);
    lcd_1.print("*Sim ou Nao");
    delay(1000);
      musicaacerto();
     
    
    }
        if(respusua[i]==respostas[i] && respostas[i]=="Nao"){
      lcd_1.clear();
    lcd_1.print("Resposta correta");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Sim ou *Nao");
    delay(1000);
          musicaacerto();
     
    }
    if(respusua[i]!=respostas[i] && respusua[i]=="Sim"){
      musicaerro();
      lcd_1.clear();
    lcd_1.print("Resposta errada");
    lcd_1.setCursor(0, 1);
    lcd_1.print("*Sim ou Nao");
    delay(1000);
      reiniciarJogo();
          	return;
    }
        if(respusua[i]!=respostas[i] && respusua[i]=="Nao"){
      musicaerro();
          lcd_1.clear();
    lcd_1.print("Resposta errada");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Sim ou *Nao");
    delay(1000);
          reiniciarJogo();
          	return;
     
    }
   }
  
  
  lcd_1.clear();
    lcd_1.print("eisten era fisico?");
    delay(4000);
  
  
  segundos2=0;
    
  unsigned long tempoAnterior2 = 0;
  
  
  while (true){
   
    int botaosim = digitalRead(8);
    int botaonao = digitalRead(10);
    int estadoBotaoStart = digitalRead(botaostart);
    int chance= 0;
    
   
         
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
                lcd_1.print("acabou o tempo");
                delay(1000);
                lcd_1.clear();
                lcd_1.print("Derrota");
                lcd_1.setCursor(0, 1);
                lcd_1.print("Reiniciando");
                delay(1000);
                reiniciarJogo();
           		return;
            }

  
  
  
  
  
  }
  
  
  
  lcd_1.clear();
    lcd_1.print("Prabens voce ");
    lcd_1.setCursor(0, 1);
    lcd_1.print("concluiu");
    delay(1000);
  	musicavitoria();
    reiniciarJogo();
  
}



void reiniciarJogo() {
     lcd_1.clear();
    lcd_1.print("Reiniciando...");
    delay(1000);
    
    // Resetar variáveis de controle do jogo
    contagemseq = 0;         // Zera a contagem da sequência
    for (int i = 0; i < tamanho; i++) {
        memoriausu[i] = 0;   // Zera a sequência de entrada do usuário
        memoria[i] = 0;      // Opcional: Zera a sequência gerada
    }
    segundos = 0;            // Zera o contador de tempo
    jogoAtivo = false;       // Marca que o jogo está inativo
    erro = false;            // Resetar a flag de erro
    
    lcd_1.clear();
    lcd_1.print("Pressione iniciar");
}

void embaralharPerguntas() {
    for (int i = 0; i < numeroDePerguntas; i++) {
        randomSeed(analogRead(0));
      	int j = random(i + 1);
        String tempPergunta = perguntas[i];
        perguntas[i] = perguntas[j];
        perguntas[j] = tempPergunta;

        String tempResposta = respostas[i];
        respostas[i] = respostas[j];
        respostas[j] = tempResposta;
    }
}

void selecionarPerguntas() {
    String perguntasSelecionadas[numeroDePerguntas];
    String respostasSelecionadas[numeroDePerguntas];

    for (int i = 0; i < numeroDePerguntas; i++) {
        perguntasSelecionadas[i] = perguntas[i];
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
  



void musicatempo(){
 int melody[] = {
    NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4
  };

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

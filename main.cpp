#include <LiquidCrystal.h>
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
            delay(1000);
            erro = true;
            reiniciarJogo(); // Reinicia o jogo em caso de erro
            return; // Sai da função
        }
    }

    if (!erro) {
        lcd_1.clear();
        lcd_1.print("Parabens!");
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
  
  for(int i=0;i<=numeroDePerguntas;i++){
        segundos = 0;
    unsigned long tempoAnterior = 0;
    
    lcd_1.clear();
    lcd_1.print(perguntas[i]);
    
    
    delay(4000);
    
    
    
    while (true) {
        int botaosim = digitalRead(8);
        int botaonao = digitalRead(10);
        
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
            lcd_1.print("acabou o tempo");
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
     
    
    }
        if(respusua[i]==respostas[i] && respostas[i]=="Nao"){
      lcd_1.clear();
    lcd_1.print("Resposta correta");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Sim ou *Nao");
    delay(1000);
     
    }
    if(respusua[i]!=respostas[i] && respusua[i]=="Sim"){
      lcd_1.clear();
    lcd_1.print("Resposta errada");
    lcd_1.setCursor(0, 1);
    lcd_1.print("*Sim ou Nao");
    delay(1000);
      reiniciarJogo();
          	return;
     
    
    }
        if(respusua[i]!=respostas[i] && respusua[i]=="Nao"){
      lcd_1.clear();
    lcd_1.print("Resposta errada");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Sim ou *Nao");
    delay(1000);
          reiniciarJogo();
          	return;
     
    }
        
      
      
      }
  
  
  
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

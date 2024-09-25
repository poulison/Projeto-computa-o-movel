#include <LiquidCrystal.h>
int segundos=0 ;
int vermelho = 6;
int verde = 7;
int botaostart = 9;
int buzzer = 13;
const int tamanho = 10;
const int numeroDePerguntas = 5;
int memoria[tamanho];
int ligaled = 0; // se for 1 liga verde se for 0 liga vermelho
int indsequeusuario = 0;
int memoriausu[tamanho];
int contagemseq = 0;
const int tamanhoquest = 9; // Mudado para o número correto de perguntas

// Declaração de arrays de perguntas e respostas
String perguntas[tamanhoquest] = {
    "Neymar joga bola?", 
    "A terra é plana?", 
    "Pedra é dura?",
    "Cego vê?", 
    "O sol é quente?",
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
  	
}; // LOW no verde é sim e low no vermelho é nao

String respusuario[tamanho]; // Array para as respostas do usuário

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup() {
    pinMode(vermelho, OUTPUT);
    pinMode(verde, OUTPUT);
    pinMode(10, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(botaostart, INPUT_PULLUP);
    pinMode(buzzer, OUTPUT);
  
    lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.
    lcd_1.print("Seja bem vindo!");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Pressione iniciar");
}

void loop() {
    int estadoBotao = digitalRead(botaostart);  // Lê o estado do botão

    // Verifica se o botão foi pressionado (LOW porque está em modo INPUT_PULLUP)
    if (estadoBotao == LOW) {
        lcd_1.clear();
        lcd_1.print("Jogo Iniciado");
        delay(1000);
        lcd_1.clear();
        lcd_1.print("Memorize as cores");
        lcd_1.setCursor(0, 1);
        lcd_1.print("dos LEDs");
        delay(1000);

        for (int i = 0; i < tamanho; i++) {
            memoria[i] = random(2); // Gera 0 ou 1
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

        contagemseq = 0; // Resetar contagemseq para cada nova tentativa
        bool erro = false;
        
        for (int b = 0; b < tamanho; b++) {
            lcd_1.clear();
            lcd_1.print("Contagem: ");
            lcd_1.print(contagemseq);

            // Espera até que um botão seja pressionado
            while (true) {
                int botaovd = digitalRead(8);
                int botaovm = digitalRead(10);
                
                if (botaovd == LOW) {
                    indsequeusuario = 1;
                    digitalWrite(verde, HIGH);
                    delay(1000);
                    digitalWrite(verde, LOW);
                    memoriausu[b] = indsequeusuario;
                    contagemseq++;
                    break; // Sai do loop enquanto para processar a próxima sequência
                } 
                else if (botaovm == LOW) {
                    indsequeusuario = 0;
                    digitalWrite(vermelho, HIGH);
                    delay(1000);
                    digitalWrite(vermelho, LOW);
                    memoriausu[b] = indsequeusuario;
                    contagemseq++;
                    break; // Sai do loop enquanto para processar a próxima sequência
                }
            }

            // Verifica se a entrada do usuário está correta
            if (memoriausu[b] != memoria[b]) {
                lcd_1.clear();
                lcd_1.print("Errou!");
                delay(1000);
                erro = true; // Marca que houve erro
                break; // Sai do loop
            }
        }

        if (!erro) {
            lcd_1.clear();
            lcd_1.print("Parabens!"); // Se tudo correto
            delay(1000);
        }
        
        lcd_1.clear();
        lcd_1.print("segunda parte"); 
        lcd_1.setCursor(0, 1);
        lcd_1.print("perguntas");
        delay(1000);
        
      // embaralhar os char de perguntas e respostas
      	embaralharPerguntas();
      	selecionarPerguntas();
      
      	
      for(int i=0;i<numeroDePerguntas;i++){
        segundos = 0;
        
        
        
        
        if (segundos>10){
        	lcd_1.clear();
            lcd_1.print("acabou o tempo"); 
            delay(1000);
          	break;
        
        }
      
      
      }
        
        lcd_1.clear(); // Limpa o LCD
        lcd_1.print("Pressione Iniciar"); // Volta a mensagem inicial
    }
}


void embaralharPerguntas() {
    for (int i = tamanhoquest - 1; i > 0; i--) {
        int j = random(i + 1); // Gera um índice aleatório
        // Troca as perguntas
        String tempPergunta = perguntas[i];
        perguntas[i] = perguntas[j];
        perguntas[j] = tempPergunta;

        // Troca as respostas
        String tempResposta = respostas[i];
        respostas[i] = respostas[j];
        respostas[j] = tempResposta;
    }
}

void selecionarPerguntas() {
    String perguntasSelecionadas[numeroDePerguntas];
    String respostasSelecionadas[numeroDePerguntas];

    for (int i = 0; i <= numeroDePerguntas; i++) {
        perguntasSelecionadas[i] = perguntas[i]; // Pega as 5 primeiras após embaralhar
        respostasSelecionadas[i] = respostas[i];
    }

 /*
  for (int p = 0; p < tamanho; p++) {
            lcd_1.clear();
            lcd_1.print("Contagem: ");
            lcd_1.print(contagemseq);

            // Espera até que um botão seja pressionado
            while (true) {
                int botaovd = digitalRead(8);
                int botaovm = digitalRead(10);
                
                if (botaovd == LOW) {
                    indsequeusuario = 1;
                    digitalWrite(verde, HIGH);
                    delay(1000);
                    digitalWrite(verde, LOW);
                    memoriausu[b] = indsequeusuario;
                    contagemseq++;
                    break; // Sai do loop enquanto para processar a próxima sequência
                } 
                else if (botaovm == LOW) {
                    indsequeusuario = 0;
                    digitalWrite(vermelho, HIGH);
                    delay(1000);
                    digitalWrite(vermelho, LOW);
                    memoriausu[b] = indsequeusuario;
                    contagemseq++;
                    break; // Sai do loop enquanto para processar a próxima sequência
             }
      } 
  */
   
}

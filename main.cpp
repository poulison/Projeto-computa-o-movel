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
        

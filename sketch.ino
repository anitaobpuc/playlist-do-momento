// potenciômetro A0 controla
// brilho LED pino 9
// LCD I2C mostra valor 0-255
// Semáforo de pedestres
// Botão aciona travessia; LEDs verde, amarelo e vermelho mudam em sequência temporizada.

const int botaoPin = 2;      // Pino do botão de chamada
const int ledVerde = 9;      // LED verde (pode atravessar)
const int ledAmarelo = 10;   // LED amarelo (prepare-se para parar)
const int ledVermelho = 11;  // LED vermelho (não atravesse)

const unsigned long tempoVerde = 5000;   // Tempo de travessia (ms)
const unsigned long tempoAmarelo = 2000; // Tempo de alerta antes de encerrar
const unsigned long debounceDelay = 50;  // Debounce do botão (ms)

void setup() {
  pinMode(botaoPin, INPUT_PULLUP);  // Botão com pull-up interno
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  mostrarSemaforo(false, false, true); // Inicia com vermelho ligado
}

void loop() {
  if (botaoApertado()) {
    realizarTravessia();
  }
}

bool botaoApertado() {
  if (digitalRead(botaoPin) == LOW) {
    delay(debounceDelay);
    if (digitalRead(botaoPin) == LOW) {
      while (digitalRead(botaoPin) == LOW) {
        // espera o botão ser solto para evitar acionamentos repetidos
        delay(10);
      }
      return true;
    }
  }
  return false;
}

void realizarTravessia() {
  // Verde: pedestres podem atravessar
  mostrarSemaforo(true, false, false);
  delay(tempoVerde);

  // Amarelo: tempo de alerta antes de encerrar
  mostrarSemaforo(false, true, false);
  delay(tempoAmarelo);

  // Vermelho: pedestres devem parar; volta ao estado inicial
  mostrarSemaforo(false, false, true);
}

void mostrarSemaforo(bool verde, bool amarelo, bool vermelho) {
  digitalWrite(ledVerde, verde ? HIGH : LOW);
  digitalWrite(ledAmarelo, amarelo ? HIGH : LOW);
  digitalWrite(ledVermelho, vermelho ? HIGH : LOW);
}

// Teclado de alterações, valores analisados

const int numRows = 4;       // Número de linhas na matriz
const int numCols = 4;       // Número de colunas na matriz

char keypad[numRows][numCols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Pinos digitais conectados às linhas do teclado
int rowPins[numRows] = {2, 3, 4, 5};

// Pinos digitais conectados às colunas do teclado
int colPins[numCols] = {6, 7, 8, 9};

char primeirasTeclas[5] = "";  // Array para armazenar as 4 primeiras teclas pressionadas
int contadorTeclas = 0;        // Contador para controlar o número de teclas pressionadas

int iluminacao = 0;  // Variável para armazenar a informação de iluminação
int temperatura = 0;  // Variável para armazenar a informação de temperatura
int humidade = 0;  // Variável para armazenar a informação de humidade

bool selecaoRealizada = false; // Flag para indicar se a seleção foi realizada
bool opcoesHabilitadas = false; // Flag para indicar se as opções estão habilitadas

void setup() {
  Serial.begin(9600);
  
  // Configura os pinos das colunas como saídas e define-os como HIGH
  for (int col = 0; col < numCols; col++) {
    pinMode(colPins[col], OUTPUT);
    digitalWrite(colPins[col], HIGH);
  }
  
  // Configura os pinos das linhas como entradas e ativa os pull-ups internos
  for (int row = 0; row < numRows; row++) {
    pinMode(rowPins[row], INPUT_PULLUP);
  }
}

void loop() {
  if (!selecaoRealizada) {
    processarSelecao();
  } else {
    if (opcoesHabilitadas && contadorTeclas < 4) {
      char key = getKey();
      
      if (key != '\0') {
        primeirasTeclas[contadorTeclas] = key;
        contadorTeclas++;
        Serial.println(key);
      }
    }
    
    if (contadorTeclas == 4) {
      // Aqui você pode realizar ações adicionais com as teclas pressionadas
      // após a seleção ter sido realizada
      
      // Reinicia as variáveis para esperar por novas teclas pressionadas
      primeirasTeclas[0] = '\0';
      contadorTeclas = 0;
    }
  }
}

char getKey() {
  // Verifica todas as colunas para determinar se uma tecla foi pressionada
  for (int col = 0; col < numCols; col++) {
    digitalWrite(colPins[col], LOW);    // Define a coluna atual como LOW
    
    // Verifica todas as linhas para determinar qual tecla foi pressionada
    for (int row = 0; row < numRows; row++) {
      if (digitalRead(rowPins[row]) == LOW) {
        delay(50);    // Debounce: aguarda um curto período para evitar leituras falsas
        
        // Verifica novamente se a tecla ainda está pressionada após o debounce
        if (digitalRead(rowPins[row]) == LOW) {
          digitalWrite(colPins[col], HIGH);   // Restaura o estado HIGH na coluna atual
          return keypad[row][col];            // Retorna o caractere correspondente à tecla pressionada
        }
      }
    }
    
    digitalWrite(colPins[col], HIGH);   // Restaura o estado HIGH na coluna atual
  }
  
  return '\0';   // Retorna '\0' se nenhuma tecla foi pressionada
}

void processarSelecao() {
  Serial.println("Pressione '*' para exibir as opções.");

  while (!selecaoRealizada) {
    char key = getKey();

    if (key != '\0') {
      if (key == '*') {
        Serial.println("Opções:");
        Serial.println("[A] Iluminação");
        Serial.println("[B] Temperatura");
        Serial.println("[C] Humidade");
        Serial.println("[D] Sair");
        opcoesHabilitadas = true;
      } else if (opcoesHabilitadas) {
        switch (key) {
          case 'A':
            // Opção Iluminação selecionada
            Serial.println("Opção: Iluminação");
            iluminacao = lerValorTeclado();
            Serial.print("Iluminação: ");
            Serial.println(iluminacao);
            selecaoRealizada = true;
            break;
          
          case 'B':
            // Opção Temperatura selecionada
            Serial.println("Opção: Temperatura");
            temperatura = lerValorTeclado();
            Serial.print("Temperatura: ");
            Serial.println(temperatura);
            selecaoRealizada = true;
            break;
          
          case 'C':
            // Opção Humidade selecionada
            Serial.println("Opção: Humidade");
            humidade = lerValorTeclado();
            Serial.print("Humidade: ");
            Serial.println(humidade);
            selecaoRealizada = true;
            break;
          
          case 'D':
            // Opção Sair selecionada
            Serial.println("Opção: Sair");
            selecaoRealizada = true;
            break;
          
          default:
            // Opção inválida
            Serial.println("Opção inválida. Tente novamente.");
            break;
        }
      }
    }
  }
}

int lerValorTeclado() {
  // Lógica para ler e retornar o valor numérico digitado no teclado
  // Você pode personalizar esta função de acordo com suas necessidades
  
  // Exemplo: leitura de um valor inteiro de 0 a 999
  
  int valor = 0;
  
  while (contadorTeclas < 4) {
    char key = getKey();
    
    if (key >= '0' && key <= '9') {
      valor = valor * 10 + (key - '0');
      contadorTeclas++;
      Serial.print(key);
    }
  }
  
  Serial.println();
  
  return valor;
}

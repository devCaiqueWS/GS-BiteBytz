# Projeto BiteBytz - Monitoramento de Condições de Transporte de alimentos

Este é um projeto de Arduino que utiliza sensores para monitorar as condições de armazenamento de vinhos, incluindo temperatura, umidade e luminosidade. Com base nos dados obtidos pelos sensores, o projeto fornece indicações visuais e sonoras para auxiliar na manutenção das condições ideais de armazenamento.

## Objetivo

O objetivo deste projeto é desenvolver um sistema de monitoramento das condições de transporte de alimentos, garantindo que as condições ideais sejam mantidas para preservar a qualidade e segurança dos alimentos durante o transporte.

## Desenvolvimento do Projeto

O projeto foi desenvolvido utilizando um Arduino Uno e diversos componentes eletrônicos. Foi realizado o esquema elétrico e a programação necessária para o monitoramento da luminosidade, umidade e temperatura. O sistema utiliza um display LCD para exibir as informações coletadas pelos sensores e LEDs para indicar as condições de transporte.

## Como Executar o Projeto

Para executar o projeto, siga as etapas abaixo:

1. Monte o circuito elétrico de acordo com o esquema fornecido.
2. Faça o upload do código para o Arduino.
3. Conecte o Arduino a uma fonte de alimentação.
4. Observe as informações exibidas no display LCD e as indicações dos LEDs.

## Pré-requisitos

Para executar o projeto, siga os passos abaixo ou entre na simulação [(Link simulação)](https://www.tinkercad.com/things/3VLIiHJQjDJ): 

Você precisará dos seguintes materiais:

- Arduino Uno
- Display LCD (16x2)
- Sensor de luminosidade (LDR)
- Sensor de umidade
- Sensor de temperatura
- LEDs (verde, amarelo e vermelho)
- Buzzer

## Esquema Elétrico

![Esquema Elétrico]([circuit.png](https://github.com/devCaiqueWS/GS-BiteBytz/blob/main/circuit.png))

## Funcionamento

O sistema realiza a leitura da luminosidade, umidade e temperatura ambiente. Com base nesses valores, são feitas as seguintes indicações:

- Luminosidade:
  - Menor que 850: ambiente ideal (LED verde aceso).
  - Entre 850 e 960: ambiente com meia luz (LED amarelo aceso).
  - Maior que 960: ambiente claro (LED vermelho aceso e buzzer ativado por 3 segundos).
- Umidade:
  - Menor que 25%: risco ao alimento.(LED vermelho aceso e buzzer ativado por 3 segundos).
  - Entre 25% e 50%: umidade adequada.
  - Entre 50% e 75%: umidade certa.
  - Maior que 75%: risco de bolor.(LED vermelho aceso e buzzer ativado por 3 segundos).
- Temperatura:
  - Menor que 10°C: aumentar a temperatura.(LED vermelho aceso e buzzer ativado por 3 segundos).
  - Entre 10°C e 20°C: temperatura ideal.
  - Entre 20°C e 35°C: abaixar a temperatura.
  - Maior que 35°C: risco ao alimento.(LED vermelho aceso e buzzer ativado por 3 segundos).

## Dificuldades

Durante o desenvolvimento do projeto, algumas dificuldades foram encontradas, tais como:

- Calibração dos sensores para garantir a precisão das leituras.
- Adaptação do código para a exibição correta das informações no display LCD.
- Controle adequado dos LEDs e do buzzer de acordo com as condições detectadas.

## Código

Aqui está o código utilizado no projeto:

Código completo no arquivo [`main.ino`](https://github.com/devCaiqueWS/vinheiria/edit/main/main.ino) do repositório

## Link do Vídeo Explicativo

Um vídeo explicativo sobre o projeto pode ser encontrado neste [link](https://youtu.be/Uy7qmzroecA)

## Conclusão

O projeto de Monitoramento de Condições de Transporte de Alimentos permite monitorar a luminosidade, umidade e temperatura durante o transporte de alimentos, auxiliando na manutenção das condições ideais. É uma solução simples e eficaz para garantir a qualidade e segurança dos alimentos transportados.

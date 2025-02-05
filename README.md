# Temporizador Periódico - Semáforo

Este projeto exemplifica o uso do temporizador periódico do Pico SDK para implementar um semáforo. Através da função `add_repeating_timer_ms()`, o sistema alterna os sinais do semáforo (LEDs) com um atraso de 3 segundos entre cada mudança.

## Funcionalidades

- **Ciclo do Semáforo:**  
  Inicia com o LED vermelho, alterna para o LED amarelo e depois para o LED verde, repetindo o ciclo continuamente.

- **Temporização:**  
  A cada 3.000 ms (3 s) ocorre a mudança de sinal, utilizando o repetidor de temporizador.

- **Feedback Serial:**  
  A rotina principal imprime mensagens a cada 1 segundo na porta serial, informando o estado atual do semáforo.

- **Experimento com LED RGB:**  
  Foi utilizado um LED RGB (conectado aos GPIOs 11, 12 e 13) para demonstrar a aplicação na Ferramenta Educacional BitDogLab.

## Componentes Utilizados

- **Microcontrolador:** Raspberry Pi Pico W
- **LEDs:** 3 LEDs (vermelho, amarelo e verde)
- **Resistores:** 3 resistores de 330 Ω
- **Simulador:** Wokwi integrado ao VS Code

## Requisitos e Ambiente

- Ambiente de desenvolvimento: VS Code com integração ao simulador Wokwi.
- Pico SDK devidamente configurado.
- Repositório versionado no GitHub.

## Instruções de Uso

1. **Clone o Repositório:**

   ```bash
   git clone https://github.com/ElissonNadson/temporizador-periodico-semaforo.git
   cd temporizador-periodico-semaforo
Abra o Projeto no VS Code:
Certifique-se de que a integração com o Wokwi esteja funcionando.

Compile e Simule:
Utilize o ambiente configurado para compilar o código em C e inicie a simulação.
O semáforo deverá iniciar com o LED vermelho, passando para amarelo e depois para verde a cada 3 segundos, com mensagens na porta serial.

Verificação:
Confira os prints na porta serial para acompanhar o ciclo do semáforo.


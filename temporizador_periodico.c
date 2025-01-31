#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos do LED RGB
#define LED_R 11  // LED Vermelho (STOP)
#define LED_G 12  // LED Amarelo (ATENÇÃO)
#define LED_B 13  // LED Verde (SIGA)

// Callback do temporizador para alternar as cores do semáforo
bool troca_leds_callback(struct repeating_timer *t) {
    static int estado = 0;

    // Desliga todas as cores do LED RGB antes de mudar o estado
    gpio_put(LED_R, 0);
    gpio_put(LED_G, 0);
    gpio_put(LED_B, 0);

    // Alterna entre os estados do semáforo
    if (estado == 0) {
        gpio_put(LED_R, 1);  // Acende vermelho
        printf("🚦 Sinal Vermelho! Pare.\n");
    } else if (estado == 1) {
        gpio_put(LED_G, 1);  // Acende amarelo
        printf("⚠️ Sinal Amarelo! Atenção.\n");
    } else {
        gpio_put(LED_B, 1);  // Acende verde
        printf("✅ Sinal Verde! Siga.\n");
    }

    estado = (estado + 1) % 3;  // Alterna entre 0 → 1 → 2 → 0
    return true;
}

int main() {
    stdio_init_all();
    sleep_ms(3000);  // Pequeno delay para inicializar a UART corretamente

    // Inicializa os GPIOs do LED RGB
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);

    // Inicia o temporizador que troca os LEDs a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, troca_leds_callback, NULL, &timer);

    // Loop principal imprimindo mensagens a cada 1 segundo
    while (true) {
        printf("🖥️ Sistema rodando...\n");
        sleep_ms(1000);
    }

    return 0;
}
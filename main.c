/***
 * Timer Periodic
 * By: Adimael Santos da Silva
 * Código disponível em: github.com/adimael
 */
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Definição dos LEDs do semáfaro
#define LED_VERMELHO 13 //Pare
#define LED_AMARELO 12 //Atenção
#define LED_VERDE 11 // Siga
#define TIMER_INTERVAL 3000 // Intervalo de troca (ms)

// Estados do semáfaro
typedef enum { VERMELHO, AMARELO, VERDE } EstadoSemaforo;

EstadoSemaforo estado_atual = VERMELHO; // Começa no vermelho

// Lista de LEDs
const uint LEDS[3] = {LED_VERMELHO, LED_AMARELO, LED_VERDE};

// Função para configurar os pinos dos LEDs
void configurar_gpio() {
    for (int i = 0; i < 3; i++) {
        gpio_init(LEDS[i]);     // Inicializa o pino do LED
        gpio_set_dir(LEDS[i], GPIO_OUT); // Define como saída
        gpio_put(LEDS[i], i == 0); // Liga o LED vermelho (inicial)
    }
}

// Função chamada pelo temporizador para alternar os sinais
bool alternar_sinal(struct repeating_timer *t) {
    gpio_put(LEDS[estado_atual], 0); // Desliga o LED atual
    estado_atual = (estado_atual + 1) % 3; // Muda para o próximo estado
    gpio_put(LEDS[estado_atual], 1); // Liga o novo LED

    // Exibe no terminal o estado atual do semáforo
    printf("Semáforo: %s\n", 
        estado_atual == VERMELHO ? "Vermelho - PARE" :
        estado_atual == AMARELO ? "Amarelo - ATENÇÃO" :
        "Verde - SIGA");
    
    return true;
}

// Função principal
int main() {
    stdio_init_all();
    sleep_ms(2000); // Pequeno atraso para inicialização serial
    configurar_gpio();

    // Configuração do temporizador para alternar o sinal a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(TIMER_INTERVAL, alternar_sinal, NULL, &timer);

    // Loop principal que imprime mensagens no terminal a cada 1 segundo
    while (true) {
        printf("Sistema de Semáforo Operando...\n");
        sleep_ms(1000);
    }
}

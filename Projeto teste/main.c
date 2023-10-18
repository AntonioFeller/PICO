#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/cyw43_arch.h"

void gpio_callback(uint gpio, uint32_t events)
{
    printf("botao no pino %d",gpio);

    if(events & GPIO_IRQ_EDGE_RISE)
    {
        printf("Disparou no evento de subida");
    } else if (events & GPIO_IRQ_EDGE_FALL)
    {
        printf("Disparou no evento de decida");
    }

}

int main()
{
    stdio_init_all();
    cyw43_arch_init();

    for (int i = 0; i < 4; i++){
        gpio_init(i);
        gpio_set_dir(i, GPIO_IN);
        gpio_set_pulls(i, true, false);
        gpio_set_irq_enable_with_callback(i, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    }

    while (true)
    {
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,1);
        sleepms(250);
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN,0);
        sleepms(250);
    }
    

    return 0;
}

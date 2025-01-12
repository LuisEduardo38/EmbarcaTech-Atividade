#include <stdio.h>
#include "pico/stdlib.h"

const uint led_red_pin = 13;

//função para controlar o estado do led sendo ON ou OFF
void ON_OFF(int estado){
  if(estado == 1){
    gpio_put(led_red_pin, true);
  }
  else{
    gpio_put(led_red_pin, false);
  }
}

//função para controle do intervalo do led
void intervalo(int tempo){
  if(tempo == 1){
    sleep_ms(800);
  }
  else if(tempo == 2){
    sleep_ms(200);
  }
  else if(tempo == 3){
    sleep_ms(125);
  }
  else if(tempo == 4){
    sleep_ms(250);
  }
  else{
    sleep_ms(3000);
  }
}

//main do código para gerencia o funcionamento
int main(){
  int contador;
  stdio_init_all();
  gpio_init(led_red_pin);
  gpio_set_dir(led_red_pin, GPIO_OUT);

  while(true){//Esse while deixara o código em loop infinito
    contador = 3;//Essa variável contador ser para o código sabe quantas vezes piscar
    while(contador != 0){//Quando a variável contador for igual a 0 ira sair do loop
      ON_OFF(1);
      intervalo(1);
      ON_OFF(0);
      intervalo(3);
      contador--;
      printf(" - ");
    }
    intervalo(4);//Intervalo entre as lebras

    contador = 3;
    while(contador != 0){//Esse while ira piscar o O
      ON_OFF(1);
      intervalo(2);
      ON_OFF(0);
      intervalo(3);
      contador--;
      printf(" . ");
    }
    intervalo(4);

    contador = 3;
    while(contador != 0){//Esse while ira piscar o S
      ON_OFF(1);
      intervalo(1);
      ON_OFF(0);
      intervalo(3);
      contador--;
      printf(" - ");
    }
    intervalo(0);//Intervalo de 3 segundo para reiniciar o SOS
    printf("\n");
  }
}
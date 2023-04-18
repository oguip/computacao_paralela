# Laboratório de Computação Paralela

Grupo GGD+

<br>Daniel Ribas Nascimento de Melo 32111401
<br>Gabriel Vicentin Negro 32137095
<br>Guilherme de Oliveira Pereira 32165366

<br>Laboratório 05
<br>Para compilar o serial: ```gcc traps.c -o traps -lm```
<br>Para executar o serial: ```time ./traps```
<br>Para compilar o paralelo: ```gcc trapp.c -o trapp -fopenmp -lm```
<br>Para executar o paralelo: ```time ./trapp 2```
<br>OBS: O trapp é o que tem opemmp implementado, e o traps é o serial. O 2 apos o trapp significa que vai rodar em 2 threads, e o time é para calcular o tempo.
<br>Aqui podemos visualizar uma comparação com certos valores:
<br>![Capturar2](https://user-images.githubusercontent.com/83314109/232786280-011fb658-cda4-4dda-bd05-e094cb6e06e6.PNG)
<br>Na comparação dos tempos temos o speedud (Ts/Tp) de (vou usar o real): 
<br>1º: 1,813079551000488, ou seja, ganhamos desempenho, quase o dobro.
<br>Agora com outros valores:
<br>![Capturar3](https://user-images.githubusercontent.com/83314109/232786415-113a185c-c0e1-4674-b495-c555c5059f35.PNG)
<br>2º: 1,58241469816273, ou seja, ganhamos desempenho de novo.

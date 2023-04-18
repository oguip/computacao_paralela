# Laboratório de Computação Paralela

Grupo GGD+

<br>Daniel Ribas Nascimento de Melo 32111401
<br>Gabriel Vicentin Negro 32137095
<br>Guilherme de Oliveira Pereira 32165366

<br>Laboratório 04
<br>Para compilar o serial: ```gcc traps.c -o traps -lm```
<br>Para executar o serial: ```time ./traps```
<br>Para compilar o paralelo: ```gcc trapp.c -o trapp -fopenmp -lm```
<br>Para executar o paralelo: ```time ./trapp 2```
<br>OBS:O trapp é o que tem opemmp implementado, e o traps é o serial. O 2 apos o trapp significa que vai rodar em 2 threads, e o time é para calcular o tempo.
<br>Aqui podemos visualizar que em alguns momentos a execução serial ganha e outros que a paralela ganha:

<br>Na comparação dos tempos temos o speedud (Ts/Tp) de (vou usar o real): 
<br>1º: 0,86, ou seja, perdemos desempenho.
<br>2º: 1,11, ou seja, ganhamos desempenho.
<br>3º: 1, não mudou nada.
<br>4º: 1 também.

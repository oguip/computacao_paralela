# Laboratório de Computação Paralela

Grupo GGD+

<br>Daniel Ribas Nascimento de Melo 32111401
<br>Gabriel Vicentin Negro 32137095
<br>Guilherme de Oliveira Pereira 32165366

<br>Laboratório 04
<br>Para compilar o serial: ```gcc mults.c -o mults```
<br>Para executar o serial: ```time ./multsl```
<br>Para compilar o paralelo: ```gcc −g −Wall −o mult mult.c −lpthread```
<br>Para executar o paralelo: ```time ./mult 2```
<br>OBS:O mult é o que tem pthread implementado, e o mults é o serial. O 2 apos o mult significa que vai rodar em 2 threads, e o time é para calcular o tempo.
<br>Aqui podemos visualizar eu compilando os dois arquivos:
![image](https://user-images.githubusercontent.com/83314109/232643941-a803b291-62c0-472a-95b6-2a2f1ecae25e.png)
<br>E aqui podemos visualizar que em alguns momentos a execução serial ganha e outros que a paralela ganha:
![image1](https://user-images.githubusercontent.com/83314109/232643952-307da724-5227-4a79-b449-f3e924a6749d.png)
<br>Na comparação dos tempos temos o speedud (Ts/Tp) de (vou usar o real): 
<br>1º: 0,86, ou seja, perdemos desempenho.
<br>2º: 1,11, ou seja, ganhamos desempenho.
<br>3º: 1, não mudou nada.
<br>4º: 1 também.

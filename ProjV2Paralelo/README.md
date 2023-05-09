# Laboratório de Computação Paralela

Grupo GGD+

<br>Daniel Ribas Nascimento de Melo 32111401
<br>Gabriel Vicentin Negro 32137095
<br>Guilherme de Oliveira Pereira 32165366

<br>Projeto V2 Paralelo
<br>Nós utilizamos a máquina z1d.large para a execução do nosso programa, recomendamos que use a mesma.
<br>Depois de clonar o git, é necessário instalar o gcc com os comandos abaixo:
<br> ```sudo apt-get update``` -> ```sudo apt-get install build-essential```
<br>Depois será necessário instalar a biblioteca gmp, que foi utilizado para alcançar números de maior precisão:
<br>```sudo apt-get install libgmp-dev```
<br>Agora para compilar o programa: ```gcc eParalelo.c -o eParalelo -lm -lgmp -fopenmp```
<br>Para executar: ```time ./eParalelo```
<br>Aqui podemos visualizar a execução do programa:
<br>![image](https://user-images.githubusercontent.com/83314109/235497078-136708bd-2c20-46b8-bbca-aa31168ed900.png)
<br>O resultado é salvo em resultadoSerial.txt, e nele você pode checar o número com 3 000 000 de digitos.

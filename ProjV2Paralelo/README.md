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
<br>Para executar: ```time ./eParalelo 2```
<br>O número 2 indica a quantiade de threads que vou utilizar para rodar o programa.
<br>Aqui podemos visualizar a execução do programa:
<br>![image](https://user-images.githubusercontent.com/83314109/236970739-81b4bb77-661c-4594-8d42-4e3e18f27e5c.png)
<br>O resultado é salvo em resultadoParalelo.txt, e nele você pode checar o número com 10 000 000 de digitos com precisão correta.
<br>Foram necessario 66 minutos de execução para gerar essa precisâo com 2 000 000 de iterações:
<br>![image](https://user-images.githubusercontent.com/83314109/237039299-a8d55129-50cf-43b6-a527-d5173fcbc273.png)



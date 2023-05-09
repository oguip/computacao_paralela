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
<br>Foram necessario 66 minutos de execução para gerar essa precisão com 2 000 000 de iterações:
<br>![image](https://user-images.githubusercontent.com/83314109/237039299-a8d55129-50cf-43b6-a527-d5173fcbc273.png)
<br>Aqui temos uma comparação dos dois códigos em uma execução com 10 000 iterações e podemos visualizar que o Paralelo conseguiu um speedup de 1,375230471736295
<br>Serial: 
<br>![image](https://user-images.githubusercontent.com/83314109/237041197-513f3348-c7d6-4916-ae02-89993f9be7f9.png)
<br>Paralelo: 
<br>![image](https://user-images.githubusercontent.com/83314109/237041228-1876b4a5-1dd1-4bba-9c08-fc2277f0b6c7.png)
<br>E para validarmos o resultado, utilizamos um código em python que eu estarei disponibilizando aqui, e comparamos com um arquivo que possui a constante ```e``` com 1 bilhão de casas de precisão, que baixamos desse site: https://archive.org/details/Math_Constants. E para executar esse código em python, é necessário um txt com o nosso número chamado resultadoParalelo.txt, e um com o número original chamado original.txt
<br>Comparação dos arquivos:
<br>![image](https://user-images.githubusercontent.com/83314109/237042200-ff818b92-86ee-45f0-b3b5-0f9bac43dd2e.png)





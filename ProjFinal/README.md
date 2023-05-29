# Laboratório de Computação Paralela

Grupo GGD+

<br>Gabriel Vicentin Negro 32137095
<br>Guilherme de Oliveira Pereira 32165366

<br>Projeto Final
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
<br>Aqui temos uma comparação dos dois códigos em uma execução com 10 000 iterações e podemos visualizar que o Paralelo conseguiu um speedup de 1,375230471736295.
<br>Serial: 
<br>![image](https://user-images.githubusercontent.com/83314109/237041197-513f3348-c7d6-4916-ae02-89993f9be7f9.png)
<br>Paralelo: 
<br>![image](https://user-images.githubusercontent.com/83314109/237041228-1876b4a5-1dd1-4bba-9c08-fc2277f0b6c7.png)
<br>Aqui podemos visualizar outra comparação, o programa em paralelo rodando em 2 threads demorou 66 minutos para rodar 2 000 000 iterações:
<br>![image](https://user-images.githubusercontent.com/83314109/237039299-a8d55129-50cf-43b6-a527-d5173fcbc273.png)
<br>E aqui vemos que demorou 26 minutos uma execução com 8 threads:
<br>![image](https://github.com/oguip/computacao_paralela/assets/83314109/117bfed9-78d8-40dc-bfd7-fe9bea75c79f)
<br>Podemos reparar um speedup de 2,538461538461538
<br>E para validarmos o resultado, utilizamos um código em python que eu estarei disponibilizando aqui, e comparamos com um arquivo que possui a constante ```e``` com 1 bilhão de casas de precisão, que baixamos desse site: https://archive.org/details/Math_Constants. E para executar esse código em python, é necessário um txt com o nosso número chamado resultadoParalelo.txt, e outro com o número original chamado original.txt, localizados na mesma pasta do código em python.
<br>Comparação dos arquivos:
<br>![image](https://user-images.githubusercontent.com/83314109/237042200-ff818b92-86ee-45f0-b3b5-0f9bac43dd2e.png)

-----

<br>Decomposição de tarefas
<br>1. Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.
<br>![image](https://github.com/oguip/computacao_paralela/assets/26818066/b5e731c7-193b-41af-86be-9061ed6e9c56)

<br>2. Qual é o limite inferior do tempo de execução paralela para cada decomposição?
<br>Após tentativas malsucedidas de compilação utilizando o Profiler dentro da plataforma da AWS, não foi possível calcular o limite inferior de cada decomposição.
<br>Entretanto, é possível notar que a parte paralelizável do programa é a função ```serieTaylor```, as demais etapas são sequenciais.

<br>3. Quantos processadores são necessários para se conseguir o tempo mínimo de execução?
<br>Sem dados experimentais, que seriam obtidos utilizando o profiler, não é possível determinar a quantidade de processadores necessários para se obter o tempo mínimo de execução. Entretanto, hoje, a plataforma da AWS oferece apenas 2 processadores para se utilizar no programa.

<br>4. Qual é o grau máximo de concorrência?
<br>O Grau máximo de concorrência será o número máximo de tarefas independentes que podem ser executadas simultaneamente. Neste caso, ele está limitado pelo número de termos na função ```serieTaylor```, que será igual a N, nesse caso, 2 milhões. 

<br>5. Qual é o paralelismo médio?
<br>No caso apresentado, o paralelismo médio será a razão entre o grau máximo de concorrência e a quantidade média de trabalho por thread. Utilizando duas threads, o paralelismo médio será de 1 milhão. Vale notar que o paralelismo médio também será afetado, mesmo que minimamente, pela fração não paralelizada do programa.

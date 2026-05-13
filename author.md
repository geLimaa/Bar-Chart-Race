# Introduction

Este é um programa de linha de comando, desenvolvido em C++, que cria uma animação de "corrida de gráficos de barras" (Bar Chart Race) a partir de um arquivo de dados. Ele transforma dados que mudam ao longo do tempo em uma visualização dinâmica e fácil de entender.

## Author(s)

Autor: Gean Carlos de Lima Borges Filho
Email: <geancarloslima0907@gmail.com>


## Problems found or limitations

Não encontramos nenhuma limitação, apesar de ter consciência de que algumas soluções utilizadas poderiam ser otimizadas, mas essas não foram feitas pois precisariamos de mais tempo.

## Grading

Item     | Valor máximo   | Valor esperado
-------- | :-----: | :-----:
Read, validate, and process command line arguments | 5 | 5
Program runs with default values, if no options are provided | 5 | 5
Read the input data file and store the information in memory    | 10 | 10
Display a summary of the data read from the input file _before_ the animation starts | 5 | 5
Display a summary of the running options (set by the user or default values) _before_ the animation starts | 5 | 5
The project contains at least two classes | 10 | 10
Create individual bar charts containing all data items for a single date | 10 | 10
Run the bar chart animation at the correct speed | 10  | 10
The bar chart anatomy is complete and correct | 30 | 30
Program handles errors properly | 10 | 10

## Compiling and Running

### Compiling

Para compilar o projeto, crie um diretório de compilação (ex: build), entre nele e execute os seguintes comandos:

cmake ..
make

### Running

Após a compilação, o executável bcr estará disponível. Para executá-lo, utilize o comando abaixo, substituindo [arquivo de dados] pelo caminho do seu arquivo:

./bcr [arquivo de dados]

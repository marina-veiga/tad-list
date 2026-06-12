# Trabalho de Implementação 02 - TAD Lista Encadeada

## Descrição do Projeto
Este projeto foi desenvolvido em linguagem C com o objetivo de implementar uma Lista Encadeada Simples e aplicar conceitos relacionados ao uso de ponteiros, alocação dinâmica de memória e manipulação de estruturas de dados. Para mostrar como a estrutura funciona na prática, foi desenvolvida uma aplicação simples de gerenciamento de filmes. Nela, o usuário pode cadastrar filmes em dois conjuntos distintos (C1 e C2), remover registros, realizar operações de união e interseção entre os conjuntos e gerar um terceiro conjunto (C3) com os resultados, tudo por meio de um menu interativo no terminal.

Cada filme possui as seguintes informações:
* `char nome[100]`: Nome do filme.
* `int ano`: Ano de lançamento do filme.
* `float notaLetter`: Nota de avaliação do filme no Letterboxd.

## 1. Ambiente de Desenvolvimento
*   **Sistemas Operacionais:** Windows / Linux Ubuntu.
*   **Compilador:** MinGW no Windows.
*   **Bibliotecas:** Bibliotecas padrão da linguagem C

## 2. Compilação e Execução

Para compilar o código fonte e gerar o executável, utilize os comandos abaixo conforme o seu sistema:

**Ambiente Windows:**
```bash
gcc src/main.c src/sllist.c -o programa.exe
.\programa.exe
```
**Ambiente Linux:**
```bash
gcc src/main.c src/sllist.c -o programa
./programa
```

## 3. Funcionalidades Implementadas
- Inserir em C1: Permite cadastrar um novo filme no conjunto C1, adicionando-o no início da lista encadeada.

- Inserir em C2: Permite cadastrar um novo filme no conjunto C2, adicionando-o no final da lista encadeada.

- Remover de C1: Permite remover um filme armazenado no conjunto C1. A busca do registro pode ser realizada pelo nome, ano de lançamento ou nota do filme.

- Remover de C2: Permite remover um filme armazenado no conjunto C2. A busca do registro pode ser realizada pelo nome, ano de lançamento ou nota do filme.

- Listar C1: Exibe todos os filmes cadastrados no conjunto C1.

- Listar C2: Exibe todos os filmes cadastrados no conjunto C2.

- Listar C3 (União): Cria e exibe um terceiro conjunto contendo todos os filmes presentes em C1 e C2, sem duplicação de registros.

- Listar C3 (Interseção): Cria e exibe um terceiro conjunto contendo apenas os filmes presentes simultaneamente em C1 e C2.

- Sair: Fecha o programa após liberar a memória alocada.

# Identificação
Disciplina: Estrutura de Dados I

Aluna: Marina Nascimento Veiga

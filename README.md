
# Batalha Naval

Este é um jogo desenvolvido em linguagem C pautado na utilização dos conceitos de matrizes e vetores o qual exibe um tabuleiro 10x10 representando o jogo de Batalha Naval, com a seguinte lógica:
- A água é representada pelo número 0
- Os navios são representados pelo número 3
- Áreas com habilidades especiais tem formatos geométricos (cone, octaedro e cruz), sendo representadas pelo número 5, exceto se houver sobreposição dos navios

# Exemplos de saídas das habilidades especiais no tabuleiro:

Cone:

0 0 5 0 0
0 5 5 5 0
5 5 5 5 5

Octaedro:

0 0 5 0 0
5 5 5 5 5
0 0 5 0 0

Cruz:

0 0 5 0 0
0 5 5 5 0
0 0 5 0 0
 
## Pré-requisitos

- **Compilador C:** É necessário ter o GCC (GNU Compiler Collection) ou outro compilador de C instalado no seu sistema.
- **Terminal ou Prompt de Comando:** Necessário para compilar e executar o código.
- **Codificação UTF-8:** Certifique-se de que seu terminal esteja configurado para exibir corretamente caracteres especiais.

## Instruções para Compilação e Execução

### Unix, Linux e macOS

1. Abra o terminal.
2. Navegue até o diretório onde está o arquivo `batalhaNaval.c`:
   ```bash
   cd caminho/para/diretorio
   ```
3. Compile o código:
   ```bash
   gcc batalhaNaval.c -o batalhaNaval
   ```
4. Execute o programa:
   ```bash
   ./batalhaNaval
   ```

### Windows

#### Usando MinGW (recomendado)

1. Abra o Prompt de Comando.
2. Navegue até o diretório onde está o arquivo `batalhaNaval.c`:
   ```
   cd caminho\para\diretorio
   ```
3. Compile o código:
   ```
   gcc batalhaNaval.c -o batalhaNaval.exe
   ```
4. Execute o programa:
   ```
   batalhaNaval.exe
   ```

#### Usando Compilador do Visual Studio

1. Abra o Prompt de Comando do Desenvolvedor Visual Studio.
2. Navegue até o diretório:
   ```
   cd caminho\para\diretorio
   ```
3. Compile o programa:
   ```
   cl batalhaNaval.c
   ```
4. Execute o programa:
   ```
   batalhaNaval.exe
   ```

## Observações

- Caso caracteres especiais não sejam exibidos corretamente, ajuste seu terminal para UTF-8. O comando `chcp 65001` no terminal do Windows ativa esses caracteres temporariamente.
- Este projeto tem propósito didático.

---

Desenvolvido como parte do desafio de implementação do jogo de Batalha Naval em linguagem C.

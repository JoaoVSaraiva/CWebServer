# Servidor Web Simples em C
Este é um exemplo de um servidor web simples escrito em C, que roda no Windows. O servidor escuta na porta 8080 e, ao receber uma conexão, grava a hora atual em um arquivo especificado na requisição.

## Requisitos
- Sistema Operacional: Windows
- Compilador C compatível com Windows (ex: MinGW, MSVC)
- Biblioteca Winsock2 (já incluída no Windows)

## Como Compilar

### Terminal
Para compilar o código, você pode usar o `gcc` do MinGW ou outro compilador C compatível com Windows, e execute o seguinte comando:

```bash
gcc -o webserver webserver.c -lws2_32 -lMswsock
```

### Code-Blocks

No caso do uso do `code-blocks` realize o seguinte:
*Settings > Global Compiler Settings > Linker Settings > Add*

Entao adicione `ws2_32` e `Mswsock` como bibliotecas a serem linkadas

## Uso

1. Crie um arquivo `.html` com qualquer conteudo, preferencialmente no mesmo diretorio do binario criado.
2. Verifique seu IPV4 local no command prompt (cmd)
    ```bash
    ipconfig
    ```
3. Solicite uma requisicao `HTTP` pelo browser para o arquivo `.html` criado, exemplo:
    ```bash
    192.168.1.1:8080/index.html
    ```
    
De acordo com o efeito do codigo, o arquivo index.html tera o conteudo trocado pelo horario atual. A partir disso, fica livre a criativade para mudar o conteudo como quiser

## Melhoras

Adicao de uma interface grafica para agilidade na manipulacao dos parametros construtores do socket.
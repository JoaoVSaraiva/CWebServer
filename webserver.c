#include <winsock2.h>
#include <string.h>
#include <mswsock.h>
#include <stdio.h>
#include <time.h>

int main(){

    //INCIALIZANDO WEB SERVER NO WINDOWS
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    //CRIANDO O SOCKET DO WEB SERVER
    int sock=socket(AF_INET, //USANDO IPV4
                    SOCK_STREAM, //TIPO DO SOCKET
                    IPPROTO_TCP); //TRANSPORTE EM TCP

    //CRIANDO O ENDERECO DO SOCKET
    struct sockaddr_in addr;
    addr.sin_family=AF_INET; //IPV4
    addr.sin_port=htons(8080); //PORTA
    addr.sin_addr.s_addr=0; //LOCALHOST

    //BIND DO SOCKET AO ENDERECO
    bind(sock,(struct sockaddr*)&addr,sizeof(addr));

    //ESCUTANDO CONEXOES AO SERVER
    listen(sock,1);

    //ACEITANDO QUALQUER CONEXAO LOCAL
    int sock_con = accept(sock, NULL, NULL);

    //RECEBENDO DADOS DA CONEXAO
    char buffer[1024]; //TAMANHO DO BUFFER
    recv(sock_con,buffer,1024,0); //TRANSFENRECIA PELO SOCKET

    //ADQUIRINDO 5 PRIMEIROS CARACTERES
    char *f=buffer + 5; //5 CARACTERES DEPOIS DO INICIO
    *strchr(f, ' ')=0; //PARA AQUISICAO APOS ESPACAMENTO

    //ABRINDO ARQUIVO REQUISITADO
    FILE *file=fopen(f,"w");

    //PRINTANDO NO ARQUIVO REQUISITADO O HORARIO ATUAL
    time_t horario=time(NULL);
    struct tm *horalocal=localtime(&horario);
    fprintf(file,"Hora atual: %02d:%02d:%02d\n",
           horalocal->tm_hour, horalocal->tm_min, horalocal->tm_sec);

    //FINALIZANDO OS SOCKETS ABERTOS
    closesocket(sock);
    closesocket(sock_con);

    return 0;
}

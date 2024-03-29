#include "server.h"

void server()
{
    int Server_socket = socket(AF_INET,SOCK_STREAM,0);
    assert(Server_socket!=-1);

    struct sockaddr_in Server_address;
    Server_address.sin_family = AF_INET;

    uint16_t Port_number;
    Port_number = get_port_number_server();
    Server_address.sin_port = htons(Port_number);

    Server_address.sin_addr.s_addr = INADDR_ANY;

    char buffer[INET_ADDRSTRLEN];
    inet_ntop(AF_INET,&Server_address.sin_addr.s_addr,buffer,sizeof(buffer));
    printf("%s\n",buffer);

    int Bind_check = bind(Server_socket,(const struct sockaddr*)&Server_address,sizeof(Server_address));
    assert(Bind_check!=-1);
    
    int Number_of_connections = get_number_of_connections();
    
    int Listen_check = listen(Server_socket,Number_of_connections);
    assert(Listen_check!=-1);
    
    system("clear");
    printf("%s\n",buffer);
    printf("Listening...\n");

    //check why there is NULL, NULL

    int Client_socket = accept(Server_socket, NULL,NULL);
    assert(Client_socket!=-1);

    handle_communication_server(Client_socket);

    printf("End of communication.\n");

    close(Server_socket);
}

uint16_t get_port_number_server()
{
    int Chosen_port_number = 0;
    int Option = -1;

    while (Option!=0&&Option!=1)
    {
        system("clear");
        printf("To choose port number for server application manually write '0', for the number to be picked at random write '1':\n\n");
        printf("    (O) - Choose port number manually.\n\n");
        printf("    (1) - Port number will be picked at random.\n\n");
        printf("    Answer: ");
        scanf("%d",&Option);
    }

    if(Option==0)
    {
        while (Chosen_port_number<49152||Chosen_port_number>65535)
        {
            system("clear");
            printf("Choose port number between 49152 and 65535\n\n");
            printf("    Port number: ");
            scanf("%d",&Chosen_port_number);
        }
    }
    else
    {
        srand(time(NULL));
        Chosen_port_number = (rand()%16383)+49152;
    }

    return (uint16_t)Chosen_port_number;
}

int get_number_of_connections()
{
    int Chosen_number_of_connections = 0;
    while (Chosen_number_of_connections<1||Chosen_number_of_connections>10)
    {
        system("clear");
        printf("Choose number of possible connection. There can be upto 10 connections and there needs to be at least 1.\n\n");
        printf("    Number of connections: ");
        scanf("%d", &Chosen_number_of_connections);
    }

    return Chosen_number_of_connections;    
}

void handle_communication_server(int Socket)
{
    char Message[256];
    memset(Message,' ',256*sizeof(char));
    scanf("%s",Message);
    send(Socket,&Message,sizeof(Message),0);
    recv(Socket,&Message,sizeof(&Message),0);
    printf("%s\n",Message);
}
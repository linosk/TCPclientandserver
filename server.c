#include "server.h"

void server()
{
    int Server_socket_first = socket(AF_INET,SOCK_STREAM,0);
    assert(Server_socket_first!=-1);
    struct sockaddr_in Server_address_first;
    Server_address_first.sin_family = AF_INET;

    int Server_socket_second = socket(AF_INET,SOCK_STREAM,0);
    assert(Server_socket_second!=-1);
    struct sockaddr_in Server_address_second;
    Server_address_second.sin_family = AF_INET;

    //int Server_socket = socket(AF_INET,SOCK_STREAM,0);
    //assert(Server_socket!=-1);
    //struct sockaddr_in Server_address;
    //Server_address.sin_family = AF_INET;

    //uint16_t Port_number;
    //Port_number = get_port_number_server();
    //Server_address_first.sin_port = htons(Port_number);
    Server_address_first.sin_port = htons(55550);
    //Port_number = get_port_number_server();
    //Server_address_second.sin_port = htons(Port_number);
    Server_address_second.sin_port = htons(55555);

    //uint16_t Port_number;
    //Port_number = get_port_number_server();
    //Server_address.sin_port = htons(Port_number);
    //Server_address.sin_port = htons(55555);

    Server_address_first.sin_addr.s_addr = INADDR_ANY;
    Server_address_second.sin_addr.s_addr = INADDR_ANY;

    //Server_address.sin_addr.s_addr = INADDR_ANY;

    //char buffer[INET_ADDRSTRLEN];
    //inet_ntop(AF_INET,&Server_address_first.sin_addr.s_addr,buffer,sizeof(buffer));
    //printf("%s\n",buffer);

    int Bind_check_first = bind(Server_socket_first,(const struct sockaddr*)&Server_address_first,sizeof(Server_address_first));
    assert(Bind_check_first!=-1);
    int Bind_check_second = bind(Server_socket_second,(const struct sockaddr*)&Server_address_second,sizeof(Server_address_second));
    assert(Bind_check_second!=-1);
    
    //int Bind_check = bind(Server_socket,(const struct sockaddr*)&Server_address,sizeof(Server_address));
    //assert(Bind_check!=-1);

    //int Number_of_connections = get_number_of_connections();

    int Number_of_connections = 1;
    
    //int Listen_check_first = listen(Server_socket_first,Number_of_connections);
    //assert(Listen_check_first!=-1);
    //int Listen_check_second = listen(Server_socket_second,Number_of_connections);
    //assert(Listen_check_second!=-1);
    
    int Listen_check_first = listen(Server_socket_first,Number_of_connections);
    assert(Listen_check_first!=-1);

    system("clear");
    //printf("%s\n",buffer);
    printf("Listening...\n");

    int Client_socket_first = accept(Server_socket_first, NULL,NULL);
    assert(Client_socket_first!=-1);

    //check why there is NULL, NULL
    
    int Listen_check_second = listen(Server_socket_second,Number_of_connections);
    assert(Listen_check_second!=-1);
//
    system("clear");
    ////printf("%s\n",buffer);
    printf("Listening...\n");
//
    int Client_socket_second = accept(Server_socket_second, NULL,NULL);
    assert(Client_socket_second!=-1);

    //handle_communication_server(Client_socket_first);

    handle_communication_between_clients(Client_socket_first,Client_socket_second);

    printf("End of communication.\n");

    close(Server_socket_first);

    close(Server_socket_second);

    //close(Server_socket_first);
    close(Client_socket_first);
    //close(Server_socket_second);
    //close(Client_socket_second);
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

void handle_communication_between_clients(int Socket_first, int Socket_second)
{
    char Message_to_first[256] = "Send hello message to your interlocutor.";
    char Message_to_second[256] = "Wait for message from your interlocutor.";

    send(Socket_first,&Message_to_first,sizeof(Message_to_first),0);
    send(Socket_second,&Message_to_second,sizeof(Message_to_second),0);

    char Message_to[256];
    char Message_from[256];

    while (strcmp(Message_from,"EXIT")!=0)
    {
        recv(Socket_first,&Message_from,sizeof(Message_from),0);
        strncpy(Message_from,Message_to,sizeof(Message_from));
        send(Socket_second,&Message_to,sizeof(Message_to),0);
        printf("%s\n",Message_from);
        printf("%s\n",Message_to);

        recv(Socket_second,&Message_from,sizeof(Message_from),0);
        strncpy(Message_from,Message_to,sizeof(Message_from));
        send(Socket_first,&Message_to,sizeof(Message_to),0);
        printf("%s\n",Message_from);
        printf("%s\n",Message_to);
    }
}
#include "client.h"

void client()
{
    int Client_socket = socket(AF_INET,SOCK_STREAM,0);
    assert(Client_socket!=-1);

    struct sockaddr_in Server_address;
    Server_address.sin_family = AF_INET;

    uint16_t Port_number = get_port_number_client();
    Server_address.sin_port = htons(Port_number);
    //Server_address.sin_port = htons(55555);

    //get_ip4_address();

    system("clear");

    //int Address_correct_check = inet_aton(Chosen_ip4_address,&Server_address.sin_addr);
    int Address_correct_check = inet_aton("192.168.0.206",&Server_address.sin_addr);
    assert(Address_correct_check!=0);

    int Connect_check = connect(Client_socket,(const struct sockaddr*)&Server_address,sizeof(Server_address));
    assert(Connect_check!=-1);

    handle_communication_client(Client_socket);

    printf("End of communication.\n");

    close(Client_socket);
}

uint16_t get_port_number_client()
{
    int Chosen_port_number = 0;
    
    while (Chosen_port_number<49152||Chosen_port_number>65535)
    {
        system("clear");
        printf("Choose port number between 49152 and 65535\n\n");
        printf("    Port number: ");
        scanf("%d",&Chosen_port_number);
    }

    return (uint16_t)Chosen_port_number;
}

void get_ip4_address()
{
    int Address_correct_check = 0;

    while(Address_correct_check==0)
    {
        memset(Chosen_ip4_address,'0',INET_ADDRSTRLEN*sizeof(char));
        system("clear");
        printf("Input correct Ipv4 address of server to connect to\n\n");
        printf("    IP Address: ");
        scanf("%s",Chosen_ip4_address);
        Address_correct_check = inet_pton(AF_INET,Chosen_ip4_address,&(Address_check.sin_addr));
    }
}

void handle_communication_client(int Socket)
{
    char Message_from[256];
    recv(Socket,&Message_from,sizeof(Message_from),0);
    printf("%s\n\n",Message_from);

    char Message_to[256];

    //First client
    if(strcmp(Message_from,"Wait for message from your interlocutor.")!=0)
    {
        while (strcmp(Message_to,"EXIT")!=0)
        {
            printf("    Send message: ");
            //scanf(" %s",Message_to);
            fgets(Message_to,256,stdin);
            printf("%s",Message_to);
            send(Socket,&Message_to,sizeof(Message_to),0);
            recv(Socket,&Message_from,sizeof(Message_from),0);
            printf("\n\n");
            printf("Received message: %s\n\n",Message_from);
        }
    }

    //Second client
    //if(strcmp(Message_from,"Send hello message to your interlocutor."));
    else
    {
        while (strcmp(Message_to,"EXIT")!=0)
        {
            recv(Socket,&Message_from,sizeof(Message_from),0);
            printf("\n\n");
            printf("Received message: %s\n\n",Message_from);
            printf("    Send message: ");
            //scanf(" %s",Message_to);
            fgets(Message_to,256,stdin);
            send(Socket,&Message_to,sizeof(Message_to),0);
        }
    }
    
    /*
    system("clear");
    printf("%s\n\n",Message);
    printf("    Your message:");
    scanf("%s",Message);
    send(Socket,&Message,sizeof(Message),0);
    while (strcmp(Message,"EXIT")!=0)
    {
        //system("clear");
        printf("%s\n\n",Message);
        printf("    Your response:");
        scanf("%s",Message);
        send(Socket,&Message,sizeof(Message),0);
    }
    */
}
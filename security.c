#include "security.h"

void check(int Number_of_inputs, char** Inputs)
{
    if(Number_of_inputs<REQUIRED_INPUTS)
    {
        printf("%s\n\n",ERROR);
        printf("%s\n\n",NEEDS_ARGUMENTS);
        printf("%s\n",HOW_TO_RUN);
        exit(1);
    }
    
    if(Number_of_inputs>REQUIRED_INPUTS)
    {
        printf("%s\n\n",ERROR);
        printf("%s\n\n",TOO_MANY_ARGUMENTS);
        printf("%s\n",HOW_TO_RUN);
        exit(1);
    }

    if(strcmp(Inputs[Number_of_inputs-1],SERVER)&&strcmp(Inputs[Number_of_inputs-1],CLIENT))
    {
        printf("%s\n\n",ERROR);
        printf("%s %s\n\n",Inputs[Number_of_inputs-1],WRONG_ARGUMENTS);
        printf("%s\n",HOW_TO_RUN);
        exit(1);
    }

    strncpy(Answer,Inputs[Number_of_inputs-1],LENGTH_CORRECT);

    if(!strcmp(Answer,SERVER))
    {
        server();
    }
    else
    {
        client();
    }
}
#include "Compare_Message.h"

int Compare_Message(char message[], char letters[])
{

    int m_length= strlen(message);
    int l_length=strlen(letters);
    int i,j,k=0;
    char aux[m_length];
    memset(aux, 0, m_length);

// First remove all characters not considered letters and maintain the same case:
    for (i = 0; letters[i]=='\0'; ++i)
        letters[i]=tolower(letters[i]);

    for (i = 0, j = 0; message[i]; ++i)
    {
        message[i]=tolower(message[i]);
        if (isalpha(message[i]))
        {
            aux[j++] = message[i];

        }
    }

    strcpy(message,aux);

// Compare the 2 strings:
    for(i=0; message[i] != '\0'; ++i)
    {
        for(j=0; letters[j] != '\0'; ++j)
        {
            if (message[i] != letters[j])
            {
                if (j==(strlen(letters)-1))
                {
                    k=1;
                }
            }else break;

        }

    }
// Result:
    if(k)
        return(0);
    else
        return(1);


}





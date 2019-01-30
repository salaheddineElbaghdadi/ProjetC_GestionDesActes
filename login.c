#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "const.h"
#include "login.h"

int _login()
{
    char pass[20];

    system(CLEAR_SCREEN);
    printf("Mot de passe: ");
    scanf("%s", pass);

    if (strcmp(pass, "ensias2019") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
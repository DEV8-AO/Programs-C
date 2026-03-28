#include <stdio.h>
#include <stdlib.h>

char m[2][2] ;

int main (){  system("cls");
    int opc;
    do
    {
        printf("Bem-vindo ao teatro ;)\n");
    
        for(int i=0;i<17;i++){printf("=");}
        printf("\n1. Fazer reserva\n2. Lista de reserva\n3. Sair\n");
        for(int i=0;i<17;i++){printf("=");}
        printf("\nChoice: ");  scanf("%i",&opc);

        system("cls");
switch (opc)
{
    case 1:
printf("h");
    break;

    case 2:
printf("p");
    break;

    case 3:
printf("Thanks for use my code, finish program...");
    break;

default:
printf("Worong choice, try again...\n");
    break;
}
        

    } while (opc!=3); 



}




int fzr(void){ system("cls");
    int f,c;

    printf("Choice de fila: ");scanf("%i",&f);
    printf("Choice de cadeira:  ");scanf("%i",&c); 

    return 0;
}

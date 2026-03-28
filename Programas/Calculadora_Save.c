#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
int main (){

    system ("cls");
   
    printf ("\tPlease, enter the following personal data. \n");

char name [50]; printf ("Write your firt and last name: ");    scanf ("%[^\n]", name);
int age; printf ("Write your current age: ");                    scanf ("%i",&age);
float hei; printf ("Please, write your current heigth: ");      scanf ("%f",&hei);
     
                    system ("cls");

int s, ss; printf ("Write your password: "); scanf ("%i", &s);
 system ("cls");
                    
do
{
printf ("Confirm yoyur password: "); scanf ("%i", &ss);
system ("cls");
} while ( s!=ss);



                    system ("cls");
        printf ("Thanks, yours informencion will be salve. ");

                                        int a,b,opc;
                                        char opcc [3];
do{
printf ("Choice the opcs:");
printf ("\n1. Plus\n2. Subrtrait\n3. Division\n4. Multiplicacion\nChoice: "); scanf ("%i",&opc);
system ("cls");

switch (opc)
{
case 1:
printf("Write the firts number: "); scanf ("%i",&a); 
printf("Write the secund number: "); scanf ("%i",&b);

system ("cls");
printf("%i + %i = %i",a,b,a+b );
printf("\nThanks for use my code");
    break;

case 2:
printf("Write the firts number: "); scanf ("%i",&a); 
printf("Write the secund number: "); scanf ("%i",&b);

system ("cls");
printf("%i - %i = %i",a,b,a-b );
printf("\nThanks for use my code");
    break;

case 3:
printf("Write the firts number: "); scanf ("%i",&a); 
printf("Write the secund number: "); scanf ("%i",&b);

system ("cls");
printf("%i / %i = %i",a,b,a/b );
printf("\nThanks for use my code");
    break;

case 4:
printf("Write the firts number: "); scanf ("%i",&a); 
printf("Write the secund number: "); scanf ("%i",&b);

system ("cls");
printf("%i x %i = %i",a,b,a*b );
printf("\nThanks for use my code");
    break;

default:
printf ("Error choice.");
    break;
}
    printf ("\nDo you want continue this program?\nyes (y) or not (n) :"); scanf ("%2s",opcc); 
    system ("cls");
    
} while (strcmp(opcc, "y")==0);
return 0 ; 
}
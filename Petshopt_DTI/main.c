#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[10];
int dia = 0;
int mes = 0;
int ano = 0;
int  validacao = 0;

typedef struct // definição do tipo struct
{
    char nome[50];
    float distancia;
    float pequeno;
    float grande;
    float pequeno_fds;
    float grande_fds;
    float valor_total;
}TCanil;

TCanil Canis[3]; // declaração da struct Canis do tipo Tcanil

int main()
{
    while(validacao == 0 )
    {
    printf("\nDigite a data desejada para o banho:(Formato: xx/xx/xxxx )\n");
    scanf("%i/%i/%i", &dia, &mes, &ano); //armazena data inserida pelo usuario
    validacao = valida_data(dia, mes, ano); //chamada func para validar data inserida
    }

    system("pause");
    return 0;
}


int valida_data(int dia, int mes, int ano)
    {
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2200)) //cheaca se os numeros sao validos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //checa se o ano e bissexto
            {
                return 1;
            }
            if (dia <= 28 && mes == 2) //checa o mes de feveireiro
            {
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //checa os meses de 30 dias
            {
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
            {
                return 1;
            }
            else
            {
                printf("\ndata invalida\n");
                return 0;
            }
      }
       else
           {
                printf("\ndata invalida\n");
                return 0;
           }
}

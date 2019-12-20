#include <stdio.h>
#include <stdlib.h>
#include <string.h>


///----------------------------------------------------------
/// Declaração de todas variaveis e structs
///----------------------------------------------------------
char data[10];
int dia = 0;
int mes = 0;
int ano = 0;
int i;
int validacao = 0;
int dia_semana;
int qt_pequenos;
int qt_grandes;

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
///----------------------------------------------------------

int main()
{
    init_structs();

    while(validacao == 0 )
    {
    printf("\nDigite a data desejada para o banho:(Formato: xx/xx/xxxx )\n");
    scanf("%i/%i/%i", &dia, &mes, &ano); //armazena data inserida pelo usuario "/" é um delimitador
    validacao = valida_data(dia, mes, ano); //chamada para validar data inserida
    }
    dia_semana = calc_data(dia, mes, ano);//chamada para verificar se é dia de semana ou nao
    printf("Digite a quantidade de Dog's pequenos: ");
    scanf("%i", &qt_pequenos);
    printf("Digite a quantidade de Dog's grandes: ");
    scanf("%i", &qt_grandes);
    calc_preco();//chamada para calcular os valores por petshop
    printf("\nValor Total %s: RS %.02f", Canis[0].nome, Canis[0].valor_total);
    printf("\nValor Total %s: RS %.02f", Canis[1].nome, Canis[1].valor_total);
    printf("\nValor Total %s: RS %.02f\n", Canis[2].nome, Canis[2].valor_total);

    system("pause");
    return 0;
}

///-------------------------------------------------------------------------------
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

///-------------------------------------------------------------------------------
int calc_data(int dia, int mes, int ano)
{
    int a = (14 - mes) /12;
    int y = ano - a;
    int m = mes + (12*a) - 2;
    int q = dia + 31*m/12 + y + y/4 - y/100 + y/400;
    int d = q % 7;

    if(d == 0 || d == 6)
    {
        return(0); //indica que é sabado ou domingo
    }else
    {
        return(1); //indica que é dia de semana - segunda a sexta
    }

}

///------------------------------------------------------------------------------
void init_structs()// Inicialização das struct's e população das mesmas
{
    strcpy(Canis[0].nome, "Meu Canino Feliz" );
    Canis[0].distancia = 2;
    Canis[0].pequeno = 20;
    Canis[0].grande = 40;
    Canis[0].valor_total = 0;

    strcpy(Canis[1].nome, "Vai Rex" );
    Canis[1].distancia = 1.7;
    Canis[1].pequeno = 15;
    Canis[1].grande = 50;
    Canis[1].valor_total = 0;

    strcpy(Canis[2].nome, "ChowChawgas" );
    Canis[2].distancia = 0.8;
    Canis[2].pequeno = 30;
    Canis[2].grande = 45;
    Canis[2].valor_total = 0;
}

///-------------------------------------------------------------------
void calc_preco()
{
    for(i=0; i<3; i++)
    {
        if(dia_semana)
        {
            Canis[i].valor_total = (Canis[i].pequeno * qt_pequenos) + (Canis[i].grande * qt_grandes);

        }else
        {
            switch(i) //calcula o valor no final de semana de acordo com cada regra de negocio
            {
            case 0:
                Canis[i].valor_total = ((Canis[i].pequeno * qt_pequenos) + (Canis[i].grande * qt_grandes)) *1.2;
            case 1:
                Canis[i].valor_total = ((Canis[i].pequeno + 5) * qt_pequenos) + ((Canis[i].grande + 5) * qt_grandes);
            case 2:
                Canis[i].valor_total = (Canis[i].pequeno * qt_pequenos) + (Canis[i].grande * qt_grandes);
            }

        }
    }
}

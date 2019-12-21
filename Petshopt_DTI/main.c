#include <stdio.h>
#include <stdlib.h>

///----------------------------------------------------------
/// Declaração de todas variaveis e structs
///----------------------------------------------------------

char data[10];
int data_conv[10];
int dia = 0;
int mes = 0;
int ano = 0;
int validacao = 0;
int dia_semana;
int qt_pequenos;
int qt_grandes;
int teste;

typedef struct // definição do tipo struct
{
    char nome[50];
    float distancia;
    float pequeno;
    float grande;
    float valor_total;
}TCanil;

TCanil Canis[3]; // declaração da struct Canis do tipo Tcanil
///----------------------------------------------------------

int main()
{
    init_structs();
    printf("\n\t\t\tBem vindo, Eduardo!\n");

    while(validacao == 0 )
    {
        printf("\nDigite a data desejada para o banho( Formato: xx/xx/xxxx ), e pressione ENTER: ");
        gets(data); //armazena data inserida pelo usuario "/" é um delimitador
        if(teste_entrada(data))
        {
            validacao = valida_data(dia, mes, ano); //chamada para validar data inserida
        }
    }

    dia_semana = calc_data(dia, mes, ano);//chamada para verificar se é dia de semana ou nao

    printf("\nDigite a quantidade de Dog's pequenos, e pressione ENTER: ");
    scanf("%i", &qt_pequenos);
    printf("\nDigite a quantidade de Dog's grandes, e pressione ENTER: ");
    scanf("%i", &qt_grandes);

    calc_preco();//chamada para calcular os valores por petshop

    teste_valores();

    printf("\nPetshop com melhor preco para a data:\t%s", Canis[teste].nome);
    printf("\nValor total dos banhos: \t\tRS: %.02f\n\n", Canis[teste].valor_total);

    system("\npause");
    return 0;
}
///-------------------------------------------------------------------------------
/// Declaraçao das funçoes utilizadas no codigo
///-------------------------------------------------------------------------------
int valida_data(int dia, int mes, int ano)
    {
        if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2200)) //cheaca se os numeros sao validos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) // confirmar se o ano e bissexto
            {
                return 1;
            }
            if (dia <= 28 && mes == 2) // confirmar o mes de feveireiro
            {
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) // confirmar os meses de 30 dias
            {
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) // confirmar os meses de 31 dias
            {
                return 1;
            }
            else
            {
                printf("\nData invalida!\n");
                return 0;
            }
      }else
           {
                printf("\nData invalida!\n");
                return 0;
           }
}

///-------------------------------------------------------------------------------
int calc_data(int dia, int mes, int ano)
{
    int a = (14 - mes) /12;
    int y = ano - a;
    int m = mes + (12 * a) - 2;
    int q = dia + 31 * m / 12 + y + y / 4 - y / 100 + y / 400;
    int d = q % 7;

    if(d == 0 || d == 6)
    {
        return(0); // indica que é sabado ou domingo
    }else
    {
        return(1); // indica que é dia de semana - segunda a sexta
    }

}

///------------------------------------------------------------------------------
void init_structs() // Inicialização das struct's e população das mesmas
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
void calc_preco() // Calculo do preço de cada estabelecimento de acordo com as regras de negocio
{
int i;
    for(i=0; i<3; i++)
    {
        if(dia_semana)
        {
            Canis[i].valor_total = (Canis[i].pequeno * qt_pequenos) + (Canis[i].grande * qt_grandes);

        }else
        {
            switch(i) // calcula o valor no final de semana
            {
            case 0:
                Canis[i].valor_total = (Canis[i].pequeno * 1.2 * qt_pequenos) + (Canis[i].grande * 1.2 * qt_grandes);
                break;
            case 1:
                Canis[i].valor_total = ((Canis[i].pequeno + 5) * qt_pequenos) + ((Canis[i].grande + 5) * qt_grandes);
                break;
            case 2:
                Canis[i].valor_total = (Canis[i].pequeno * qt_pequenos) + (Canis[i].grande * qt_grandes);
                break;
            }

        }
    }
}

///---------------------------------------------------------------------
void teste_valores() // Determinar menor custo, desempate por menor distancia
{
int i;
int menor = Canis[0].valor_total; // primeira referencia para teste
    teste = 0;
    for(i=0; i<3; i++)
    {
         if(menor >= Canis[i].valor_total); // pode ser menor ou igual
         {
             if(menor > Canis[i].valor_total)
             {
                menor = Canis[i].valor_total;
                teste = i;
             }else if(menor == Canis[i].valor_total) // se não é menor, logo é igual, entao teste da distancia
             {
                 if(Canis[i].distancia < Canis[teste].distancia) // desempate por distancia
                 {
                     teste = i;
                 }
             }
         }
    }
}

///------------------------------------------------------------------------
void teste_entrada(char data[10]) // verificaçao dos parametros de entrada e conversao para decimal
{
    for(int i=0; i<10; i++)
    {
        if((data[i] >= '0' && data[i] <= '9') || (data[i] == '/'))
        {
            data_conv[i] = data[i] - '0';
        }else
        {
            return 0;
        }
    }
    for(int i=0; i<10; i++)
    {
        data_conv[i] = data[i] - '0';
    }
    dia = data_conv[0] * 10  + data_conv[1];
    mes = data_conv[3] * 10  + data_conv[4];
    ano = data_conv[6] * 1000 + data_conv[7] * 100 + data_conv[8] * 10 + data_conv[9];
    return 1;
}

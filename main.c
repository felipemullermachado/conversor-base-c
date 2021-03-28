/*
Descricao - Este programa serve como uma calculadora de conversão de bases numéricas,
e realiza as seguinte conversões:
binário para octal ou decimal; decimal para binário ou octal; e octal para decimal
*/

#include<stdio.h> // para ter as funções de entrada e saída de daos
#include <stdlib.h> //para utilizar a função system()
#include<math.h> //para fazer as operações de potenciação com a funçao pow()
#include<locale.h>

//Declarando a função que fará o calculo de conversão
int ConversorDeBases(int baseInicial, long int numero, int baseFinal);

int main() {
setlocale(LC_ALL, "Portuguese"); //para que as palavras estejam acentuadas corretamente

    //Declarando as variáveis que serão informadas pelo usuário
    long int numero;
    int baseInicial, baseFinal;

    //Apresentando as informações na tela para o usuário
    printf("Conversor de bases numericas \n");
    printf("Este programa realiza as seguintes conversões: \n");
    printf("- binário para octal ou decimal \n");
    printf("- decimal para binário ou octal \n");
    printf("- octal para decimal \n");
    printf("Digite o número que você deseja converter e a sua base: ");
    //Armazenando o numero e a base inicial declaradas pelo usuário
    scanf("%ld %d", &numero, &baseInicial);

    printf("\n Agora escolha a base da conversão desejada(2, 8 ou 10): ");
    scanf("%d", &baseFinal);

    //Apresentando o resultado da conversão para o usuário
    printf("O número %ld na base %d é igual a: \n %d na base %d \n", numero, baseInicial,
    ConversorDeBases(baseInicial,numero,baseFinal), baseFinal);

    return 0; //para que o número retornado seja inteiro

    system("PAUSE"); //para que o usuário consiga ver o resultado sem o programa fechar
}

//Declaração da função que fará o cálculo da conversão
int ConversorDeBases(int baseInicial, long int numero, int baseFinal) {

    //necessidade de declarar para que o numero retornado seja invertido
    int soma = 0;
    //atribuindo o numero digitado pelo usuário a var quociente
    int quociente = numero;

    int restoDivisao = 0;
    //para saber a posicao do número (e assim o seu expoente)
    int i = 0;


    while (quociente != 0) {
        //aqui estamos fazendo a conta para encontrar os modulos das divisões
        restoDivisao = quociente%baseFinal;
        quociente = quociente / baseFinal;
        //agora, precisamos pegar o resultado do resto e multiplicar pela base inicial potencializada de acordo com sua posicao
        // e então soma-los
        soma = (restoDivisao * (pow(baseInicial,i))) + soma;
        i++;
    }
    return soma;
}

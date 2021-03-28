/*
Descricao - Este programa serve como uma calculadora de convers�o de bases num�ricas,
e realiza as seguinte convers�es:
bin�rio para octal ou decimal; decimal para bin�rio ou octal; e octal para decimal
*/

#include<stdio.h> // para ter as fun��es de entrada e sa�da de daos
#include <stdlib.h> //para utilizar a fun��o system()
#include<math.h> //para fazer as opera��es de potencia��o com a fun�ao pow()
#include<locale.h>

//Declarando a fun��o que far� o calculo de convers�o
int ConversorDeBases(int baseInicial, long int numero, int baseFinal);

int main() {
setlocale(LC_ALL, "Portuguese"); //para que as palavras estejam acentuadas corretamente

    //Declarando as vari�veis que ser�o informadas pelo usu�rio
    long int numero;
    int baseInicial, baseFinal;

    //Apresentando as informa��es na tela para o usu�rio
    printf("Conversor de bases numericas \n");
    printf("Este programa realiza as seguintes convers�es: \n");
    printf("- bin�rio para octal ou decimal \n");
    printf("- decimal para bin�rio ou octal \n");
    printf("- octal para decimal \n");
    printf("Digite o n�mero que voc� deseja converter e a sua base: ");
    //Armazenando o numero e a base inicial declaradas pelo usu�rio
    scanf("%ld %d", &numero, &baseInicial);

    printf("\n Agora escolha a base da convers�o desejada(2, 8 ou 10): ");
    scanf("%d", &baseFinal);

    //Apresentando o resultado da convers�o para o usu�rio
    printf("O n�mero %ld na base %d � igual a: \n %d na base %d \n", numero, baseInicial,
    ConversorDeBases(baseInicial,numero,baseFinal), baseFinal);

    return 0; //para que o n�mero retornado seja inteiro

    system("PAUSE"); //para que o usu�rio consiga ver o resultado sem o programa fechar
}

//Declara��o da fun��o que far� o c�lculo da convers�o
int ConversorDeBases(int baseInicial, long int numero, int baseFinal) {

    //necessidade de declarar para que o numero retornado seja invertido
    int soma = 0;
    //atribuindo o numero digitado pelo usu�rio a var quociente
    int quociente = numero;

    int restoDivisao = 0;
    //para saber a posicao do n�mero (e assim o seu expoente)
    int i = 0;


    while (quociente != 0) {
        //aqui estamos fazendo a conta para encontrar os modulos das divis�es
        restoDivisao = quociente%baseFinal;
        quociente = quociente / baseFinal;
        //agora, precisamos pegar o resultado do resto e multiplicar pela base inicial potencializada de acordo com sua posicao
        // e ent�o soma-los
        soma = (restoDivisao * (pow(baseInicial,i))) + soma;
        i++;
    }
    return soma;
}

#include <stdio.h>

int euclides(int a, int b)
{
    int divsor, divndo, c;

    if(a == 0) return 1;

    if(b > a) {
        divndo = b;
        divsor = a;
    } else {
        divndo = a;
        divsor = b;
    }
    
    do {
        c = divndo % divsor;
        divndo = divsor;
        divsor = c;   
    } while(divndo % divsor != 0);
    return divsor;
}

int main()
{
    char c1, c2, c3;
    int n, N1, N2, D1, D2, num, den, numS, denS, e;
    
    printf("Insira o Numero de Casos: \n ");
    scanf("%i", &n);

    int i;
    for (i = 0; i < n; ++i) {
        
        scanf("%i %c %i %c %i %c %i", &N1, &c1, &D1, &c2, &N2, &c3, &D2);
        
        if(c2 == '+') {
            num = ((N1 * D2) + (N2 * D1));
            den = (D1 * D2);
        } else if(c2 == '-') {
            num = ((N1 * D2) - (N2 * D1));
            den = (D1 * D2);
        } else if(c2 == '*') {
            num = (N1 * N2);
            den = (D1 * D2);
        } else {
            num = (N1 * D2);
            den = (N2 * D1);
        }

        e = euclides(num, den);
        numS = num / e;
        denS = den / e;

        if(numS > 0 && denS > 0) {
            printf("%i/%i = %i/%in", num, den, numS, denS);
        }
        else
        {
            if(denS < 0) {
                denS = -denS;
                numS = -numS;
            }
            printf("%i/%i = %i/%in", num, den, numS, denS);
        }
    }

    return 0;
}

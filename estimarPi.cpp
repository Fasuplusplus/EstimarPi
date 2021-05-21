//estimar Pi con un círculo de r=1 y puntos aleatorios
#include <iostream>
#include <cstdio>
#include <cmath>
float rand1 = 0; //números aleatorios
float rand2 = 0;
int randN() //2 números pseudoaleatorios entre 0 y 1
{
    rand1 = (((float)rand()) / (float)RAND_MAX);
    rand2 = (((float)rand()) / (float)RAND_MAX);
    return 0;
}
bool isInCircle(int r) //comprobar si el número aleatorio entra dentro de un círculo de radio r
{
    bool i = 0;
    if (((pow(rand1, 2)) + (pow(rand2, 2))) <= (pow(r, 2)))
    {
        i = 1;
    }
    return i;
}
double probability(double reps) //calcular probabilidad de que el punto caiga dentro del círculo con (reps) repeticiones
{
    double strikes = 0; //cantidad de puntos dentro del círculo
    for (unsigned long int i = 0; i < reps; i++)
    {
        randN();
        strikes = strikes + isInCircle(1);
    }
    return (((double)strikes) / ((double)reps));
}
double Pi()
{
    return (4 * probability(1000000000)); //0-4294967295; 1min por mil millones de repeticiones aprox.
}
int main()
{
        printf("%f\n", Pi());
    
}
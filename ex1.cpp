#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

//define as dimensões da matriz
#define M 4
#define N 5

//matriz binária
int m[M][N] = { {1,0,1,0,0},
                {1,0,1,1,1},
                {1,1,1,1,1},
                {1,0,0,1,0} };

//variáveis auxiliares
int contador = 0;
int sequencia = 0;
int vetArea[M];
int ctr = 0; // controla vetor de resultados
int saida = 0;

//variáveis que guardam onde está o inicio da sequencia de 1 na matriz m[i][j]
bool primeiro = false;
int ai = 0;
int aj = 0;

//variáveis que guardam onde está o fim da sequencia de 1 na matriz m[i][j]
int bi = 0;
int bj = 0;



//função que verifica se a sequencia encontrada é parte de um retângulo
void testaRetangulo(int m[][N], int ai, int aj, int bj, int cont) {
    int area = 0;
    int saida = 0;


    for (int i = ai; i < M; i++) {
        int flag = 0;

        for (int j = aj; j <= bj; j++) {
            if (m[i][j] == 1) {
                area++;
            }
            else {
                area = area - flag;
                break;
            }
            vetArea[ctr] = area;
            flag++;
        }
    }
    ctr++;
}


//função que retonar o valor da área do maior retângulo
void imprimeMaior(int v[]) {
    for (int i = 0; i < M; i++) {
        if (v[i] > saida) {
            saida = v[i];
        }
    }
    cout << "O maior retangulo da matriz tem a area de: " << saida << endl;
}


//função principal
int main()
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {


            if (m[i][j] == 1) {
                contador++;

                if (primeiro == false) {
                    ai = i;
                    aj = j;
                    primeiro = true;
                }
            }


            if (m[i][j] == 0) {
                contador = 0;
                primeiro = false;
            }

            if (sequencia < contador) {
                sequencia = contador;
                bi = i;
                bj = j;
            }

            if (j == 4) {
                if (sequencia > 1) {
                    testaRetangulo(m, ai, aj, bj, contador);
                }
            }
        }

        primeiro = false;
        ai, aj = 0;
        bi, bj = 0;
        sequencia = 0;
        contador = 0;
    }
    imprimeMaior(vetArea);
}

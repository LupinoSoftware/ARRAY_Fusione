// AUTHOR:Giuliano Lupi
//DATE:08/04/2022
//TITLE:FUSIONE DI DUE ARRAY 
/*ALGORITHM:Fonde due array in uno seguendo l'ordine crescente.*/
#include <iostream>

using namespace std;
//PUNTO 1
void fusione(int V1[], int V2[], int V3[], int n, int n2) {
    int i = 0, j = 0, k = 0;
    do {
        if (V1[i] < V2[j])
            V3[k++] = V1[i++];
        else if (V1[i] == V2[j]) {//PUNTO 2
            V3[k++] = V1[i++];
            j++;
        }  
        else
            V3[k++] = V2[j++];

    } while (i < n && j < n2);
    //copio la coda dell'array non ancora terminato
    if (i == n)
        for (int y = j; y < n2; y++)
            V3[k++] = V2[y];
    else
        for (int y = i; y < n; y++)
            V3[k++] = V1[y];
}

//PUNTO 3
void fusione(int V1[], int V2[], int V3[], int n, int n2, int n3) {
    int i = 0, j = 0, k = 0, uguali=0;
    do {
        if (i < n && j < n2) {
            if (V1[i] < V2[j])
                V3[k++] = V1[i++];
            else if (V1[i] == V2[j]) {
                V3[k++] = V1[i++];
                j++;
                uguali++;
            }
            else
                V3[k++] = V2[j++];
        }
        else {
            if (i == n)
                for (int y = j; y < n2; y++)
                    V3[k++] = V2[y];
            else
                for (int y = i; y < n; y++)
                    V3[k++] = V1[y];
        }
    } while (k < n3-uguali);
}

void visualizza(int Arr[], int n) {

    for (int i = 0; i < n; i++)
        if (Arr[i] != 0) {//E' tutto inizializzato a 0
            cout << Arr[i] << "\t";
        }
    cout << endl;

}



int main() {
    int A[7] = { 1,3,5,8,9,12,13 };
    int B[8] = { 2,4,6,8,10,12,15,16 };
    int C[15] = { 0 };
    fusione(B, A, C, 8, 7,15);
    /*FUNZIONE fusione(int A[], int B[], int C[], int N, int N2, int N3)
    * A[]=primo array
    * B[]=secondo array
    * C[]=terzo array
    * N=lunghezza primo array
    * N2=lunghezza secondo array
    * N3=lunghezza terzo array
    */
    visualizza(C, 15);

}

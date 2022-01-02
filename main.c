#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <mem.h>

#define MAXN 20
#define MAXM 20

typedef struct{
    int punteggio;
    int indice;
} squadra;

int ricercamassimo (int v[], int n);

int main(){
    int Tabellone[MAXN][MAXM]={{0},{0}};
    FILE* fp;
    int i=0,j=1,k=0;
    char punteggio[2*MAXM+1];

    if((fp=fopen("campionato.txt", "r"))==NULL){
        fprintf(stderr, "Errore nell'apertura del file.\n");
        return EXIT_FAILURE;
    }

    fgets(punteggio, 2*MAXM+1, fp);
    for(i=0; i<strlen(punteggio); i++){
        if(isalnum(punteggio[i])){
            Tabellone[0][k]=punteggio[i]-'0';
            k++;
        }
    }

    while(!feof(fp)){
        for (i=0; i<k; i++){
            fscanf(fp, "%d", &Tabellone[j][i]);
        }
        j++;
    }

    int nrighe=j;
    fclose(fp);

    for (j=0; j<nrighe-1; j++){
        for(i=0; i<k; i++){
            printf("%d ", Tabellone[j][i]);
        }
        printf("\n");
    }

    int punti[nrighe-1];
    for (int n=0; n<nrighe-1; n++){
        punti[n]=0;
    }
    int l;

    for (j=0; j<k; j++){
        l=0;
        for (i=0; i<nrighe-1; i++){
            //Ricercamassimo
            punti[l]=punti[l]+Tabellone[i][j];
            l++;
        }
        printf("Capolista: %d\n", ricercamassimo(punti, nrighe-1)+1);
    }

    return 0;
}

int ricercamassimo(int v[], int n){
    int max=v[0];
    int indice=0;
    for (int i=1; i<n; i++){
        if(v[i]>=max){
            max=v[i];
            indice=i;
        }
    }

    return indice;
}

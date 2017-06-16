#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define max_tree 3
#define nro_filhos 5

typedef struct _habilidade {
    int id;
    int nivel;
    int habilidade_pre_req;
    int nivel_pre_req;
    int n_filhos;
    int filhos[nro_filhos];
} habilidade;

void init_arvore(habilidade* arvore)
{
    int i=0,j=0;

    for(i=0; i<max_tree; i++){

        arvore[i].id = 0;
        arvore[i].nivel = 0;
        arvore[i].habilidade_pre_req = 0;
        arvore[i].nivel_pre_req = 0;
        arvore[i].n_filhos = 0;

        for(j=0;j<nro_filhos;j++){
             arvore[i].filhos[j] = 0;
        }

    }

}

void validate_hab_req(habilidade* arvore, int nroHabilidade)
{
    int i=0, j=0, habRequirido=0;

    for(i=0; i < nroHabilidade; i++){
        for(j=0; j < arvore[i].n_filhos; j++){
            arvore[arvore[i].filhos[j]-1].habilidade_pre_req = arvore[i].id;
            if(arvore[arvore[i].filhos[j]-1].nivel_pre_req > habRequirido){
                habRequirido = arvore[arvore[i].filhos[j]-1].nivel_pre_req;
            }
        }
        arvore[i].nivel = habRequirido;
        habRequirido=0;
    }

}

void init_program(habilidade* arvore)
{
    int i=0, j=0, k=0, print=0, nroHabilidade=0, nroHabilidade2=0, intAux=0, intAux2=0, contadorNivel=0, contChar=0, auxMult=0, sizeofArray=0, sizeofArray2=0, contadorArrayAux=0;
    char vetAux[100],vetAux2[10];
    int matAuxInteiro[100][8], matAuxInteiro2[100][2], auxMatrInteiro = 0;

    scanf("%d", &nroHabilidade);

    for(i=0; i < nroHabilidade; i++){

        fflush(stdin);
        gets(vetAux);
        intAux=0;
        auxMatrInteiro = 0;

        for(k=0; k < 100; k++){

            if(vetAux[k] == ' ' || vetAux[k] == '\0'){
                print = 1;
                contChar = 0;
                if(vetAux[k] == '\0') k=100;
            }else{
                vetAux2[contChar] = vetAux[k];
                vetAux2[contChar+1] = '\0';
                contChar++;
                print = 0;
            }

            if(print != 0){

                sizeofArray2=0;
                intAux=0;

                for(j=0; vetAux2[j] != '\0'; j++){
                    sizeofArray2++;
                }

                sizeofArray = sizeofArray2;

                for(j=0; j < sizeofArray2; j++){

                    if(sizeofArray > 2){
                        auxMult = pow(10,sizeofArray);
                        auxMult = auxMult/10;
                    }else if (sizeofArray == 2){
                        auxMult = 10;
                    }else{
                        auxMult = 1;
                    }

                    intAux2 = vetAux2[j];
                    intAux2 = intAux2 - 48;
                    intAux += (intAux2*auxMult);
                    --sizeofArray;
                }
                matAuxInteiro[i][auxMatrInteiro] = intAux;
                ++auxMatrInteiro;
                ++contadorArrayAux;
            }
        }
    }

    for(i=0; i < nroHabilidade; i++){

        arvore[i].id = matAuxInteiro[i][0];
        arvore[i].nivel_pre_req = matAuxInteiro[i][1];
        arvore[i].n_filhos = matAuxInteiro[i][2];

        for(j=0; j < arvore[i].n_filhos; j++){

            switch(j){

                case 0:{
                    arvore[i].filhos[j] = matAuxInteiro[i][3];
                    break;
                }
                case 1:{
                    arvore[i].filhos[j] = matAuxInteiro[i][4];
                    break;
                }
                case 2:{
                    arvore[i].filhos[j] = matAuxInteiro[i][5];
                    break;
                }
                case 3:{
                    arvore[i].filhos[j] = matAuxInteiro[i][6];
                    break;
                }
                case 4:{
                    arvore[i].filhos[j] = matAuxInteiro[i][7];
                    break;
                }
            }
        }

    }

    validate_hab_req(arvore,nroHabilidade);

    scanf("%d", &nroHabilidade2);

    for(i=0; i < nroHabilidade2; i++){

        fflush(stdin);
        gets(vetAux);
        intAux=0;
        auxMatrInteiro = 0;

        for(k=0; k < 100; k++){

            if(vetAux[k] == ' ' || vetAux[k] == '\0'){
                print = 1;
                contChar = 0;
                if(vetAux[k] == '\0') k=100;
            }else{
                vetAux2[contChar] = vetAux[k];
                vetAux2[contChar+1] = '\0';
                contChar++;
                print = 0;
            }

            if(print != 0){

                sizeofArray2=0;
                intAux=0;

                for(j=0; vetAux2[j] != '\0'; j++){
                    sizeofArray2++;
                }

                sizeofArray = sizeofArray2;

                for(j=0; j < sizeofArray2; j++){

                    if(sizeofArray > 2){
                        auxMult = pow(10,sizeofArray);
                        auxMult = auxMult/10;
                    }else if (sizeofArray == 2){
                        auxMult = 10;
                    }else{
                        auxMult = 1;
                    }

                    intAux2 = vetAux2[j];
                    intAux2 = intAux2 - 48;
                    intAux += (intAux2*auxMult);
                    --sizeofArray;
                }
                matAuxInteiro2[i][auxMatrInteiro] = intAux;
                ++auxMatrInteiro;
                ++contadorArrayAux;
            }
        }
    }

    for(i=0; i < nroHabilidade2; i++){
        for(j=0; j < nroHabilidade; j++){
            if(arvore[j].id == matAuxInteiro2[i][0]){
                arvore[j].nivel = matAuxInteiro2[i][1];
            }
        }
    }

    for(i=0; i < nroHabilidade; i++){
        printf("ID: %d\tNiv: %d\n", arvore[i].id, arvore[i].nivel);
        contadorNivel += arvore[i].nivel;
    }
    printf("TOTAL: %d\n", contadorNivel);


}

int main()
{
    habilidade arvore[max_tree];

    init_arvore(&arvore);
    init_program(&arvore);

    return 0;
}

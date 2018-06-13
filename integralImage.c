#include <stdio.h>
#include <stdlib.h>

//Adaptado de https://github.com/ckreisl/summed-area-table/blob/master/main.cpp, acesso em 12/06/2018

#include <stdio.h>
#include <stdlib.h>

//ESTE CÓDIGO CALCULA A IMAGEM INTEGRAL UTILIZANDO MATRIZ E VETOR

int main(){
	
	int matriz[2][2]={{2,1},{5,4}};
	int matrizIntegral[2][2]={{0,0},{0,0}};
	int vetor[4]={2,1,5,4};
	int vetorIntegral[4]={0,0,0,0};
	int y=0,x=0, valorMatriz=0, valorVetor=0;
	
	for(y = 0; y < 2; y++){
		for(x = 0; x < 2; x++){
			valorMatriz = matriz[x][y];
			valorVetor = vetor[y*2+x];
			if(y>0){
				valorMatriz += matrizIntegral[x][y-1];
				valorVetor += vetorIntegral[(y-1)*2+x];
			}
			if(x>0){
				valorMatriz += matrizIntegral[x-1][y];
				valorVetor += vetorIntegral[y*2+x-1];
			}
			if(x>0 && y>0){
				valorMatriz -= matrizIntegral[x-1][y-1];
				valorVetor -= vetorIntegral[(y-1)*2+x-1];
			}
			matrizIntegral[x][y] = valorMatriz; 
			vetorIntegral[y*2+x] = valorVetor;
		}
	}
	
	//Exibe a matriz original
	for(y=0; y<2; y++){
		for(x=0; x<2; x++){
			printf(" %d ", matriz[y][x]);
		}
		printf("\n");
	}
	
	printf("\n");
	//Exibe a matriz integral
	for(y=0; y<2; y++){
		for(x=0; x<2; x++){
			printf(" %d ", matrizIntegral[y][x]);
		}
		printf("\n");
	}
	
	printf("\n");
	//Exibe o vetor original
	for(y=0; y<2; y++){
		for(x=0; x<2; x++){
			printf(" %d ", vetor[y*2+x]);
		}
		printf("\n");
	}
	
	printf("\n");
	//Exibe o vetor integral
	for(y=0; y<2; y++){
		for(x=0; x<2; x++){
			printf(" %d ", vetorIntegral[y*2+x]);
		}
		printf("\n");
	}
	
	return 0;
}


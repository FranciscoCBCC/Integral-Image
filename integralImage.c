#include <stdio.h>
#include <stdlib.h>

//Adaptado de https://github.com/ckreisl/summed-area-table/blob/master/main.cpp, acesso em 12/06/2018

int main(){
	
	int imagemOriginal[4][4] = {{5,2,5,2},
								{3,6,3,6},
								{5,2,5,2},
								{3,6,3,6}};
	int integralImage[4][4], valor;
	
	integralImage[0][0] = imagemOriginal[0][0];
	for(int yLinha = 0; yLinha < 4; yLinha++){
		for(int xColuna=0; xColuna<4; xColuna++){
			valor = imagemOriginal[xColuna][yLinha];
			if(yLinha>0)
				valor += integralImage[xColuna][yLinha-1];
			if(xColuna>0)
				valor += integralImage[xColuna-1][yLinha];
			if(xColuna>0 && yLinha>0)
				valor -= integralImage[xColuna-1][yLinha-1];
			integralImage[xColuna][yLinha] = valor;
		}
	}
	
	//Imagem Original
	printf("Imagem Original\n\n");
	for(int yLinha = 0; yLinha < 4; yLinha++){
		for(int xColuna=0; xColuna<4; xColuna++){
			printf("  %d  ",imagemOriginal[yLinha][xColuna]);
		}
		printf("\n");
	}
	
	//Integral Image
	printf("\nIntegral Image\n\n");
	for(int yLinha = 0; yLinha < 4; yLinha++){
		for(int xColuna=0; xColuna<4; xColuna++){
			printf("  %d  ",integralImage[yLinha][xColuna]);
		}
		printf("\n");
	}
	
	return 0;
}

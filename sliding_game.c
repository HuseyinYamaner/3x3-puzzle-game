#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void ciz(int dizi[3][3]){
	printf("\033[H\033[J");

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(dizi[i][j]==0)
		        printf("[    ]");
			else
			    printf("[ %d ]", dizi[i][j]);
	}
	printf("\n\n");
	
	}
}

void oyna(int dizi[3][3],int *konum_i, int *konum_j,char hamle){
	if((hamle=='w' || hamle=='W') && *konum_i>0){
		dizi[*konum_i][*konum_j]=dizi[*konum_i-1][*konum_j];
		dizi[*konum_i-1][*konum_j]=0;
		(*konum_i)--;
	}
	else if((hamle=='s' || hamle=='S') && *konum_i<2){
		dizi[*konum_i][*konum_j]=dizi[*konum_i+1][*konum_j];
		dizi[*konum_i+1][*konum_j]=0;
		(*konum_i)++;
	}
	else if((hamle=='a' || hamle=='A') && *konum_j>0){
		dizi[*konum_i][*konum_j]=dizi[*konum_i][*konum_j-1];
		dizi[*konum_i][*konum_j-1]=0;
		(*konum_j)--;
	}
	else if((hamle=='d' || hamle=='D') && *konum_j<2){
		dizi[*konum_i][*konum_j]=dizi[*konum_i][*konum_j+1];
		dizi[*konum_i][*konum_j+1]=0;
		(*konum_j)++;
	}
}

int kontrol(int dizi[3][3]){
	int sayac=1,i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==2 && j==2){
				if(dizi[i][j]==0){
					return 1;
				}
				else {
					return 0;
				}
			}
			if(dizi[i][j]!=sayac){
				return 0;
			}
			sayac++;
		}
	}
	return 1;
}

void karistir(int dizi[3][3], int *konum_i, int *konum_j){
	int randomhamle;
	srand(time(NULL));
	for(int i=0;i<100;i++){
		randomhamle=rand()%4; //4 kullaninca 0,1,2,3 sayilarini buluyor tuslara esdeger.
		if (randomhamle == 0) {
            oyna(dizi, konum_i, konum_j, 'w'); 
        } 
        else if (randomhamle == 1) {
            oyna(dizi, konum_i, konum_j, 's');
        } 
        else if (randomhamle == 2) {
            oyna(dizi, konum_i, konum_j, 'a');
        } 
        else if (randomhamle == 3) {
            oyna(dizi, konum_i, konum_j, 'd');
        }
	}
}

int main(){
	int dizi[3][3]={ {1,2,3},{4,5,6},{7,8,0} };
	int konum_i=2,konum_j=2,oyun_devam=1;
	char hamle;

	karistir(dizi,&konum_i, &konum_j);

	while(oyun_devam==1){
		ciz(dizi);
		if(kontrol(dizi)==1){
			printf("Tebrikler, Puzzle Cozuldu!\n");
			break;
		}
		printf("Yapilan Hamle: ");
		scanf(" %c", &hamle);
		if(hamle=='q' || hamle=='Q'){
			oyun_devam=0;
			printf("Oyun Bitti.\n");
		}
		else{
			oyna(dizi,&konum_i,&konum_j,hamle);
		}
	}
	return 0;

}

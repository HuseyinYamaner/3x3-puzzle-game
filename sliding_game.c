#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void randomize(int temparr[8])
{
	int i, j, temp;
	for (i = 0; i < 8; i++)
	{
		j = rand() % 8;
		temp = temparr[i];
		temparr[i] = temparr[j];
		temparr[j] = temp;
	}	
}	

void ata(int dizi[3][3],int temparr[8])
{
for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (i == 2 && j == 2)
			{
				dizi[i][j] = 0;
				continue;
			}
			dizi[i][j] = temparr[i * 3 + j];//0*3+0=0,0*3+1=1,0*3+2=2,1*3+0=3,1*3+1=4,1*3+2=5,2*3+0=6,2*3+1=7,2*3+2=8
		}
	}		
}

void ciz(int dizi[3][3])
{
	printf("-------------\n");
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			printf("[%d]", dizi[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");		
}

int bitir(int dizi[3][3])
{
	int kontrol[3][3] = { {1, 2, 3}, { 4,5,6 }, { 7,8,0 } };
	for (int i = 0;i < 3;i++)
	{
		for (int j = 0;j < 3;j++)
		{
			if (dizi[i][j] != kontrol[i][j])
			{
				return 0;
			}
		}
	}
	return 1;		
}

void oyna(int dizi[3][3], int *konum_i, int *konum_j)
{
	int hamle;
	hamle = _getch();
	if (hamle == 'w')//yukarý hareket
	{
		if (*konum_i > 0)
		{
			dizi[*konum_i][*konum_j] = dizi[*konum_i - 1][*konum_j];
			dizi[*konum_i - 1][*konum_j] = 0;
			*konum_i -= 1;
		}
	}
	else if (hamle == 's')//aþaðý hareket
	{	
		if (*konum_i < 2)
		{
			dizi[*konum_i][*konum_j] = dizi[*konum_i + 1][*konum_j];
			dizi[*konum_i + 1][*konum_j] = 0;
			*konum_i += 1;
		}
		
	}
	else if (hamle == 'a')//sol hareket
	{
		if (*konum_j > 0)
		{
			dizi[*konum_i][*konum_j] = dizi[*konum_i][*konum_j - 1];
			dizi[*konum_i][*konum_j - 1] = 0;
			*konum_j -= 1;
		}
		
	}
	else if (hamle == 'd')//sað hareket
	{
		if(*konum_j < 2)
		{
			dizi[*konum_i][*konum_j] = dizi[*konum_i][*konum_j + 1];
			dizi[*konum_i][*konum_j + 1] = 0;
			*konum_j += 1;
		}
	}	
}

int main()
{
	int konum_i=2, konum_j=2;
	srand(time(NULL));
	
	int dizi[3][3];
	int gecici[8]={1,2,3,4,5,6,7,8};
	
	printf("Numbers: \n");
	for (int i = 0;i < 8;i++)
	{
		printf("%d ", gecici[i]);
	}
	
	randomize(gecici);
	printf("\nRandomized numbers: \n");
	for (int i = 0;i < 8;i++)
	{
		printf("%d ", gecici[i]);
	}
	
	printf("\n\n");
	
	ata(dizi, gecici);
	
	ciz(dizi);	
	
	
	while(!bitir(dizi))
	{
		oyna(dizi, &konum_i, &konum_j);
		ciz(dizi);
	}
	printf("Cozdun");	
	
}

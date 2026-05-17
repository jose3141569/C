#include <stdio.h>
	  
void reacomodo(int a[3]){

	int minimo=0,tem=0;
	

	for(int i=0;i<3;i++){
		minimo = i;
		for (int j = i + 1; j < 3; j++) {
            	if (a[j] < a[minimo]) {
                	minimo = j;
            		}
        	}
		tem = a[i];
		a[i] = a[minimo];
		a[minimo] = tem;
	}
}


int main()
{
	int matriz[3][3]={0},vec[3],n=0,h=0,h2=1;
	
	printf("Matriz de 3x3\n");
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{ 
			if(i==j){
				break;
			}
			printf("Ingresa un numero: ");
			scanf("%d",&n);
			if(matriz[i][j]!=0)
			{	
			}
			else
			{
			matriz[i][j]=n;
			matriz[j][i]=n;
			}

			while(h2>h)
			{
				vec[h]=n;
				h++;	
			}
			
			h2++;
		}
	}
	
	
	printf("\n---------\n");


	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{ 
			printf("%d ",matriz[i][j]); 
		}

		printf("\n");
	}
	
	printf("---------\n");

	for(int i=0;i<3;i++)
	{
		printf("%d ",vec[i]);
	}
	printf("\n");
	
	printf("---------\n");
	
	reacomodo(vec);


	for(int i=0;i<3;i++)
	{
		printf("%d ",vec[i]);
	}
	printf("\n");
	
	printf("---------\n");	


}



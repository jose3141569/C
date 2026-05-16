#include <stdio.h>

void reacomodo(int a[9])
{
	int min=0,ban=0;
	
	ban=a[0];

	for(int i=0;i<9;i++)
	{
	  if(ban<a[i])
	  {

	  }
	  else
	  {
		ban=a[i];
	  }
	}
	min=ban;

	printf("minimo = %d",min);
}

int main()
{
	int matriz[3][3],vec[9],n=0,h=0,h2=1;
	
	printf("Matriz de 3x3\n");
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{ 
			printf("Ingresa un numero: ");
			scanf("%d",&n);
			matriz[i][j]=n;
			
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

	for(int i=0;i<9;i++)
	{
		printf("%d ",vec[i]);
	}
	printf("\n");
	
	printf("---------\n");

	reacomodo(vec);
}



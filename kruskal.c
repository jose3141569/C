#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
int **matriz(int filas, int columnas){ //crear matriz
	int **matriz = (int **)malloc(filas * sizeof(int *));
	for(int i = 0; i < filas; i++){
		matriz[i] = (int *)malloc(columnas * sizeof(int));
	}
	return matriz;
}
 
void liberar(int **matriz,int filas){//liberar la memoria
	for(int i = 0; i < filas; i++){
		free(matriz[i]);
	}
	free(matriz);
}
 
void exportar_Mat(int **Ma, int v){ // crear archivo dot para la grafica
                                    // sugerido por la IA para crear una grafica apartir de graphviz
	FILE *f = fopen("kruskal.dot","w");
 
	if(f == NULL){
		printf("Error al crear el archivo.\n");
		return;
	}
 
	fprintf(f,"graph {\n");
	fprintf(f,"      node [style=filled, fillcolor=lightblue]\n");
	for(int i = 0; i < v; i++){
		fprintf(f,"    %d;\n", i+1);
	}
 
	for(int i = 0; i < v; i++){
		for(int j = 0; j < v; j++){
			fprintf(f,"    %d -- %d\n",i+1,j+1); 
		}
	}
 
	fprintf(f,"}\n");
	fclose(f);
 
	system("dot -Tpng kruskal.dot -o kruskal.png && xdg-open kruskal.png");
	printf("\n\tImagen generada como kruskal.png\n\n");
}


int reacomodo(int n,int a[n]){

	int minimo=0,tem=0;
	

	for(int i=0;i<n;i++){
		minimo = i;
		for (int j = i + 1; j < n; j++) {
            	if (a[j] < a[minimo]) {
                	minimo = j;
            		}
        	}
		tem = a[i];
		a[i] = a[minimo];
		a[minimo] = tem;
	}
}

int main() //inicio de main

{
	int vert=0,vert1=0,vert2=0,aris=0,intervalo=0,valor=0,h=1;
 
	printf("Ingresa la cantidad de nodos: "); scanf("%d",&vert);	
	
	int *vector=NULL;
	
 
	if(vert>5){
		printf("Demasiados vertices.");
		return 0;
	}//final del if
	else{
		printf("Ingresa la cantidad de aristas: "); scanf("%d",&aris);
		int **mat=matriz(vert,vert);
 
		for(int i=0;i<vert;i++){ //matriz de ceros
			for(int j=0;j<vert;j++){
				mat[i][j]=0;
			}			
		}
 
		printf("\n\nIngresa los vertices relacionados junto con el valor.\n\nEscoge entre estos valores de los vertices: ");
		
		for(int i=0;i<vert;i++){ // muestra la cantidad de vertices 
			printf("V{%d} ",i+1);
			intervalo++;
		}
		
		printf("\n\n");
 		
		for(int i=0;i<aris;i++){

			printf("%d => ",i+1); scanf("%d%d",&vert1,&vert2); printf("Ingresa el valor: "); scanf("%d",&valor);
 
			if( (vert1 >= 1 && vert2 >= 1 && valor >= 1) && (vert1 <= intervalo && vert2 <= intervalo)){
			
				if(mat[vert1][vert2] != 0){
					printf("Arista ya existe.\n");
    					i--;
					continue;
				}
				if(vert1 != vert2){ //vert1 y vert2 para la posicion
					vert1-=1;
					vert2-=1;
 
					mat[vert1][vert2]=valor;
					mat[vert2][vert1]=valor;
					
					
					vector = realloc(vector,h*sizeof(int));
					vector[h-1]=valor;
					h++;

				}
		 	}
			else{
				if(vert1 < 1 || vert2 < 1 ){
					printf("--Fuera del intervalo de vertices [1,%d].--\n",intervalo);

				}else{
					printf("--El valor ingresado es menor a 1--\n");
				}
				
			}
		}
		
			
		//Inicio de impresion de valores.//
		
		//impresion de la matriz
		printf("\n-----------------------------\n");
		for(int i = 0; i < vert; i++){
			printf("\tv{%d} ",i+1);// dar los vertices de las columnas
		}
		printf("\n");

		for(int i = 0; i < vert; i++){ // imprime la matriz y valores de los vertices en las filas
			printf("v{%d} ",i+1);
			for(int j = 0; j < vert; j++){
				printf("\t [%d] ",mat[i][j]);
				
			}
			printf("\n");
		}
		liberar(mat,vert); // liberar el espacio
		
		printf("\n");
		//impresion del vector de costos
		
		printf("-----------------------------\n");

		printf("Vec.Cos = ");

		for(int i=0;i<h;i++){
			printf("[%d] ",vector[i]);
		}
		printf("\n");
		free(vector);
		vector=NULL;

	}//final del else
 
}//final del main

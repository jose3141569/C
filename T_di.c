#include <stdio.h>
#include <stdlib.h>

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

void exportar_dot(int **Ma, int v){ // crear archivo dot para la grafica
                                    // sugerido por la IA para crear una grafica apartir de graphviz
    FILE *f = fopen("digrafo.dot","w");

    if(f == NULL){
        printf("Error al crear el archivo.\n");
        return;
    }

    fprintf(f,"digraph {\n");
    fprintf(f,"      node [style=filled, fillcolor=lightblue]\n");
    for(int i = 0; i < v; i++){
        fprintf(f,"    %d;\n", i+1);
    }

    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(Ma[i][j] == 1){
                fprintf(f,"    %d -> %d;\n", i+1, j+1);
            }else {
              int n=Ma[i][j];
              for(int h=0;h<n;h++){
               fprintf(f,"    %d -> %d\n",i+1,j+1); 
              }
            }
        }
    }

    fprintf(f,"}\n");
    fclose(f);

    system("dot -Tpng digrafo.dot -o digrafo.png && xdg-open digrafo.png");
    printf("\n\tImagen generada como grafo.png\n\n");
}

int main(){ // cuerpo del programa

    int opc = 0,opc2=0;
    printf("\n\nEscuela: \n\tFacultad de Estudios Superiores Acatlan.\nAlumnos: \n\tMartinez celis Enrique\n\tMiranda Mateo Hector Adolfo\n\tPadilla Martinez Jose Miguel\n\n");

    do{
        int v = 0, a = 0, v1 = 0, v2 = 0, intervalo = 0; // v es para los vertices, a para las aristas, v1 y v2 para las posiciciones de la matriz y por ultimo el intervalo para no salirse de las opciones de los vertices

        printf("\t--Bienvenido--\n\n");

        printf("Ingresa la cantidad de nodos: ");
        scanf("%d",&v);
        if(v > 15){
          printf("\n\nLa cantidad de nodos es menor o igual a 15\n\n");
        }else{ 
        printf("¿Deseas la matriz llenarla de 1 [Ingresa 1]? --> ");
        scanf("%d",&opc2);
        if(opc2 == 1)
        {
          int **Ma = matriz(v,v); //crear la matriz
            for(int i = 0; i < v; i++){ // llenar la matriz de ceros
                for(int j = 0; j < v; j++){
                    Ma[i][j] = 1;                
                }
            }
            exportar_dot(Ma,v);
            for(int i = 0; i < v; i++)
            {
                printf("\tv_{%d} ",i+1);// dar los vertices de las columas
            }
            printf("\n");
            for(int i = 0; i < v; i++)
            { // imprime la matriz y valores de los vertices en las filas
                printf("v_{%d} ",i+1);
                for(int j = 0; j < v; j++)
                {
                    printf("\t [%d] ",Ma[i][j]);
                }
                printf("\n");
            }
            liberar(Ma,v); // liberar el espacio
            return 0;
        }else
        {
          printf("...ok\n\n");
        }
        printf("Ingresa la cantidad de aristas: ");
        scanf("%d",&a);
        if(a > v*v){ // condicion que garantiza no agregar mas aristas para el grafo .
                             // implementado con iA
            printf("Demasiadas aristas para un grafo dirigido\n\n");
            return 0;
        }
        else{

            int **Ma = matriz(v,v); //crear la matriz

            for(int i = 0; i < v; i++){ // llenar la matriz de ceros
                for(int j = 0; j < v; j++){
                    Ma[i][j] = 0;
                }
            }

            printf("Da la relacion de Phi. Ingresando el primer y el segundo elemento con los valores que se muestran:\n\n");
                                       //parte donde se pide la relacion para saber que vertice esta relacionado con otro
            for(int i = 0; i < v; i++){//muestra la cantidad de vertice que se tiene
                printf("V_{%d} ", i+1);
                intervalo++;
            }
            printf("\n\n");

            for(int i = 0; i < a; i++){ // es para indicar que vertice se relaciona con el otro
                printf("\u03C6(a_{%d})= ", i+1);
                scanf("%d%d",&v1,&v2);

                if((v1 >= 1 && v2 >= 1) && (v1 <= intervalo && v2 <= intervalo)){

                    if(v1 != v2){ // ingresar las variables de v1 y v2 a la matriz

                        v1-=1;
                        v2-=1;

                    //if(Ma[v1][v2] == 1){ // si ya hay un uno omitir el ingreso
                      //printf("Ingresaste un 1 donde ya hay un valor.\n\n");
                    //}else{
                    
                      Ma[v1][v2] += 1; // hacer la matriz simetrica
                    //}

                    }else{
                      v1-=1;
                      v2-=1;
                      Ma[v1][v2] += 1;
                    }

                }else{
                    printf("Ingresa los nodos entre [1,%d].\n\n",intervalo); // Hacer que se respete el intervalo de los vectores
                }
            }

            exportar_dot(Ma,v); // muestra la grafica y aparte se guarda en png para su consulta mas adelante

            for(int i = 0; i < v; i++){
                printf("\tv_{%d} ",i+1);// dar los vertices de las columas
            }
            
            printf("\n");

            for(int i = 0; i < v; i++){ // imprime la matriz y valores de los vertices en las filas
                printf("v_{%d} ",i+1);
                for(int j = 0; j < v; j++){
                  if(Ma[i][j]!=1 && Ma[i][j]!=0){
                    Ma[i][j]=1;
                    printf("\t [%d] ",Ma[i][j]);
                  }else{
                    printf("\t [%d] ",Ma[i][j]);
                  }
                }
                printf("\n");
            }

            liberar(Ma,v); // liberar el espacio 
        }
        }
        printf("\n\n¿Quieres volver a ingresar una matriz?\n\n\tIngresa 1 para repetir: ");
        scanf("%d",&opc); // preguntar si se quiere volver a iniciar el programa

    }while(opc == 1);

    printf("\n\n\tNos vemos...\n");

    return 0;
}

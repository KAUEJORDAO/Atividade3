#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h" 

float calcularAreaPoligono(Ponto *vertices, int numVertices);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <vertice.txt>\n", argv[0]);
        return 1;
    }

    FILE *arquivo;
    arquivo = fopen("vertice.txt", "r");

    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    int numVertices;
    fscanf(arquivo, "%d", &numVertices);

    if (numVertices < 3) {
        printf("Um polígono deve ter pelo menos 3 vértices.\n");
        fclose(arquivo);
        return 1;
    }

    Ponto *vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));

    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &(vertices[i].X), &(vertices[i].Y));
    }

    fclose(arquivo);

    float area = calcularAreaPoligono(vertices, numVertices);
    printf("A área do polígono é %.2f\n", area);

    free(vertices);
    return 0;
}

float calcularAreaPoligono(Ponto *vertices, int numVertices) {
    float area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices; // Próximo vértice
        area += (vertices[i].X * vertices[j].Y) - (vertices[j].X * vertices[i].Y);
    }

    area = fabs(area) / 2.0; // Valor absoluto e divisão por 2
    return area;
}

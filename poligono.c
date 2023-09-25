#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double calculatePolygonArea(Point *vertices, int numVertices) {
    double area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        int j = (i + 1) % numVertices;
        area += (vertices[i].x * vertices[j].y - vertices[j].x * vertices[i].y);
    }

    area = 0.5 * fabs(area);
    return area;
}

int main() {
    FILE *file = fopen("poligono.txt", "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    int numVertices;
    fscanf(file, "%d", &numVertices);

    if (numVertices < 3) {
        printf("O polígono deve ter pelo menos 3 vértices.\n");
        fclose(file);
        return 1;
    }

    Point *vertices = (Point *)malloc(numVertices * sizeof(Point));

    for (int i = 0; i < numVertices; i++) {
        fscanf(file, "%lf %lf", &vertices[i].x, &vertices[i].y);
    }

    fclose(file);

    double area = calculatePolygonArea(vertices, numVertices);

    printf("A área do polígono é %.2lf\n", area);

    free(vertices);

    return 0;
}

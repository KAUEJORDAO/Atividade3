#include <math.h>
#include "ponto.h"

float calcularDistancia(Ponto p1, Ponto p2) {
    float dx = p2.X - p1.X;
    float dy = p2.Y - p1.Y;
    return sqrt(dx * dx + dy * dy);
}

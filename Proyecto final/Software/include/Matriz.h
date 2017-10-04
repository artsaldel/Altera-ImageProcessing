
#ifndef MATRIZ_H
#define	MATRIZ_H

#include <string>
using namespace std;


class Matriz {
public:
    Matriz(int filas,int columnas);
    virtual ~Matriz();
    int getFilas();
    int getColumnas();
    void imprimeMatriz();
    int ** getMatriz();
    int contador;
private:
    int **matriz;
    int filas,columnas;
};

#endif	/* MATRIZ_H */




#include "Matriz.h"
#include <iostream>

//Constructor principal de la clase
Matriz::Matriz(int filas, int columnas) {
    this->contador=filas*columnas;
    this->filas=filas;
    this->columnas=columnas;
    this->matriz= new int *[this->filas];
    for (int i=0;i<filas;i++){ //Loop que agrega punteros a un puntero (matriz)
        this->matriz[i]= new int [this->columnas];
    }
}

//Método para obtener la matriz de la clase
int ** Matriz::getMatriz(){
    return this->matriz;
}

//Método que imprime la matriz (loop)
void Matriz::imprimeMatriz(){
    for (int i=0;i!=this->filas;i++){
        for (int j=0;j!=this->columnas;j++){

            std::cout << this->matriz [i][j]<<"|";
        }
        std::cout<< std::endl<<std::endl<<std::endl;
    }
    cout<<endl<<endl;
}

//Método para obtener el número de filas de la matriz
int Matriz::getFilas(){
    return this->filas;
}

//Método que obtiene el número de columnas de la matriz
int Matriz::getColumnas(){
    return this->columnas;
}

//Destructor de la matriz (loop)
Matriz::~Matriz() {
    for (int i=0;i<this->filas;i++){
        delete [] this->matriz[i];
    }
    delete this->matriz;
}



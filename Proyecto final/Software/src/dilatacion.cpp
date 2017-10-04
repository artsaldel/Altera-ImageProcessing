#include "dilatacion.h"

#include <cv.h>
#include <highgui.h>
#include <iostream>
#include <iomanip>
#include "Matriz.h"
#include <thread>
#include "app.h"

using namespace std;

#define CANT_PIXELES 4000

Dilatacion::Dilatacion()
{
    porcentajeAtom = -1;
    terminaFilasAtom = false;
    terminaColumnasAtom = false;
    terminaFilasNios = false;
    terminaColumnasNios = false;
}

void Dilatacion::EjecutaAlgoritmo(Mat mat){
    MatrizInicio = new Matriz(mat.rows, mat.cols);
    for(int i = 0; i < mat.rows; i++)
    {
        for(int j = 0; j < mat.cols; j++)
        {
            MatrizInicio->getMatriz()[i][j] = (int)mat.at<uchar>(i,j);
        }
    }

    while(porcentajeAtom > 100 || porcentajeAtom < 0){
        cout<<endl<<"Ingrese el porcentaje que procesará el ATOM: ";
        cin>>porcentajeAtom;

        if (porcentajeAtom > 100 || porcentajeAtom < 0)
            cout<<endl<<"------------¡¡Ingrese un porcentaje válido para el procesamiento!!-------------"<<endl<<endl;
    }

    porcentajeNios = (100 - porcentajeAtom)/100;
    porcentajeAtom = porcentajeAtom/100;

    cout<<endl<<"Porcentaje Atom: "<<porcentajeAtom*100<<"%"<<endl;
    cout<<"Porcentaje Nios: "<<porcentajeNios*100<<"%"<<endl<<endl;

    filasAtom = MatrizInicio->getFilas()*porcentajeAtom;
    colsAtom = MatrizInicio->getColumnas()*porcentajeAtom;

    filasNios = MatrizInicio->getFilas() - filasAtom;
    colsNios = MatrizInicio->getColumnas() - colsAtom;

    tiempo1 = high_resolution_clock::now();

    Finaliza(Algoritmo());
}

void Dilatacion::Finaliza(Matriz* matriz)
{

    tiempo2 = high_resolution_clock::now();

    auto duration = duration_cast<seconds>( tiempo2 - tiempo1 ).count();
    auto duration2 = duration_cast<milliseconds>( tiempo2 - tiempo1 ).count();
    auto duration3 = duration_cast<microseconds>( tiempo2 - tiempo1 ).count();

    cout <<"El tiempo de ejecución en segundos fue de "<< duration<< "s"<<endl;
    cout <<"El tiempo de ejecución en milisegundos fue de "<< duration2<< "ms"<<endl;
    cout <<"El tiempo de ejecución en microsegundos fue de "<< duration3<< "us"<<endl;

    cv::Mat resultImg = Mat(matriz->getFilas(),matriz->getColumnas(),CV_8UC1);
    for (int i = 0; i < matriz->getFilas(); i++)
    {
        for(int j = 0; j < matriz->getColumnas(); j++)
        {
            resultImg.at<uchar>(i,j) = matriz->getMatriz()[i][j];
        }
    }
    cv::namedWindow("Resultado");
    cv::imshow("Resultado",resultImg);
    cv::imwrite( "resultado.jpg", resultImg );
    cvWaitKey(0);
    matriz->~Matriz();
}


Matriz* Dilatacion::Algoritmo(){

    int filas = MatrizInicio->getFilas();
    int columnas = MatrizInicio->getColumnas();

    MatrizTemp = new Matriz(filas, columnas);
    MatrizResultante = new Matriz(filas, columnas);

    // Esto es para asignar la nueva matriz con los valores de pixeles de la matriz original

    if (filas >= 5 && columnas >= 5)
    {

        //Ejecuto horizontal primero, insertando lo que realiza el atom y el nios en hilos, para ser ejecutados al mismo tiempo
        std::thread t1([this]() {
            DilataFilasAtom(MatrizInicio);
        });
        std::thread t2([this]() {
            DilataFilasNios(MatrizInicio);
        });
        t1.join();
        t2.join();

        while (!terminaFilasAtom || !terminaFilasNios){}

        //Lleno la nueva matriz
        int porcionFilas = filasAtom;
        int porcionColumnas = colsAtom;

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (i < porcionFilas){
                    MatrizTemp->getMatriz()[i][j] = MatrizAtomFilas->getMatriz()[i][j];
                }
                else{
                    MatrizTemp->getMatriz()[i][j] = MatrizNiosFilas->getMatriz()[i - porcionFilas][j];
                }
            }
        }

        //Ejecuto vertical, insertando lo que realiza el atom y el nios en hilos, para ser ejecutados al mismo tiempo
        std::thread t3([this]() {
            DilataColumnasAtom(MatrizTemp);
        });
        std::thread t4([this]() {
            DilataColumnasNios(MatrizTemp);
        });
        t3.join();
        t4.join();

        while (!terminaColumnasAtom || !terminaColumnasNios){}

        //Vuelvo a completar matriz
        for (int j = 0; j < columnas; j++){
            for (int i = 0; i < filas; i++){
                if (j < porcionColumnas){
                    MatrizResultante->getMatriz()[i][j] = MatrizAtomColumnas->getMatriz()[i][j];
                }
                else{
                    MatrizResultante->getMatriz()[i][j] = MatrizNiosColumnas->getMatriz()[i][j - porcionColumnas];
                }
            }
        }
    }
    return MatrizResultante;
}

//*****************************************************************************************************************
//******************************* FUNCIONES PARA PROCESAMIENTO PARALELO *******************************************
//*****************************************************************************************************************

//DILATO LAS FILAS POR MEDIO DEL PROCESADOR ATOM
void Dilatacion::DilataFilasAtom(Matriz* matriz){

    int columnas = matriz->getColumnas();
    int porcion = filasAtom;

    MatrizAtomFilas = new Matriz(porcion, matriz->getColumnas());

    //Relleno la Matriz de atom filas con los valores actuales
    for (int  i = 0; i < porcion; i++){
        for (int j = 0; j < columnas; j++){
            MatrizAtomFilas->getMatriz()[i][j] = matriz->getMatriz()[i][j];
        }
    }

    int columnaActual = 0;
    int pixelMaximo =0;

    for (int i = 0; i < porcion; i++){
        for (int j = 0; j < columnas; j++){
            //MatrizAtomFilas->getMatriz()[i][j] = matriz->getMatriz()[i][j];
            columnaActual = j;
            if ( (columnaActual + 4) < columnas){
                int  columnaCambio = columnaActual + 2;
                pixelMaximo = matriz->getMatriz()[i][columnaCambio];
                for (int temp = 0; temp < 5; temp++){
                    int posX = columnaActual + temp;
                    if (matriz->getMatriz()[i][posX] > pixelMaximo)
                        pixelMaximo = matriz->getMatriz()[i][posX];
                }
                MatrizAtomFilas->getMatriz()[i][columnaCambio] = pixelMaximo;
            }
        }
    }
    terminaFilasAtom = true;
}

//DILATO LAS COLUMNAS POR MEDIO DEL PROCESADOR ATOM
void Dilatacion::DilataColumnasAtom(Matriz* matriz){
    int filas = matriz->getFilas();
    int porcion = colsAtom;

    MatrizAtomColumnas = new Matriz(filas, porcion);

    //Relleno la Matriz de atom filas con los valores actuales
    for (int  j = 0; j < porcion; j++){
        for (int i = 0; i < filas; i++){
            MatrizAtomColumnas->getMatriz()[i][j] = matriz->getMatriz()[i][j];
        }
    }

    int filaActual = 0;
    int pixelMaximo =0;

    //Ejecuto vertical
    for (int j = 0; j < porcion; j++){
        for (int i = 0; i < filas; i++){
            //MatrizAtomColumnas->getMatriz()[i][j] = matriz->getMatriz()[i][j];
            filaActual = i;
            if ( (filaActual + 4) < filas){
                int filaCambio = filaActual + 2;
                pixelMaximo = matriz->getMatriz()[filaCambio][j];
                for (int temp = 0; temp < 5; temp++){
                    int posY = filaActual + temp;
                    if (matriz->getMatriz()[posY][j] > pixelMaximo)
                        pixelMaximo = matriz->getMatriz()[posY][j];
                }
                MatrizAtomColumnas->getMatriz()[filaCambio][j] = pixelMaximo;
            }
        }
    }
    terminaColumnasAtom = true;
}

//DILATO LAS FILAS POR MEDIO DEL PROCESADOR NIOS
void Dilatacion::DilataFilasNios(Matriz* matriz){

    int filas = matriz->getFilas();
    int columnas = matriz->getColumnas();

    int porcion = filasAtom;

    MatrizNiosFilas = new Matriz(filasNios, columnas);

    if (porcentajeNios == 0){
        for (int  i = 0; i < filasNios; i++){
            for (int j = 0; j < columnas; j++)
                MatrizNiosFilas->getMatriz()[i][j] = 0;
        }
    }
    else{
        //Todo para enviar datos al NIOS
        int ctdrPixeles = 0;
        int whereFila = 0;

        int n = columnas;
        int m = CANT_PIXELES/columnas;
        if (m > filas)
            m = filas;

        int* arregloTemp = new int[ (n*m) + 2];
        arregloTemp[0] = n;
        arregloTemp[1] = m;

        app* niosApp = new app();
        bool esFinal = false;

        for (int i = porcion; i < filas; i++){
            for (int j = 0; j < columnas; j++){

                //*****************************************************************************
                //******************Esto es lo que debería ejecutar el NIOS********************
                //*****************************************************************************

                if(!esFinal){
                    arregloTemp[ctdrPixeles + 2] = matriz->getMatriz()[i][j];
                    ctdrPixeles++;
                }
                else{
                    int* arregloNios = niosApp->init(arregloTemp);

            //      for (int t = 0; t < n*m; t++ )
              //          cout<<"Piexel "<< t<< " Viejo: "<<arregloTemp[t]<<endl;

//                        cout<<"Piexel "<< t<< " Viejo: "<<arregloTemp[t+2]<<" Nuevo: "<<arregloNios[t]<<endl;
                    ctdrPixeles = 0;

                    int tempCtdr = 0;
                    for (int x = whereFila; x < i-porcion; x++){
                        for (int y = 0; y < columnas; y++){
                            MatrizNiosFilas->getMatriz()[x][y] = arregloNios[tempCtdr];
                            tempCtdr++;
                        }
                    }

                    whereFila = i - porcion;
                    j--;
                    esFinal = false;
                }

                //*****************************************************************************
                //*****************************************************************************
                //*****************************************************************************
            }
            if ( (ctdrPixeles + columnas ) > CANT_PIXELES ){
                esFinal = true;
            }
        }

        int* arregloNios = niosApp->init(arregloTemp);

      //  for (int t = 0; t < n*m; t++ )
           // cout<<"Piexel "<< t<< " Viejo: "<<arregloTemp[t+2]<<" Nuevo: "<<arregloNios[t]<<endl;

        ctdrPixeles = 0;

        int tempCtdr = 0;
        for (int x = whereFila; x < filas-porcion; x++){
            for (int y = 0; y < columnas; y++){
                MatrizNiosFilas->getMatriz()[x][y] = arregloNios[tempCtdr];
                tempCtdr++;
            }
        }
    }
    terminaFilasNios = true;
}


void Dilatacion::DilataColumnasNios(Matriz* matriz){
    int filas = matriz->getFilas();
    int columnas = matriz->getColumnas();
    int porcion = colsAtom;

    MatrizNiosColumnas= new Matriz(filas, colsNios);

    if (porcentajeNios == 0){
        for (int  i = 0; i < filas; i++){
            for (int j = 0; j < colsNios; j++)
                MatrizNiosColumnas->getMatriz()[i][j] = 0;
        }
    }
    else{
        //Todo para enviar datos al NIOS
        int ctdrPixeles = 0;
        int whereColumna = 0;

        int n = filas;
        int m = CANT_PIXELES/filas;

        if (m > columnas)
            m = columnas;

        int* arregloTemp = new int[ (n*m) + 2];
        arregloTemp[0] = n;
        arregloTemp[1] = m;

        app* niosApp = new app();
        bool esFinal = false;

        for (int j = porcion; j < columnas; j++){
            for (int i = 0; i < filas; i++){

                //*****************************************************************************
                //******************Esto es lo que debería ejecutar el NIOS********************
                //*****************************************************************************

                if(!esFinal){
                    arregloTemp[ctdrPixeles + 2] = matriz->getMatriz()[i][j];
                    ctdrPixeles++;
                }
                else{
                    int* arregloNios = niosApp->init(arregloTemp);
                    ctdrPixeles = 0;
                    int tempCtdr = 0;
                    for (int y = whereColumna; y < j - porcion; y++){
                        for (int x = 0; x < filas; x++){
                            MatrizNiosColumnas->getMatriz()[x][y] = arregloNios[tempCtdr];
                            tempCtdr++;
                        }
                    }
                    whereColumna = j - porcion;
                    i--;
                    esFinal = false;
                }

                //*****************************************************************************
                //*****************************************************************************
                //*****************************************************************************
            }
            if ( (ctdrPixeles + filas ) > CANT_PIXELES ){
                esFinal = true;
            }
        }
        int* arregloNios = niosApp->init(arregloTemp);
        ctdrPixeles = 0;
        int tempCtdr = 0;
        for (int y = whereColumna; y < columnas - porcion; y++){
            for (int x = 0; x < filas; x++){
                MatrizNiosColumnas->getMatriz()[x][y] = arregloNios[tempCtdr];
                tempCtdr++;
            }
        }
    }
    terminaColumnasNios = true;
}


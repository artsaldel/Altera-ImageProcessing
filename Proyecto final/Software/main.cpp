
#include <cv.h>
#include <highgui.h>
#include "dilatacion.h"
#include "Matriz.h"
#include <math.h>
#include "app.h"
#include <time.h>

using namespace cv;

int main( int argc, char** argv )
{

    bool listo =  false;
    while (!listo){

        cout<<"Ingrese el nombre la imagen con su formato correspondiente: ";
        string imageName;
        cin>>imageName;

        try{
            Mat image;
            image = imread( imageName, 1 );
            Mat gray_image;
            cv::cvtColor( image, gray_image, CV_BGR2GRAY );
            cv::imwrite( "resultado_gris.jpg", gray_image );

            Dilatacion *newDil = new Dilatacion();
            newDil->EjecutaAlgoritmo(gray_image);

            cout<<endl<<endl<<"Desea ingresar otra imagen? (y/n): ";
            string continuar;
            cin>>continuar;

            while (continuar!= "Y" && continuar!= "N" && continuar != "n" && continuar != "y"){
                cout<<endl<<endl<<"Ingrese un valor válido. Desea ingresar otra imagen? (y/n): ";
                string continuar;
                cin>>continuar;
            }
            //if (continuar== "N" || continuar == "n")
                listo = false;
            cout<<"***********************************************************************"<<endl<<endl;
        }
        catch(cv::Exception e){
            cout<<endl<<"--------------------¡¡Ingrese una imagen válida!!--------------------"<<endl<<endl;
        }
    }
    cout<<"Edicion de imágenes finalizada. Vuelva Pronto!!"<<endl<<endl;

    return 0;
}

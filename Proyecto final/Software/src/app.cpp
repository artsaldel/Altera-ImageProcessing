#include "app.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "PCIE.h"
#include "pcie_c.h"
#include <iostream>

//MAX BUFFER FOR DMA
#define MAXDMA 4002
#define RWSIZE (32 / 8)

#define ONCHIP_CONTROL 0x000211ee //Esta direccion contiene el byte para el polling
#define ONCHIP_DATA 0x000212f8 //Esta direccion contiene el lugar donde se va a escribir lo del DMA
#define ONCHIP_DATA2 0x00030900
#define DATA_SIZE 4096

PCIE_BAR pcie_bars[] = { PCIE_BAR0, PCIE_BAR1 , PCIE_BAR2 , PCIE_BAR3 , PCIE_BAR4 , PCIE_BAR5 };
PCIE_HANDLE hPCIe;

using namespace std;

app::app(){
    void *lib_handle;
    lib_handle = PCIE_Load(); //Carga la libreria PCIE dinamicamente
    if (!lib_handle)
        printf("PCIE_Load failed\n");
    hPCIe = PCIE_Open(0,0,0); //Abre el dispositivo PCIE para lectura y escritura
    if (!hPCIe)
        printf("PCIE_Open failed\n");
}


int* app::init(int* buff){
    WORD control; //tiene que ser de este tipo para que sirva. Solo usar DWORD O WORD
    BOOL bPass; //Indica si la transaccion o lectura se logro realizar
    int* buff_nuevo = new int[buff[0]*buff[1]];
    //Ya el dispositivo ha sido abierto, si no se han presentado fallos
    control = 0x48;
    bPass = PCIE_Write8( hPCIe, pcie_bars[0], ONCHIP_CONTROL, control);

    bPass = PCIE_DmaWrite(hPCIe, ONCHIP_DATA, buff, MAXDMA * RWSIZE );
    //Le indica al NIOS que empieze a realizar los calculos
    control = 0x42;  //escribe una B
    bPass = PCIE_Write8( hPCIe, pcie_bars[0], ONCHIP_CONTROL, control);
    //Realiza polling hasta que el NIOS termine de realizar los calculos
    while(control != 'H'){
        bPass = PCIE_Read8( hPCIe, pcie_bars[0], ONCHIP_CONTROL, (unsigned char*)&control);
    }

    //Manda a leer al dma los datos calculados por el NIOS
    bPass = PCIE_DmaRead(hPCIe, ONCHIP_DATA2, buff_nuevo, MAXDMA * RWSIZE );
    return buff_nuevo;
}


/*
int* app::init(int* array){

    int n = array[0]; // contiene el n
    int m = array[1]; // contiene el m

    int* onchip_data_old_image = new int[n*m];
    int* onchip_data_new_image = new int[n*m];

    for(int i = 0; i < n*m; i++){
        onchip_data_old_image[i] = array[i+2];
        onchip_data_new_image[i] = array[i+2];
    }

    int pixel, pixel_mayor;
    int i, j;
    int k = 0;

    while (k < n*m) {
        for (i = 2 + k; i < n+k - 2; i++) {
            pixel_mayor = *(onchip_data_old_image + i);
            for (j = i - 2; j <= i + 2; j++) {

                if (pixel_mayor < (pixel = *(onchip_data_old_image + j))) {
                    pixel_mayor = *(onchip_data_old_image + j);

                    if (i == 2 + k) {
                        *(onchip_data_new_image + j) = pixel; //pixel actual

                    } else if ((i != 2 + k) & (j == (i + 2))) {
                        *(onchip_data_new_image + j) = pixel; //pixel actual
                    }
                } else {
                    if (i == 2+k) {
                        *(onchip_data_new_image + j) = pixel; //pixel actual

                    } else if ((i != 2+k) & (j == (i + 2))) {
                        *(onchip_data_new_image + j) = pixel; //pixel actual
                    }
                }
            }
            *(onchip_data_new_image + i) = pixel_mayor; //pixel centro
        }
        k = k + n;
    }
    return onchip_data_new_image;
}

*/

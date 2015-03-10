//
//  main.cpp
//  Decodificar
//
//  Created by Daniel on 26/02/15.
//  Copyright (c) 2015 Gotomo. All rights reserved.
//

#include <iostream>
#include "Transformar.h"
#include "IOpersonal.h"

using namespace std;

int main(int argc, const char * argv[]) {
    list<char> * texto;
    
    string direccion, password;
    int* llave;
    
    direccion ="/Users/Daniel/Desktop/hola.txt";
    password = "32178";
//    password = "8321";
    
    llave = new int[password.size()];
    for(int i = 0; i < password.size(); ++i){
        llave[i] = password[i] - '0';
    }
    
    texto = IOpersonal::leerArchivo(direccion);
    texto = Transformar::desencriptar(texto, llave, llave + password.size());
    IOpersonal::reescribir_archivo(direccion, texto);
    
    delete texto;
    return 0;
}

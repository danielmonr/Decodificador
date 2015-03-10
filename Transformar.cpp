//
//  Transformar.cpp
//  Decodificar
//
//  Created by Daniel on 26/02/15.
//  Copyright (c) 2015 Gotomo. All rights reserved.
//

#include "Transformar.h"

list<char>* Transformar::desencriptar(list<char> * lista, int * codigo, int* final){
    
    cout << "Decodificando...";
    const unsigned int N = 4;
    t_fase fase[N];
    fase[0] = fase_uno;
    fase[1] = fase_dos;
    fase[2] = fase_tres;
    fase[3] = fase_cuatro;
    
    int cont = ((final - codigo) % 4) - 1;
    final--;
    while(codigo <= final){
        if(cont < 0){
            cont = N-1;
        }
        cout << "\nCodigo: " << *final << "\ncont: " << cont << endl;

        lista = fase[cont](lista, *final);
        final --;
        cont--;
    }
    cout << "\nTamano: " << lista->size() << endl;
    cout << "  Terminado.\n";
    return lista;
}

//  Regresar caracteres a su posicion original, cambio hacia atrás.
list<char>* Transformar::fase_uno(list<char> * lista, int num){
    int _cont = 0;
    char temp1, temp2;
    list<char>::iterator it = (*lista).begin();
    advance(it, num-1);
    temp1 = *it;
    it = lista->begin();
    advance(it, (lista->size() - ((lista->size() % num)))-1);
    for (list<char>::iterator i = it; i != lista->begin(); --i){
        if (_cont == 0){
            temp2 = *i;
            *i = temp1;
            temp1 = temp2;
            _cont = num-1;
        }
        else{
            _cont --;
        }
        
    }
    
    return lista;
}

//  Eliminar caracteres extra
list<char>* Transformar::fase_dos(list<char> * lista, int num){
    int _cont = 0;
    if(lista->size() < num){
        return lista;
    }
    for (list<char>::iterator i = lista->begin(); i != lista->end(); ++i){
        if (_cont == num){
            lista->erase(i);
            ++i;
            _cont = 1;
        }
        else{
            _cont ++;
        }
    }
    return lista;
}

//  Regresar el caracter a su codigo original
list<char>* Transformar::fase_tres(list<char> * lista, int num){
    
    for (list<char>::iterator i = lista->begin(); i != lista->end(); ++i){
        if(*i < 32 + num && *i > 32){
            *i = 126 - (*i -31);
        }
        else{
            *i = *i - num;
        }
    }
    
    return lista;
}

//  Regresar caracteres a su posición original, cambio hacia adelante.
list<char>* Transformar::fase_cuatro(list<char> * lista, int num){
    int _cont = 0;
    list<char>::iterator it = (*lista).begin();
    if (lista->size() >= num) {
        advance(it, num-1);
    }
    else{
        return lista;
    }
    char temp1 = *it;
    char temp2;
    
    for(list<char>::iterator i = it; i != (*lista).end(); ++i){
        if(_cont == num){
            temp2 = *i;
            *i = temp1;
            temp1 = temp2;
            _cont = 1;
        }
        else{
            _cont++;
        }
    }
    
    it = (*lista).begin();
    advance(it, num-1);
    *it = temp1;
    
    return lista;
}
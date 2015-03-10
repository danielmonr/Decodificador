//
//  Transformar.h
//  Decodificar
//
//  Created by Daniel on 26/02/15.
//  Copyright (c) 2015 Gotomo. All rights reserved.
//

#ifndef __Decodificar__Transformar__
#define __Decodificar__Transformar__

#include <iostream>
#include <list>
#include "IOpersonal.h"

using namespace std;

typedef list<char>* (*t_fase)(list<char>*, int);

class Transformar{
public:
    static list<char>* desencriptar(list<char>*, int*, int*);
    
private:
    static list<char>* fase_uno(list<char>*, int);
    static list<char>* fase_dos(list<char>*, int);
    static list<char>* fase_tres(list<char>*, int);
    static list<char>* fase_cuatro(list<char>*, int);
};

#endif /* defined(__Decodificar__Transformar__) */

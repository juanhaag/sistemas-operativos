/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

                Thread Project

				Iteration 1.1

		Ciclo 2009
*/
#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include<conio.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>

#include "writer.h"

int _tmain(int argc, _TCHAR* argv[]) {
    Writer writer;
    Writer writer2;
    writer.start();
    writer2.start();
    writer.terminateAndWait();
    writer2.terminateAndWait(); 
    writer.

    for (int i = 0; i < 100; i++) {
        std::cout << "\t\tMain working ..." << std::endl;
        ::Sleep(15);
    }

    return 0;
}
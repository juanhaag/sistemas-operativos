/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

                Thread Project

                Declaracion para la clase Action

        Ciclo 2009
*/
#ifndef actionH
#define actionH

struct Action {
    virtual unsigned long __fastcall execute(void) = 0;
};

#endif
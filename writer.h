/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

                Thread Project ( not typing )

                Declaracion para las clases
                    Writer, WriterAction

        Ciclo 2009
*/
#ifndef writer_h
#define writer_h

#include "action.h"
#include "thread.h"
#include <iostream>

class Writer {
public:
    __fastcall Writer(void);
    __fastcall ~Writer(void);

    void __fastcall start(void);
    void __fastcall stop(void);
    void __fastcall exit(void);
    void __fastcall terminateAndWait(void);
    bool __fastcall isRunning(void);
    bool __fastcall isTerminated(void);
    bool __fastcall isAlive(void);

private:
    Thread* thread;
    WriterAction* writerAction;

    unsigned long __fastcall write(void);
};

#endif
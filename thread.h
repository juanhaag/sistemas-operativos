/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

                Thread Project

                Declaracion para la clase Thread

        Ciclo 2009
*/

#ifndef threadH
#define threadH

#include <windows.h>
#include "action.h"

class Thread {
    enum { TIME_OUT = 200 };
private:
    HANDLE thread;
    DWORD threadId;
    DWORD timeOut;
    BOOL terminated;
    BOOL active;
    Action* action;

    static unsigned long __stdcall threadFunction(void* threadAction);

public:
    __fastcall Thread(Action* action, DWORD flags = CREATE_SUSPENDED, DWORD timeOut = TIME_OUT);
    __fastcall ~Thread(void);

    void __fastcall start();
    void __fastcall stop();
    void __fastcall exit();
    void __fastcall terminateAndWait();
    bool __fastcall isRunning();
    bool __fastcall isTerminated();
    bool __fastcall isAlive();
};

#endif


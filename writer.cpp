/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

				Thread Project

                Definicion para las clases
                    Writer, WriterAction

		Ciclo 2009
*/
#pragma hdrstop

#include "writer.h"
#include "thread.h"
#include "action.h"

__fastcall Writer::Writer(void)
    : writerAction(nullptr), thread(nullptr) {
    writerAction = new WriterAction(this, &Writer::write);
    thread = new Thread(writerAction);
}

__fastcall Writer::~Writer(void) {
    if (writerAction) delete writerAction;
    if (thread) delete thread;
}

void Writer::start() {
    thread->start();
}

void __fastcall Writer::stop(void) {
    thread->stop();
}

void __fastcall Writer::exit(void) {
    thread->exit();
}

void __fastcall Writer::terminateAndWait(void) {
    thread->terminateAndWait();
}

bool __fastcall Writer::isRunning(void) {
    return thread->isRunning();
}

bool __fastcall Writer::isTerminated(void) {
    return thread->isTerminated();
}

bool __fastcall Writer::isAlive(void) {
    return thread->isAlive();
}

unsigned long __fastcall Writer::write(void) {
    while (!isTerminated()) {
        std::cout << "Writer working ..." << std::endl; 
        ::Sleep(100);
    }
    return 0;
}
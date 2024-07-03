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

#include<iostream>
#include "writer.h"
#include "thread.h"
#include "action.h"

__fastcall WriterAction::WriterAction(Writer* writer, Method method): object(writer), function(method) {
}

__fastcall WriterAction::~WriterAction(void) {
}

unsigned long __fastcall WriterAction::execute(void) {
    return (object->*function)();
}

__fastcall Writer::Writer(void)
    : thread(new Thread(writerAction = new WriterAction( this, &Writer::write ))) {
}

__fastcall Writer::~Writer(void) {
    if ( writerAction ) delete writerAction;
    if ( thread ) delete thread;
}

void Writer::start() {
    thread->start();
    // std::cout << "Writer thread started." << std::endl; 
}

void __fastcall Writer::stop(void) {
    thread->stop();
}

void __fastcall Writer::exit(void) {
    thread->exit();
}

void __fastcall Writer::terminateAndWait(void) {
    // std::cout << "Writer thread terminateanWait" << thread->terminateAndWait() << std::endl; 
    thread->terminateAndWait();
}

bool __fastcall Writer::isRunning(void) {
    // std::cout << "Writer thread is running." << thread->isRunning() << std::endl; 
    return thread->isRunning();
}

bool __fastcall Writer::isTerminated(void) {
    //std::cout << "Writer thread has finished." << thread->isTerminated() << std::endl; 
    return thread->isTerminated();
}

bool __fastcall Writer::isAlive(void) {
    //std::cout << "Writer is alive" << thread->isAlive() << std::endl;
    return thread->isAlive();
}

unsigned long __fastcall Writer::write(void) {
    while (!isTerminated()) {
        std::cout << "Writer working ..." << std::endl; 
        ::Sleep(100);
    }
    return 0;
}
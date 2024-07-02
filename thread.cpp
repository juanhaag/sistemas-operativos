/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

                Thread Project

                Definicion para la clase Thread

		Ciclo 2009
*/
#include "thread.h"
#include "action.h"
#pragma package(smart_init)

unsigned long __stdcall Thread::threadFunction(void* threadAction) {
    return ((Action*)threadAction)->execute();
}

__fastcall Thread::Thread(Action* action, DWORD flags, DWORD timeOut)
    : terminated(false), action(action), timeOut(timeOut) {
    thread = ::CreateThread(0, 0, threadFunction, action, flags, &threadId);
    active = (flags != CREATE_SUSPENDED);
}

__fastcall Thread::~Thread(void) {
    terminateAndWait();
}

void __fastcall Thread::start() {
    if (!active) {
        ::ResumeThread(thread);
        active = true;
    }
}

void __fastcall Thread::stop() {
    if (active) {
        ::SuspendThread(thread);
        active = false;
    }
}

void __fastcall Thread::exit() {
    if (!terminated) {
        ::TerminateThread(thread, 0);
        ::WaitForSingleObject(thread, timeOut);
        active = false;
        terminated = true;
    }
}

void __fastcall Thread::terminateAndWait() {
    if (!terminated) {
        ::TerminateThread(thread, 0);
        ::WaitForSingleObject(thread, timeOut);
        terminated = true;
    }
}

bool __fastcall Thread::isRunning() {
    return active;
}

bool __fastcall Thread::isTerminated() {
    return terminated;
}

bool __fastcall Thread::isAlive() {
    return !terminated;
}
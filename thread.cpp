/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

                Thread Project

                Definicion para la clase Thread

		Ciclo 2009
*/
#pragma hdrstop

#include "thread.h"
#pragma package(smart_init)

//
// threadFunction...
unsigned long __stdcall Thread::threadFunction( void* threadAction ) {
	return ( ( Action* ) threadAction )->execute() ;
}

__fastcall Thread::Thread( Action* action, DWORD flags, DWORD timeOut ): terminated( false ) {
		this->timeOut = timeOut ;
        this->action = action ;
		thread = ::CreateThread( 0, 0, threadFunction, action, flags, &threadId ) ;
		active = ( flags != CREATE_SUSPENDED ) ;
}

__fastcall Thread::~Thread( void ) {
		terminateAndWait() ;
}

void __fastcall Thread::start( void ) {
	if ( !active ) {
		::ResumeThread( thread ) ;
		active = true ;
	}
}

void __fastcall Thread::stop( void ) {
	if ( active ) {
		::SuspendThread( thread ) ;
		active = false ;
	}
}

void __fastcall Thread::exit( void ) {
	if ( !terminated ) {
		::TerminateThread( thread, 0 ) ;
		::WaitForSingleObject( thread, timeOut ) ;
		active = false ;
		terminated = true ;
	}
}

void __fastcall Thread::terminateAndWait( void ) {
	if ( !terminated ) {
		::TerminateThread( thread, 0 ) ;
		::WaitForSingleObject( thread, timeOut ) ;
		active = false ;
		terminated = true ;
	}
}

bool __fastcall Thread::isRunning( void ) {
	return active ;
}

bool __fastcall Thread::isTerminated( void ) {
	return terminated ;
}

bool __fastcall Thread::isAlive( void ) {
	return !terminated;
}

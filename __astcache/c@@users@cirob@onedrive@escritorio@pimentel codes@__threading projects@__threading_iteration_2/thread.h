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

#include <vcl.h>
#include "action.h"

class Thread {
	enum { TIME_OUT = 200 } ;
private:
	HANDLE thread ;
	DWORD threadId ;
	DWORD timeOut ;
	BOOL terminated ;
	BOOL active ;
	Action* action ;

        static unsigned long __stdcall threadFunction( void* threadAction ) ;

    public:
		__fastcall Thread( Action* action, DWORD flags = CREATE_SUSPENDED, DWORD timeOut = TIME_OUT ) ;
		__fastcall ~Thread( void ) ;

		void __fastcall start( void ) ;
		void __fastcall stop( void ) ;
		void __fastcall exit( void ) ;
		void __fastcall terminateAndWait( void ) ;
		bool __fastcall isRunning( void ) ;
		bool __fastcall isTerminated( void ) ;
		bool __fastcall isAlive( void ) ;
} ;

#endif

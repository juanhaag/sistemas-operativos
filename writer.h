/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

                Thread Project ( not typing )

                Declaracion para las clases
                    Writer, WriterAction

        Ciclo 2009
*/
#ifndef writerH
#define writerH

#include "action.h"
#include "thread.h"

class Writer ;

class WriterAction : public Action {

	typedef unsigned long __fastcall ( Writer::* Method )( void ) ;

public:
	__fastcall WriterAction( Writer* writer, Method method ) ;
	__fastcall ~WriterAction( void ) ;

	virtual unsigned long __fastcall execute( void ) ;
private:
	Writer* object ;
	Method function ;
} ;

class Writer{
public:
	__fastcall Writer( void ) ;
	__fastcall ~Writer( void ) ;

	void __fastcall start( void ) ;
	void __fastcall stop( void ) ;
	void __fastcall exit( void ) ;
	void __fastcall terminateAndWait( void ) ;
	bool __fastcall isRunnig( void ) ;
	bool __fastcall isTerminated( void ) ;
	bool __fastcall isAlive( void ) ;
private:
	Thread* thread;
	WriterAction* writerAction ;
	unsigned long __fastcall write( void ) ;
} ;

#endif

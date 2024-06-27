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

#pragma package(smart_init)
//
// Metodos para la clase WriterAction ...
__fastcall WriterAction::WriterAction( Writer* writer, Method method ) : object( writer), function( method ) {
}

__fastcall WriterAction::~WriterAction( void ) {
}

unsigned long __fastcall WriterAction::execute( void ) {
	return (object->*function)() ;
} ;
//
// Metodos para la clase Writer ...
__fastcall Writer::Writer( void ){
	writerAction = new WriterAction( this, &Writer::write );
	thread = new Thread( writerAction );
} ;

__fastcall Writer::~Writer( void ) {
	if ( writerAction ) delete writerAction ;
	if ( thread ) delete thread;

} ;

void __fastcall Writer::start( void ) {
	thread->start() ;
} ;

void __fastcall Writer::stop( void ) {
	thread->stop() ;
} ;

void __fastcall Writer::exit( void ) {
	thread->exit() ;
} ;

void __fastcall Writer::terminateAndWait( void ) {
    thread->terminateAndWait() ;
}

bool __fastcall Writer::isRunnig( void ) {
	return thread->isRunning() ;
} ;

bool __fastcall Writer::isTerminated( void ) {
	return thread->isTerminated() ;
} ;

bool __fastcall Writer::isAlive( void ) {
	return !thread->isAlive() ;
} ;

unsigned long __fastcall Writer::write( void ) {
	while ( !thread->isTerminated() ) {
		std::cout << "Writer working ...." << std::endl ;
	}
	return 0 ;
} ;


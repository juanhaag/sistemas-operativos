/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

				Thread Project

                Declaracion para la clase Action

		Ciclo 2009
*/
#pragma hdrstop

#include "action.h"
#include "writer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall WriterAction::WriterAction(Writer* writer, Method method)
    : writer(writer), method(method) {
}

__fastcall WriterAction::~WriterAction(void) {
}

unsigned long __fastcall WriterAction::execute(void) {
    return (writer->*method)();
}

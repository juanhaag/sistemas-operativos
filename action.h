/*
        Instituto Superior de Formacion Tecnica 151
        Tecnicatura Superior en Analisis de Sistemas

        Espacio Curricular Sistemas Operativos

                Thread Project

                Declaracion para la clase Action

        Ciclo 2009
*/
#ifndef actionH
#define actionH

class Writer;

struct Action {
    virtual unsigned long __fastcall execute(void) = 0;
};

class WriterAction : public Action {
public:
    typedef unsigned long (Writer::* Method)(void);

    __fastcall WriterAction(Writer* writer, Method method);
    __fastcall ~WriterAction(void);

    virtual unsigned long __fastcall execute(void) override;

private:
    Writer* writer;
    Method method;
};


#endif
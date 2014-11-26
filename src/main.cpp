#include <QtGui/QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{

            ////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////
            QApplication a(argc, argv);
            ////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////

            QVector<QString> inputArguments;
                             inputArguments.resize(argc);
            for  (int i=0; i<inputArguments.size(); i++)
                             inputArguments[i] = QString::fromLocal8Bit(argv[i]);


            ////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////

            MainWindow www;
            www.define_SEQ_numberStr( inputArguments[1] /*"01"*/ );
            www.initialize();
            www.show();

            return a.exec();

            ////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////

}



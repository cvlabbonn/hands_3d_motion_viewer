#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::read_MODELS_INFO_TXT( QString myFileString_MODELS_INFO_TXT )
{

        QFile myFile( myFileString_MODELS_INFO_TXT );

        myFile.open(QIODevice::ReadOnly);

        if (myFile.exists() == false)   {   qDebug() << "MainWindow::read_MODELS_INFO_TXT - File **" << myFileString_MODELS_INFO_TXT << "** DOESN'T exist !!!!!";   return;     }
        if( !myFile.isOpen() )          {   qDebug() << "MainWindow::read_MODELS_INFO_TXT - File **" << myFileString_MODELS_INFO_TXT << "** DOESN'T open !!!!!";    return;     }

        QTextStream myTextStream(&myFile);

        int                           modelsNumber;
        myTextStream >>               modelsNumber;
        INPUT_ModelNamesQVect.resize( modelsNumber );

        for (int i=0; i<INPUT_ModelNamesQVect.size(); i++)     myTextStream >> INPUT_ModelNamesQVect[i];

        myFile.close();

                                            ui->myCheck_RenderObject_1->setEnabled(false);      ui->myCheck_RenderObject_1->setVisible(false);      ui->myCheck_RenderObject_1->setChecked(false);  ui->myButtonColor_Mesh1->setEnabled(false); ui->myButtonColor_Mesh1->setVisible(false);
                                            ui->myCheck_RenderObject_2->setEnabled(false);      ui->myCheck_RenderObject_2->setVisible(false);      ui->myCheck_RenderObject_2->setChecked(false);  ui->myButtonColor_Mesh2->setEnabled(false); ui->myButtonColor_Mesh2->setVisible(false);
                                            ui->myCheck_RenderObject_3->setEnabled(false);      ui->myCheck_RenderObject_3->setVisible(false);      ui->myCheck_RenderObject_3->setChecked(false);  ui->myButtonColor_Mesh3->setEnabled(false); ui->myButtonColor_Mesh3->setVisible(false);

        if (modelsNumber == 0)              return;
        if (modelsNumber >= 1)      {       ui->myCheck_RenderObject_1->setEnabled(true);       ui->myCheck_RenderObject_1->setVisible(true);       ui->myCheck_RenderObject_1->setChecked(true);   ui->myButtonColor_Mesh1->setEnabled(true);  ui->myButtonColor_Mesh1->setVisible(true);  ui->myCheck_RenderObject_1->setText( INPUT_ModelNamesQVect[0] );   }
        if (modelsNumber >= 2)      {       ui->myCheck_RenderObject_2->setEnabled(true);       ui->myCheck_RenderObject_2->setVisible(true);       ui->myCheck_RenderObject_2->setChecked(true);   ui->myButtonColor_Mesh2->setEnabled(true);  ui->myButtonColor_Mesh2->setVisible(true);  ui->myCheck_RenderObject_2->setText( INPUT_ModelNamesQVect[1] );   }
        if (modelsNumber >= 3)      {       ui->myCheck_RenderObject_3->setEnabled(true);       ui->myCheck_RenderObject_3->setVisible(true);       ui->myCheck_RenderObject_3->setChecked(true);   ui->myButtonColor_Mesh3->setEnabled(true);  ui->myButtonColor_Mesh3->setVisible(true);  ui->myCheck_RenderObject_3->setText( INPUT_ModelNamesQVect[2] );   }

}


void MainWindow::print_MODELS_INFO_TXT()
{

                                                                qDebug() << "\n";
                                                                qDebug() << INPUT_ModelNamesQVect.size();
    for (int mmm=0; mmm<INPUT_ModelNamesQVect.size(); mmm++)    qDebug() << INPUT_ModelNamesQVect[mmm];
                                                                qDebug() << "\n";

}


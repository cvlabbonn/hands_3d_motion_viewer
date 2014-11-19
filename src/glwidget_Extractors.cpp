#include <glwidget.h>



void GLWidget::extractOneFrame_SLOT()
{

        QImage myCapturedFrame = this->grabFrameBuffer();

        QImageWriter imagefile;

        QFile myFileIN( "Capture/SingleFrames/number.txt" );

        if (myFileIN.exists() == true)
        {
                myFileIN.open(QIODevice::ReadOnly);

                if(!myFileIN.isOpen())
                {
                        qDebug() << "- Error, unable to open file in **extractOneFrame_SLOT** for INput";

                        extractOne_Count = -1; // tha afksithei amesws
                }
                else
                {
                        QTextStream myStreamIN(&myFileIN);

                        extractOne_Count = myStreamIN.readAll().toInt();

                        myFileIN.close();
                }
        }
        else            extractOne_Count = -1; // tha afksithei amesws

        ///////////////////
        extractOne_Count++;
        ///////////////////

        QFile myFileOUT( "Capture/SingleFrames/number.txt" );
        myFileOUT.open(QIODevice::WriteOnly);

        if(!myFileOUT.isOpen())
        {
            qDebug() << "- Error, unable to open file in **extractOneFrame_SLOT** for OUTput";
            return;
        }

        QTextStream myStreamOUT(&myFileOUT);

        myStreamOUT << QString::number(extractOne_Count);

        myFileOUT.close();

        QString PATH = "Capture/SingleFrames/" + QString::number( extractOne_Count ).rightJustified(5,'0',false) + ".jpg";

        imagefile.setFileName( PATH );
        imagefile.setFormat("jpg");
        imagefile.setQuality( 100 );
        imagefile.write(myCapturedFrame);

        QDir basedir = QDir(QApplication::applicationDirPath());
        basedir.cdUp();
        QString basePath = basedir.path();
        std::cout << "Image rendered @ " << QString(basePath+PATH).toStdString() << std::endl;

}

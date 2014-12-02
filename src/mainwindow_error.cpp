#include "mainwindow.h"

void MainWindow::error_manager(int error){
    QMessageBox messageBox;

    switch ( error ) {
    case 1:
        messageBox.critical( 0, "Error", "The folder doesn't exist or doesn't contain a valid dataset" );
        break;
    case 2:
        messageBox.critical( 0, "Error", "The folder is not the correct one for the current sequence or you have not chosen a sequence." );
        break;
    default:
        break;
    }
}

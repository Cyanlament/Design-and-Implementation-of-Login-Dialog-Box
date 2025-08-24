#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    LoginDialog dialog;
    if (dialog.exec() == QDialog::Accepted) {
        // Login successful - could show main window here
        return 0;
    }
    
    return 0;
}
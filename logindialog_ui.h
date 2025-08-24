#ifndef LOGINDIALOG_UI_H
#define LOGINDIALOG_UI_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginDialog; }
QT_END_NAMESPACE

class RegisterDialog;

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    
private slots:
    void onLoginClicked();
    void onResetClicked();
    void onRegisterClicked();
    void togglePasswordVisibility();
    
private:
    void setupConnections();
    bool validateCredentials(const QString &username, const QString &password);
    void saveUserCredentials(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
    
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_UI_H
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QPixmap>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QDateTime>

class RegisterDialog;

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    
private slots:
    void onLoginClicked();
    void onResetClicked();
    void onRegisterClicked();
    void togglePasswordVisibility();
    
private:
    void setupUI();
    void setupStyles();
    bool validateCredentials(const QString &username, const QString &password);
    void saveUserCredentials(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
    
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginButton;
    QPushButton *resetButton;
    QPushButton *registerButton;
    QPushButton *togglePasswordButton;
    QLabel *titleLabel;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *logoLabel;
};

#endif // LOGINDIALOG_H
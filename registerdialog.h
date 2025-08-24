#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QDateTime>
#include <QRegExpValidator>

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    
private slots:
    void onRegisterClicked();
    void onCancelClicked();
    void togglePasswordVisibility();
    void toggleConfirmPasswordVisibility();
    void onPasswordChanged();
    void onConfirmPasswordChanged();
    
private:
    void setupUI();
    void setupStyles();
    bool validateInput();
    bool userExists(const QString &username);
    void saveUserCredentials(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
    
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *confirmPasswordEdit;
    QLineEdit *emailEdit;
    QPushButton *registerButton;
    QPushButton *cancelButton;
    QPushButton *togglePasswordButton;
    QPushButton *toggleConfirmPasswordButton;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *confirmPasswordLabel;
    QLabel *emailLabel;
    QLabel *passwordStrengthLabel;
    QLabel *passwordMatchLabel;
};

#endif // REGISTERDIALOG_H
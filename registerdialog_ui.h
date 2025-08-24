#ifndef REGISTERDIALOG_UI_H
#define REGISTERDIALOG_UI_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCryptographicHash>
#include <QDateTime>
#include <QRegExp>

QT_BEGIN_NAMESPACE
namespace Ui { class RegisterDialog; }
QT_END_NAMESPACE

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();
    
private slots:
    void onRegisterClicked();
    void onCancelClicked();
    void togglePasswordVisibility();
    void toggleConfirmPasswordVisibility();
    void onPasswordChanged();
    void onConfirmPasswordChanged();
    
private:
    void setupConnections();
    bool validateInput();
    bool userExists(const QString &username);
    void saveUserCredentials(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
    
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_UI_H
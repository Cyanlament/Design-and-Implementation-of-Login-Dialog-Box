#include "logindialog_ui.h"
#include "ui_logindialog.h"
#include "registerdialog_ui.h"
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setupConnections();
    
    // Create default admin account if users.txt doesn't exist
    QFile file("users.txt");
    if (!file.exists()) {
        saveUserCredentials("admin", "admin123");
        saveUserCredentials("user", "password");
    }
    
    ui->usernameEdit->setFocus();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::setupConnections()
{
    // Connect button signals
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &LoginDialog::onResetClicked);
    connect(ui->registerButton, &QPushButton::clicked, this, &LoginDialog::onRegisterClicked);
    connect(ui->togglePasswordButton, &QPushButton::clicked, this, &LoginDialog::togglePasswordVisibility);
    
    // Enter key support
    connect(ui->usernameEdit, &QLineEdit::returnPressed, this, &LoginDialog::onLoginClicked);
    connect(ui->passwordEdit, &QLineEdit::returnPressed, this, &LoginDialog::onLoginClicked);
}

void LoginDialog::onLoginClicked()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    
    if (username.isEmpty()) {
        QMessageBox::warning(this, "登录失败", "请输入用户名！");
        ui->usernameEdit->setFocus();
        return;
    }
    
    if (password.isEmpty()) {
        QMessageBox::warning(this, "登录失败", "请输入密码！");
        ui->passwordEdit->setFocus();
        return;
    }
    
    if (validateCredentials(username, password)) {
        QMessageBox::information(this, "登录成功", 
            QString("欢迎您，%1！\n登录时间：%2")
            .arg(username)
            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
        accept();
    } else {
        QMessageBox::critical(this, "登录失败", 
            "用户名或密码错误！\n\n提示：默认账户\n用户名：admin 密码：admin123\n用户名：user 密码：password");
        ui->passwordEdit->clear();
        ui->passwordEdit->setFocus();
    }
}

void LoginDialog::onResetClicked()
{
    ui->usernameEdit->clear();
    ui->passwordEdit->clear();
    ui->usernameEdit->setFocus();
}

void LoginDialog::onRegisterClicked()
{
    RegisterDialog *registerDialog = new RegisterDialog(this);
    if (registerDialog->exec() == QDialog::Accepted) {
        QMessageBox::information(this, "提示", "注册成功！您现在可以使用新账户登录。");
    }
    delete registerDialog;
}

void LoginDialog::togglePasswordVisibility()
{
    if (ui->togglePasswordButton->isChecked()) {
        ui->passwordEdit->setEchoMode(QLineEdit::Normal);
        ui->togglePasswordButton->setText("🙈");
    } else {
        ui->passwordEdit->setEchoMode(QLineEdit::Password);
        ui->togglePasswordButton->setText("👁");
    }
}

bool LoginDialog::validateCredentials(const QString &username, const QString &password)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open users.txt";
        return false;
    }
    
    QTextStream in(&file);
    QString hashedPassword = hashPassword(password);
    
    qDebug() << "登录尝试 - 用户:" << username << "哈希:" << hashedPassword;
    
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");
        qDebug() << "检查行:" << line;
        if (parts.size() == 2 && parts[0] == username && parts[1] == hashedPassword) {
            qDebug() << "登录验证成功!";
            return true;
        }
    }
    
    qDebug() << "登录验证失败!";
    return false;
}

void LoginDialog::saveUserCredentials(const QString &username, const QString &password)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Cannot open users.txt for writing";
        return;
    }
    
    QTextStream out(&file);
    out << username << ":" << hashPassword(password) << "\n";
}

QString LoginDialog::hashPassword(const QString &password)
{
    return QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
}
#include "registerdialog_ui.h"
#include "ui_registerdialog.h"
#include <QDebug>

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    setupConnections();
    
    ui->usernameEdit->setFocus();
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::setupConnections()
{
    // Connect button signals
    connect(ui->registerButton, &QPushButton::clicked, this, &RegisterDialog::onRegisterClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &RegisterDialog::onCancelClicked);
    connect(ui->togglePasswordButton, &QPushButton::clicked, this, &RegisterDialog::togglePasswordVisibility);
    connect(ui->toggleConfirmPasswordButton, &QPushButton::clicked, this, &RegisterDialog::toggleConfirmPasswordVisibility);
    
    // Connect text change signals for real-time validation
    connect(ui->passwordEdit, &QLineEdit::textChanged, this, &RegisterDialog::onPasswordChanged);
    connect(ui->confirmPasswordEdit, &QLineEdit::textChanged, this, &RegisterDialog::onConfirmPasswordChanged);
    
    // Enter key support
    connect(ui->confirmPasswordEdit, &QLineEdit::returnPressed, this, &RegisterDialog::onRegisterClicked);
}

void RegisterDialog::onRegisterClicked()
{
    if (!validateInput()) {
        return;
    }
    
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    QString email = ui->emailEdit->text().trimmed();
    
    if (userExists(username)) {
        QMessageBox::warning(this, "注册失败", "用户名已存在，请选择其他用户名！");
        ui->usernameEdit->setFocus();
        ui->usernameEdit->selectAll();
        return;
    }
    
    // Save user credentials
    saveUserCredentials(username, password);
    
    // Save additional user info to a separate file
    QFile userInfoFile("userinfo.txt");
    if (userInfoFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&userInfoFile);
        out << QString("%1|%2|%3\n")
            .arg(username)
            .arg(email.isEmpty() ? "未提供" : email)
            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        userInfoFile.flush(); // 强制刷新到磁盘
    }
    
    qDebug() << "用户注册成功:" << username;
    
    QMessageBox::information(this, "注册成功", 
        QString("用户 \"%1\" 注册成功！\n注册时间：%2\n\n您现在可以使用新账户登录。")
        .arg(username)
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
    
    accept();
}

void RegisterDialog::onCancelClicked()
{
    reject();
}

void RegisterDialog::togglePasswordVisibility()
{
    if (ui->togglePasswordButton->isChecked()) {
        ui->passwordEdit->setEchoMode(QLineEdit::Normal);
        ui->togglePasswordButton->setText("🙈");
    } else {
        ui->passwordEdit->setEchoMode(QLineEdit::Password);
        ui->togglePasswordButton->setText("👁");
    }
}

void RegisterDialog::toggleConfirmPasswordVisibility()
{
    if (ui->toggleConfirmPasswordButton->isChecked()) {
        ui->confirmPasswordEdit->setEchoMode(QLineEdit::Normal);
        ui->toggleConfirmPasswordButton->setText("🙈");
    } else {
        ui->confirmPasswordEdit->setEchoMode(QLineEdit::Password);
        ui->toggleConfirmPasswordButton->setText("👁");
    }
}

void RegisterDialog::onPasswordChanged()
{
    QString password = ui->passwordEdit->text();
    
    if (password.isEmpty()) {
        ui->passwordStrengthLabel->setText("");
        return;
    }
    
    // Check password strength
    int strength = 0;
    if (password.length() >= 6) strength++;
    if (password.length() >= 8) strength++;
    if (password.contains(QRegExp("[a-z]"))) strength++;
    if (password.contains(QRegExp("[A-Z]"))) strength++;
    if (password.contains(QRegExp("[0-9]"))) strength++;
    if (password.contains(QRegExp("[^a-zA-Z0-9]"))) strength++;
    
    QString strengthText;
    QString color;
    
    if (strength < 2) {
        strengthText = "密码强度：弱";
        color = "#ff4757";
    } else if (strength < 4) {
        strengthText = "密码强度：中等";
        color = "#ffa502";
    } else {
        strengthText = "密码强度：强";
        color = "#2ed573";
    }
    
    ui->passwordStrengthLabel->setText(strengthText);
    ui->passwordStrengthLabel->setStyleSheet(QString("color: %1; font-weight: bold;").arg(color));
    
    // Check password match
    onConfirmPasswordChanged();
}

void RegisterDialog::onConfirmPasswordChanged()
{
    QString password = ui->passwordEdit->text();
    QString confirmPassword = ui->confirmPasswordEdit->text();
    
    if (confirmPassword.isEmpty()) {
        ui->passwordMatchLabel->setText("");
        return;
    }
    
    if (password == confirmPassword) {
        ui->passwordMatchLabel->setText("✓ 密码匹配");
        ui->passwordMatchLabel->setStyleSheet("color: #2ed573; font-weight: bold;");
    } else {
        ui->passwordMatchLabel->setText("✗ 密码不匹配");
        ui->passwordMatchLabel->setStyleSheet("color: #ff4757; font-weight: bold;");
    }
}

bool RegisterDialog::validateInput()
{
    QString username = ui->usernameEdit->text().trimmed();
    QString password = ui->passwordEdit->text();
    QString confirmPassword = ui->confirmPasswordEdit->text();
    QString email = ui->emailEdit->text().trimmed();
    
    // Validate username
    if (username.isEmpty()) {
        QMessageBox::warning(this, "注册失败", "请输入用户名！");
        ui->usernameEdit->setFocus();
        return false;
    }
    
    if (username.length() < 3 || username.length() > 20) {
        QMessageBox::warning(this, "注册失败", "用户名长度必须在3-20个字符之间！");
        ui->usernameEdit->setFocus();
        ui->usernameEdit->selectAll();
        return false;
    }
    
    // Check for valid username characters
    QRegExp usernameRegex("^[a-zA-Z0-9_\\u4e00-\\u9fa5]+$");
    if (!usernameRegex.exactMatch(username)) {
        QMessageBox::warning(this, "注册失败", "用户名只能包含字母、数字、下划线和中文字符！");
        ui->usernameEdit->setFocus();
        ui->usernameEdit->selectAll();
        return false;
    }
    
    // Validate password
    if (password.isEmpty()) {
        QMessageBox::warning(this, "注册失败", "请输入密码！");
        ui->passwordEdit->setFocus();
        return false;
    }
    
    if (password.length() < 6) {
        QMessageBox::warning(this, "注册失败", "密码长度至少需要6位字符！");
        ui->passwordEdit->setFocus();
        ui->passwordEdit->selectAll();
        return false;
    }
    
    // Validate password confirmation
    if (confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "注册失败", "请确认密码！");
        ui->confirmPasswordEdit->setFocus();
        return false;
    }
    
    if (password != confirmPassword) {
        QMessageBox::warning(this, "注册失败", "两次输入的密码不一致！");
        ui->confirmPasswordEdit->setFocus();
        ui->confirmPasswordEdit->selectAll();
        return false;
    }
    
    // Validate email (optional but if provided, must be valid)
    if (!email.isEmpty()) {
        QRegExp emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        if (!emailRegex.exactMatch(email)) {
            QMessageBox::warning(this, "注册失败", "邮箱格式不正确！");
            ui->emailEdit->setFocus();
            ui->emailEdit->selectAll();
            return false;
        }
    }
    
    return true;
}

bool RegisterDialog::userExists(const QString &username)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");
        if (parts.size() >= 1 && parts[0] == username) {
            return true;
        }
    }
    
    return false;
}

void RegisterDialog::saveUserCredentials(const QString &username, const QString &password)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Cannot open users.txt for writing";
        return;
    }
    
    QTextStream out(&file);
    QString hashedPwd = hashPassword(password);
    out << username << ":" << hashedPwd << "\n";
    file.flush(); // 强制刷新到磁盘
    
    qDebug() << "保存用户:" << username << "哈希:" << hashedPwd;
}

QString RegisterDialog::hashPassword(const QString &password)
{
    return QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
}
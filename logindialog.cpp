#include "logindialog.h"
#include "registerdialog.h"
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
    setupStyles();
    
    // Create default admin account if users.txt doesn't exist
    QFile file("users.txt");
    if (!file.exists()) {
        saveUserCredentials("admin", "admin123");
        saveUserCredentials("user", "password");
    }
}

void LoginDialog::setupUI()
{
    setWindowTitle("用户登录");
    setFixedSize(400, 500);
    
    // Create widgets
    titleLabel = new QLabel("用户登录");
    logoLabel = new QLabel("请输入您的账号信息");
    usernameLabel = new QLabel("用户名:");
    passwordLabel = new QLabel("密码:");
    
    usernameEdit = new QLineEdit();
    usernameEdit->setPlaceholderText("请输入用户名");
    
    passwordEdit = new QLineEdit();
    passwordEdit->setPlaceholderText("请输入密码");
    passwordEdit->setEchoMode(QLineEdit::Password);
    
    togglePasswordButton = new QPushButton("👁");
    togglePasswordButton->setFixedSize(35, 35);
    togglePasswordButton->setCheckable(true);
    
    loginButton = new QPushButton("登录");
    resetButton = new QPushButton("取消");
    registerButton = new QPushButton("注册");
    
    // Layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(40, 60, 40, 40);
    mainLayout->setSpacing(0);
    
    // Header section
    QVBoxLayout *headerLayout = new QVBoxLayout();
    headerLayout->setAlignment(Qt::AlignCenter);
    headerLayout->setSpacing(10);
    
    titleLabel->setAlignment(Qt::AlignCenter);
    logoLabel->setAlignment(Qt::AlignCenter);
    
    headerLayout->addWidget(titleLabel);
    headerLayout->addWidget(logoLabel);
    
    // Form section with better spacing
    QVBoxLayout *formLayout = new QVBoxLayout();
    formLayout->setSpacing(15);
    
    // Username field
    QVBoxLayout *usernameLayout = new QVBoxLayout();
    usernameLayout->setSpacing(8);
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(usernameEdit);
    
    // Password field with toggle button
    QVBoxLayout *passwordLayout = new QVBoxLayout();
    passwordLayout->setSpacing(8);
    passwordLayout->addWidget(passwordLabel);
    
    QHBoxLayout *passwordInputLayout = new QHBoxLayout();
    passwordInputLayout->setSpacing(0);
    passwordInputLayout->addWidget(passwordEdit);
    passwordInputLayout->addWidget(togglePasswordButton);
    
    passwordLayout->addLayout(passwordInputLayout);
    
    formLayout->addLayout(usernameLayout);
    formLayout->addLayout(passwordLayout);
    
    // Button section
    QVBoxLayout *buttonLayout = new QVBoxLayout();
    buttonLayout->setSpacing(15);
    
    // Main login button
    buttonLayout->addWidget(loginButton);
    
    // Secondary buttons
    QHBoxLayout *secondaryButtonLayout = new QHBoxLayout();
    secondaryButtonLayout->addWidget(resetButton);
    secondaryButtonLayout->addStretch();
    secondaryButtonLayout->addWidget(registerButton);
    
    buttonLayout->addLayout(secondaryButtonLayout);
    
    // Assemble main layout
    mainLayout->addLayout(headerLayout);
    mainLayout->addSpacing(40);
    mainLayout->addLayout(formLayout);
    mainLayout->addSpacing(30);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    
    // Connect signals
    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);
    connect(resetButton, &QPushButton::clicked, this, &LoginDialog::onResetClicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginDialog::onRegisterClicked);
    connect(togglePasswordButton, &QPushButton::clicked, this, &LoginDialog::togglePasswordVisibility);
    
    // Enter key support
    connect(usernameEdit, &QLineEdit::returnPressed, this, &LoginDialog::onLoginClicked);
    connect(passwordEdit, &QLineEdit::returnPressed, this, &LoginDialog::onLoginClicked);
}

void LoginDialog::setupStyles()
{
    setStyleSheet(R"(
        QDialog {
            background: white;
        }
        
        QLabel#title {
            font-size: 28px;
            font-weight: bold;
            color: #333333;
            margin: 20px 0 10px 0;
        }
        
        QLabel#logo {
            font-size: 14px;
            color: #666666;
            margin: 0 0 30px 0;
        }
        
        QLabel {
            color: #333333;
            font-size: 14px;
            font-weight: normal;
            margin: 0 0 5px 0;
        }
        
        QLineEdit {
            padding: 15px;
            border: 1px solid #e0e0e0;
            border-radius: 8px;
            font-size: 14px;
            background: white;
            margin: 0 0 20px 0;
            min-height: 20px;
        }
        
        QLineEdit:focus {
            border-color: #667eea;
            outline: none;
        }
        
        QPushButton#loginButton {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 #667eea, stop:1 #764ba2);
            color: white;
            border: none;
            border-radius: 8px;
            padding: 15px;
            font-size: 16px;
            font-weight: bold;
            margin: 10px 0;
            min-height: 20px;
        }
        
        QPushButton#loginButton:hover {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 #5a67d8, stop:1 #6b46c1);
        }
        
        QPushButton#loginButton:pressed {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 #4c51bf, stop:1 #553c9a);
        }
        
        QPushButton#resetButton {
            background: transparent;
            color: #666666;
            border: none;
            padding: 10px 15px;
            font-size: 14px;
            margin: 5px;
        }
        
        QPushButton#resetButton:hover {
            color: #333333;
            text-decoration: underline;
        }
        
        QPushButton#registerButton {
            background: transparent;
            color: #667eea;
            border: none;
            padding: 10px 15px;
            font-size: 14px;
            margin: 5px;
        }
        
        QPushButton#registerButton:hover {
            color: #5a67d8;
            text-decoration: underline;
        }
        
        QPushButton#togglePassword {
            background: transparent;
            border: none;
            color: #666666;
            margin: 0;
            padding: 8px;
        }
        
        QPushButton#togglePassword:hover {
            background: #f5f5f5;
            border-radius: 4px;
        }
    )");
    
    titleLabel->setObjectName("title");
    logoLabel->setObjectName("logo");
    loginButton->setObjectName("loginButton");
    resetButton->setObjectName("resetButton");
    registerButton->setObjectName("registerButton");
    togglePasswordButton->setObjectName("togglePassword");
}

void LoginDialog::onLoginClicked()
{
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text();
    
    if (username.isEmpty()) {
        QMessageBox::warning(this, "登录失败", "请输入用户名！");
        usernameEdit->setFocus();
        return;
    }
    
    if (password.isEmpty()) {
        QMessageBox::warning(this, "登录失败", "请输入密码！");
        passwordEdit->setFocus();
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
        passwordEdit->clear();
        passwordEdit->setFocus();
    }
}

void LoginDialog::onResetClicked()
{
    usernameEdit->clear();
    passwordEdit->clear();
    usernameEdit->setFocus();
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
    if (togglePasswordButton->isChecked()) {
        passwordEdit->setEchoMode(QLineEdit::Normal);
        togglePasswordButton->setText("🙈");
    } else {
        passwordEdit->setEchoMode(QLineEdit::Password);
        togglePasswordButton->setText("👁");
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
    
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(":");
        if (parts.size() == 2 && parts[0] == username && parts[1] == hashedPassword) {
            return true;
        }
    }
    
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
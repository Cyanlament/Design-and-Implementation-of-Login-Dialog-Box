#include "registerdialog.h"
#include <QDebug>
#include <QRegExp>

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUI();
    setupStyles();
}

void RegisterDialog::setupUI()
{
    setWindowTitle("用户注册");
    setFixedSize(400, 600);
    
    // Create widgets
    titleLabel = new QLabel("用户注册");
    subtitleLabel = new QLabel("创建您的新账户");
    usernameLabel = new QLabel("用户名:");
    passwordLabel = new QLabel("密码:");
    confirmPasswordLabel = new QLabel("确认密码:");
    emailLabel = new QLabel("邮箱:");
    
    usernameEdit = new QLineEdit();
    usernameEdit->setPlaceholderText("请输入用户名（3-20位字符）");
    
    passwordEdit = new QLineEdit();
    passwordEdit->setPlaceholderText("请输入密码（至少6位）");
    passwordEdit->setEchoMode(QLineEdit::Password);
    
    confirmPasswordEdit = new QLineEdit();
    confirmPasswordEdit->setPlaceholderText("请再次输入密码");
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    
    emailEdit = new QLineEdit();
    emailEdit->setPlaceholderText("请输入邮箱地址（可选）");
    
    togglePasswordButton = new QPushButton("👁");
    togglePasswordButton->setFixedSize(35, 35);
    togglePasswordButton->setCheckable(true);
    
    toggleConfirmPasswordButton = new QPushButton("👁");
    toggleConfirmPasswordButton->setFixedSize(35, 35);
    toggleConfirmPasswordButton->setCheckable(true);
    
    passwordStrengthLabel = new QLabel("");
    passwordMatchLabel = new QLabel("");
    
    registerButton = new QPushButton("注册");
    cancelButton = new QPushButton("取消");
    
    // Layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(40, 40, 40, 40);
    mainLayout->setSpacing(0);
    
    // Header section
    QVBoxLayout *headerLayout = new QVBoxLayout();
    headerLayout->setAlignment(Qt::AlignCenter);
    headerLayout->setSpacing(10);
    
    titleLabel->setAlignment(Qt::AlignCenter);
    subtitleLabel->setAlignment(Qt::AlignCenter);
    
    headerLayout->addWidget(titleLabel);
    headerLayout->addWidget(subtitleLabel);
    
    // Form section
    QVBoxLayout *formLayout = new QVBoxLayout();
    formLayout->setSpacing(15);
    
    // Username field
    QVBoxLayout *usernameLayout = new QVBoxLayout();
    usernameLayout->setSpacing(8);
    usernameLayout->addWidget(usernameLabel);
    usernameLayout->addWidget(usernameEdit);
    
    // Email field
    QVBoxLayout *emailLayout = new QVBoxLayout();
    emailLayout->setSpacing(8);
    emailLayout->addWidget(emailLabel);
    emailLayout->addWidget(emailEdit);
    
    // Password field with toggle button
    QVBoxLayout *passwordLayout = new QVBoxLayout();
    passwordLayout->setSpacing(8);
    passwordLayout->addWidget(passwordLabel);
    
    QHBoxLayout *passwordInputLayout = new QHBoxLayout();
    passwordInputLayout->setSpacing(0);
    passwordInputLayout->addWidget(passwordEdit);
    passwordInputLayout->addWidget(togglePasswordButton);
    
    passwordLayout->addLayout(passwordInputLayout);
    passwordLayout->addWidget(passwordStrengthLabel);
    
    // Confirm password field
    QVBoxLayout *confirmPasswordLayout = new QVBoxLayout();
    confirmPasswordLayout->setSpacing(8);
    confirmPasswordLayout->addWidget(confirmPasswordLabel);
    
    QHBoxLayout *confirmPasswordInputLayout = new QHBoxLayout();
    confirmPasswordInputLayout->setSpacing(0);
    confirmPasswordInputLayout->addWidget(confirmPasswordEdit);
    confirmPasswordInputLayout->addWidget(toggleConfirmPasswordButton);
    
    confirmPasswordLayout->addLayout(confirmPasswordInputLayout);
    confirmPasswordLayout->addWidget(passwordMatchLabel);
    
    formLayout->addLayout(usernameLayout);
    formLayout->addLayout(emailLayout);
    formLayout->addLayout(passwordLayout);
    formLayout->addLayout(confirmPasswordLayout);
    
    // Button section
    QVBoxLayout *buttonLayout = new QVBoxLayout();
    buttonLayout->setSpacing(15);
    
    // Main register button
    buttonLayout->addWidget(registerButton);
    
    // Cancel button
    QHBoxLayout *cancelButtonLayout = new QHBoxLayout();
    cancelButtonLayout->addStretch();
    cancelButtonLayout->addWidget(cancelButton);
    cancelButtonLayout->addStretch();
    
    buttonLayout->addLayout(cancelButtonLayout);
    
    // Assemble main layout
    mainLayout->addLayout(headerLayout);
    mainLayout->addSpacing(30);
    mainLayout->addLayout(formLayout);
    mainLayout->addSpacing(25);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();
    
    // Connect signals
    connect(registerButton, &QPushButton::clicked, this, &RegisterDialog::onRegisterClicked);
    connect(cancelButton, &QPushButton::clicked, this, &RegisterDialog::onCancelClicked);
    connect(togglePasswordButton, &QPushButton::clicked, this, &RegisterDialog::togglePasswordVisibility);
    connect(toggleConfirmPasswordButton, &QPushButton::clicked, this, &RegisterDialog::toggleConfirmPasswordVisibility);
    connect(passwordEdit, &QLineEdit::textChanged, this, &RegisterDialog::onPasswordChanged);
    connect(confirmPasswordEdit, &QLineEdit::textChanged, this, &RegisterDialog::onConfirmPasswordChanged);
    
    // Enter key support
    connect(confirmPasswordEdit, &QLineEdit::returnPressed, this, &RegisterDialog::onRegisterClicked);
    
    usernameEdit->setFocus();
}

void RegisterDialog::setupStyles()
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
        
        QLabel#subtitle {
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
        
        QLabel#strengthLabel {
            font-size: 12px;
            margin: 3px 0 0 0;
        }
        
        QLabel#matchLabel {
            font-size: 12px;
            margin: 3px 0 0 0;
        }
        
        QLineEdit {
            padding: 15px;
            border: 1px solid #e0e0e0;
            border-radius: 8px;
            font-size: 14px;
            background: white;
            margin: 0 0 5px 0;
            min-height: 20px;
        }
        
        QLineEdit:focus {
            border-color: #667eea;
            outline: none;
        }
        
        QPushButton#registerButton {
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
        
        QPushButton#registerButton:hover {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 #5a67d8, stop:1 #6b46c1);
        }
        
        QPushButton#registerButton:pressed {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 #4c51bf, stop:1 #553c9a);
        }
        
        QPushButton#registerButton:disabled {
            background: #cccccc;
            color: #999999;
        }
        
        QPushButton#cancelButton {
            background: transparent;
            color: #666666;
            border: none;
            padding: 10px 15px;
            font-size: 14px;
            margin: 5px;
        }
        
        QPushButton#cancelButton:hover {
            color: #333333;
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
    subtitleLabel->setObjectName("subtitle");
    registerButton->setObjectName("registerButton");
    cancelButton->setObjectName("cancelButton");
    togglePasswordButton->setObjectName("togglePassword");
    toggleConfirmPasswordButton->setObjectName("togglePassword");
    passwordStrengthLabel->setObjectName("strengthLabel");
    passwordMatchLabel->setObjectName("matchLabel");
}

void RegisterDialog::onRegisterClicked()
{
    if (!validateInput()) {
        return;
    }
    
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text();
    QString email = emailEdit->text().trimmed();
    
    if (userExists(username)) {
        QMessageBox::warning(this, "注册失败", "用户名已存在，请选择其他用户名！");
        usernameEdit->setFocus();
        usernameEdit->selectAll();
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
    }
    
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
    if (togglePasswordButton->isChecked()) {
        passwordEdit->setEchoMode(QLineEdit::Normal);
        togglePasswordButton->setText("🙈");
    } else {
        passwordEdit->setEchoMode(QLineEdit::Password);
        togglePasswordButton->setText("👁");
    }
}

void RegisterDialog::toggleConfirmPasswordVisibility()
{
    if (toggleConfirmPasswordButton->isChecked()) {
        confirmPasswordEdit->setEchoMode(QLineEdit::Normal);
        toggleConfirmPasswordButton->setText("🙈");
    } else {
        confirmPasswordEdit->setEchoMode(QLineEdit::Password);
        toggleConfirmPasswordButton->setText("👁");
    }
}

void RegisterDialog::onPasswordChanged()
{
    QString password = passwordEdit->text();
    
    if (password.isEmpty()) {
        passwordStrengthLabel->setText("");
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
    
    passwordStrengthLabel->setText(strengthText);
    passwordStrengthLabel->setStyleSheet(QString("color: %1; font-weight: bold;").arg(color));
    
    // Check password match
    onConfirmPasswordChanged();
}

void RegisterDialog::onConfirmPasswordChanged()
{
    QString password = passwordEdit->text();
    QString confirmPassword = confirmPasswordEdit->text();
    
    if (confirmPassword.isEmpty()) {
        passwordMatchLabel->setText("");
        return;
    }
    
    if (password == confirmPassword) {
        passwordMatchLabel->setText("✓ 密码匹配");
        passwordMatchLabel->setStyleSheet("color: #2ed573; font-weight: bold;");
    } else {
        passwordMatchLabel->setText("✗ 密码不匹配");
        passwordMatchLabel->setStyleSheet("color: #ff4757; font-weight: bold;");
    }
}

bool RegisterDialog::validateInput()
{
    QString username = usernameEdit->text().trimmed();
    QString password = passwordEdit->text();
    QString confirmPassword = confirmPasswordEdit->text();
    QString email = emailEdit->text().trimmed();
    
    // Validate username
    if (username.isEmpty()) {
        QMessageBox::warning(this, "注册失败", "请输入用户名！");
        usernameEdit->setFocus();
        return false;
    }
    
    if (username.length() < 3 || username.length() > 20) {
        QMessageBox::warning(this, "注册失败", "用户名长度必须在3-20个字符之间！");
        usernameEdit->setFocus();
        usernameEdit->selectAll();
        return false;
    }
    
    // Check for valid username characters
    QRegExp usernameRegex("^[a-zA-Z0-9_\\u4e00-\\u9fa5]+$");
    if (!usernameRegex.exactMatch(username)) {
        QMessageBox::warning(this, "注册失败", "用户名只能包含字母、数字、下划线和中文字符！");
        usernameEdit->setFocus();
        usernameEdit->selectAll();
        return false;
    }
    
    // Validate password
    if (password.isEmpty()) {
        QMessageBox::warning(this, "注册失败", "请输入密码！");
        passwordEdit->setFocus();
        return false;
    }
    
    if (password.length() < 6) {
        QMessageBox::warning(this, "注册失败", "密码长度至少需要6位字符！");
        passwordEdit->setFocus();
        passwordEdit->selectAll();
        return false;
    }
    
    // Validate password confirmation
    if (confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "注册失败", "请确认密码！");
        confirmPasswordEdit->setFocus();
        return false;
    }
    
    if (password != confirmPassword) {
        QMessageBox::warning(this, "注册失败", "两次输入的密码不一致！");
        confirmPasswordEdit->setFocus();
        confirmPasswordEdit->selectAll();
        return false;
    }
    
    // Validate email (optional but if provided, must be valid)
    if (!email.isEmpty()) {
        QRegExp emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
        if (!emailRegex.exactMatch(email)) {
            QMessageBox::warning(this, "注册失败", "邮箱格式不正确！");
            emailEdit->setFocus();
            emailEdit->selectAll();
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
    out << username << ":" << hashPassword(password) << "\n";
}

QString RegisterDialog::hashPassword(const QString &password)
{
    return QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
}
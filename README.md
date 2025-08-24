作业1：登录对话框设计与实现
1.1 功能需求分析
登录对话框是软件系统中重要的用户身份验证组件，本系统需要实现完整的用户登录和注册功能。系统的主要功能需求包括用户身份验证、用户注册管理、界面交互优化等方面。
用户身份验证是系统的核心功能，需要支持用户名和密码的输入验证机制。当用户输入正确的用户名和密码时，系统应该验证通过并显示登录成功信息。当输入错误的用户名或密码时，系统需要给出明确的错误提示，帮助用户纠正输入错误。为了保证系统安全性，所有密码都需要进行加密处理后存储，避免明文保存敏感信息。
用户注册功能是系统的重要扩展，允许新用户创建账户。注册过程需要收集用户名、密码、确认密码等基本信息，还可以选择性收集邮箱地址等扩展信息。系统需要对注册信息进行完整性验证，包括用户名长度限制、格式检查、重复性验证等。密码设置需要有强度要求，并提供实时的强度反馈，帮助用户设置安全可靠的密码。
界面交互方面需要提供良好的用户体验，包括清晰的视觉设计、合理的布局安排、便捷的操作方式等。界面应该支持键盘快捷操作，如回车键登录、Tab键切换输入框等。密码输入需要提供可见性切换功能，方便用户确认输入内容。系统还需要提供及时的操作反馈，让用户了解当前的操作状态和结果。
用例图
参与者	用例	描述
用户	用户登录	输入用户名和密码进行身份验证
用户	用户注册	创建新的用户账户
用户	密码可见性切换	显示或隐藏密码输入内容
系统	身份验证	验证用户凭据的有效性
系统	数据存储	保存和读取用户信息

1.2 系统设计步骤
系统采用模块化的设计思路，将用户界面、业务逻辑和数据存储分离，确保系统的可维护性和可扩展性。整体架构采用经典的Model-View-Controller模式，LoginDialog类作为主要的控制器，协调用户界面操作和数据处理逻辑。
界面设计阶段着重考虑用户体验和现代化视觉效果。采用Qt的UI文件设计方式，将界面布局与业务逻辑分离，便于后续的维护和修改。界面采用白色简洁的现代化设计风格，使用圆角元素和渐变效果提升视觉吸引力。布局使用响应式设计，确保在不同屏幕尺寸下都能正常显示。
数据存储设计采用文件存储方式，便于部署和测试。用户认证信息存储在users.txt文件中，使用用户名和加密密码的键值对格式。用户扩展信息存储在userinfo.txt文件中，包含注册时间、邮箱等信息。密码加密采用SHA-256哈希算法，确保存储安全。
功能实现阶段按照登录验证、用户注册、界面优化的顺序进行开发。登录验证模块实现用户输入检查、密码哈希验证、错误处理等功能。用户注册模块实现注册表单验证、密码强度检测、用户名重复检查等功能。界面优化包括样式美化、交互改进、用户反馈等方面。
系统架构图
用户界面层 (UI Layer)
├── LoginDialog - 登录主界面
├── RegisterDialog - 用户注册界面
└── 消息提示框 - 操作结果反馈

业务逻辑层 (Logic Layer)  
├── 用户验证模块 - validateCredentials()
├── 密码加密模块 - hashPassword()
├── 注册验证模块 - validateInput()
└── 文件操作模块 - saveUserCredentials()

数据存储层 (Data Layer)
├── users.txt - 用户认证数据
└── userinfo.txt - 用户扩展信息
1.3 系统运行界面
登录界面采用现代化的白色背景设计，整体布局简洁清爽。窗口尺寸为400x500像素，提供舒适的视觉体验。界面顶部显示”用户登录”标题，下方是”请输入您的账号信息”的提示文字。
主要输入区域包含用户名和密码两个输入框，每个输入框都有相应的标签说明。用户名输入框使用”请输入用户名”作为占位符提示，密码输入框使用”请输入密码”作为提示。密码输入框旁边有一个眼睛图标按钮，点击可以切换密码的可见性。
底部操作区域包含三个按钮：登录按钮使用紫色渐变设计，是主要的操作按钮；取消按钮为透明背景的灰色文字；注册按钮为透明背景的蓝色文字。所有按钮都采用圆角设计，符合现代UI设计趋势。
注册界面在点击注册按钮后弹出，包含更完整的用户信息收集表单。注册界面包含用户名、邮箱、密码、确认密码等输入字段。密码输入时会实时显示密码强度提示，包括弱、中等、强三个等级，用不同颜色标识。确认密码字段会实时检查与原密码的匹配情况，提供即时反馈。
1.4 系统源代码
主程序文件
main.cpp是程序的入口点，负责创建QApplication对象和启动登录对话框。
#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    LoginDialog dialog;
    if (dialog.exec() == QDialog::Accepted) {
        return 0;
    }
    
    return 0;
}
登录对话框头文件
logindialog.h定义了LoginDialog类的接口，包含所有必要的头文件引用和成员函数声明。
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

#endif
核心功能实现
登录验证函数是系统的核心功能，负责验证用户输入的凭据是否正确。
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
            QString("欢迎您，%1！\\n登录时间：%2")
            .arg(username)
            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
        accept();
    } else {
        QMessageBox::critical(this, "登录失败", 
            "用户名或密码错误！");
        passwordEdit->clear();
        passwordEdit->setFocus();
    }
}

bool LoginDialog::validateCredentials(const QString &username, const QString &password)
{
    QFile file("users.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
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
用户注册功能
注册对话框提供完整的用户注册功能，包括输入验证和密码强度检测。
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
        return;
    }
    
    saveUserCredentials(username, password);
    
    QFile userInfoFile("userinfo.txt");
    if (userInfoFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&userInfoFile);
        out << QString("%1|%2|%3\\n")
            .arg(username)
            .arg(email.isEmpty() ? "未提供" : email)
            .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    }
    
    QMessageBox::information(this, "注册成功", "用户注册成功！您现在可以使用新账户登录。");
    accept();
}
数据存储格式
用户认证数据存储在users.txt文件中，格式为”用户名:密码哈希值”，每行一个用户记录。
admin:240be518fabd2724ddb6f04eeb1da5967448d7e831c08c8fa822809f74c720a9
user:5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8
newuser:ecd71870d1963316a97e3ac3408c9835ad8cf0f3c1bc703527c30265534f75ae
用户扩展信息存储在userinfo.txt文件中，格式为”用户名|邮箱|注册时间”。
admin|未提供|2024-03-15 10:30:25
user|未提供|2024-03-15 10:30:25
newuser|test@example.com|2024-03-15 14:25:30
1.5 系统代码网址
项目代码已上传至代码托管平台，具体访问地址如下：
GitHub仓库地址：https://github.com/Cyanlament/Design-and-Implementation-of-Login-Dialog-Box
1.6 总结与展望
本登录对话框项目采用Qt框架和C++语言开发，实现了完整的用户身份验证和注册功能。系统采用现代化的界面设计，提供良好的用户体验。在技术实现上，使用了文件存储、密码加密、输入验证等多种技术手段，确保系统的安全性和可靠性。
开发过程中使用了Qt Creator集成开发环境，采用qmake作为项目构建工具。系统支持Windows、Linux、macOS等多个平台，具有良好的跨平台兼容性。界面设计使用了Qt样式表技术，实现了自定义的视觉效果。
项目的优势在于代码结构清晰、功能完整、界面美观。采用的技术都是业界标准，便于后续的维护和扩展。系统具有良好的扩展性，可以方便地添加更多的用户管理功能。
未来可以考虑的改进方向包括：集成数据库存储替代文件存储，提高数据管理效率；添加用户头像上传功能，增强个性化体验；实现找回密码功能，提高用户便利性；集成第三方登录如微信、QQ等，扩展登录方式；添加用户权限管理，支持不同级别的用户访问控制。

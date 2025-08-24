/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *headerLayout;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QSpacerItem *headerSpacer;
    QVBoxLayout *formLayout;
    QVBoxLayout *usernameLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QVBoxLayout *passwordLayout;
    QLabel *passwordLabel;
    QHBoxLayout *passwordInputLayout;
    QLineEdit *passwordEdit;
    QPushButton *togglePasswordButton;
    QSpacerItem *formSpacer;
    QVBoxLayout *buttonLayout;
    QPushButton *loginButton;
    QHBoxLayout *secondaryButtonLayout;
    QPushButton *resetButton;
    QSpacerItem *buttonSpacer;
    QPushButton *registerButton;
    QSpacerItem *bottomSpacer;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(400, 500);
        LoginDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background: white;\n"
"}\n"
"\n"
"QLabel#titleLabel {\n"
"    font-size: 28px;\n"
"    font-weight: bold;\n"
"    color: #333333;\n"
"    margin: 20px 0 10px 0;\n"
"}\n"
"\n"
"QLabel#subtitleLabel {\n"
"    font-size: 14px;\n"
"    color: #666666;\n"
"    margin: 0 0 30px 0;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #333333;\n"
"    font-size: 14px;\n"
"    font-weight: normal;\n"
"    margin: 0 0 5px 0;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 15px;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    background: white;\n"
"    margin: 0 0 20px 0;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #667eea;\n"
"    outline: none;\n"
"}\n"
"\n"
"QPushButton#loginButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #667eea, stop:1 #764ba2);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 15px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
""
                        "    margin: 10px 0;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QPushButton#loginButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #5a67d8, stop:1 #6b46c1);\n"
"}\n"
"\n"
"QPushButton#loginButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #4c51bf, stop:1 #553c9a);\n"
"}\n"
"\n"
"QPushButton#resetButton {\n"
"    background: transparent;\n"
"    color: #666666;\n"
"    border: none;\n"
"    padding: 10px 15px;\n"
"    font-size: 14px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton#resetButton:hover {\n"
"    color: #333333;\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"QPushButton#registerButton {\n"
"    background: transparent;\n"
"    color: #667eea;\n"
"    border: none;\n"
"    padding: 10px 15px;\n"
"    font-size: 14px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton#registerButton:hover {\n"
"    color: #5a67d8;\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"QPushButton#togglePasswordButton {\n"
"    backgro"
                        "und: transparent;\n"
"    border: none;\n"
"    color: #666666;\n"
"    margin: 0;\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QPushButton#togglePasswordButton:hover {\n"
"    background: #f5f5f5;\n"
"    border-radius: 4px;\n"
"}"));
        verticalLayout = new QVBoxLayout(LoginDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(40, 60, 40, 40);
        headerLayout = new QVBoxLayout();
        headerLayout->setSpacing(10);
        headerLayout->setObjectName(QString::fromUtf8("headerLayout"));
        titleLabel = new QLabel(LoginDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        headerLayout->addWidget(titleLabel);

        subtitleLabel = new QLabel(LoginDialog);
        subtitleLabel->setObjectName(QString::fromUtf8("subtitleLabel"));
        subtitleLabel->setAlignment(Qt::AlignCenter);

        headerLayout->addWidget(subtitleLabel);


        verticalLayout->addLayout(headerLayout);

        headerSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(headerSpacer);

        formLayout = new QVBoxLayout();
        formLayout->setSpacing(15);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        usernameLayout = new QVBoxLayout();
        usernameLayout->setSpacing(8);
        usernameLayout->setObjectName(QString::fromUtf8("usernameLayout"));
        usernameLabel = new QLabel(LoginDialog);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        usernameLayout->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(LoginDialog);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        usernameLayout->addWidget(usernameEdit);


        formLayout->addLayout(usernameLayout);

        passwordLayout = new QVBoxLayout();
        passwordLayout->setSpacing(8);
        passwordLayout->setObjectName(QString::fromUtf8("passwordLayout"));
        passwordLabel = new QLabel(LoginDialog);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        passwordLayout->addWidget(passwordLabel);

        passwordInputLayout = new QHBoxLayout();
        passwordInputLayout->setSpacing(0);
        passwordInputLayout->setObjectName(QString::fromUtf8("passwordInputLayout"));
        passwordEdit = new QLineEdit(LoginDialog);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        passwordInputLayout->addWidget(passwordEdit);

        togglePasswordButton = new QPushButton(LoginDialog);
        togglePasswordButton->setObjectName(QString::fromUtf8("togglePasswordButton"));
        togglePasswordButton->setMaximumSize(QSize(35, 35));
        togglePasswordButton->setCheckable(true);

        passwordInputLayout->addWidget(togglePasswordButton);


        passwordLayout->addLayout(passwordInputLayout);


        formLayout->addLayout(passwordLayout);


        verticalLayout->addLayout(formLayout);

        formSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(formSpacer);

        buttonLayout = new QVBoxLayout();
        buttonLayout->setSpacing(15);
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        buttonLayout->addWidget(loginButton);

        secondaryButtonLayout = new QHBoxLayout();
        secondaryButtonLayout->setObjectName(QString::fromUtf8("secondaryButtonLayout"));
        resetButton = new QPushButton(LoginDialog);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        secondaryButtonLayout->addWidget(resetButton);

        buttonSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        secondaryButtonLayout->addItem(buttonSpacer);

        registerButton = new QPushButton(LoginDialog);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        secondaryButtonLayout->addWidget(registerButton);


        buttonLayout->addLayout(secondaryButtonLayout);


        verticalLayout->addLayout(buttonLayout);

        bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(bottomSpacer);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        titleLabel->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\346\202\250\347\232\204\350\264\246\345\217\267\344\277\241\346\201\257", nullptr));
        usernameLabel->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215:", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201:", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        togglePasswordButton->setText(QCoreApplication::translate("LoginDialog", "\360\237\221\201", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        resetButton->setText(QCoreApplication::translate("LoginDialog", "\345\217\226\346\266\210", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H

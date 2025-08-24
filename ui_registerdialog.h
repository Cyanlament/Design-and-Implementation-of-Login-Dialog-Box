/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.16
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

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

class Ui_RegisterDialog
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
    QVBoxLayout *emailLayout;
    QLabel *emailLabel;
    QLineEdit *emailEdit;
    QVBoxLayout *passwordLayout;
    QLabel *passwordLabel;
    QHBoxLayout *passwordInputLayout;
    QLineEdit *passwordEdit;
    QPushButton *togglePasswordButton;
    QLabel *passwordStrengthLabel;
    QVBoxLayout *confirmPasswordLayout;
    QLabel *confirmPasswordLabel;
    QHBoxLayout *confirmPasswordInputLayout;
    QLineEdit *confirmPasswordEdit;
    QPushButton *toggleConfirmPasswordButton;
    QLabel *passwordMatchLabel;
    QSpacerItem *formSpacer;
    QVBoxLayout *buttonLayout;
    QPushButton *registerButton;
    QHBoxLayout *cancelButtonLayout;
    QSpacerItem *buttonSpacer;
    QPushButton *cancelButton;
    QSpacerItem *buttonSpacer2;
    QSpacerItem *bottomSpacer;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QString::fromUtf8("RegisterDialog"));
        RegisterDialog->resize(400, 600);
        RegisterDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
"QLabel#passwordStrengthLabel {\n"
"    font-size: 12px;\n"
"    margin: 3px 0 0 0;\n"
"}\n"
"\n"
"QLabel#passwordMatchLabel {\n"
"    font-size: 12px;\n"
"    margin: 3px 0 0 0;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    padding: 15px;\n"
"    border: 1px solid #e0e0e0;\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    background: white;\n"
"    margin: 0 0 5px 0;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: #667eea;\n"
"    outline: none;\n"
"}\n"
"\n"
"QPushButton#registerButton {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
""
                        "        stop:0 #667eea, stop:1 #764ba2);\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 15px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    margin: 10px 0;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QPushButton#registerButton:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #5a67d8, stop:1 #6b46c1);\n"
"}\n"
"\n"
"QPushButton#registerButton:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #4c51bf, stop:1 #553c9a);\n"
"}\n"
"\n"
"QPushButton#cancelButton {\n"
"    background: transparent;\n"
"    color: #666666;\n"
"    border: none;\n"
"    padding: 10px 15px;\n"
"    font-size: 14px;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"QPushButton#cancelButton:hover {\n"
"    color: #333333;\n"
"    text-decoration: underline;\n"
"}\n"
"\n"
"QPushButton#togglePasswordButton {\n"
"    background: transparent;\n"
"    border: none;\n"
"    color: #666666;\n"
"    margin: 0;\n"
"    padding: 8px;\n"
""
                        "}\n"
"\n"
"QPushButton#togglePasswordButton:hover {\n"
"    background: #f5f5f5;\n"
"    border-radius: 4px;\n"
"}"));
        verticalLayout = new QVBoxLayout(RegisterDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(40, 40, 40, 40);
        headerLayout = new QVBoxLayout();
        headerLayout->setSpacing(10);
        headerLayout->setObjectName(QString::fromUtf8("headerLayout"));
        titleLabel = new QLabel(RegisterDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);

        headerLayout->addWidget(titleLabel);

        subtitleLabel = new QLabel(RegisterDialog);
        subtitleLabel->setObjectName(QString::fromUtf8("subtitleLabel"));
        subtitleLabel->setAlignment(Qt::AlignCenter);

        headerLayout->addWidget(subtitleLabel);


        verticalLayout->addLayout(headerLayout);

        headerSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(headerSpacer);

        formLayout = new QVBoxLayout();
        formLayout->setSpacing(15);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        usernameLayout = new QVBoxLayout();
        usernameLayout->setSpacing(8);
        usernameLayout->setObjectName(QString::fromUtf8("usernameLayout"));
        usernameLabel = new QLabel(RegisterDialog);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));

        usernameLayout->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(RegisterDialog);
        usernameEdit->setObjectName(QString::fromUtf8("usernameEdit"));

        usernameLayout->addWidget(usernameEdit);


        formLayout->addLayout(usernameLayout);

        emailLayout = new QVBoxLayout();
        emailLayout->setSpacing(8);
        emailLayout->setObjectName(QString::fromUtf8("emailLayout"));
        emailLabel = new QLabel(RegisterDialog);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));

        emailLayout->addWidget(emailLabel);

        emailEdit = new QLineEdit(RegisterDialog);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));

        emailLayout->addWidget(emailEdit);


        formLayout->addLayout(emailLayout);

        passwordLayout = new QVBoxLayout();
        passwordLayout->setSpacing(8);
        passwordLayout->setObjectName(QString::fromUtf8("passwordLayout"));
        passwordLabel = new QLabel(RegisterDialog);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        passwordLayout->addWidget(passwordLabel);

        passwordInputLayout = new QHBoxLayout();
        passwordInputLayout->setSpacing(0);
        passwordInputLayout->setObjectName(QString::fromUtf8("passwordInputLayout"));
        passwordEdit = new QLineEdit(RegisterDialog);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        passwordInputLayout->addWidget(passwordEdit);

        togglePasswordButton = new QPushButton(RegisterDialog);
        togglePasswordButton->setObjectName(QString::fromUtf8("togglePasswordButton"));
        togglePasswordButton->setMaximumSize(QSize(35, 35));
        togglePasswordButton->setCheckable(true);

        passwordInputLayout->addWidget(togglePasswordButton);


        passwordLayout->addLayout(passwordInputLayout);

        passwordStrengthLabel = new QLabel(RegisterDialog);
        passwordStrengthLabel->setObjectName(QString::fromUtf8("passwordStrengthLabel"));

        passwordLayout->addWidget(passwordStrengthLabel);


        formLayout->addLayout(passwordLayout);

        confirmPasswordLayout = new QVBoxLayout();
        confirmPasswordLayout->setSpacing(8);
        confirmPasswordLayout->setObjectName(QString::fromUtf8("confirmPasswordLayout"));
        confirmPasswordLabel = new QLabel(RegisterDialog);
        confirmPasswordLabel->setObjectName(QString::fromUtf8("confirmPasswordLabel"));

        confirmPasswordLayout->addWidget(confirmPasswordLabel);

        confirmPasswordInputLayout = new QHBoxLayout();
        confirmPasswordInputLayout->setSpacing(0);
        confirmPasswordInputLayout->setObjectName(QString::fromUtf8("confirmPasswordInputLayout"));
        confirmPasswordEdit = new QLineEdit(RegisterDialog);
        confirmPasswordEdit->setObjectName(QString::fromUtf8("confirmPasswordEdit"));
        confirmPasswordEdit->setEchoMode(QLineEdit::Password);

        confirmPasswordInputLayout->addWidget(confirmPasswordEdit);

        toggleConfirmPasswordButton = new QPushButton(RegisterDialog);
        toggleConfirmPasswordButton->setObjectName(QString::fromUtf8("toggleConfirmPasswordButton"));
        toggleConfirmPasswordButton->setMaximumSize(QSize(35, 35));
        toggleConfirmPasswordButton->setCheckable(true);

        confirmPasswordInputLayout->addWidget(toggleConfirmPasswordButton);


        confirmPasswordLayout->addLayout(confirmPasswordInputLayout);

        passwordMatchLabel = new QLabel(RegisterDialog);
        passwordMatchLabel->setObjectName(QString::fromUtf8("passwordMatchLabel"));

        confirmPasswordLayout->addWidget(passwordMatchLabel);


        formLayout->addLayout(confirmPasswordLayout);


        verticalLayout->addLayout(formLayout);

        formSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(formSpacer);

        buttonLayout = new QVBoxLayout();
        buttonLayout->setSpacing(15);
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        registerButton = new QPushButton(RegisterDialog);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));

        buttonLayout->addWidget(registerButton);

        cancelButtonLayout = new QHBoxLayout();
        cancelButtonLayout->setObjectName(QString::fromUtf8("cancelButtonLayout"));
        buttonSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        cancelButtonLayout->addItem(buttonSpacer);

        cancelButton = new QPushButton(RegisterDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        cancelButtonLayout->addWidget(cancelButton);

        buttonSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        cancelButtonLayout->addItem(buttonSpacer2);


        buttonLayout->addLayout(cancelButtonLayout);


        verticalLayout->addLayout(buttonLayout);

        bottomSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(bottomSpacer);


        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        titleLabel->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("RegisterDialog", "\345\210\233\345\273\272\346\202\250\347\232\204\346\226\260\350\264\246\346\210\267", nullptr));
        usernameLabel->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215:", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("RegisterDialog", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\357\274\2103-20\344\275\215\345\255\227\347\254\246\357\274\211", nullptr));
        emailLabel->setText(QCoreApplication::translate("RegisterDialog", "\351\202\256\347\256\261:", nullptr));
        emailEdit->setPlaceholderText(QCoreApplication::translate("RegisterDialog", "\350\257\267\350\276\223\345\205\245\351\202\256\347\256\261\345\234\260\345\235\200\357\274\210\345\217\257\351\200\211\357\274\211", nullptr));
        passwordLabel->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206\347\240\201:", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("RegisterDialog", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201\357\274\210\350\207\263\345\260\2216\344\275\215\357\274\211", nullptr));
        togglePasswordButton->setText(QCoreApplication::translate("RegisterDialog", "\360\237\221\201", nullptr));
        passwordStrengthLabel->setText(QString());
        confirmPasswordLabel->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201:", nullptr));
        confirmPasswordEdit->setPlaceholderText(QCoreApplication::translate("RegisterDialog", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        toggleConfirmPasswordButton->setText(QCoreApplication::translate("RegisterDialog", "\360\237\221\201", nullptr));
        passwordMatchLabel->setText(QString());
        registerButton->setText(QCoreApplication::translate("RegisterDialog", "\346\263\250\345\206\214", nullptr));
        cancelButton->setText(QCoreApplication::translate("RegisterDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H

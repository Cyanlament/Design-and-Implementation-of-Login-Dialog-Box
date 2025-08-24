QT += core widgets

CONFIG += c++17

TARGET = LoginDialog_UI

SOURCES += \
    main_ui.cpp \
    logindialog_ui.cpp \
    registerdialog_ui.cpp

HEADERS += \
    logindialog_ui.h \
    registerdialog_ui.h

FORMS += \
    logindialog.ui \
    registerdialog.ui

# macOS specific settings
macx {
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.14
}
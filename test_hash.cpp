#include <QCoreApplication>
#include <QCryptographicHash>
#include <QDebug>

QString hashPassword(const QString &password)
{
    return QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex();
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    
    qDebug() << "Testing password hashing:";
    qDebug() << "admin123 hash:" << hashPassword("admin123");
    qDebug() << "password hash:" << hashPassword("password");
    
    return 0;
}
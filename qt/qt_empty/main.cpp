#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QHostAddress>

#include "dispatcher.h"

Dispatcher* dispatcher = nullptr;

void EventString(const QString &message);
void EventVariant(const QVariant &variant);

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject* root = engine.rootObjects()[0];
    dispatcher = new Dispatcher(root);
    QObject::connect(root, SIGNAL(onEvent(QString)), dispatcher, SLOT(eventSlot_String(QString)));
    QObject::connect(dispatcher, &Dispatcher::eventSignal_String, EventString);
    QObject::connect(dispatcher, &Dispatcher::eventSignal_Variant, EventVariant);

    QObject* widget = root->findChild<QObject*>("Widget");
    if (widget) {
        QObject::connect(widget, SIGNAL(onEvent(QVariant)), dispatcher, SLOT(eventSlot_Variant(QVariant)));
    }

    return app.exec();
}

void EventString(const QString &message) {
    QStringList params = message.split('-');    
}
void EventVariant(const QVariant &array) {
    QVariantList list = array.toList();

    return;
}




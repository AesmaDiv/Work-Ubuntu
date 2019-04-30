#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QHostAddress>

#include "./dispatcher.h"
#include "./enumerator.hpp"
#include "./headers/AesmaTcp.h"

Dispatcher* dispatcher = nullptr;
AesmaTcp* client = nullptr;

void eventButton(const QString &message);
void processAdam(const QString &message);

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
    QObject::connect(dispatcher, &Dispatcher::eventSignal, eventButton);

    {
        QObject* widget_adam = root->findChild<QObject*>("widgetAdam");
        QObject::connect(widget_adam, SIGNAL(eventButton(QString)), dispatcher, SLOT(eventSlot(QString)));
    }

    client = new AesmaTcp();

    return app.exec();
}

void eventButton(const QString &message) {
    QStringList params = message.split('-');
    if (params[0] == "Adam") {
        processAdam(message);
        return;
    }
}

void processAdam(const QString &message) {
    QStringList params = message.split('-');
    if (params[1] == "Connect") {
        bool state = (params[2] == "true");
        if (state) {
            state = client->Connect("10.10.10.10", "502");
            if (state) client->SetReading(state);
        } else {
            client->Disconnect();
        }

        dispatcher->setProperty("widgetAdam", "isConnected", state);

        return;
    }
    if (params[1] == "Send") {
        ushort val = client->GetChannel(AesmaTcp::Analog, 0, 0);
        return;
    }

}


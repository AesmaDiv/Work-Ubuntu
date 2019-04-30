#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QHostAddress>

#include "./headers/globals.hpp"
#include "./headers/gui.hpp"
#include "./headers/funcs.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QObject* root = engine.rootObjects()[0];
    Globals::Vars::dispatcher = new Dispatcher(root);
    QObject::connect(Globals::Vars::dispatcher, &Dispatcher::eventSignal_String, Events::EventString);
    QObject::connect(Globals::Vars::dispatcher, &Dispatcher::eventSignal_Variant, Events::EventVariant);

    Events::RegisterEvent(root, SIGNAL(onEvent(QString)), SLOT(eventSlot_String(QString)));
    Events::RegisterEvent(root, "testList", SIGNAL(onSelectionChanged(QVariant)), SLOT(eventSlot_Variant(QVariant)));

    GUI::TestList::Fill(root);

    QObject* tl = root->findChild<QObject*>("testList");
    if (tl)
        QObject::connect(tl, SIGNAL(onItemClicked(QString)), Globals::Vars::dispatcher, SLOT(eventSlot_String(QString)));

    return app.exec();
}






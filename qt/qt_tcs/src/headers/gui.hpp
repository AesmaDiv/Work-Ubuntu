#ifndef GUI_HPP
#define GUI_HPP

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QHostAddress>
#include <QObject>
#include <QString>

#include "./globals.hpp"
#include "./events.hpp"
#include "./funcs.hpp"

namespace GUI {
    namespace TestList {
        QList<QObject*> CreateRows(QObject* root, const DataBase::DBTable &table);
        DataBase::DBTable ReadTable();
        void Fill(QObject* root);
    }
}
/* ************************************************************************************************************************ */
/* ******************************************************** TestList ****************************************************** */
/* ************************************************************************************************************************ */
DataBase::DBTable GUI::TestList::ReadTable() {
    std::string path_to_db = "/home/aesma/Develop/db/TCS.sqlite";
    std::string columns = Funcs::Tools::Combine(Globals::Consts::TESTLIST_COLUMNS, ", ");
    std::string select_value = "Select " + columns + " from Tests;";
    DataBase db(path_to_db);
    DataBase::DBTable result;
    db.ExecuteSqlQuery(select_value, result);

    return result;
}
QList<QObject*> GUI::TestList::CreateRows(QObject* root, const DataBase::DBTable &table) {
    QList<QObject*> result;
    QQmlEngine* engine = QtQml::qmlEngine(root);
    QQmlComponent component(engine, QUrl("qrc:/ui/TestListRow.qml"));
    for(auto row : table) {
//        component.setProperty("recId", QString::fromStdString(row[0]));
//        component.setProperty("dateTime", QString::fromStdString(row[1]));
//        component.setProperty("order", QString::fromStdString(row[2]));
//        component.setProperty("serial", QString::fromStdString(row[3]));
        QObject* obj = component.create();
        if (obj) {
            obj->setProperty("recId", "QString::fromStdString(row[0])");
            obj->setProperty("dateTime", "QString::fromStdString(row[1])");
            obj->setProperty("order", "QString::fromStdString(row[2])");
            obj->setProperty("serial", "QString::fromStdString(row[3])");
//            obj->setProperty("recId", QString::fromStdString(row[0]));
//            obj->setProperty("dateTime", QString::fromStdString(row[1]));
//            obj->setProperty("order", QString::fromStdString(row[2]));
//            obj->setProperty("serial", QString::fromStdString(row[3]));

            result.append(obj);
        } else {
            std::cerr << "Main::CreateListOfRows::error: cant create TestListRow object\n";
            break;
        }
    }


    return result;
}
void GUI::TestList::Fill(QObject* root) {
    DataBase::DBTable table = ReadTable();
    if (table.size() > 0) {
        QList<QObject*> rows = CreateRows(root, table);
        if (rows.size() > 0) {
            QObject* testList = root->findChild<QObject*>("testList");
            if (testList) {
                QQmlEngine *engine = QtQml::qmlEngine(testList);
                if (engine)
                    engine->rootContext()->setContextProperty(QStringLiteral("testListViewModel"), QVariant::fromValue(rows));
            }
        }
    }
}
/* ************************************************************************************************************************ */
/* ************************************************************************************************************************ */
/* ************************************************************************************************************************ */

#endif // GUI_HPP

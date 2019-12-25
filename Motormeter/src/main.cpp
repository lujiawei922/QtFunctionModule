#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <logger.h>
#include <QFontDatabase>
#include <QDebug>
#include <languagetranslator.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //注册日志消息输出
    qInstallMessageHandler(Logger::myMessageOutput);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //初始化翻译类
    LanguageTranslator::getInstance()->initLanguageTranslator(app,engine);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

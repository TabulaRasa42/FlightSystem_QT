#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QApplication>



int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    // 1. 指定文件路径（在 Qt Creator 左侧右键 qss 文件 -> Copy Resource Path）
    QFile file(":/QSS/MacOS.qss");

    // 2. 打开文件
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        // 3. 读取内容
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();

        // 4. 应用到全局
        a.setStyleSheet(styleSheet);

        file.close();
    } else {
        // 如果加载失败，打印一条日志，方便调试
        qDebug() << "Open QSS failed!";
    }

    w.show();
    return a.exec();
}

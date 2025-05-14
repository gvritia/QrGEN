#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QColor>
#include <QDateTime>
#include <QImage>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDataTypeChanged(int index);
    void onGenerateClicked();
    void onSaveClicked();
    void onInstructionClicked();
    void onColorButtonClicked();
    void onAddLogoButtonClicked();
    void on_removeLogoButton_clicked();
    void checkExpiry();


private:
    Ui::MainWindow *ui;

    QColor qrColor = Qt::black;
    QPixmap qrPixmap;
    QImage logoImage;
    QTimer expiryTimer;
    QString generateDataString();
    QImage generateQrImage(const QString &data, int size, const QString &ecLevel);
    QImage addLogoToQr(const QImage &qrImage, const QImage &logo);
    bool qrGenerated = false;
};

#endif // MAINWINDOW_H


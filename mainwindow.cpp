#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include <QPainter>
#include <QBuffer>
#include <QDateTime>
#include <QImageReader>
#include <QDebug>

#include "qrcodegen.hpp"

using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(&expiryTimer, &QTimer::timeout, this, &MainWindow::checkExpiry);
    expiryTimer.start(1000);

    connect(ui->dataTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onDataTypeChanged);
    connect(ui->generateButton, &QPushButton::clicked,
            this, &MainWindow::onGenerateClicked);
    connect(ui->saveButton, &QPushButton::clicked,
            this, &MainWindow::onSaveClicked);
    connect(ui->instructionButton, &QPushButton::clicked,
            this, &MainWindow::onInstructionClicked);
    connect(ui->colorButton, &QPushButton::clicked,
            this, &MainWindow::onColorButtonClicked);
    connect(ui->addLogoButton, &QPushButton::clicked,
            this, &MainWindow::onAddLogoButtonClicked);

    onDataTypeChanged(ui->dataTypeComboBox->currentIndex());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onDataTypeChanged(int index) {
    ui->dataInputStack->setCurrentIndex(index);
}

QString MainWindow::generateDataString() {
    QString type = ui->dataTypeComboBox->currentText();

    if (type == "Text") {
        return ui->textLineEdit->text();
    } else if (type == "URL") {
        return ui->urlLineEdit->text();
    } else if (type == "VCARD") {
        QString name = ui->vcardNameLineEdit->text();
        QString phone = ui->vcardPhoneLineEdit->text();
        return QString("BEGIN:VCARD\nVERSION:3.0\nFN:%1\nTEL:%2\nEND:VCARD").arg(name, phone);
    } else if (type == "Email") {
        QString email = ui->emailLineEdit->text();
        QString body = ui->emailBodyTextEdit->toPlainText();
        return QString("MATMSG:TO:%1;BODY:%2;;").arg(email, body);
    } else if (type == "WiFi") {
        QString ssid = ui->wifiSsidLineEdit->text();
        QString password = ui->wifiPasswordLineEdit->text();
        QString encryption = ui->wifiEncryptionComboBox->currentText();
        return QString("WIFI:T:%1;S:%2;P:%3;;").arg(encryption, ssid, password);
    } else if (type == "Location") {
        QString lat = ui->latitudeLineEdit->text();
        QString lon = ui->longitudeLineEdit->text();
        return QString("geo:%1,%2").arg(lat, lon);
    } else if (type == "Event") {
        QString start = ui->eventStartDateTimeEdit->dateTime().toString("yyyyMMddTHHmmss");
        QString end = ui->eventEndDateTimeEdit->dateTime().toString("yyyyMMddTHHmmss");
        QString title = ui->eventTitleLineEdit->text();
        return QString("BEGIN:VEVENT\nSUMMARY:%1\nDTSTART:%2\nDTEND:%3\nEND:VEVENT")
            .arg(title, start, end);
    }

    return "";
}

QImage MainWindow::generateQrImage(const QString &data, int size, const QString &ecLevelStr) {
    QrCode::Ecc ecc = QrCode::Ecc::LOW;
    if (ecLevelStr == "M") ecc = QrCode::Ecc::MEDIUM;
    else if (ecLevelStr == "Q") ecc = QrCode::Ecc::QUARTILE;
    else if (ecLevelStr == "H") ecc = QrCode::Ecc::HIGH;

    QrCode qr = QrCode::encodeText(data.toUtf8().constData(), ecc);
    const int border = 4;
    const int qrSize = qr.getSize() + border * 2;
    double scale = static_cast<double>(size) / qrSize;

    QImage image(size, size, QImage::Format_ARGB32);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setBrush(qrColor);
    painter.setPen(Qt::NoPen);

    for (int y = 0; y < qr.getSize(); ++y) {
        for (int x = 0; x < qr.getSize(); ++x) {
            if (qr.getModule(x, y)) {
                QRectF r((x + border) * scale, (y + border) * scale, scale, scale);
                painter.drawRect(r);
            }
        }
    }

    return image;
}

QImage MainWindow::addLogoToQr(const QImage &qrImage, const QImage &logo) {
    QImage result = qrImage.copy();
    if (logo.isNull()) return result;

    QPainter painter(&result);
    int size = qMin(qrImage.width(), qrImage.height()) / 4;
    QRect targetRect((qrImage.width() - size) / 2, (qrImage.height() - size) / 2, size, size);
    painter.drawImage(targetRect, logo);
    return result;
}

void MainWindow::onGenerateClicked() {
    QString data = generateDataString();

    if (data.isEmpty()) {
        QMessageBox::warning(this, "Error", "No data provided.");
        return;
    }

    if (ui->expiryCheckBox->isChecked()) {
        QDateTime expiry = ui->expiryDateTimeEdit->dateTime();
        QDateTime now = QDateTime::currentDateTime();

        if (!expiry.isValid()) {
            QMessageBox::warning(this, "Error", "Invalid expiration date.");
            return;
        }

        if (now > expiry) {
            QMessageBox::warning(this, "Expired", "The QR code is expired.");

            // Создаём изображение с надписью "Срок действия истёк"
            QImage expiredImage(300, 300, QImage::Format_ARGB32);
            expiredImage.fill(Qt::white);

            QPainter painter(&expiredImage);
            painter.setPen(Qt::red);
            QFont font = painter.font();
            font.setPointSize(16);
            font.setBold(true);
            painter.setFont(font);
            painter.drawText(expiredImage.rect(), Qt::AlignCenter, "Срок действия\nистёк");
            painter.end();

            qrPixmap = QPixmap::fromImage(expiredImage);
            ui->qrCodeLabel->setFixedSize(qrPixmap.size());
            ui->qrCodeLabel->setPixmap(qrPixmap);
            return;
        }
    qrGenerated = true;
    }

    int size = ui->sizeSpinBox->value();
    QString ecLevel = ui->errorCorrectionComboBox->currentText();

    QImage qrImage = generateQrImage(data, size, ecLevel);
    if (!logoImage.isNull()) {
        qrImage = addLogoToQr(qrImage, logoImage);
    }

    qrPixmap = QPixmap::fromImage(qrImage);
    ui->qrCodeLabel->setFixedSize(qrPixmap.size());
    ui->qrCodeLabel->setPixmap(qrPixmap);
}

void MainWindow::onSaveClicked() {
    if (qrPixmap.isNull()) {
        QMessageBox::warning(this, "Warning", "No QR code to save.");
        return;
    }

    if (ui->expiryCheckBox->isChecked()) {
        QDateTime expiry = ui->expiryDateTimeEdit->dateTime();
        if (expiry.isValid() && QDateTime::currentDateTime() > expiry) {
            QMessageBox::warning(this, "Expired", "QR-код истёк и не может быть сохранён.");
            return;
        }
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Save QR Code", "", "PNG Image (*.png);;JPEG Image (*.jpg);;SVG File (*.svg)");

    if (fileName.endsWith(".svg")) {
        QMessageBox::information(this, "Note", "SVG export не поддерживается напрямую. Вы можете сохранить в PNG или JPG.");
        return;
    }

    qrPixmap.save(fileName);
}

void MainWindow::onInstructionClicked() {
    QMessageBox::information(this, "Инструкция",
                             "1. Выберите тип данных (текст/URL/vCard и др.)\n"
                             "2. Заполните обязательные поля\n"
                             "3. Настройте параметры (цвет/размер/коррекция)\n"
                             "4. Для временных кодов:\n"
                             "   - Отметьте галочку 'Срок действия'\n"
                             "   - Укажите дату/время\n"
                             "5. Добавьте логотип (при необходимости)\n"
                             "6. Нажмите 'Сгенерировать QR-код'\n"
                             "7. Сохраните в PNG/JPG\n\n"
                             "Важно:\n"
                             "- Без галочки срок действия не учитывается\n"
                             "- Логотип добавляется только после генерации\n");
}

void MainWindow::onColorButtonClicked() {
    QColor color = QColorDialog::getColor(qrColor, this, "Choose QR Color");
    if (color.isValid()) {
        qrColor = color;
    }
}

void MainWindow::onAddLogoButtonClicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select Logo Image", "", "Images (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {
        logoImage = QImage(fileName);
    }
}

void MainWindow::on_removeLogoButton_clicked() {
    logoImage = QImage();
    onGenerateClicked();
}

void MainWindow::checkExpiry() {
    if (!qrGenerated || !ui->expiryCheckBox->isChecked()) {
        return; // ничего не делаем, если QR не создавался или срок действия не включён
    }

    QDateTime expiry = ui->expiryDateTimeEdit->dateTime();
    QDateTime now = QDateTime::currentDateTime();

    if (expiry.isValid() && now > expiry) {
        // Если уже отображается надпись об истечении — не обновляем
        if (qrPixmap.isNull() || ui->qrCodeLabel->pixmap().isNull()) {
            return;
        }

        qDebug() << "QR code expired. Displaying expiration message.";

        QImage expiredImage(300, 300, QImage::Format_ARGB32);
        expiredImage.fill(Qt::white);

        QPainter painter(&expiredImage);
        painter.setPen(Qt::red);
        QFont font = painter.font();
        font.setPointSize(16);
        font.setBold(true);
        painter.setFont(font);
        painter.drawText(expiredImage.rect(), Qt::AlignCenter, "Срок действия\nистёк");
        painter.end();

        qrPixmap = QPixmap::fromImage(expiredImage);
        ui->qrCodeLabel->setFixedSize(qrPixmap.size());
        ui->qrCodeLabel->setPixmap(qrPixmap);
    }
}


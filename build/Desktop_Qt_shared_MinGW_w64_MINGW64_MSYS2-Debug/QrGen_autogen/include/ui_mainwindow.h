/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *hboxLayout;
    QLabel *dataTypeLabel;
    QComboBox *dataTypeComboBox;
    QStackedWidget *dataInputStack;
    QWidget *textWidget;
    QVBoxLayout *vboxLayout;
    QLineEdit *textLineEdit;
    QWidget *urlWidget;
    QVBoxLayout *vboxLayout1;
    QLineEdit *urlLineEdit;
    QWidget *vcardWidget;
    QVBoxLayout *vboxLayout2;
    QLineEdit *vcardNameLineEdit;
    QLineEdit *vcardPhoneLineEdit;
    QWidget *emailWidget;
    QVBoxLayout *vboxLayout3;
    QLineEdit *emailLineEdit;
    QTextEdit *emailBodyTextEdit;
    QWidget *wifiWidget;
    QVBoxLayout *vboxLayout4;
    QLineEdit *wifiSsidLineEdit;
    QLineEdit *wifiPasswordLineEdit;
    QComboBox *wifiEncryptionComboBox;
    QWidget *locationWidget;
    QVBoxLayout *vboxLayout5;
    QLineEdit *latitudeLineEdit;
    QLineEdit *longitudeLineEdit;
    QWidget *eventWidget;
    QVBoxLayout *vboxLayout6;
    QLineEdit *eventTitleLineEdit;
    QDateTimeEdit *eventStartDateTimeEdit;
    QDateTimeEdit *eventEndDateTimeEdit;
    QHBoxLayout *hboxLayout1;
    QLabel *sizeLabel;
    QSpinBox *sizeSpinBox;
    QLabel *ecLevelLabel;
    QComboBox *errorCorrectionComboBox;
    QPushButton *colorButton;
    QPushButton *addLogoButton;
    QPushButton *removeLogoButton;
    QHBoxLayout *hboxLayout2;
    QLabel *expiryLabel;
    QCheckBox *expiryCheckBox;
    QDateTimeEdit *expiryDateTimeEdit;
    QPushButton *generateButton;
    QLabel *qrCodeLabel;
    QHBoxLayout *hboxLayout3;
    QPushButton *saveButton;
    QPushButton *instructionButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 620);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        dataTypeLabel = new QLabel(centralwidget);
        dataTypeLabel->setObjectName("dataTypeLabel");

        hboxLayout->addWidget(dataTypeLabel);

        dataTypeComboBox = new QComboBox(centralwidget);
        dataTypeComboBox->addItem(QString());
        dataTypeComboBox->addItem(QString());
        dataTypeComboBox->addItem(QString());
        dataTypeComboBox->addItem(QString());
        dataTypeComboBox->addItem(QString());
        dataTypeComboBox->addItem(QString());
        dataTypeComboBox->addItem(QString());
        dataTypeComboBox->setObjectName("dataTypeComboBox");

        hboxLayout->addWidget(dataTypeComboBox);


        mainLayout->addLayout(hboxLayout);

        dataInputStack = new QStackedWidget(centralwidget);
        dataInputStack->setObjectName("dataInputStack");
        textWidget = new QWidget();
        textWidget->setObjectName("textWidget");
        vboxLayout = new QVBoxLayout(textWidget);
        vboxLayout->setObjectName("vboxLayout");
        textLineEdit = new QLineEdit(textWidget);
        textLineEdit->setObjectName("textLineEdit");

        vboxLayout->addWidget(textLineEdit);

        dataInputStack->addWidget(textWidget);
        urlWidget = new QWidget();
        urlWidget->setObjectName("urlWidget");
        vboxLayout1 = new QVBoxLayout(urlWidget);
        vboxLayout1->setObjectName("vboxLayout1");
        urlLineEdit = new QLineEdit(urlWidget);
        urlLineEdit->setObjectName("urlLineEdit");

        vboxLayout1->addWidget(urlLineEdit);

        dataInputStack->addWidget(urlWidget);
        vcardWidget = new QWidget();
        vcardWidget->setObjectName("vcardWidget");
        vboxLayout2 = new QVBoxLayout(vcardWidget);
        vboxLayout2->setObjectName("vboxLayout2");
        vcardNameLineEdit = new QLineEdit(vcardWidget);
        vcardNameLineEdit->setObjectName("vcardNameLineEdit");

        vboxLayout2->addWidget(vcardNameLineEdit);

        vcardPhoneLineEdit = new QLineEdit(vcardWidget);
        vcardPhoneLineEdit->setObjectName("vcardPhoneLineEdit");

        vboxLayout2->addWidget(vcardPhoneLineEdit);

        dataInputStack->addWidget(vcardWidget);
        emailWidget = new QWidget();
        emailWidget->setObjectName("emailWidget");
        vboxLayout3 = new QVBoxLayout(emailWidget);
        vboxLayout3->setObjectName("vboxLayout3");
        emailLineEdit = new QLineEdit(emailWidget);
        emailLineEdit->setObjectName("emailLineEdit");

        vboxLayout3->addWidget(emailLineEdit);

        emailBodyTextEdit = new QTextEdit(emailWidget);
        emailBodyTextEdit->setObjectName("emailBodyTextEdit");

        vboxLayout3->addWidget(emailBodyTextEdit);

        dataInputStack->addWidget(emailWidget);
        wifiWidget = new QWidget();
        wifiWidget->setObjectName("wifiWidget");
        vboxLayout4 = new QVBoxLayout(wifiWidget);
        vboxLayout4->setObjectName("vboxLayout4");
        wifiSsidLineEdit = new QLineEdit(wifiWidget);
        wifiSsidLineEdit->setObjectName("wifiSsidLineEdit");

        vboxLayout4->addWidget(wifiSsidLineEdit);

        wifiPasswordLineEdit = new QLineEdit(wifiWidget);
        wifiPasswordLineEdit->setObjectName("wifiPasswordLineEdit");

        vboxLayout4->addWidget(wifiPasswordLineEdit);

        wifiEncryptionComboBox = new QComboBox(wifiWidget);
        wifiEncryptionComboBox->addItem(QString());
        wifiEncryptionComboBox->addItem(QString());
        wifiEncryptionComboBox->addItem(QString());
        wifiEncryptionComboBox->setObjectName("wifiEncryptionComboBox");

        vboxLayout4->addWidget(wifiEncryptionComboBox);

        dataInputStack->addWidget(wifiWidget);
        locationWidget = new QWidget();
        locationWidget->setObjectName("locationWidget");
        vboxLayout5 = new QVBoxLayout(locationWidget);
        vboxLayout5->setObjectName("vboxLayout5");
        latitudeLineEdit = new QLineEdit(locationWidget);
        latitudeLineEdit->setObjectName("latitudeLineEdit");

        vboxLayout5->addWidget(latitudeLineEdit);

        longitudeLineEdit = new QLineEdit(locationWidget);
        longitudeLineEdit->setObjectName("longitudeLineEdit");

        vboxLayout5->addWidget(longitudeLineEdit);

        dataInputStack->addWidget(locationWidget);
        eventWidget = new QWidget();
        eventWidget->setObjectName("eventWidget");
        vboxLayout6 = new QVBoxLayout(eventWidget);
        vboxLayout6->setObjectName("vboxLayout6");
        eventTitleLineEdit = new QLineEdit(eventWidget);
        eventTitleLineEdit->setObjectName("eventTitleLineEdit");

        vboxLayout6->addWidget(eventTitleLineEdit);

        eventStartDateTimeEdit = new QDateTimeEdit(eventWidget);
        eventStartDateTimeEdit->setObjectName("eventStartDateTimeEdit");
        eventStartDateTimeEdit->setCalendarPopup(true);

        vboxLayout6->addWidget(eventStartDateTimeEdit);

        eventEndDateTimeEdit = new QDateTimeEdit(eventWidget);
        eventEndDateTimeEdit->setObjectName("eventEndDateTimeEdit");
        eventEndDateTimeEdit->setCalendarPopup(true);

        vboxLayout6->addWidget(eventEndDateTimeEdit);

        dataInputStack->addWidget(eventWidget);

        mainLayout->addWidget(dataInputStack);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        sizeLabel = new QLabel(centralwidget);
        sizeLabel->setObjectName("sizeLabel");

        hboxLayout1->addWidget(sizeLabel);

        sizeSpinBox = new QSpinBox(centralwidget);
        sizeSpinBox->setObjectName("sizeSpinBox");
        sizeSpinBox->setMinimum(100);
        sizeSpinBox->setMaximum(1000);
        sizeSpinBox->setValue(300);

        hboxLayout1->addWidget(sizeSpinBox);

        ecLevelLabel = new QLabel(centralwidget);
        ecLevelLabel->setObjectName("ecLevelLabel");

        hboxLayout1->addWidget(ecLevelLabel);

        errorCorrectionComboBox = new QComboBox(centralwidget);
        errorCorrectionComboBox->addItem(QString());
        errorCorrectionComboBox->addItem(QString());
        errorCorrectionComboBox->addItem(QString());
        errorCorrectionComboBox->addItem(QString());
        errorCorrectionComboBox->setObjectName("errorCorrectionComboBox");

        hboxLayout1->addWidget(errorCorrectionComboBox);

        colorButton = new QPushButton(centralwidget);
        colorButton->setObjectName("colorButton");

        hboxLayout1->addWidget(colorButton);

        addLogoButton = new QPushButton(centralwidget);
        addLogoButton->setObjectName("addLogoButton");

        hboxLayout1->addWidget(addLogoButton);

        removeLogoButton = new QPushButton(centralwidget);
        removeLogoButton->setObjectName("removeLogoButton");

        hboxLayout1->addWidget(removeLogoButton);


        mainLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName("hboxLayout2");
        expiryLabel = new QLabel(centralwidget);
        expiryLabel->setObjectName("expiryLabel");

        hboxLayout2->addWidget(expiryLabel);

        expiryCheckBox = new QCheckBox(centralwidget);
        expiryCheckBox->setObjectName("expiryCheckBox");

        hboxLayout2->addWidget(expiryCheckBox);

        expiryDateTimeEdit = new QDateTimeEdit(centralwidget);
        expiryDateTimeEdit->setObjectName("expiryDateTimeEdit");
        expiryDateTimeEdit->setCalendarPopup(true);

        hboxLayout2->addWidget(expiryDateTimeEdit);


        mainLayout->addLayout(hboxLayout2);

        generateButton = new QPushButton(centralwidget);
        generateButton->setObjectName("generateButton");

        mainLayout->addWidget(generateButton);

        qrCodeLabel = new QLabel(centralwidget);
        qrCodeLabel->setObjectName("qrCodeLabel");
        qrCodeLabel->setMinimumSize(QSize(300, 300));
        qrCodeLabel->setFrameShape(QFrame::Box);
        qrCodeLabel->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(qrCodeLabel);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName("hboxLayout3");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        hboxLayout3->addWidget(saveButton);

        instructionButton = new QPushButton(centralwidget);
        instructionButton->setObjectName("instructionButton");

        hboxLayout3->addWidget(instructionButton);


        mainLayout->addLayout(hboxLayout3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        dataInputStack->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QR Code Generator", nullptr));
        dataTypeLabel->setText(QCoreApplication::translate("MainWindow", "\320\242\320\270\320\277 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        dataTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Text", nullptr));
        dataTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "URL", nullptr));
        dataTypeComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "VCARD", nullptr));
        dataTypeComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Email", nullptr));
        dataTypeComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "WiFi", nullptr));
        dataTypeComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Location", nullptr));
        dataTypeComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Event", nullptr));

        textLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter text", nullptr));
        urlLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter URL", nullptr));
        vcardNameLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Full name", nullptr));
        vcardPhoneLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Phone number", nullptr));
        emailLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email address", nullptr));
        emailBodyTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email body", nullptr));
        wifiSsidLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "SSID", nullptr));
        wifiPasswordLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        wifiEncryptionComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "WPA", nullptr));
        wifiEncryptionComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "WEP", nullptr));
        wifiEncryptionComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "nopass", nullptr));

        latitudeLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Latitude", nullptr));
        longitudeLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Longitude", nullptr));
        eventTitleLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Event Title", nullptr));
        sizeLabel->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200", nullptr));
        ecLevelLabel->setText(QCoreApplication::translate("MainWindow", "\320\243\321\200\320\276\320\262\320\265\320\275\321\214 \320\272\320\276\321\200\321\200\320\265\320\272\321\206\320\270\320\270", nullptr));
        errorCorrectionComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "L (7%)", nullptr));
        errorCorrectionComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "M (15%)", nullptr));
        errorCorrectionComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Q (25%)", nullptr));
        errorCorrectionComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "H (30%)", nullptr));

        colorButton->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202", nullptr));
        addLogoButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\273\320\276\320\263\320\276\321\202\320\270\320\277", nullptr));
        removeLogoButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\273\320\276\320\263\320\276\321\202\320\270\320\277", nullptr));
        expiryLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\276\320\272 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\217", nullptr));
        expiryCheckBox->setText(QString());
        generateButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 QR Code", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        instructionButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

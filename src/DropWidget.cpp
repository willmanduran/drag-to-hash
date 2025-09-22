#include "DropWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFile>
#include <QCryptographicHash>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

DropWidget::DropWidget(QWidget *parent) : QWidget(parent) {
    setAcceptDrops(true);
    setWindowTitle("Drag-to-Hash");
    setMinimumSize(550, 380);

    dropLabel_ = new QLabel("Drop files here");
    dropLabel_->setAlignment(Qt::AlignCenter);
    dropLabel_->setStyleSheet("border: 2px dashed gray; padding: 20px; font-size: 14px;");

    fileList_ = new QListWidget();

    fileBtn_ = new QPushButton("Browse Files");
    connect(fileBtn_, &QPushButton::clicked, this, &DropWidget::browseFiles);

    outputPath_ = new QLineEdit(QDir::homePath() + "/Documents/output-hash.txt");
    outputBtn_ = new QPushButton("Browse Output");
    connect(outputBtn_, &QPushButton::clicked, this, &DropWidget::browseOutput);

    auto outputLayout = new QHBoxLayout();
    outputLayout->addWidget(outputPath_);
    outputLayout->addWidget(outputBtn_);

    includeFileName_ = new QCheckBox("Include filename");
    includeFileName_->setChecked(true);

    hashBtn_ = new QPushButton("Hash and Save");
    connect(hashBtn_, &QPushButton::clicked, this, &DropWidget::hashAndSave);

    auto layout = new QVBoxLayout(this);
    layout->addWidget(dropLabel_);
    layout->addWidget(fileList_);
    layout->addWidget(fileBtn_);
    layout->addLayout(outputLayout);
    layout->addWidget(includeFileName_);
    layout->addWidget(hashBtn_);
}

void DropWidget::dragEnterEvent(QDragEnterEvent *e) {
    if (e->mimeData()->hasUrls())
        e->acceptProposedAction();
}

void DropWidget::dropEvent(QDropEvent *e) {
    auto urls = e->mimeData()->urls();
    for (const auto &u : urls) {
        QString path = u.toLocalFile();
        if (!path.isEmpty() && !files_.contains(path)) {
            files_ << path;
            fileList_->addItem(path);
        }
    }
}

QString DropWidget::hashFile(const QString &path) {
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly)) return "ERROR";
    QCryptographicHash h(QCryptographicHash::Sha256);
    constexpr qint64 CHUNK = 1 << 20; // 1 MB
    QByteArray buf;
    buf.resize(CHUNK);
    while (true) {
        qint64 n = f.read(buf.data(), buf.size());
        if (n <= 0) break;
        h.addData(QByteArrayView(buf.constData(), n));
    }
    return h.result().toHex();
}

void DropWidget::hashAndSave() {
    if (files_.isEmpty()) {
        QMessageBox::warning(this, "No files", "Please add some files first.");
        return;
    }
    QString fileName = outputPath_->text();
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "No output path", "Please set a valid output file path.");
        return;
    }

    QFile out(fileName);
    if (!out.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Failed to open output file for writing.");
        return;
    }

    for (const QString &path : files_) {
        QString hash = hashFile(path);
        QString line;
        if (includeFileName_->isChecked())
            line = QString("%1  %2\n").arg(hash, path);
        else
            line = QString("%1\n").arg(hash);
        out.write(line.toUtf8());
    }
    out.close();

    QMessageBox::information(this, "Success", "Hashes saved to:\n" + fileName);
}

void DropWidget::browseFiles() {
    QStringList paths = QFileDialog::getOpenFileNames(this, "Select Files", QDir::homePath());
    for (const QString &path : paths) {
        if (!path.isEmpty() && !files_.contains(path)) {
            files_ << path;
            fileList_->addItem(path);
        }
    }
}

void DropWidget::browseOutput() {
    QString fileName = QFileDialog::getSaveFileName(this, "Select Output File",
                        QDir::homePath() + "/Documents/output-hash.txt",
                        "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        outputPath_->setText(fileName);
    }
}

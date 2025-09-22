#pragma once
#include <QWidget>
#include <QStringList>

class QLabel;
class QPushButton;
class QListWidget;
class QLineEdit;
class QCheckBox;

class DropWidget : public QWidget {
    Q_OBJECT
public:
    explicit DropWidget(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *e) override;
    void dropEvent(QDropEvent *e) override;

private slots:
    void hashAndSave();
    void browseFiles();
    void browseOutput();

private:
    QLabel *dropLabel_;
    QListWidget *fileList_;
    QPushButton *hashBtn_;
    QPushButton *fileBtn_;
    QPushButton *outputBtn_;
    QLineEdit *outputPath_;
    QCheckBox *includeFileName_;
    QStringList files_;
    QString hashFile(const QString &path);
};

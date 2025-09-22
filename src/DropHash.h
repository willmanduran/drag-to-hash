#pragma once
#include <QWidget>
#include <QStringList>

class QLabel;
class QPushButton;
class QListWidget;

class DropWidget : public QWidget {
    Q_OBJECT
public:
    explicit DropWidget(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *e) override;
    void dropEvent(QDropEvent *e) override;

private slots:
    void hashAndSave();

private:
    QLabel *dropLabel_;
    QListWidget *fileList_;
    QPushButton *hashBtn_;
    QString hashFile(const QString &path);
    QStringList files_;
};

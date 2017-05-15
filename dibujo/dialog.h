#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QPixmap>
#include <QTextEdit>
#include <QLabel>

class QPushButton;
class Dialog: public QWidget {
    Q_OBJECT

    QPixmap defender;
    QTimer* timer;

    int dx = 30;
    int dy = 30;
    int ds = 1;

    QPushButton *m_button;
    QTextEdit *m_Text;
    QLabel *lbl;

    public:
    explicit Dialog(QWidget *parent = 0);
            ~Dialog();

    protected:
    void paintEvent(QPaintEvent *event);

    public slots:
    void nextFrame();
    void resetBtn();
};

#endif // DIALOG_H

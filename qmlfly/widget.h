#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVariantList>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void loadData();

public slots:
    int getDesktopWidth();
    int getDesktopHeight();

signals:
    void readData(const QVariantList &list);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

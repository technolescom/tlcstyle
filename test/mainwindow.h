#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QRadioButton>
#include <QStyle>
#include <QGroupBox>
#include <QStyleFactory>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QSignalMapper>
#include <QCheckBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGroupBox *topLeftGroupBox;
    QRadioButton *rb;
    QRadioButton *rb2;
    QCheckBox *cb1;
    QCheckBox *cb2;
protected:
    void createTopLeftGroupBox();
    void applyTheme( const QString & key );
    void mySlot(const QString &key);
};

#endif // MAINWINDOW_H

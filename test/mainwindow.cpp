#include "mainwindow.h"
#include <Tlc.h>
#include <QApplication>
#include <QStyleFactory>
#include <QSettings>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    createTopLeftGroupBox();

}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::mySlot(const QString &key){
    qApp->setStyle(QStyleFactory::create(key));
    return;
}


void MainWindow::createTopLeftGroupBox()
{
    QRadioButton *rb = new QRadioButton ("Test");
    QRadioButton *rb2 = new QRadioButton ("Test 2");
    QCheckBox *cb1 = new QCheckBox ("Test3");
    QCheckBox *cb2 = new QCheckBox ("Test4");


    QPalette palette = rb->palette();
    palette.setColor(QPalette::Base, Qt::lightGray);
    palette.setColor(QPalette::Text, Tlc::brightTextColor(palette));
    rb->setPalette(palette);
    rb->setChecked(true);

    QPalette palette2 = rb2->palette();
    palette2.setColor(QPalette::Base, Qt::gray);
    palette2.setColor(QPalette::Text, Tlc::brightTextColor(palette2));
    rb2->setPalette(palette2);

    QPalette palette3 = cb1->palette();
    palette3.setColor(QPalette::Base, Qt::gray);
    palette3.setColor(QPalette::Text, Tlc::brightTextColor(palette3));
    cb1->setPalette(palette3);

    QPalette palette4 = cb2->palette();
    palette4.setColor(QPalette::Base, Qt::gray);
    palette4.setColor(QPalette::Text, Tlc::brightTextColor(palette4));
    cb2->setPalette(palette4);

    QVBoxLayout *layout = new QVBoxLayout;
    topLeftGroupBox = new QGroupBox();
    layout->addWidget(rb);
    layout->addWidget(rb2);
    layout->addWidget(cb1);
    layout->addWidget(cb2);
    topLeftGroupBox->setLayout(layout);
    setCentralWidget(topLeftGroupBox);

    QMenu *file = new QMenu("&File");
    QAction *quit = new QAction("&Quit", this);
    file->addAction(quit);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);

    QMenu *view = new QMenu("&View");

    QMainWindow::menuBar()->addMenu(file);
    QMainWindow::menuBar()->addMenu(view);

    QSignalMapper * mapper = new QSignalMapper( this );
    connect( mapper, &QSignalMapper::mappedString,
        this, &MainWindow::mySlot );

    for (const QString & key : QStyleFactory::keys() ) {
        QAction *action = view->addAction(key);
        connect( action, &QAction::triggered, mapper,
          static_cast< void( QSignalMapper::* )() >(  &QSignalMapper::map ) );
        mapper->setMapping( action, key );
    }

}


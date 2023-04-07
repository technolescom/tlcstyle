/*******************************************************************************
 *┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑*
 *│   ▄▄▄█████▓ ██▓     ▄████▄    ██████ ▄▄▄█████▓▓██   ██▓ ██▓    ▓█████     │*
 *│   ▓  ██▒ ▓▒▓██▒    ▒██▀ ▀█  ▒██    ▒ ▓  ██▒ ▓▒ ▒██  ██▒▓██▒    ▓█   ▀     │*
 *│   ▒ ▓██░ ▒░▒██░    ▒▓█    ▄ ░ ▓██▄   ▒ ▓██░ ▒░  ▒██ ██░▒██░    ▒███       │*
 *│   ░ ▓██▓ ░ ▒██░    ▒▓▓▄ ▄██▒  ▒   ██▒░ ▓██▓ ░   ░ ▐██▓░▒██░    ▒▓█  ▄     │*
 *│     ▒██▒ ░ ░██████▒▒ ▓███▀ ░▒██████▒▒  ▒██▒ ░   ░ ██▒▓░░██████▒░▒████▒    │*
 *│     ▒ ░░   ░ ▒░▓  ░░ ░▒ ▒  ░▒ ▒▓▒ ▒ ░  ▒ ░░      ██▒▒▒ ░ ▒░▓  ░░░ ▒░ ░    │*
 *│       ░    ░ ░ ▒  ░  ░  ▒   ░ ░▒  ░ ░    ░     ▓██ ░▒░ ░ ░ ▒  ░ ░ ░  ░    │*
 *│     ░        ░ ░   ░        ░  ░  ░    ░       ▒ ▒ ░░    ░ ░      ░       │*
 *│                ░  ░░ ░            ░            ░ ░         ░  ░   ░  ░    │*
 *│                    ░    © 2021 TechnoLesCom    ░ ░                        │*
 *┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙*
 ******************************************************************************/

#include "TlcStyle.h"
#include <QCheckBox>
#include <QRadioButton>

#include <QPainter>
#include <QStyleFactory>
#include <QStyleOption>

#include <QDebug>

TlcStyle::TlcStyle()
  : QProxyStyle("Fusion")
{
}

QPalette
TlcStyle::standardPalette() const // override
{
  if ( ! m_standard_palette.isBrushSet( QPalette::Disabled, QPalette::Mid ) ) {
     QColor gray("#60606a");
     //QColor beige(180, 180, 180);
     //QColor slightlyOpaqueBlack(0, 0, 0, 63);

     /*
     QImage backgroundImage(":/images/woodbackground.png");
     QImage buttonImage(":/images/woodbutton.png");
     QImage midImage = buttonImage.convertToFormat(QImage::Format_RGB32);

     QPainter painter;
     painter.begin(&midImage);
     painter.setPen(Qt::NoPen);
     painter.fillRect(midImage.rect(), slightlyOpaqueBlack);
     painter.end();
     */


     QPalette palette( gray );

     ///palette.setColor( QPalette::Normal, QPalette::Base, Qt::blue );

     palette.setBrush( QPalette::Text, QColor("#dfdfef") );
     palette.setBrush( QPalette::BrightText, QColor("#fafaff") );
     palette.setBrush( QPalette::Base, QColor("#82828c") );
     palette.setBrush( QPalette::AlternateBase, QColor("#787882") );
     palette.setBrush( QPalette::Highlight, QColor("#407446") );
     palette.setBrush( QPalette::WindowText, QColor("#cccccc") );
     palette.setBrush( QPalette::Link, QColor("#40d040") );
     palette.setBrush( QPalette::LinkVisited, QColor("#20a020") );
     //setTexture(palette, QPalette::Button, buttonImage);
     //setTexture(palette, QPalette::Mid, midImage);
     //setTexture(palette, QPalette::Window, backgroundImage);

     QBrush brush = palette.window();
     brush.setColor( brush.color().darker());

     palette.setBrush( QPalette::Disabled, QPalette::Base, QColor("#5b5b61") );
     palette.setBrush( QPalette::Disabled, QPalette::AlternateBase, QColor("#5f5f67") );
     palette.setBrush( QPalette::Disabled, QPalette::WindowText, Qt::gray );
     palette.setBrush( QPalette::Disabled, QPalette::Text, QColor("#7a7a84") );
     palette.setBrush( QPalette::Disabled, QPalette::ButtonText, QColor("#7a7a84") );
     //palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
     palette.setBrush( QPalette::Disabled, QPalette::Button, brush);
     palette.setBrush( QPalette::Disabled, QPalette::Mid, QColor("#6b6b74") );

     m_standard_palette = palette;
  }

  return m_standard_palette;
}


void
TlcStyle::polish( QWidget *widget) // override
{
    QRadioButton *rb = qobject_cast<QRadioButton *>( widget );
    QCheckBox *cb = qobject_cast<QCheckBox *>( widget );
    if(rb || cb){
        QPalette palette = widget->palette();
        QColor color = m_standard_palette.color( QPalette::Highlight );
        palette.setColor(QPalette::Base, Qt::lightGray);
        palette.setColor(QPalette::Text, QColor::fromHsv( color.hue(), 255, 200 ));
        widget->setPalette(palette);
    }
}
/*
void
TlcStyle::drawPrimitive( QStyle::PrimitiveElement element, const QStyleOption
    * option, QPainter * painter, const QWidget * widget) const
      // override
{
  switch ( element ) {
    case PE_PanelButtonCommand: {
      painter->fillRect( option->rect, QColor("#aa0000") );
    }
    break;

    default:
      QProxyStyle::drawPrimitive( element, option, painter, widget );

  }
}
*/


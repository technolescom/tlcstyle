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

#include <QPainter>
#include <QStyleFactory>
#include <QStyleOption>

#include <QDebug>

QPalette
TlcStyle::standardPalette() const // override
{
  if ( ! m_standard_palette.isBrushSet( QPalette::Disabled, QPalette::Mid ) ) {
     QColor gray("#484848");
     QColor beige(180, 180, 180);
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

     palette.setBrush( QPalette::Text, QColor("#dddddd") );
     palette.setBrush( QPalette::BrightText, Qt::white );
     palette.setBrush( QPalette::Base, QColor("#727272") );
     palette.setBrush( QPalette::AlternateBase, QColor("#686868") );
     palette.setBrush( QPalette::Highlight, QColor("#407446") );
     palette.setBrush( QPalette::WindowText, QColor("#cccccc") );
     //setTexture(palette, QPalette::Button, buttonImage);
     //setTexture(palette, QPalette::Mid, midImage);
     //setTexture(palette, QPalette::Window, backgroundImage);

     QBrush brush = palette.window();
     brush.setColor(brush.color().darker());

     palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
     palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
     palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
     palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
     palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
     palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);

     m_standard_palette = palette;
  }

  return m_standard_palette;
}

void
TlcStyle::polish( QPalette & palette ) // override
{
  //qDebug() << Q_FUNC_INFO;
  //palette.setBrush( QPalette::Button, Qt::blue );
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


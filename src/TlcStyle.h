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
#pragma once

#include <QProxyStyle>


namespace Tlc {

  QColor brightTextColor( const QPalette & palette );
};

class TlcStyle : public QProxyStyle
{
  Q_OBJECT

  public:
    explicit TlcStyle();

    QPalette standardPalette() const override;

    void polish( QWidget * widget ) override final;

    void drawPrimitive(QStyle::PrimitiveElement element,
      const QStyleOption *option, QPainter *painter, const QWidget *widget = nullptr) const override;

    /*
    void drawPrimitive( QStyle::PrimitiveElement element, const QStyleOption
        * option, QPainter * painter, const QWidget * widget = nullptr ) const
      override;
      */

  private:
    mutable QPalette m_standard_palette;
};


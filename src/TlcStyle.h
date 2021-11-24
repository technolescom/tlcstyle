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

class TlcStyle : public QProxyStyle
{
  Q_OBJECT

  public:
    explicit TlcStyle();

    QPalette standardPalette() const override;

    void polish( QPalette & palette ) override;

    /*
    void drawPrimitive( QStyle::PrimitiveElement element, const QStyleOption
        * option, QPainter * painter, const QWidget * widget = nullptr ) const
      override;
      */

  private:
    mutable QPalette m_standard_palette;
};


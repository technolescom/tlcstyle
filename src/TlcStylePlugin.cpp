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

#include "TlcStylePlugin.h"

#include "TlcStyle.h"

QStringList
TlcStylePlugin::keys() const
{
  return {"TlcStyle"};
}

QStyle *
TlcStylePlugin::create( const QString & key ) // override
{
  return key.toLower() == "tlcstyle" ? new TlcStyle : nullptr;
}


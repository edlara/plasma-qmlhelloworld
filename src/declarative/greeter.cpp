/***************************************************************************
 *   Copyright (C) 2015 Eduardo Lara <edward.lara.lara@gmail.com>          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; see the file COPYING. If not, write to       *
 *   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,  *
 *   Boston, MA 02110-1301, USA.                                           *
 ***************************************************************************/

#include <limits.h>
#include <iostream>

#include <cstdlib>

#include <QDebug>
#include <QTimer>
#include <QDBusReply>

#include <KLocalizedString>
#include <KFormat>
#include <KNotification>
#include <KIconLoader>
#include <KConfigGroup>
#include <KSharedConfig>

#include <QDBusInterface>
#include <QDBusReply>

#include "greeter.h"

Q_LOGGING_CATEGORY(PLASMA_GREETER, "plasma-greeter")

using namespace std;

Greeter::Greeter(QObject *parent) :
    QObject(parent), mEnabled(false)
{
    qCDebug(PLASMA_GREETER) << "Greeter::Greeter() invoked";
}

Greeter::~Greeter()
{
    qCDebug(PLASMA_GREETER) << "Greeter::Greeter() invoked";
}

QString Greeter::home() const
{
    qCDebug(PLASMA_GREETER) << "home() invoked";
    return std::getenv("HOME");
}

QString Greeter::sayHelloWorld() const
{
    qCDebug(PLASMA_GREETER) << "sayHelloWorld() invoked";
    return i18n("Hello World!");
}

void Greeter::playPause() const
{
    qCDebug(PLASMA_GREETER) << "playPause() invoked";

    // open DBus interface
    QDBusInterface dBusIf( "org.kde.amarok", "/Player", "org.freedesktop.MediaPlayer" );
    if (!dBusIf.isValid())  {
        cout << "cannot open dbus interface" << endl;
        return;
    }
    
    // call play/pause method
    QDBusReply<void> dBusReply = dBusIf.call("PlayPause");
    if ( !dBusReply.isValid() )  {
        cout << "Error " << dBusReply.error().name().toAscii().data() << ": value :"
                << dBusReply.error().message().toAscii().data() << endl;
    }
}

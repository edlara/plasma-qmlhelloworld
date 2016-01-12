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

#include <QtQml>

#include "qmlplugins.h"
#include "greeter.h"

void QmlPlugins::registerTypes(const char* uri)
{
    Q_ASSERT(uri == QLatin1String("org.custom.plasma.HelloWorld"));

    // @uri org.custom.plasma.HelloWorld.Greeter
    qmlRegisterType<Greeter>(uri, 1, 0, "Greeter");
}

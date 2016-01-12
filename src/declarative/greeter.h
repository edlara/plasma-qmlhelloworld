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

#ifndef __GREETER_H__
#define __GREETER_H__

#include <QObject>
#include <QPointer>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(PLASMA_GREETER)

class Greeter : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)

public:

    explicit Greeter(QObject *parent = 0);
    ~Greeter();

    Q_INVOKABLE QString home() const;

    Q_INVOKABLE QString sayHelloWorld() const;
    
    Q_INVOKABLE void playPause() const;
    
    bool enabled() const { return mEnabled; };
    void setEnabled(const bool enabled)
    {
        mEnabled = enabled;
        emit enabledChanged(enabled);
    };
    
signals:
    void enabledChanged(bool enabled);

private:
    bool mEnabled;
};

#endif // __GREETER_H__

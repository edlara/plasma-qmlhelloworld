/***************************************************************************
 *   Copyright (C) 2014 by Aleix Pol Gonzalez <aleixpol@blue-systems.com>  *
 *   Copyright (C) 2015 by Lukáš Tinkl <lukas@kde.org>                     *
 *   Copyright (C) 2015 by Jan Grulich <jgrulich@redhat.com>               *
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
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

import QtQuick 2.2
import QtQuick.Layouts 1.1
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents
import org.custom.plasma.HelloWorld 1.0

Item {
    id: mainWindow
    clip: true
    
    property bool mEnabled: true

    Greeter {
        id: greeter
    }

    RowLayout {
        ColumnLayout {
            PlasmaComponents.Label {
                id: intervalLabel
                text: "Update Interval: " + plasmoid.configuration.updateInterval;
            }
            PlasmaComponents.Label {
                id: enabledLabel
                text: "Enabled: " + mEnabled;
            }
            PlasmaComponents.Label {
                id: greetingLabel
                text: "the greeting: " + greeter.sayHelloWorld();
            }
            PlasmaComponents.Label {
                id: homeLabel
                text: "Home: " + greeter.home();
            }
            PlasmaComponents.Label {
                id: pluginEnabledLabel
                text: "Plugin Enabled: " + greeter.enabled;
            }
            MouseArea {
                anchors.fill: parent
                onClicked: toggleState();
            }
            
        }
        
        PlasmaComponents.Label {
            id: playPauseLabel
            text: "Play/Pause";
            MouseArea {
                anchors.fill: parent
                onClicked: greeter.playPause();
            }
        }
    }

    function toggleState() {
        console.debug("toggleState Begin");
        mEnabled = !mEnabled;
        greeter.enabled=!greeter.enabled;
        console.debug("toggleState End");
    }
}

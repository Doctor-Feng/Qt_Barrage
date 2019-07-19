import QtQuick 2.0

Item {
    id: itemroot

    Component.onCompleted: {
        timer.start()
    }
    property alias name: name

    property int speed: 30

    Timer{
        id: timer
        interval: 100
        onTriggered: {

            var s = root.getSeed()
            Math.seed = s

            itemroot.y = Math.floor(Math.random()*1050)
            itemroot.speed = Math.floor(Math.random() * 30 + 3)
            itemroot.name.text = root.textD[Math.floor((Math.random()*root.textD.length))]
            itemroot.name.color = Qt.rgba(Math.random()*255/255,Math.random()*255/255,Math.random()*255/255,Math.random()+0.6)
            itemroot.name.font.pixelSize = Math.floor(Math.random()*20) + 20

            anim.restart()
        }
    }

    Text {
        id: name
        x: 2000
        text: qsTr("text")
        font.pixelSize: 25
        font.family: "微软雅黑"
        color: "white"
    }

    ParallelAnimation{
        id: anim

        PropertyAnimation{target: name; property: "x";from: widget.getDesktopWidth() + 5;to: (-name.width - 10);duration: speed * (600) ;}

        onStopped: {
            timer.restart()
        }
    }
}

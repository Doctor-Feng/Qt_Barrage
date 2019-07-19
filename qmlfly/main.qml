import QtQuick 2.0

Item {
    id: root
    width: 800
    height: 600

    property var items: new Array
    property var textD: new Array

    Connections{
        target: widget
        onReadData: {
            for(var i in list){
                textD.push(list[i])
            }
            test()
        }
    }

    function addZero(value){
        if(value < 10){
            return "0" + value
        }
        return value
    }

    function getSeed(){

        var date = new Date
        var y = date.getFullYear()
        var M = addZero(date.getMonth())
        var d = addZero(date.getDate())
        var h = addZero(date.getHours())
        var m = addZero(date.getMinutes())
        var s = addZero(date.getSeconds())

        var time = String(y) + String(M) + String(d) + String(h) + String(m) + String(s)

        return Number(time)
    }

    function test(){

        Math.seed = getSeed()
//        console.log("===",time,Math.seed)

        for(var i=0;i<50;i++){

            var obj = Qt.createComponent("OneItem.qml").createObject(root)
            items.push(obj)

//            console.log(obj.speed,obj.name.text,obj.name.color,obj.name.font.pixelSize)
        }
    }
}

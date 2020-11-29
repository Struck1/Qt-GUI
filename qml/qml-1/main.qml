import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")



    Rectangle {
        x: 100
        y: 100
        width: 150
        height: 150
        color: handlerOne.pressed ? "red" : "yellow"

        TapHandler {

            id: handlerOne
        }
    }

     Rectangle {
         x: 300
         y: 100
         width: 150
         height: 150
         color: handlerTwo.pressed ? "purple" : "black"

         TapHandler {

            id: handlerTwo
         }



    }


}

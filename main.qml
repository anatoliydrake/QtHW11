import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import com.vv.exampleclass 1.0 // Подключаем наш класс
import QtQuick.Controls 2.5

Window {
    id:root
    width: 640
    height: 480
    visible: true
    title: qsTr("Органайзер")
    function addThisDate(task, deadline, progress)
    {
        loader.insertRecord(task, deadline, progress)
    }

    function add(task, deadline, progress) {
        root.addThisDate(task, deadline, progress)
        console.log(task)
        console.log(deadline)
        console.log(progress)
    }
    function printB()
    {
        loader.runTable()
    }

    Rectangle {
        color: '#eeeee4'
        width: 640
        height: 480
        id:mainrect
        property int dcheck: 0
        Text {
            x:10
            y:10
            text: qsTr("Task")
        }

       Rectangle {
           color: 'white'
           x: flick.x
           y: flick.y
           width: flick.width
           height: flick.height
       }
       Flickable {
           id: flick
           y: 10
           x: 80
           width: 400
           height: 35
           ScrollBar.vertical: ScrollBar{}
           TextArea.flickable: TextArea {
               id: taskInfo
               width: flick.width
               height: flick.height
               focus: true
               wrapMode: TextEdit.Wrap
               selectByMouse: true
           }
       }

       Text {
           y: 55
           x: 10
           text: qsTr("Deadline")
       }

       Rectangle {
           color: 'white'
           x: deadlineInfo.x
           y: deadlineInfo.y
           width: deadlineInfo.width
           height: deadlineInfo.height
       }

       TextField {
            id: deadlineInfo
            y: 55
            x: 80
            width: 60
            focus: true
            height: 18
            validator: RegularExpressionValidator { regularExpression: /\d{2}[.]\d{2}[.]\d{4}/ }
            onTextChanged: mainrect.dcheck = acceptableInput ? 1 : 0
       }

       Text {
           y: 55
           x: 160
           text: qsTr("Progress")
       }

       Rectangle {
           color: 'white'
           x: progressInfo.x
           y: progressInfo.y
           width: progressInfo.width
           height: progressInfo.height
       }

       TextField {
            id: progressInfo
            y: 55
            x: 220
            width: 15
            focus: true
            height: 18
            validator: IntValidator { bottom:0; top: 10}
        }

       MyButton {
           y: 55
           x: 430
           width: 50
           height: 50
           text: qsTr("Add")
           onClicked: {
               var task = taskInfo.text
               var deadline = deadlineInfo.text
               var progress = progressInfo.text
               if (taskInfo.length !== 0 && mainrect.dcheck != 0 && ((parseInt(progressInfo.text) <= 10) && (parseInt(progressInfo.text) >= 0))) {
                    add(task, deadline, progress)
                   lbl.text = ""
               } else {
                   lbl.text = "Недопустимый ввод!"
               }
           }
       }

       MyButton {
           y: 55
           x: 370
           width: 50
           height: 50
           text: qsTr("Print")
           onClicked: {
               printB()
           }
       }

//       Label {
//           y: 55
//           x: 280
//           text: qsTr("Tasks in list: " + root.num)
//       }

       Label {
           id: lbl
           y: 80
           x: 10
       }
    }

    BaseReader{
        id : loader
    }
}

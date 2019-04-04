import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
	visible: true
	width: 640
	height: 480
	
	ListView {
		anchors.fill: parent
		model: OOPModel {
			
			FunctionalModel {
				
			}
			
			ListModel {
				ListElement { role_lang: "Bash"; role_desc: "Scripting" }
				ListElement { role_lang: "Perl"; role_desc: "Scripting" }
			}
			
			ListModel {
				ListElement { role_lang: "R"; role_desc: "Statistical" }
				ListElement { role_lang: "Julia"; role_desc: "Statistical" }
			}
			
		}
		
		delegate: ItemDelegate {
			width: parent.width; height: 50
			
			Row {
				anchors.fill: parent
				
				Text {
					width: parent.width / 2; height: 50
					text: role_lang
					
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
				}
				
				Text {
					width: parent.width / 2; height: 50
					text: role_desc
					
					horizontalAlignment: Text.AlignHCenter
					verticalAlignment: Text.AlignVCenter
				}
			}
			
			onClicked: {
				console.log("clicked:", role_lang, '(A ' + role_desc + ' Language)');
			}
		}
	}
}

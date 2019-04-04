import QtQuick 2.0

ListModel {
	id: model
	default property list<ListModel> otherModels
	
	ListElement { role_lang: "C++"; role_desc: "OOP" }
    ListElement { role_lang: "Java"; role_desc: "OOP" }
    ListElement { role_lang: "Python"; role_desc: "OOP" }
	
	onOtherModelsChanged: {
		//	add ListElements from otherModels to this model
		var i = otherModels.length - 1;
		if (i < 0) return;
		
		for (var j = 0; j < otherModels[i].count; j++)
			model.append(otherModels[i].get(j));
	}
}

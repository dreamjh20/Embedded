# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Animal.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(783, 522)
        self.Pig = QtWidgets.QPushButton(Form)
        self.Pig.setGeometry(QtCore.QRect(0, 0, 391, 261))
        font = QtGui.QFont()
        font.setFamily("Adobe Devanagari")
        font.setPointSize(72)
        self.Pig.setFont(font)
        self.Pig.setStyleSheet("background-image: url(:/bg/수수.png);")
        self.Pig.setObjectName("Pig")
        self.Owl = QtWidgets.QPushButton(Form)
        self.Owl.setGeometry(QtCore.QRect(390, 0, 391, 261))
        font = QtGui.QFont()
        font.setFamily("Adobe Devanagari")
        font.setPointSize(72)
        self.Owl.setFont(font)
        self.Owl.setStyleSheet("background-image: url(:/bg/부엉이.png);")
        self.Owl.setObjectName("Owl")
        self.Koala = QtWidgets.QPushButton(Form)
        self.Koala.setGeometry(QtCore.QRect(0, 260, 391, 261))
        font = QtGui.QFont()
        font.setFamily("Adobe Devanagari")
        font.setPointSize(72)
        self.Koala.setFont(font)
        self.Koala.setStyleSheet("background-image: url(:/bg/코알라.jpg);")
        self.Koala.setObjectName("Koala")
        self.Beaver = QtWidgets.QPushButton(Form)
        self.Beaver.setGeometry(QtCore.QRect(390, 260, 391, 261))
        font = QtGui.QFont()
        font.setFamily("Adobe Devanagari")
        font.setPointSize(72)
        self.Beaver.setFont(font)
        self.Beaver.setStyleSheet("background-image: url(:/bg/비비버.png);")
        self.Beaver.setObjectName("Beaver")

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "Form"))
        self.Pig.setText(_translate("Form", "SU"))
        self.Owl.setText(_translate("Form", "OWL"))
        self.Koala.setText(_translate("Form", "KOALA"))
        self.Beaver.setText(_translate("Form", "BEAVER"))

import bg_img_rc



if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Form = QtWidgets.QWidget()
    ui = Ui_Form()
    ui.setupUi(Form)
    Form.show()
    sys.exit(app.exec_())


from cal_gui import *
def signals(self):
    self.Calculate_btn.clicked.connect(self.calc)
def calc(self):
    a = self.Input1.text()
    b = self.Input2.text()
    operator = self.comboBox.currentText()

    try:
        c=eval(a + operator + b)
        self.Result.setText(str(c))
    except:
        QtWidgets.QMessageBox.critical(MainWindow, 'Error', 'Invalid inputs!', QtWPidgets.QMessageBox.Ok)
Ui_Form.signals = signals
Ui_Form.calc = calc
if __name__=="__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)

    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_Form()
    ui.setupUi(MainWindow)
    ui.signals()
    MainWindow.show()
    sys.exit(app.exec_())
from Animal import *
import pygame
pygame.init()
pygame.mixer.init()

def pig_wav():
	sounda = pygame.mixer.Sound('wav/Pig.wav');  sounda.play()
def cat_wav():
	soundb = pygame.mixer.Sound('wav/OWL.wav');  soundb.play()
def bird_wav():
	soundc = pygame.mixer.Sound('wav/Pig.wav');  soundc.play()
def wolf_wav():
	soundd = pygame.mixer.Sound('wav/OWL.wav');  soundd.play()
def signals(self):
    self.Pig.clicked.connect(pig_wav)
    self.Owl.clicked.connect(cat_wav)
    self.Koala.clicked.connect(bird_wav)
    self.Beaver.clicked.connect(wolf_wav)

Ui_Form.signals = signals

if __name__=="__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)

    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_Form()
    ui.setupUi(MainWindow)
    ui.signals()
    MainWindow.show()
    sys.exit(app.exec_())

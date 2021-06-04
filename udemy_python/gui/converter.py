import sys
from PySide2.QtWidgets import *
from PySide2.QtCore import Qt, SIGNAL


class ConverterApp(QDialog):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        layout = QGridLayout(self)
        label = QLabel("Kg", parent=self)
        label.setMaximumHeight(25)
        layout.addWidget(label, 0, 0, alignment=Qt.AlignCenter)
        
        self.input_field = QLineEdit(parent=self)
        self.input_field.setMaximumSize(50, 25)
        layout.addWidget(self.input_field, 0, 1, alignment=Qt.AlignCenter)

        convert_it = QPushButton(parent=self, text="Convert")
        convert_it.setCheckable(True)
        convert_it.setMaximumSize(50, 25)
        layout.addWidget(label, 0, 2, alignment=Qt.AlignCenter)

        self.widgets = []
        for i in range(3):
            widget = QLineEdit(parent=self)
            widget.setMaximumSize(75, 25)
            layout.addWidget(widget, 1, i)
            self.widgets.append(widget)
        
        self.setLayout(layout)

        # signals
        convert_it.connect(convert_it, SIGNAL('clicked(bool)'), self.convert)

    def convert(self):
        print("input: {}".format(self.input_field.text()))
        try:
            value = float(self.input_field.text())
        except ValueError:
            print("invalid float!")
            return
        factors = [1000.0, 2.20462, 35.274]
        [wid.setText(str(value * f)) for f, wid in zip(factors, self.widgets)]


                                                     
if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = ConverterApp()

    window.show()
    sys.exit(app.exec_())

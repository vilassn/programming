from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.button import Button


class DesktopApp(App):
    def build(self):
        layout = BoxLayout(orientation='vertical', padding=20, spacing=10)

        self.label = Label(text="Hello, Kivy Desktop App!")
        layout.add_widget(self.label)

        button = Button(text="Click Me!")
        button.bind(on_press=self.on_button_click)
        layout.add_widget(button)

        return layout

    def on_button_click(self, instance):
        self.label.text = "Button Clicked!"


if __name__ == '__main__':
    DesktopApp().run()

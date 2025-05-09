class Engine:
    def __init__(self, horsepower):
        self.horsepower = horsepower

class Body:
    def __init__(self, material):
        self.material = material

class Car(Engine, Body):
    def __init__(self, horsepower, material):
        Engine.__init__(self, horsepower)  
        Body.__init__(self, material)       

    def show_details(self):
        print(f"Horsepower: {self.horsepower}, Material: {self.material}")


my_car = Car(300, "Aluminum")


my_car.show_details()
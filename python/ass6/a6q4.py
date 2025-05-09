class Vehicle:
    def __init__(self, brand, speed):
        self.brand = brand
        self.speed = speed

    def show_details(self):
        print(f"Brand: {self.brand}, Speed: {self.speed} km/h")

class Car(Vehicle):
    def __init__(self, brand, speed, mileage):
        super().__init__(brand, speed)  
        self.mileage = mileage

    def show_details(self):
        super().show_details()  
        print(f"Mileage: {self.mileage} km/l")


my_car = Car("Toyota", 180, 15)


my_car.show_details()
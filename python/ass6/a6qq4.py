class Vehicle():
    def __init__(self,brand,speed):
        self.brand=brand
        self.speed=speed
    
    def show__details(self):
        print(f"brand:{self.brand},speed{self.speed}")
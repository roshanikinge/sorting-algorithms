class Car():
 def display_info(self,brand,year,color):
        self.brand=brand
        self.year=year
        self.color=color
        print(f"Car Brand:{brand}")
        print(f"car year:{year}")
        print(f"car color:{color}")
my_car=Car()

my_car.display_info("toyta" ,2020,"RED")   
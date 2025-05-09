
class Emp:
    def __init__(self, name="rk", position="superviser", salary=45000):
        self.name = name
        self.position = position
        self.salary = salary
    
    def display_info(self):
        print(f"name: {self.name}, position: {self.position}, salary: {self.salary}")


obj = Emp()


obj.display_info()
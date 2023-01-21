from random import randint

class DoorOrder:
    # Class Attributes
    NoOfOrders = 0
    NextOrderId = 500

    # Constructor
    def __init__(self, *args) -> None:
        self.orderId = str(DoorOrder.NextOrderId) + str(randint(1, 10))

        if(len(args) < 1):
            self.quantity = 0
            self.height = 198.1
            self.width = 76.2
            self.depth = 3.5
            self.material = "Wood"
        else:
            self.quantity = args[0]
            self.height = args[1]
            self.width = args[2]
            self.depth = args[3]
            self.material = args[4]

        DoorOrder.NextOrderId += 1
        DoorOrder.NoOfOrders += 1
    
    # Accessor Methods

    def get_orderid(self) -> str:
        return self.orderId

    def get_height(self) -> float:
        return self.height
    
    def get_quantity(self) -> int:
        return self.quantity
    
    # Mutator Methods

    def set_height(self, value):
        self.height = value
        
    
    def set_width(self, value):
        self.width = value
        

    def set_depth(self, value):
        self.depth = value
        
    
    def set_quantity(self, value):
        self.quantity = value
        
    
    # # # #


    def getTotalSurfaceArea(self):
        return 2 * (self.depth * self.width + self.height * self.width + self.height * self.depth) * self.quantity
    
    def getTotalCost(self):
        cost = 0.3
        area = self.getTotalSurfaceArea()

        if self.material == "Wood":
            return cost * area
        elif self.material == "Fiberglass":
            return cost * 1.5 * area
        else:
            return cost * 2 * area

    def __str__(self) -> str:
        output = ""
        output += "Order ID: " + self.orderId + "\n"
        output += "Quantity Ordered: " + str(self.quantity) + "\n"

        return output

d = DoorOrder()
print(d)

print(f"The height of doors for Order ID {d.get_orderid()} has been changed to {d.get_height()} cm.")
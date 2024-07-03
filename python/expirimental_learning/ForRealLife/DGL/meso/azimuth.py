import pygame
from DGL.micro import Unit, Settings


class Azimuth: 
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.state = Unit.Available
        self.size = Settings.CELL_SIZE.value
    
    def __str__(self):
        return f"({self.x}, {self.y}) - {self.state}"
    
    # We can potentially compare the Unit type to the cell state
    def __eq__(self, other):
        return self.state == other

    # TODO: REALLY REALLY NEED TO TODO THIS
    # TODO: Implement this as a type check with a type update.
    def update(self, occupancy):
        self.state = occupancy

    def draw(self, screen):
        pygame.draw.rect(screen, self.state.value, (self.x * self.size, self.y * self.size, self.size, self.size), 1)
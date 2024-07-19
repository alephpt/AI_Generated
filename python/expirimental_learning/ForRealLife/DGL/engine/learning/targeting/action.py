import random
from DGL.cosmos import BaseType


# There are our "eyes" in our agent
class TargetAction(BaseType):
    Pursue = 0                              # This will be the trigger action that will do Nothing until a target is selected
    Pull_First = 1                        # This should map to the first target in the target pool
    Drop_First = 2
    Pull_Segundo = 3                      # This should map to the second target in the target pool
    Drop_Segundo = 4
    Pull_Tre = 5                          # This should map to the third target in the target pool
    Drop_Tre = 6
    Flush_ALL = 7                           # Flush the target pool
    Nothing = 8

    def idx(self):
        return self.value

    @staticmethod
    def random():
        return TargetAction(random.choice([*TargetAction]))


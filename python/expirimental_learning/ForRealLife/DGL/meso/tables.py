import numpy

## THIS ALLOWS FOR AGENTS TO LEARN HOW TO CHOOSE THEIR ACTIONS
##              State->Action Space
## "[QTable] is a table that maps states to actions."
#
#  Keys are possible states, and outputs are optimal weights for determining
#           the best action to take in that state.
#

# State Space Includes
#   - Current Magnitude



class DecisionNetwork:
    def __init__(self):
        self.target_table = {}

        # These are our input conditions
        self.state_space = {
            "magnitude": 0,  ## We need to find the best magnitude
            "energy": 0,
            "wealth": 0,
            "action": "none"       
        }

        # these are our 'target' conditions
        self.target_space = {
            "food": 0,
            "work": 0,
            "mate": 0,
            "sleep": 0,
            "none": 0
        }

        # These are our output parameters
        self.action_space = {
            "find_food": 0,
            "find_work": 0,
            "find_mate": 0,
            "find_sleep": 0,
            "none": 0
        }

        self.n_states = len(self.state_space)
        self.n_choices = len(self.n_choices)
        self.n_actions = len(self.action_space)


    def train(self, x, y):
        self.model.fit(x, y, epochs=1, verbose=0)

    def predict(self, x):
        return self.model.predict(x)

## 

##  THIS ALLOWS FOR AGENTS TO DETERMINE PREFERENCES OVER GENERATIONS
##                  State->Mate Space
## "[MateTable] is a table that maps states to 'choosing a mate'."
#
class MateNetwork:
    def __init__(self):
        self.mate_table = {}

        self.state_space = {
            "self": 0,              # This is "Who I am
            "partner": 0,           # This is "Who my partner is"
            "agenda": 0,            # This is "What I want"
            "target_agenda": 0,     # This is "What my partner wants"
            "integrity": 0,         # This would steer behaviours regarding 'honesty' or 'deception'
            "compassion": 0,        # This would steer behaviours regarding to community or 'selfishness'
            "restlessness": 0       # This would be a multiplier for the 'impulsivity' , or as an aggregate of the other two
        }

    ## ... ?
    

## Lets Not Even Talk about an Economy..

from DGL.micro import p

## Reward Functions for our Agents Movement towards the Target
def calculateReward(prev_d, x, y, target):
    '''
    'findBest' utility function to calculate the reward for the agent

    Parameters:
    prev_d: float - The previous distance to the target
    x: int - The x coordinate of the agent
    y: int - The y coordinate of the agent
    target: Unit - The target of the agent
            '''
    if target is None:
        return {
            'magnitude': 0,
            'reward': 0,
            'target_direction_vector': (0, 0)
        }

    # If the previous distance is 0, we are at the target
    if prev_d is 0:
        target_direction_vector, magnitude = p(x, y, target.x, target.y)

        return {
            'magnitude': magnitude,
            'reward': 'here', # We may experience a glitch here later but this could work temporarily
            'target_direction_vector': target_direction_vector
        }

    reward = 0

    target_direction_vector, magnitude = p(target.x, target.y, target.x, target.y)

    target_reward, target_direction_vector = (magnitude - prev_d, target_direction_vector)
    reward += target_reward

    return {
        'magnitude': magnitude,
        'reward': reward,
        'target_direction_vector': target_direction_vector
    }
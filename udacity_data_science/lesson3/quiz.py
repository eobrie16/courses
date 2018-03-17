import numpy as np

def compute_r_squared(data, predictions):
    # Write a function that, given two input numpy arrays, 'data', and 'predictions,'
    # returns the coefficient of determination, R^2, for the model that produced 
    # predictions.
    # 
    # Numpy has a couple of functions -- np.mean() and np.sum() --
    # that you might find useful, but you don't have to use them.

    ssres = np.sum(np.square(data - predictions))
    sstot = np.sum(np.square(data - np.mean(data)))
    r_squared = 1 - (ssres / sstot)
    return r_squared
    
    
data = np.array([1.1,2.2,3.3,4.4,5.5])
predictions = data
#predictions = np.array([1,2,3,4,5])
#data = np.array([1,2])
#predictions = np.array([0,1])
print (compute_r_squared(data, predictions))
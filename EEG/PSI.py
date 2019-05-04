import pyeeg
import os
import statistics
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

psi_set_A = {'alpha':[],'beta':[],'theta':[]}
psi_set_E = {'alpha':[],'beta':[],'theta':[]}
vector_band = [0.5,4,7,12,30,100]
fs = 50

for file in os.listdir('./Datasets/Z'):
    temp = open('./Datasets/Z/'+file,'r').readlines()
    data = [float(k) for k in temp]
    PSI = pyeeg.bin_power(data,vector_band,fs)
    psi_set_A['alpha'].append(PSI[0][2])
    psi_set_A['beta'].append(PSI[0][3])
    psi_set_A['theta'].append(PSI[0][1])
    
for k,v in psi_set_A.items():psi_set_A[k] = [float(i)/max(v) for i in v]

alpha_set_A = statistics.mean(psi_set_A['alpha'])
beta_set_A = statistics.mean(psi_set_A['beta'])
theta_set_A = statistics.mean(psi_set_A['theta'])

for file in os.listdir('./Datasets/S'):
    temp = open('./Datasets/S/'+file,'r').readlines()
    data = [float(k) for k in temp]
    PSI = pyeeg.bin_power(data,vector_band,fs)
    psi_set_E['alpha'].append(PSI[0][2])
    psi_set_E['beta'].append(PSI[0][3])
    psi_set_E['theta'].append(PSI[0][1])
    
for k,v in psi_set_E.items():psi_set_E[k] = [float(i)/max(v) for i in v]

alpha_set_E = statistics.mean(psi_set_E['alpha'])
beta_set_E = statistics.mean(psi_set_E['beta'])
theta_set_E = statistics.mean(psi_set_E['theta'])

N = 3
set_A = (alpha_set_A, beta_set_A, theta_set_A)
set_E = (alpha_set_E, beta_set_E, theta_set_E)
ind = np.arange(N) 
width = 0.35
plt.style.use('ggplot')
plt.bar(ind + width, set_E, width,label='Set E')
plt.bar(ind, set_A, width, label='Set A')
plt.ylabel('Average PSI Value')
plt.title('Comparison between the values of PSI of Alpha,Beta and Theta for Normal i.e. SET A and Epileptic patient i.e. SET E')
plt.xticks(ind + width / 2, ('alpha', 'beta', 'theta'))
plt.legend(loc='best')
plt.savefig('psi.png')
plt.show()

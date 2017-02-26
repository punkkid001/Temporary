#make graph using python
import matplotlib.pyplot as plt
import matplotlib.legend as legend
#setting x axis value
index=[0,5,10,15,20,25,30,35,40,45,50,55,60,90,120,180]
#setting result value
A_one=[1.000,0.543,0.541,0.533,0.531,0.531,0.531,0.531,0.530,0.529,0.529,0.529,0.529,0.529,0.528,0.527]
gab,=plt.plot(index, A_one, 'ro-')
#setting result value2
A_two=[1.000,0.633,0.544,0.536,0.535,0.534,0.534,0.534,0.534,0.534,0.534,0.534,0.534,0.533,0.532,0.532]
rab,=plt.plot(index, A_two, 'g^-')
#make line index
plt.legend([rab,gab],['A_two','A_one'],loc=2)
#setting x axis label
plt.xlabel('Time(min)')
#setting y axis label
plt.ylabel('Gram(g)')
#setting grid
plt.grid(True)
plt.show()

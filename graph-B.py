#make graph using python
import matplotlib.pyplot as plt
import matplotlib.legend as legend
#setting x axis value
index=[0,5,10,15,20,25,30,35,40,45,50,55,60,90,120,180]
#setting result value
B_one=[1.000,0.742,0.731,0.713,0.699,0.686,0.674,0.655,0.655,0.647,0.641,0.638,0.636,0.633,0.633,0.633]
gab,=plt.plot(index, B_one, 'ro-')
#setting result value2
B_two=[1.000,0.682,0.657,0.645,0.641,0.640,0.640,0.640,0.640,0.640,0.640,0.640,0.640,0.638,0.638,0.638]
rab,=plt.plot(index, B_two, 'g^-')
#make line index
plt.legend([rab,gab],['B_two','B_one'],loc=2)
#setting x axis label
plt.xlabel('Time(min)')
#setting y axis label
plt.ylabel('Gram(g)')
#setting grid
plt.grid(True)
plt.show()

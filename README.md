This project shows how to enable the Temperature Sensor embedded in the nRF51822 processor.
Temperature value is saved in two values tempereature.val1 and temperature.val2, T1 & T2.

By using the following line is possible to show a "float" value using integers. 

LOG_INF("Temperatura: %d.%02d °C", T1,T2/1000); // You should change 1000 for 10000

To convert from int or float to string you can use the following lines of code:

@ prj.conf file:
  CONFIG_CBPRINTF_FP_SUPPORT=y

@ main.c

// Variable declaration
char Ts[16];

// Main routine
snprintf(Ts, sizeof(Ts), "%d.02%d °C", T1, T2/10000);

// En Ts se guarda T1 y T2/10000 en formato xx.xx °C

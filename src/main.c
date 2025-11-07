/* * *********************************************************
Sample code to get data from the Temperature Sensor 
This code is only for educational purposes
The sensor is embedded on the NRF chip so the temperature
is higher than the ambient temperature
* ** ** * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(Temperature, LOG_LEVEL_INF); // LOG_INF y LOG_ERR sustituyen a printk

const struct device *temp_dev;
struct sensor_value temperature;
int T1, T2;
//float T;



int main(void)
{
    
   int ret;

   LOG_INF("Inicializar Sensor de Temperatura");

    // Activar el sensor de temperatura del chip nordic
    temp_dev = DEVICE_DT_GET_ANY(nordic_nrf_temp);
    if (!device_is_ready(temp_dev)) {
        LOG_ERR("Hubo un fallo en el sensor");
        return 0;
    }

    while (1) {
        ret = sensor_sample_fetch(temp_dev);
        if (ret) {
            LOG_ERR("Error (%d) en el sensor", ret);
            k_sleep(K_SECONDS(1));
            continue;
        }

        ret = sensor_channel_get(temp_dev, SENSOR_CHAN_DIE_TEMP, &temperature);
        if (ret) {
            LOG_ERR("Error (%d) en el sensor", ret);
        } else {
            
            T1=temperature.val1;
            T2=temperature.val2;
            //T=T1+T2/1000;
            LOG_INF("Temperatura: %d.%02d °C", T1,T2/1000);
        }

        k_sleep(K_SECONDS(2));
    }
    return 0;
}


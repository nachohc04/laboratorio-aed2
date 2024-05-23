#include "weather_utils.h"

typedef struct {
    unsigned int r_rainfall;
    month_t r_month;
} max_rainfall;

int min_history_temp(WeatherTable weather_record, unsigned int year_length, unsigned int month_length, unsigned int day_length) {
    // guardo la primera temperatura minima
    int res = weather_record[0][0][0]._min_temp;

    // checkeo si hay alguna menor en el resto de temperaturas minimas registradas
    for (unsigned int year=0u; year<year_length; year++) {
        for (unsigned int month=0u; month<month_length; month++) {
            for (unsigned int day=1u; day<day_length; day++) {
                if (weather_record[year][month][day]._min_temp < res) {
                    res = weather_record[year][month][day]._min_temp;
                }
            }
        }
    }

    return res;
}

void max_yearly_temp(WeatherTable weather_record, unsigned int year_length, unsigned int month_length, unsigned int day_length, int anual_max_temps[]) {
    int anual_max;
    
    // checkeo si hay alguna mayor en el resto de temperaturas maximas registradas
    for (unsigned int year=0u; year<year_length; year++) {
        // guardo la primera temperatura maxima del a;o
        anual_max = weather_record[year][0][0]._max_temp;
        
        for (unsigned int month=0u; month<month_length; month++) {
            for (unsigned int day=1u; day<day_length; day++) {
                if (weather_record[year][month][day]._min_temp > anual_max) {
                    anual_max = weather_record[year][month][day]._min_temp;
                }
            }
        }
        // guardo la temperatura anual maxima en el a;o correspondiente
        anual_max_temps[year] = anual_max;
    }
}

void max_yearly_rainfall(WeatherTable weather_record, unsigned int year_length, unsigned int month_length, unsigned int day_length, month_t anual_max_rainfalls[]) {
    max_rainfall anual_max_rainfall;

    // checkeo si hay alguna mayor en el resto de temperaturas maximas registradas
    for (unsigned int year=0u; year<year_length; year++) {
        // guardo la primera temperatura maxima del a;o
        anual_max_rainfall.r_rainfall = weather_record[year][0][0]._rainfall;
        
        for (unsigned int month=0u; month<month_length; month++) {
            for (unsigned int day=1u; day<day_length; day++) {
                if (weather_record[year][month][day]._rainfall > anual_max_rainfall.r_rainfall) {
                    anual_max_rainfall.r_rainfall = weather_record[year][month][day]._rainfall;
                    anual_max_rainfall.r_month = month;
                }
            }
        }
        // guardo la temperatura anual maxima en el a;o correspondiente
        anual_max_rainfalls[year] = anual_max_rainfall.r_month;
    }
}
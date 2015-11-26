/*
 * File:   ADXL313.c
 * Author: Praveenanurag Dulapalli
 *
 * Created: 10/02/2015
 * Last Modified: 10/29/2015
 */

#include "ADXL313.h"

void initializeADXL313(void){
    //ADXL313 Register Initialization Sequence

    SPI_Write(REG_ADDR_ADXL313_DATA_FORMAT, ADXL313_SPI_4_WIRE); //Set 4-wire SPI
    Delay10TCYx(1);

    SPI_Write(REG_ADDR_ADXL313_SOFT_RESET, ADXL313_BEGIN_SOFT_RESET); //Reset routine
    Delay10TCYx(1);

    SPI_Write(REG_ADDR_ADXL313_POWER_CTL, ADXL313_STANDBY_MODE); //Standby
    Delay10TCYx(1);

    SPI_Write(REG_ADDR_ADXL313_BW_RATE, ADXL313_DATA_RATE_800_HZ); //Set 800 Hz output data rate
    Delay10TCYx(1);

    SPI_Write(REG_ADDR_ADXL313_INT_ENABLE, ADXL313_DISABLE_ALL_INTERRUPTS); //DISABLE_INTERRUPTS
    Delay10TCYx(1);

    SPI_Write(REG_ADDR_ADXL313_DATA_FORMAT, ADXL313_USE_FULL_RES | ADXL313_TWO_G_RANGE); //Configure data output
    Delay10TCYx(1);

    SPI_Write(REG_ADDR_ADXL313_POWER_CTL, ADXL313_DISABLE_I2C | ADXL313_MEASUREMENT_ENABLE); //Disable sleep-related bits
                                                                                             //and begin measurement
    Delay10TCYx(1);
}

AccelData readAxisMeasurements(void){
    unsigned char buffer[6];
    AccelData currData;

    SPI_Read_Multiple(REG_ADDR_ADXL313_DATA_X0, 6, buffer);

    currData.y_axis = concatenateRawValues(buffer[3], buffer[2]);
    currData.z_axis = concatenateRawValues(buffer[5], buffer[4]);
    currData.x_axis = concatenateRawValues(buffer[1], buffer[0]);

    return currData;
}

double computeAmplitude(AccelData axisMeasurement, int measurementRange){
    double x, y, z, amplitude, deBogue;

    y = fabs(digitalToAnalogMeasurement(axisMeasurement.y_axis, measurementRange));
    z = fabs(digitalToAnalogMeasurement(axisMeasurement.z_axis, measurementRange));
    x = fabs(digitalToAnalogMeasurement(axisMeasurement.x_axis, measurementRange));

    //sin(y) overflow correction
    if(y >= 1){
        y = 0.99;
    }

    amplitude = fabs( z - fabs( cos( asin(y) ) )  ); //Trigonometric expression to calculate amplitude
                                                     //and maintain operation even with changes in y-axis
    return amplitude;
}

double digitalToAnalogMeasurement(unsigned int digitalInput, int measurementRange){
    //Range Code:  '0' => 0.5g; '1' => 1.0g; '2' => 2.0g
    //Assumes Full-Resolution Enabled
    //Output unit = milli-G's

    int digitalIntermediate, magnitude;
    double convertedVal;
    unsigned int sign;

    sign = (digitalInput >> 11) % 2;
    convertedVal = 0;

    //Mask measurement bits according to bits occupied by measurement range
    //0.5g = 10 bits, 1.0g = 11 bits, 2.0g = 12 bits

    switch(measurementRange){
        case ADXL313_HALF_G_RANGE:
            digitalIntermediate = digitalInput & MASK_9_BITS;
            magnitude = sign ? (~digitalIntermediate + 1) : digitalIntermediate;
            magnitude = magnitude & MASK_9_BITS;
            break;

        case ADXL313_ONE_G_RANGE:
            digitalIntermediate = digitalInput & MASK_10_BITS;
            magnitude = sign ? (~digitalIntermediate + 1) : digitalIntermediate;
            magnitude = magnitude & MASK_10_BITS;
            break;

        case ADXL313_TWO_G_RANGE:
            digitalIntermediate = digitalInput & MASK_11_BITS;
            magnitude = sign ? (~digitalIntermediate + 1) : digitalIntermediate;
            magnitude = magnitude & MASK_11_BITS;
            break;
    }

    convertedVal += magnitude;

    convertedVal /= (double) LSB_PER_G; //Conversion from digital value to analog value

    convertedVal = sign ? -convertedVal : convertedVal; //Apply correct sign

    return convertedVal;
}

unsigned int concatenateRawValues(unsigned char upperBits, unsigned char lowerBits){
    unsigned int concatenatedValue;

    concatenatedValue = 0;

    //Simple bit-shifting and adding
    concatenatedValue += upperBits;
    concatenatedValue = concatenatedValue << 8;
    concatenatedValue += lowerBits;

    return concatenatedValue;
}

void measurementGracePeriod(int numSeconds, int measurementRange){
    int i, numSamples;

    numSamples = numSeconds*MEASUREMENT_SAMPLE_RATE;

    for(i = 0; i < numSamples; i++){
        addDataAccel(computeAmplitude(readAxisMeasurements(), measurementRange)); //Perform full measurement, capture, and storage sequence
        delayOneSamplePeriod();
    }
}




/* DHT library

 MIT license
 written by Adafruit Industries

 This is an ESP8266 flavour of the original Adafruit DHT library

 */
#ifndef DHT_H
#define DHT_H

#include "Arduino.h"
#include "interrupts.h"

// Uncomment to enable printing out nice debug messages.
//#define DHT_DEBUG

// Define where debug output will be printed.
#define DEBUG_PRINTER Serial

// Setup debug printing macros.
#ifdef DHT_DEBUG
#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
#define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
#define DEBUG_PRINT(...) {}
#define DEBUG_PRINTLN(...) {}
#endif

// Define types of sensors.
#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21

class DHT {
public:
	ICACHE_FLASH_ATTR DHT(uint8_t pin, uint8_t type, uint8_t count = 6);
	void ICACHE_FLASH_ATTR begin(void);
	float ICACHE_FLASH_ATTR readTemperature(bool S = false, bool force = false);
	float ICACHE_FLASH_ATTR convertCtoF(float);
	float ICACHE_FLASH_ATTR convertFtoC(float);
	float ICACHE_FLASH_ATTR computeHeatIndex(float temperature, float percentHumidity, bool isFahrenheit = true);
	float ICACHE_FLASH_ATTR readHumidity(bool force = false);

private:
	uint8_t data[5];
	uint8_t _pin, _type;
	uint32_t _lastreadtime, _maxcycles;
	bool _lastresult;
	bool read(bool force = false);
	uint32_t expectPulse(bool level);
};

#endif

#include <iostream>

/**
 * @temper: stores temperature value
 * @cel: performs conversion from celsius
 * to kelvin and fahrenheit.
 * @fah: performs conversion from fahrenheit
 * to to kelvin and celsius.
 * @kel: performs conversion from kelvin to
 * fahrenheit and celsius
 */

class temperature
{
        protected:
        double userTemperature;

        public:

        temperature(double userTemperature)
        {
                this->userTemperature = userTemperature;
        }
        virtual void convert(void){}
};

class Celsius : public temperature
{
        public:

        Celsius(double temp) : temperature(temp){}

        //@override
        void convert(void)
        {
                double fahrenTemp = (userTemperature * 1.8) + 32.0;
                double kelvinTemp = userTemperature + 273.0;
                std::cout << "\t --> Celsius: " << userTemperature << "\t --> Fahrenheit: " << fahrenTemp << "\t --> Kelvin: " << kelvinTemp << "\n";
        }
};

class Fahrenheit : public temperature
{
        public:
        Fahrenheit(double t) : temperature(t){}

        //@override
        void convert(void)
        {
                double celsTemp = (userTemperature - 32.0) * 5.0/9;
                double kelvinTemp = (userTemperature + 459.0) * 5.0/9;
                std::cout << "\t --> Fahrenheit: " << userTemperature << "\t --> Celsius: " << celsTemp << "\t --> Kelvin: " << kelvinTemp << "\n";
        }
};

class Kelvin : public temperature
{
        public:

        Kelvin(double temp) : temperature(temp){}

        //@override
        void convert(void)
        {
                double celsiusTemp = userTemperature - 273.0;
                double fahrenheitTemp = (userTemperature * 9.0/5.0) - 459.0;
                std::cout << "\t --> Kelvin: " << userTemperature << "\t --> Celsius: " << celsiusTemp << "\t --> Fahrenheit: " << fahrenheitTemp << "\n";
        }
};

/**
 * main - entry point
 * description: prompts user for the number
 * of conversions to perform and than with
 * user choice it coverts that temp to another
 *
 * Return: 0 = always success
 */
int main(void)
{
    std::cout << "Temperature Converter of Choice\n\n";

    int numberOfConversions;

    std::cout << "Enter the number of conversions you'd like to do: ";
    std::cin >> numberOfConversions;

    if (numberOfConversions > 0)
    {
         for (int i = 0; i < numberOfConversions; i++)
         {
            char temperatureType;
            double temperature;

            std::cout << "\nEnter Temperature: ";
            std::cin >> temperature;

            std::cout << "Choose the temperature you'd like to convert (c/f/k): ";
            std::cin >> temperatureType;

            Celsius celsius(0);
            Fahrenheit fahrenheit(0);
            Kelvin kelvin(0);

            if (tolower(temperatureType) == 'c')
            {
                celsius = Celsius(temperature);
                celsius.convert();
            }
            else if (tolower(temperatureType) == 'f')
            {
                fahrenheit = Fahrenheit(temperature);
                fahrenheit.convert();
            }
            else if (tolower(temperatureType) == 'k')
            {
                kelvin = Kelvin(temperature);
                kelvin.convert();
            }
            else
            {
                std::cout << "Value entered does not exist or is incorrect\n";
            }
         }
    }
    else
    {
        std::cout << "Enter numbers only and number should be > 0";
    }

    return (0);
}

#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float temp, converted_temp, celsius_val;
    int current_scale, target_scale;

    while (1) {
        // Input: Temperature value 
        printf("Enter the temperature value: ");
        if (scanf("%f", &temp) != 1) break;

        // Input: Current scale 
        printf("Choose the current scale (1) Fahrenheit, (2) Celsius, (3) Kelvin: ");
        scanf("%d", &current_scale);

        // Input: Target scale
        printf("Convert to (1) Fahrenheit, (2) Celsius, (3) Kelvin: ");
        scanf("%d", &target_scale);

        // Error Handling: Invalid conversion choice
        if (current_scale == target_scale) {
            printf("Error: Cannot convert to the same scale. Please try again.\n\n");
            continue;
        }

        // Convert input to Celsius first to simplify 
        if (current_scale == 1) {
            celsius_val = fahrenheit_to_celsius(temp);
        } else if (current_scale == 3) {
            if (temp < 0) {
                printf("Error: Temperature in Kelvin cannot be negative.\n\n");
                continue;
            }
            celsius_val = kelvin_to_celsius(temp);
        } else {
            celsius_val = temp;
        }

        // Perform target conversion
        if (target_scale == 1) {
            converted_temp = celsius_to_fahrenheit(celsius_val);
            printf("\nConverted temperature: %.2f°F\n", converted_temp);
        } else if (target_scale == 2) {
            converted_temp = celsius_val;
            printf("\nConverted temperature: %.2f°C\n", converted_temp);
        } else if (target_scale == 3) {
            converted_temp = celsius_to_kelvin(celsius_val);
            printf("\nConverted temperature: %.2fK\n", converted_temp);
        } else {
            printf("Error: Invalid scale selection.\n\n");
            continue;
        }

        // Provide categorization and advisory
        categorize_temperature(celsius_val);
        printf("\n");
    }

    return 0;
}

// Requirement 1: Celsius to Fahrenheit 
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

// Requirement 2: Fahrenheit to Celsius 
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

// Requirement 3: Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Requirement 4: Kelvin to Celsius
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

// Categorization and Advisory Function
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Category: Freezing\nAdvisory: Wear a heavy jacket."); 
    } else if (celsius >= 0 && celsius < 10) {
        printf("Category: Cold\nAdvisory: Wear a jacket."); 
    } else if (celsius >= 10 && celsius < 25) {
        printf("Category: Comfortable\nAdvisory: You should feel fine.");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Category: Hot\nAdvisory: Stay hydrated."); 
    } else {
        printf("Category: Extreme Heat\nAdvisory: Stay indoors."); 
    }
}
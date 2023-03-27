// Writing a program that uses the api from Open Exchange Rates and displays the current exchange rates for the currencies against Pakistan Rupees and saves them in a
// text file.

#include <iostream>
#include <fstream>
#include <curl/curl.h>

using namespace std;

// This function will be called by cURL when new data is received
size_t writeCallback(char* buf, size_t size, size_t nmemb, void* up)
{
    // Cast the 'up' argument to a ofstream* pointer
    ofstream* file = (ofstream*) up;

    // Write the received data to the file
    file->write(buf, size * nmemb);

    // Return the number of bytes written
    return size * nmemb;
}

int main()
{
    // Initialize cURL
    CURL* curl = curl_easy_init();

    // Set the API endpoint URL and parameters
    // Replace YOUR_API_KEY with your API key that you get after signing up at Open Exchange Rates
    string url = "https://openexchangerates.org/api/latest.json?app_id=YOUR_API_KEY&base=PKR&symbols=USD,EUR,GBP,JPY,CAD";
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    // Create a file to save the response
    ofstream file("currency_rates.txt");

    // Set the writeCallback function to be called when data is received
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);

    // Set the 'up' argument to be the file stream
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &file);

    // Perform the cURL request
    CURLcode res = curl_easy_perform(curl);

    // Check for errors
    if (res != CURLE_OK) {
        cout << "cURL error: " << curl_easy_strerror(res) << endl;
    }

    // Clean up cURL and close the file stream
    curl_easy_cleanup(curl);
    file.close();

    return 0;
}

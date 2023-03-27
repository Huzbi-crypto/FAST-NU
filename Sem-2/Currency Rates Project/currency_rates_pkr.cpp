// Writing a program that uses cURL to get the current exchange rates for the currencies against Pakistan Rupees and saves them in a text file.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <curl/curl.h>

using namespace std;

// This class will be used to get the exchange rates for the currencies against Pakistan Rupees and save them in a text file.
class CurrencyConverter {
public:

    // Constructor that takes the API key as an argument
    CurrencyConverter(const string& api_key) : api_key_(api_key) {}

    // Get the exchange rates for the currencies against Pakistan Rupees
    bool get_exchange_rates(const string& base_currency, const vector<string>& currencies) {

        // Construct the URL to get the exchange rates
        string url = "https://open.er-api.com/v6/latest/" + base_currency + "?apikey=" + api_key_;

        // Add the currencies to the URL as a comma separated list
        url += "&symbols=";
        for (const auto& currency : currencies) {
            url += currency + ",";
        }

        // Remove the last comma from the URL
        url.pop_back(); 

        // Initialize cURL
        CURL* curl = curl_easy_init();

        // Create a string to save the response
        string readBuffer;

        // Set the writeCallback function to be called when data is received and pass the string to it to be appended to
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            // Perform the cURL request
            CURLcode res = curl_easy_perform(curl);

            // Check for errors
            if (res != CURLE_OK) {
                cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
                return false;
            }

            // Clean up cURL
            curl_easy_cleanup(curl);
        } else {
            cerr << "Failed to initialize curl" << endl;
            return false;
        }

        // Save the response to the exchange_rates_ member variable
        exchange_rates_ = readBuffer;
        return true;
    }

    // Save the exchange rates to a text file
    bool save_exchange_rates(const string& filename) {

        // Open the file for writing
        ofstream outputFile(filename);

        // Write the exchange rates to the file
        if (outputFile.is_open()) {
            outputFile << exchange_rates_ << endl;
            outputFile.close();
            cout << "Exchange rates saved to " << filename << endl;
            return true;
        } else {
            cerr << "Failed to open or create " << filename << endl;
            return false;
        }
    }

private:

    // This function will be called by cURL when new data is received
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
        ((string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    // The API key and the exchange rates
    string api_key_;
    string exchange_rates_;
};

int main() {

    // Initialize the CurrencyConverter object with the API key
    CurrencyConverter converter("YOUR_API_KEY");

    // In the vector below, add the currencies you want to get the exchange rates for
    vector<string> currencies = {"USD", "EUR", "GBP", "AUD", "JPY"};

    // Get the exchange rates and save them to a text file
    if (converter.get_exchange_rates("PKR", currencies)) {
        converter.save_exchange_rates("exchange_rates.txt");
    }
    
    return 0;
}

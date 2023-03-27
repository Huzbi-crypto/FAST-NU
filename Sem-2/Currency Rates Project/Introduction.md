# Creating a Currency Rates Program by Using cURL

## Introduction
The code shows one how to use cURL library to make requests using your API key which you can get by signing up for Open Exchange Rates account. The code also shows how to use the cURL library to parse the JSON response and save the 5 currencies in a text file.

## Prerequisites
- A text editor
- A web browser
- A computer with an internet connection
- A free Open Exchange Rates account
- cURL library

## Brief Explanation of the Code
- The `CurrencyConverter` class has two public member functions: `get_exchange_rates()` and `save_exchange_rates()`, and two private member variables: `api_key_` and `exchange_rates_`.
- `get_exchange_rates()` function takes in the base currency as a string and a vector of currencies for which exchange rates are required. It uses the cURL library to get the exchange rates from an API and saves it in `exchange_rates_` variable.
- `save_exchange_rates()` function takes a filename as a string and saves the exchange rates in a file with the given filename.
- The `WriteCallback()` function is a static member function of the `CurrencyConverter` class, which is used by cURL library to store the API response in `exchange_rates_` variable.
- The `main()` function creates an object of the `CurrencyConverter` class and calls `get_exchange_rates()` function with the base currency and a vector of currencies. If the exchange rates are successfully retrieved, it calls the `save_exchange_rates()` function with a filename.
<br>Finally, `YOUR_API_KEY` in the `main` function should be replaced with an actual API key for the exchange rates API being used.

**Note:** The code is still not completed. It is possible that more features and improvements may be added to it in the future.

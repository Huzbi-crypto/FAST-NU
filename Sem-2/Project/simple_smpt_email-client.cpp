#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;

// Callback function to handle server responses
static size_t responseCallback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    string *response = (string*) userdata;
    response->append(ptr, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    struct curl_slist *recipients = NULL;
    string response;
    
    // Initialize libcurl
    curl = curl_easy_init();
    if (!curl) {
        cerr << "Could not initialize libcurl" << endl;
        return 1;
    }
    
    // Set SMTP server and port number
    curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.server.com:587");
    
    // Set username and password for authentication (if required)
    // curl_easy_setopt(curl, CURLOPT_USERNAME, "username");
    // curl_easy_setopt(curl, CURLOPT_PASSWORD, "password");
    
    // Set from address and recipient(s)
    // *Change the email addresses to your own and the recipient's email address as well
    curl_easy_setopt(curl, CURLOPT_MAIL_FROM, "<sender@client.com>");
    recipients = curl_slist_append(recipients, "<recipient1@server.com>");
    recipients = curl_slist_append(recipients, "<recipient2@server.com>");
    curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
    
    // Set email headers and content
    // *Also change the To: and From: addresses to what you wrote above
    curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
    string message = "Subject: Test Email\r\nTo: <recipient1@server.com>, <recipient2@server.com>\r\n\r\nThis is a test email sent using libcurl.\r\n";
    curl_easy_setopt(curl, CURLOPT_READDATA, &message);
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    
    // Set callback function to handle server responses
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, responseCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    
    // Perform the SMTP transaction
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        cerr << "Failed to send email: " << curl_easy_strerror(res) << endl;
        curl_easy_cleanup(curl);
        curl_slist_free_all(recipients);
        return 1;
    }
    
    // Check the response from the server
    long responseCode;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
    if (responseCode != 250) {
        cerr << "Server response: " << response << endl;
        curl_easy_cleanup(curl);
        curl_slist_free_all(recipients);
        return 1;
    }
    
    // Cleanup
    curl_easy_cleanup(curl);
    curl_slist_free_all(recipients);
    
    return 0;
}

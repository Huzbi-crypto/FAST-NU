# Class Feature List for SMPT Sending Operation

## Class: `SmtpClient`

## Properties:
- `serverUrl` (string): The URL of the SMPT server to use.
- `portNumber` (int): The port number to connect to on the SMPT server.
- `username` (string): The username to use for authentication, if required.
- `password` (string): The password to use for authentication, if required.
- `fromAddress` (string): The email address of the sender.
- `recipients` (vector<string>): A vector of email addresses of the recipients.
- `subject` (string): The subject line of the email message.
- `body` (string): The body of the email message.

## Methods:
- `setServer(url: string, port: int)`: Sets the URL and port number of the SMPT server.
- `setCredentials(username: string, password: string)`: Sets the username and password for authentication on the SMPT server.
- `setSender(email: string)`: Sets the email address of the sender.
- `addRecipient(email: string)`: Adds an email address to the list of recipients.
- `setSubject(subjectL string)`: Sets the subject line of the email message.
- `setBody(body: string)`: Sets the body of the email message.
- `send()`: Sends the email message to the specified recipients. Returns true if the email was sent successfully, false otherwise.

### The `SmptClient` class would encapsulate the functionality provided by the code example in a more modular and resusable way. Users of the class would be able to set various propperties of the email message(e.g. sender, recipients, subject, body), and then call the `send()` method to send the message using the configured SMPT server.

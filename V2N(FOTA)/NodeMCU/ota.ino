#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <SoftwareSerial.h>
#include <ESP8266HTTPClient.h>
#include "config.h"
#define TIMEOUT_MS 1000

SoftwareSerial __uart(D5, D6); // (Rx, Tx)

String line_break = "**************************************************************";

bool wifiConnected = false;

// Encryption key

String key = "Jimmy";

void connectToWifi(void)
{
    Serial.println(line_break);
    Serial.println("CONNECTING TO WI-FI");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    for (int counter = 0; counter < WIFI_TIMEOUT_S; counter++)
    {
        Serial.print(".");
        wifiConnected = (WiFi.status() == WL_CONNECTED);
        if (wifiConnected)
        {
            Serial.println();
            Serial.print("CONNECTED TO WI-FI WITH IP: ");
            Serial.println(WiFi.localIP());
            break;
        }
        delay(1000);
    }

    if (!wifiConnected)
    {
        Serial.println();
        Serial.println("COULD NOT CONNECT TO WI-FI");
    }
    Serial.println(line_break);
}

void connectToServer(void)
{
    // Make a HTTP request
    Serial.println("Making HTTP request...");

    // Create a WiFiClient object
    WiFiClient client;

    if (client.connect(serverAddress, 80)) {
        // Make a HTTP GET request
        client.println("GET / HTTP/1.1");
        client.print("Host: ");
        client.println(serverAddress);
        client.println("Connection: close");
        client.println();

        // Wait for response
        while (client.connected()) {
            if (client.available()) {
                String line = client.readStringUntil('\r');
                Serial.print(line);
                Serial.println("successful connection to server");
                break ;
            }
        }
        // Close connection
        client.stop();
    } else {
        Serial.println("Failed to connect to server");
    }
}





// XOR decryption function
String xor_decrypt(String encrypted_text, String key) {
    String decrypted_text = "";
    for (int i = 0; i < encrypted_text.length(); i++) {
        decrypted_text += (char)(encrypted_text.charAt(i) ^ key.charAt(i % key.length()));
    }
    return decrypted_text;
}





void readfile2() {
    int i = 0 ;
    String x = " ";
    String line = "";
    WiFiClient client;
    int lineNumber = 1; // Counter for line numbers

    // Connect to the server
    if (!client.connect(serverAddress, 80)) {
        Serial.println("Connection failed");
        return;
    }

    // Make an HTTP GET request
    client.print(String("GET ") + filePath + " HTTP/1.1\r\n" +
                "Host: " + serverAddress + "\r\n" +
                "Connection: close\r\n\r\n");

    Serial.println("Request sent");

    // Read the response line by line
    while (client.connected() || client.available()) {
        if (client.available()) {
            char c = client.read();
            if (c == '\n') {
                // End of line, do something with the line
                if (lineNumber <= 10) {
                    Serial.print("Received line  ");
                    Serial.print(lineNumber); // Print the line number
                    Serial.print("  ");
                    Serial.println(line);
                    // Process the line as needed

                    // Clear the line variable
                    line = "";
                } else {
                   // Decrypt the line
                    String decryptedLine = xor_decrypt(line, key);
                    if(decryptedLine != "")
                    {
                  // Send decrypted line over UART
                    __uart.println(decryptedLine);
                    Serial.println(line);
                    Serial.println(decryptedLine);
                    x = __uart.readString();
                    while (x != "OK\r");
                    line = "";
                    }
                }
                lineNumber++;
            } else {
                // Append the character to the line
                line += c;
            }
        }
    }

    // Disconnect from the server
    client.stop();
}

void setup()
{
    Serial.begin(9600);
    /* Initialize UART */
    __uart.begin(9600);
    /* waiting 300 ms in read string function (waiting for "OK" Message) */
    __uart.setTimeout(500);
    /* Connect to Wifi */
    connectToWifi();
    /* Connect To server */
    connectToServer();
    /* Read File */
    readfile2();
}

void loop()
{
    if (wifiConnected)
    {
    }
    delay(2000);
}